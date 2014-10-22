<?php
/**
 * @file
 * DemoTour export UI plugin.
 */

/**
 * Define this Export UI plugin.
 */
$plugin = array(
  'schema' => 'demo_tour_presets',
  'access' => 'administer demo tour',

  'menu' => array(
    'menu item' => 'demo_tour',
    'menu title' => 'Demo Tour',
    'menu description' => 'Administer Demo tours.',
  ),

  'title singular' => t('tour'),
  'title plural' => t('tours'),
  'title singular proper' => t('Demo Tour'),
  'title plural proper' => t('Demo Tours'),

  'form' => array(
    'settings' => 'demo_tour_ctools_export_ui_form',
  ),
);

/**
 * Implements hook_ctools_export_ui_form().
 */
function demo_tour_ctools_export_ui_form(&$form, &$form_state) {
  $preset = $form_state['item'];
  $form_state['storage']['steps'] = isset($form_state['storage']['steps']) ? $form_state['storage']['steps'] : count($preset->steps);

  $form['title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#description' => t('Readable name for this tour'),
    '#default_value' => $preset->title,
  );

  $roles = is_array($preset->roles) ? $preset->roles : array();
  $form['roles'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Roles'),
    '#description' => t('Which roles will take this tour'),
    '#options' => user_roles(),
    '#default_value' => $roles,
  );

  $form['paths'] = array(
    '#type' => 'textarea',
    '#title' => t('Paths'),
    '#description' => t('Just play the tour if the current path matches one of the patterns above (one per line)'),
    '#default_value' => (isset($preset->paths) ? $preset->paths : ''),
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
    '#attributes' => array('class' => array('edit-steps')),
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
        '#maxlength' => 512,
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
      'callback' => 'demo_tour_ajax_add_step',
      'wrapper' => 'steps',
    ),
  );

  $form_state['storage']['steps']++;
  
  $form['#after_build'] = array('_demo_tour_load_form_javascript');
  
  return $form;
}

function demo_tour_ajax_add_step($form, $form_state) {
  return $form['steps'];
}

/**
 * Implements hook_ctools_export_ui_form_submit().
 */
function demo_tour_ctools_export_ui_form_submit(&$form, &$form_state) {
  for ($i = 0; $i < $form_state['storage']['steps']; $i++) {
    if (!isset($form_state['values']['steps'][$i])) {
      array_splice($form_state['item']->steps, $i, 1);
      $form_state['storage']['steps']--;
    }

    else {
      $element = $form_state['values']['steps'][$i];

      if (empty($element['element']) || empty($element['title']) || empty($element['content'])) {
        array_splice($form_state['values']['steps'], $i, 1);
        array_splice($form_state['item']->steps, $i, 1);
        $form_state['storage']['steps']--;
      }
    }
  }
}
