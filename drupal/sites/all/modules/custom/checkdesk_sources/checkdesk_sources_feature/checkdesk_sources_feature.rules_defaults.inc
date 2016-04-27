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
  $items['checkdesk_reports_feature_change_source_status'] = entity_import('rules_config', '{ "checkdesk_reports_feature_change_source_status" : {
      "LABEL" : "Change source status",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "checkdesk" ],
      "REQUIRES" : [ "rules", "php", "heartbeat_rules" ],
      "ON" : { "node_update" : [] },
      "IF" : [
        { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "source" : "source" } } } },
        { "php_eval" : { "code" : "if (isset($node-\\u003Efield_source_status[LANGUAGE_NONE][0][\\u0027tid\\u0027])) {\\r\\n  if (!isset($node_unchanged-\\u003Efield_source_status[LANGUAGE_NONE][0][\\u0027tid\\u0027])) {\\r\\n    return TRUE;\\r\\n  }\\r\\n  if ($node_unchanged-\\u003Efield_source_status[LANGUAGE_NONE][0][\\u0027tid\\u0027] != $node-\\u003Efield_source_status[LANGUAGE_NONE][0][\\u0027tid\\u0027]) {\\r\\n    return TRUE;\\r\\n  }\\r\\n}\\r\\nreturn FALSE;" } }
      ],
      "DO" : [
        { "heartbeat_activity_checkdesk_status_source" : {
            "nid" : [ "node:nid" ],
            "uid" : [ "site:current-user:uid" ],
            "message_id" : { "value" : { "checkdesk_status_source" : "checkdesk_status_source" } },
            "!editor_url" : [ "site:current-user:url" ],
            "!editor" : [ "node:author:name" ],
            "!source_url" : [ "node:url" ],
            "!status" : [ "node:field-source-status:name" ]
          }
        }
      ]
    }
  }');
  $items['checkdesk_reports_feature_new_source'] = entity_import('rules_config', '{ "checkdesk_reports_feature_new_source" : {
      "LABEL" : "New source",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "checkdesk" ],
      "REQUIRES" : [ "rules", "heartbeat_rules", "rules_scheduler" ],
      "ON" : { "node_insert" : [] },
      "IF" : [
        { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "source" : "source" } } } }
      ],
      "DO" : [
        { "heartbeat_activity_checkdesk_new_source" : {
            "nid" : [ "node:nid" ],
            "uid" : [ "node:author:uid" ],
            "message_id" : { "value" : { "checkdesk_new_source" : "checkdesk_new_source" } },
            "!user_url" : [ "node:author:url" ],
            "!username" : [ "node:author:name" ],
            "!source_url" : [ "node:url" ]
          }
        },
        { "schedule" : {
            "component" : "checkdesk_reports_feature_notify_subscribed_users_new_source",
            "date" : "now",
            "param_source" : [ "node" ]
          }
        }
      ]
    }
  }');
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
  $items['checkdesk_reports_feature_notify_subscribed_users_new_source'] = entity_import('rules_config', '{ "checkdesk_reports_feature_notify_subscribed_users_new_source" : {
      "LABEL" : "Notify subscribed users: new source",
      "PLUGIN" : "action set",
      "OWNER" : "rules",
      "TAGS" : [ "checkdesk" ],
      "REQUIRES" : [ "php", "rules", "meedan_notifications" ],
      "USES VARIABLES" : { "source" : { "label" : "Source", "type" : "node" } },
      "ACTION SET" : [
        { "notify_subscribers" : {
            "object" : [ "source" ],
            "event" : "email_new_source",
            "subject" : "New source created",
            "message" : "Hello !recipient_name,\\r\\n\\r\\n!author has added a new report !source.\\r\\n\\r\\n\\u003Ca href=\\u0022!url\\u0022\\u003EClick here \\u003C\\/a\\u003E to view this source.\\r\\n",
            "actor" : [ "source:author" ],
            "t_args" : "\\u003C?php\\r\\nreturn serialize(array(\\u0027!author\\u0027 =\\u003E user_load($source-\\u003Euid)-\\u003Ename, \\u0027!url\\u0027 =\\u003E url(\\u0027node\\/\\u0027 . $source-\\u003Enid, array(\\u0027absolute\\u0027 =\\u003E TRUE, \\u0027alias\\u0027 =\\u003E TRUE)), \\u0027!source\\u0027 =\\u003E node_load($source-\\u003Enid)-\\u003Etitle, \\u0027!site\\u0027 =\\u003E variable_get(\\u0027site_name\\u0027, \\u0027Checkdesk\\u0027), \\u0027!recipient_name\\u0027 =\\u003E \\u0027[recipient:name]\\u0027, \\u0027!recipient_url\\u0027 =\\u003E \\u0027[recipient:edit-url]\\u0027)); \\r\\n?\\u003E"
          }
        }
      ]
    }
  }');
  return $items;
}
