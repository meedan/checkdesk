<?php
/**
 * @file
 * checkdesk_nodejs_features.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function checkdesk_nodejs_features_default_rules_configuration() {
  $items = array();
  $items['rules_update_liveblog'] = entity_import('rules_config', '{ "rules_update_liveblog" : {
      "LABEL" : "Update Liveblog",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "checkdesk" ],
      "REQUIRES" : [ "rules", "views_nodejs" ],
      "ON" : { "node_insert" : [], "node_update" : [] },
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "media" : "media", "discussion" : "discussion", "post" : "post" } }
          }
        }
      ],
      "DO" : [
        { "views_nodejs" : { "views" : { "value" : { "a:2:{s:4:\\u0022name\\u0022;s:8:\\u0022liveblog\\u0022;s:10:\\u0022display_id\\u0022;s:4:\\u0022page\\u0022;}" : "a:2:{s:4:\\u0022name\\u0022;s:8:\\u0022liveblog\\u0022;s:10:\\u0022display_id\\u0022;s:4:\\u0022page\\u0022;}" } } } }
      ]
    }
  }');
  return $items;
}
