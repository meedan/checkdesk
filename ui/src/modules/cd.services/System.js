/**
 * @ngdoc service
 * @name cd.services.System
 *
 * @description
 * Resource to interact with the Drupal system API.
 */
cdServices
  .factory('System', ['$resource', function($resource) {
    return $resource('api/system/:verb', {}, {
      /**
       * @ngdoc method
       * @name cd.services.System#connect
       * @methodOf cd.services.System
       *
       * @description
       * Resolves to an object like {sessid:'123',user:{...}}
       */
      connect: {
        method:  'POST',
        params:  { verb: 'connect' },
        isArray: false
      }
    });
  }]);
