<?php

/**
 * @todo
 *   Set high expire value to the hash for rotation when memory is empty
 *   React upon cache clear all and rebuild path list?
 */
class Redis_Queue_PhpRedis extends Redis_Queue_Base
{
    public function createItem($data)
    {
        $client = $this->getClient();

        $dKey = $this->getKeyForData();
        $qKey = $this->getKeyForQueue();

        // Identifier does not not need to be in the transaction,
        // in case of any error we'll just skip a value in the sequence.
        $id = $client->hincrby($dKey, self::QUEUE_HKEY_SEQ, 1);

        $record = new stdClass();
        $record->qid = $id;
        $record->data = $data;
        $record->timestamp = time();

        $pipe = $client->multi(Redis::PIPELINE);
        // Thanks to the redis_queue standalone module maintainers for
        // this piece of code, very effective. Note that we added the
        // pipeline thought.
        $pipe->hsetnx($dKey, $id, serialize($record));
        $pipe->llen($qKey);
        $pipe->lpush($qKey, $id);
        $ret = $pipe->exec();

        if (!$success = ($ret[0] && $ret[1] < $ret[2])) {
            if ($ret[0]) {
                // HSETNEX worked but not the PUSH command we therefore
                // need to drop the inserted data. I would have prefered
                // a DISCARD instead but we are in pipelined transaction
                // we cannot actually do a DISCARD here.
                $client->hdel($dKey, $id);
            }
        }

        return $success;
    }

    public function numberOfItems()
    {
        return $this->getClient()->llen($this->getKeyForQueue());
    }

    public function claimItem($lease_time = 30)
    {
        // @todo Deal with lease
        $client = $this->getClient();

        $id = $client->rpoplpush(
            $this->getKeyForQueue(),
            $this->getKeyForClaimed()
        );

        if ($id) {
            if ($item = $client->hget($this->getKeyForData(), $id)) {
                if ($item = unserialize($item)) {
                    return $item;
                }
            }
        }

        return false;
    }

    public function deleteItem($item)
    {
        $pipe = $this->getClient()->multi(Redis::PIPELINE);
        $pipe->lrem($this->getKeyForQueue(), $item->qid);
        $pipe->lrem($this->getKeyForClaimed(), $item->qid);
        $pipe->hdel($this->getKeyForData(), $item->qid);
        $pipe->exec();
    }

    public function releaseItem($item)
    {
        $pipe = $this->getClient()->multi(Redis::PIPELINE);
        $pipe->lrem($this->getKeyForClaimed(), $item->qid, -1);
        $pipe->lpush($this->getKeyForQueue(), $item->qid);
        $ret = $pipe->exec();

        return $ret[0] && $ret[1];
    }

    public function createQueue()
    {
    }

    public function deleteQueue()
    {
        $this->getClient()->del(
            $this->getKeyForQueue(),
            $this->getKeyForClaimed(),
            $this->getKeyForData()
        );
    }
}

