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
      $scope.translationTable[language][source] = $scope.editedTranslations[language][source];
      $translate.uses($translate.uses());
    };
  }]);
