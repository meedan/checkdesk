<?php
/**
 * @file
 * Metatag integration for the metatag Twitter Cards module.
 */

/**
 * Implements hook_metatag_config_default_alter().
 */
function metatag_twitter_cards_metatag_config_default_alter(array &$configs) {
  foreach ($configs as &$config) {
    switch ($config->instance) {
      case 'global':
        $config->config += array(
          'twitter:card' => array('value' => 'summary'),
          'twitter:description' => array('value' => '[site:slogan]'),
          'twitter:title' => array('value' => '[site:name]'),
          'twitter:url' => array('value' => '[current-page:url:absolute]'),
        );
        break;

      case 'global:frontpage':
        $config->config += array(
          'twitter:description' => array('value' => ''),
        );
        break;

      // On error pages point everything to the homepage.
      case 'global:403':
      case 'global:404':
        $config->config += array(
          'twitter:description' => array('value' => ''),
          'twitter:title' => array('value' => '[site:name]'),
          'twitter:url' => array('value' => '[site:url]'),
        );
        break;

      case 'node':
        $config->config += array(
          'twitter:card' => array('value' => 'summary'),
          'twitter:description' => array('value' => '[node:summary]'),
          'twitter:title' => array('value' => '[node:title]'),
        );
        break;

      case 'taxonomy_term':
        $config->config += array(
          'twitter:card' => array('value' => 'summary'),
          'twitter:title'=> array('value' => '[term:name]'),
        );
        break;
    }
  }
}

/**
 * Implements hook_metatag_info().
 */
function metatag_twitter_cards_metatag_info() {
  $info['groups']['twitter-cards'] = array(
    'label' => t('Twitter card'),
    'description' => t('A set of meta tags specially for controlling the summaries displayed when content is shared on <a href="!url">Twitter</a>.', array('!url' => 'http://twitter.com/')),
    'form' => array(
      '#weight' => 60,
    ),
  );

  $info['tags']['twitter:card'] = array(
    'label' => t('Twitter card type'),
    'description' => t('Notes: no other fields are required for a <em>Summary</em> card, a <em>Photo</em> card requires the \'image\' field, a <em>Media player</em> card requires the \'title\', \'description\', \'media player URL\', \'media player width\', \'media player height\' and \'image\' fields, a <em>Summary Card with Large Image</em> card requires the \'Summary\' field and the \'image\' field, a <em>Gallery Card</em> requires all the \'Gallery Image\' fields, an <em>App Card</em> requires the \'iPhone app ID\' field, the \'iPad app ID\' field and the \'Google Play app ID\' field, a <em>Product Card</em> requires the \'description\' field, the \'image\' field, the \'Label 1\' field, the \'Data 1\' field, the \'Label 2\' field and the \'Data 2\' field.'),
    'class' => 'DrupalTextMetaTag',
    'group' => 'twitter-cards',
    'form' => array(
      '#type' => 'select',
      '#options' => array(
        'summary' => t('Summary (default)'),
        'summary_large_image' => t('Summary with large image'),
        'photo' => t('Photo'),
        'player' => t('Media player'),
        'gallery' => t('Gallery'),
        'app' => t('App'),
        'product' => t('Product'),
      ),
      '#empty_option' => t('- None -'),
    ),
    'element' => array(
      '#theme' => 'metatag_twitter_cards',
    ),
  );
  $info['tags']['twitter:site'] = array(
    'label' => t('Site\'s Twitter account'),
    'description' => t('The @username for the website, which will be displayed in the Card\'s footer; must include the @ symbol.'),
    'class' => 'DrupalTextMetaTag',
    'group' => 'twitter-cards',
    'context' => array('global'),
    'element' => array(
      '#theme' => 'metatag_twitter_cards',
    ),
    'devel_generate' => array(
      'type' => 'twitter',
    ),
  );
  $info['tags']['twitter:site:id'] = array(
    'label' => t('Site\'s Twitter account ID'),
    'description' => t('The numerical Twitter account ID for the website, which will be displayed in the Card\'s footer.'),
    'class' => 'DrupalTextMetaTag',
    'group' => 'twitter-cards',
    'context' => array('global'),
    'element' => array(
      '#theme' => 'metatag_twitter_cards',
    ),
    'devel_generate' => array(
      'type' => 'integer',
    ),
  );
  $info['tags']['twitter:creator'] = array(
    'label' => t('Creator\'s Twitter account'),
    'description' => t('The @username for the content creator / author for this page, including the @ symbol.'),
    'class' => 'DrupalTextMetaTag',
    'group' => 'twitter-cards',
    'element' => array(
      '#theme' => 'metatag_twitter_cards',
    ),
    'devel_generate' => array(
      'type' => 'twitter',
    ),
  );
  $info['tags']['twitter:creator:id'] = array(
    'label' => t('Creator\'s Twitter account ID'),
    'description' => t('The numerical Twitter account ID for the content creator / author for this page.'),
    'class' => 'DrupalTextMetaTag',
    'group' => 'twitter-cards',
    'element' => array(
      '#theme' => 'metatag_twitter_cards',
    ),
    'devel_generate' => array(
      'type' => 'integer',
    ),
  );
  $info['tags']['twitter:url'] = array(
    'label' => t('Page URL'),
    'description' => t('The permalink / canonical URL of the current page.'),
    'class' => 'DrupalTextMetaTag',
    'group' => 'twitter-cards',
    'element' => array(
      '#theme' => 'metatag_twitter_cards',
    ),
    'devel_generate' => array(
      'type' => 'canonical',
    ),
  );
  $info['tags']['twitter:title'] = array(
    'label' => t('Title'),
    'description' => t('The page\'s title, which should be concise; it will be truncated at 70 characters by Twitter. This field is required unless this the \'type\' field is set to "photo".'),
    'class' => 'DrupalTextMetaTag',
    'group' => 'twitter-cards',
    'element' => array(
      '#theme' => 'metatag_twitter_cards',
    ),
  );
  $info['tags']['twitter:description'] = array(
    'label' => t('Description'),
    'description' => t('A description that concisely summarizes the content of the page, as appropriate for presentation within a Tweet. Do not re-use the title text as the description, or use this field to describe the general services provided by the website. The string will be truncated, by Twitter, at the word to 200 characters.'),
    'class' => 'DrupalTextMetaTag',
    'group' => 'twitter-cards',
    'element' => array(
      '#theme' => 'metatag_twitter_cards',
    ),
  );
  $info['tags']['twitter:image'] = array(
    'label' => t('Image URL'),
    'description' => t('The URL to a unique image representing the content of the page. Do not use a generic image such as your website logo, author photo, or other image that spans multiple pages. Images larger than 120x120px will be resized and cropped square based on longest dimension. Images smaller than 60x60px will not be shown. If the \'type\' is set to <em>Photo</em> then the image must be at least 280x150px.'),
    'class' => 'DrupalTextMetaTag',
    'group' => 'twitter-cards',
    'element' => array(
      '#theme' => 'metatag_twitter_cards',
    ),
    'devel_generate' => array(
      'type' => 'image',
    ),
  );
  $info['tags']['twitter:image:width'] = array(
    'label' => t('Image width'),
    'description' => t('The width of the image being linked to, in pixels.'),
    'class' => 'DrupalTextMetaTag',
    'group' => 'twitter-cards',
    'element' => array(
      '#theme' => 'metatag_twitter_cards',
    ),
    'devel_generate' => array(
      'type' => 'integer',
    ),
  );
  $info['tags']['twitter:image:height'] = array(
    'label' => t('Image height'),
    'description' => t('The height of the image being linked to, in pixels.'),
    'class' => 'DrupalTextMetaTag',
    'group' => 'twitter-cards',
    'element' => array(
      '#theme' => 'metatag_twitter_cards',
    ),
    'devel_generate' => array(
      'type' => 'integer',
    ),
  );
  $info['tags']['twitter:image0'] = array(
    'label' => t('1st Gallery Image '),
    'description' => t('A URL to the image representing the first photo in your gallery.'),
    'class' => 'DrupalTextMetaTag',
    'group' => 'twitter-cards',
    'element' => array(
      '#theme' => 'metatag_twitter_cards',
    ),
  );
  $info['tags']['twitter:image1'] = array(
    'label' => t('2nd Gallery Image '),
    'description' => t('A URL to the image representing the second photo in your gallery.'),
    'class' => 'DrupalTextMetaTag',
    'group' => 'twitter-cards',
    'element' => array(
      '#theme' => 'metatag_twitter_cards',
    ),
  );
  $info['tags']['twitter:image2'] = array(
    'label' => t('3rd Gallery Image '),
    'description' => t('A URL to the image representing the third photo in your gallery.'),
    'class' => 'DrupalTextMetaTag',
    'group' => 'twitter-cards',
    'element' => array(
      '#theme' => 'metatag_twitter_cards',
    ),
  );
  $info['tags']['twitter:image3'] = array(
    'label' => t('4th Gallery Image '),
    'description' => t('A URL to the image representing the fourth photo in your gallery.'),
    'class' => 'DrupalTextMetaTag',
    'group' => 'twitter-cards',
    'element' => array(
      '#theme' => 'metatag_twitter_cards',
    ),
  );
  $info['tags']['twitter:player'] = array(
    'label' => t('Media player URL'),
    'description' => t('The full URL for loading a media player. Required when using a <em>Media player</em> card.'),
    'class' => 'DrupalTextMetaTag',
    'group' => 'twitter-cards',
    'element' => array(
      '#theme' => 'metatag_twitter_cards',
    ),
    'devel_generate' => array(
      'type' => 'url',
    ),
  );
  $info['tags']['twitter:player:width'] = array(
    'label' => t('Media player width'),
    'description' => t('The width of the media player iframe, in pixels. Required when using a <em>Media player</em> card.'),
    'class' => 'DrupalTextMetaTag',
    'group' => 'twitter-cards',
    'element' => array(
      '#theme' => 'metatag_twitter_cards',
    ),
    'devel_generate' => array(
      'type' => 'integer',
    ),
  );
  $info['tags']['twitter:player:height'] = array(
    'label' => t('Media player height'),
    'description' => t('The height of the media player iframe, in pixels. Required when using a <em>Media player</em> card.'),
    'class' => 'DrupalTextMetaTag',
    'group' => 'twitter-cards',
    'element' => array(
      '#theme' => 'metatag_twitter_cards',
    ),
    'devel_generate' => array(
      'type' => 'integer',
    ),
  );
  $info['tags']['twitter:player:stream'] = array(
    'label' => t('MP4 media stream URL'),
    'description' => t('The full URL for an MP4 video (h.264) or audio (AAC) stream, takes precidence over the other media player field.'),
    'class' => 'DrupalTextMetaTag',
    'group' => 'twitter-cards',
    'element' => array(
      '#theme' => 'metatag_twitter_cards',
    ),
    'devel_generate' => array(
      'type' => 'url',
    ),
  );
  $info['tags']['twitter:player:stream:content_type'] = array(
    'label' => t('MP4 media stream MIME type'),
    'description' => t('The MIME type for the media contained in the stream URL, as defined by <a href="!url">RFC 4337</a>.', array('!url' => 'http://tools.ietf.org/rfc/rfc4337.txt')),
    'class' => 'DrupalTextMetaTag',
    'group' => 'twitter-cards',
    'element' => array(
      '#theme' => 'metatag_twitter_cards',
    ),
    'devel_generate' => array(
      'maxlength' => 1,
    ),
  );
  $info['tags']['twitter:app:id:iphone'] = array(
    'label' => t('iPhone app ID'),
    'description' => t("String value, should be the numeric representation of your iPhone app's ID in the App Store."),
    'class' => 'DrupalTextMetaTag',
    'group' => 'twitter-cards',
    'element' => array(
      '#theme' => 'metatag_twitter_cards'
    ),
  );
  $info['tags']['twitter:app:id:ipad'] = array(
    'label' => t('iPad app ID'),
    'description' => t("String value, should be the numeric representation of your iPad app's ID in the App Store."),
    'class' => 'DrupalTextMetaTag',
    'group' => 'twitter-cards',
    'element' => array(
      '#theme' => 'metatag_twitter_cards'
    ),
  );
  $info['tags']['twitter:app:id:googleplay'] = array(
    'label' => t('Google Play app ID'),
    'description' => t("String value, and should be the numeric representation of your app's ID in Google Play."),
    'class' => 'DrupalTextMetaTag',
    'group' => 'twitter-cards',
    'element' => array(
      '#theme' => 'metatag_twitter_cards'
    ),
  );
  $info['tags']['twitter:app:url:iphone'] = array(
    'label' => t('iPhone app\'s custom URL scheme'),
    'description' => t('Your iPhone app\'s custom URL scheme (you must include "://" after your scheme name).'),
    'class' => 'DrupalTextMetaTag',
    'group' => 'twitter-cards',
    'element' => array(
      '#theme' => 'metatag_twitter_cards'
    ),
  );
  $info['tags']['twitter:app:url:ipad'] = array(
    'label' => t('iPad app\'s custom URL scheme'),
    'description' => t('Your iPad app\'s custom URL scheme (you must include "://" after your scheme name).'),
    'class' => 'DrupalTextMetaTag',
    'group' => 'twitter-cards',
    'element' => array(
      '#theme' => 'metatag_twitter_cards'
    ),
  );
  $info['tags']['twitter:app:country'] = array(
    'label' => t('App Store Country'),
    'description' => t('If your application is not available in the US App Store, you must set this value to the two-letter country code for the App Store that contains your application.'),
    'class' => 'DrupalTextMetaTag',
    'group' => 'twitter-cards',
    'element' => array(
      '#theme' => 'metatag_twitter_cards'
    ),
  );
  $info['tags']['twitter:app:url:googleplay'] = array(
    'label' => t('Google Play\'s URL scheme'),
    'description' => t('Your app\'s custom URL scheme.'),
    'class' => 'DrupalTextMetaTag',
    'group' => 'twitter-cards',
    'element' => array(
      '#theme' => 'metatag_twitter_cards'
    ),
  );
  $info['tags']['twitter:label1'] = array(
    'label' => t('Label 1'),
    'description' => t('This field expects a string, and you can specify values for labels such as price, items in stock, sizes, etc.'),
    'class' => 'DrupalTextMetaTag',
    'group' => 'twitter-cards',
    'element' => array(
      '#theme' => 'metatag_twitter_cards'
    ),
  );
  $info['tags']['twitter:data1'] = array(
    'label' => t('Data 1'),
    'description' => t('This field expects a string, and allows you to specify the types of data you want to offer (price, country, etc.).'),
    'class' => 'DrupalTextMetaTag',
    'group' => 'twitter-cards',
    'element' => array(
      '#theme' => 'metatag_twitter_cards'
    ),
  );
  $info['tags']['twitter:label2'] = array(
    'label' => t('Label 2'),
    'description' => t('This field expects a string, and you can specify values for labels such as price, items in stock, sizes, etc.'),
    'class' => 'DrupalTextMetaTag',
    'group' => 'twitter-cards',
    'element' => array(
      '#theme' => 'metatag_twitter_cards'
    ),
  );
  $info['tags']['twitter:data2'] = array(
    'label' => t('Data 2'),
    'description' => t('This field expects a string, and allows you to specify the types of data you want to offer (price, country, etc.).'),
    'class' => 'DrupalTextMetaTag',
    'group' => 'twitter-cards',
    'element' => array(
      '#theme' => 'metatag_twitter_cards'
    ),
  );

  return $info;
}
