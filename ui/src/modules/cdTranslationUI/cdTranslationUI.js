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

    $scope.translationChanged = function (index) {
      var uses = $translate.uses(),
          source = $scope.missingTranslations[index],
          translation = $scope.inputTranslations[index];

      $scope.translationTable[uses][source] = translation;
      $translate.uses(uses);
    };
  }]);
