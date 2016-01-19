<?php

use Behat\Behat\Context\ClosuredContextInterface,
    Behat\Behat\Context\TranslatedContextInterface,
    Behat\Behat\Context\BehatContext,
    Behat\Behat\Exception\PendingException;
use Behat\Gherkin\Node\PyStringNode,
    Behat\Gherkin\Node\TableNode;
use Behat\MinkExtension\Context\MinkContext;
use Drupal\DrupalExtension\Hook\Scope\EntityScope;

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
      $username = variable_get('checkdesk_tests_http_user', '');
      $password = variable_get('checkdesk_tests_http_password', '');
      if (!empty($username) && !empty($password)) {
        $this->getSession()->getDriver()->setBasicAuth($username, $password);
      }
    }

    /**
     * Call this function before nodes are created.
     *
     * @beforeNodeCreate
     */
    public function alterNodeObject($event) {
      $node = $event->getEntity();
      if ($node->type === 'discussion') {
        $node->field_lead_image[LANGUAGE_NONE] = array();
      }
    }

    /**
     * @Given /^I enter the report URL "([^"]*)" and wait$/
     */
    public function iEnterTheReportUrlAndWait($url)
    {
      $this->getSession()->switchToIFrame('seamless');
      $this->fillField('edit-field-link-und-0-url', $url);
      $this->getSession()->wait(20000);
    }

    /**
     * @Given /^I wait for (\d+) seconds$/
     */
    public function iWaitForSeconds($time)
    {
      $this->getSession()->wait(intval($time) * 1000);
    }

    /**
     * @Given /^from "([^"]*)" I select "([^"]*)"$/
     */
    public function fromISelect($select, $option)
    {
      $page = $this->getSession()->getPage();
      $field = $page->findField($select);
      $field->setValue($option);
    }

    /**
     * @When /^I click on ([^ ]*) "([^"]*)"$/
     */
    public function iClickOn($tag, $text)
    {
      $page = $this->getSession()->getPage();
      foreach ($page->findAll('css', $tag) as $element) {
        if (
          (trim(strip_tags($element->getHtml())) === $text) ||
          (preg_match('/^\./', $text) && preg_match('/(^| )' . preg_replace('/^\./', '', $text) . '( |$)/', $element->getAttribute('class')))
        ) {
          $element->click();
          return;
        }
      }
      throw new \Exception('Element not found');
    }

    /**
     * @When /^I check the "([^"]*)" radio button$/
     */
    public function iCheckTheRadioButton($labeltext)
    {
      $page = $this->getSession()->getPage();
      foreach ($page->findAll('css', 'label') as $label) {
        if (trim($labeltext) === trim(strip_tags($label->getHtml()))) {
          foreach ($page->findAll('css', 'input[type="radio"]') as $radio) {
            if ($radio->getAttribute('id') === $label->getAttribute('for')) {
              $this->fillField($radio->getAttribute('name'), $radio->getAttribute('value'));
              return;
            }
          }
        }
      }
      throw new \Exception('Radio button not found');
    }

    /**
     * @Given /^I press "([^"]*)" in "([^"]*)"$/
     */
    public function iPressIn($button, $form)
    {
      $page = $this->getSession()->getPage();
      $element = $page->find('css', "#$form input[value=\"$button\"]");
      $element->click();
    }

    /**
     * @Given /^a story "([^"]*)" with the following updates:$/
     */
    public function aStoryWithTheFollowingUpdates($story_title, TableNode $updates)
    {
      if (!isset($this->nodes_to_be_removed)) {
        $this->nodes_to_be_removed = array();
      }

      $story = (object) array(
        'title' => $story_title,
        'type' => 'discussion',
        'language' => 'en',
        'status' => 1,
        'uid' => 1,
        'promote' => 0,
        'sticky' => NODE_NOT_STICKY,
      );
      $story->field_additional_authors[LANGUAGE_NONE] = array();
      $story->field_lead_image[LANGUAGE_NONE] = array();
      node_save($story);

      foreach ($updates->getHash() as $update) {
        $update = (object) $update;
        $update->type = 'post';
        $update->language = 'en';
        $update->status = 1;
        $update->promote = 0;
        $update->sticky = NODE_NOT_STICKY;
        $update->field_desk[LANGUAGE_NONE][0]['target_id'] = $story->nid;
        $update->field_additional_authors[LANGUAGE_NONE] = array();

        node_save($update); // This does not work with entity reference fields: $this->getDriver()->createNode($update);
        $this->nodes_to_be_removed[] = $update;
      }

      // For some reason, if we add the nodes to $this->nodes, they are removed before we go to the next page
      $this->nodes_to_be_removed[] = $story;
    }

    /**
     * @Given /^I go to the last node$/
     */
    function iGoToTheLastNode() {
      $nid = db_query('SELECT nid FROM {node} ORDER BY nid DESC LIMIT 1')->fetchField();
      $this->getSession()->visit($this->locatePath('/node/' . $nid));
    }

    /**
     * @Given /^a report from URL "([^"]*)"$/
     */
    public function aReportFromUrl($url)
    {
      if (!isset($this->nodes_to_be_removed)) {
        $this->nodes_to_be_removed = array();
      }

      $report = (object) array(
        'type' => 'media',
        'language' => 'en',
        'status' => 1,
        'uid' => 1,
        'comment' => 2,
        'promote' => 1,
        'sticky' => NODE_NOT_STICKY,
      );
      $report->field_link[LANGUAGE_NONE][0]['url'] = $url;

      node_save($report);

      // For some reason, if we add the nodes to $this->nodes, they are removed before we go to the next page
      $this->nodes_to_be_removed[] = $report;
    }

    /**
     * @Given /^a report from URL "([^"]*)" flagged as "([^"]*)" and with status "([^"]*)"$/
     */
    public function aReportFromUrlFlaggedAsAndWithStatus($url, $flag_name, $status)
    {
      if (!isset($this->nodes_to_be_removed)) {
        $this->nodes_to_be_removed = array();
      }

      $report = (object) array(
        'type' => 'media',
        'language' => 'en',
        'status' => 1,
        'uid' => 1,
        'comment' => 2,
        'promote' => 1,
        'sticky' => NODE_NOT_STICKY,
      );
      $report->field_link[LANGUAGE_NONE][0]['url'] = $url;

      $tids = array_keys(taxonomy_get_term_by_name($status));
      $report->field_rating[LANGUAGE_NONE][0]['tid'] = $tids[0];

      node_save($report);

      $flag = flag_get_flag($flag_name);
      $flag->flag('flag', $report->nid);

      // For some reason, if we add the nodes to $this->nodes, they are removed before we go to the next page
      $this->nodes_to_be_removed[] = $report;
    }

    /**
     * @Given /^I remove the created nodes$/
     */
    public function iRemoveTheCreatedNodes()
    {
      foreach ($this->nodes_to_be_removed as $node) {
        $this->nodes[] = $node;
      }
      $this->nodes_to_be_removed = array();
    }

    /**
     * @Then /^element "([^"]*)" should be expanded$/
     */
    public function elementShouldBeExpanded($item)
    {
      $page = $this->getSession()->getPage();
      $element = $page->find('css', $item);
      if ($element->hasClass('open')) {
        return; 
      }
      throw new \Exception();
    }

    /**
     * @Then /^element "([^"]*)" should not be expanded$/
     */
    public function elementShouldNotBeExpanded($item)
    {
      $page = $this->getSession()->getPage();
      $element = $page->find('css', $item);
      if ($element->hasClass('open')) {
        throw new \Exception();
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
              <img src="data:image/png;base64,' . $base64 . '" id="checkdesk-tests-screenshot" style="width: 100%;" />
            <p>';
    }

    /**
     * Determine if the a user is already logged in.
     */
    public function loggedIn() {
      $session = $this->getSession();
      $session->visit($this->locatePath('/user'));

      // If a logout link is found, we are logged in. While not perfect, this is
      // how Drupal SimpleTests currently work as well.
      $element = $session->getPage();
      return $element->findLink($this->getDrupalText('log_out'));
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
