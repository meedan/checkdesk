/**
 * @ngdoc overview
 * @name cd
 *
 * @description
 * ## Checkdesk App
 *
 * The Checkdesk application is an AngularJS based front-end consuming
 * web-servicesprovided by a Drupal powered back-end.
 */
var app = angular.module('cd', [
      'pascalprecht.translate',
      'cd.l10n',
      'cd.translationUI',
      'cd.page',
      'cd.services',
      'cd.user',
      'cd.liveblog',
      'cd.report',
      'cd.story'
    ]),

    /**
     * @ngdoc overview
     * @name cd.services
     *
     * @description
     * ## Module: cd.services
     * Houses all API integration of the Checkdesk app.
     */
    cdServices = angular.module('cd.services', ['ngResource', 'cd.csrfToken']),

    /**
     * @ngdoc overview
     * @name cd.user
     *
     * @description
     * ## Module: cd.user
     * Manages the login, registration and user pages of the Checkdesk app.
     */
    cdUser = angular.module('cd.user', ['pascalprecht.translate']),

    /**
     * @ngdoc overview
     * @name cd.liveblog
     *
     * @description
     * ## Module: cd.liveblog
     * Manages the liveblog page of the Checkdesk app.
     */
    cdLiveblog = angular.module('cd.liveblog', ['pascalprecht.translate']),

    /**
     * @ngdoc overview
     * @name cd.page
     *
     * @description
     * ## Module: cd.page
     * Houses services and controllers to maintain the
     * overall page state of the Checkdesk app.
     */
    cdPage = angular.module('cd.page', ['pascalprecht.translate']),

    /**
     * @ngdoc overview
     * @name cd.report
     *
     * @description
     * ## Module: cd.report
     * Manages the reports pages of the Checkdesk app.
     */
    cdReport = angular.module('cd.report', ['pascalprecht.translate']),

    /**
     * @ngdoc overview
     * @name cd.story
     *
     * @description
     * ## Module: cd.story
     * Manages the stories pages of the Checkdesk app.
     */
    cdStory = angular.module('cd.story', ['pascalprecht.translate']);
