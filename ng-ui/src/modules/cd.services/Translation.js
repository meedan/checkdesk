/**
 * @ngdoc service
 * @name cd.services.Translation
 *
 * @description
 * Resource to interact with the Drupal i18n API.
 */
cdServices
  .factory('Translation', ['$resource', '$http', function($resource, $http) {
    var Translation = $resource('api/i18n/:lid', { lid: '@lid' }, {
      /**
       * @ngdoc method
       * @name cd.services.Translation#query
       * @methodOf cd.services.Translation
       */
      query: {
        method: 'GET',
        params: { lid: '', 'textgroup': 'ui' },
        isArray: false
      },

      /**
       * @ngdoc method
       * @name cd.services.Translation#save
       * @methodOf cd.services.Translation
       */
      save: {
        method: 'POST',
        params: { lid: '' }
      },

      /**
       * @ngdoc method
       * @name cd.services.Translation#update
       * @methodOf cd.services.Translation
       */
      update: {
        method: 'PUT'
      },

      /**
       * @ngdoc method
       * @name cd.services.Translation#remove
       * @methodOf cd.services.Translation
       */
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
