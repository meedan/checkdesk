/*! checkdesk - v0.1.0 - 2013-06-04
 *  Copyright (c) 2013 Meedan | Licensed MIT
 */
var app = angular.module('Checkdesk', [
      'pascalprecht.translate',
      'cdTranslationUI',
      'Checkdesk.services'
    ]),
    appServices = angular.module('Checkdesk.services', ['ngResource']);

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

app.config(['$translateProvider', function ($translateProvider) {
  $translateProvider.translations('en_EN', {
    // #/reports
    'CALL_TO_ACTION_HEAD':                 'Help verify this report',
    'CALL_TO_ACTION_TEXT':                 'Checkdesk is a collaborative space for journalist led and citizen participating fact-checking.',
    'LANGUAGE_TOGGLE':                     'Switch to Arabic',
    'WELCOME_USER':                        'Welcome, {{name}}',
    'LOGOUT':                              'Logout',
    'USER_NAME':                           'User name',
    'PASSWORD':                            'Password',
    'LOG_IN':                              'Log in',
    'BOTTOM_CONTENT_GOES_HERE':            'Bottom content goes here.',
    'REALLY_BOTTOM_CONTENT_GOES_HERE':     'Really bottom content goes here.',

    // #/report/:nid
    '#_FACT_CHECKING_FOOTNOTES':           '{{num}} fact-checking footnotes',
    'VERIFIED':                            'Verified',
    'CREATE_NOTE':                         'Create note',
    'PEOPLE_HELPING_VERIFY_THIS_REPORT':   'People helping verify this report:',
    '#_JOURNALISTS':                       '{{num}} journalists',
    '#_CITIZENS':                          '{{num}} citizens',
    'CHANGED_STATUS_TO_VERIFIED':          'Changed status to verified',
    '#_MINUTES_SHORT':                     '{{num}}m',
    '#_HOURS_SHORT':                       '{{num}}h',
    'LOREM_IPSUM':                         'Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.',
    'CHANGED_STATUS_TO':                   'Changed status to',
    'UNDETERMINED':                        'Undetermined',
    'LOAD_MORE':                           'Load more'
  });

  $translateProvider.translations('ar_AR', {
    // #/reports
    'CALL_TO_ACTION_HEAD':                 'مساعدة في التحقق من هذا التقرير',
    'CALL_TO_ACTION_TEXT':                 'Checkdesk هو مساحة تعاونية للصحفي ومواطن قاد المشاركة تدقيق الحقائق.',
    'LANGUAGE_TOGGLE':                     'التبديل إلى الإنجليزية',
    'WELCOME_USER':                        'أهلا، {{name}}',
    'LOGOUT':                              'تسجيل الخروج',
    'USER_NAME':                           'اسم المستخدم',
    'PASSWORD':                            'كلمة السر',
    'LOG_IN':                              'تسجيل الدخول',
    'BOTTOM_CONTENT_GOES_HERE':            'محتوى أسفل يذهب هنا.',
    'REALLY_BOTTOM_CONTENT_GOES_HERE':     'محتوى أسفل حقا يذهب هنا.',

    // #/report/:nid
    '#_FACT_CHECKING_FOOTNOTES':           '{{num}} الحواشي تدقيق الحقائق',
    'VERIFIED':                            'التحقق',
    'CREATE_NOTE':                         'إنشاء حاشية',
    'PEOPLE_HELPING_VERIFY_THIS_REPORT':   'الناس الذين يساعدون تحقق من هذا التقرير:',
    '#_JOURNALISTS':                       '{{num}} الصحفيين',
    '#_CITIZENS':                          '{{num}} مواطنا',
    'CHANGED_STATUS_TO_VERIFIED':          'تغيرت الحالة إلى <em>التحقق</em>',
    '#_MINUTES_SHORT':                     '{{num}} دقيقة',
    '#_HOURS_SHORT':                       '{{num}} ساعات',
    'LOREM_IPSUM':                         'غريمه وحلفاؤها تعد من, جُل لم الذود السبب الأمامية, وبعض شمال فمرّ بحث لم. مما أمدها الأرواح بـ, بالقصف اتفاقية لبولندا بـ حشد, سقط أم الذود للصين للألمان.',
    'CHANGED_STATUS_TO_*':                 'تغيرت الحالة إلى',
    'UNDETERMINED':                        'غير محدد',
    'LOAD_MORE':                           'تحميل أكثر'
  });
  $translateProvider.uses('ar_AR');

  // FIXME: Something is amiss with the cookie thing.
  // $translateProvider.useCookieStorage();

  $translateProvider.useMissingTranslationHandler('cdTranslationUI');
}]);

angular.module('cdTranslationUI', [])
  .provider('cdTranslationUI', function () {
    var $translationTable,
        $missingTranslations = [],
        $missingTranslationHandler = function (translationId) {
          if ($missingTranslations.indexOf(translationId) === -1) {
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
  .config(['$translateProvider', 'cdTranslationUIProvider', function ($translateProvider, cdTranslationUIProvider) {
    cdTranslationUIProvider.translationTable($translateProvider.translations());
  }])
  .controller('cdTranslationUICtrl', ['$scope', '$translate', 'cdTranslationUI', function ($scope, $translate, cdTranslationUI) {
    $scope.collapsed = true;

    $scope.toggle = function () {
      $scope.collapsed = !$scope.collapsed;
    };

    $scope.translationTable = cdTranslationUI.translationTable();
    $scope.missingTranslations = cdTranslationUI.missingTranslations();
    $scope.inputTranslations = [];
    // FIXME: $translate.uses() is not updating when language is switched
    $scope.currentLanguage = $translate.uses();

    $scope.translationChanged = function (index) {
      var uses = $translate.uses(),
          source = $scope.missingTranslations[index],
          translation = $scope.inputTranslations[index];

      $scope.translationTable[uses][source] = translation;
      $translate.uses(uses);
    };
  }]);

// Integration with Drupal services API
appServices
  .factory('Comment', ['$resource', function($resource) {
    return $resource('api/node/:nid/comments', {}, {
      query: {
        method: 'GET',
        isArray: true
      }
    });
  }]);

// Integration with Drupal services API
appServices
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
appServices
  // TODO: Merge 'ReportActivity' cleanly into the 'Report' service.
  .factory('ReportActivity', ['$resource', function($resource) {
    return $resource('api/views/activity_report', {}, {
      query: {
        method: 'GET',
        // FIXME: Sending the {format_output: '1'} param causes Drupal's
        //        services_views.module to return pre-formatted HTML. This is
        //        slightly more helpful, but I couldn't get Angular to process
        //        it correctly. Raw data is much better anyway.
        params: { display_id: 'page_1', args: [] },
        isArray: true
      }
    });
  }]);

// Integration with Drupal services API
appServices
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
appServices
  .factory('Translation', ['$resource', '$http', function($resource, $http) {
    var Translation = $resource('api/i18n/:lid', { lid: '@lid' }, {
      query: {
        method: 'GET',
        params: { lid: '', 'textgroup': 'ui' },
        isArray: true
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
appServices
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
    if ($translate.uses() === 'en_EN') {
      $translate.uses('ar_AR');
    } else {
      $translate.uses('en_EN');
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

var ReportCtrl = ['$scope', '$routeParams', 'Report', 'ReportActivity', function ($scope, $routeParams, Report, ReportActivity) {
  $scope.report = Report.get({ nid: $routeParams.nid });
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

var ReportsCtrl = ['$scope', 'Report', function ($scope, Report) {
  $scope.reports = [];

  Report.query(function (reports) {
    for (var i = 0; i < reports.length; i++) {
      // LOL: Hilariously unperformant, we will improve this of course.
      $scope.reports.push(Report.get({ nid: reports[i].nid }));
    }
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
