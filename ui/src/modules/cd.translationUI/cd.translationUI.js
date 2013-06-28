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
