// Integration with Drupal services API
appServices
  .factory('User', ['$resource', '$http', function($resource, $http) {
    return $resource('api/user/:verb', {}, {
      login: {
        method: 'POST',
        params:  { verb: 'login' },
        isArray: false // eg: {sessid:'123',sessname:'abc',user:{...}}
      },
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
