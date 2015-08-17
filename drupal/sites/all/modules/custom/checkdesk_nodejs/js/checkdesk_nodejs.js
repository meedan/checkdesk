(function ($) {

Drupal.Nodejs.callbacks.reportReactor = { 
  callback: function (message) {
    console.log("Let's update report - reactor replacement");
    console.log(message);
    Drupal.nodejs_ajax.runCommands(message);
    
  }
};

}(jQuery));

