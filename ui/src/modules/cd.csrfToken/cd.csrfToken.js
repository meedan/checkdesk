/**
 * @ngdoc overview
 * @name cd.csrfToken
 *
 * @description
 * ## Module: cd.csrfToken
 *
 * Integration with Drupal Services X-CSRF-Token header.
 *
 * This code relies on this tag to be added to the page BEFORE the main application
 * script tag.
 *
 *     <script src="services/session/token"></script>
 */
angular.module('cd.csrfToken', [])

  /**
   * @ngdoc method
   * @name cd.csrfToken#config
   * @methodOf cd.csrfToken
   *
   * @description
   * Set the cookie and header name to what the Drupal Services module expects.
   */
  .config(['$httpProvider', function ($httpProvider) {
    $httpProvider.defaults.xsrfCookieName = 'CSRF-Token';
    $httpProvider.defaults.xsrfHeaderName = 'X-CSRF-Token';
  }]);
