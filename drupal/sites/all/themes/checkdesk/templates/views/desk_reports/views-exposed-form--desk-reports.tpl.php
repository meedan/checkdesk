<?php

/**
 * @file
 * This template handles the layout of the views exposed filter form.
 *
 * Variables available:
 * - $widgets: An array of exposed form widgets. Each widget contains:
 * - $widget->label: The visible label to print. May be optional.
 * - $widget->operator: The operator for the widget. May be optional.
 * - $widget->widget: The widget itself.
 * - $sort_by: The select box to sort the view using an exposed form.
 * - $sort_order: The select box with the ASC, DESC options to define order. May be optional.
 * - $items_per_page: The select box with the available items per page. May be optional.
 * - $offset: A textfield to define the offset of the view. May be optional.
 * - $reset_button: A button to reset the exposed filter applied. May be optional.
 * - $button: The submit button for the form.
 *
 * @ingroup views_templates
 */
?>
<section id="incoming-reports-filters">
  <?php if (!empty($q)): ?>
    <?php
      // This ensures that, if clean URLs are off, the 'q' is added first so that
      // it shows up first in the URL.
      print $q;
    ?>
  <?php endif; ?>
  <header>
    <h2><?php print t('Incoming Reports'); ?></h2>
  </header>
  <ul class="panels">
    <li id="sort-by" class="panel">
      <a href="#" class="panel-toggle"><?php print t('Sort by'); ?> <span class="icon-caret-down"></span></a>
      <div class="panel-content">
        <?php if (!empty($sort_by)): ?>
          <div class="views-exposed-widget views-widget-sort-by">
            <?php /* There is just one option, better to hide it: print $sort_by; */ ?>
          </div>
          <div class="views-exposed-widget views-widget-sort-order">
            <?php print $sort_order; ?>
          </div>
        <?php endif; ?>
        <div class="views-exposed-widget views-submit-button">
          <?php print $button; ?>
        </div>
      </div>
    </li>
    <li id="filter-by" class="panel">
      <a href="#" class="panel-toggle"><?php print t('Filter'); ?> <span class="icon-caret-down"></span></a>
      <div class="panel-content">

        <?php 
          global $language;
          if ($language->direction == LANGUAGE_RTL) {
            $tabs_direction = 'right';
          } else {
            $tabs_direction = 'left';
          }
        ?>

        <div class="tabbable tabs-<?php print $tabs_direction; ?>">
          <ul class="nav nav-tabs">
            <?php foreach ($widgets as $id => $widget): ?>
              <li>
                <a href="#<?php print $widget->id; ?>" data-toggle="tab">
                  <?php print $widget->label; ?>
                </a>
              </li>
            <?php endforeach; ?>
          </ul>

          <div class="tab-content">
            <?php foreach ($widgets as $id => $widget): ?>
            <div class="tab-pane" id="<?php print $widget->id; ?>">
              <?php print $widget->description; ?>
              <?php print $widget->widget; ?>
              <?php print $widget->operator; ?>
            </div>
            <?php endforeach; ?>
          </div>
        </div>

        <?php if (!empty($items_per_page)): ?>
          <div class="views-exposed-widget views-widget-per-page">
            <?php print $items_per_page; ?>
          </div>
        <?php endif; ?>
        <?php if (!empty($offset)): ?>
          <div class="views-exposed-widget views-widget-offset">
            <?php print $offset; ?>
          </div>
        <?php endif; ?>

        <div class="views-exposed-widget views-submit-button">
          <?php print $button; ?>
          <a id="close" class="btn" data-dismiss="dropdown" aria-hidden="true"><?php print t('Close'); ?></a>
        </div>
        
        <?php if (!empty($reset_button)): ?>
          <div class="views-exposed-widget views-reset-button">
            <?php print $reset_button; ?>
          </div>
        <?php endif; ?>
      </div>
    </li>
  </ul>
  

</section>
