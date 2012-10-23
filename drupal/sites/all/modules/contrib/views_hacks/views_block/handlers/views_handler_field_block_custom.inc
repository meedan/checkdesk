<?php

class views_handler_field_block_custom extends views_handler_field {
  function render($values) {
    $strings = array(
      t('Show always'),
      t('Show by default'),
      t('Hide by default')
    );
    return $strings[$values->{$this->field_alias}];
  }
}

