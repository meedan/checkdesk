cdPage

  /**
   * @ngdoc function
   * @name cd.page.NavbarCtrl
   * @requires $scope
   * @requires $translate
   * @requires System
   * @requires User
   *
   * @description
   * Controller for site navigation bar.
   */
  .controller('NavbarCtrl', ['$scope', '$translate', 'System', 'User', function ($scope, $translate, System, User) {
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

    // TODO: Unstub the mainMenu.
    $scope.mainMenu = [
      {
        title: $translate('MAIN_MENU_ITEM_HOME_TITLE'),
        href: '/',
        icon: 'icon-home'
      },
      {
        title: $translate('MAIN_MENU_ITEM_REPORTS_TITLE'),
        href: '/reports',
        icon: 'icon-eye-open'
      }
    ];

    // TODO: Unstub the userMenu.
    $scope.userMenu = [
      {
        title: $translate('USER_MENU_ITEM_LOGIN_TITLE'),
        href: '/user/login'
      }
    ];

    // Initially set the HTML language class
    updateLangClass('add', $translate.uses());

    $scope.toggleLang = function () {
      updateLangClass('remove', $translate.uses());
      if ($translate.uses() === 'en-NG') {
        $translate.uses('ar');
      } else {
        $translate.uses('en-NG');
      }
      updateLangClass('add', $translate.uses());
    };


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
  }]);
