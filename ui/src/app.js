var app = angular.module('Checkdesk', [
      'ngTranslate',
      'cdTranslationUI',
      'Checkdesk.services'
    ]),
    appServices = angular.module('Checkdesk.services', ['ngResource']);
