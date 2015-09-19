/*jslint nomen: true, plusplus: true, todo: true, white: true, browser: true, indent: 2 */
(function ($) {
  'use strict';
  jQuery('div.cd-slice-wrapper li.cd-slice-item').hover(
      function () {
        jQuery(this).find('div.cd-item-container').toggleClass('u-faux-block-link-hover');
      }
  );

}(jQuery));
