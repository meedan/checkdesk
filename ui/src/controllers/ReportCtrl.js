var ReportCtrl = ['$scope', '$routeParams', 'Report', 'ReportActivity', function ($scope, $routeParams, Report, ReportActivity) {
  $scope.report = Report.get({ nid: $routeParams.nid });
  $scope.reportActivity = ReportActivity.query({ args: [$routeParams.nid] });
}];

app.controller('ReportCtrl', ReportCtrl);
