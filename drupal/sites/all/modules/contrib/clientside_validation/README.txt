DESCRIPTION
===========
  This module adds clientside validation for all forms and webforms using
  jquery.validate[1]. The included jquery.validate.js file is patched because we
  needed to be able to hide empty messages.

EXAMPLE
=======
  If you want to try out an example of Clientside Validation in combination with
  the form API, FAPI Validation (http://www.drupal.org/project/fapi_validation),
  and/or Vertical Tabs (D6: http://www.drupal.org/project/vertical_tabs, D7: in
  core) you can download and enable the example module from this sandbox project:
  http://drupal.org/sandbox/jelles/1193994
  or
  http://drupal.org/project/1193994/git-instructions (direct link to git
  instructions tab)

DEMO
====
  Demo's can be a little bit outdated
  Drupal 6:
    * Custom form: http://atix.be/cv6a
    * Webform: http://atix.be/cv6b
  Drupal 7:
    * Custom form: http://atix.be/cv7a
    * Webform: http://atix.be/cv7b

STATUS
======
  * Validation is added to all forms and webforms (only tested with version 3).
  * The error messages are displayed the same way as without this module, in a
    div above the form.
  * The error messages use the same css classes as drupal does out of the box,
    so you only have to theme it once.
  * Supports the following conditions: Fields that
      - are required
      - have a maximum length
      - must have one of specified extensions
      - must be one of the allowed values
      - can only contain max x elements (checkboxes, multiple selects)
      - must contain minimum x elements (checkboxes, multiple selects)
      - must be greater than a minimum value
      - must be smaller than a maximum value
      - must be a number
      - must be a decimal
      - must equal an other field
      - can not equal an other field
      - must equal a specific value
      - must be an ean number
      - must match a POSIX regex
      - must match a PCRE regex
      - must be a valid e-mail address
      - must be a valid url
      - must be alpha (FAPI validation)
      - must be alphanumeric (FAPI validation)
      - must be valid IPv4 (FAPI validation)
      - must be "alpha dash" (FAPI validation)
    Note: The FAPI validation rules come down to matching a PCRE regex
  * CCK: textfield, textarea, decimal, float, integer, file and image
  * Supports multiple forms on one page
  * Added support for Webform Validation
  * Added support for FAPI Validation
  * D7: Added support for Field Validation
  * Added support for Vertical Tabs (for D6: Vertical Tabs)
  * Supports most of CCK Date
  * Added an option to enclose the field name in quotes (defaults to nothing)
  * Added an option to validate all tabs or only the visible one (defaults to
    all tabs)
  * Added an option to specify on which forms to validate all fields (including
    those hidden) and on which forms only to validate the visible fields
    (defaults to only visible)
  * Added an option to specify on which forms to add Clientside Validation
    (defaults to all forms)
  * Added an option to specify whether or not to use the minified version of
    jquery.validate.js
  * Checkboxes are working
  * Now using jquery.validate 1.8
  * Supports multi page webforms

TODO
====
  * Add settings to control position and behaviour of the error messages

USAGE
=====
  The only thing this module will do is translate validation rules defined in
  PHP to javascript counter parts, if you mark a field as required it will
  create a javascript rule that checks the field on submit. This means no real
  configuration is needed. You can however configure the prefix and suffix used
  for the field names in the error messages (e.g.: prefix:", suffix:" or
  prefix:<<, suffix:>>), whether or not to use the minified version of
  jquery.validate.js, whether or not to validate hidden fields on specific
  forms, whether or not to validate all vertical tabs or only the visible one
  and to add Clientside Validation to all forms or only to those specified.

AUTHOR
======
  The author can be contacted for paid customizations of this module as well as
  Drupal consulting and development.DESCRIPTION
===========
  This module adds clientside validation for all forms and webforms using
  jquery.validate[1]. The included jquery.validate.js file is patched because we
  needed to be able to hide empty messages.

EXAMPLE
=======
  If you want to try out an example of Clientside Validation in combination with
  the form API, FAPI Validation (http://www.drupal.org/project/fapi_validation),
  and/or Vertical Tabs (D6: http://www.drupal.org/project/vertical_tabs, D7: in
  core) you can download and enable the example module from this sandbox project:
  http://drupal.org/sandbox/jelles/1193994
  or
  http://drupal.org/project/1193994/git-instructions (direct link to git
  instructions tab)

DEMO
====
  Demo's can be a little bit outdated
  Drupal 6:
    * Custom form: http://atix.be/cv6a
    * Webform: http://atix.be/cv6b
  Drupal 7:
    * Custom form: http://atix.be/cv7a
    * Webform: http://atix.be/cv7b

STATUS
======
  * Validation is added to all forms and webforms (only tested with version 3).
  * The error messages are displayed the same way as without this module, in a
    div above the form.
  * The error messages use the same css classes as drupal does out of the box,
    so you only have to theme it once.
  * Supports the following conditions: Fields that
      - are required
      - have a maximum length
      - must have one of specified extensions
      - must be one of the allowed values
      - can only contain max x elements (checkboxes, multiple selects)
      - must contain minimum x elements (checkboxes, multiple selects)
      - must be greater than a minimum value
      - must be smaller than a maximum value
      - must be a number
      - must be a decimal
      - must equal an other field
      - can not equal an other field
      - must equal a specific value
      - must be an ean number
      - must match a POSIX regex
      - must match a PCRE regex
      - must be a valid e-mail address
      - must be a valid url
      - must be alpha (FAPI validation)
      - must be alphanumeric (FAPI validation)
      - must be valid IPv4 (FAPI validation)
      - must be "alpha dash" (FAPI validation)
    Note: The FAPI validation rules come down to matching a PCRE regex
  * CCK: textfield, textarea, decimal, float, integer, file and image
  * Supports multiple forms on one page
  * Added support for Webform Validation
  * Added support for FAPI Validation
  * D7: Added support for Field Validation
  * Added support for Vertical Tabs (for D6: Vertical Tabs)
  * Supports most of CCK Date
  * Added an option to enclose the field name in quotes (defaults to nothing)
  * Added an option to validate all tabs or only the visible one (defaults to
    all tabs)
  * Added an option to specify on which forms to validate all fields (including
    those hidden) and on which forms only to validate the visible fields
    (defaults to only visible)
  * Added an option to specify on which forms to add Clientside Validation
    (defaults to all forms)
  * Added an option to specify whether or not to use the minified version of
    jquery.validate.js (defaults to not)
  * Checkboxes are working
  * Now using jquery.validate 1.8
  * Supports multi page webforms

TODO
====
  * Add settings to control position and behaviour of the error messages

USAGE
=====
  The only thing this module will do is translate validation rules defined in
  PHP to javascript counter parts, if you mark a field as required it will
  create a javascript rule that checks the field on submit. This means no real
  configuration is needed. You can however configure the prefix and suffix used
  for the field names in the error messages (e.g.: prefix:", suffix:" or
  prefix:<<, suffix:>>), whether or not to use the minified version of
  jquery.validate.js, whether or not to validate hidden fields on specific
  forms, whether or not to validate all vertical tabs or only the visible one
  and to add Clientside Validation to all forms or only to those specified.

AUTHOR
======
  The author can be contacted for paid customizations of this module as well as
  Drupal consulting and development.