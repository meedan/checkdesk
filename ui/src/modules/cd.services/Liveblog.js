/**
 * @ngdoc service
 * @name cd.services.Liveblog
 *
 * @description
 * Resource to retrieve the Drupal API for the liveblog stream.
 */
cdServices
  .factory('Liveblog', ['$resource', function($resource) {
    return $resource('api/views/liveblog', {}, {
      /**
       * @ngdoc method
       * @name cd.services.Liveblog#query
       * @methodOf cd.services.Liveblog
       */
      query: {
        method: 'GET',
        params: { display_id: 'services_1', args: [] },
        isArray: true
      }
    });
  }]);
