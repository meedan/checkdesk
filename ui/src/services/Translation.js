// Integration with Drupal services API
appServices
  .factory('Translation', ['$resource', '$http', function($resource, $http) {
    var Translation = $resource('api/i18n/:lid', { lid: '@lid' }, {
      query: {
        method: 'GET',
        params: { lid: '', 'textgroup': 'ui' },
        isArray: true
      },
      save: {
        method: 'POST',
        params: { lid: '' }
      },
      update: {
        method: 'PUT'
      },
      remove: {
        method: 'DELETE'
      }
    });

    // Override the default $save method such that it uses PUT instead of POST
    // when updating
    // See: http://stackoverflow.com/a/16263805/806988
    angular.extend(Translation.prototype, {
      save: function (callback) {
        if (this.lid) {
          return this.$update(callback);
        }
        return this.$save(callback);
      }
    });

    return Translation;
  }]);
