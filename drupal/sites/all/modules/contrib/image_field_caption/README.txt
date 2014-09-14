|=====================|
| Image Field Caption |
|=====================|

  Provides a caption text area for image fields.

|==============|
| Installation |
|==============|

  1. Download the module
  2. Upload module to the sites/all/modules folder
  3. Enable the module
  4. Flush all of Drupal's caches

|=======|
| Usage |
|=======|

  1. Add a new image field to a content type, or use an existing image field and
     configure it t o show the caption elements.
  2. Add or edit a node or any other entity with an image field
  3. Go to the image field on the entity form
  4. Enter text into the caption text area and choose format
  5. Save the entity
  6. View the entity to see your image field caption

|===============|
| Configuration |
|===============|

  The configuration is only done on a per field basis.

|===============|
| Caption Theme |
|===============|

  By default, an image field's caption will be rendered below the image. To
  customize the image caption display, copy the image_field_caption.tpl.php file
  to your theme's directory and adjust the html for your needs. Flush Drupal's
  theme registry cache to have it recognize your theme's new file:

  sites/all/themes/MY_THEME/image_field_caption.tpl.php

|=============|
| Caption CSS |
|=============|

  To make changes to the caption css, use this CSS selector:

  blockquote.image-field-caption { /* add custom css here */ }

|==================|
| More Information |
|==================|

  http://www.drupal.org/project/image_field_caption
  http://www.tylerfrankenstein.com/image_field_caption

