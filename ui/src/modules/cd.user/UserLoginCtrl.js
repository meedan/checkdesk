cdUser

  /**
   * @ngdoc function
   * @name cd.user.UserLoginCtrl
   * @requires $scope
   * @requires $routeParams
   * @requires pageState
   *
   * @description
   * Controller for userLogin.html template.
   */
  .controller('UserLoginCtrl', ['$scope', '$location', 'pageState', 'User', function ($scope, $location, pageState, User) {
    $scope.user = {
      uid: 0,
      name: '',
      pass: '',
      // TODO: Do something useful with $scope.user.remember_me
      remember_me: false
    };

    $scope.submit = function() {
      // Must provide both user and pass
      if (!$scope.user.name || !$scope.user.pass) {
        // TODO: Display error.
        return false;
      } else if (!$scope.user || $scope.user.uid === 0) {
        // Must not already have an established connection
        User.login({ username: $scope.user.name, password: $scope.user.pass }, function (connection) {
          // TODO: Manage the currently logged in user with a service of some sort.
          $scope.user       = connection.user;
          $scope.isLoggedIn = !angular.isUndefined(connection.user) && connection.user.uid > 0;

          // TODO: Display a success message about the user being logged in?
          $location.path('/');
        });
      } else {
        // Already logged in, run away
        $location.path('/');
      }
    };

    $scope.cancel = function () {
      $location.path('/');
    };
  }]);
