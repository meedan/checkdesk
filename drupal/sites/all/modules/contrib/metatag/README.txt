Metatag
-------
This module allows you to automatically provide structured metadata, aka "meta
tags", about your website and web pages.

In the context of search engine optimization, providing an extensive set of
meta tags may help improve your site's & pages' ranking, thus may aid with
achieving a more prominent display of your content within search engine
results. Additionally, using meta tags can help control the summary content
that is used within social networks when visitors link to your site,
particularly the Open Graph submodule for use with Facebook (see below).

This version of the module only works with Drupal 7.15 and newer.


Features
------------------------------------------------------------------------------
The primary features include:

* The current supported basic meta tags are ABSTRACT, DESCRIPTION, CANONICAL,
  COPYRIGHT, GENERATOR, IMAGE_SRC, KEYWORDS, PUBLISHER, REVISIT-AFTER, ROBOTS,
  SHORTLINK and the page's TITLE tag.

* Multi-lingual support using the Entity Translation module.

* Translation support using the Internationalization (i18n) module.

* Full support for entity revisions and workflows based upon revision editing,
  e.g., Revisioning module.

* Per-path control over meta tags using the "Metatag: Context" submodule
  (requires the Context module).

* Integration with the Views module allowing meta tags to be controlled for
  individual Views pages, with each display in the view able to have different
  meta tags, by using the "Metatag: Views" submodule.

* Integration with the Panels module allowing meta tags to be controlled for
  individual Panels pages, by using the "Metatag: Panels" submodule.

* The fifteen Dublin Core Basic Element Set 1.1 meta tags may be added by
  enabling the "Metatag: Dublin Core" submodule.

* The Open Graph Protocol meta tags, as used by Facebook, may be added by
  enabling the "Metatag: Open Graph" submodule.

* The Twitter Cards meta tags may be added by enabling the "Metatag: Twitter
  Cards" submodule.

* An API allowing for additional meta tags to be added, beyond what is provided
  by this module - see metatag.api.php for full details.

* Support for the Migrate module for migrating data from another system - see
  metatag.migrate.inc for full details.

* Support for the Feeds module for importing data from external data sources or
  file uploads.

* Integrates with Devel_Generate, part of the Devel module, to automatically
  generate meta tags for generated nodes, via the Metatag:Devel submodule.

* Integrates with Workbench Moderation v1 allowing meta tags on nodes to be
  managed through the workflow process.


Configuration
------------------------------------------------------------------------------
 1. On the People Permissions administration page ("Administer >> People
    >> Permissions") you need to assign:

    - The "Administer meta tags" permission to the roles that are allowed to
      access the meta tags admin pages to control the site defaults.

    - The "Edit meta tags" permission to the roles that are allowed to change
      meta tags on each individual page (node, term, etc).

 2. The main administrative page controls the site-wide defaults, both global
    settings and defaults per entity (node, term, etc), in addition to those
    assigned specifically for the front page:
      admin/config/search/metatags

 3. Each supported entity object (nodes, terms, users) will have a set of meta
    tag fields available for customization on their respective edit page, these
    will inherit their values from the defaults assigned in #2 above. Any
    values that are not overridden per object will automatically update should
    the defaults be updated.

 4. As the meta tags are output using Tokens, it may be necessary to customize
    the token display for the site's entities (content types, vocabularies,
    etc). To do this go to e.g., admin/structure/types/manage/article/display,
    in the "Custom Display Settings" section ensure that "Tokens" is checked
    (save the form if necessary), then to customize the tokens go to:
    admin/structure/types/manage/article/display/token


Internationalization: i18n.module
------------------------------------------------------------------------------
All default configurations may be translated using the Internationalization
(i18n) module. The custom strings that are assigned to e.g., the "Global: Front
page" configuration will show up in the Translate Interface admin page
(admin/config/regional/translate/translate) and may be customized per language.


Fine Tuning
------------------------------------------------------------------------------
* By default Metatag will load the global default values for all pages that do
  not have meta tags assigned via the normal entity display or via Metatag
  Context. This may be disabled by setting the variable 'metatag_load_all_pages'
  to FALSE through one of the following methods:
  * Use Drush to set the value:
    drush vset metatag_load_all_pages FALSE
  * Hardcode the value in the site's settings.php file:
    $conf['metatag_load_all_pages'] = FALSE;
  To re-enable this option simply set the value to TRUE.
* By default users will be able to edit meta tags on forms based on the 'Edit
  meta tags' permission. The 'metatag_extended_permissions' variable may be set
  to TRUE to give each individual meta tag a separate permission. This allows
  fine-tuning of the site's editorial control, and for rarely-used fields to be
  hidden from most users. Note: The 'Edit meta tags' permission is still
  required otherwise none of the meta tag fields will display at all. The
  functionality may be disabled again by either removing the variable or
  setting it to FALSE.
* It's possible to disable Metatag integration for certain entity types or
  bundles using variables. To disable an entity just assigning a variable
  'metatag_enable_{$entity_type}' or 'metatag_enable_{$entity_type}__{$bundle}'
  the value FALSE, e.g.:
    // Disable metatags for file_entity.
    $conf['metatag_enable_file'] = FALSE;
    // Disable metatags for carousel nodes.
    $conf['metatag_enable_node__carousel'] = FALSE;
  To enable the entity and/or bundle simply set the value to TRUE or remove the
  settings.php line. Note that the Metatag cache will need to be cleared after
  changing these settings, specifically the 'info' records, e.g., 'info:en'; a
  quick version of doing this is to clear the site caches using either Drush,
  Admin Menu (flush all caches), or the "Clear all caches" button on
  admin/config/development/performance.
* By default Metatag will not display meta tags on admin pages. To enable meta
  tags on admin pages simply set the 'metatag_load_all_pages' variable to TRUE
  through one of the following methods:
  * Use Drush to set the value:
    drush vset metatag_load_all_pages TRUE
  * Hardcode the value in the site's settings.php file:
    $conf['metatag_load_all_pages'] = TRUE;
  To re-enable this option simply set the value to FALSE or delete the
  settings.php line.


Developers
------------------------------------------------------------------------------
Full API documentation is available in metatag.api.php.

To enable Metatag support in custom entities, add 'metatag' => TRUE to either
the entity or bundle definition in hook_entity_info(); see metatag.api.php for
further details and example code.


Troubleshooting / Known Issues
------------------------------------------------------------------------------
* When using custom page template files, e.g., page--front.tpl.php, it is
  important to ensure that the following code is present in the template file:
    <?php render($page['content']); ?>
  or
    <?php render($page['content']['metatags']); ?>
  Without one of these being present the meta tags will not be displayed.
* Versions of Drupal older than v7.17 were missing necessary functionality for
  taxonomy term pages to work correctly.
* Using Metatag with values assigned for the page title and the Page Title
  module simultaneously can cause conflicts and unexpected results.
* Using the Exclude Node Title module will cause the [node:title] token to be
  empty on node pages, so using [current-page:title] will work around the
  issue. Note: it isn't possible to "fix" this as it's a by-product of what
  Exclude Node Title does - it removes the node title from display.
* When customizing the meta tags for user pages, it is strongly recommended to
  not use the [current-user] tokens, these pertain to the person *viewing* the
  page and not e.g., the person who authored a page.
* If images being displayed in image tags need to be resized to fit a specific
  requirements, use the Imagecache Token module to customize the value.
* Certain browser plugins, e.g., on Chrome, can cause the page title to be
  displayed with additional double quotes, e.g., instead of:
    <title>The page title | My cool site</title>
  it will show:
    <title>"The page title | My cool site"</title>
  The solution is to remove the browser plugin - the page's actual output is not
  affected, it is just a problem in the browser.
* The core RDF module is known to cause validation problems for Open Graph meta
  tags output by the Metatag:OpenGraph module. Unless it is actually needed for
  the site, it may be worthwhile to disable the RDF module to avoid any
  possible problems for the Open Graph integration.


Related modules
------------------------------------------------------------------------------
Some modules are available that extend Metatag with additional functionality:

* Domain Meta Tags
  http://drupal.org/project/domain_meta
  Integrates with the Domain Access module, so each site of a multi-domain
  install can separately control their meta tags.

* Select or Other
  http://drupal.org/project/select_or_other
  Enhances the user experience of the metatag_opengraph submodule by allowing
  the creation of custom Open Graph types.

* Imagecache Token
  http://drupal.org/project/imagecache_token
  Provide tokens to load fields using an image style preset, for when meta tags
  need to fix exact requirements.

* Node Form Panes
  https://drupal.org/project/node_form_panes
  Create custom node-edit forms and control the location of the Metatag fields.

* Textimage
  https://drupal.org/project/textimage
  Supports using Textimage's custom tokens in meta tag fields.


Credits / Contact
------------------------------------------------------------------------------
Currently maintained by Damien McKenna [1] and Dave Reid [2]; all initial
development was by Dave Reid.

Ongoing development is sponsored by Mediacurrent [3] and Palantir.net [4]. All
initial development was sponsored by Acquia [5] and Palantir.net.

The best way to contact the authors is to submit an issue, be it a support
request, a feature request or a bug report, in the project issue queue:
  http://drupal.org/project/issues/metatag


References
------------------------------------------------------------------------------
1: http://drupal.org/user/108450
2: http://drupal.org/user/53892
3: http://www.mediacurrent.com/
4: http://www.palantir.net/
5: http://www.acquia.com/
