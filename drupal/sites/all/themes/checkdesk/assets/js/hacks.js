/*jslint nomen: true, plusplus: true, todo: true, white: true, browser: true, indent: 2 */
(function ($) {
  'use strict';

  // HACK: Twitter Bootstrap will close a dropdown menu even when someone
  //       clicks inside of it. This is annoying, only clicks OUTSIDE of the
  //       dropdown menu should close the menu.
  Drupal.behaviors.checkdeskKeepTBDropdownsOpen = {
    attach: function (context) {
      $('.dropdown-menu', context).children().each(function () {
        var $this = $(this);

        switch (this.tagName) {
          // Events will not bubble outside of IFRAMEs, the hack is not needed here
          case 'IFRAME':
          // Anchors should be followed
          case 'A':
            break;

          // All other first-child level elements should not have their clicks
          // propagate up to the dropdown-menu.
          default:
            $this.click(function (e) {
              e.stopPropagation();
            });
            break;
        }
      });
    }
  }

}(jQuery));
