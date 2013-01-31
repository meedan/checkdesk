INSTALLATION

- Install libraries module (dependency).
- Download jQuery-Placeholder library from https://github.com/danielstocks/jQuery-Placeholder
- Place this library in sites/[all/sitename/default]/libraries/placeholder
  so the jquery.placeholder.js is located at sites/[all/sitename/default]/libraries/placeholder/jquery.placeholder.js
  or glone directly; 'git clone --recursive git://github.com/danielstocks/jQuery-Placeholder.git placeholder'
  in your libraries folder.

USAGE

- Add a '#placeholder' key or a 'placeholder' element to the '#attributes'
  array of textfields or textareas.

EXAMPLES

/**
 * Implements hook_form_FORM_ID_alter().
 */
function placeholder_form_search_block_form_alter(&$form, &$form_state) {
  $form['search_block_form']['#placeholder'] = t('Search here');
  // or ....
  $form['search_block_form']['#attributes']['placeholder'] = t('Search here');
}

function my_custom_module_form() {
  $form['name'] = array(
    '#type' => 'textfield',
    '#title' => 'Name',
    '#placeholder' => t('Enter your name here'),
  );
  // ....
}
