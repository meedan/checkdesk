<?php

class views_handler_field_block_cache extends views_handler_field {
  function render($values) {
    $cache = $values->{$this->field_alias};
    if ($cache == BLOCK_NO_CACHE) {
      return 'BLOCK_NO_CACHE';
    }
    $caches = array(
      BLOCK_CACHE_PER_ROLE => 'BLOCK_CACHE_PER_ROLE',
      BLOCK_CACHE_PER_USER => 'BLOCK_CACHE_PER_USER',
      BLOCK_CACHE_PER_PAGE => 'BLOCK_CACHE_PER_PAGE',
      BLOCK_CACHE_GLOBAL => 'BLOCK_CACHE_GLOBAL',
    );
    $result = array();
    foreach ($caches as $bit => $string) {
      if (($cache & $bit) > 0) {
        $result[] = $string;
      }
    }
    return implode("\n", $result);
  }
}

