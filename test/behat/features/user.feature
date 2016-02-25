Feature: User
  In order to do some things on the application
  As an application user
  I need to be able to register, login and logout
 
@api @javascript
Scenario: User goes to profile
  Given users:
  | name   | mail               | pass   |
  | Meedan | meedan@example.com | 123456 |
  And I am not logged in
  And I am on "/user"
  When I fill in "E-mail" with "meedan"
  And I fill in "Password" with "123456"
  And I press "Sign in"
  And I click "Meedan"
  And I wait for 3 seconds
  And I click "My account"
  Then I should be on "/en/user"
  And I wait for 10 seconds
  And I should see "Meedan's reports"

@api
Scenario: Sign in link
  Given I am on the homepage
  When I am not logged in
  Then I should see the link "Sign in"
  When I am logged in as a user with the "citizen journalist" role
  Then I should not see the link "Sign in"

@api @javascript
Scenario: Notifications
  Given I am on the homepage
  And I am logged in as a user with the "citizen journalist" role
  And a report from URL "http://meedan.org" flagged as "factcheck_journalist" and with status "In Progress"
  And I go to the last node
  And I fill in "comment_body[und][0][value]" with "Footnote test"
  And press "Add footnote"
  And I wait for 10 seconds
  When I am logged in as a user with the "journalist" role
  Then the ".notifications-count" element should contain "1"
  And I remove the created nodes

@api @javascript
Scenario: Notifications - Report flagged as spam
  Given I am logged in as a user with the "citizen journalist" role
  And a report from URL "http://meedan.org"
  When I go to the last node
  And I click on span ".icon-flag"
  And I click "Flag spam"
  And I wait for 20 seconds
  And I fill in "Reason" with "Test"
  And press "Flag spam"
  And I wait for 10 seconds
  When I am logged in as a user with the "journalist" role
  Then the ".notifications-count" element should contain "1"
  And I remove the created nodes

@api @javascript
Scenario: Notifications - Report flagged for graphic content
  Given a report from URL "http://meedan.org"
  And I am logged in as a user with the "flag graphic" permission
  When I go to the last node
  And I click on span ".icon-flag"
  And I click "Flag graphic content"
  And I wait for 20 seconds
  Then I fill in "Reason" with "Test"
  And press "Flag graphic content"
  When I am logged in as a user with the "journalist" role
  Then the ".notifications-count" element should contain "1"
  And I remove the created nodes

@api @javascript
Scenario: Notifications - Report flagged for fact checking
  Given a report from URL "http://meedan.org"
  And I am logged in as a user with the "flag factcheck" permission
  When I go to the last node
  And I click on span ".icon-flag"
  And I click "Flag for fact-checking"
  And I wait for 20 seconds
  Then I fill in "Reason" with "Test"
  And press "Flag for fact-checking"
  When I am logged in as a user with the "journalist" role
  Then the ".notifications-count" element should contain "1"
  And I remove the created nodes

@api
Scenario: Checking the Homepage
  Given I am logged in as a user with the "citizen journalist" role
  And I am on the homepage
  Then I should see the heading "Most popular"
  And I should see the heading "New and updated stories"

@api
Scenario: Sign in 
  Given users:
  | name    | pass   |
  | noha121 | 123456 |
  And I am not logged in
  And I am on "/user"
  When I fill in "Email address or display name" with "noha121"
  And I fill in "Password" with "123456"
  And I press "Sign in"
  Then I should see "noha121" in the "#user-menu" element

@api @javascript
Scenario: Checking the Arabic Homepage
  Given I am logged in as a user with the "citizen journalist" role
  And I am on the homepage
  And I visit "/ar"
  Then I should see the heading "قصص جديدة و محدثة"
  And I should see the heading "الأكثر انتشارا"
