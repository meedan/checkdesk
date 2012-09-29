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
      "LABEL" : "New story",
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
  $items['rules_new_report'] = entity_import('rules_config', '{ "rules_new_report" : {
      "LABEL" : "New report",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "checkdesk" ],
      "REQUIRES" : [ "rules", "heartbeat_rules" ],
      "ON" : [ "node_insert" ],
      "IF" : [
        { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "media" : "media" } } } }
      ],
      "DO" : [
        { "heartbeat_activity_new_report" : {
            "nid" : [ "node:nid" ],
            "uid" : [ "node:author:uid" ],
            "message_id" : { "value" : { "new_report" : "new_report" } },
            "!title" : [ "node:title" ],
            "!username" : [ "node:author:name" ]
          }
        }
      ]
    }
  }');
  $items['rules_new_report_comment'] = entity_import('rules_config', '{ "rules_new_report_comment" : {
      "LABEL" : "New report comment",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "checkdesk" ],
      "REQUIRES" : [ "rules", "heartbeat_rules", "comment" ],
      "ON" : [ "comment_insert" ],
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "comment:node" ],
            "type" : { "value" : { "media" : "media" } }
          }
        }
      ],
      "DO" : [
        { "heartbeat_activity_new_comment_report" : {
            "nid" : [ "comment:node:nid" ],
            "uid" : [ "comment:author:uid" ],
            "nid_target" : [ "" ],
            "cid" : [ "comment:cid" ],
            "message_id" : { "value" : { "new_comment_report" : "new_comment_report" } },
            "!username" : [ "comment:author:name" ],
            "!comment" : [ "comment:comment-body:value" ]
          }
        }
      ]
    }
  }');
  $items['rules_publish_report'] = entity_import('rules_config', '{ "rules_publish_report" : {
      "LABEL" : "Publish report",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "checkdesk" ],
      "REQUIRES" : [ "rules", "heartbeat_rules" ],
      "ON" : [ "node_insert" ],
      "IF" : [
        { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "post" : "post" } } } }
      ],
      "DO" : [
        { "LOOP" : {
            "USING" : { "list" : [ "node:reports" ] },
            "ITEM" : { "report" : "Report" },
            "DO" : [
              { "heartbeat_activity_publish_report" : {
                  "nid" : [ "report:nid" ],
                  "uid" : [ "node:author:uid" ],
                  "message_id" : { "value" : { "publish_report" : "publish_report" } },
                  "!publisher" : [ "node:author:name" ],
                  "!story" : [ "node:field_desk:title" ]
                }
              }
            ]
          }
        }
      ]
    }
  }');
  $items['rules_status_report'] = entity_import('rules_config', '{ "rules_status_report" : {
      "LABEL" : "Status report",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "checkdesk" ],
      "REQUIRES" : [ "rules", "heartbeat_rules" ],
      "ON" : [ "node_update" ],
      "IF" : [
        { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "media" : "media" } } } },
        { "NOT data_is" : {
            "data" : [ "node:field-rating:tid" ],
            "value" : [ "node-unchanged:field-rating:tid" ]
          }
        }
      ],
      "DO" : [
        { "heartbeat_activity_status_report" : {
            "nid" : [ "node:nid" ],
            "uid" : [ "node:author:uid" ],
            "message_id" : { "value" : { "status_report" : "status_report" } },
            "!status" : [ "node:field-rating:name" ],
            "!editor" : [ "node:author:name" ]
          }
        }
      ]
    }
  }');
  return $items;
}
