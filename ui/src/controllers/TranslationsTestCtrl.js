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
