/**
 * @doc app
 * @id index
 * @name Checkdesk App
 *
 * @description
 * The Checkdesk application is an AngularJS based front-end consuming
 * web-servicesprovided by a Drupal powered back-end.
 */
var app = angular.module('Checkdesk', [
      'pascalprecht.translate',
      'cd.l10n',
      'cd.translationUI',
      'cd.page',
      'cd.services'
    ]),
    cdServices = angular.module('cd.services', ['ngResource', 'cd.csrfToken']);
