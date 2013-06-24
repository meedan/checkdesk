/**
 * @ngdoc method
 * @name cd#config
 * @methodOf cd
 *
 * @description
 * Checkdesk UI app configuration. This includes:
 *  - Router configuration
 *  - Enabling HTML5Mode
 *
 * ## Additional notes
 * `templateUrl`'s are affected by the currently set <base> in the
 * index.html. Running this app in a sub-directory needs the correct <base>
 * to be set!
 */
app.config(['$routeProvider', '$locationProvider', function($routeProvider, $locationProvider) {
  // See: http://docs.angularjs.org/guide/dev_guide.services.$location
  $locationProvider.html5Mode(true).hashPrefix('!');

  $routeProvider.when('/liveblog', {
    templateUrl: 'templates/liveblog.html',
    controller: LiveblogCtrl
  });

  $routeProvider.when('/reports', {
    templateUrl: 'templates/reports.html',
    controller: ReportsCtrl
  });

  $routeProvider.when('/report/add', {
    templateUrl: 'templates/reportForm.html',
    controller: ReportFormCtrl
  });
  $routeProvider.when('/report/:nid', {
    templateUrl: 'templates/report.html',
    controller: ReportCtrl
  });
  // Note, here is the technique to reuse a controller and template for two, or
  // more, pages.
  $routeProvider.when('/report/:nid/edit', {
    templateUrl: 'templates/reportForm.html',
    controller: ReportFormCtrl
  });

  $routeProvider.when('/translationsTest', {
    templateUrl: 'templates/translationsTest.html',
    controller: TranslationsTestCtrl
  });

  $routeProvider.otherwise({ redirectTo: '/liveblog' });
}]);
