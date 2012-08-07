<?php

class views_handler_field_block_region extends views_handler_field {
  function render($values) {
    return empty($values->{$this->field_alias}) ? '('. t('none') .')' : $values->{$this->field_alias};
  }
}

