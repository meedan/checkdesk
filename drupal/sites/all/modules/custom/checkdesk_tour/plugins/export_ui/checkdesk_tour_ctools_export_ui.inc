<?php
/**
 * @file
 * CheckdeskTour export UI plugin.
 */

/**
 * Define this Export UI plugin.
 */
$plugin = array(
  'schema' => 'checkdesk_tour_presets',
  'access' => 'administer checkdesk tour',

  'menu' => array(
    'menu item' => 'checkdesk_tour',
    'menu title' => 'Checkdesk Tour',
    'menu description' => 'Administer Checkdesk tours.',
  ),

  'title singular' => t('tour'),
  'title plural' => t('tours'),
  'title singular proper' => t('Checkdesk Tour'),
  'title plural proper' => t('Checkdesk Tours'),

  'form' => array(
    'settings' => 'checkdesk_tour_ctools_export_ui_form',
  ),
);

/**
 * Implements hook_ctools_export_ui_form().
 */
function checkdesk_tour_ctools_export_ui_form(&$form, &$form_state) {
  $preset = $form_state['item'];
  $form_state['storage']['steps'] = isset($form_state['storage']['steps']) ? $form_state['storage']['steps'] : count($preset->steps);

  $form['title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#description' => t('Readable name for this tour'),
    '#default_value' => $preset->title,
  );

  $form['roles'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Roles'),
    '#description' => t('Which roles will take this tour'),
    '#options' => user_roles(),
    '#default_value' => $preset->roles,
  );

  $form['auto'] = array(
    '#type' => 'checkbox',
    '#title' => t('Auto play once'),
    '#default_value' => $preset->auto,
    '#description' => t('Play this tour automatically only once per user'),
  );

  $form['steps'] = array(
    '#type' => 'fieldset',
    '#title' => t('Steps'),
    '#collapsible' => TRUE, 
    '#collapsed' => FALSE,
    '#tree' => TRUE,
    '#prefix' => '<div id="steps">',
    '#suffix' => '</div>',
  );

  if ($form_state['storage']['steps']) {
    for ($i = 0; $i < $form_state['storage']['steps']; $i++) {

      $form['steps'][$i] = array(
        '#type' => 'fieldset',
        '#title' => t('Step #@i', array('@i' => ($i + 1))),
        '#collapsible' => TRUE, 
        '#collapsed' => FALSE,
        '#tree' => TRUE,
      );

      $form['steps'][$i]['element'] = array(
        '#type' => 'textfield',
        '#title' => t('Element'),
        '#description' => t('CSS selector of the element targeted by this step'),
        '#default_value' => $preset->steps[$i]['element'],
      );
      
      $form['steps'][$i]['title'] = array(
        '#type' => 'textfield',
        '#title' => t('Title'),
        '#description' => t('Title of this step'),
        '#default_value' => $preset->steps[$i]['title'],
      );

      $form['steps'][$i]['content'] = array(
        '#type' => 'textarea',
        '#title' => t('Content'),
        '#description' => t('Content of this step'),
        '#default_value' => $preset->steps[$i]['content'],
      );

    }
  }

  $form['add_step'] = array(
    '#type' => 'button',
    '#value' => t('Add a step'),
    '#href' => '',
    '#ajax' => array(
      'callback' => 'checkdesk_tour_ajax_add_step',
      'wrapper' => 'steps',
    ),
  );

  $form_state['storage']['steps']++;

  return $form;
}

function checkdesk_tour_ajax_add_step($form, $form_state) {
  return $form['steps'];
}
