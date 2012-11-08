<?php
/**
 * @file
 * Classes to implement the full Twitter API
 */

/**
 * Exception handling class.
 */
class TwitterException extends Exception {
  /**
   * Overrides constructor to log the error.
   */
  public function __construct($message = NULL, $code = 0, Exception $previous = NULL) {
    watchdog('twitter', 'Unexpected error: @message', array(
      '@message' => $message,
    ), WATCHDOG_ERROR);
    if (is_null($previous)) {
      parent::__construct($message, $code);
    }
    else {
      parent::__construct($message, $code, $previous);
    }
  }
}

/**
 * Primary Twitter API implementation class
 * Supports the full REST API for twitter.
 */
class Twitter {

  /**
   * @var $format API format to use: can be json or xml
   */
  protected $format = 'json';

  /**
   * @var $source the twitter api 'source'
   */
  protected $source = 'drupal';

  /**
   * @var $username Twitter username to use for authenticated requests
   */
  protected $username;

  /**
   * @var $password Twitter password to use for authenticated requests
   */
  protected $password;

  /**
   * Constructor for the Twitter class
   */
  public function __construct($username = NULL, $password = NULL) {
    if (!empty($username) && !empty($password)) {
      $this->set_auth($username, $password);
    }
  }

  /**
   * Set the username and password
   */
  public function set_auth($username, $password) {
    $this->username = $username;
    $this->password = $password;
  }

  /**
   * Get an array of TwitterStatus objects from an API endpoint
   */
  protected function get_statuses($path, $params = array(), $use_auth = FALSE) {
    $values = $this->call($path, $params, 'GET', $use_auth);
    // Check on successfull call
    if ($values) {
      $statuses = array();
      foreach ($values as $status) {
        $statuses[] = new TwitterStatus($status);
      }
      return $statuses;
    }
    // Call might return FALSE , e.g. on failed authentication
    else {
      // As call allready throws an exception, we can return an empty array to
      // break no code.
      return array();
    }
  }

  /**
   * Fetch a user's timeline
   *
   * @see https://dev.twitter.com/docs/api/1/get/statuses/user_timeline
   */
  public function user_timeline($id, $params = array(), $use_auth = FALSE) {
    if (is_numeric($id)) {
      $params['user_id'] = $id;
    }
    else {
      $params['screen_name'] = $id;
    }
    return $this->get_statuses('statuses/user_timeline', $params, $use_auth);
  }

  /**
   *
   * @see https://dev.twitter.com/docs/api/1/get/statuses/mentions
   */
  public function mentions($params = array()) {
    return $this->get_statuses('statuses/mentions', $params, TRUE);
  }

  /**
   * Post a new status.
   *
   * @see https://dev.twitter.com/docs/api/1/post/statuses/update
   */
  public function status_update($status, $params = array()) {
    $params['status'] = $status;
    if ($this->source) {
      $params['source'] = $this->source;
    }
    if ($values = $this->call('statuses/update', $params, 'POST', TRUE)) {
      return new TwitterStatus($values);
    }
  }

  /**
   * Returns profile information about a user.
   *
   * @see https://dev.twitter.com/docs/api/1/get/users/show
   */
  public function users_show($id, $use_auth = TRUE) {
    $params = array();
    if (is_numeric($id)) {
      $params['user_id'] = $id;
    }
    else {
      $params['screen_name'] = $id;
    }

    if ($values = $this->call('users/show', $params, 'GET', $use_auth)) {
      return new TwitterUser($values);
    }
  }

  /**
   *
   * @see https://dev.twitter.com/docs/api/1/get/account/verify_credentials
   */
  public function verify_credentials() {
    if ($values = $this->call('account/verify_credentials', array(), 'GET', TRUE)) {
      return new TwitterUser($values);
    }
  }

  /**
   * Calls a twitter api resource
   *
   * @param $path
   *   string REST resource to be called
   * @param $params
   *   array of settings to be sent along
   * @param $method
   *   string method to be used (GET or POST)
   * @param $use_oauth
   *   boolean indicating if the call should use OAuth authentication of not
   */
  public function call($path, $params = array(), $method = 'GET', $use_auth = FALSE) {
    $url = $this->create_url($path);

    try {
      if ($use_auth) {
        $response = $this->auth_request($url, $params, $method);
      }
      else {
        $response = $this->request($url, $params, $method);
      }
    }
    catch (TwitterException $e) {
      watchdog('twitter', '!message', array('!message' => $e->__toString()), WATCHDOG_ERROR);
      drupal_set_message('Twitter returned an error: ' . $e->getMessage(), 'error');
      return FALSE;
    }

    if (!$response) {
      return FALSE;
    }

    return $this->parse_response($response);
  }

  /**
   * Perform an authentication required request.
   */
  protected function auth_request($path, $params = array(), $method = 'GET') {
    if (empty($this->username) || empty($this->password)) {
      return false;
    }

    return $this->request($path, $params, $method, TRUE);
  }

  /**
   * Perform a request
   *
   * @throws TwitterException
   */
  protected function request($url, $params = array(), $method = 'GET', $use_auth = FALSE) {
    $data = '';
    if (count($params) > 0) {
      if ($method == 'GET') {
        $url .= '?'. http_build_query($params, '', '&');
      }
      else {
        $data = http_build_query($params, '', '&');
      }
    }

    $headers = array();

    if ($use_auth) {
      $headers['Authorization'] = 'Basic '. base64_encode($this->username .':'. $this->password);
      $headers['Content-type'] = 'application/x-www-form-urlencoded';
    }

    $response = drupal_http_request($url, array('headers' => $headers, 'method' => $method, 'data' => $data));
    if (!isset($response->error)) {
      return $response->data;
    }
    else {
      $error = 'Unknown error.';
      if (isset($response->error)) {
        $error = $response->error;
      }
      if (isset($response->data) && $data = $this->parse_response($response->data)) {
        if (is_array($data)) {
          if (isset($data['errors'][0]['message'])) {
            $error = $data['errors'][0]['message'];
          }
          elseif (isset($data['error'])) {
            $error = $data['error'];
          }
        }
      }
      throw new TwitterException($error);
    }
  }

  protected function parse_response($response, $format = NULL) {
    if (empty($format)) {
      $format = $this->format;
    }

    switch ($format) {
      case 'json':
        // http://drupal.org/node/985544 - json_decode large integer issue
        $length = strlen(PHP_INT_MAX);
        $response = preg_replace('/"(id|in_reply_to_status_id)":(\d{' . $length . ',})/', '"\1":"\2"', $response);
        return json_decode($response, TRUE);
    }
  }

  protected function create_url($path, $format = NULL) {
    if (is_null($format)) {
      $format = $this->format;
    }
    $url =  variable_get('twitter_api', TWITTER_API) .'/1/'. $path;
    if (!empty($format)) {
      $url .= '.'. $this->format;
    }
    return $url;
  }
}

/**
 * A class to provide OAuth enabled access to the twitter API
 */
class TwitterOAuth extends Twitter {

  protected $signature_method;

  protected $consumer;

  protected $token;

  public function __construct($consumer_key, $consumer_secret, $oauth_token = NULL, $oauth_token_secret = NULL) {
    $this->signature_method = new OAuthSignatureMethod_HMAC_SHA1();
    $this->consumer = new OAuthConsumer($consumer_key, $consumer_secret);
    if (!empty($oauth_token) && !empty($oauth_token_secret)) {
      $this->token = new OAuthConsumer($oauth_token, $oauth_token_secret);
    }
  }

  /**
   * Builds a full URL to perform an OAuth operation
   *
   * @param $path
   *   string the path of the operation
   * @param $format
   *   string a valid format
   * @return
   *   string full URL
   */
  protected function create_oauth_url($path, $format = NULL) {
    if (is_null($format)) {
      $format = $this->format;
    }
    $url =  variable_get('twitter_api', TWITTER_API) .'/'. $path;
    if (!empty($format)) {
      $url .= '.'. $this->format;
    }
    return $url;
  }

  public function get_request_token() {
    $url = $this->create_oauth_url('oauth/request_token', '');
    try {
      $response = $this->auth_request($url);
    }
    catch (TwitterException $e) {
    }
    parse_str($response, $token);
    $this->token = new OAuthConsumer($token['oauth_token'], $token['oauth_token_secret']);
    return $token;
  }

  public function get_authorize_url($token) {
    $url = $this->create_oauth_url('oauth/authorize', '');
    $url.= '?oauth_token=' . $token['oauth_token'];

    return $url;
  }

  public function get_authenticate_url($token) {
    $url = $this->create_oauth_url('oauth/authenticate', '');
    $url.= '?oauth_token=' . $token['oauth_token'];

    return $url;
  }

  public function get_access_token() {
    $url = $this->create_oauth_url('oauth/access_token', '');
    try {
      $response = $this->auth_request($url);
    }
    catch (TwitterException $e) {
    }
    parse_str($response, $token);
    $this->token = new OAuthConsumer($token['oauth_token'], $token['oauth_token_secret']);
    return $token;
  }

  public function auth_request($url, $params = array(), $method = 'GET') {
    $request = OAuthRequest::from_consumer_and_token($this->consumer, $this->token, $method, $url, $params);
    $request->sign_request($this->signature_method, $this->consumer, $this->token);
    switch ($method) {
      case 'GET':
        return $this->request($request->to_url());
      case 'POST':
        return $this->request($request->get_normalized_http_url(), $request->get_parameters(), 'POST');
    }
  }

}

/**
  * Twitter search is not used in this module yet
  */
class TwitterSearch extends Twitter {
  public function search($params = array()) {}
}

/**
 * Class for containing an individual twitter status.
 */
class TwitterStatus {
  /**
   * @var created_at
   */
  public $created_at;

  public $id;

  public $text;

  public $source;

  public $truncated;

  public $favorited;

  public $in_reply_to_status_id;

  public $in_reply_to_user_id;

  public $in_reply_to_screen_name;

  public $user;

  /**
   * Constructor for TwitterStatus
   */
  public function __construct($values = array()) {
    $this->created_at = $values['created_at'];
    $this->id = $values['id'];
    $this->text = $values['text'];
    $this->source = $values['source'];
    $this->truncated = $values['truncated'];
    $this->favorited = $values['favorited'];
    $this->in_reply_to_status_id = $values['in_reply_to_status_id'];
    $this->in_reply_to_user_id = $values['in_reply_to_user_id'];
    $this->in_reply_to_screen_name = $values['in_reply_to_screen_name'];
    if (isset($values['user'])) {
      $this->user = new TwitterUser($values['user']);
    }
  }

}

class TwitterUser {

  public $id;

  public $screen_name;

  public $name;

  public $location;

  public $description;

  public $followers_count;

  public $friends_count;

  public $statuses_count;

  public $favourites_count;

  public $url;

  public $protected;

  public $profile_image_url;

  public $profile_background_color;

  public $profile_text_color;

  public $profile_link_color;

  public $profile_sidebar_fill_color;

  public $profile_sidebar_border_color;

  public $profile_background_image_url;

  public $profile_background_tile;

  public $verified;

  public $created_at;

  public $created_time;

  public $utc_offset;

  public $status;

  protected $password;

  protected $oauth_token;

  protected $oauth_token_secret;

  public function __construct($values = array()) {
    $this->id = $values['id'];
    $this->screen_name = $values['screen_name'];
    $this->name = $values['name'];
    $this->location = $values['location'];
    $this->description = $values['description'];
    $this->url = $values['url'];
    $this->followers_count = $values['followers_count'];
    $this->friends_count = $values['friends_count'];
    $this->statuses_count = $values['statuses_count'];
    $this->favourites_count = $values['favourites_count'];
    $this->protected = $values['protected'];
    $this->profile_image_url = $values['profile_image_url'];
    $this->profile_background_color = $values['profile_background_color'];
    $this->profile_text_color = $values['profile_text_color'];
    $this->profile_link_color = $values['profile_link_color'];
    $this->profile_sidebar_fill_color = $values['profile_sidebar_fill_color'];
    $this->profile_sidebar_border_color = $values['profile_sidebar_border_color'];
    $this->profile_background_image_url = $values['profile_background_image_url'];
    $this->profile_background_tile = $values['profile_background_tile'];
    $this->verified = $values['verified'];
    $this->created_at = $values['created_at'];
    if ($values['created_at'] && $created_time = strtotime($values['created_at'])) {
      $this->created_time = $created_time;
    }
    $this->utc_offset = $values['utc_offset']?$values['utc_offset']:0;

    if (isset($values['status'])) {
      $this->status = new TwitterStatus($values['status']);
    }
  }

  public function get_auth() {
    return array('password' => $this->password, 'oauth_token' => $this->oauth_token, 'oauth_token_secret' => $this->oauth_token_secret);
  }

  public function set_auth($values) {
    $this->oauth_token = isset($values['oauth_token'])?$values['oauth_token']:NULL;
    $this->oauth_token_secret = isset($values['oauth_token_secret'])?$values['oauth_token_secret']:NULL;
  }
}
