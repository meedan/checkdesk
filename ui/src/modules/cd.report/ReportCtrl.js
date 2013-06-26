cdReport

  /**
   * @ngdoc function
   * @name cd.liveblog.ReportCtrl
   * @requires $scope
   * @requires $routeParams
   * @requires pageState
   *
   * @description
   * Controller for report.html template.
   */
  .controller('ReportCtrl', ['$scope', '$routeParams', 'pageState', 'Report', 'ReportActivity', function ($scope, $routeParams, pageState, Report, ReportActivity) {
    $scope.report = Report.get({ nid: $routeParams.nid }, function () {
      pageState.status('ready'); // This page has finished loading
    });
    $scope.reportActivity = ReportActivity.query({ args: [$routeParams.nid] });
  }]);
