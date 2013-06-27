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
var app = angular.module('cd', [
      'pascalprecht.translate',
      'cd.l10n',
      'cd.translationUI',
      'cd.page',
      'cd.services',
      'cd.liveblog',
      'cd.report',
      'cd.story'
    ]),

    /**
     * @ngdoc object
     * @name cd.services
     *
     * @description
     * The `cd.services` module houses all API integration of the Checkdesk app.
     */
    cdServices = angular.module('cd.services', ['ngResource', 'cd.csrfToken']),

    /**
     * @ngdoc object
     * @name cd.liveblog
     *
     * @description
     * The `cd.liveblog` module manages the liveblog page of the Checkdesk app.
     */
    cdLiveblog = angular.module('cd.liveblog', ['pascalprecht.translate']),

    /**
     * @ngdoc object
     * @name cd.page
     *
     * @description
     * The `cd.page` module houses services and controllers to maintain the
     * overall page state of the Checkdesk app.
     */
    cdPage = angular.module('cd.page', ['pascalprecht.translate']),

    /**
     * @ngdoc object
     * @name cd.report
     *
     * @description
     * The `cd.report` module manages the reports pages of the Checkdesk app.
     */
    cdReport = angular.module('cd.report', ['pascalprecht.translate']),

    /**
     * @ngdoc object
     * @name cd.story
     *
     * @description
     * The `cd.story` module manages the stories pages of the Checkdesk app.
     */
    cdStory = angular.module('cd.story', ['pascalprecht.translate']);
