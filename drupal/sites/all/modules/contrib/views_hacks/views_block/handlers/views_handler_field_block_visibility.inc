<?php

class views_handler_field_block_visibility extends views_handler_field {
  function render($values) {
    $strings = array(
      t('All except listed pages'),
      t('Only listed pages'),
      t('PHP code'),
    );
    return $strings[$values->{$this->field_alias}];
  }
}

