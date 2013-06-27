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


  // User pages
  $routeProvider.when('/user/register', {
    templateUrl: 'templates/user/userForm.html',
    controller: 'UserFormCtrl'
  });
  $routeProvider.when('/user/login', {
    templateUrl: 'templates/user/userLogin.html',
    controller: 'UserLoginCtrl'
  });
  $routeProvider.when('/user/password', {
    templateUrl: 'templates/user/userForgotPassword.html',
    controller: 'UserForgotPasswordCtrl'
  });
  $routeProvider.when('/user/:uid', {
    templateUrl: 'templates/user/userProfile.html',
    controller: 'UserProfileCtrl'
  });
  $routeProvider.when('/user/:uid/edit', {
    templateUrl: 'templates/user/userForm.html',
    controller: 'UserFormCtrl'
  });


  // Liveblog pages
  $routeProvider.when('/liveblog', {
    templateUrl: 'templates/liveblog.html',
    controller: 'LiveblogCtrl'
  });


  // Reports pages
  $routeProvider.when('/reports', {
    templateUrl: 'templates/reports.html',
    controller: 'ReportsCtrl'
  });
  $routeProvider.when('/report/add', {
    templateUrl: 'templates/reportForm.html',
    controller: 'ReportFormCtrl'
  });
  $routeProvider.when('/report/:nid', {
    templateUrl: 'templates/report.html',
    controller: 'ReportCtrl'
  });
  $routeProvider.when('/report/:nid/edit', {
    templateUrl: 'templates/reportForm.html',
    controller: 'ReportFormCtrl'
  });

  $routeProvider.otherwise({ redirectTo: '/liveblog' });
}]);
