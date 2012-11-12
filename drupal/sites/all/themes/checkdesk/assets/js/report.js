(function ($) {

	Drupal.behaviors.reports = {
		attach: function () {
			// show report activity
			$('.report-activity > header').click(function(event) {
				var target = $(this);
				var element = target.parent().attr('id');
				$('#'+ element + ' .activity-wrapper').slideToggle('fast');
				$('#'+ element).toggleClass('open');
				return false;
			});
			
		}
	};

})(jQuery);