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

This version of the module only works with Drupal 7.x.


Features
------------------------------------------------------------------------------
The primary features include:

* The current supported basic meta tags are ABSTRACT, DESCRIPTION, CANONICAL,
  COPYRIGHT, GENERATOR, IMAGE_SRC, KEYWORDS, PUBLISHER, ROBOTS, SHORTLINK and
  the page's TITLE tag.

* Multi-lingual support using the Entity Translation module.

* Per-path control over meta tags using the "Meta tags: Context" submodule
  (requires the Context module).

* The fifteen Dublin Core Basic Element Set 1.1 meta tags may be added by
  enabling the "Meta tags: Dublin Core" submodule.

* The Open Graph Protocol meta tags, as used by Facebook, may be added by
  enabling the "Meta tags: Open Graph" submodule.

* The Twitter Cards meta tags may be added by enabling the "Meta tags: Twitter
  Cards" submodule.

* An API allowing for additional meta tags to be added, beyond what is provided
  by this module - see metatag.api.php for full details.


Configuration
------------------------------------------------------------------------------
 1. On the People Permissions administration page ("Administer >> People
    >> Permissions") you need to assign:

    - The "Administer meta tags" permission to the roles that are allowed to
      access the meta tags admin pages to control the site defaults.

    - The "Edit meta tags" permission to the roles that are allowed to change
      meta tags on each individual page (node, term, etc).

 2. The main admininistrative page controls the site-wide defaults, both global
    settings and defaults per entity (node, term, etc), in addition to those
    assigned specifically for the front page:
      admin/config/search/metatags

 3. Each supported entity object (nodes, terms, users) will have a set of meta
    tag fields available for customization on their respective edit page, these
    will inherit their values from the defaults assigned in #2 above. Any
    values that are not overridden per object will automatically update should
    the defaults be updated.


Developers
------------------------------------------------------------------------------
Full API documentation is available in metatag.api.php.

To enable Metatag support in custom entities, add 'metatag' => TRUE to either
the entity or bundle definition in hook_entity_info(); see metatag.api.php for
further details and example code.


Known Issues
------------------------------------------------------------------------------
* Versions of Drupal older than v7.17 were missing necessary functionality for
  taxonomy term pages to work correctly.
* Using Metatag with values assigned for the page title and the Page Title
  module simultaneously can cause conflicts and unexpected results.
* Using the Exclude Node Title module will cause the [node:title] token to be
  empty on node pages, so using [current-page:title] will work around the
  issue. Note: it isn't possible to "fix" this as it's a by-product of what
  Exclude Node Title does - it removes the node title from display.


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


Credits / Contact
------------------------------------------------------------------------------
Currently maintained by Dave Reid [1] and Damien McKenna [2].

All initial development was sponsored by Acquia [3] and Palantir [4];
continued development sponsored by Palantir and Mediacurrent [5].

The best way to contact the authors is to submit an issue, be it a support
request, a feature request or a bug report, in the project issue queue:
  http://drupal.org/project/issues/metatag


References
------------------------------------------------------------------------------
1: http://drupal.org/user/53892
2: http://drupal.org/user/108450
3: http://www.acquia.com/
4: http://www.palantir.net/
5: http://www.mediacurrent.com/
