var ReportCtrl = ['$scope', '$routeParams', 'PageState', 'Report', 'ReportActivity', function ($scope, $routeParams, PageState, Report, ReportActivity) {
  $scope.report = Report.get({ nid: $routeParams.nid }, function () {
    PageState.status('ready'); // This page has finished loading
  });
  $scope.reportActivity = ReportActivity.query({ args: [$routeParams.nid] });
}];

app.controller('ReportCtrl', ReportCtrl);
