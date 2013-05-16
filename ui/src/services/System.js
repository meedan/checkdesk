// Integration with Drupal services API
appServices
  .factory('System', ['$resource', function($resource) {
    return $resource('api/system/:verb', {}, {
      connect: {
        method:  'POST',
        params:  { verb: 'connect' },
        isArray: false // eg: {sessid:'123',user:{...}}
      }
    });
  }]);
