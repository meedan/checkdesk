angular.module('cdTranslationUI', [])
  // Defines cdTranslationUIProvider
  .provider('cdTranslationUI', function () {
    var $missingTranslations = [];

    this.missingTranslationHandler = function (translationId) {
      if ($missingTranslations.indexOf(translationId) === -1) {
        $missingTranslations.push(translationId);
      }
    };

    this.$get = function () {
      return {
        missingTranslations: function () {
          return $missingTranslations;
        }
      };
    };
  })
  .controller('cdTranslationUICtrl', ['$scope', '$translate', 'cdTranslationUI', function ($scope, $translate, cdTranslationUI) {
    $scope.collapsed = true;

    $scope.toggle = function () {
      $scope.collapsed = !$scope.collapsed;
    };

    $scope.missingTranslations = cdTranslationUI.missingTranslations();
    $scope.inputTranslations = [];

    $scope.translationChanged = function (index) {
      var uses = $translate.uses(),
          source = $scope.missingTranslations[index],
          translation = $scope.inputTranslations[index];

      $translate.translationTable[uses][source] = translation;
      $translate.uses(uses);
    };
  }]);
