/**
 * @ngdoc object
 * @name cd
 *
 * @description
 * ## Checkdesk App
 *
 * The Checkdesk application is an AngularJS based front-end consuming
 * web-servicesprovided by a Drupal powered back-end.
 */
var app = angular.module('Checkdesk', [
      'pascalprecht.translate',
      'cd.l10n',
      'cd.translationUI',
      'cd.page',
      'cd.services',
      'cd.liveblog',
      'cd.report',
      'cd.story'
    ]),
    cdLiveblog = angular.module('cd.liveblog', ['pascalprecht.translate']),
    cdPage = angular.module('cd.page', ['pascalprecht.translate']),
    cdReport = angular.module('cd.report', ['pascalprecht.translate']),
    cdStory = angular.module('cd.story', ['pascalprecht.translate']),
    cdServices = angular.module('cd.services', ['ngResource', 'cd.csrfToken']);
