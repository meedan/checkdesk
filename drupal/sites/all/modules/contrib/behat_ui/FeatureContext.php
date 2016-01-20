<?php

use Behat\Behat\Context\ClosuredContextInterface,
    Behat\Behat\Context\TranslatedContextInterface,
    Behat\Behat\Context\BehatContext,
    Behat\Behat\Exception\PendingException;
use Behat\Gherkin\Node\PyStringNode,
    Behat\Gherkin\Node\TableNode;
use Behat\MinkExtension\Context\MinkContext;

//
// Require 3rd-party libraries here:
//
//   require_once 'PHPUnit/Autoload.php';
//   require_once 'PHPUnit/Framework/Assert/Functions.php';
//

/**
 * Features context.
 */
class FeatureContext extends Drupal\DrupalExtension\Context\DrupalContext
{
    /**
     * Initializes context.
     * Every scenario gets it's own context object.
     *
     * @param array $parameters context parameters (set them up through behat.yml)
     */
    public function __construct(array $parameters)
    {
      // Initialize your context here
    }

    /**
     * @BeforeStep ~@javascript
     */
    public function beforeStep($event)
    {
      $username = variable_get('behat_ui_http_user', '');
      $password = variable_get('behat_ui_http_password', '');
      if (!empty($username) && !empty($password)) {
        $this->getSession()->getDriver()->setBasicAuth($username, $password);
      }
    }

    /**
     * @Then /^take screenshot$/
     */
    public function takeScreenshot()
    {
      $driver = $this->getSession()->getDriver();
      // Only makes sense on HTML formatting and using the testing module
      $base64 = base64_encode($driver->getScreenshot());
      echo '<p>
              <img src="data:image/png;base64,' . $base64 . '" id="behat-ui-screenshot" style="width: 100%;" />
            <p>';
    }

//
// Place your definition and hook methods here:
//
//    /**
//     * @Given /^I have done something with "([^"]*)"$/
//     */
//    public function iHaveDoneSomethingWith($argument)
//    {
//        doSomethingWith($argument);
//    }
//
}
