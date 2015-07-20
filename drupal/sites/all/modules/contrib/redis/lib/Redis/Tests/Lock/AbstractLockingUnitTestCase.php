<?php

abstract class Redis_Tests_Lock_AbstractLockingUnitTestCase extends Redis_Tests_AbstractUnitTestCase
{
    /**
     * Ensure lock flush at tear down.
     *
     * @var array
     */
    protected $backends = array();

    public function setUp()
    {
        parent::setUp();

        $this->backends = array();
    }

    public function tearDown()
    {
        if (!empty($this->backends)) {
            foreach ($this->backends as $backend) {
                $backend->lockReleaseAll();
            }

            $this->backends = array();
        }

        parent::tearDown();
    }

    /**
     * Create a new lock backend with a generated lock id
     *
     * @return Redis_Lock_Backend_Interface
     */
    public function createLockBackend()
    {
        $class = Redis_Client::getClass(Redis_Client::REDIS_IMPL_LOCK);

        if (!class_exists($class)) {
            throw new \Exception("Lock backend class does not exist");
        }

        return $this->backends[] = new $class();
    }

    public function testLock()
    {
        $b1 = $this->createLockBackend();
        $b2 = $this->createLockBackend();

        $s = $b1->lockAcquire('test1', 20000);
        $this->assertTrue($s, "Lock test1 acquired");

        $s = $b1->lockAcquire('test1', 20000);
        $this->assertTrue($s, "Lock test1 acquired a second time by the same thread");

        $s = $b2->lockAcquire('test1', 20000);
        $this->assertFalse($s, "Lock test1 could not be acquired by another thread");

        $b2->lockRelease('test1');
        $s = $b2->lockAcquire('test1');
        $this->assertFalse($s, "Lock test1 could not be released by another thread");

        $b1->lockRelease('test1');
        $s = $b2->lockAcquire('test1');
        $this->assertTrue($s, "Lock test1 has been released by the first thread");
    }

    public function testReleaseAll()
    {
        $b1 = $this->createLockBackend();
        $b2 = $this->createLockBackend();

        $b1->lockAcquire('test1', 200);
        $b1->lockAcquire('test2', 2000);
        $b1->lockAcquire('test3', 20000);

        $s = $b2->lockAcquire('test2');
        $this->assertFalse($s, "Lock test2 could not be released by another thread");
        $s = $b2->lockAcquire('test3');
        $this->assertFalse($s, "Lock test4 could not be released by another thread");

        $b1->lockReleaseAll();

        $s = $b2->lockAcquire('test1');
        $this->assertTrue($s, "Lock test1 has been released");
        $s = $b2->lockAcquire('test2');
        $this->assertTrue($s, "Lock test2 has been released");
        $s = $b2->lockAcquire('test3');
        $this->assertTrue($s, "Lock test3 has been released");

        $b2->lockReleaseAll();
    }
}