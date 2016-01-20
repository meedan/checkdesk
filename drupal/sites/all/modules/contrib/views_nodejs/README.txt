README.txt
____________________


DESCRIPTION
____________________

This module implements dynamically update of views by nodejs after executing rules
action.
This module implements rules action which we can add to any rule for updating
some views (views which need update, one can select in action).
During updating of views all arguments that are already passed to view will be
taken into account.
It is also correctly working with views which use ajax.

Why do you need to use this module?
You need to use this module if you want to update some views for all users who
review these views after some event on the site.

Exemple:
You have some views which show last added nodes. You can create rule on event
"After saving new content" after this you can add action "Views update"(which
implements this module) to this rule and select views which will have to be
updated.


INSTALLATION
____________________

To install this module, do the following:

1. Extract the tar ball that you downloaded from Drupal.org.

2. Upload the views_nodejs directory and all its contents to your modules
   directory.

3. Visit admin/modules and enable the "Views with node.js" module.


CONFIGURATION
____________________

To configure this module do the following:

1. It is necessary to configure correctly Node.js integration module -
   (http://drupal.org/node/1713530).
2. It is necessary to configure correctly Rules module -
   (https://drupal.org/documentation/modules/rules).
2. It is necessary to configure correctly Views module -
   (https://drupal.org/documentation/modules/views).
   
API
____________________

One can use powerful API from the Views, Rules, Node.js modules, and one can
find some hooks in views_nodejs.api.php with description.
