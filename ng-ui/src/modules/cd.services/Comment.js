/**
 * @ngdoc service
 * @name cd.services.Comment
 *
 * @description
 * Resource to interact with the Drupal comments API.
 */
cdServices
  .factory('Comment', ['$resource', function($resource) {
    return $resource('api/node/:nid/comments', {}, {
      /**
       * @ngdoc method
       * @name cd.services.Comment#query
       * @methodOf cd.services.Comment
       */
      query: {
        method: 'GET',
        isArray: true
      }
    });
  }]);
