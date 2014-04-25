cdPage

  /**
   * @ngdoc object
   * @name cd.page.controllers:WidgetsSidebarCtrl
   * @requires $scope
   * @requires $translate
   * @requires System
   * @requires User
   *
   * @description
   * Controller for widgets sidebar.
   */
  .controller('WidgetsSidebarCtrl', ['$scope', function ($scope) {
    // TODO: Pull logoSrc from the server.
    $scope.logoSrc = 'http://qa.checkdesk.org/sites/qa.checkdesk.org/files/checkdesk_theme/meedan.png';

    // TODO: Unstub featuredStories content.
    $scope.featuredStories = [
      {
        href: '/story/1510',
        title: 'الشعب يريد إقالةالوزير المتحرش',
        imageSrc: 'http://qa.checkdesk.org/sites/qa.checkdesk.org/files/styles/featured_stories_lead_image/public/adbusters_blog_occupygezi_s_2.jpg?itok=uYCbtd7B',
        description: 'أثار رد وزير الإعلام "صلاح عبد المقصود" على سؤال أحدى الصحفيات في مؤتمر صحفي أمس ضجة كبيرة على مواقع التواصل...'
      }
    ];

    // TODO: Unstub followLinks content.
    $scope.followLinks = [
      {
        href: 'https://www.facebook.com/YomatyEgypt',
        icon: 'icon-facebook'
      },
      {
        href: 'https://twitter.com/YomatyEgypt',
        icon: 'icon-twitter'
      },
      {
        href: 'http://www.youtube.com/user/weladelbaladlt',
        icon: 'icon-youtube'
      }
    ];
  }]);
