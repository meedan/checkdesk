<?php

/**
 * Client proxy, client handling class tied to the bare mininum.
 */
interface Redis_Client_Interface {
  /**
   * Get the connected client instance.
   * 
   * @return mixed
   *   Real client depends from the library behind.
   */
  public function getClient($host = NULL, $port = NULL, $base = NULL);

  /**
   * Get underlaying library name used.
   * 
   * This can be useful for contribution code that may work with only some of
   * the provided clients.
   * 
   * @return string
   */
  public function getName();
}
