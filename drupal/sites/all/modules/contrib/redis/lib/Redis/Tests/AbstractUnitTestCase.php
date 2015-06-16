<?php

abstract class Redis_Tests_AbstractUnitTestCase extends DrupalUnitTestCase
{
    /**
     * Is autoloader enabled (system wide)
     *
     * @var boolean
     */
    static protected $loaderEnabled = false;

    /**
     * Enable the autoloader (system wide)
     */
    static protected function enableAutoload()
    {
        if (self::$loaderEnabled) {
            return;
        }
        if (class_exists('Redis_Client')) {
            return;
        }

        spl_autoload_register(function ($className) {
            $parts = explode('_', $className);
            if ('Redis' === $parts[0]) {
                $filename = __DIR__ . '/../lib/' . implode('/', $parts) . '.php';
                return (bool) include_once $filename;
            }
            return false;
        }, null, true);

        self::$loaderEnabled = true;
    }

    /**
     * Drupal $conf array backup
     *
     * @var array
     */
    private $originalConf = array(
        'cache_lifetime'          => null,
        'cache_prefix'            => null,
        'redis_client_interface'  => null,
        'redis_eval_enabled'      => null,
        'redis_flush_mode'        => null,
        'redis_perm_ttl'          => null,
    );

    /**
     * Set up the Redis configuration
     *
     * Set up the needed variables using variable_set() if necessary.
     *
     * @return string
     *   Client interface or null if not exists
     */
    abstract protected function getClientInterface();

    /**
     * Prepare Drupal environmment for testing
     */
    final private function prepareDrupalEnvironment()
    {
        // Site on which the tests are running may define this variable
        // in their own settings.php file case in which it will be merged
        // with testing site
        global $conf;
        foreach (array_keys($this->originalConf) as $key) {
            if (isset($conf[$key])) {
                $this->originalConf[$key] = $conf[$key];
                unset($conf[$key]);
            }
        }
        $conf['cache_prefix'] = $this->testId;
    }

    /**
     * Restore Drupal environment after testing.
     */
    final private function restoreDrupalEnvironment()
    {
        $GLOBALS['conf'] = $this->originalConf + $GLOBALS['conf'];
    }

    /**
     * Prepare client manager
     */
    final private function prepareClientManager()
    {
        $interface = $this->getClientInterface();

        if (null === $interface) {
            throw new \Exception("Test skipped due to missing driver");
        }

        $GLOBALS['conf']['redis_client_interface'] = $interface;
        Redis_Client::reset();
    }

    /**
     * Restore client manager
     */
    final private function restoreClientManager()
    {
        Redis_Client::reset();
    }

    /**
     * {@inheritdoc}
     */
    public function setUp()
    {
        self::enableAutoload();

        $this->prepareDrupalEnvironment();
        $this->prepareClientManager();

        parent::setUp();

        drupal_install_schema('system');
        drupal_install_schema('locale');
    }

    /**
     * {@inheritdoc}
     */
    public function tearDown()
    {
        drupal_uninstall_schema('locale');
        drupal_uninstall_schema('system');

        $this->restoreDrupalEnvironment();
        $this->restoreClientManager();

        parent::tearDown();
    }
}
