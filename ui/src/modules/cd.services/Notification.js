/**
 * @ngdoc service
 * @name cd.services.Notification
 *
 * @description
 * Resource to retrieve the Drupal API for the liveblog stream.
 */
cdServices
  .factory('Notification', ['$resource', function($resource) {
    return $resource('api/views/my_notifications', {}, {

      /**
       * @ngdoc method
       * @name cd.services.Notification#autorefresh
       * @methodOf cd.services.Notification
       */
      autorefresh: {
        url: 'sites/all/modules/custom/checkdesk_notifications/ping.php',
        method: 'GET',
        params: { user: 0, timestamp: 0 },
        isArray: false
      },

      /**
       * @ngdoc method
       * @name cd.services.Notification#query
       * @methodOf cd.services.Notification
       */
      query: {
        method: 'GET',
        params: { display_id: 'services_1', args: [] },
        isArray: true
      }
    });
  }]);
