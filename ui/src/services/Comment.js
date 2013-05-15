// Integration with Drupal services API
appServices
  .factory('Comment', ['$resource', function($resource) {
    return $resource('api/node/:nid/comments', {}, {
      query: {
        method: 'GET',
        isArray: true
      }
    });
  }]);
