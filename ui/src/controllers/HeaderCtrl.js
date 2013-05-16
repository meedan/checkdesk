var HeaderCtrl = ['$scope', '$translate', 'System', 'User', function ($scope, $translate, System, User) {
  var updateLangClass = function (mode, langClass) {
        switch (mode) {
          case 'remove':
            $('html').removeClass(langClass);
            break;
          case 'add':
            $('html').addClass(langClass);
            break;
        }
      };

  // Initially set the HTML language class
  updateLangClass('add', $translate.uses());

  $scope.toggleLang = function () {
    updateLangClass('remove', $translate.uses());
    if ($translate.uses() === 'en_EN') {
      $translate.uses('ar_AR');
    } else {
      $translate.uses('en_EN');
    }
    updateLangClass('add', $translate.uses());
  };


  // Determine logged in or logged out state and set up helper functions
  var anonymousUser = { uid: 0 };
  $scope.isLoggedIn = false;
  $scope.user       = angular.copy(anonymousUser);

  System.connect({}, function (connection) {
    $scope.user       = connection.user;
    $scope.isLoggedIn = !angular.isUndefined(connection.user) && connection.user.uid > 0;
  });

  $scope.login = function () {
    // Must provide both user and pass
    if (!$scope.user.name || !$scope.user.pass) {
      // TODO: Display error.
      return false;
    } else if (!$scope.user || $scope.user.uid === 0) {
      // Must not already have an established connection
      User.login({ username: $scope.user.name, password: $scope.user.pass }, function (connection) {
        $scope.user       = connection.user;
        $scope.isLoggedIn = !angular.isUndefined(connection.user) && connection.user.uid > 0;
      });
    } else {
      // Already logged in
    }
  };

  $scope.logout = function () {
    // Must send empty POST data for this to work
    User.logout({}, function (data) {
      if (data.result) {
        $scope.user       = angular.copy(anonymousUser);
        $scope.isLoggedIn = false;
      } else {
        // TODO: Display error.
      }
    });
  };
}];

app.controller('HeaderCtrl', HeaderCtrl);
