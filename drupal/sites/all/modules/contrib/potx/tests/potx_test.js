
/**
 * Test Drupal.t and Drupal.formatPlural() invocation.
 */

Drupal.t('Test string in JS');
Drupal.formatPlural(count, '1 test string in JS', '@count test strings in JS');

Drupal.t('');

Drupal.t('String with @placeholder value', {'@placeholder': 'placeholder'});

Drupal.t('Test string in JS in test context', {}, {'context': 'Test context'});
Drupal.t('Test string in JS in context and with @placeholder', {'@placeholder': 'placeholder'}, {'context': 'Test context'});

Drupal.t('Multiline string for the test with @placeholder',
  {'@placeholder': 'placeholder'},
  {'context': 'Test context'}
);

Drupal.formatPlural(count, '1 test string in JS in test context', '@count test strings in JS in test context', {'@placeholder': 'placeholder', '%value': 12}, {'context': 'Test context'});
Drupal.formatPlural(count, '1 test string in JS with context and @placeholder', '@count test strings in JS with context and @placeholder', {'@placeholder': 'placeholder', '%value': 12}, {'context': 'Test context'});
