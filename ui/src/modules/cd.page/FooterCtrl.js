cdPage

  /**
   * @ngdoc object
   * @name cd.page.controllers:FooterCtrl
   * @requires $scope
   * @requires pageState
   * @requires Story
   *
   * @description
   * Controller for site footer.
   */
  .controller('FooterCtrl', FooterCtrl = ['$scope', '$translate', 'System', 'User', function ($scope, $translate, System, User) {
    // TODO: Unstub the informationMenu.
    $scope.informationMenu = [
      {
        title: $translate('INFORMATION_MENU_ITEM_ABOUT_TITLE'),
        href: '/about-checkdesk'
      }
    ];

    // TODO: Unstub the footerMenu.
    $scope.footerMenu = [
      {
        title: $translate('FOOTER_MENU_ITEM_MEEDAN_TITLE'),
        href: 'http://meedan.org'
      },
      {
        title: $translate('FOOTER_MENU_ITEM_CHECKDESK_TITLE'),
        href: 'http://checkdesk.org'
      }
    ];
  }]);
