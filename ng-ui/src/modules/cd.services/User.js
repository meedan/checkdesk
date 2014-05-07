/**
 * @ngdoc service
 * @name cd.services.User
 *
 * @description
 * Resource to interact with the Drupal user API.
 */
cdServices
  .factory('User', ['$rootScope', '$resource', '$http', function($rootScope, $resource, $http) {
    var User,
        anonymousUser,
        currentUser,
        isLoggedIn;

    anonymousUser = { uid: 0, pass: null, name: 'Anonymous' };
    currentUser = angular.copy(anonymousUser);
    isLoggedIn = false;

    User = $resource('api/user/:verb', {}, {
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
        isArray: false,
        transformResponse: $http.defaults.transformResponse.concat([
          function (data, headersGetter) {
            if (angular.isObject(data) && angular.isObject(data.user)) {
              currentUser = data.user;
              isLoggedIn = true;
            }
            // TODO: Flipping to anonymous user when a login error occurs. Double check if this logic is sound.
            else {
              currentUser = angular.copy(anonymousUser);
              isLoggedIn = false;
            }

            return data;
          }
        ])
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
              if (data[0] === true) {
                currentUser = angular.copy(anonymousUser);
                isLoggedIn = false;
              }

              return { result: data[0] };
            } else {
              // TODO: Deal with indeterminate state here. Is the user logged in still or not?
              // TODO: Return error.
              return { result: false };
            }
          }
        ])
      }
    });

    /**
     * @ngdoc property
     * @name cd.services.User#isLoggedIn
     * @methodOf cd.services.User
     *
     * @description
     * Is any user currently logged in?
     */
    User.isLoggedIn = isLoggedIn;

    /**
     * @ngdoc property
     * @name cd.services.User#currentUser
     * @methodOf cd.services.User
     *
     * @description
     * The currently logged in user or the anonymousUser.
     */
    User.currentUser = currentUser;

    // Bring these objects under the purview of Angular.
    $rootScope.isLoggedIn = isLoggedIn;
    $rootScope.currentUser = currentUser;

    return User;
  }]);
