var app = angular.module('Checkdesk', [
      'pascalprecht.translate',
      'cdTranslationUI',
      'Checkdesk.services'
    ]),
    appServices = angular.module('Checkdesk.services', ['ngResource']);
