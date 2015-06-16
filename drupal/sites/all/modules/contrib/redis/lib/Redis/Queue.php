<?php

class Redis_Queue implements DrupalReliableQueueInterface
{
    /**
     * @var DrupalQueueInterface
     */
    protected $backend;

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
        $className = Redis_Client::getClass(Redis_Client::REDIS_IMPL_QUEUE);
        $this->backend = new $className($name);
    }

    public function createItem($data)
    {
        return $this->backend->createItem($data);
    }

    public function numberOfItems()
    {
        return $this->backend->numberOfItems();
    }

    public function claimItem($lease_time = 3600)
    {
        return $this->backend->claimItem($lease_time);
    }

    public function deleteItem($item)
    {
        return $this->backend->deleteItem($item);
    }

    public function releaseItem($item)
    {
        return $this->backend->releaseItem($item);
    }

    public function createQueue()
    {
        return $this->backend->createQueue();
    }

    public function deleteQueue()
    {
        return $this->backend->deleteQueue();
    }
}
