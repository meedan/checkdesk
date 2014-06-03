Feature: Report
  In order to verify media
  As a user
  I need to be able to create and manage reports

@api @javascript
Scenario: Preview report
  Given I am logged in as a user with the "citizen journalist" role
  When I click "Submit report"
  Then I should not see a ".bookmarklet-preview" element
  When I fill in "Add a link" with "http://meedan.org"
  And I wait for 10 seconds
  Then I should see a ".bookmarklet-preview" element

@api @javascript
Scenario: Submit report
  Given I am logged in as a user with the "citizen journalist" role
  And I click "Submit report"
  When I fill in "Add a link" with "http://meedan.org"
  And I press "Submit"
  Then I should see the success message "Report Meedan.org has been created."

@api
Scenario: Flag Icon - Journalist
  Given a report from URL "http://meedan.org" flagged as "factcheck_journalist" and with status "In Progress" 
  And I am logged in as a user with the "journalist" role
  When I go to the last node
  Then I should not see the link "Flag spam"
  And I should see the link "Flag graphic content"
  And I should not see the link "Flag for fact-checking"
  And I remove the created nodes

@api
Scenario: Flag Icon - Citizen Journalist
  Given a report from URL "http://meedan.org" flagged as "factcheck_journalist" and with status "In Progress" 
  And I am logged in as a user with the "citizen journalist" role
  When I go to the last node
  Then I should see the link "Flag spam"
  And I should see the link "Flag graphic content"
  And I should see the link "Flag for fact-checking"
  And I remove the created nodes

@api
Scenario: Flag Icon - Anonymous
  Given a report from URL "http://meedan.org" flagged as "factcheck_journalist" and with status "In Progress" 
  And I am an anonymous user
  When I go to the last node
  Then I should not see the link "Flag spam"
  And I should not see the link "Flag graphic content"
  And I should not see the link "Flag for fact-checking"
  And I remove the created nodes

@api @javascript
Scenario: Add Footnote
  Given a report from URL "http://meedan.org" flagged as "factcheck_journalist" and with status "In Progress" 
  And I am logged in as a user with the "citizen journalist" role
  When I go to the last node
  And I fill in "comment_body[und][0][value]" with "Footnote test"
  And press "Add footnote"
  And I wait for 10 seconds
  Then I should see "Footnote test"
  And the "comment_body[und][0][value]" field should contain ""
  And I remove the created nodes

@api @javascript
Scenario: Add Footnote - Anonymous
  Given a report from URL "http://meedan.org" flagged as "factcheck_journalist" and with status "In Progress" 
  And I am an anonymous user
  When I go to the last node
  Then I should not see "Add footnote"
  And I remove the created nodes

@api
Scenario: Add Footnote - Checking the button exists
  Given a report from URL "http://meedan.org" flagged as "factcheck_journalist" and with status "In Progress" 
  And I am logged in as a user with the "citizen journalist" role
  When I go to the last node
  Then I should see "Add footnote"
  And I remove the created nodes

@api @javascript
Scenario: Turn on fact-checking
  Given a report from URL "http://meedan.org"
  And I am logged in as a user with the "journalist" role
  When I go to the last node
  Then I should not see "In Progress"
  When I click "Actions"
  And I wait for 2 seconds
  And I click "Turn on fact-checking"
  And I wait for 15 seconds
  Then I should see "In Progress"
  And I remove the created nodes

@api @javascript
Scenario: Change status to verified
  Given a report from URL "http://meedan.org" flagged as "factcheck_journalist" and with status "In Progress" 
  And I am logged in as a user with the "journalist" role
  When I go to the last node
  Then I should see "In Progress"
  And I should not see "Verified"
  When I click on span "Edit Status"
  And I click on label "Verified"
  And press "Add footnote"
  And I wait for 10 seconds
  Then I should see "Verified"
  And I should not see "In Progress"
  And I remove the created nodes

@api @javascript
Scenario: Journalist - Edit status (false)
  Given a report from URL "http://meedan.org" flagged as "factcheck_journalist" and with status "In Progress"
  And I am logged in as a user with the "journalist" role
  When I go to the last node
  Then I should see "In Progress"
  And  should not see "False"
  When I click on span "Edit Status"
  When I click on label "False"
  And press "Add footnote"
  And  I wait for 10 seconds
  Then I should see "False"
  And I should not see "In Progress"
  And I remove the created nodes

@api @javascript
Scenario: Journalist - Edit status (undetermined)
  Given a report from URL "http://meedan.org" flagged as "factcheck_journalist" and with status "In Progress"
  And I am logged in as a user with the "journalist" role
  When I go to the last node
  Then I should see "In Progress"
  And  I should not see "Undetermined"
  When I click on span "Edit Status"
  When I click on label "Undetermined"
  And press "Add footnote"
  And  I wait for 10 seconds
  Then I should see "Undetermined"
  And I should not see "In Progress"
  And I remove the created nodes

@api @javascript
Scenario: Journalist - Edit status (not applicable)
  Given a report from URL "http://meedan.org" flagged as "factcheck_journalist" and with status "In Progress"
  And I am logged in as a user with the "journalist" role
  When I go to the last node
  Then I should see "In Progress"
  And  I should not see "Not Applicable"
  When I click on span "Edit Status"
  When I click on label "Not Applicable"
  And press "Add footnote"
  And  I wait for 10 seconds
  Then I should see "Not Applicable"
  And I should not see "In Progress"
  And I remove the created nodes

@api @javascript
Scenario: Flag report as spam
  Given a report from URL "http://meedan.org"
  And I am logged in as a user with the "flag spam" permission
  When I go to the last node
  And I click on span ".icon-flag"
  And I click "Flag spam"
  And I wait for 20 seconds
  And I fill in "Reason" with "Test"
  And press "Flag spam"
  And I wait for 10 seconds
  And I click on span ".icon-flag"
  Then I should see "Flagged as spam"
  And I remove the created nodes

@api @javascript
Scenario: Flag a report for fact-checking
  Given a report from URL "http://meedan.org"
  And I am logged in as a user with the "flag factcheck" permission
  When I go to the last node
  And I click on span ".icon-flag"
  And I click "Flag for fact-checking"
  And I wait for 20 seconds
  And I fill in "Reason" with "Test"
  And press "Flag for fact-checking"
  And I wait for 10 seconds
  And I click on span ".icon-flag"
  Then  I should see "Flagged for fact-checking"
  And I remove the created nodes

@api @javascript
Scenario: Journalist Flag Graphic
  Given a report from URL "http://meedan.org"
  And I am logged in as a user with the "flag graphic_journalist" permission
  When I go to the last node
  And I click on span ".icon-ellipsis-h"
  And I click "Flag graphic content"
  And I wait for 20 seconds
  And I fill in "Reason" with "Test"
  And press "Flag graphic content"
  And I wait for 10 seconds
  And I click on span ".icon-ellipsis-h"
  Then I should see "Flagged graphic content"
  And I remove the created nodes
