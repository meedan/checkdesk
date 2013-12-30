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
