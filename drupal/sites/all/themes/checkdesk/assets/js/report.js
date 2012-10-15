(function ($) {

	Drupal.behaviors.reports = {
		attach: function () {
			// show report activity
			$('.report-activity>header').click(function(event) {
				var target = $(event.target);
				var element = target.parent().attr('id');
				$('#'+ element + ' .activity-list').slideToggle('fast');
				$('#'+ element).toggleClass('open');
				return false;
			});
		}
	};

})(jQuery);