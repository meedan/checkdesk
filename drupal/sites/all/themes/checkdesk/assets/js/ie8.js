(function ($) {

	// IE8 fixes
	Drupal.behaviors.ie8 = {
		attach: function (context, settings) {
			// set the width of content in presence of a sidebar
			var bodyWidth = $(window).width();
				gutter = 12;
			var sidebarWidth = $('BODY.sidebar-first #main .column#sidebar-first').width();

			var contentWidth = bodyWidth - sidebarWidth - buffer;
			$('BODY.sidebar-first #main DIV#content .inner').width(contentWidth);
			
			$(window).resize(function(){
				var bodyWidth = $(window).width();
				var contentWidth = bodyWidth - sidebarWidth - buffer;
				$('BODY.sidebar-first #main DIV#content .inner').width(contentWidth);
			});

		}
	};

})(jQuery);
