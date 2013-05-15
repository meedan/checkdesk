// Integration with Drupal services API
appServices
  // TODO: Merge 'ReportActivity' cleanly into the 'Report' service.
  .factory('ReportActivity', ['$resource', function($resource) {
    return $resource('api/views/activity_report', {}, {
      query: {
        method: 'GET',
        // FIXME: Sending the {format_output: '1'} param causes Drupal's
        //        services_views.module to return pre-formatted HTML. This is
        //        slightly more helpful, but I couldn't get Angular to process
        //        it correctly. Raw data is much better anyway.
        params: { display_id: 'page_1', args: [] },
        isArray: true
      }
    });
  }]);
