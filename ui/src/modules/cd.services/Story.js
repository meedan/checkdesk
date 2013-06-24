/**
 * @ngdoc service
 * @name cd.services.Story
 *
 * @description
 * Resource to interact with the Drupal story (aka 'discussion') node API.
 */
cdServices
  .factory('Story', ['$resource', '$http', function($resource, $http) {
    var Story = $resource('api/node/:nid', { nid: '@nid' }, {
      /**
       * @ngdoc method
       * @name cd.services.Story#query
       * @methodOf cd.services.Story
       */
      query: {
        method: 'GET',
        params: { nid: '', 'parameters[type]': 'discussion', pagesize: 5 },
        isArray: true
      },

      /**
       * @ngdoc method
       * @name cd.services.Story#get
       * @methodOf cd.services.Story
       */
      get: {
        method: 'GET',
        isArray: false
      },

      /**
       * @ngdoc method
       * @name cd.services.Story#save
       * @methodOf cd.services.Story
       */
      save: {
        method: 'POST',
        params: { nid: '' }
      },

      /**
       * @ngdoc method
       * @name cd.services.Story#update
       * @methodOf cd.services.Story
       */
      update: {
        method: 'PUT'
      }
    });

    // Override the default $save method such that it uses PUT instead of POST
    // when updating
    // See: http://stackoverflow.com/a/16263805/806988
    angular.extend(Story.prototype, {
      save: function (callback) {
        if (this.nid) {
          return this.$update(callback);
        }
        return this.$save(callback);
      }
    });

    return Story;
  }]);
