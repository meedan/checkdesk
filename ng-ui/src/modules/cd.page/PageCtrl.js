cdPage

  /**
   * @ngdoc object
   * @name cd.page.controllers:PageCtrl
   * @requires $scope
   * @requires pageState
   *
   * @description
   * Meta-controller for the <html> tag on the page. Manages page state and the
   * like.
   */
  .controller('PageCtrl', ['$scope', 'pageState', function ($scope, pageState) {
    $scope.pageState = pageState;
  }]);
