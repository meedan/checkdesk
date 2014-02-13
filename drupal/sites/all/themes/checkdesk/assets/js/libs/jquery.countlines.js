;(function($){
$.fn.countLines = function(selector) {

  $(this).each(function() {

    var $container = $(this);
    var $elements = $container.find(selector);

    function allOffsetsEqual() {
      var offsets = _.map($elements, function(section) {
        return $(section).offset().top;
      });
      var allEqual = _.all(offsets, function(offset) {
        return offsets[0] == offset;
      });
      return allEqual;
    }

    function countLines(delay) {
      if (!delay) {
        delay = 0;
      }
      setTimeout(function() { // allow the browser to render changes
        declareSingleLine(); // this is necessary
        if (allOffsetsEqual()) {
          declareSingleLine();
        } else {
          declareMultipleLines();
        }
      }, delay);
    }

    function declareSingleLine() {
      $container.removeClass('multiple_lines');
      $container.addClass('single_line');
    }

    function declareMultipleLines() {
      $container.removeClass('single_line');
      $container.addClass('multiple_lines');
    }

    $(window).on('load', countLines);
    countLines();
    countLines(50);

  });

};
})(jQuery);