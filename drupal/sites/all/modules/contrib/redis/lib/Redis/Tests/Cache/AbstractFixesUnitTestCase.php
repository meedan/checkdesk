<?php

/**
 * Bugfixes made over time test class.
 */
abstract class Redis_Tests_Cache_AbstractFixesUnitTestCase extends Redis_Tests_Cache_AbstractUnitTestCase
{
    public function testTemporaryCacheExpire()
    {
        global $conf; // We are in unit tests so variable table does not exist.

        $backend = $this->getBackend();

        // Permanent entry.
        $backend->set('test1', 'foo', CACHE_PERMANENT);
        $data = $backend->get('test1');
        $this->assertNotEqual(false, $data);
        $this->assertIdentical('foo', $data->data);

        // Permanent entries should not be dropped on clear() call.
        $backend->clear();
        $data = $backend->get('test1');
        $this->assertNotEqual(false, $data);
        $this->assertIdentical('foo', $data->data);

        // Expiring entry with permanent default lifetime.
        $conf['cache_lifetime'] = 0;
        $backend->set('test2', 'bar', CACHE_TEMPORARY);
        sleep(2);
        $data = $backend->get('test2');
        $this->assertNotEqual(false, $data);
        $this->assertIdentical('bar', $data->data);
        sleep(2);
        $data = $backend->get('test2');
        $this->assertNotEqual(false, $data);
        $this->assertIdentical('bar', $data->data);

        // Expiring entry with negative lifetime.
        $backend->set('test3', 'baz', time() - 100);
        $data = $backend->get('test3');
        $this->assertEqual(false, $data);

        // Expiring entry with short lifetime.
        $backend->set('test4', 'foobar', time() + 2);
        $data = $backend->get('test4');
        $this->assertNotEqual(false, $data);
        $this->assertIdentical('foobar', $data->data);
        sleep(3);
        $data = $backend->get('test4');
        $this->assertEqual(false, $data);

        // Expiring entry with short default lifetime.
        $conf['cache_lifetime'] = 2;
        $backend->set('test5', 'foobaz', CACHE_TEMPORARY);
        $data = $backend->get('test5');
        $this->assertNotEqual(false, $data);
        $this->assertIdentical('foobaz', $data->data);
        sleep(3);
        $data = $backend->get('test5');
        $this->assertEqual(false, $data);
    }

    public function testDefaultPermTtl()
    {
        $backend = $this->getBackend();
        $this->assertIdentical(Redis_Cache_Base::LIFETIME_PERM_DEFAULT, $backend->getPermTtl());
    }

    public function testUserSetDefaultPermTtl()
    {
        global $conf;
        // This also testes string parsing. Not fully, but at least one case.
        $conf['redis_perm_ttl'] = "3 months";
        $backend = $this->getBackend();
        $this->assertIdentical(7776000, $backend->getPermTtl());
    }

    public function testUserSetPermTtl()
    {
        global $conf;
        // This also testes string parsing. Not fully, but at least one case.
        $conf['redis_perm_ttl_cache'] = "1 months";
        $backend = $this->getBackend();
        $this->assertIdentical(2592000, $backend->getPermTtl());
    }

    public function testPermTtl()
    {
        global $conf;
        // This also testes string parsing. Not fully, but at least one case.
        $conf['redis_perm_ttl_cache'] = "2 seconds";
        $backend = $this->getBackend();
        $this->assertIdentical(2, $backend->getPermTtl());

        $backend->set('test6', 'cats are mean');
        $this->assertIdentical('cats are mean', $backend->get('test6')->data);

        sleep(3);
        $item = $backend->get('test6');
        $this->assertTrue(empty($item));
    }
}
