
Node export README

CONTENTS OF THIS FILE
----------------------

  * Introduction
  * Installation
  * Configuration
  * Usage
  * Node export features tips


INTRODUCTION
------------
This module allows users to export nodes and then import it into another
Drupal installation, or on the same site.

This module allows user to export/import nodes if they have the 'export nodes'
or 'export own nodes' permission, have node access to view the node and create
the node type, and the node type is not omitted in node export's settings. The
module does not check access to the filter formats used by the node's fields,
please keep this in mind when assigning permissions to user roles.

Maintainer: Daniel Braksator (http://drupal.org/user/134005)
Project page: http://drupal.org/project/node_export.

Note: this module was originally built upon code from the node_clone module
maintained by Peter Wolanin (http://drupal.org/user/49851) at 
http://drupal.org/project/node_clone which was derived from code posted by
Steve Ringwood (http://drupal.org/user/12856) at 
http://drupal.org/node/73381#comment-137714
Features integration, relations, and UUID initially developed by Tushar Mahajan
(http://drupal.org/user/398572).
Significant improvements, file handling, and extra functionality pioneered by 
James Andres (http://drupal.org/user/33827).


INSTALLATION
------------
1. Copy node_export folder to modules directory (usually sites/all/modules).
2. At admin/build/modules enable the Node export module in the Node export 
   package.
3. Enable any other modules in the Node export package that tickle your fancy.


CONFIGURATION
-------------
1. Enable permissions at admin/user/permissions.
   Security Warning: Users with the permission "use PHP to import nodes"
   will be able to change nodes as they see fit before an import, as well as 
   being able to execute PHP scripts on the server.  It is advisable not to
   give this permission to a typical node author, only the administrator or
   developer should use this feature.  You may even like to turn this module
   off when it is no longer required.
   This module does not check access to the filter formats used by the node's
   fields, please keep this in mind when assigning permissions to user roles.
2. Configure module at admin/settings/node_export.


USAGE
-----
1. To export nodes, either:
   a) Use the 'Node export' tab on a node page.
   b) Use the Content page (admin/content/node) to filter the nodes you wish to
      export and then choose 'Node export' under the 'Update options'.
   c) Use Drush: http://drupal.org/project/drush
2. To import nodes, either:
   a) Use the form at 'Node export: import' under 'Add content'
      (node/add/node_export).
   b) Use Drush: http://drupal.org/project/drush


NODE EXPORT FEATURES TIPS
-------------------------
Regarding the module node_export_features which integrates with the features
module, any nodes to be used with this must have a UUID (universally unique 
ID).  To export older nodes that don't have UUID make sure you have selected
the content type and click on 'create missings uuids' from 
'admin/settings/uuid' under the fieldset 'Synchronize'.  Then you should be 
able to see more nodes under the feature component, If you don't see the node
export component, that means no nodes has been configured with UUID.
UUID likely to become a consistent requirement across the node export
package.