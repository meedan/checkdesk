/**
 * @ngdoc module
 * @name l10n
 *
 * @description
 * The `cd.l10n` module manages all translation and localization aspects of
 * the Checkdesk app.
 */
angular.module('cd.l10n', ['pascalprecht.translate', 'cd.translationUI'])

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
    // Initially empty translation tables
    $translateProvider.translations('en-NG', {});
    $translateProvider.translations('ar', {});

    $translateProvider.uses('ar');

    // FIXME: Something is amiss with the cookie thing.
    // $translateProvider.useCookieStorage();

    $translateProvider.useMissingTranslationHandler('cdTranslationUI');
  }])

  /**
   * @ngdoc function
   * @name l10n.class:run
   * @requires $translate
   * @requires cdTranslationUI
   * @requires Translation
   *
   * @description
   * On run, uses the Translation service to fetch the necessary translation
   * strings from the Drupal API. Once retrieved the strings are installed
   * in the $translate service and the interface is refreshed.
   */
  .run(['$translate', 'cdTranslationUI', 'Translation', function ($translate, cdTranslationUI, Translation) {
    Translation.query({}, function (translations) {
      var translationTable,
          languages = ['ar', 'en-NG'],
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
