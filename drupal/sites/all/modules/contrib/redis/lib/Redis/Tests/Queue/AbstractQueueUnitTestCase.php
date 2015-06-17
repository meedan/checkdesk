<?php

/**
 * Some tests in there credits goes to the redis_queue module.
 * Thanks to their author.
 */
abstract class Redis_Tests_Queue_AbstractQueueUnitTestCase extends Redis_Tests_AbstractUnitTestCase
{
    /**
     * @var Redis_Queue
     */
    public $queue;

    /**
     * @var string
     */
    public $name;

    public function setUp()
    {
        parent::setUp();

        module_load_include('inc', 'system', 'system.queue');

        $this->name = 'redis-queue-test-' . time();
        $this->queue = new Redis_Queue($this->name);
    }

    public function tearDown()
    {
        $this->queue->deleteQueue();
        $this->name = null;

        parent::tearDown();
    }

    public function testCreate()
    {
        $res = $this->queue->createItem('test-queue-item-create');
        $num = $this->queue->numberOfItems();
        $this->assertEqual(1, $num);
    }

    public function testClaim()
    {
        $data = 'test-queue-item-claimed';
        $res = $this->queue->createItem($data);
        $item = $this->queue->claimItem();
        $this->assertEqual($data, $item->data);
    }

    /*
    public function testClaimBlocking()
    {
        $data = 'test-queue-item-claimed';
        $res = $this->queue->createItem($data);
        $this->assertTrue($res);
        $item = $this->queue->claimItemBlocking(10);
        $this->assertEqual($data, $item->data);
    }
     */

    public function testRelease()
    {
        $data = 'test-queue-item';

        $res = $this->queue->createItem($data);
        $item = $this->queue->claimItem();

        $num = $this->queue->numberOfItems();
        $this->assertEqual(0, $num);

        $res = $this->queue->releaseItem($item);

        $num = $this->queue->numberOfItems();
        $this->assertEqual(1, $num);
    }

    public function testOrder()
    {
        $keys = array('test1', 'test2', 'test3');
        foreach ($keys as $k) {
            $this->queue->createItem($k);
        }

        $first = $this->queue->claimItem();
        $this->assertEqual($first->data, $keys[0]);

        $second = $this->queue->claimItem();
        $this->assertEqual($second->data, $keys[1]);

        $this->queue->releaseItem($first);

        $third = $this->queue->claimItem();
        $this->assertEqual($third->data, $keys[2]);

        $first_again = $this->queue->claimItem();
        $this->assertEqual($first_again->data, $keys[0]);

        $num = $this->queue->numberOfItems();
        $this->assertEqual(0, $num);
    }

    /*
    public function lease()
    {
        $data = 'test-queue-item';
        $res = $this->queue->createItem($data);
        $num = $this->queue->numberOfItems();
        $this->assertEquals(1, $num);
        $item = $this->queue->claimItem(1);
        // In Redis 2.4 the expire could be between zero to one seconds off. 
        sleep(2);
        $expired = $this->queue->expire();
        $this->assertEquals(1, $expired);
        $this->assertEquals(1, $this->queue->numberOfItems());
        // Create a second queue to test expireAll()
        $q2 = new RedisQueue($this->name . '_2');
        $q2->createItem($data);
        $q2->createItem($data);
        $this->assertEquals(2, $q2->numberOfItems());
        $item = $this->queue->claimItem(1);
        $item2 = $q2->claimItem(1);
        $this->assertEquals(1, $q2->numberOfItems());
        sleep(2);
        $expired = $this->queue->expireAll();
        $this->assertEquals(2, $expired);
        $this->assertEquals(1, $this->queue->numberOfItems());
        $this->assertEquals(2, $q2->numberOfItems());
        $q2->deleteQueue();
    }
     */
}