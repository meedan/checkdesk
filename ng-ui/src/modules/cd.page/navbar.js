cdPage

  /**
   * @ngdoc object
   * @name cd.page.controllers:NavbarCtrl
   * @requires $scope
   * @requires $translate
   * @requires User
   *
   * @description
   * Controller for site navigation bar.
   */
  .controller('NavbarCtrl', ['$scope', '$translate', 'User', function ($scope, $translate, User) {
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

    $scope.currentUser = User.currentUser;
    $scope.isLoggedIn = User.isLoggedIn;

    // TODO: Unstub the mainMenu.
    $scope.mainMenu = [
      {
        title: $translate('MAIN_MENU_ITEM_HOME_LINK'),
        href: '/',
        icon: 'icon-home'
      },
      {
        title: $translate('MAIN_MENU_ITEM_REPORTS_LINK'),
        href: '/reports',
        icon: 'icon-eye-open'
      }
    ];

    // TODO: Unstub the userMenu.
    $scope.$watch('currentUser', function (newVal, oldVal) {
      console.log([newVal, oldVal], 'Watching curentUser');
      if (newVal.uid > 0) {
        $scope.userMenu = [
          {
            title: $translate('USER_MENU_ITEM_LOGOUT_LINK'),
            click: function () {
              // Must send empty POST data for this to work
              User.logout({});
            }
          }
        ];
      } else {
        $scope.userMenu = [
          {
            title: $translate('USER_MENU_ITEM_LOGIN_LINK'),
            href: '/user/login'
          }
        ];
      }
    }, true);

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
  }])

  /**
   * @ngdoc directive
   * @name cd.page.directives:cdMenuItem
   *
   * @description
   * Renders a Checkdesk menu item.
   */
  .directive('cdMenuItem', function () {
    return {
      restrict: 'A',
      scope: { item: '=cdMenuItem' },
      template: ['<a href="{{item.href}}" ng-click="item.click()">',
                   '<span ng-show="item.icon" class="{{item.icon}}"></span>',
                   '{{item.title | translate}}',
                 '</a>'].join('')
    };
  });
