/**
 * @ngdoc service
 * @name cd.services.ReportActivity
 *
 * @description
 * Resource to retrieve the Drupal API for the activiy_report stream.
 */
cdServices
  // TODO: Merge 'ReportActivity' cleanly into the 'Report' service.
  .factory('ReportActivity', ['$resource', function($resource) {
    return $resource('api/views/activity_report', {}, {
      /**
       * @ngdoc method
       * @name cd.services.ReportActivity#query
       * @methodOf cd.services.ReportActivity
       */
      query: {
        method: 'GET',
        // FIXME: Sending the {format_output: '1'} param causes Drupal's
        //        services_views.module to return pre-formatted HTML. This is
        //        slightly more helpful, but I couldn't get Angular to process
        //        it correctly. Raw data is much better anyway.
        params: { display_id: 'services_1', args: [] },
        isArray: true
      }
    });
  }]);
