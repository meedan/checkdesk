/**
 * @ngdoc service
 * @name cd.services.Report
 *
 * @description
 * Resource to interact with the Drupal report node API.
 */
cdServices
  .factory('Report', ['$resource', '$http', function($resource, $http) {
    var Report = $resource('api/node/:nid', { nid: '@nid' }, {
      /**
       * @ngdoc method
       * @name cd.services.Report#query
       * @methodOf cd.services.Report
       */
      query: {
        method: 'GET',
        params: { nid: '', 'parameters[type]': 'media', pagesize: 5 },
        isArray: true
      },

      /**
       * @ngdoc method
       * @name cd.services.Report#get
       * @methodOf cd.services.Report
       */
      get: {
        method: 'GET',
        isArray: false
      },

      /**
       * @ngdoc method
       * @name cd.services.Report#save
       * @methodOf cd.services.Report
       */
      save: {
        method: 'POST',
        params: { nid: '' }
      },

      /**
       * @ngdoc method
       * @name cd.services.Report#update
       * @methodOf cd.services.Report
       */
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
