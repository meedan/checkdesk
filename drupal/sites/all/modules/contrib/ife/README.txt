Description:
-----------

IFE or Inline Form Errors allows you to place form submission error inline with the form elements. Three options are provided for setting your inline error behaviour. You can configure the default behaviour or override the behaviour on a per form basis.

Install instructions:
--------------------

Install as usual, http://drupal.org/node/70151

1. Copy the entire ife directory the Drupal modules directory.

2. Login as administrator. Enable the module in the "administer" -> "build" -> "modules"

3. (Required) Edit the settings under "administer" -> "settings" -> "Inline Form Errors" (admin/settings/ife)

Usage:
-----

On the settings page (see step 3 above) you can configure which forms are enabled with inline form errors. In Drupal, every form has a unique ID. This ID must be used to target a form. You can enter a new form id at the bottom of the settings page. By default all the forms will have a general error message and general display setting.

FAQ:
---

Q: How can I retrieve the unique form ID from a specific form?
A: You can switch on the 'Show form_ids on form' option at the settings page. Only users with the permission 'administer inline form errors' will see an indication above all the forms with the unique form ID.

Q: Which types of error behaviours are supported?
A: IFE provides three 'display types' for the configured forms:

1. Leave the messages in place, this option will copy the error messages and place them inline. The original error messages set by Drupal will remain in place
2. Show an alternative message, this option will replace the original messages with a generic error message such as 'Please correct all errors.'. This message can be set in the IFE configuration page. The original error messages are placed inline with the form elements
3. Remove all messages, this option will remove all error messages and place them inline with the form element


MAINTAINERS:
------------

This module is maintained by stijndm (http://drupal.org/user/201482)
Development is sponsored by nascom.be and villaviscom.be