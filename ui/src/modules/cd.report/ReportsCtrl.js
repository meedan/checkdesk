cdReport

  /**
   * @ngdoc object
   * @name cd.liveblog.controllers:ReportsCtrl
   * @requires $scope
   * @requires pageState
   * @requires Report
   *
   * @description
   * Controller for reportForm.html template.
   */
  .controller('ReportsCtrl', ['$scope', 'pageState', 'Report', function ($scope, pageState, Report) {
    $scope.reports = [];

    Report.query(function (reports) {
      for (var i = 0; i < reports.length; i++) {
        // LOL: Hilariously unperformant, we will improve this of course.
        $scope.reports.push(Report.get({ nid: reports[i].nid }));
      }

      pageState.status('ready'); // This page has finished loading
    });
  }]);
