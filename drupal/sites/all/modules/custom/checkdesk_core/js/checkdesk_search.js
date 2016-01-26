/*jslint nomen: true, plusplus: true, todo: true, white: true, browser: true, indent: 2 */
(function ($) {
  'use strict';

  Drupal.behaviors.searchPage = {
    attach: function (context, settings) {
      // auto-submit form after user click/unclick unassigned reports
      $( "#edit-report-unassigned" ).click(function() {
        $('#views-exposed-form-checkdesk-search-page').submit();
      });

      // filter group collapse/expand
      $('.filter-list > .views-exposed-widget label').unbind('click').click(function(event) {
        var $target = $(this).parent();
        if ($target.hasClass('open')) {
          $target.removeClass('open').find('.bef-select-as-links').slideUp('fast');
        }
        else {
          $target.addClass('open').find('.bef-select-as-links').slideDown('fast');
        }
        return false;
      });

      // set filter value to "All" if it's not already set.
      $('.filter-list .bef-select-as-links').each(function() {
        if ($('.form-type-bef-link a[class="active"]', this).length === 0) {
          $('.form-type-bef-link[id$="-all"] a', this).addClass('active');
        }
      });

      // collapse filter group whose active value is "All" and open others.
      $('.filter-list .form-type-bef-link[id!="edit-type-all"][id$="-all"] a[class="active"]').parents('.bef-select-as-links').hide();
      $('.filter-list .form-type-bef-link:not([id$="-all"]) a[class="active"]').parents('.form-type-select, .views-exposed-widget').addClass('open');

      // scroll to active elements inside filters.
      // @see http://stackoverflow.com/questions/2346011/jquery-scroll-to-an-element-within-an-overflowed-div
      $('.filter-list .search-list').each(function() {
        var $item = $('.form-type-bef-link a[class="active"]', this);
        $(this).scrollTop($(this).scrollTop() + $item.position().top);
      });
      
      // prevent ajax handling of content types filter to force filters form reload
      $('.form-item-type .bef-select-as-links').find('a').unbind('click');
    }
  };

}(jQuery));
