cdUser

  /**
   * @ngdoc object
   * @name cd.user.controllers:UserLoginCtrl
   * @requires $scope
   * @requires $routeParams
   * @requires pageState
   *
   * @description
   * Controller for userLogin.html template.
   */
  .controller('UserLoginCtrl', ['$scope', '$location', 'pageState', 'User', function ($scope, $location, pageState, User) {
    $scope.user = User.currentUser;
    $scope.isLoggedIn = User.isLoggedIn;

    $scope.submit = function() {
      // Must provide both user and pass
      if (!$scope.user.name || !$scope.user.pass) {
        // TODO: Display error.
        return false;
      } else if (!$scope.user || $scope.user.uid === 0) {
        // Must not already have an established connection
        User.login({ username: $scope.user.name, password: $scope.user.pass }, function (connection) {
          if ($scope.isLoggedIn) {
            // TODO: Display a success message about the user being logged in?
            $location.path('/');
          }
          else {
            // TODO: Display the error message here.
          }
        });
      } else {
        // TODO: Is this logic sound?? Perhaps we should do this immediately when the login page loads?
        // Already logged in, run away
        $location.path('/');
      }
    };

    $scope.cancel = function () {
      $location.path('/');
    };
  }]);
