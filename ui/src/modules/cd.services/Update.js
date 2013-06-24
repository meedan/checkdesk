/**
 * @ngdoc service
 * @name cd.services.Update
 *
 * @description
 * Resource to interact with the Drupal update (aka 'post') node API.
 */
cdServices
  .factory('Update', ['$resource', '$http', function($resource, $http) {
    var Update = $resource('api/node/:nid', { nid: '@nid' }, {
      /**
       * @ngdoc method
       * @name cd.services.Update#query
       * @methodOf cd.services.Update
       */
      query: {
        method: 'GET',
        params: { nid: '', 'parameters[type]': 'post', pagesize: 5 },
        isArray: true
      },

      /**
       * @ngdoc method
       * @name cd.services.Update#get
       * @methodOf cd.services.Update
       */
      get: {
        method: 'GET',
        isArray: false
      },

      /**
       * @ngdoc method
       * @name cd.services.Update#save
       * @methodOf cd.services.Update
       */
      save: {
        method: 'POST',
        params: { nid: '' }
      },

      /**
       * @ngdoc method
       * @name cd.services.Update#update
       * @methodOf cd.services.Update
       */
      update: {
        method: 'PUT'
      }
    });

    // Override the default $save method such that it uses PUT instead of POST
    // when updating
    // See: http://stackoverflow.com/a/16263805/806988
    angular.extend(Update.prototype, {
      save: function (callback) {
        if (this.nid) {
          return this.$update(callback);
        }
        return this.$save(callback);
      }
    });

    return Update;
  }]);
