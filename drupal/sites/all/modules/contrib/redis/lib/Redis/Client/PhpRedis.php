<?php

/**
 * PhpRedis client specific implementation.
 */
class Redis_Client_PhpRedis implements Redis_Client_Interface {

  public function getClient($host = NULL, $port = NULL, $base = NULL, $password = NULL, $socket = NULL) {
    $client = new Redis;

    if (!empty($socket)) {
      $client->connect($socket);
    } else {
      $client->connect($host, $port);
    }

    if (isset($password)) {
      $client->auth($password);
    }

    if (isset($base)) {
      $client->select($base);
    }

    // Do not allow PhpRedis serialize itself data, we are going to do it
    // ourself. This will ensure less memory footprint on Redis size when
    // we will attempt to store small values.
    $client->setOption(Redis::OPT_SERIALIZER, Redis::SERIALIZER_NONE);

    return $client;
  }

  public function getName() {
    return 'PhpRedis';
  }
}
