(function ($) {

	// IE8 fixes
	Drupal.behaviors.ie8 = {
		attach: function (context, settings) {
      if ($.browser.msie) {

        
  			// set the width of content in presence of a sidebar
  			var bodyWidth = $(window).width();
  				gutter = 12;
  			var sidebarWidth = $('BODY.sidebar-first #main .column#sidebar-first').width();

  			var contentWidth = bodyWidth - sidebarWidth - gutter;
  			$('BODY.sidebar-first #main DIV#content .inner').width(contentWidth);
  			
  			$(window).resize(function(){
  				var bodyWidth = $(window).width();
  				var contentWidth = bodyWidth - sidebarWidth - gutter;
  				$('BODY.sidebar-first #main DIV#content .inner').width(contentWidth);
  			});

        // Make embedded media's width render properly
        $('.report .report-content .report-media .container').each(function(i) {
          // if a video
          if ($(this).children('.oembed-video').length != 0) {
            var embeddedMediaWidth = $('.report .report-content .report-media .container iframe').attr('width');
            $(this).width(embeddedMediaWidth);
          }
          // if media like twitter set width explicitly
          if ($(this).children('.oembed-rich').length != 0) {
            $(this).css('width', '400');
          }
        });
      }
		}
	};

  // Simulate placeholder
  Drupal.behaviors.ie8placeholder = {
    attach: function(context, settings) {
      if ($.browser.msie) { 
        $('input[placeholder], textarea[placeholder]', context).each(function() {

          var input = $(this);
          $(input).val(input.attr('placeholder'));

          $(input).focus(function() {
            if (input.val() == input.attr('placeholder')) {
              input.val('');
            }
          });

          $(input).blur(function() {
            if (input.val() == '' || input.val() == input.attr('placeholder')) {
              input.val(input.attr('placeholder'));
            }
          });

        });
      }
    }
  };

})(jQuery);
