cdUser
  .run(['User', 'System', function (User, System) {
      System.connect({}, function (connection) {
        if (angular.isObject(connection) && angular.isObject(connection.user)) {
          User.currentUser = connection.user;
          User.isLoggedIn  = !angular.isUndefined(connection.user) && connection.user.uid > 0;
        }
      });
    }]);
