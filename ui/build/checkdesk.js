/*! checkdesk - v0.1.0 - 2013-06-18
 *  Copyright (c) 2013 Meedan | Licensed MIT
 */
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

app.config(['$routeProvider', '$locationProvider', function($routeProvider, $locationProvider) {
  // See: http://docs.angularjs.org/guide/dev_guide.services.$location
  $locationProvider.html5Mode(true).hashPrefix('!');

  // Note, templateUrls are affected by the currently set <base> in the
  // index.html. Running this app in a sub-directory needs the correct <base>
  // to be set!
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

  $routeProvider.otherwise({ redirectTo: '/reports' });
}]);

/**
 * @ngdoc function
 *
 * Integration with Drupal Services X-CSRF-Token header.
 *
 * This code relies on this tag to be added to the page BEFORE the main application
 * script tag.
 *
 *     <script src="services/session/token"></script>
 */
angular.module('cd.csrfToken', [])
  .config(['$httpProvider', function ($httpProvider) {
    // Set the cookie and header name to what the Drupal Services module expects.
    $httpProvider.defaults.xsrfCookieName = 'CSRF-Token';
    $httpProvider.defaults.xsrfHeaderName = 'X-CSRF-Token';
  }]);

/**
 * @ngdoc module
 * @name l10n
 *
 * @description
 * The `cd.l10n` module manages all translation and localization aspects of
 * the Checkdesk app.
 */
angular.module('cd.l10n', ['ngCookies', 'pascalprecht.translate', 'cd.translationUI'])

  /**
   * @ngdoc function
   * @name l10n.class:config
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

angular.module('cd.page', [])
  .factory('PageState', function() {
    var status = 'loading',
        title  = 'Checkdesk';

    return {
      status: function(newStatus) {
        if (newStatus) {
          status = newStatus;
        }
        return status;
      },
      title: function(newTitle) {
        if (newTitle) {
          title = newTitle;
        }
        return title;
      }
    };
  });

// Integration with Drupal services API
cdServices
  .factory('Comment', ['$resource', function($resource) {
    return $resource('api/node/:nid/comments', {}, {
      query: {
        method: 'GET',
        isArray: true
      }
    });
  }]);

// Integration with Drupal services API
cdServices
  .factory('Report', ['$resource', '$http', function($resource, $http) {
    var Report = $resource('api/node/:nid', { nid: '@nid' }, {
      query: {
        method: 'GET',
        params: { nid: '', 'parameters[type]': 'media', pagesize: 5 },
        isArray: true
      },
      get: {
        method: 'GET',
        isArray: false
      },
      save: {
        method: 'POST',
        params: { nid: '' }
      },
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

// Integration with Drupal services API
cdServices
  // TODO: Merge 'ReportActivity' cleanly into the 'Report' service.
  .factory('ReportActivity', ['$resource', function($resource) {
    return $resource('api/views/activity_report', {}, {
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

// Integration with Drupal services API
cdServices
  .factory('System', ['$resource', function($resource) {
    return $resource('api/system/:verb', {}, {
      connect: {
        method:  'POST',
        params:  { verb: 'connect' },
        isArray: false // eg: {sessid:'123',user:{...}}
      }
    });
  }]);

// Integration with Drupal services API
cdServices
  .factory('Translation', ['$resource', '$http', function($resource, $http) {
    var Translation = $resource('api/i18n/:lid', { lid: '@lid' }, {
      query: {
        method: 'GET',
        params: { lid: '', 'textgroup': 'ui' },
        isArray: false
      },
      save: {
        method: 'POST',
        params: { lid: '' }
      },
      update: {
        method: 'PUT'
      },
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

// Integration with Drupal services API
cdServices
  .factory('User', ['$resource', '$http', function($resource, $http) {
    return $resource('api/user/:verb', {}, {
      login: {
        method: 'POST',
        params:  { verb: 'login' },
        isArray: false // eg: {sessid:'123',sessname:'abc',user:{...}}
      },
      logout: {
        method: 'POST',
        params:  { verb: 'logout' },
        isArray: false, // eg: [true] transformed to { result: true }
        transformResponse: $http.defaults.transformResponse.concat([
          function (data, headersGetter) {
            if (angular.isArray(data) && data.length > 0) {
              return { result: data[0] };
            } else {
              // TODO: Return error.
              return { result: false };
            }
          }
        ])
      }
    });
  }]);

/**
 * @ngdoc module
 * @name translationUI
 *
 * @description
 * The `cd.translationUI` module houses the service and controller necessary
 * to manage the Checkdesk real-time translation interface.
 */
angular.module('cd.translationUI', ['pascalprecht.translate'])

  /**
   * @ngdoc service
   * @name translationUI.global:cdTranslationUI
   * @requires $http
   *
   * @description
   * Provides coordination for UI translation. Enables access to the
   * $translate.translationTable and can be used as a missing translation handler
   * for $translate.
   */
  .provider('cdTranslationUI', function () {
    var $translationTable,
        $missingTranslations = [],
        $missingTranslationHandler = function (translationId, uses) {
          if ($missingTranslations.indexOf(translationId) === -1) {
            console.log([translationId, uses]);
            $missingTranslations.push(translationId);
          }
        };

    this.translationTable = function (translationTable) {
      if (!angular.isUndefined(translationTable)) {
        $translationTable = translationTable;
      }

      return $translationTable;
    };

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
   * @ngdoc function
   * @name translationUI.class:config
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
   * @name translationUI.global:cdTranslationUICtrl
   * @requires $scope
   * @requires $translate
   * @requires cdTranslationUI
   *
   * @description
   * Controller for the cd-translation-ui.html template.
   */
  .controller('cdTranslationUICtrl', ['$scope', '$translate', 'cdTranslationUI', function ($scope, $translate, cdTranslationUI) {
    var translationSources = {};

    $scope.collapsed = true;

    $scope.toggle = function () {
      $scope.collapsed = !$scope.collapsed;
    };

    $scope.$translate = $translate;
    $scope.cdTranslationUI = cdTranslationUI;

    $scope.translationTable = cdTranslationUI.translationTable();
    $scope.editedTranslations = {};

    // Helpful list of languages available in the system
    $scope.languages = function () {
      var languages = [], language;

      for (language in $scope.translationTable) {
        if ($scope.translationTable.hasOwnProperty(language)) {
          languages.push(language);
        }
      }

      return languages;
    };

    $scope.translationSources = function () {
      var translationTable = cdTranslationUI.translationTable(),
          missingTranslations = cdTranslationUI.missingTranslations(),
          languages = $scope.languages(),
          language, source, i, j;

      for (language in translationTable) {
        if (translationTable.hasOwnProperty(language)) {
          for (source in translationTable[language]) {
            // Ensure source is not an internal angular property, ugh.
            if (translationTable[language].hasOwnProperty(source) && !source.match(/^\$\$/)) {
              translationSources[source] = translationSources[source] || {};

              // Create an empty record for each source language
              for (j = languages.length - 1; j >= 0; j--) {
                translationSources[source][languages[j]] = '';
              }

              translationSources[source][language] = translationTable[language][source];
            }
          }
        }
      }

      for (i = missingTranslations.length - 1; i >= 0; i--) {
        source = missingTranslations[i];

        if (angular.isUndefined(translationSources[source])) {
          translationSources[source] = {};

          for (j = languages.length - 1; j >= 0; j--) {
            if (angular.isUndefined(translationSources[source][languages[j]])) {
              translationSources[source][languages[j]] = '';
            }
          }
        }
      }

      return translationSources;
    };

    // Refreshes the display when a translation is changed
    $scope.translationChanged = function (language, source) {
      console.log([$scope.editedTranslations, language, source]);
      $scope.translationTable[language][source] = $scope.editedTranslations[language][source];
      $translate.uses($translate.uses());
    };
  }]);

var HeaderCtrl = ['$scope', '$translate', 'System', 'User', function ($scope, $translate, System, User) {
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


  // Determine logged in or logged out state and set up helper functions
  var anonymousUser = { uid: 0 };
  $scope.isLoggedIn = false;
  $scope.user       = angular.copy(anonymousUser);

  System.connect({}, function (connection) {
    $scope.user       = connection.user;
    $scope.isLoggedIn = !angular.isUndefined(connection.user) && connection.user.uid > 0;
  });

  $scope.login = function () {
    // Must provide both user and pass
    if (!$scope.user.name || !$scope.user.pass) {
      // TODO: Display error.
      return false;
    } else if (!$scope.user || $scope.user.uid === 0) {
      // Must not already have an established connection
      User.login({ username: $scope.user.name, password: $scope.user.pass }, function (connection) {
        $scope.user       = connection.user;
        $scope.isLoggedIn = !angular.isUndefined(connection.user) && connection.user.uid > 0;
      });
    } else {
      // Already logged in
    }
  };

  $scope.logout = function () {
    // Must send empty POST data for this to work
    User.logout({}, function (data) {
      if (data.result) {
        $scope.user       = angular.copy(anonymousUser);
        $scope.isLoggedIn = false;
      } else {
        // TODO: Display error.
      }
    });
  };
}];

app.controller('HeaderCtrl', HeaderCtrl);

var PageCtrl = ['$scope', 'PageState', function ($scope, PageState) {
  $scope.PageState = PageState;
}];

app.controller('PageCtrl', PageCtrl);

var ReportCtrl = ['$scope', '$routeParams', 'PageState', 'Report', 'ReportActivity', function ($scope, $routeParams, PageState, Report, ReportActivity) {
  $scope.report = Report.get({ nid: $routeParams.nid }, function () {
    PageState.status('ready'); // This page has finished loading
  });
  $scope.reportActivity = ReportActivity.query({ args: [$routeParams.nid] });
}];

app.controller('ReportCtrl', ReportCtrl);

var ReportFormCtrl = ['$scope', '$routeParams', '$location', 'Report', function ($scope, $routeParams, $location, Report) {
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
}];

app.controller('ReportFormCtrl', ReportFormCtrl);

var ReportsCtrl = ['$scope', 'PageState', 'Report', function ($scope, PageState, Report) {
  $scope.reports = [];

  Report.query(function (reports) {
    for (var i = 0; i < reports.length; i++) {
      // LOL: Hilariously unperformant, we will improve this of course.
      $scope.reports.push(Report.get({ nid: reports[i].nid }));
    }

    PageState.status('ready'); // This page has finished loading
  });
}];

app.controller('ReportsCtrl', ReportsCtrl);

var TranslationsTestCtrl = ['$scope', '$translate', 'Translation', function ($scope, $translate, Translation) {
  $scope.translations = Translation.query({ language: $translate.uses() });

  $scope.translation = new Translation({
    language:    '',
    context:     '',
    source:      '',
    translation: '',
    textgroup:   '',
    location:    '',
    plid:        '',
    plural:      ''
  });

  $scope.submit = function () {
    $scope.translation.save();
    return false;
  };

}];

app.controller('TranslationsTestCtrl', TranslationsTestCtrl);
