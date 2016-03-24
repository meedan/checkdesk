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
  $items['checkdesk_reports_feature_comment_footnote_on_a_source'] = entity_import('rules_config', '{ "checkdesk_reports_feature_comment_footnote_on_a_source" : {
      "LABEL" : "Comment (footnote) on a source",
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
        { "heartbeat_activity_checkdesk_comment_on_source" : {
            "nid" : [ "comment:node:nid" ],
            "uid" : [ "comment:author:uid" ],
            "nid_target" : "0",
            "uid_target" : "0",
            "cid" : [ "comment:cid" ],
            "message_id" : { "value" : { "checkdesk_comment_on_source" : "checkdesk_comment_on_source" } },
            "!user_url" : [ "comment:author:url" ],
            "!username" : [ "comment:author:name" ],
            "!source_url" : [ "comment:node:url" ]
          }
        }
      ]
    }
  }');
  return $items;
}
