/**
 * @ngdoc object
 * @name cd.translationUI
 *
 * @description
 * The `cd.translationUI` module houses the service and controller necessary
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
            $missingTranslations[language][translationId] = null;
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

    /**
     * @ngdoc method
     * @name cd.translationUI.cdTranslationUIProvider#invertTranslations
     * @methodOf cd.translationUI.cdTranslationUIProvider
     *
     * @description
     * Helper method to invert the translationTable or missingTranslations objects.
     *
     * @param  {object} translations A translations object, eg: the translationTable
     * @return {object} The inverted translations object
     */
    this.invertTranslations = function (translations) {
      var inverted = {};

      angular.forEach(translations, function (sources, language) {
        var sourcesIsArray = angular.isArray(sources);

        angular.forEach(sources, function (translation, source) {
          if (angular.isUndefined(inverted[source])) {
            inverted[source] = sourcesIsArray ? [] : {};
          }
          if (sourcesIsArray) {
            if (inverted[source].indexOf(language) === -1) {
              inverted[source].push(language);
            }
          }
          else {
            if (angular.isUndefined(inverted[source][language])) {
              inverted[source][language] = translation;
            }
          }
        });
      });

      return inverted;
    };

    $missingTranslationHandler.translationTable = this.translationTable;
    $missingTranslationHandler.missingTranslations = this.missingTranslations;
    $missingTranslationHandler.invertTranslations = this.invertTranslations;

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
   * @ngdoc function
   * @name cd.translationUI.cdTranslationUICtrl
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
    $scope.missingTranslations = cdTranslationUI.missingTranslations();

    $scope.translationTableInvert = {};
    $scope.missingTranslationsInvert = {};
    $scope.editedTranslations = {};
    $scope.languages = [];

    // Check when available languages list changes, ensure the model is ready
    // for this and the languages helper is updated
    $scope.$watch('translationTable', function (newVal, oldVal) {
      $scope.languages = [];

      angular.forEach(newVal, function (translations, language) {
        if ($scope.languages.indexOf(language) === -1) {
          $scope.languages.push(language);
        }

        if (angular.isUndefined($scope.editedTranslations[language])) {
          $scope.editedTranslations[language] = {};

          angular.forEach(translations, function (translation, source) {
            if (angular.isUndefined($scope.editedTranslations[language][source])) {
              $scope.editedTranslations[language][source] = translation;
            }
          });
        }
      });

      $scope.translationTableInvert = cdTranslationUI.invertTranslations(newVal);
    }, true);

    // Helper object for creating table listing of missing translations
    $scope.$watch('missingTranslations', function (newVal, oldVal) {
      $scope.missingTranslationsInvert = cdTranslationUI.invertTranslations(newVal);
    }, true);

    // Refreshes the display when a translation is changed
    $scope.translationChanged = function (language, source) {
      $scope.translationTable[language][source] = $scope.editedTranslations[language][source];
      $translate.uses($translate.uses());
    };
  }]);
