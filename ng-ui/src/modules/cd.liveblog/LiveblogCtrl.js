cdLiveblog

  /**
   * @ngdoc object
   * @name cd.liveblog.controllers:LiveblogCtrl
   * @requires $scope
   * @requires pageState
   * @requires Story
   *
   * @description
   * Controller for liveblog.html template.
   */
  .controller('LiveblogCtrl', ['$scope', 'pageState', 'Story', function ($scope, pageState, Story) {
    // TODO: This page title management is clunky, could it be moved to the router?
    pageState.headTitle('Liveblog');
    pageState.title('Liveblog');

    $scope.stories = [];

    Story.query(function (stories) {
      for (var i = 0; i < stories.length; i++) {
        // LOL: Hilariously unperformant, we will improve this of course.
        $scope.stories.push(Story.get({ nid: stories[i].nid }));
      }

      pageState.status('ready'); // This page has finished loading
    });
  }]);
