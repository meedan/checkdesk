<?php

/**
 * @file
 * Contains potx test class of \Drupal\Core\Language\LanguageManager.
 */

/**
 * Mock class
 */
class PotxMockLanguageManager {

  public static function getStandardLanguageList() {
    return array(
      'af' => array('Test English language', 'Test localized language'),
    );
  }

}
