Feature: Report
  In order to verify media
  As a user
  I need to be able to create and manage reports

@api @javascript
Scenario: Preview report
  Given I am logged in as a user with the "citizen journalist" role
  When I click "Submit report"
  Then I should not see a ".bookmarklet-preview" element
  When I enter the report URL "http://meedan.org" and wait
  Then I should see a ".bookmarklet-preview" element

@api @javascript
Scenario: Submit report
  Given I am logged in as a user with the "citizen journalist" role
  When I click "Submit report"
  And I enter the report URL "http://meedan.org" and wait
  And I press "Submit"
  And I wait for 10 seconds
  Then I should see "Success: Report created"

@api
Scenario: Flag Icon - Journalist
  Given I am on the homepage
  When I am logged in as a user with the "journalist" role
  Then I should not see the link "Flag spam"
  And I should see the link "Flag graphic content"
  And I should not see the link "Flag for fact-checking"

@api
Scenario: Flag Icon - Citizen Journalist
  Given I am on the homepage
  When I am logged in as a user with the "citizen journalist" role
  Then I should see the link "Flag spam"
  And I should see the link "Flag graphic content"
  And I should see the link "Flag for fact-checking"

@api
Scenario: Flag Icon - Anonymous
  Given I am on the homepage
  When I am an anonymous user
  Then I should not see the link "Flag spam"
  And I should not see the link "Flag graphic content"
  And I should not see the link "Flag for fact-checking"
