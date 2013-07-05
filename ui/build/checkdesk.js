/*! checkdesk - v0.1.0 - 2013-07-05
 *  Copyright (c) 2013 Meedan | Licensed MIT
 */
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
 *     <script src="services/session/token.json"></script>
 */
angular.module('cd.csrfToken', [])
  .config(['$httpProvider', function ($httpProvider) {
    $httpProvider.defaults.xsrfCookieName = 'CSRF-Token';
    $httpProvider.defaults.xsrfHeaderName = 'X-CSRF-Token';
  }]);

/**
 * @ngdoc overview
 * @name cd.l10n
 *
 * @description
 * ## Module: cd.l10n
 *
 * Manages all translation and localization aspects of
 * the Checkdesk app.
 */
angular.module('cd.l10n', ['ngCookies', 'pascalprecht.translate', 'cd.translationUI'])

  /**
   * @ngdoc method
   * @name cd.l10n#config
   * @methodOf cd.l10n
   * @requires $translateProvider
   *
   * @description
   * Configures all languages necessary for the Checkdesk app and sets the
   * cdTranslationUI service as the missing translation handler for $translate.
   */
  .config(['$translateProvider', function ($translateProvider) {
    $translateProvider.useUrlLoader('api/i18n?textgroup=ui&angular=1');
    $translateProvider.preferredLanguage('ar');

    $translateProvider.useCookieStorage();

    $translateProvider.useMissingTranslationHandler('cdTranslationUI');
  }]);

cdLiveblog

  /**
   * @ngdoc object
   * @name cd.liveblog.controllers:LiveblogCtrl
   * @requires $scope
   * @requires pageState
   * @requires Story
   *
   * @description
   * Controller for liveblog.html template.
   */
  .controller('LiveblogCtrl', ['$scope', 'pageState', 'Story', function ($scope, pageState, Story) {
    // TODO: This page title management is clunky, could it be moved to the router?
    pageState.headTitle('Liveblog');
    pageState.title('Liveblog');

    $scope.stories = [];

    Story.query(function (stories) {
      for (var i = 0; i < stories.length; i++) {
        // LOL: Hilariously unperformant, we will improve this of course.
        $scope.stories.push(Story.get({ nid: stories[i].nid }));
      }

      pageState.status('ready'); // This page has finished loading
    });
  }]);

cdPage

  /**
   * @ngdoc object
   * @name cd.page.controllers:FooterCtrl
   * @requires $scope
   * @requires pageState
   * @requires Story
   *
   * @description
   * Controller for site footer.
   */
  .controller('FooterCtrl', FooterCtrl = ['$scope', '$translate', 'System', 'User', function ($scope, $translate, System, User) {
    // TODO: Unstub the informationMenu.
    $scope.informationMenu = [
      {
        title: $translate('INFORMATION_MENU_ITEM_ABOUT_TITLE'),
        href: '/about-checkdesk'
      }
    ];

    // TODO: Unstub the footerMenu.
    $scope.footerMenu = [
      {
        title: $translate('FOOTER_MENU_ITEM_MEEDAN_TITLE'),
        href: 'http://meedan.org'
      },
      {
        title: $translate('FOOTER_MENU_ITEM_CHECKDESK_TITLE'),
        href: 'http://checkdesk.org'
      }
    ];
  }]);

cdPage

  /**
   * @ngdoc object
   * @name cd.page.controllers:PageCtrl
   * @requires $scope
   * @requires pageState
   *
   * @description
   * Meta-controller for the <html> tag on the page. Manages page state and the
   * like.
   */
  .controller('PageCtrl', ['$scope', 'pageState', function ($scope, pageState) {
    $scope.pageState = pageState;
  }]);

cdPage

  /**
   * @ngdoc object
   * @name cd.page.controllers:WidgetsSidebarCtrl
   * @requires $scope
   * @requires $translate
   * @requires System
   * @requires User
   *
   * @description
   * Controller for widgets sidebar.
   */
  .controller('WidgetsSidebarCtrl', ['$scope', function ($scope) {
    // TODO: Pull logoSrc from the server.
    $scope.logoSrc = 'http://qa.checkdesk.org/sites/qa.checkdesk.org/files/checkdesk_theme/meedan.png';

    // TODO: Unstub featuredStories content.
    $scope.featuredStories = [
      {
        href: '/story/1510',
        title: 'الشعب يريد إقالةالوزير المتحرش',
        imageSrc: 'http://qa.checkdesk.org/sites/qa.checkdesk.org/files/styles/featured_stories_lead_image/public/adbusters_blog_occupygezi_s_2.jpg?itok=uYCbtd7B',
        description: 'أثار رد وزير الإعلام "صلاح عبد المقصود" على سؤال أحدى الصحفيات في مؤتمر صحفي أمس ضجة كبيرة على مواقع التواصل...'
      }
    ];

    // TODO: Unstub followLinks content.
    $scope.followLinks = [
      {
        href: 'https://www.facebook.com/YomatyEgypt',
        icon: 'icon-facebook'
      },
      {
        href: 'https://twitter.com/YomatyEgypt',
        icon: 'icon-twitter'
      },
      {
        href: 'http://www.youtube.com/user/weladelbaladlt',
        icon: 'icon-youtube'
      }
    ];
  }]);

cdPage

  /**
   * @ngdoc object
   * @name cd.page.controllers:NavbarCtrl
   * @requires $scope
   * @requires $translate
   * @requires User
   *
   * @description
   * Controller for site navigation bar.
   */
  .controller('NavbarCtrl', ['$scope', '$translate', 'User', function ($scope, $translate, User) {
    var updateLangClass = function (mode, langClass) {
          switch (mode) {
            case 'remove':
              $('html').removeClass(langClass);
              break;
            case 'add':
              $('html').addClass(langClass);
              break;
          }
        };

    $scope.currentUser = User.currentUser;
    $scope.isLoggedIn = User.isLoggedIn;

    // TODO: Unstub the mainMenu.
    $scope.mainMenu = [
      {
        title: $translate('MAIN_MENU_ITEM_HOME_LINK'),
        href: '/',
        icon: 'icon-home'
      },
      {
        title: $translate('MAIN_MENU_ITEM_REPORTS_LINK'),
        href: '/reports',
        icon: 'icon-eye-open'
      }
    ];

    // TODO: Unstub the userMenu.
    $scope.$watch('currentUser', function (newVal, oldVal) {
      console.log([newVal, oldVal], 'Watching curentUser');
      if (newVal.uid > 0) {
        $scope.userMenu = [
          {
            title: $translate('USER_MENU_ITEM_LOGOUT_LINK'),
            click: function () {
              // Must send empty POST data for this to work
              User.logout({});
            }
          }
        ];
      } else {
        $scope.userMenu = [
          {
            title: $translate('USER_MENU_ITEM_LOGIN_LINK'),
            href: '/user/login'
          }
        ];
      }
    }, true);

    // Initially set the HTML language class
    updateLangClass('add', $translate.uses());

    $scope.toggleLang = function () {
      updateLangClass('remove', $translate.uses());
      if ($translate.uses() === 'en-NG') {
        $translate.uses('ar');
      } else {
        $translate.uses('en-NG');
      }
      updateLangClass('add', $translate.uses());
    };
  }])

  /**
   * @ngdoc directive
   * @name cd.page.directives:cdMenuItem
   *
   * @description
   * Renders a Checkdesk menu item.
   */
  .directive('cdMenuItem', function () {
    return {
      restrict: 'A',
      scope: { item: '=cdMenuItem' },
      template: ['<a href="{{item.href}}" ng-click="item.click()">',
                   '<span ng-show="item.icon" class="{{item.icon}}"></span>',
                   '{{item.title | translate}}',
                 '</a>'].join('')
    };
  });

/**
 * @ngdoc service
 * @name cd.page.pageState
 *
 * @description
 * State management for the loading status and title of each page.
 */
cdPage
  .factory('pageState', function() {
    var status     = 'loading',
        headTitle  = 'Checkdesk',
        title      = 'Checkdesk';

    return {
      /**
       * @ngdoc method
       * @name cd.page.pageState#status
       * @methodOf cd.page.pageState
       * @param {string=} new page status
       * @returns {string} The current page status
       */
      status: function(newStatus) {
        if (newStatus) {
          status = newStatus;
        }
        return status;
      },

      /**
       * @ngdoc method
       * @name cd.page.pageState#headTitle
       * @methodOf cd.page.pageState
       * @param {string=} new page headTitle
       * @returns {string} The current page headTitle
       */
      headTitle: function(newHeadTitle, appendSiteName) {
        if (newHeadTitle) {
          appendSiteName = !angular.isUndefined(appendSiteName) ? appendSiteName : true;
          headTitle = newHeadTitle;

          if (appendSiteName) {
            headTitle += ' | Checkdesk';
          }
        }
        return headTitle;
      },

      /**
       * @ngdoc method
       * @name cd.page.pageState#title
       * @methodOf cd.page.pageState
       * @param {string=} new page title
       * @returns {string} The current page title
       */
      title: function(newTitle) {
        if (newTitle) {
          title = newTitle;
        }
        return title;
      }
    };
  });

cdReport

  /**
   * @ngdoc object
   * @name cd.liveblog.controllers:ReportCtrl
   * @requires $scope
   * @requires $routeParams
   * @requires pageState
   *
   * @description
   * Controller for report.html template.
   */
  .controller('ReportCtrl', ['$scope', '$routeParams', 'pageState', 'Report', 'ReportActivity', function ($scope, $routeParams, pageState, Report, ReportActivity) {
    $scope.report = Report.get({ nid: $routeParams.nid }, function () {
      pageState.status('ready'); // This page has finished loading
    });
    $scope.reportActivity = ReportActivity.query({ args: [$routeParams.nid] });
  }]);

cdReport

  /**
   * @ngdoc object
   * @name cd.liveblog.controllers:ReportFormCtrl
   * @requires $scope
   * @requires $routeParams
   * @requires $location
   * @requires Report
   *
   * @description
   * Controller for reportForm.html template.
   */
  .controller('ReportFormCtrl', ['$scope', '$routeParams', '$location', 'Report', function ($scope, $routeParams, $location, Report) {
    if ($routeParams.nid) {
      $scope.report = Report.get({ nid: $routeParams.nid });
    } else {
      $scope.report = new Report({
        title: '',
        type: 'media',
        body: {
          und: [
            {
              url: ''
            }
          ]
        },
        field_link: {
          und: [
            {
              url: ''
            }
          ]
        }
      });
    }

    $scope.submit = function() {
      $scope.report.save(function (report) {
        $location.path('/report/' + report.nid);
      });
      return false;
    };

    $scope.cancel = function () {
      if ($routeParams.nid) {
        $location.path('/report/' + $routeParams.nid);
      } else {
        $location.path('/');
      }
    };
  }]);

cdReport

  /**
   * @ngdoc object
   * @name cd.liveblog.controllers:ReportsCtrl
   * @requires $scope
   * @requires pageState
   * @requires Report
   *
   * @description
   * Controller for reportForm.html template.
   */
  .controller('ReportsCtrl', ['$scope', 'pageState', 'Report', function ($scope, pageState, Report) {
    $scope.reports = [];

    Report.query(function (reports) {
      for (var i = 0; i < reports.length; i++) {
        // LOL: Hilariously unperformant, we will improve this of course.
        $scope.reports.push(Report.get({ nid: reports[i].nid }));
      }

      pageState.status('ready'); // This page has finished loading
    });
  }]);

/**
 * @ngdoc service
 * @name cd.services.Comment
 *
 * @description
 * Resource to interact with the Drupal comments API.
 */
cdServices
  .factory('Comment', ['$resource', function($resource) {
    return $resource('api/node/:nid/comments', {}, {
      /**
       * @ngdoc method
       * @name cd.services.Comment#query
       * @methodOf cd.services.Comment
       */
      query: {
        method: 'GET',
        isArray: true
      }
    });
  }]);

/**
 * @ngdoc service
 * @name cd.services.Liveblog
 *
 * @description
 * Resource to retrieve the Drupal API for the liveblog stream.
 */
cdServices
  .factory('Liveblog', ['$resource', function($resource) {
    return $resource('api/views/liveblog', {}, {

      /**
       * @ngdoc method
       * @name cd.services.Liveblog#autorefresh
       * @methodOf cd.services.Liveblog
       */
      autorefresh: {
        url: 'sites/all/modules/custom/checkdesk_core/autorefresh/liveblog.php',
        method: 'GET',
        params: { type: 'discussion', field: 'changed', timestamp: 0 },
        isArray: false
      },

      /**
       * @ngdoc method
       * @name cd.services.Liveblog#query
       * @methodOf cd.services.Liveblog
       */
      query: {
        method: 'GET',
        params: { display_id: 'services_1', args: [] },
        isArray: true
      }
    });
  }]);

/**
 * @ngdoc service
 * @name cd.services.Notification
 *
 * @description
 * Resource to retrieve the Drupal API for the liveblog stream.
 */
cdServices
  .factory('Notification', ['$resource', function($resource) {
    return $resource('api/views/my_notifications', {}, {

      /**
       * @ngdoc method
       * @name cd.services.Notification#autorefresh
       * @methodOf cd.services.Notification
       */
      autorefresh: {
        url: 'sites/all/modules/custom/checkdesk_notifications/ping.php',
        method: 'GET',
        params: { user: 0, timestamp: 0 },
        isArray: false
      },

      /**
       * @ngdoc method
       * @name cd.services.Notification#query
       * @methodOf cd.services.Notification
       */
      query: {
        method: 'GET',
        params: { display_id: 'services_1', args: [] },
        isArray: true
      }
    });
  }]);

/**
 * @ngdoc service
 * @name cd.services.Report
 *
 * @description
 * Resource to interact with the Drupal report node API.
 */
cdServices
  .factory('Report', ['$resource', '$http', function($resource, $http) {
    var Report = $resource('api/node/:nid', { nid: '@nid' }, {
      /**
       * @ngdoc method
       * @name cd.services.Report#query
       * @methodOf cd.services.Report
       */
      query: {
        method: 'GET',
        params: { nid: '', 'parameters[type]': 'media', pagesize: 5 },
        isArray: true
      },

      /**
       * @ngdoc method
       * @name cd.services.Report#get
       * @methodOf cd.services.Report
       */
      get: {
        method: 'GET',
        isArray: false
      },

      /**
       * @ngdoc method
       * @name cd.services.Report#save
       * @methodOf cd.services.Report
       */
      save: {
        method: 'POST',
        params: { nid: '' }
      },

      /**
       * @ngdoc method
       * @name cd.services.Report#update
       * @methodOf cd.services.Report
       */
      update: {
        method: 'PUT'
      }
    });

    // Override the default $save method such that it uses PUT instead of POST
    // when updating
    // See: http://stackoverflow.com/a/16263805/806988
    angular.extend(Report.prototype, {
      save: function (callback) {
        if (this.nid) {
          return this.$update(callback);
        }
        return this.$save(callback);
      }
    });

    return Report;
  }]);

/**
 * @ngdoc service
 * @name cd.services.ReportActivity
 *
 * @description
 * Resource to retrieve the Drupal API for the activiy_report stream.
 */
cdServices
  // TODO: Merge 'ReportActivity' cleanly into the 'Report' service.
  .factory('ReportActivity', ['$resource', function($resource) {
    return $resource('api/views/activity_report', {}, {
      /**
       * @ngdoc method
       * @name cd.services.ReportActivity#query
       * @methodOf cd.services.ReportActivity
       */
      query: {
        method: 'GET',
        // FIXME: Sending the {format_output: '1'} param causes Drupal's
        //        services_views.module to return pre-formatted HTML. This is
        //        slightly more helpful, but I couldn't get Angular to process
        //        it correctly. Raw data is much better anyway.
        params: { display_id: 'services_1', args: [] },
        isArray: true
      }
    });
  }]);

/**
 * @ngdoc service
 * @name cd.services.Story
 *
 * @description
 * Resource to interact with the Drupal story (aka 'discussion') node API.
 */
cdServices
  .factory('Story', ['$resource', '$http', function($resource, $http) {
    var Story = $resource('api/node/:nid', { nid: '@nid' }, {
      /**
       * @ngdoc method
       * @name cd.services.Story#query
       * @methodOf cd.services.Story
       */
      query: {
        method: 'GET',
        params: { nid: '', 'parameters[type]': 'discussion', pagesize: 5 },
        isArray: true
      },

      /**
       * @ngdoc method
       * @name cd.services.Story#get
       * @methodOf cd.services.Story
       */
      get: {
        method: 'GET',
        isArray: false
      },

      /**
       * @ngdoc method
       * @name cd.services.Story#save
       * @methodOf cd.services.Story
       */
      save: {
        method: 'POST',
        params: { nid: '' }
      },

      /**
       * @ngdoc method
       * @name cd.services.Story#update
       * @methodOf cd.services.Story
       */
      update: {
        method: 'PUT'
      }
    });

    // Override the default $save method such that it uses PUT instead of POST
    // when updating
    // See: http://stackoverflow.com/a/16263805/806988
    angular.extend(Story.prototype, {
      save: function (callback) {
        if (this.nid) {
          return this.$update(callback);
        }
        return this.$save(callback);
      }
    });

    return Story;
  }]);

/**
 * @ngdoc service
 * @name cd.services.System
 *
 * @description
 * Resource to interact with the Drupal system API.
 */
cdServices
  .factory('System', ['$resource', function($resource) {
    return $resource('api/system/:verb', {}, {
      /**
       * @ngdoc method
       * @name cd.services.System#connect
       * @methodOf cd.services.System
       *
       * @description
       * Resolves to an object like {sessid:'123',user:{...}}
       */
      connect: {
        method:  'POST',
        params:  { verb: 'connect' },
        isArray: false
      }
    });
  }]);

/**
 * @ngdoc service
 * @name cd.services.Translation
 *
 * @description
 * Resource to interact with the Drupal i18n API.
 */
cdServices
  .factory('Translation', ['$resource', '$http', function($resource, $http) {
    var Translation = $resource('api/i18n/:lid', { lid: '@lid' }, {
      /**
       * @ngdoc method
       * @name cd.services.Translation#query
       * @methodOf cd.services.Translation
       */
      query: {
        method: 'GET',
        params: { lid: '', 'textgroup': 'ui' },
        isArray: false
      },

      /**
       * @ngdoc method
       * @name cd.services.Translation#save
       * @methodOf cd.services.Translation
       */
      save: {
        method: 'POST',
        params: { lid: '' }
      },

      /**
       * @ngdoc method
       * @name cd.services.Translation#update
       * @methodOf cd.services.Translation
       */
      update: {
        method: 'PUT'
      },

      /**
       * @ngdoc method
       * @name cd.services.Translation#remove
       * @methodOf cd.services.Translation
       */
      remove: {
        method: 'DELETE'
      }
    });

    // Override the default $save method such that it uses PUT instead of POST
    // when updating
    // See: http://stackoverflow.com/a/16263805/806988
    angular.extend(Translation.prototype, {
      save: function (callback) {
        if (this.lid) {
          return this.$update(callback);
        }
        return this.$save(callback);
      }
    });

    return Translation;
  }]);

/**
 * @ngdoc service
 * @name cd.services.Update
 *
 * @description
 * Resource to interact with the Drupal update (aka 'post') node API.
 */
cdServices
  .factory('Update', ['$resource', '$http', function($resource, $http) {
    var Update = $resource('api/node/:nid', { nid: '@nid' }, {
      /**
       * @ngdoc method
       * @name cd.services.Update#query
       * @methodOf cd.services.Update
       */
      query: {
        method: 'GET',
        params: { nid: '', 'parameters[type]': 'post', pagesize: 5 },
        isArray: true
      },

      /**
       * @ngdoc method
       * @name cd.services.Update#get
       * @methodOf cd.services.Update
       */
      get: {
        method: 'GET',
        isArray: false
      },

      /**
       * @ngdoc method
       * @name cd.services.Update#save
       * @methodOf cd.services.Update
       */
      save: {
        method: 'POST',
        params: { nid: '' }
      },

      /**
       * @ngdoc method
       * @name cd.services.Update#update
       * @methodOf cd.services.Update
       */
      update: {
        method: 'PUT'
      }
    });

    // Override the default $save method such that it uses PUT instead of POST
    // when updating
    // See: http://stackoverflow.com/a/16263805/806988
    angular.extend(Update.prototype, {
      save: function (callback) {
        if (this.nid) {
          return this.$update(callback);
        }
        return this.$save(callback);
      }
    });

    return Update;
  }]);

/**
 * @ngdoc service
 * @name cd.services.User
 *
 * @description
 * Resource to interact with the Drupal user API.
 */
cdServices
  .factory('User', ['$rootScope', '$resource', '$http', function($rootScope, $resource, $http) {
    var User,
        anonymousUser,
        currentUser,
        isLoggedIn;

    anonymousUser = { uid: 0, pass: null, name: 'Anonymous' };
    currentUser = angular.copy(anonymousUser);
    isLoggedIn = false;

    User = $resource('api/user/:verb', {}, {
      /**
       * @ngdoc method
       * @name cd.services.User#login
       * @methodOf cd.services.User
       *
       * @description
       * Resolves to an object like {sessid:'123',sessname:'abc',user:{...}}
       */
      login: {
        method: 'POST',
        params:  { verb: 'login' },
        isArray: false,
        transformResponse: $http.defaults.transformResponse.concat([
          function (data, headersGetter) {
            if (angular.isObject(data) && angular.isObject(data.user)) {
              currentUser = data.user;
              isLoggedIn = true;
            }
            // TODO: Flipping to anonymous user when a login error occurs. Double check if this logic is sound.
            else {
              currentUser = angular.copy(anonymousUser);
              isLoggedIn = false;
            }

            return data;
          }
        ])
      },

      /**
       * @ngdoc method
       * @name cd.services.User#logout
       * @methodOf cd.services.User
       *
       * @description
       * After transformation, resolves to an object like { result: true }
       */
      logout: {
        method: 'POST',
        params:  { verb: 'logout' },
        isArray: false, // eg: [true] transformed to { result: true }
        transformResponse: $http.defaults.transformResponse.concat([
          function (data, headersGetter) {
            if (angular.isArray(data) && data.length > 0) {
              if (data[0] === true) {
                currentUser = angular.copy(anonymousUser);
                isLoggedIn = false;
              }

              return { result: data[0] };
            } else {
              // TODO: Deal with indeterminate state here. Is the user logged in still or not?
              // TODO: Return error.
              return { result: false };
            }
          }
        ])
      }
    });

    /**
     * @ngdoc property
     * @name cd.services.User#isLoggedIn
     * @methodOf cd.services.User
     *
     * @description
     * Is any user currently logged in?
     */
    User.isLoggedIn = isLoggedIn;

    /**
     * @ngdoc property
     * @name cd.services.User#currentUser
     * @methodOf cd.services.User
     *
     * @description
     * The currently logged in user or the anonymousUser.
     */
    User.currentUser = currentUser;

    // Bring these objects under the purview of Angular.
    $rootScope.isLoggedIn = isLoggedIn;
    $rootScope.currentUser = currentUser;

    return User;
  }]);

/**
 * @ngdoc overview
 * @name cd.translationUI
 *
 * @description
 * ## Module: cd.translationUI
 *
 * Houses the service and controller necessary
 * to manage the Checkdesk real-time translation interface.
 */
angular.module('cd.translationUI', ['pascalprecht.translate'])

  /**
   * @ngdoc object
   * @name cd.translationUI.cdTranslationUIProvider
   * @requires $http
   *
   * @description
   * Provides coordination for UI translation. Enables access to the
   * $translate.translationTable and can be used as a missing translation handler
   * for $translate.
   */
  .provider('cdTranslationUI', function () {
    var $translationTable,
        $missingTranslations = {},
        $missingTranslationHandler = function (translationId, language) {
          if (angular.isUndefined($missingTranslations[language])) {
            $missingTranslations[language] = {};
          }
          if (angular.isUndefined($missingTranslations[language][translationId])) {
            $missingTranslations[language][translationId] = '';
          }
        };

    /**
     * @ngdoc method
     * @name cd.translationUI.cdTranslationUIProvider#translationTable
     * @methodOf cd.translationUI.cdTranslationUIProvider
     *
     * @description
     * Getter/setter for the translationTable object.
     *
     * @param  {object} translationTable A new translation table to set.
     * @return {object} The current $translationTable.
     */
    this.translationTable = function (translationTable) {
      if (!angular.isUndefined(translationTable)) {
        $translationTable = translationTable;
      }

      return $translationTable;
    };

    /**
     * @ngdoc method
     * @name cd.translationUI.cdTranslationUIProvider#missingTranslations
     * @methodOf cd.translationUI.cdTranslationUIProvider
     *
     * @description
     * Getter for the $missingTranslations object.
     *
     * @return {object} The current $missingTranslations object.
     */
    this.missingTranslations = function () {
      return $missingTranslations;
    };

    $missingTranslationHandler.translationTable = this.translationTable;
    $missingTranslationHandler.missingTranslations = this.missingTranslations;

    this.$get = function () {
      return $missingTranslationHandler;
    };
  })

  /**
   * @ngdoc method
   * @name cd.translationUI#config
   * @methodOf cd.translationUI
   * @requires $translateProvider
   * @requires cdTranslationUIProvider
   *
   * @description
   * Get's a reference to $translate's master translationTable. This is sort of
   * a hack but is a very handy way to directly access the current list of
   * translated strings on the page.
   *
   * See: {@link https://github.com/PascalPrecht/angular-translate/pull/61}
   */
  .config(['$translateProvider', 'cdTranslationUIProvider', function ($translateProvider, cdTranslationUIProvider) {
    cdTranslationUIProvider.translationTable($translateProvider.translations());
  }])

  /**
   * @ngdoc object
   * @name cd.translationUI.controllers:cdTranslationUICtrl
   * @requires $scope
   * @requires $translate
   * @requires cdTranslationUI
   *
   * @description
   * Controller for the cd-translation-ui.html template.
   */
  .controller('cdTranslationUICtrl', ['$scope', '$translate', 'cdTranslationUI', 'Translation', function ($scope, $translate, cdTranslationUI, Translation) {
    var translationSources = {};

    $scope.collapsed = true;

    $scope.toggle = function () {
      $scope.collapsed = !$scope.collapsed;
    };

    $scope.$translate = $translate;
    $scope.cdTranslationUI = cdTranslationUI;

    $scope.translationTable = cdTranslationUI.translationTable();
    $scope.missingTranslations = cdTranslationUI.missingTranslations();

    $scope.allTranslations = {};
    $scope.languages = [];

    // Check when available languages list changes, ensure the model is ready
    // for this and the languages helper is updated
    $scope.$watch('translationTable', function (newVal, oldVal) {
      // Update the languages array. Rebuild it to ensure correct order
      $scope.languages = [];
      angular.forEach(newVal, function (translations, language) {
        $scope.languages.push(language);
      });

      angular.forEach(newVal, function (translations, language) {
        angular.forEach(translations, function (translation, source) {
          if (angular.isUndefined($scope.allTranslations[source])) {
            $scope.allTranslations[source] = {};
          }
          if (angular.isUndefined($scope.allTranslations[source][language])) {
            $scope.allTranslations[source][language] = translation;
          }

          angular.forEach($scope.languages, function (l) {
            if (angular.isUndefined($scope.allTranslations[source][l])) {
              $scope.allTranslations[source][l] = '';
            }
          });
        });
      });
    }, true);

    // Helper object for creating table listing of missing translations
    $scope.$watch('missingTranslations', function (newVal, oldVal) {
      angular.forEach(newVal, function (translations, language) {
        angular.forEach(translations, function (translation, source) {
          if (angular.isUndefined($scope.allTranslations[source])) {
            $scope.allTranslations[source] = {};
          }
          if (angular.isUndefined($scope.allTranslations[source][language])) {
            $scope.allTranslations[source][language] = translation;
          }

          angular.forEach($scope.languages, function (l) {
            if (angular.isUndefined($scope.allTranslations[source][l])) {
              $scope.allTranslations[source][l] = '';
            }
          });
        });
      });
    }, true);

    // Refreshes the display when a translation is changed
    $scope.translationChanged = function (language, source) {
      // FIXME: Causing the input to go out of focus after each keypress
      // $scope.translationTable[language][source] = $scope.allTranslations[source][language];
      // $translate.uses($translate.uses());
    };

    $scope.save = function (language, source) {
      var record;

      if (!$scope.allTranslations[source][language]) {
        return false;
      }

      record = new Translation({
        language:    language,
        source:      source,
        translation: $scope.allTranslations[source][language],
        textgroup:   'ui'
      });

      record.save(function (translation) {
        $scope.translationTable[language][source] = $scope.allTranslations[source][language];
        $translate.uses($translate.uses());
      });
    };
  }]);

cdUser

  /**
   * @ngdoc object
   * @name cd.user.controllers:UserForgotPasswordCtrl
   * @requires $scope
   * @requires $routeParams
   * @requires pageState
   *
   * @description
   * Controller for userForgotPassword.html template.
   */
  .controller('UserForgotPasswordCtrl', ['$scope', 'pageState', 'User', function ($scope, pageState, User) {
  }]);

cdUser

  /**
   * @ngdoc object
   * @name cd.user.controllers:UserFormCtrl
   * @requires $scope
   * @requires $routeParams
   * @requires pageState
   *
   * @description
   * Controller for userForm.html template.
   */
  .controller('UserFormCtrl', ['$scope', 'pageState', 'User', function ($scope, pageState, User) {
  }]);

cdUser

  /**
   * @ngdoc object
   * @name cd.user.controllers:UserLoginCtrl
   * @requires $scope
   * @requires $routeParams
   * @requires pageState
   *
   * @description
   * Controller for userLogin.html template.
   */
  .controller('UserLoginCtrl', ['$scope', '$location', 'pageState', 'User', function ($scope, $location, pageState, User) {
    $scope.user = User.currentUser;
    $scope.isLoggedIn = User.isLoggedIn;

    $scope.submit = function() {
      // Must provide both user and pass
      if (!$scope.user.name || !$scope.user.pass) {
        // TODO: Display error.
        return false;
      } else if (!$scope.user || $scope.user.uid === 0) {
        // Must not already have an established connection
        User.login({ username: $scope.user.name, password: $scope.user.pass }, function (connection) {
          if ($scope.isLoggedIn) {
            // TODO: Display a success message about the user being logged in?
            $location.path('/');
          }
          else {
            // TODO: Display the error message here.
          }
        });
      } else {
        // TODO: Is this logic sound?? Perhaps we should do this immediately when the login page loads?
        // Already logged in, run away
        $location.path('/');
      }
    };

    $scope.cancel = function () {
      $location.path('/');
    };
  }]);

cdUser

  /**
   * @ngdoc object
   * @name cd.user.controllers:UserProfileCtrl
   * @requires $scope
   * @requires $routeParams
   * @requires pageState
   *
   * @description
   * Controller for userProfile.html template.
   */
  .controller('UserProfileCtrl', ['$scope', 'pageState', 'User', function ($scope, pageState, User) {
  }]);

cdUser
  .run(['User', 'System', function (User, System) {
      System.connect({}, function (connection) {
        if (angular.isObject(connection) && angular.isObject(connection.user)) {
          User.currentUser = connection.user;
          User.isLoggedIn  = !angular.isUndefined(connection.user) && connection.user.uid > 0;
        }
      });
    }]);
