
CONTENTS OF THIS FILE
---------------------

 * Introduction
 * Installation
 * Configuration
 * E-mail templates
 * Multilangual sites
 * Known issues
 * Password reset support
 * Resend confirmation mail
 * De-installation
 * Upgrade notes


INTRODUCTION
------------

User Registration Password let's users register with a password
on the registration form when 'Require e-mail verification when
a visitor creates an account' is enabled on the configuration page.

By default, users can create accounts directly on the registration form, set
their password and be immediately logged in, or they can create their account,
wait for a verification e-mail, and then create their password.

With this module, users are able to create their account along with their
password and simply activate their account when receiving the verification
e-mail by clicking on the activation link provided via this e-mail.

User Registration Password transforms the checkbox on the
admin/config/people/accounts page into a radio list with 3 options.

The first 2 are default Drupal behaviour:
0 Do not require a verification e-mail, and let users set their password on the registration form.
0 Require a verification e-mail, but wait for the approval e-mail to let users set their password.

The newly added option is:
X Require a verification e-mail, but let users set their password directly on the registration form.

The first 2 disable User Registration Password, only the 3rd option activates
the behaviour offered by this module.


INSTALLATION
------------

Installation is like any other module, just place the files in the
sites/all/modules directory and enable the module on the modules page.


CONFIGURATION
-------------

From the 7.x-1.3 release and higher the module sets the correct
configuration settings on install, including the correct account
activation e-mail template. But if you want to change something, these
steps describe how to configure the module in more detail.

On the admin/config/people/accounts page make sure you have selected:

Who can register accounts?
0 Administrators only
X Visitors
0 Visitors, but administrator approval is required

Then select 'Require a verification e-mail, but let users set their password directly on the registration form.' at:

Require e-mail verification when a visitor creates an account
0 Do not require a verification e-mail, and let users set their password on the registration form.
0 Require a verification e-mail, but wait for the approval e-mail to let users set their password.
X Require a verification e-mail, but let users set their password directly on the registration form.

The module is now configured and ready for use. This is also the only way to
configure it correctly. This module will also not work if you do not have
'Visitors' selected at 'Who can register accounts?' on the same page.


E-MAIL TEMPLATES
----------------

Regarding e-mail templates:

You do not have to alter any e-mail templates, User Registration Password
overrides the default 'Account activation' e-mail template from version
7.x-1.3 and from 6.x-1.0 (and higher) during installation. So there is no
need to change anything anymore on a fresh installation.

If you have previously modified the account activation e-mail template
before you installed this module and discovered that it overrides the
default Account activation e-mail template, no worries! The installer saves
your changes to the template to a temporally variable and revives them when
you disable AND uninstall User Registration Password. Your modifications are
revived and you can now copy paste them to a text file and re-install
User Registration Password again and make the changes to the 'account
activation' e-mail template based on your previous version.


MULTILANGUAL SITES
------------------

For multilangual sites: i18n / variables are supported for the e-mail template.
Be sure to enable them at the admin/config/regional/i18n/variable page and to
translate them via the admin/config/regional/translate page.

Ones configured correctly, users will receive an e-mail in their default
language, setting available on user's edit page. It does not matter what the
site language is, this setting will be leading and supercede the site's default
language. So it is logical and corrent that if you have an German based site
with, let's say German and English languages enabled, and German is also the
site's default language, still when users have English as their default browser
language, they will receive an English e-mail.


KNOWN ISSUES
------------

None yet that we didn't solve.

If you run into problems, like access denied or other (possibly) cache-related
issues, or if you have enabled the module via drush, remember to clear
the site cache via the admin/config/development/performance page.

If this does not help, first try on IRC if anyone can help you, if you still
are not able to get it to work, open a new issue with a descent title and
description of the problem here:
http://drupal.org/node/add/project-issue/user_registrationpassword


PASSWORD RESET SUPPORT
----------------------

Password reset support includes 2 goals:
- Provide a privacy-save form.
- Limit floods.

This is currently not fixed in core, so we implemented it as a temporary fix.

The flood_control module can be used to tweak settings.


RESEND CONFIRMATION MAIL
------------------------

We have implemented a new action via hook_user_operations()
called: 'resend confirmation mail'. This enabled administrators
to re-send confirmation e-mails to users from the admin users page.


DE-INSTALLATION
---------------

If you want to disable the module temporally, just select the first or second
option on the the admin/config/people/accounts page at:

Require e-mail verification when a visitor creates an account
1 Do not require a verification e-mail, and let users set their password on the registration form.
2 Require a verification e-mail, but wait for the approval e-mail to let users set their password.
3 Require a verification e-mail, but let users set their password directly on the registration form.

This disables the User Registration Password functionality without
disabling / uninstalling it.

If you want to remove the module, just disable and uninstall it as you do
for any other module via the admin/modules page.


UPGRADE NOTES
-------------

1.3 - 1.4

You need to run update.php to fix the variable name we changed.
Visit admin/reports/status and click on the update database link
or update.php direct from your browser.

1.0 - 1.3

In earlier versions, this module did not override the default 'Account
activation' e-mail template. To prevent questions and keep in line with the
level of information we would like to offer with this module, we provide the
default e-mail template this module will use to override the 'Account
activation' e-mail template. When you update from 1.0/1.1/1.2 to 1.3, this
template is not activated when you run the updater. You have to change this
manually, just like before version 1.3, so most of you already know this.
From versions 6.x-1.0 and 7.x-1.3 and up, the installer overrides the default
'Account activation' e-mail template, so we only list it here as extra information.

Modified 'Account activation' e-mail template for User Registration password:
--------------------------------------------------------------------------------

[user:name],

Your account at [site:name] has been activated.

You will be able to log in to [site:login-url] in the future using:

username: [user:name]
password: your password.

-- [site:name] team

--------------------------------------------------------------------------------

You can edit the 'Account activation' e-mail template at the
admin/config/people/accounts page.
