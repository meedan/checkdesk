<?php

/**
 * Redis allows implementing reliable queues, here is the spec:
 *
 *  - For each queue, you have 4 different HASH:
 *
 *     - One for queued items queue:NAME:queued
 *
 *     - One for claimed items being processed: queue:NAME:claimed
 *
 *     - One for claimed items leave time: queue:NAME:leave
 *       Items from this one will be arbitrarily fetched at cron
 *       time and released when leave is outdated.
 *
 *     - One containing the item values and other valuable stateful
 *       information: queue:NAME:data ;
 *
 *        - For example, current job maximum identifier (auto increment
 *          emulation) will be stored in the "sequence" HASH key
 *
 *        - All other keys within the HASH will be the items themselves,
 *          keys for those will always be numeric
 *
 *     - Each time a queue will be emptied, even during a pragmatic process,
 *       it will be automatically deleted, reseting the sequence counter to
 *       the 0 value each time
 *
 *  - Algorithm is a variation of the one described in "Reliable queue"
 *    section of http://redis.io/commands/rpoplpush and partial port of what
 *    you can find in the http://drupal.org/project/redis_queue module.
 *
 * You will find the driver specific implementation in the Redis_Queue_*
 * classes as they may differ in how the API handles transaction, pipelining
 * and return values.
 */
abstract class Redis_Queue_Base extends Redis_AbstractBackend implements
    DrupalReliableQueueInterface
{
    /**
     * Key prefix for queue data.
     */
    const QUEUE_KEY_PREFIX = 'queue';

    /**
     * Data HASH sequence key name.
     */
    const QUEUE_HKEY_SEQ = 'seq';

    /**
     * Queue name
     *
     * @var string
     */
    protected $name;

    /**
     * Get data HASH key
     *
     * Key will already be prefixed
     *
     * @return string
     */
    public function getKeyForData()
    {
        return $this->getKey(self::QUEUE_KEY_PREFIX, $this->name, 'data');
    }

    /**
     * Get queued items LIST key
     *
     * Key will already be prefixed
     *
     * @return string
     */
    public function getKeyForQueue()
    {
        return $this->getKey(self::QUEUE_KEY_PREFIX, $this->name, 'queued');
    }

    /**
     * Get claimed LIST key
     *
     * Key will already be prefixed
     *
     * @return string
     */
    public function getKeyForClaimed()
    {
        return $this->getKey(self::QUEUE_KEY_PREFIX, $this->name, 'claimed');
    }

    /**
     * Default contructor
     *
     * Beware that DrupalQueueInterface does not defines the __construct
     * method in the interface yet is being used from DrupalQueue::get()
     *
     * @param unknown $name
     */
    public function __construct($name)
    {
        $this->name = $name;
    }
}
