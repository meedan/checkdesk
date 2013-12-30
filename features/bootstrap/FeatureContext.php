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
      $this->nodes_to_be_removed = array();
      $story = (object) array(
        'title' => $story_title,
        'type' => 'discussion',
        'language' => 'en',
        'status' => 1,
        'uid' => 1,
      );
      node_save($story);

      foreach ($updates->getHash() as $update) {
        $update = (object) $update;
        $update->type = 'post';
        $update->language = 'en';
        $update->status = 1;
        $update->field_desk[LANGUAGE_NONE][0]['target_id'] = $story->nid;
        node_save($update); // This does not work with entity reference fields: $this->getDriver()->createNode($update);
        $this->nodes_to_be_removed[] = $update;
      }

      // For some reason, if we add the nodes to $this->nodes, they are removed before we go to the next page
      $this->nodes_to_be_removed[] = $story;
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
     * @Then /^menu item "([^"]*)" should be expanded$/
     */
    public function menuItemShouldBeExpanded($item)
    {
      $page = $this->getSession()->getPage();
      $element = $page->find('css', $item);
      if ($element->hasClass('open')) {
        return; 
      }
      throw new \Exception();
    }

    /**
     * @Then /^menu item "([^"]*)" should not be expanded$/
     */
    public function menuItemShouldNotBeExpanded($item)
    {
      $page = $this->getSession()->getPage();
      $element = $page->find('css', $item);
      if ($element->hasClass('open')) {
        throw new \Exception();
      }
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
