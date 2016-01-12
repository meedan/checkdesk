<?php
/**
 * @file
 * Enables modules and site configuration for a standard site installation.
 */

/**
 * Implements hook_form_FORM_ID_alter() for install_configure_form().
 *
 * Allows the profile to alter the site configuration form.
 */
function checkdesk_form_install_configure_form_alter(&$form, $form_state) {
  // Pre-populate the site name with the server name.
  $form['site_information']['site_name']['#default_value'] = st('Checkdesk');
}

/**
 * Implements hook_install_tasks().
 */
function checkdesk_install_tasks($install_state) {
  $tasks['cd_configuration_form'] = array(
    'display_name' => st('Configure Checkdesk'),
    'display' => TRUE,
    'type' => 'form',
    'run' => INSTALL_TASK_RUN_IF_NOT_COMPLETED,
  );
  $tasks['cd_apps_form'] = array(
    'display_name' => st('Configure Web services'),
    'display' => TRUE,
    'type' => 'form',
    'run' => INSTALL_TASK_RUN_IF_NOT_COMPLETED,
  );
  $tasks['cd_import_translations'] = array(
    'display_name' => st('Import translations'),
    'type' => 'batch',
  );
  return $tasks;
}

function cd_import_translations() {
  module_enable(array('l10n_update'));
  variable_set('l10n_update_download_store', 'sites/all/translations');
  variable_set('l10n_update_check_mode', '2');
  include_once DRUPAL_ROOT . '/includes/locale.inc';
  include_once DRUPAL_ROOT . '/includes/language.inc';
  module_load_include('check.inc', 'l10n_update');
  module_load_include('batch.inc', 'l10n_update');
  //make translation as array to enforce adding multilanguage on future.
  $translations = array('ar');
  // Prepare batch process to enable languages and download translations.
  $operations = array();
  foreach ($translations as $translation) {
    locale_add_language(strtolower($translation));
    // Build batch with l10n_update module.
    $history = l10n_update_get_history();
    $available = l10n_update_available_releases();
    $updates = l10n_update_build_updates($history, $available);
    $operations = array_merge($operations, _l10n_update_prepare_updates($updates, NULL, array()));
  }
  //configure language settings.
  $providers = language_negotiation_info();
  $negotiation = array();
  $negotiation['locale-url'] = $providers['locale-url'];
  $negotiation['language-default'] = $providers['language-default'];
  language_negotiation_set('language', $negotiation);
  //update prefix for english language
  db_update('languages')
    ->fields(array(
      'prefix' => 'en',
    ))   
    ->condition('language', 'en')
    ->execute();
  //add sample content
  _cd_create_sample_content();
  //add translation for administer users.
  _cd_translate_system_menu();
  $batch = l10n_update_batch_multiple($operations, LOCALE_IMPORT_KEEP);
  return $batch;
}


function cd_configuration_form($form, &$form_state, &$install_state) {
  $form['cd_information'] = array(
    '#type' => 'fieldset',
    '#title' => st('Checkdesk information'),
    '#collapsible' => FALSE,
  );
  $form['cd_information']['site_name'] = array(
    '#type' => 'textfield',
    '#title' => st('Site name [English]'),
    '#default_value' => variable_get('site_name', 'Drupal'),
    '#required' => TRUE,
  );
  $form['cd_information']['site_name_ar'] = array(
    '#type' => 'textfield',
    '#title' => st('Site name [Arabic]'),
    '#default_value' => variable_get('site_name', 'Drupal'),
    '#required' => TRUE
  );
  $form['cd_information']['site_slogan'] = array(
    '#type' => 'textfield',
    '#title' => st('Slogan [English]'),
  );
  $form['cd_information']['site_slogan_ar'] = array(
    '#type' => 'textfield',
    '#title' => st('Slogan [Arabic]'),
  );
  $form['cd_information']['checkdesk_site_owner'] = array(
    '#title' => st('Site owner [English]'),
    '#type' => 'textfield',
  );
  $form['cd_information']['checkdesk_site_owner_ar'] = array(
    '#title' => st('Site owner [Arabic]'),
    '#type' => 'textfield',
  );
  $form['cd_information']['checkdesk_site_owner_url'] = array(
    '#title' => st('Site owner URL'),
    '#type' => 'textfield',
  );
  $form['cd_multilingual'] = array(
    '#type' => 'fieldset',
    '#title' => st('Multilingual feature'),
    '#collapsible' => FALSE,
  );
  $form['cd_multilingual']['enable_multilingual'] = array(
    '#type' => 'checkboxes',
    '#options' => array(
      1 => st('Enable multilingual feature'),
    ),
  );
  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => st('Save and continue'),
    '#weight' => 15,
  );
  return $form;
}

function cd_configuration_form_submit($form, &$form_state) {
  $values = $form_state['values'];
  if(isset($values['site_name'])) {
    i18n_variable_set('site_name', $values['site_name'], 'en');
  }
  if (isset($values['site_name_ar'])) {
    i18n_variable_set('site_name', $values['site_name_ar'], 'ar');
  }
  if (isset($values['site_slogan'])) {
    i18n_variable_set('site_slogan', $values['site_slogan'], 'en');
  }
  if (isset($values['site_slogan_ar'])) {
    i18n_variable_set('site_slogan', $values['site_slogan_ar'], 'ar');
  }
  if (isset($values['checkdesk_site_owner'])) {
    i18n_variable_set('checkdesk_site_owner', $values['checkdesk_site_owner'], 'en');
  }
  if (isset($values['checkdesk_site_owner_ar'])) {
    i18n_variable_set('checkdesk_site_owner', $values['checkdesk_site_owner_ar'], 'ar');
  }
  variable_set('checkdesk_site_owner_url', $values['checkdesk_site_owner_url']);
  //enable our features.
  module_enable(array('checkdesk_core_feature', 'checkdesk_photos_feature', 'checkdesk_advaggr_feature'));
  if ($form_state['values']['enable_multilingual'][1]) {
    module_enable(array('checkdesk_multilingual_feature'));
  }
  //set error msg to display to be none.
  variable_set('error_level', 0);
}

function cd_apps_form($form, &$form_state, &$install_state) {
  $form['embedly'] = array(
    '#type' => 'fieldset',
    '#title' => st('Embedly configuration'),
    '#collapsible' => FALSE,
  );
  $form['embedly']['oembedembedly_api_key'] = array(
    '#type' => 'textfield',
    '#title' => st('API Key'),
    '#default_value' => variable_get('oembedembedly_api_key', NULL),
    '#required' => TRUE,
  );

  $form['twitter'] = array(
    '#type' => 'fieldset',
    '#title' => st('Twitter configuration'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['twitter']['twitter_consumer_key'] = array(
    '#type' => 'textfield',
    '#title' => st('API key'),
    '#default_value' => variable_get('twitter_consumer_key', NULL),
  );  
  $form['twitter']['twitter_consumer_secret'] = array(
    '#type' => 'textfield',
    '#title' => st('API secret'),
    '#default_value' => variable_get('twitter_consumer_secret', NULL),
  );

  $form['facebook'] = array(
    '#type' => 'fieldset',
    '#title' => st('Facebook configuration'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['facebook']['fboauth_id'] = array(
    '#type' => 'textfield',
    '#title' => st('App ID'),
    '#size' => 20, 
    '#maxlengh' => 50, 
    '#default_value' => variable_get('fboauth_id', ''),
  );  
  $form['facebook']['fboauth_secret'] = array(
    '#type' => 'textfield',
    '#title' => st('App Secret'),
    '#size' => 40, 
    '#maxlengh' => 50, 
    '#default_value' => variable_get('fboauth_secret', ''),
  ); 
  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => st('Save and continue'),
    '#weight' => 15,
  );
  return $form;
}

function cd_apps_form_submit($form, &$form_state) {
  $values = $form_state['values'];
  variable_set('oembedembedly_api_key', $values['oembedembedly_api_key']);
  if (isset($values['twitter_consumer_key'])) {
    variable_set('twitter_consumer_key', $values['twitter_consumer_key']);
  }
  if (isset($values['twitter_consumer_secret'])) {
    variable_set('twitter_consumer_secret', $values['twitter_consumer_secret']);
  }
  if (isset($values['fboauth_id'])) {
    variable_set('fboauth_id', $values['fboauth_id']);
  }
  if (isset($values['fboauth_secret'])) {
    variable_set('fboauth_secret', $values['fboauth_secret']);
  }
  //change l18n_update setting to import translation from local server.
  module_enable(array('checkdesk_featured_stories_feature'));
  features_revert(array('checkdesk_core_feature' => array('translations', 'menu_links', 'uuid_node')));
  features_revert(array('checkdesk_featured_stories_feature' => array('user_permission')));
  // Copy default user picture
  $uri = variable_get('user_picture_default', '');
  if ($uri) {
    $default_picture =  basename($uri);
    $directory = str_replace($default_picture, '', $uri);
    drupal_mkdir($directory, NULL, TRUE);
    // Copy default picture
    file_unmanaged_copy('sites/all/themes/checkdesk/assets/imgs/' . $default_picture, $directory, FILE_EXISTS_REPLACE );
  }
}

/**
 * 
 */
function _cd_cleanup_install_batch($module, $module_name, &$context) {
  module_enable(array($module), FALSE);
  $context['results'][] = $module;
  $context['message'] = st('Installed %module module.', array('%module' => $module_name));
}

/**
 * Revert overridden component
 */
function _cd_cleanup_revert_batch($feature, $component, &$context) {
  features_revert(array($feature => array($component)));
  $context['results'][] = $component;
  $context['message'] = st('Reverted %feature -- %component.', array('%feature' => $feature, '%component' => $component));
}

function _cd_cleanup_finished($success, $results, $operations) {
  //revert features
  //drupal_flush_all_caches();
  //update language settings
}

/**
 * Workaround to translate Administer users menu.
 */
function _cd_translate_system_menu() {
  $object_type = 'menu_link';
  $query = db_select('menu_links', 'ml');
  $query->addField('ml', 'mlid');
  $query->condition('menu_name', 'main-menu');
  $query->condition('link_title', 'Administer users');
  $mlid = $query->execute()->fetchField();
  $object_value = menu_link_load($mlid);
  $object_value['localized_options'] = $object_value['options'];
  $object_value['i18n_menu'] = 1;
  $object = i18n_object($object_type, $object_value);
  $strings = $object->get_strings(array('empty' => TRUE));
  foreach ($strings as $item) {
    $status = $item->update(array('messages' => TRUE));
  }
  foreach ($strings as $name => $value) {
    list($textgroup, $context) = i18n_string_context(explode(':', $name));
    i18n_string_textgroup($textgroup)->build_string($context, $name);
    $result = i18n_string_textgroup($textgroup)->update_translation($context, 'ar', 'إدارة المستخدمين');
  }
}

/**
 * Function to create sample story and update.
 */
function _cd_create_sample_content() {
  global $user;
  //create stories
  $story = new stdClass(); 
  $story->type = 'discussion';
  $story->title = 'This is a Story!';
  $story->language = 'en'; 
  $story->uid = 1;
  node_object_prepare($story); 
  $story->body[LANGUAGE_NONE][0]['value'] = '<p>The story is the topic headline and a short paragraph that provides context for updates (see below). We can also add a featured image.</p>';
  $story->body[LANGUAGE_NONE][0]['summary'] = '';
  $story->body[LANGUAGE_NONE][0]['format'] = 'filtered_html'; 
  node_save($story); 
  $target_en_nid = $story->nid;
  // initiate heartbeat variables 
  $heartbeat_variables = array(
    '!user_url' => url('user/'. $user->uid),
    '!username' => $user->name,
    '!story_url' => url('node/'. $target_en_nid),
    '!story' => $story->title,
  );
  //add english report
  $node = new stdClass(); 
  $node->type = 'media';
  $node->language = 'und';
  $node->uid = 1;
  node_object_prepare($node); 
  $node->field_link[LANGUAGE_NONE][0]['url'] = 'https://www.youtube.com/watch?v=iwMO84pJwMs&list=UUL6xkW90kBI76OuApogUbFQ&feature=share&index=1'; 
  node_save($node); 
  $report_nid_en = $node->nid;
  // log activity for english report
  $variables = $heartbeat_variables;
  $variables['!report_url'] = url('node/'. $report_nid_en);
  heartbeat_api_log('checkdesk_report_suggested_to_story', $user->uid, 0, $report_nid_en, $target_en_nid, $variables);

  //create updates ...
  $node = new stdClass(); 
  $node->type = 'post';
  $node->title = 'Another update';
  $node->language = 'en'; 
  $node->uid = 1;
  node_object_prepare($node); 
  $node->body[LANGUAGE_NONE][0]['value'] = '<p>Including reports in a story update is optional (although updates with reports do look better) - an update can consist only of text and <a href="http://meedan.org/category/checkdesk/">links</a>.</p><p>Updates appear chronologically on the story page, most recent first (just like Twitter). Updates are also numbered (look to the side of this update) and timestamped. The timestamp provides a direct link to the update which can be shared on social networks.</p>';
  $node->body[LANGUAGE_NONE][0]['summary'] = NULL;
  $node->body[LANGUAGE_NONE][0]['format'] = 'liveblog';
  $node->field_desk[LANGUAGE_NONE][0]['target_id'] = $target_en_nid;
  node_save($node); 
  //log activity for update
  $variables = $heartbeat_variables;
  $variables['!update_url'] = url('node/'. $node->nid);
  heartbeat_api_log('checkdesk_new_update_on_story_i_commented_on_update', $user->uid, 0, $node->nid, $target_en_nid, $variables);

  $node = new stdClass(); 
  $node->type = 'post';
  $node->title = 'First update';
  $node->language = 'en'; 
  $node->uid = 1;
  node_object_prepare($node); 
  $node->body[LANGUAGE_NONE][0]['value'] = '<p>Updates are added to a story, as new events unfold. Updates include reports from social networks and new media. A single update can include multiple reports, within a narrative that you compose.</p><p>[checkdesk-english:report-en-nid]</p>';
  //embed report into update
  $node->body[LANGUAGE_NONE][0]['value'] = str_replace('report-en-nid', $report_nid_en, $node->body[LANGUAGE_NONE][0]['value']);
  $node->body[LANGUAGE_NONE][0]['summary'] = NULL;
  $node->body[LANGUAGE_NONE][0]['format'] = 'liveblog';
  $node->field_desk[LANGUAGE_NONE][0]['target_id'] = $target_en_nid;
  node_save($node); 
  //log activity for update
  $variables['update_url'] = url('node/'. $node->nid);
  heartbeat_api_log('checkdesk_new_update_on_story_i_commented_on_update', $user->uid, 0, $node->nid, $target_en_nid, $variables);

  //create arabic stories
  $story = new stdClass(); 
  $story->type = 'discussion';
  $story->title = 'هذا هو الموضوع!';
  $story->language = 'ar'; 
  $story->uid = 1;
  node_object_prepare($story); 
  $story->body[LANGUAGE_NONE][0]['value'] = '<p>هذا الموضوع له عنوان ويتضمن فقرة قصيرة تتضمن شرحاً يوفر السياق للتحديثات (أدناه). كما يمكنك إضافة صورة مختارة له.</p><p>&nbsp;</p>';
  $story->body[LANGUAGE_NONE][0]['summary'] = '';
  $story->body[LANGUAGE_NONE][0]['format'] = 'filtered_html';
  node_save($story); 
  $target_ar_nid = $story->nid;
  // initiate heartbeat variables 
  $heartbeat_variables = array(
    '!user_url' => url('user/'. $user->uid),
    '!username' => $user->name,
    '!story_url' => url('node/'. $target_ar_nid),
    '!story' => $story->title,
  );

  //add arabic report
  $node = new stdClass(); 
  $node->type = 'media';
  $node->language = 'und';
  $node->uid = 1;
  node_object_prepare($node); 
  $node->field_link[LANGUAGE_NONE][0]['url'] = 'https://www.youtube.com/watch?v=-2ch6n9SdZc&list=UUL6xkW90kBI76OuApogUbFQ&feature=share'; 
  node_save($node); 
  $report_nid_ar = $node->nid;
  // log activity for arabic report
  $variables = $heartbeat_variables;
  $variables['!report_url'] = url('node/'. $report_nid_ar);
  heartbeat_api_log('checkdesk_report_suggested_to_story', $user->uid, 0, $report_nid_ar, $target_ar_nid, $variables);
  //create updates ...
  $node = new stdClass(); 
  $node->type = 'post';
  $node->title = 'وهذا تحديث آخر';
  $node->language = 'ar'; 
  $node->uid = 1;
  node_object_prepare($node); 
  $node->body[LANGUAGE_NONE][0]['value'] = '<p>تضمين التقارير من الإعلام الاجتماعي ليس إجبارياً (على الرغم من أن التحديثات تبدو أفضل عندما تتضمن بعض التقارير)، حيث يمكن أن يكون التحديث عبارة عن نص <a href="http://meedan.org/category/checkdesk/">وروابط</a> فقط.</p><p>تظهر التحديثات ضمن الموضوع مرتباً زمنياً من الأحدث للأقدم (على غرار تويتر). التحديثات مرقمة (انظر بجانب التحديث) ويظهر تاريخ إنشائها تحت ذلك الرقم. ويمكنك الضغط على تاريخ الإنشاء للحصول على رابط ذلك التحديث حصراً ومشاركته على الشبكات الاجتماعية.</p>';
  $node->body[LANGUAGE_NONE][0]['summary'] = NULL;
  $node->body[LANGUAGE_NONE][0]['format'] = 'liveblog';
  $node->field_desk[LANGUAGE_NONE][0]['target_id'] = $target_ar_nid;
  node_save($node); 
  //log activity for update
  $variables = $heartbeat_variables;
  $variables['!update_url'] = url('node/'. $node->nid);
  heartbeat_api_log('checkdesk_new_update_on_story_i_commented_on_update', $user->uid, 0, $node->nid, $target_ar_nid, $variables);
  
  $node = new stdClass(); 
  $node->type = 'post';
  $node->title = 'هذا أول تحديث!';
  $node->language = 'ar'; 
  $node->uid = 1;
  node_object_prepare($node); 
  $node->body[LANGUAGE_NONE][0]['value'] = '<p>تتم إضافة التحديثات على الموضوع ويتضمن التحديث تقارير من الشبكات الإجتماعية والإعلام الجديد. يمكنك إضافة تحديثات جديدة مع تطور الأحداث المتعلقة بالموضوع. كما يمكنك إضافة أي عدد من التقارير التي تحتاجها ضمن تحديث واحد، كما يمكنك النص قبل التقارير...</p><p>[تْشِك-دِسْك-عربي:report-ar-nid]</p><p>..أو بعدها، حسب الحاجة</p>';
  //embed report into update
  $node->body[LANGUAGE_NONE][0]['value'] = str_replace('report-ar-nid', $report_nid_ar, $node->body[LANGUAGE_NONE][0]['value']);
  $node->body[LANGUAGE_NONE][0]['summary'] = NULL;
  $node->body[LANGUAGE_NONE][0]['format'] = 'liveblog';
  $node->field_desk[LANGUAGE_NONE][0]['target_id'] = $target_ar_nid;
  node_save($node); 
  //log activity for update
  $variables = $heartbeat_variables;
  $variables['!update_url'] = url('node/'. $node->nid);
  heartbeat_api_log('checkdesk_new_update_on_story_i_commented_on_update', $user->uid, 0, $node->nid, $target_ar_nid, $variables);

}

