// Integration with Drupal services API
appServices
  .factory('Report', ['$resource', '$http', function($resource, $http) {
    var Report = $resource('api/node/:nid', { nid: '@nid' }, {
      query: {
        method: 'GET',
        params: { nid: '', 'parameters[type]': 'media', pagesize: 5 },
        isArray: true
      },
      get: {
        method: 'GET',
        isArray: false
      },
      save: {
        method: 'POST',
        params: { nid: '' }
      },
      update: {
        method: 'PUT'
      }
    });

    // Override the default $save method such that it uses PUT instead of POST
    // when updating
    // See: http://stackoverflow.com/a/16263805/806988
    angular.extend(Report.prototype, {
      save: function (callback) {
        if (this.nid) {
          return this.$update(callback);
        }
        return this.$save(callback);
      }
    });

    return Report;
  }]);
