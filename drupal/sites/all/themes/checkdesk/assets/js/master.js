(function ($) {

	/**
	 * Provide the HTML to create the modal dialog.
	 */
	Drupal.theme.prototype.CToolsModalDialog = function () {
		var html = '';


		html += '<div id="ctools-modal">';
		html += '<div class="ctools-modal-content">';
		html += '<div class="modal">';
		html += '  <div class="modal-header">';
		html += '   <button type="button" class="close" data-dismiss="modal" aria-hidden="true">&times;</button>';
		html += '   <h4><span id="modal-title" class="modal-title"></span></h4>';
		html += '  </div>';
		html += ' <div class="modal-body">';
		html += '   <div id="modal-content" class="modal-content"></div>';
		html += ' </div>';
		html += '</div>';
		html += '</div>';
		html += '</div>';

		return html;

	}

	// filters for reports inside sidebar
	Drupal.behaviors.installBookmarklet = {
		attach: function (context, settings) {
			// set the top margin of modal
			var bodyHeight = $(window).height();
				percentage = 20;
			var modalPosition = ((percentage / 100) * bodyHeight);
			$('div.modal-install-bookmarklet#modalContent').css('top', modalPosition);
			
			$(window).resize(function(){
				var bodyHeight = $(window).height();
				var modalPosition = ((percentage / 100) * bodyHeight);
				$('div.modal-install-bookmarklet#modalContent').css('top', modalPosition);
			});

		}
	};

})(jQuery);
