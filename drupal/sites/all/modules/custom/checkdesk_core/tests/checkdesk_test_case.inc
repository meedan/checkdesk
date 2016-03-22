<?php

class CheckdeskTestCase extends DrupalWebTestCase {

  // A user with permissions
  protected $web_user;

  // Upload directory
  protected $public_files_directory = '/tmp';

  // Our own implementation of drupalLogin()
  // We need this because we have different labels for the sign in and logout links
  // @see https://api.drupal.org/api/drupal/modules!simpletest!drupal_web_test_case.php/function/DrupalWebTestCase%3A%3AdrupalLogin/7
  protected function checkdeskLogin(stdClass $account) {
    if ($this->loggedInUser) {
      $this->drupalLogout();
    }

    $edit = array(
      'name' => $account->name,
      'pass' => $account->pass_raw
    );
    $this->drupalPost('user', $edit, t('Sign in'));

    // If a "log out" link appears on the page, it is almost certainly because
    // the login was successful.
    $pass = $this->assertLink(t('Logout'), 0, t('User %name successfully logged in.', array('%name' => $account->name)), t('User login'));

    if ($pass) {
      $this->loggedInUser = $account;
    }
  }

  protected function authenticate($permissions = array()) {
    $web_user = $this->drupalCreateUser($permissions);
    $web_user->roles[] = 'authenticated user';
    user_save($web_user);
    $this->checkdeskLogin($web_user);
    $this->web_user = $web_user;
  }

  // Runs before each test
  public function setUp() {
    // Switch to testing database
    $this->dbs = $dbs = $GLOBALS['databases'];
    $dbs['default'] = $dbs['test'];
    $GLOBALS['databases'] = $dbs;
    $this->setup = TRUE;
  }

  // Runs after each test
  public function tearDown() {
    // Switch back to default database
    $GLOBALS['databases'] = $this->dbs;
    $this->dbs = NULL;
    // @TODO Remove any testing data
  }
}
