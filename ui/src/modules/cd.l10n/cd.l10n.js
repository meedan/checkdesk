/**
 * @ngdoc object
 * @name cd.l10n
 *
 * @description
 * The `cd.l10n` module manages all translation and localization aspects of
 * the Checkdesk app.
 */
angular.module('cd.l10n', ['ngCookies', 'pascalprecht.translate', 'cd.translationUI'])

  /**
   * @ngdoc method
   * @name cd.l10n#config
   * @methodOf cd.l10n
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
