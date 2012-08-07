<?php

class views_handler_field_block_format extends views_handler_field {
  function render($values) {
    if (!isset($values->{$this->field_alias})) return '';
    $formats = filter_formats();
    return $formats[$values->{$this->field_alias}]->name;
  }
}

