/*jslint nomen: true, plusplus: true, todo: true, white: true, browser: true, indent: 2 */
(function ($) {
	'use strict';

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
	};

	// filters for reports inside sidebar
	Drupal.behaviors.reportsPage = {
		attach: function(context) {
      // configure masonry
			if ($('#reports', context).masonry) {
				$('#reports', context).masonry({ 
					itemSelector: '.report-item',
					columnWidth: function(containerWidth) {
						return containerWidth / 3;
					},
					isRTL: true
				}).imagesLoaded(function() {
					$('#reports', context).masonry('reload');
				});
        $('#reports .report-item', context).watch('height', function() { $('#reports', context).masonry('reload'); }, 1000);
			}
		}
	};

  Drupal.behaviors.transparentFrames = {
    attach: function(context) {
      $('.oembed-content', context).watch('height', function() {
        $('.oembed-content iframe', context).attr('wmode', 'transparent')
          .contents().find('iframe').attr('wmode', 'transparent')
          .attr('src', function(i, src) {
            var sep = (src.indexOf('?') == -1 ? '?' : '&');
            return (src.indexOf('wmode') == -1 ? src + sep + 'wmode=transparent' : src);
          });
      }, 1000);
    }
  };

  $.fn.scrollToHere = function(speed) {
    $('html, body').animate({ scrollTop : $(this).offset().top - $('#toolbar').height() - $('#navbar').height() }, speed);
  };

}(jQuery));
