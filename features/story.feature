Feature: Story
  In order to organize information
  As a journalist
  I need to be able to create and manage stories

@api
Scenario: Update story
  Given "discussion" nodes:
  | title        |
  | Meedan Story |
  And I am logged in as a user with the "journalist" role
  And I click "Update story"
  When I fill in "Update headline" with "Update for Meedan Story"
  And I select "Meedan Story" from "edit-field-desk-und"
  And I press "Publish" in "post-node-form"
  Then I should see the success message "Update Update for Meedan Story has been created."

@api
Scenario: Show story on liveblog only if it has updates
  Given a story "Meedan Story" with the following updates:
  | title                   |
  | Update for Meedan Story |
  And "discussion" nodes:
  | title              |
  | Meedan Empty Story |
  And I am logged in as a user with the "journalist" role
  When I go to the homepage
  Then I should see "Meedan Story"
  And I should not see "Meedan Empty Story"
  And I remove the created nodes

@api @javascript
Scenario: Display compose update form on story page
  Given a story "Meedan Story" with the following updates:
  | title                   |
  | Update for Meedan Story |
  And I am logged in as a user with the "journalist" role
  When I go to the homepage
  And I click "Meedan Story"
  Then element ".compose-update-form" should not be expanded
  When I click "Compose Update"
  And I wait for 5 seconds
  Then element ".compose-update-form" should be expanded
  And I remove the created nodes

@api @javascript
Scenario: Open create story modal
  Given I am logged in as a user with the "journalist" role
  When I go to the homepage
  Then element ".create-story" should not be expanded
  When I click "Create story"
  And I wait for 5 seconds
  Then element ".create-story" should be expanded

@api @javascript
Scenario: Sharing options for stories
  Given a story "Share Story" with the following updates:
  | title  |
  | Update |
  And I am not logged in
  When I go to the homepage
  And I click "Share Story"
  And I click "Share"
  And I wait for 1 seconds
  Then I should see "Share on Facebook"
  And I should see "Share on Twitter"
  And I should see "Share on Google"
  And I remove the created nodes
