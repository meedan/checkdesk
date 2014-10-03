<?php
/**
 * @file
 * Metatag integration for the metatag_opengraph module.
 */

/**
 * Implements hook_metatag_bundled_config_alter().
 */
function metatag_opengraph_metatag_bundled_config_alter(array &$configs) {
  foreach ($configs as &$config) {
    switch ($config->instance) {
      case 'global':
        $config->config += array(
          'og:site_name' => array('value' => '[site:name]'),
          'og:title' => array('value' => '[current-page:title]'),
          'og:type' => array('value' => 'article'),
          'og:url' => array('value' => '[current-page:url:absolute]'),
        );
        break;

      case 'global:frontpage':
        $config->config += array(
          'og:description' => array('value' => '[site:slogan]'),
          'og:title' => array('value' => '[site:name]'),
          'og:type' => array('value' => 'website'),
          'og:url' => array('value' => '[site:url]'),
        );
        break;

      // On error pages point everything to the homepage.
      case 'global:403':
      case 'global:404':
        $config->config += array(
          'og:title' => array('value' => '[site:name]'),
          'og:type' => array('value' => 'website'),
          'og:url' => array('value' => '[site:url]'),
        );
        break;

      case 'node':
        $config->config += array(
          'og:description' => array('value' => '[node:summary]'),
          'og:title' => array('value' => '[node:title]'),
        );
        break;

      case 'taxonomy_term':
        $config->config += array(
          'og:description' => array('value' => '[term:description]'),
          'og:title' => array('value' => '[term:name]'),
        );
        break;

      case 'user':
        $config->config += array(
          'og:title' => array('value' => '[user:name]'),
          'og:type' => array('value' => 'profile'),
        );
        if (variable_get('user_pictures')) {
          $config->config += array(
            'og:image' => array('value' => '[user:picture:url]'),
          );
        }
        break;
    }
  }
}

/**
 * Implements hook_metatag_info().
 */
function metatag_opengraph_metatag_info() {
  $info['groups']['open-graph'] = array(
    'label' => t('Open Graph'),
    'form' => array(
      '#weight' => 50,
    ),
  );

  // Default values for each meta tag.
  $tag_info_defaults = array(
    'description' => '',
    'class' => 'DrupalTextMetaTag',
    'group' => 'open-graph',
    'element' => array(
      '#theme' => 'metatag_property',
    ),
  );

  // Open Graph meta tags stack after the Facebook tags.
  $weight = 25;

  $info['tags']['og:site_name'] = array(
    'label' => t('Open Graph site name'),
    'description' => t('A human-readable name for your site, e.g., <em>IMDb</em>.'),
    'context' => array('global'),
    'weight' => ++$weight,
  ) + $tag_info_defaults;

  $info['tags']['og:title'] = array(
    'label' => t('Open Graph title'),
    'description' => t('The title of your object as it should appear within the graph, e.g., <em>The Rock</em>.'),
    'weight' => ++$weight,
  ) + $tag_info_defaults;

  $info['tags']['og:description'] = array(
    'label' => t('Open Graph description'),
    'description' => t('A one to two sentence description of your page.'),
    'weight' => ++$weight,
  ) + $tag_info_defaults;

  $info['tags']['og:type'] = array(
    'label' => t('Open Graph type'),
    'description' => t('The type of your object, e.g., <em>movie</em>.'),
    'weight' => ++$weight,
    'form' => array(
      '#type' => 'select',
      '#options' => _metatag_opengraph_type_options(),
      '#empty_option' => t('- None -'),
    ),
  ) + $tag_info_defaults;

  if (module_exists('select_or_other')) {
    // Enhance the og:type field to support custom types.
    $info['tags']['og:type']['form']['#type'] = 'select_or_other';
    $info['tags']['og:type']['form']['#other'] = t('Other (please type a value)');
    $info['tags']['og:type']['form']['#other_unknown_defaults'] = 'other';
    $info['tags']['og:type']['form']['#theme'] = 'select_or_other';
    $info['tags']['og:type']['form']['#element_validate'] = array('select_or_other_element_validate');
  }

  $info['tags']['og:image'] = array(
    'label' => t('Open Graph image'),
    'description' => t('An image URL which should represent your object within the graph. The image must be at least 50px by 50px and have a maximum aspect ratio of 3:1. Supports PNG, JPEG and GIF formats.'),
    'multiple' => TRUE,
    'weight' => ++$weight,
    'devel_generate' => array(
      'type' => 'image',
    ),
  ) + $tag_info_defaults;

  $info['tags']['og:image:secure_url'] = array(
    'label' => t('Open Graph secure image'),
    'description' => t('A secure (HTTPS) image URL which should represent your object within the graph. The image must be at least 50px by 50px and have a maximum aspect ratio of 3:1. Supports PNG, JPEG and GIF formats. All "http://" URLs will automatically be converted to "https://".'),
    'multiple' => TRUE,
    'secure' => TRUE,
    'weight' => ++$weight,
    'devel_generate' => array(
      'type' => 'image',
    ),
  ) + $tag_info_defaults;

  $info['tags']['og:url'] = array(
    'label' => t('Open Graph URL'),
    'description' => t('The canonical URL of your object that will be used as its permanent ID in the graph, e.g., <em>http://www.imdb.com/title/tt0117500/</em>.'),
    'weight' => ++$weight,
    'devel_generate' => array(
      'type' => 'canonical',
    ),
  ) + $tag_info_defaults;

  $info['tags']['og:latitude'] = array(
    'label' => t('Open Graph Latitude'),
    'weight' => ++$weight,
    'devel_generate' => array(
      'type' => 'float',
    ),
  ) + $tag_info_defaults;
  $info['tags']['og:longitude'] = array(
    'label' => t('Open Graph Longitude'),
    'weight' => ++$weight,
    'devel_generate' => array(
      'type' => 'float',
    ),
  ) + $tag_info_defaults;

  $info['tags']['og:street-address'] = array(
    'label' => t('Open Graph Street Address'),
    'weight' => ++$weight,
  ) + $tag_info_defaults;
  $info['tags']['og:locality'] = array(
    'label' => t('Open Graph Locality'),
    'weight' => ++$weight,
  ) + $tag_info_defaults;
  $info['tags']['og:region'] = array(
    'label' => t('Open Graph Region'),
    'weight' => ++$weight,
  ) + $tag_info_defaults;
  $info['tags']['og:postal-code'] = array(
    'label' => t('Open Graph Postal Code'),
    'weight' => ++$weight,
  ) + $tag_info_defaults;
  $info['tags']['og:country-name'] = array(
    'label' => t('Open Graph Country Name'),
    'weight' => ++$weight,
  ) + $tag_info_defaults;

  $info['tags']['og:email'] = array(
    'label' => t('Open Graph Email'),
    'weight' => ++$weight,
    'devel_generate' => array(
      'type' => 'email',
    ),
  ) + $tag_info_defaults;
  $info['tags']['og:phone_number'] = array(
    'label' => t('Open Graph Phone Number'),
    'weight' => ++$weight,
    'devel_generate' => array(
      'type' => 'phone',
    ),
  ) + $tag_info_defaults;
  $info['tags']['og:fax_number'] = array(
    'label' => t('Open Graph Fax Number'),
    'weight' => ++$weight,
    'devel_generate' => array(
      'type' => 'phone',
    ),
  ) + $tag_info_defaults;

  $info['tags']['og:locale'] = array(
    'label' => t('Open Graph Locale'),
    'description' => 'The locale these tags are marked up in. Of the format language_TERRITORY. Default is en_US.',
    'weight' => ++$weight,
    'devel_generate' => array(
      'maxlength' => 1,
    ),
  ) + $tag_info_defaults;

  $info['tags']['og:video'] = array(
    'label' => t('Open Graph Video URL'),
    'description' => t('A URL to a video file that complements this object.'),
    'weight' => ++$weight,
    'devel_generate' => array(
      'type' => 'url',
    ),
  ) + $tag_info_defaults;
  $info['tags']['og:video:secure_url'] = array(
    'label' => t('Open Graph Video Secure URL'),
    'description' => t('A URL to a video file that complements this object using the HTTPS protocol. All "http://" URLs will automatically be converted to "https://".'),
    'secure' => TRUE,
    'weight' => ++$weight,
    'devel_generate' => array(
      'type' => 'url',
    ),
  ) + $tag_info_defaults;
  $info['tags']['og:video:width'] = array(
    'label' => t('Open Graph Video Width'),
    'description' => t('The width of the video.'),
    'weight' => ++$weight,
    'devel_generate' => array(
      'type' => 'integer',
    ),
  ) + $tag_info_defaults;
  $info['tags']['og:video:height'] = array(
    'label' => t('Open Graph Video Height'),
    'description' => t('The height of the video.'),
    'weight' => ++$weight,
    'devel_generate' => array(
      'type' => 'integer',
    ),
  ) + $tag_info_defaults;
  $info['tags']['og:video:type'] = array(
    'label' => t('Open Graph Video Type'),
    'description' => t('The type of the video file.'),
    'weight' => ++$weight,
    'form' => array(
      '#type' => 'select',
      '#options' => array(
        'application/x-shockwave-flash' => 'Flash - playable directly from the feed',
        'text/html' => 'Separate HTML page',
      ),
      '#empty_option' => t('- None -'),
    ),
  ) + $tag_info_defaults;

  return $info;
}

function _metatag_opengraph_type_options() {
  $options = array(
    t('Activities') => array(
      'activity' => t('Activity'),
      'sport' => t('Sport'),
    ),
    t('Businesses') => array(
      'bar' => t('Bar', array('context' => 'an establishment')),
      'company' => t('Company'),
      'cafe' => t('Cafe'),
      'hotel' => t('Hotel'),
      'restaurant' => t('Restaurant'),
    ),
    t('Groups') => array(
      'cause' => t('Cause'),
      'sports_league' => t('Sports league'),
      'sports_team' => t('Sports team'),
    ),
    t('Organizations') => array(
      'band' => t('Band'),
      'government' => t('Government'),
      'non_profit' => t('Non-profit'),
      'school' => t('School'),
      'university' => t('University'),
    ),
    t('People') => array(
      'actor' => t('Actor'),
      'athlete' => t('Athlete'),
      'author' => t('Author'),
      'director' => t('Director'),
      'musician' => t('Musician'),
      'politician' => t('Politician'),
      'profile' => t('Profile'),
      'public_figure' => t('Public figure'),
    ),
    t('Places') => array(
      'city' => t('City'),
      'country' => t('Country'),
      'landmark' => t('Landmark'),
      'state_province' => t('State or province'),
    ),
    t('Products and Entertainment') => array(
      'album' => t('Album'),
      'book' => t('Book'),
      'drink' => t('Drink'),
      'food' => t('Food'),
      'game' => t('Game'),
      'movie' => t('Movie'),
      'product' => t('Product'),
      'song' => t('Song'),
      'tv_show' => t('TV show'),
    ),
    t('Websites') => array(
      'blog' => t('Blog'),
      'website' => t('Website'),
      'article' => t('Article'),
    ),
  );

  return $options;
}
