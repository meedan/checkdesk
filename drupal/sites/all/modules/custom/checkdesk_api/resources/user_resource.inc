<?php


function _checkdesk_api_user_resource_login($provider, $parameters) {
    global $user;
    if ($user->uid) {
        // user is already logged in
        return _checkdesk_api_error(t('Already logged in as @user.', array('@user' => $user->name)), 406);
    }
    $fun_callback = '_checkdesk_api_user_login_'.$provider;
    return $fun_callback($parameters, $provider);
}

/**
 * Login with CHECKDESK provider
 * @param $parameters
 * @param $provider
 * @return array|mixed
 * @throws ServicesException
 */
function _checkdesk_api_user_login_checkdesk($parameters, $provider) {
    if (!isset($parameters['username']) || !isset($parameters['password']) ) {
        return services_error(t('Parameters missing username or password'), 400);
    }
    $username = $parameters['username'];
    $password = $parameters['password'];

    // Check if account is active.
    if (user_is_blocked($username)) {
        return _checkdesk_api_error(t('The username %name has not been activated or is blocked.', array('%name' => $username)), 403);
    }
    $uid = user_authenticate($username, $password);
    if ($uid) {
        $user = user_load($uid);
        if ($user->uid) {
            return _checkdesk_api_user_success_login($user, $provider);
        }
    }
    return _checkdesk_api_error(t('Wrong username or password.'), 401);
}

/**
 * Login with CHECKDESK provider
 * @param $parameters
 * @param $provider
 * @return array|mixed
 * @throws ServicesException
 */
function _checkdesk_api_user_login_facebook($parameters, $provider) {
    if (!isset($parameters['access_token'])) {
        return _checkdesk_api_error(t('Parameters missing access_token'), 400);
    }
    // Include fboauth functions as required.
    module_load_include('inc', 'fboauth', 'includes/fboauth.fboauth');
    $access_token = $parameters['access_token'];
    // Find Drupal user that corresponds with this Facebook user.
    $fbuser = fboauth_graph_query('me', $access_token);
    $uid = fboauth_uid_load($fbuser->id);
    if ($user = user_load($uid)) {
        if ($user->status) {
            return _checkdesk_api_user_success_login($user, $provider);
        }
        else {
            $message = t('The username %name has not been activated or is blocked.', array('%name' => $user->name));
        }
    }
    else {
        $message = t('Error: no Drupal account was found for the specified Facebook user');
    }

    return _checkdesk_api_error($message, 401);

}

/**
 *
 */
function _checkdesk_api_user_success_login($user, $provider) {
    user_login_finalize();
    return array(
        'type' => 'user',
        'data' => array(
            'provider' => $provider,
            'uid' => $user->uid,
            'url' => url('user/'. $user->uid, array('absolute' => TRUE)),
            'sessid' => session_id(),
            'session_name' => session_name(),
            'token' => drupal_get_token('services'),
            'name' => $user->name,
        ),
    );
}
