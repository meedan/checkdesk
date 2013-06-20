/**
 * @ngdoc service
 * @name cd.services.User
 *
 * @description
 * Resource to interact with the Drupal user API.
 */
cdServices
  .factory('User', ['$resource', '$http', function($resource, $http) {
    return $resource('api/user/:verb', {}, {
      /**
       * @ngdoc method
       * @name cd.services.User#login
       * @methodOf cd.services.User
       *
       * @description
       * Resolves to an object like {sessid:'123',sessname:'abc',user:{...}}
       */
      login: {
        method: 'POST',
        params:  { verb: 'login' },
        isArray: false
      },

      /**
       * @ngdoc method
       * @name cd.services.User#logout
       * @methodOf cd.services.User
       *
       * @description
       * After transformation, resolves to an object like { result: true }
       */
      logout: {
        method: 'POST',
        params:  { verb: 'logout' },
        isArray: false, // eg: [true] transformed to { result: true }
        transformResponse: $http.defaults.transformResponse.concat([
          function (data, headersGetter) {
            if (angular.isArray(data) && data.length > 0) {
              return { result: data[0] };
            } else {
              // TODO: Return error.
              return { result: false };
            }
          }
        ])
      }
    });
  }]);
