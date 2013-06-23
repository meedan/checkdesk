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

  Drupal.behaviors.story = {
    attach: function (context, settings) {
      // show or hide compose update form
      $('.compose-update-form>h2').click(function() {
        $('.compose-update-form .node-post-form').slideToggle('fast');
        $(this).toggleClass('open');
        return false;
      });
    }
  };

  $.fn.scrollToHere = function(speed) {
    $('html, body').animate({ scrollTop : $(this).offset().top - $('#toolbar').height() - $('#navbar').height() }, speed);
  };

  // Add destination to login links
  // We are using JavaScript because of cache
  Drupal.behaviors.addDestinationToLogin = {
    attach: function(context) {
      var prefix = (Drupal.settings.basePath + Drupal.settings.pathPrefix).replace(/\/$/, '');
      $('a[href^="' + prefix + '/user/login"]', context).attr('href', function(index, path) {
        // Remove old destination value
        var value = path.replace(/([?&])destination=[^&]+(&|$)/, '$1').replace(/[?&]$/, ''),
            sep = (/\?/.test(value) ? '&' : '?'),
            destination = (window.location.pathname === prefix ? 'liveblog' : window.location.pathname.replace(prefix + '/', ''));
        value = value + sep + 'destination=' + destination;
        return value;
      });
    }
  };

  /**
   * Takes the data-lazy-load-src attribute of any element and applies it
   * to the src attribute when that element is in view.
   *
   * Additionally, all iframes
   *
   * Relies on the jquery.inview.js plugin by Remy Sharp
   * See: http://remysharp.com/2009/01/26/element-in-view-event-plugin/
   */
  Drupal.behaviors.lazyLoadSrc = {
    attach: function (context) {
      $('[data-lazy-load-src]:not(.processed-lazy-load-src)', context)
        .addClass('processed-lazy-load-src')
        .bind('inview', function (e, visible) {
          var $this = $(this),
              sep, src;

          if (visible) {
            // Ensure we never run this twice on the same element
            $this.unbind('inview');

            src = $this.attr('data-lazy-load-src');

            // Ensure wmode=transparent is added to both the tag AND the src URL
            // for all IFRAMEs.
            if (this.tagName === 'IFRAME') {
              $this.attr('wmode', 'transparent');

              sep = src.indexOf('?') === -1 ? '?' : '&';
              src = src.indexOf('wmode') === -1 ? src + sep + 'wmode=transparent' : src;
            }

            // Using $(this).attr('src', 'http://....'); does not appear to work
            // in some browsers.
            //
            // Kicking the DOM object directly does the trick.
            this.src = src;
          }
        });

      $('[data-lazy-load-class]:not(.processed-lazy-load-class)', context)
        .addClass('processed-lazy-load-class')
        .bind('inview', function (e, visible) {
          var $this = $(this),
              classes;

          if (visible) {
            // Ensure we never run this twice on the same element
            $this.unbind('inview');

            classes = $this.attr('data-lazy-load-class');

            this.className = classes;

            // Lazy-load tweets and livefyre comments
            if (window.twttr && window.twttr.widgets) {
              window.twttr.widgets.load();
            }
            if (Drupal.livefyreCommentCount) {
              Drupal.livefyreCommentCount.callback();
            }
          }
        });
    }
  };

}(jQuery));
