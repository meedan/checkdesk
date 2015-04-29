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

  // format select element
  Drupal.behaviors.customSelect = {
    attach: function(context) {
      // apply js plugin
      $('#edit-field-stories-und').chosen();
      $('#edit-field-desk-und').chosen();
    }
  };

  // text expander for report description
  Drupal.behaviors.textExpander = {
    attach: function(context) {
      $('span.expandable').expander({
        slicePoint: 120,
        expandPrefix: ' ',
        expandText: 'Show more&hellip;',
        expandEffect: 'fadeIn',
        expandSpeed: 300,
        moreClass: 'show-more',
        userCollapse: false,
        preserveWords: true,
      });
    }
  };

  Drupal.behaviors.story = {
    attach: function (context, settings) {
      // Show nested activity
      $('.node-media .item-nested-content-wrapper > .item-controls > .meta').unbind('click').click(function(event) {
        var target = $(this).parent(),
            element = target.parent();
        if (element.find('.item-nested-content').is(':visible')) {
          element.find('.item-nested-content').slideUp('fast');
          element.removeClass('open');
        }
        else {
          element.find('.item-nested-content').slideDown('fast');
          element.addClass('open');
          element.find('textarea[class*=expanding]').expanding();
        }
        return false;
      });

      // show or hide compose update form
      $('.compose-update-form .compose-update-header').unbind('click').click(function(event) {
        var target = $(this),
            element = target.parent();
        if (element.find('.node-post-form').is(':visible')) {
          element.find('.node-post-form').slideUp('fast');
          element.removeClass('open');
        }
        else {
          element.find('.node-post-form').slideDown('fast');
          element.addClass('open');
        }
        return false;
      });

      // Add active class to the story tab which is active
      $('.story-tabs li a.active').parents('li').addClass('active');
      
      // Initiate timeago
      $('.timeago').timeago();
    }
  };

  Drupal.behaviors.searchPage = {
    attach: function (context, settings) {
      // set focus on search field when /search page is loaded
      var pathname = window.location.pathname;
      var url = window.location.href; 
      var search = window.location.search;
      var path = pathname.split('/');

      if((path[1] == 'search' || path[2] == 'search') && (search == '')) {
        var target = $('.filter-list > .views-exposed-widget input[type=text]');
        target.focus().select().parent().addClass('selected');
      }

      $('.filter-list > .views-exposed-widget input[type=text]').focus(function() {
        $(this).parent().addClass('selected');
      });

      $('.filter-list > .views-exposed-widget input[type=text]').focusout(function() {
        $(this).parent().removeClass('selected');
      });

      // set default to open
      $('.filter-list > .views-exposed-widget label').parent().addClass('open');
      // filter group collapse/expand
      $('.filter-list > .views-exposed-widget label').unbind('click').click(function(event) {
        var target = $(this).parent();
        if (target.find('.views-widget, > .bef-select-as-links').is(':visible')) {
          target.find('.views-widget, > .bef-select-as-links').slideUp('fast');
          target.removeClass('open');
        }
        else {
          target.find('.views-widget, > .bef-select-as-links').slideDown('fast');
          target.addClass('open');
        }
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
            destination = destination.replace(/^embed\/([0-9]+)$/, 'node/$1');
        value = value + sep + 'destination=' + destination.replace(/^\//, '');
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

      // kick the event to pick up any elements already in view.
      $(window).scroll();
    }
  };

  // Things that must happen after the Drupal behaviors run
  $(window).load(function() {

      // kick the event to pick up any lazy elements already in view.
      $(window).scroll(false); // Disable scrolling the page when this event is triggered
      $(window).scroll();

      // Open story comments if anchor is present
      var match = window.location.hash.match(/^#story-comments-([0-9]+)$/);
      if (match) {
        $(match[0]).find('.fb-comments-header, .livefyre-header').click();
      }

   });

}(jQuery));
