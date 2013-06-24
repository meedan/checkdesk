var LiveblogCtrl = ['$scope', 'pageState', 'Story', function ($scope, pageState, Story) {
  $scope.stories = [];

  Story.query(function (stories) {
    for (var i = 0; i < stories.length; i++) {
      // LOL: Hilariously unperformant, we will improve this of course.
      $scope.stories.push(Story.get({ nid: stories[i].nid }));
    }

    pageState.status('ready'); // This page has finished loading
  });
}];

app.controller('LiveblogCtrl', LiveblogCtrl);
