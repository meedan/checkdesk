Feature: User
  In order to do some things on the application
  As an application user
  I need to be able to register, login and logout
 
@api
Scenario: User login directly
  Given users:
  | name   | mail               | pass   |
  | Meedan | meedan@example.com | 123456 |
  And I am not logged in
  And I am on "/user"
  When I fill in "E-mail" with "meedan"
  And I fill in "Password" with "123456"
  And I press "Sign in"
  Then I should see "Meedan" in the "#user-menu" element

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
