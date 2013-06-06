angular.module('cd.l10n', ['pascalprecht.translate', 'cd.translationUI'])
  .config(['$translateProvider', function ($translateProvider) {
    // Initially empty translation tables
    $translateProvider.translations('en', {});
    $translateProvider.translations('ar', {});

    $translateProvider.uses('ar');

    // FIXME: Something is amiss with the cookie thing.
    // $translateProvider.useCookieStorage();

    $translateProvider.useMissingTranslationHandler('cdTranslationUI');
  }])
  .run(['$translate', 'cdTranslationUI', 'Translation', function ($translate, cdTranslationUI, Translation) {
    Translation.query({}, function (translations) {
      var translationTable,
          languages = ['ar', 'en'],
          language, translation, i, j;

      // Get a reference to the translation table
      translationTable = cdTranslationUI.translationTable();

      for (i = languages.length - 1; i >= 0; i--) {
        language = languages[i];

        if (translations.hasOwnProperty(language)) {
          for (j = translations[language].length - 1; j >= 0; j--) {
            translation = translations[language][j];

            translationTable[language][translation.source] = translation.translation;
          }
        }
      }

      // Refresh interface translations
      $translate.uses($translate.uses());
    });
  }]);
