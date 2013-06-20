var ReportCtrl = ['$scope', '$routeParams', 'pageState', 'Report', 'ReportActivity', function ($scope, $routeParams, pageState, Report, ReportActivity) {
  $scope.report = Report.get({ nid: $routeParams.nid }, function () {
    pageState.status('ready'); // This page has finished loading
  });
  $scope.reportActivity = ReportActivity.query({ args: [$routeParams.nid] });
}];

app.controller('ReportCtrl', ReportCtrl);
