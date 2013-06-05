app.factory('PageState', function() {
  var status = 'loading',
      title  = 'Checkdesk';

  return {
    status: function(newStatus) {
      if (newStatus) {
        status = newStatus;
      }
      return status;
    },
    title: function(newTitle) {
      if (newTitle) {
        title = newTitle;
      }
      return title;
    }
  };
});