(function($) {
  Drupal.behaviors.utf8mb4_converter = {
    attach: function(context, settings) {
      jQuery("#utf8mb4-converter-column-list .convert-button button", context)
        .not("utf8mb4-converter-button-processed")
        .bind("click", Drupal.behaviors.utf8mb4_converter.convertButtonOnClickHandler)
        .addClass("utf8mb4-converter-button-processed");
      var unconverted = jQuery("tr.unconverted", context).length,
        truncateDanger = jQuery(".dont-truncate").length,
        messageString = "<h1>Table Converter</h1><p>Drupal Installation has "+unconverted+" unconverted rows.</p>";
      if (truncateDanger >= 1) {
        messageString += "<span class='danger'>You have " + truncateDanger + " rows that will be truncated if you convert all. Truncated rows are in red. Please convert them and then refresh the page to convert the remainder with a single click.</span>";
      } else {
        messageString += "Rows to be converted are shown in green. Primary keys will be truncated to 191 characters but you have no primary key values that are longer than that. <a href='/admin/config/system/utf8mb4/convert'>Convert All</a>";
      }
      jQuery(messageString).insertBefore("#utf8mb4-converter-column-list");
    },
    convertButtonOnClickHandler: function(evt) {
      console.log(this);
      var tablename = jQuery(this).data("table");
      jQuery("#" + tablename + "-column-list")
        .load(Drupal.settings.basePath+Drupal.settings.pathPrefix+"admin/config/system/utf8mb4/"+tablename);
    },
  }
})(jQuery)
