<?php
/**
 * @file
 * checkdesk_core_feature.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function checkdesk_core_feature_default_rules_configuration() {
  $items = array();
  $items['rules_new_discussion'] = entity_import('rules_config', '{ "rules_new_discussion" : {
      "LABEL" : "New Story",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "checkdesk" ],
      "REQUIRES" : [ "rules", "meedan_notifications" ],
      "ON" : [ "node_insert" ],
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "discussion" : "discussion" } }
          }
        }
      ],
      "DO" : [
        { "notify_subscribers" : {
            "object" : [ "node" ],
            "event" : "discussion",
            "subject" : "New story \\u0022[node:title]\\u0022",
            "message" : "Hi [recipient:name],\\r\\n\\r\\n[node:author:name] has created a new story entitled \\u0022[node:title]\\u0022. Join the discussion at [node:url]!\\r\\n\\r\\nBest,\\r\\nCheckdesk Team"
          }
        }
      ]
    }
  }');
  return $items;
}
