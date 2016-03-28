<?php
/**
 * @file
 * checkdesk_sources_feature.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function checkdesk_sources_feature_default_rules_configuration() {
  $items = array();
  $items['checkdesk_reports_feature_new_source_comment'] = entity_import('rules_config', '{ "checkdesk_reports_feature_new_source_comment" : {
      "LABEL" : "New source comment",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "checkdesk" ],
      "REQUIRES" : [ "rules", "heartbeat_rules", "comment" ],
      "ON" : { "comment_insert" : [] },
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "comment:node" ],
            "type" : { "value" : { "source" : "source" } }
          }
        }
      ],
      "DO" : [
        { "heartbeat_activity_new_comment_source" : {
            "nid" : [ "comment:node:nid" ],
            "uid" : [ "comment:author:uid" ],
            "nid_target" : "0",
            "uid_target" : "0",
            "cid" : [ "comment:cid" ],
            "message_id" : { "value" : { "new_comment_source" : "new_comment_source" } },
            "!username" : [ "comment:author:name" ],
            "!comment" : [ "comment:comment-body:value" ]
          }
        }
      ]
    }
  }');
  return $items;
}
