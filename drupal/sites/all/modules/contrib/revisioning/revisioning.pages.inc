<?php

/**
 * @file
 * Rendering and altering of pages and forms used by Revisioning.
 */

/**
 * Implements hook_form_alter().
 *
 * Note: for cases where the FORM_ID is known a priori we use
 * revisioning_form_FORMID_form_alter().
 */
function revisioning_form_alter(&$form, &$form_state, $form_id) {

  if (!empty($form['#node_edit_form'])) {

    $node = &$form['#node'];

    $is_moderated_content = isset($node->revision_moderation) ? $node->revision_moderation : revisioning_content_is_moderated($form['type']['#value'], $node);

    // Alter the Create/Edit content form, if subject to moderation.
    if ($is_moderated_content) {
      // "Create new revision" must be set when the node is to be moderated.
      $node->revision = TRUE;
      // Next line is not essential, just ensures form options are
      // consistent with the edited content being subject to moderation.
      $form['revision_information']['revision']['#default_value'] = TRUE;
      // For moderated content "Published" box will be treated as unticked,
      // See revisioning_node_presave().
    }

    // Only add this radio selector if user has the appropriate permissions.
    // 'administer nodes' is required by default, but if configured
    // appropriately, then any user premitted to publish this node will get the
    // shortcut controls.
    $add_radio_selector = variable_get('revisioning_publication_shortcuts', FALSE) ?
      revisioning_user_node_access('publish revisions', $node) :
      user_access('administer nodes');
    if ($add_radio_selector) {
      // Expand and move this vertical tab to top, so that it's in user's face.
      if (isset($form['menu'])) {
        $form['menu']['#collapsed'] = TRUE;
      }
      $form['revision_information']['#collapsed'] = FALSE;
      $form['revision_information']['#weight'] = -3;

      $options = array();
      if (isset($node->nid)) {
        $options[REVISIONING_NO_REVISION] = t('Modify current revision, no moderation');
      }
      $options[REVISIONING_NEW_REVISION_NO_MODERATION]  = t('Create new revision, no moderation');
      $options[REVISIONING_NEW_REVISION_WITH_MODERATION] = t('Create new revision and moderate');

      // This radio selection will appear in hook_node_presave as
      // $node->revision_operation
      $form['revision_information']['revision_operation'] = array(
        '#title' => t('Revision creation and moderation options'),
        '#description' => t('Moderation means that the new revision is not publicly visible until approved by someone with the appropriate permissions.'),
        '#type' => 'radios',
        '#options' => $options,
        '#default_value' => isset($node->nid)
          ? (int) $node->revision + (int) $is_moderated_content
          : ($is_moderated_content ? REVISIONING_NEW_REVISION_WITH_MODERATION : REVISIONING_NEW_REVISION_NO_MODERATION),
      );
      unset($form['revision_information']['revision']);

      // Add javascript to show/hide the "Published" checkbox if the user
      // presses one of the first two radio buttons. Also updates summary tabs.
      $js_file = drupal_get_path('module', 'revisioning') . '/js/revisioning-radios.js';
      // After node.js.
      drupal_add_js($js_file, array('weight' => 1));
      if (variable_get('revisioning_no_moderation_by_default', FALSE)) {
        $form['revision_information']['revision_operation']['#default_value'] = REVISIONING_NEW_REVISION_NO_MODERATION;
      }
    }
    else {
      // For non-admin don't show radios, just set default, hidden on form.
      // Note that $form['revision_information']['revision'] is already set.
      $form['revision_moderation'] = array(
        '#type' => 'value',
        '#value' => $is_moderated_content,
      );
    }

    // In addition to node_form_submit() append our own handler to the list, so
    // that we can redirect to the pending, as opposed to current, revision.
    $form['actions']['submit']['#submit'][] = '_revisioning_form_submit';

    if (isset($form['actions']['delete']) && isset($form['actions']['delete']['#type'])) {
      $nid = $form['#node']->nid;
      if (revisioning_get_number_of_revisions($nid) > 1) {
        // Special treatment for Delete button when there are >= 2 revisions.
        if ($form['#node']->vid == revisioning_get_current_node_revision_id($nid)) {
          // Make it obvious to user that a 'Delete' is in fact 'Delete all'.
          $form['actions']['delete']['#value'] = t('Delete (all revisions)');
        }
        elseif (user_access('delete revisions')) {
          // Change the meaning of the 'Delete' button when editing a revision
          // to be the deletion of the viewed revision, rather than the node
          // node.
          $form['actions']['delete']['#value'] = t('Delete this revision');
          $form['actions']['delete']['#submit'][] = '_revisioning_delete_submit';
        }
      }
    }
  }
}

/**
 * Implements hook_form_FORM_ID_form_alter().
 *
 * On the content type edit form, add the "New revision in draft, pending
 * moderation" tick-box and a couple of radio-boxes to select the new revision
 * and auto-publish policies.
 */
function revisioning_form_node_type_form_alter(&$form, &$form_state) {
  $form['workflow']['#collapsed'] = FALSE;
  $form['workflow']['node_options']['#options']['revision_moderation'] = t('New revision in draft, pending moderation (requires "Create new revision")');

  $form['workflow']['revisioning'] = array(
    '#type' => 'fieldset',
    '#title' => t('New revision in draft'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $content_type = $form['#node_type']->type;
  $form['workflow']['revisioning']['new_revisions'] = array(
    '#title' => t('Create new revision:'),
    '#type' => 'radios',
    '#options' => array(
      REVISIONING_NEW_REVISION_WHEN_NOT_PENDING => t('Only when saving %type content that is not already in draft/pending moderation', array('%type' => $content_type)),
      REVISIONING_NEW_REVISION_EVERY_SAVE => t('Every time %type content is updated, even when saving content in draft/pending moderation', array('%type' => $content_type))),
    '#default_value' => (int) variable_get('new_revisions_' . $content_type, REVISIONING_NEW_REVISION_WHEN_NOT_PENDING),
    '#description' => t('Use less disk space and avoid cluttering your revisions list. With the first option ticked, modifications are saved to the same copy (i.e. no additional revisions are created) until the content is published.'),
  );
  $form['workflow']['revisioning']['revisioning_auto_publish'] = array(
    '#title' => t('Auto-publish drafts of type %type (for moderators)', array('%type' => $content_type)),
    '#type' => 'checkbox',
    '#default_value' => (int) variable_get('revisioning_auto_publish_' . $content_type, FALSE),
    '#description' => t('If this box is ticked and the user has one of the "Publish content revisions" permissions, then any draft of type %type is published immediately upon saving, without further review or the option to schedule a publication date.', array('%type' => $content_type)),
  );
}

/**
 * Return a confirmation page for publishing a revision.
 */
function revisioning_publish_confirm($form, &$form_state, $node) {
  $form['node_id']  = array('#type' => 'value', '#value' => $node->nid);
  $form['title']    = array('#type' => 'value', '#value' => $node->title);
  $form['revision'] = array('#type' => 'value', '#value' => $node->vid);
  $form['type']     = array('#type' => 'value', '#value' => $node->type);
  return confirm_form($form,
    t('Are you sure you want to publish this revision of %title?', array('%title' => $node->title)),
    'node/' . $node->nid . '/revisions',
    t('Publishing this revision will make it visible to the public.'),
    t('Publish'), t('Cancel'));
}

/**
 * Submission handler for the publish_confirm form.
 */
function revisioning_publish_confirm_submit($form, &$form_state) {
  $nid = $form_state['values']['node_id'];
  $vid = $form_state['values']['revision'];
  $node = node_load($nid, $vid);
  _revisioning_publish_revision($node);
  revisioning_set_status_message(t('Revision has been published.'));
  // Redirect to the same page as unpublish and revert.
  $form_state['redirect'] = "node/$nid/revisions";
}

/**
 * Return a confirmation page for unpublishing the node.
 */
function revisioning_unpublish_confirm($form, &$form_state, $node) {
  $form['node_id'] = array('#type' => 'value', '#value' => $node->nid);
  $form['title']   = array('#type' => 'value', '#value' => $node->title);
  $form['type']    = array('#type' => 'value', '#value' => $node->type);
  return confirm_form($form,
    t('Are you sure you want to unpublish %title?', array('%title' => $node->title)),
    "node/$node->nid/revisions",
    t('Unpublishing will remove this content from public view.'),
    t('Unpublish'), t('Cancel'));
}

/**
 * Submission handler for the unpublish_confirm form.
 */
function revisioning_unpublish_confirm_submit($form, &$form_state) {
  $nid = $form_state['values']['node_id'];
  _revisioning_unpublish_revision($nid);
  $title = $form_state['values']['title'];
  revisioning_set_status_message(t('%title is no longer publicly visible.', array('%title' => $title)));
  // Redirect to the same page as publish and revert.
  $form_state['redirect'] = "node/$nid/revisions";
}

/**
 * Return a confirmation page for deleting archived revisione.
 */
function revisioning_delete_archived_confirm($form, &$form_state, $node) {
  $node->num_archived = revisioning_get_number_of_archived_revisions($node);
  $form['node']  = array('#type' => 'value', '#value' => $node);
  $t = format_plural($node->num_archived,
    'Are you sure you want to delete the archived revision of %title?',
    'Are you sure you want to delete all @count archived revisions of %title?',
    array('%title' => $node->title)
  );
  return confirm_form($form, $t, 'node/' . $node->nid . '/revisions',
    t('This action cannot be undone.'),
    t('Delete archived'), t('Cancel'));
}

/**
 * Submission handler for the delete_archived_confirm form.
 */
function revisioning_delete_archived_confirm_submit($form, &$form_state) {
  $node = $form_state['values']['node'];
  revisioning_delete_archived_revisions($node);
  $t = format_plural($node->num_archived, 'One archived revision deleted.', '@count archived revisions deleted.');
  revisioning_set_status_message($t);
  $form_state['redirect'] = ($node->num_revisions - $node->num_archived > 1) ? 'node/' . $node->nid . '/revisions' : 'node/' . $node->nid;
}

/**
 * Implements hook_form_FORM_ID_alter().
 *
 * @see node.pages.inc/node_revision_revert_confirm()
 */
function revisioning_form_node_revision_revert_confirm_alter(&$form, &$form_state) {
  $node = $form['#node_revision'];
  if (_revisioning_get_number_of_pending_revisions($node->nid) > 0) {
    drupal_set_message(t('There is a pending revision. Are you sure you want to revert to an archived revision?'), 'warning');
  }
  array_unshift($form['#submit'], 'revisioning_revert_confirm_pre_submit');
  $form['#submit'][] = 'revisioning_revert_confirm_post_submit';
}

/**
 * Implements hook_form_FORM_ID_alter().
 *
 * We only add "pre" submit handler, because "post delete" event is already
 * available via hook_nodeapi().
 *
 * @see node_revision_delete_confirm()
 */
function revisioning_form_node_revision_delete_confirm_alter(&$form, &$form_state) {
  array_unshift($form['#submit'], 'revisioning_revision_delete_confirm_pre_submit');
}

/**
 * Submission "pre" handler for the node_revision_delete_confirm form.
 *
 * Runs BEFORE the existing delete function in node.pages.inc
 */
function revisioning_revision_delete_confirm_pre_submit($form, &$form_state) {
  $node = $form['#node_revision'];
  module_invoke_all('revisionapi', 'pre delete', $node);
}

/**
 * Submission "pre" handler the revert_confirm form.
 *
 * Runs BEFORE the existing revert function in node.pages.inc
 */
function revisioning_revert_confirm_pre_submit($form, &$form_state) {
  $node = $form['#node_revision'];
  $return = module_invoke_all('revisionapi', 'pre revert', $node);
  if (in_array(FALSE, $return)) {
    drupal_goto('node/' . $node->nid . '/revisions/' . $node->vid . '/view');
  }
}

/**
 * Submission "post" handler for the revert_confirm form.
 *
 * Runs AFTER the existing revert function in node.pages.inc
 *
 * Note:
 * It would be nice if publish and revert were symmetrical operations and that
 * node_revision_revert_confirm_submit didn't save a physical copy of the
 * revision (under a new vid), as this has the side-effect of making all
 * "pending" revisions "archived". This is because the definition of "pending"
 * is: "node_vid > current_vid".
 * It would be better if "pending" relied on a separate flag rather than a field
 * such as vid or timestamp that changes every time a piece of code executes a
 * node_save().
 */
function revisioning_revert_confirm_post_submit($form, &$form_state) {
  $node = $form['#node_revision'];
  // _revisioning_publish_node($node->nid); [#611988]
  module_invoke_all('revisionapi', 'post revert', $node);
}


/**
 * Return as a themed table a list of nodes that have pending revisions.
 *
 * Also checks access rights of the logged-in user.
 *
 * @param string $access
 *   Operation, one of 'view', 'update' or 'delete'.
 * @param int $user_filter
 *   One of NO_FILTER, I_CREATED or I_LAST_MODIFIED.
 *
 * @return string
 *   themed HTML
 */
function _revisioning_show_pending_nodes($access = 'view', $user_filter = NO_FILTER) {
  $is_moderated = user_access('administer nodes') ? NO_FILTER : TRUE;
  $content_summary = module_grants_monitor_accessible_content_summary($access, NO_FILTER, $user_filter, $is_moderated, TRUE);
  if (user_access('view revision status messages') && strpos($content_summary, 'No content') === FALSE && !user_access('administer nodes')) {
    _revisioning_set_info_message();
  }
  return $content_summary;
}

/**
 * Set info message.
 */
function _revisioning_set_info_message() {
  if (user_access('publish revisions')) {
    $moderated_types = array();
    foreach (node_type_get_types() as $type) {
      if (revisioning_content_is_moderated($type->type) &&
        (user_access('view revisions') || user_access('view revisions of any ' . $type->type . ' content'))) {
        $moderated_types[] = $type->name;
      }
    }
    if (count($moderated_types) > 0) {
      drupal_set_message(t('You have permission to publish content revisions of type(s): %moderated_types.',
        array('%moderated_types' => implode(', ', $moderated_types))));
    }
  }
}

/**
 * Handler for the 'Save' button on the edit form.
 *
 * When saving a new revision we shouldn't redirect to "View current", as
 * that's not the one we've saved.
 */
function _revisioning_form_submit($form, &$form_state) {
  // Don't redirect when creating new node, when not moderated or user doesn't
  // have access to the revision.
  if (isset($form_state['node']->nid) && !empty($form_state['node']->revision_moderation) && _revisioning_access_node_revision('view revisions', $form_state['node'])) {
    $form_state['redirect'] = 'node/' . $form_state['node']->nid . '/revisions/' . $form_state['node']->vid . '/view';
  }
}

/**
 * Handler for the 'Delete this revision' button on the edit form.
 *
 * Redirect to node/%/revisions/%/delete as opposed to node/%/delete
 */
function _revisioning_delete_submit(&$form, &$form_state) {
  $form_state['redirect'][0] = 'node/' . $form['#node']->nid . '/revisions/' . $form['#node']->vid . '/delete';
}


/**
 * Implements hook_block_info().
 *
 * A block that may be placed on selected pages, alerting the moderator when
 * new content has been submitted for review. Shows titles of pending revisions
 * as a series of links. Clicking a link takes the moderator straight to the
 * revision in question.
 */
function revisioning_block_info() {
  $block['pending']['info'] = t('Pending revisions');
  $block['pending']['cache'] = DRUPAL_NO_CACHE;
  // Towards top of whatever region is chosen.
  $block['pending']['weight'] = -10;
  // Block is implemented by this module.
  $block['pending']['custom'] = FALSE;
  return $block;
}

/**
 * Implements hook_block_configure().
 */
function revisioning_block_configure($delta = 'pending') {
  $form['revisioning_block_num_pending'] = array(
    '#type' => 'textfield',
    '#title' => t('Maximum number of pending revisions displayed'),
    '#default_value' => variable_get('revisioning_block_num_pending', 5),
    '#description' => t('Note: the title of this block mentions the total number of revisions pending, which may be greater than the number of revisions displayed.'),
  );
  $form['revisioning_block_order'] = array(
    '#type' => 'radios',
    '#title' => t('Order in which pending revisions are displayed'),
    '#options' => array(
      REVISIONING_REVISIONS_BLOCK_OLDEST_AT_TOP => t('Oldest at top'),
      REVISIONING_REVISIONS_BLOCK_NEWEST_AT_TOP => t('Newest at top')),
    '#default_value' => variable_get('revisioning_block_order', REVISIONING_REVISIONS_BLOCK_NEWEST_AT_TOP),
    '#description' => t('Note: order is based on revision timestamps.'),
  );
  $form['revisioning_content_summary_page'] = array(
    '#type' => 'textfield',
    '#title' => t('Page to go to when the block title is clicked'),
    '#default_value' => variable_get('revisioning_content_summary_page', ''),
    '#description' => t('When left blank this will default to either %view_content, if the Views module is enabled, or %admin_content, subject to permissions.<br/>For any of this to work the above <strong>Block title</strong> field must be left blank.', array(
      '%view_content' => 'content-summary',
      '%admin_content' => 'admin/content')),
  );
  return $form;
}

/**
 * Implements hook_block_save().
 */
function revisioning_block_save($delta = '', $edit = array()) {
  variable_set('revisioning_block_num_pending', (int) $edit['revisioning_block_num_pending']);
  variable_set('revisioning_block_order', (int) $edit['revisioning_block_order']);
  variable_set('revisioning_content_summary_page', $edit['revisioning_content_summary_page']);
}

/**
 * Implements hook_block_view().
 */
function revisioning_block_view($delta = '') {
  $order = variable_get('revisioning_block_order', REVISIONING_REVISIONS_BLOCK_NEWEST_AT_TOP) == REVISIONING_REVISIONS_BLOCK_NEWEST_AT_TOP ? 'DESC' : 'ASC';
  $revisions = revisioning_get_revisions('view revision list', NO_FILTER, NO_FILTER, NO_FILTER, TRUE, TRUE, 100, 'timestamp ' . $order);
  if (!empty($revisions)) {
    return _revisioning_block_pending_revisions_content($revisions);
  }
}

/**
 * Define content for pending revisions block.
 *
 * @param array $revisions
 *   array of revision objects
 *
 * @return array
 *   the block array
 */
function _revisioning_block_pending_revisions_content($revisions) {
  $num_revisions = count($revisions);
  $max_num_shown = variable_get('revisioning_block_num_pending', 5);
  $links = array();
  foreach (array_slice($revisions, 0, $max_num_shown) as $revision) {
    // If they exist, should we show multiple pending revisions on same node?
    $links[] = l($revision->title, "node/$revision->nid/revisions/$revision->vid/view");
  }
  // Also loads /css/revisioning-rtl.css
  drupal_add_css(drupal_get_path('module', 'revisioning') . '/css/revisioning.css');
  $title_link = trim(variable_get('revisioning_content_summary_page', ''));
  $link_options = array();
  if (empty($title_link)) {
    if (module_exists('views')) {
      $title_link = 'content-summary';
      $link_options['query'] = array('revision_moderation' => 1, 'state' => 2);
    }
    elseif (user_access('access content overview')) {
      $title_link = 'admin/content';
    }
  }
  $title = t('!num_revisions pending', array(
    '!num_revisions' => format_plural($num_revisions, '1 revision', '@count revisions'),
  ));
  $block = array();
  $block['subject'] = empty($title_link) ? $title : l($title, $title_link, $link_options);
  $block['content'] = theme('item_list', array('items' => $links, 'title' => ''));
  return $block;
}
