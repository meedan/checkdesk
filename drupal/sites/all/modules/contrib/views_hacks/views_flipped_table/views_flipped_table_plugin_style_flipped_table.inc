<?php
/**
 * @file
 * Contains the flipped table style plugin.
 */

/**
 * Style plugin to render each item as a column in a table.
 *
 * @ingroup views_style_plugins
 */
class views_flipped_table_plugin_style_flipped_table extends views_plugin_style_table {
  function option_definition() {
    $options = parent::option_definition();

    $options['flipped_table_header_first_field'] = array('default' => TRUE);

    return $options;
  }

  /**
   * Render the given style.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['flipped_table_header_first_field'] = array(
      '#type' => 'checkbox',
      '#title' => t("Show the first field as the table header"),
      '#default_value' => $this->options['flipped_table_header_first_field'],
      '#description' => t("Outputs the flipped table's row for the first field inside a table header element."),
    );
  }
}
