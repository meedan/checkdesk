jQuery(function() {

    jQuery('div.cd-slice-wrapper li.cd-slice-item').hover(
      function () {
        jQuery(this).find('div.cd-item-container').toggleClass('u-faux-block-link-hover');
      }
  );

});
