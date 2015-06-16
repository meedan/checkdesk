<?php

/**
 * Base implementation for locking functionnal testing.
 */
abstract class Redis_Tests_Cache_AbstractUnitTestCase extends Redis_Tests_AbstractUnitTestCase
{
    protected $backend;

    /**
     * Get cache backend
     *
     * @return Redis_Cache_Base
     */
    final protected function getBackend()
    {
        if (null === $this->backend) {
            $class = Redis_Client::getClass(Redis_Client::REDIS_IMPL_CACHE);

            if (null === $class) {
                throw new \Exception("Test skipped due to missing driver");
            }

            $this->backend = new $class('cache');
        }

        return $this->backend;
    }

    public function setUp()
    {
        parent::setUp();
        $this->backend = null;
    }

    public function tearDown()
    {
        $this->backend = null;
        parent::tearDown();
    }
}
