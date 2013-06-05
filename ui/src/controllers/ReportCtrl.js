var ReportCtrl = ['$scope', '$routeParams', 'Report', 'ReportActivity', function ($scope, $routeParams, Report, ReportActivity) {
  $scope.report = Report.get({ nid: $routeParams.nid }, function () {
    $('body').attr('data-status', 'ready'); // This page has finished loading
  });
  $scope.reportActivity = ReportActivity.query({ args: [$routeParams.nid] });
}];

app.controller('ReportCtrl', ReportCtrl);
