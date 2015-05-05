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
  $items['checkdesk_core_feature_new_draft_update'] = entity_import('rules_config', '{ "checkdesk_core_feature_new_draft_update" : {
      "LABEL" : "New draft update",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "checkdesk" ],
      "REQUIRES" : [ "rules", "rules_scheduler" ],
      "ON" : { "node_insert--post" : { "bundle" : "post" } },
      "IF" : [
        { "NOT data_is_empty" : { "data" : [ "node:field_desk" ] } },
        { "NOT node_is_published" : { "node" : [ "node" ] } }
      ],
      "DO" : [
        { "schedule" : {
            "component" : "checkdesk_core_feature_notify_subscribed_users_new_update_draft",
            "date" : "now",
            "param_node" : [ "node" ],
            "param_story" : [ "node:field-desk" ]
          }
        }
      ]
    }
  }');
  $items['checkdesk_core_feature_notify_subscribed_users_new_story'] = entity_import('rules_config', '{ "checkdesk_core_feature_notify_subscribed_users_new_story" : {
      "LABEL" : "Notify subscribed users: new story",
      "PLUGIN" : "action set",
      "OWNER" : "rules",
      "TAGS" : [ "checkdesk" ],
      "REQUIRES" : [ "php", "rules", "meedan_notifications" ],
      "USES VARIABLES" : { "story" : { "label" : "Story", "type" : "node" } },
      "ACTION SET" : [
        { "notify_subscribers" : {
            "object" : [ "story" ],
            "event" : "email_new_story",
            "subject" : "New story created",
            "message" : "Hello !recipient_name,\\r\\n\\r\\n!author has added a new story !story.\\r\\n\\r\\n\\u003Ca href=\\u0022!url\\u0022\\u003EClick here \\u003C\\/a\\u003E to view or update this story.\\r\\n",
            "actor" : [ "story:author" ],
            "t_args" : "\\u003C?php\\r\\nreturn serialize(array(\\u0027!author\\u0027 =\\u003E user_load($story-\\u003Euid)-\\u003Ename, \\u0027!url\\u0027 =\\u003E url(\\u0027node\\/\\u0027 . $story-\\u003Enid, array(\\u0027absolute\\u0027 =\\u003E TRUE, \\u0027alias\\u0027 =\\u003E TRUE)), \\u0027!story\\u0027 =\\u003E node_load($story-\\u003Enid)-\\u003Etitle, \\u0027!site\\u0027 =\\u003E variable_get(\\u0027site_name\\u0027, \\u0027Checkdesk\\u0027), \\u0027!recipient_name\\u0027 =\\u003E \\u0027[recipient:name]\\u0027, \\u0027!recipient_url\\u0027 =\\u003E \\u0027[recipient:edit-url]\\u0027)); \\r\\n?\\u003E"
          }
        }
      ]
    }
  }');
  $items['checkdesk_core_feature_notify_subscribed_users_new_update_draft'] = entity_import('rules_config', '{ "checkdesk_core_feature_notify_subscribed_users_new_update_draft" : {
      "LABEL" : "Notify subscribed users: new update (draft)",
      "PLUGIN" : "action set",
      "OWNER" : "rules",
      "TAGS" : [ "checkdesk" ],
      "REQUIRES" : [ "php", "rules", "meedan_notifications" ],
      "USES VARIABLES" : {
        "node" : { "label" : "Node", "type" : "node" },
        "story" : { "label" : "Story", "type" : "node" }
      },
      "ACTION SET" : [
        { "notify_subscribers" : {
            "object" : [ "node" ],
            "event" : "email_new_update",
            "subject" : "An update has been drafted to a story",
            "message" : "Hello !recipient_name,\\r\\n\\r\\n!author has drafted a \\u003Ca href=\\u0022!url\\u0022\\u003Enew update\\u003C\\/a\\u003E to the story \\u0022!title\\u0022.\\r\\n",
            "actor" : [ "node:author" ],
            "t_args" : "\\u003C?php\\r\\nreturn serialize(array(\\u0027!author\\u0027 =\\u003E user_load($story-\\u003Euid)-\\u003Ename, \\u0027!title\\u0027 =\\u003E $story-\\u003Etitle, \\u0027!url\\u0027 =\\u003E url(\\u0027node\\/\\u0027 . $node-\\u003Enid, array(\\u0027absolute\\u0027 =\\u003E TRUE, \\u0027alias\\u0027 =\\u003E TRUE)), \\u0027!site\\u0027 =\\u003E variable_get(\\u0027site_name\\u0027, \\u0027Checkdesk\\u0027), \\u0027!recipient_name\\u0027 =\\u003E \\u0027[recipient:name]\\u0027, \\u0027!recipient_url\\u0027 =\\u003E \\u0027[recipient:edit-url]\\u0027)); \\r\\n?\\u003E"
          }
        }
      ]
    }
  }');
  $items['checkdesk_core_feature_notify_subscribed_users_update_story'] = entity_import('rules_config', '{ "checkdesk_core_feature_notify_subscribed_users_update_story" : {
      "LABEL" : "Notify subscribed users: update story",
      "PLUGIN" : "action set",
      "OWNER" : "rules",
      "TAGS" : [ "checkdesk" ],
      "REQUIRES" : [ "php", "rules", "meedan_notifications" ],
      "USES VARIABLES" : { "story" : { "label" : "Story", "type" : "node" } },
      "ACTION SET" : [
        { "notify_subscribers" : {
            "object" : [ "story" ],
            "event" : "email_update_story",
            "subject" : "Existing story updated",
            "message" : "Hello !recipient_name,\\r\\n\\r\\n!author has updated the story !story.\\r\\n\\r\\n\\u003Ca href=\\u0022!url\\u0022\\u003EClick here \\u003C\\/a\\u003E to view or update this story.\\r\\n",
            "actor" : [ "story:author" ],
            "t_args" : "\\u003C?php\\r\\nreturn serialize(array(\\u0027!author\\u0027 =\\u003E user_load($story-\\u003Euid)-\\u003Ename, \\u0027!url\\u0027 =\\u003E url(\\u0027node\\/\\u0027 . $story-\\u003Enid, array(\\u0027absolute\\u0027 =\\u003E TRUE, \\u0027alias\\u0027 =\\u003E TRUE)), \\u0027!story\\u0027 =\\u003E node_load($story-\\u003Enid)-\\u003Etitle, \\u0027!site\\u0027 =\\u003E variable_get(\\u0027site_name\\u0027, \\u0027Checkdesk\\u0027), \\u0027!recipient_name\\u0027 =\\u003E \\u0027[recipient:name]\\u0027, \\u0027!recipient_url\\u0027 =\\u003E \\u0027[recipient:edit-url]\\u0027)); \\r\\n?\\u003E"
          }
        }
      ]
    }
  }');
  $items['checkdesk_core_feature_update_an_update'] = entity_import('rules_config', '{ "checkdesk_core_feature_update_an_update" : {
      "LABEL" : "Update an update",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "checkdesk" ],
      "REQUIRES" : [ "rules", "heartbeat_rules", "checkdesk_core", "php" ],
      "ON" : { "node_update--post" : { "bundle" : "post" } },
      "IF" : [
        { "NOT data_is" : {
            "data" : [ "node-unchanged:field-desk:nid" ],
            "value" : [ "node:field-desk:nid" ]
          }
        }
      ],
      "DO" : [
        { "heartbeat_activity_checkdesk_new_update_on_story_i_commented_on_update" : {
            "nid" : [ "node:nid" ],
            "uid" : [ "node:author:uid" ],
            "nid_target" : [ "node:field-desk:nid" ],
            "uid_target" : "0",
            "message_id" : { "value" : { "checkdesk_new_update_on_story_i_commented_on_update" : "checkdesk_new_update_on_story_i_commented_on_update" } },
            "!user_url" : [ "node:author:url" ],
            "!username" : [ "node:author:name" ],
            "!update_url" : [ "node:url" ],
            "!story_url" : [ "node:field-desk:url" ],
            "!story" : [ "node:field-desk:title" ]
          }
        },
        { "checkdesk_core_actions_set_followers" : { "node" : [ "node:field-desk" ] } },
        { "php_eval" : { "code" : "_checkdesk_delete_heartbeat_activity($node_unchanged);" } }
      ]
    }
  }');
  $items['checkdesk_core_feature_update_existing_story'] = entity_import('rules_config', '{ "checkdesk_core_feature_update_existing_story" : {
      "LABEL" : "Update existing story",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "checkdesk" ],
      "REQUIRES" : [ "rules", "heartbeat_rules", "rules_scheduler" ],
      "ON" : { "node_update--discussion" : { "bundle" : "discussion" } },
      "IF" : [ { "node_is_published" : { "node" : [ "node" ] } } ],
      "DO" : [
        { "heartbeat_activity_checkdesk_update_story" : {
            "nid" : [ "node:nid" ],
            "uid" : [ "site:current-user:uid" ],
            "nid_target" : [ "node:nid" ],
            "message_id" : { "value" : { "checkdesk_update_story" : "checkdesk_update_story" } },
            "!user_url" : [ "site:current-user:url" ],
            "!username" : [ "site:current-user:name" ],
            "!story_url" : [ "node:url" ]
          }
        },
        { "schedule" : {
            "component" : "checkdesk_core_feature_notify_subscribed_users_update_story",
            "date" : "now",
            "param_story" : [ "node" ]
          }
        }
      ]
    }
  }');
  $items['rules_comment_deleted'] = entity_import('rules_config', '{ "rules_comment_deleted" : {
      "LABEL" : "Comment deleted",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "checkdesk" ],
      "REQUIRES" : [ "rules", "comment" ],
      "ON" : { "comment_delete" : [] },
      "DO" : [
        { "mail" : {
            "to" : [ "comment:author:mail" ],
            "subject" : "Comment Deleted",
            "message" : "\\u0022[comment:body]\\u0022\\r\\n\\r\\nYour comment was deleted by a moderator for violating terms of service or comment policy.\\r\\nIf you think this decision was an error you can contact us at: [site:mail]\\r\\nNote from moderator:\\r\\n\\r\\nRegards,\\r\\n[site:name]",
            "from" : "[site:mail]",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_comment_footnote_on_a_report'] = entity_import('rules_config', '{ "rules_comment_footnote_on_a_report" : {
      "LABEL" : "Comment (footnote) on a report",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "checkdesk" ],
      "REQUIRES" : [
        "rules",
        "php",
        "heartbeat_rules",
        "rules_scheduler",
        "checkdesk_core",
        "comment"
      ],
      "ON" : { "comment_insert" : [] },
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "comment:node" ],
            "type" : { "value" : { "media" : "media" } }
          }
        }
      ],
      "DO" : [
        { "heartbeat_activity_checkdesk_comment_on_report" : {
            "nid" : [ "comment:node:nid" ],
            "uid" : [ "comment:author:uid" ],
            "nid_target" : "\\u003C?php\\r\\n$node = node_load($comment-\\u003Enid);\\r\\nif (isset($node-\\u003Efield_stories[LANGUAGE_NONE][0][\\u0027target_id\\u0027])) {\\r\\n     echo $node-\\u003Efield_stories[LANGUAGE_NONE][0][\\u0027target_id\\u0027] ;\\r\\n}\\r\\nelse {\\r\\n    echo 0;\\r\\n}\\r\\n?\\u003E",
            "uid_target" : "0",
            "cid" : [ "comment:cid" ],
            "message_id" : { "value" : { "checkdesk_comment_on_report" : "checkdesk_comment_on_report" } },
            "!user_url" : [ "comment:author:url" ],
            "!username" : [ "comment:author:name" ],
            "!report_url" : [ "comment:node:url" ]
          }
        },
        { "schedule" : {
            "component" : "rules_notify_subscribed_users_footnote",
            "date" : "now",
            "param_comment" : [ "comment" ]
          }
        },
        { "checkdesk_core_actions_set_followers" : { "node" : [ "comment:node:field-stories" ] } }
      ]
    }
  }');
  $items['rules_comment_on_an_update'] = entity_import('rules_config', '{ "rules_comment_on_an_update" : {
      "LABEL" : "Comment on an update",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "checkdesk" ],
      "REQUIRES" : [ "rules", "heartbeat_rules", "rules_scheduler", "comment" ],
      "ON" : { "comment_insert" : [] },
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "comment:node" ],
            "type" : { "value" : { "post" : "post" } }
          }
        }
      ],
      "DO" : [
        { "heartbeat_activity_checkdesk_comment_on_update" : {
            "nid" : [ "comment:node:nid" ],
            "uid" : [ "comment:author:uid" ],
            "nid_target" : [ "comment:node:field-desk:nid" ],
            "uid_target" : "0",
            "cid" : [ "comment:cid" ],
            "message_id" : { "value" : { "checkdesk_comment_on_update" : "checkdesk_comment_on_update" } },
            "!user_url" : [ "comment:author:url" ],
            "!username" : [ "comment:author:name" ],
            "!update_url" : [ "comment:node:url" ],
            "!update_title" : [ "comment:node:title" ]
          }
        },
        { "schedule" : {
            "component" : "rules_notify_subscribed_users_comment_on_update",
            "date" : "now",
            "param_comment" : [ "comment" ]
          }
        }
      ]
    }
  }');
  $items['rules_existing_report_suggested_to_a_story'] = entity_import('rules_config', '{ "rules_existing_report_suggested_to_a_story" : {
      "LABEL" : "Existing report suggested to a story",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "checkdesk" ],
      "REQUIRES" : [ "rules", "heartbeat_rules", "rules_scheduler", "checkdesk_core", "php" ],
      "ON" : { "node_update--media" : { "bundle" : "media" } },
      "IF" : [
        { "NOT data_is_empty" : { "data" : [ "node:field-stories:nid" ] } },
        { "NOT data_is" : {
            "data" : [ "node-unchanged:field-stories:nid" ],
            "value" : [ "node:field-stories:nid" ]
          }
        }
      ],
      "DO" : [
        { "heartbeat_activity_checkdesk_report_suggested_to_story" : {
            "nid" : "[node:nid]",
            "uid" : "[site:current-user:uid]",
            "nid_target" : [ "node:field-stories:nid" ],
            "uid_target" : "0",
            "message_id" : { "value" : { "checkdesk_report_suggested_to_story" : "checkdesk_report_suggested_to_story" } },
            "!user_url" : "[site:current-user:url]",
            "!username" : "[site:current-user:name]",
            "!report_url" : "[node:url]",
            "!story_url" : [ "node:field-stories:url" ],
            "!story" : [ "node:field-stories:title" ]
          }
        },
        { "schedule" : {
            "component" : "rules_notify_subscribed_users_existing_report_suggested_to_story",
            "date" : "now",
            "param_node" : [ "node" ],
            "param_list_item" : [ "node:field-stories" ],
            "param_current_user" : [ "site:current-user" ]
          }
        },
        { "checkdesk_core_actions_set_followers" : { "node" : [ "node:field-stories" ] } },
        { "php_eval" : { "code" : "_checkdesk_delete_heartbeat_activity($node_unchanged);" } }
      ]
    }
  }');
  $items['rules_fact_checking_status_changed'] = entity_import('rules_config', '{ "rules_fact_checking_status_changed" : {
      "LABEL" : "Fact-checking status changed",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "checkdesk" ],
      "REQUIRES" : [ "rules", "php", "heartbeat_rules", "rules_scheduler" ],
      "ON" : { "node_update--media" : { "bundle" : "media" } },
      "IF" : [
        { "entity_has_field" : { "entity" : [ "node" ], "field" : "field_rating" } },
        { "NOT data_is" : {
            "data" : [ "node:field-rating:tid" ],
            "value" : [ "node-unchanged:field-rating:tid" ]
          }
        },
        { "php_eval" : { "code" : "return (!isset($node-\\u003Eskip_status_change_notification) || !$node-\\u003Eskip_status_change_notification);" } }
      ],
      "DO" : [
        { "heartbeat_activity_checkdesk_fact_checking_set" : {
            "nid" : [ "node:nid" ],
            "uid" : [ "site:current-user:uid" ],
            "nid_target" : "\\u003C?php\\r\\nif (isset($node-\\u003Efield_stories[LANGUAGE_NONE][0][\\u0027target_id\\u0027])) {\\r\\n     echo $node-\\u003Efield_stories[LANGUAGE_NONE][0][\\u0027target_id\\u0027];\\r\\n}\\r\\nelse {\\r\\n    echo 0;\\r\\n}\\r\\n?\\u003E",
            "uid_target" : "0",
            "message_id" : { "value" : { "checkdesk_fact_checking_set" : "checkdesk_fact_checking_set" } },
            "!user_url" : [ "site:current-user:uid" ],
            "!username" : [ "site:current-user:name" ],
            "!report_url" : [ "node:url" ],
            "!fact_checking_status" : [ "node:field-rating:name" ]
          }
        },
        { "heartbeat_activity_checkdesk_fact_status_changed_for_commenter" : {
            "nid" : [ "node:nid" ],
            "uid" : [ "site:current-user:uid" ],
            "nid_target" : "\\u003C?php\\r\\nif (isset($node-\\u003Efield_stories[LANGUAGE_NONE][0][\\u0027target_id\\u0027])) {\\r\\n     echo $node-\\u003Efield_stories[LANGUAGE_NONE][0][\\u0027target_id\\u0027];\\r\\n}\\r\\nelse {\\r\\n    echo 0;\\r\\n}\\r\\n?\\u003E",
            "uid_target" : "0",
            "message_id" : { "value" : { "checkdesk_fact_status_changed_for_commenter" : "checkdesk_fact_status_changed_for_commenter" } },
            "!user_url" : [ "site:current-user:uid" ],
            "!username" : [ "site:current-user:name" ],
            "!report_url" : [ "node:url" ],
            "!fact_checking_status" : [ "node:field-rating:name" ]
          }
        },
        { "schedule" : {
            "component" : "rules_notify_subscribed_users_fact_checking_status_changed_for_s",
            "date" : "now",
            "param_node" : [ "node" ],
            "param_current_user" : [ "site:current-user" ]
          }
        },
        { "schedule" : {
            "component" : "rules_notify_subscribed_users_fact_checking_status_changed_for_c",
            "date" : "now",
            "param_node" : [ "node" ],
            "param_current_user" : [ "site:current-user" ]
          }
        }
      ]
    }
  }');
  $items['rules_fact_checking_turned_off_for_report'] = entity_import('rules_config', '{ "rules_fact_checking_turned_off_for_report" : {
      "LABEL" : "Fact-checking turned off for report",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "checkdesk" ],
      "REQUIRES" : [ "rules", "flag" ],
      "ON" : { "flag_unflagged_factcheck_journalist" : [] },
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "flagged-node" ],
            "type" : { "value" : { "media" : "media" } }
          }
        }
      ],
      "DO" : [
        { "data_set" : { "data" : [ "flagged-node:field-rating" ], "value" : "4" } }
      ]
    }
  }');
  $items['rules_fact_checking_turned_on_for_report_by_citizen_journalist'] = entity_import('rules_config', '{ "rules_fact_checking_turned_on_for_report_by_citizen_journalist" : {
      "LABEL" : "Fact-checking turned on for report by citizen journalist",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "checkdesk" ],
      "REQUIRES" : [ "rules", "php", "heartbeat_rules", "rules_scheduler", "flag" ],
      "ON" : { "flag_flagged_factcheck_journalist" : [] },
      "IF" : [
        { "user_has_role" : { "account" : [ "flagging-user" ], "roles" : { "value" : { "4" : "4" } } } },
        { "node_is_of_type" : {
            "node" : [ "flagged-node" ],
            "type" : { "value" : { "media" : "media" } }
          }
        }
      ],
      "DO" : [
        { "heartbeat_activity_checkdesk_fact_checking_on_by_citizen" : {
            "nid" : [ "flagged-node:nid" ],
            "uid" : [ "flagging-user:uid" ],
            "nid_target" : "\\u003C?php\\r\\nif (isset($flagged_node-\\u003Efield_stories[LANGUAGE_NONE][0][\\u0027target_id\\u0027])) {\\r\\n     echo $flagged_node-\\u003Efield_stories[LANGUAGE_NONE][0][\\u0027target_id\\u0027];\\r\\n}\\r\\nelse {\\r\\n    echo 0;\\r\\n}\\r\\n?\\u003E",
            "uid_target" : "0",
            "message_id" : { "value" : { "checkdesk_fact_checking_on_by_citizen" : "checkdesk_fact_checking_on_by_citizen" } },
            "!user_url" : [ "flagging-user:url" ],
            "!username" : [ "flagging-user:name" ],
            "!report_url" : [ "flagged-node:url" ]
          }
        },
        { "schedule" : {
            "component" : "rules_notify_subscribed_users_citizen",
            "date" : "now",
            "param_flagged_node" : [ "flagged-node" ],
            "param_flagging_user" : [ "flagging-user" ]
          }
        }
      ]
    }
  }');
  $items['rules_new_report'] = entity_import('rules_config', '{ "rules_new_report" : {
      "LABEL" : "New report",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "checkdesk" ],
      "REQUIRES" : [ "rules", "php", "heartbeat_rules" ],
      "ON" : { "node_insert" : [] },
      "IF" : [
        { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "media" : "media" } } } }
      ],
      "DO" : [
        { "heartbeat_activity_new_report" : {
            "nid" : [ "node:nid" ],
            "uid" : [ "node:author:uid" ],
            "nid_target" : "\\u003C?php\\r\\nif (isset($node-\\u003Efield_stories[LANGUAGE_NONE][0][\\u0027target_id\\u0027])) {\\r\\n     echo $node-\\u003Efield_stories[LANGUAGE_NONE][0][\\u0027target_id\\u0027];\\r\\n}\\r\\nelse {\\r\\n    echo 0;\\r\\n}\\r\\n?\\u003E",
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
      "OWNER" : "rules",
      "TAGS" : [ "checkdesk" ],
      "REQUIRES" : [ "rules", "php", "heartbeat_rules", "comment" ],
      "ON" : { "comment_insert" : [] },
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
            "nid_target" : "\\u003C?php\\r\\n$node = node_load($comment-\\u003Enid);\\r\\nif (isset($node-\\u003Efield_stories[LANGUAGE_NONE][0][\\u0027target_id\\u0027])) {\\r\\n     echo $node-\\u003Efield_stories[LANGUAGE_NONE][0][\\u0027target_id\\u0027];\\r\\n}\\r\\nelse {\\r\\n    echo 0;\\r\\n}\\r\\n?\\u003E",
            "cid" : [ "comment:cid" ],
            "message_id" : { "value" : { "new_comment_report" : "new_comment_report" } },
            "!username" : [ "comment:author:name" ],
            "!comment" : [ "comment:comment-body:value" ]
          }
        }
      ]
    }
  }');
  $items['rules_new_story'] = entity_import('rules_config', '{ "rules_new_story" : {
      "LABEL" : "New story",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "checkdesk" ],
      "REQUIRES" : [ "rules", "heartbeat_rules", "rules_scheduler" ],
      "ON" : { "node_insert--discussion" : { "bundle" : "discussion" } },
      "IF" : [ { "node_is_published" : { "node" : [ "node" ] } } ],
      "DO" : [
        { "heartbeat_activity_checkdesk_add_story" : {
            "nid" : [ "node:nid" ],
            "uid" : [ "site:current-user:uid" ],
            "nid_target" : [ "node:nid" ],
            "message_id" : { "value" : { "checkdesk_add_story" : "checkdesk_add_story" } },
            "!user_url" : [ "site:current-user:url" ],
            "!username" : [ "site:current-user:name" ],
            "!story_url" : [ "node:url" ]
          }
        },
        { "schedule" : {
            "component" : "checkdesk_core_feature_notify_subscribed_users_new_story",
            "date" : "now",
            "param_story" : [ "node" ]
          }
        }
      ]
    }
  }');
  $items['rules_new_update'] = entity_import('rules_config', '{ "rules_new_update" : {
      "LABEL" : "New update",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "checkdesk" ],
      "REQUIRES" : [ "rules", "heartbeat_rules", "rules_scheduler", "checkdesk_core" ],
      "ON" : { "node_insert--post" : { "bundle" : "post" } },
      "IF" : [
        { "NOT data_is_empty" : { "data" : [ "node:field_desk" ] } },
        { "node_is_published" : { "node" : [ "node" ] } }
      ],
      "DO" : [
        { "heartbeat_activity_checkdesk_new_update_on_story_i_commented_on_update" : {
            "nid" : [ "node:nid" ],
            "uid" : [ "node:author:uid" ],
            "nid_target" : [ "node:field-desk:nid" ],
            "uid_target" : "0",
            "message_id" : { "value" : { "checkdesk_new_update_on_story_i_commented_on_update" : "checkdesk_new_update_on_story_i_commented_on_update" } },
            "!user_url" : [ "node:author:url" ],
            "!username" : [ "node:author:name" ],
            "!update_url" : [ "node:url" ],
            "!story_url" : [ "node:field-desk:url" ],
            "!story" : [ "node:field-desk:title" ]
          }
        },
        { "schedule" : {
            "component" : "rules_notify_subscribed_users_new_update",
            "date" : "now",
            "param_node" : [ "node" ],
            "param_story" : [ "node:field-desk" ]
          }
        },
        { "checkdesk_core_actions_set_followers" : { "node" : [ "node:field-desk" ] } }
      ]
    }
  }');
  $items['rules_new_user'] = entity_import('rules_config', '{ "rules_new_user" : {
      "LABEL" : "New user",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "checkdesk" ],
      "REQUIRES" : [ "php", "rules", "heartbeat_rules", "rules_scheduler" ],
      "ON" : { "user_insert" : [] },
      "IF" : [
        { "php_eval" : { "code" : "if (variable_get(\\u0027user_register\\u0027, USER_REGISTER_VISITORS_ADMINISTRATIVE_APPROVAL) == USER_REGISTER_VISITORS_ADMINISTRATIVE_APPROVAL) {\\r\\n  return TRUE;\\r\\n}\\r\\nreturn FALSE;" } },
        { "user_is_blocked" : { "account" : [ "account" ] } }
      ],
      "DO" : [
        { "heartbeat_activity_checkdesk_new_user" : {
            "nid" : "[account:uid]",
            "uid" : "[account:uid]",
            "nid_target" : "0",
            "uid_target" : "0",
            "message_id" : { "value" : { "checkdesk_new_user" : "checkdesk_new_user" } },
            "!url" : "[account:edit-url]",
            "!name" : "[account:name]"
          }
        },
        { "schedule" : {
            "component" : "rules_notify_subscribed_users_new_user",
            "date" : "now",
            "param_user" : [ "account" ]
          }
        }
      ]
    }
  }');
  $items['rules_notify_follower_users_change_report_status'] = entity_import('rules_config', '{ "rules_notify_follower_users_change_report_status" : {
      "LABEL" : "Notify follower users: change report status",
      "PLUGIN" : "action set",
      "OWNER" : "rules",
      "TAGS" : [ "checkdesk" ],
      "REQUIRES" : [ "php", "rules", "meedan_notifications" ],
      "USES VARIABLES" : {
        "node" : { "label" : "Node", "type" : "node" },
        "story" : { "label" : "Story", "type" : "node" },
        "current_user" : { "label" : "Current user", "type" : "user" }
      },
      "ACTION SET" : [
        { "notify_subscribers" : {
            "object" : [ "node" ],
            "event" : "email_report_status_on_story_i_followed",
            "subject" : "Change report status",
            "message" : "Hello !recipient_name,\\r\\n\\r\\n!actor has changed report \\u0022!node_title\\u0022  status.",
            "actor" : [ "current-user" ],
            "t_args" : "\\u003C?php\\r\\nreturn serialize(array(\\u0027!actor\\u0027 =\\u003E $current_user-\\u003Ename, \\u0027!story_title\\u0027 =\\u003E $story-\\u003Etitle, \\u0027!node_title\\u0027 =\\u003E $node-\\u003Etitle, \\u0027!story_url\\u0027 =\\u003E url(\\u0027node\\/\\u0027 . $story-\\u003Enid, array(\\u0027absolute\\u0027 =\\u003E TRUE, \\u0027alias\\u0027 =\\u003E TRUE)), \\u0027!site\\u0027 =\\u003E variable_get(\\u0027site_name\\u0027, \\u0027Checkdesk\\u0027), \\u0027!recipient_name\\u0027 =\\u003E \\u0027[recipient:name]\\u0027, \\u0027!recipient_url\\u0027 =\\u003E \\u0027[recipient:edit-url]\\u0027)); \\r\\n?\\u003E"
          }
        }
      ]
    }
  }');
  $items['rules_notify_subscribed_users'] = entity_import('rules_config', '{ "rules_notify_subscribed_users" : {
      "LABEL" : "Notify subscribed users: fact-checking on",
      "PLUGIN" : "action set",
      "OWNER" : "rules",
      "TAGS" : [ "checkdesk" ],
      "REQUIRES" : [ "php", "rules", "meedan_notifications" ],
      "USES VARIABLES" : {
        "flagged_node" : { "label" : "Flagged node", "type" : "node" },
        "flagging_user" : { "label" : "Flagging user", "type" : "user" }
      },
      "ACTION SET" : [
        { "notify_subscribers" : {
            "object" : [ "flagged-node" ],
            "event" : "email_fact_checking_on",
            "subject" : "Fact-checking turned on",
            "message" : "Hello !recipient_name,\\r\\n\\r\\n!actor has turned on fact-checking for a \\u003Ca href=\\u0022!url\\u0022\\u003Ereport\\u003C\\/a\\u003E you submitted.",
            "actor" : [ "flagging-user" ],
            "t_args" : "\\u003C?php\\r\\nreturn serialize(array(\\u0027!actor\\u0027 =\\u003E $flagging_user-\\u003Ename, \\u0027!url\\u0027 =\\u003E url(\\u0027node\\/\\u0027 . $flagged_node-\\u003Enid, array(\\u0027absolute\\u0027 =\\u003E TRUE, \\u0027alias\\u0027 =\\u003E TRUE)), \\u0027!site\\u0027 =\\u003E variable_get(\\u0027site_name\\u0027, \\u0027Checkdesk\\u0027), \\u0027!recipient_name\\u0027 =\\u003E \\u0027[recipient:name]\\u0027, \\u0027!recipient_url\\u0027 =\\u003E \\u0027[recipient:edit-url]\\u0027)); \\r\\n?\\u003E"
          }
        }
      ]
    }
  }');
  $items['rules_notify_subscribed_users_citizen'] = entity_import('rules_config', '{ "rules_notify_subscribed_users_citizen" : {
      "LABEL" : "Notify subscribed users: fact-checking on by citizen",
      "PLUGIN" : "action set",
      "OWNER" : "rules",
      "TAGS" : [ "checkdesk" ],
      "REQUIRES" : [ "php", "rules", "meedan_notifications" ],
      "USES VARIABLES" : {
        "flagged_node" : { "label" : "Flagged node", "type" : "node" },
        "flagging_user" : { "label" : "Flagging user", "type" : "user" }
      },
      "ACTION SET" : [
        { "notify_subscribers" : {
            "object" : [ "flagged-node" ],
            "event" : "email_fact_checking_set_by_citizen",
            "subject" : "Fact-checking turned on",
            "message" : "Hello !recipient_name,\\r\\n\\r\\n!actor has turned on fact-checking for a \\u003Ca href=\\u0022!url\\u0022\\u003Ereport\\u003C\\/a\\u003E .",
            "actor" : [ "flagging-user" ],
            "t_args" : "\\u003C?php\\r\\nreturn serialize(array(\\u0027!actor\\u0027 =\\u003E $flagging_user-\\u003Ename, \\u0027!url\\u0027 =\\u003E url(\\u0027node\\/\\u0027 . $flagged_node-\\u003Enid, array(\\u0027absolute\\u0027 =\\u003E TRUE, \\u0027alias\\u0027 =\\u003E TRUE)), \\u0027!site\\u0027 =\\u003E variable_get(\\u0027site_name\\u0027, \\u0027Checkdesk\\u0027), \\u0027!recipient_name\\u0027 =\\u003E \\u0027[recipient:name]\\u0027, \\u0027!recipient_url\\u0027 =\\u003E \\u0027[recipient:edit-url]\\u0027)); \\r\\n?\\u003E"
          }
        }
      ]
    }
  }');
  $items['rules_notify_subscribed_users_comment_on_update'] = entity_import('rules_config', '{ "rules_notify_subscribed_users_comment_on_update" : {
      "LABEL" : "Notify subscribed users: comment on update",
      "PLUGIN" : "action set",
      "OWNER" : "rules",
      "TAGS" : [ "checkdesk" ],
      "REQUIRES" : [ "php", "rules", "meedan_notifications" ],
      "USES VARIABLES" : { "comment" : { "label" : "Comment", "type" : "comment" } },
      "ACTION SET" : [
        { "notify_subscribers" : {
            "object" : [ "comment" ],
            "event" : "email_comment_on_update",
            "subject" : "Comment on an update",
            "message" : "Hello !recipient_name,\\r\\n\\r\\n!author has commented on \\u003Ca href=\\u0022!url\\u0022\\u003E!title\\u003C\\/a\\u003E:\\r\\n\\r\\n!body\\r\\n\\r\\nYou can edit your notification settings from your \\u003Ca href=\\u0022!recipient_url\\u0022\\u003Eprofile page\\u003C\\/a\\u003E.\\r\\n\\r\\nThis was an auto-generated email from !site; please do not respond directly to this email.",
            "actor" : [ "comment:author" ],
            "t_args" : "\\u003C?php\\r\\nreturn serialize(array(\\u0027!body\\u0027 =\\u003E  $comment-\\u003Ecomment_body[LANGUAGE_NONE][0][\\u0027value\\u0027], \\u0027!author\\u0027 =\\u003E user_load($comment-\\u003Euid)-\\u003Ename, \\u0027!url\\u0027 =\\u003E url(\\u0027node\\/\\u0027 . $comment-\\u003Enid, array(\\u0027absolute\\u0027 =\\u003E TRUE, \\u0027alias\\u0027 =\\u003E TRUE)), \\u0027!title\\u0027 =\\u003E node_load($comment-\\u003Enid)-\\u003Etitle, \\u0027!site\\u0027 =\\u003E variable_get(\\u0027site_name\\u0027, \\u0027Checkdesk\\u0027), \\u0027!recipient_name\\u0027 =\\u003E \\u0027[recipient:name]\\u0027, \\u0027!recipient_url\\u0027 =\\u003E \\u0027[recipient:edit-url]\\u0027)); \\r\\n?\\u003E\\r\\n"
          }
        }
      ]
    }
  }');
  $items['rules_notify_subscribed_users_existing_report_suggested_to_story'] = entity_import('rules_config', '{ "rules_notify_subscribed_users_existing_report_suggested_to_story" : {
      "LABEL" : "Notify subscribed users: existing report suggested to story",
      "PLUGIN" : "action set",
      "OWNER" : "rules",
      "TAGS" : [ "checkdesk" ],
      "REQUIRES" : [ "php", "rules", "meedan_notifications" ],
      "USES VARIABLES" : {
        "node" : { "label" : "Node", "type" : "node" },
        "list_item" : { "label" : "List Item", "type" : "node" },
        "current_user" : { "label" : "Current user", "type" : "user" }
      },
      "ACTION SET" : [
        { "notify_subscribers" : {
            "object" : [ "node" ],
            "event" : "email_report_suggested",
            "subject" : "Report added to story",
            "message" : "Hello !recipient_name,\\r\\n\\r\\n!actor has added a new report \\u0022!node_title\\u0022 to this story \\u0022!story_title\\u0022.\\r\\n\\r\\n\\u003Ca href=\\u0022!story_url\\u0022\\u003EClick here\\u003C\\/a\\u003E to compose a new update to the story using that report.\\r\\n\\r\\nYou can edit your notification settings from your \\u003Ca href=\\u0022!recipient_url\\u0022\\u003Eprofile page\\u003C\\/a\\u003E.\\r\\n\\r\\nThis was an auto-generated email from !site, please do not respond directly to this email.",
            "actor" : [ "current-user" ],
            "t_args" : "\\u003C?php\\r\\nreturn serialize(array(\\u0027!actor\\u0027 =\\u003E $current_user-\\u003Ename, \\u0027!story_title\\u0027 =\\u003E $list_item-\\u003Etitle, \\u0027!node_title\\u0027 =\\u003E $node-\\u003Etitle, \\u0027!story_url\\u0027 =\\u003E url(\\u0027node\\/\\u0027 . $list_item-\\u003Enid, array(\\u0027absolute\\u0027 =\\u003E TRUE, \\u0027alias\\u0027 =\\u003E TRUE)), \\u0027!site\\u0027 =\\u003E variable_get(\\u0027site_name\\u0027, \\u0027Checkdesk\\u0027), \\u0027!recipient_name\\u0027 =\\u003E \\u0027[recipient:name]\\u0027, \\u0027!recipient_url\\u0027 =\\u003E \\u0027[recipient:edit-url]\\u0027)); \\r\\n?\\u003E"
          }
        },
        { "notify_subscribers" : {
            "object" : [ "node" ],
            "event" : "email_report_on_story_i_followed",
            "subject" : "Report added to story",
            "message" : "Hello !recipient_name,\\r\\n\\r\\n!actor has added a new report \\u0022!node_title\\u0022 to this story \\u0022!story_title\\u0022.\\r\\n\\r\\n\\u003Ca href=\\u0022!story_url\\u0022\\u003EClick here\\u003C\\/a\\u003E to compose a new update to the story using that report.",
            "actor" : [ "current-user" ],
            "t_args" : "\\u003C?php\\r\\nreturn serialize(array(\\u0027!actor\\u0027 =\\u003E $current_user-\\u003Ename, \\u0027!story_title\\u0027 =\\u003E $list_item-\\u003Etitle, \\u0027!node_title\\u0027 =\\u003E $node-\\u003Etitle, \\u0027!story_url\\u0027 =\\u003E url(\\u0027node\\/\\u0027 . $list_item-\\u003Enid, array(\\u0027absolute\\u0027 =\\u003E TRUE, \\u0027alias\\u0027 =\\u003E TRUE)), \\u0027!site\\u0027 =\\u003E variable_get(\\u0027site_name\\u0027, \\u0027Checkdesk\\u0027), \\u0027!recipient_name\\u0027 =\\u003E \\u0027[recipient:name]\\u0027, \\u0027!recipient_url\\u0027 =\\u003E \\u0027[recipient:edit-url]\\u0027)); \\r\\n?\\u003E"
          }
        }
      ]
    }
  }');
  $items['rules_notify_subscribed_users_fact_checking_status_changed_for_c'] = entity_import('rules_config', '{ "rules_notify_subscribed_users_fact_checking_status_changed_for_c" : {
      "LABEL" : "Notify subscribed users: fact-checking status changed for commenter",
      "PLUGIN" : "action set",
      "OWNER" : "rules",
      "TAGS" : [ "checkdesk" ],
      "REQUIRES" : [ "php", "rules", "meedan_notifications" ],
      "USES VARIABLES" : {
        "node" : { "label" : "Node", "type" : "node" },
        "current_user" : { "label" : "Current user", "type" : "user" }
      },
      "ACTION SET" : [
        { "notify_subscribers" : {
            "object" : [ "node" ],
            "event" : "email_fact_status_changed_for_commenter",
            "subject" : "Fact-checking status changed",
            "message" : "Hello !recipient_name,\\r\\n\\r\\n!actor has changed the fact-checking status for a \\u003Ca href=\\u0022!url\\u0022\\u003Ereport\\u003C\\/a\\u003E you added footnote to to !rating.",
            "actor" : [ "current-user" ],
            "t_args" : "\\u003C?php\\r\\n$rating = entity_metadata_wrapper(\\u0027node\\u0027, $node)-\\u003Efield_rating-\\u003Evalue();\\r\\nreturn serialize(array(\\u0027!actor\\u0027 =\\u003E $current_user-\\u003Ename, \\u0027!url\\u0027 =\\u003E url(\\u0027node\\/\\u0027 . $node-\\u003Enid, array(\\u0027absolute\\u0027 =\\u003E TRUE, \\u0027alias\\u0027 =\\u003E TRUE)), \\u0027!rating\\u0027 =\\u003E $rating-\\u003Ename, \\u0027!site\\u0027 =\\u003E variable_get(\\u0027site_name\\u0027, \\u0027Checkdesk\\u0027), \\u0027!recipient_name\\u0027 =\\u003E \\u0027[recipient:name]\\u0027, \\u0027!recipient_url\\u0027 =\\u003E \\u0027[recipient:edit-url]\\u0027)); \\r\\n?\\u003E"
          }
        }
      ]
    }
  }');
  $items['rules_notify_subscribed_users_fact_checking_status_changed_for_s'] = entity_import('rules_config', '{ "rules_notify_subscribed_users_fact_checking_status_changed_for_s" : {
      "LABEL" : "Notify subscribed users: fact-checking status changed for submitter",
      "PLUGIN" : "action set",
      "OWNER" : "rules",
      "TAGS" : [ "checkdesk" ],
      "REQUIRES" : [ "php", "rules", "meedan_notifications" ],
      "USES VARIABLES" : {
        "node" : { "label" : "Node", "type" : "node" },
        "current_user" : { "label" : "Current user", "type" : "user" }
      },
      "ACTION SET" : [
        { "notify_subscribers" : {
            "object" : [ "node" ],
            "event" : "email_fact_checking_set",
            "subject" : "Fact-checking status changed",
            "message" : "Hello !recipient_name,\\r\\n\\r\\n!actor has changed the fact-checking status for a \\u003Ca href=\\u0022!url\\u0022\\u003Ereport\\u003C\\/a\\u003E you submitted to !rating.",
            "actor" : [ "current-user" ],
            "t_args" : "\\u003C?php\\r\\n$rating = entity_metadata_wrapper(\\u0027node\\u0027, $node)-\\u003Efield_rating-\\u003Evalue();\\r\\nreturn serialize(array(\\u0027!actor\\u0027 =\\u003E $current_user-\\u003Ename, \\u0027!url\\u0027 =\\u003E url(\\u0027node\\/\\u0027 . $node-\\u003Enid, array(\\u0027absolute\\u0027 =\\u003E TRUE, \\u0027alias\\u0027 =\\u003E TRUE)), \\u0027!rating\\u0027 =\\u003E $rating-\\u003Ename, \\u0027!site\\u0027 =\\u003E variable_get(\\u0027site_name\\u0027, \\u0027Checkdesk\\u0027), \\u0027!recipient_name\\u0027 =\\u003E \\u0027[recipient:name]\\u0027, \\u0027!recipient_url\\u0027 =\\u003E \\u0027[recipient:edit-url]\\u0027)); \\r\\n?\\u003E"
          }
        }
      ]
    }
  }');
  $items['rules_notify_subscribed_users_footnote'] = entity_import('rules_config', '{ "rules_notify_subscribed_users_footnote" : {
      "LABEL" : "Notify subscribed users: footnote",
      "PLUGIN" : "action set",
      "OWNER" : "rules",
      "TAGS" : [ "checkdesk" ],
      "REQUIRES" : [ "php", "rules", "meedan_notifications" ],
      "USES VARIABLES" : { "comment" : { "label" : "Comment", "type" : "comment" } },
      "ACTION SET" : [
        { "notify_subscribers" : {
            "object" : [ "comment:node" ],
            "event" : "email_comment_on_report",
            "subject" : "New footnote",
            "message" : "Hello !recipient_name,\\r\\n\\r\\n!author has added a footnote to the following report \\u0022!title\\u0022:\\r\\n\\r\\n!body\\r\\n\\r\\n\\u003Ca href=\\u0022!url\\u0022\\u003EClick here\\u003C\\/a\\u003E to respond or change the status of the report.",
            "actor" : [ "comment:author" ],
            "t_args" : "\\u003C?php\\r\\nreturn serialize(array(\\u0027!body\\u0027 =\\u003E $comment-\\u003Ecomment_body[LANGUAGE_NONE][0][\\u0027value\\u0027], \\u0027!author\\u0027 =\\u003E user_load($comment-\\u003Euid)-\\u003Ename, \\u0027!url\\u0027 =\\u003E url(\\u0027node\\/\\u0027 . $comment-\\u003Enid, array(\\u0027absolute\\u0027 =\\u003E TRUE, \\u0027alias\\u0027 =\\u003E TRUE)), \\u0027!title\\u0027 =\\u003E node_load($comment-\\u003Enid)-\\u003Etitle, \\u0027!site\\u0027 =\\u003E variable_get(\\u0027site_name\\u0027, \\u0027Checkdesk\\u0027), \\u0027!recipient_name\\u0027 =\\u003E \\u0027[recipient:name]\\u0027, \\u0027!recipient_url\\u0027 =\\u003E \\u0027[recipient:edit-url]\\u0027)); \\r\\n?\\u003E"
          }
        }
      ]
    }
  }');
  $items['rules_notify_subscribed_users_new_update'] = entity_import('rules_config', '{ "rules_notify_subscribed_users_new_update" : {
      "LABEL" : "Notify subscribed users: new update",
      "PLUGIN" : "action set",
      "OWNER" : "rules",
      "TAGS" : [ "checkdesk" ],
      "REQUIRES" : [ "php", "rules", "meedan_notifications" ],
      "USES VARIABLES" : {
        "node" : { "label" : "Node", "type" : "node" },
        "story" : { "label" : "Story", "type" : "node" }
      },
      "ACTION SET" : [
        { "notify_subscribers" : {
            "object" : [ "story" ],
            "event" : "email_update_on_story_i_commented_on_update",
            "subject" : "New update",
            "message" : "Hello !recipient_name,\\r\\n\\r\\nStory \\u0022!title\\u0022 which you commented on has a \\u003Ca href=\\u0022!url\\u0022\\u003Enew update\\u003C\\/a\\u003E.\\r\\n\\r\\nYou can edit your notification settings from your \\u003Ca href=\\u0022!recipient_url\\u0022\\u003Eprofile page\\u003C\\/a\\u003E.\\r\\n\\r\\nThis was an auto-generated email from !site; please do not respond directly to this email.",
            "actor" : [ "node:author" ],
            "t_args" : "\\u003C?php\\r\\nreturn serialize(array(\\u0027!title\\u0027 =\\u003E $story-\\u003Etitle, \\u0027!url\\u0027 =\\u003E url(\\u0027node\\/\\u0027 . $node-\\u003Enid, array(\\u0027absolute\\u0027 =\\u003E TRUE, \\u0027alias\\u0027 =\\u003E TRUE)), \\u0027!site\\u0027 =\\u003E variable_get(\\u0027site_name\\u0027, \\u0027Checkdesk\\u0027), \\u0027!recipient_name\\u0027 =\\u003E \\u0027[recipient:name]\\u0027, \\u0027!recipient_url\\u0027 =\\u003E \\u0027[recipient:edit-url]\\u0027)); \\r\\n?\\u003E"
          }
        },
        { "notify_subscribers" : {
            "object" : [ "node" ],
            "event" : "email_update_on_story_i_followed",
            "subject" : "New update",
            "message" : "Hello !recipient_name,\\r\\n\\r\\nStory \\u0022!title\\u0022 which you followed has a \\u003Ca href=\\u0022!url\\u0022\\u003Enew update\\u003C\\/a\\u003E.",
            "actor" : [ "node:author" ],
            "t_args" : "\\u003C?php\\r\\nreturn serialize(array(\\u0027!title\\u0027 =\\u003E $story-\\u003Etitle, \\u0027!url\\u0027 =\\u003E url(\\u0027node\\/\\u0027 . $node-\\u003Enid, array(\\u0027absolute\\u0027 =\\u003E TRUE, \\u0027alias\\u0027 =\\u003E TRUE)), \\u0027!site\\u0027 =\\u003E variable_get(\\u0027site_name\\u0027, \\u0027Checkdesk\\u0027), \\u0027!recipient_name\\u0027 =\\u003E \\u0027[recipient:name]\\u0027, \\u0027!recipient_url\\u0027 =\\u003E \\u0027[recipient:edit-url]\\u0027)); \\r\\n?\\u003E"
          }
        },
        { "notify_subscribers" : {
            "object" : [ "node" ],
            "event" : "email_new_update",
            "subject" : "An update has been added to a story",
            "message" : "Hello !recipient_name,\\r\\n\\r\\n!author has added a \\u003Ca href=\\u0022!url\\u0022\\u003Enew update\\u003C\\/a\\u003E to the story \\u0022!title\\u0022.\\r\\n",
            "actor" : [ "node:author" ],
            "t_args" : "\\u003C?php\\r\\nreturn serialize(array(\\u0027!author\\u0027 =\\u003E user_load($story-\\u003Euid)-\\u003Ename, \\u0027!title\\u0027 =\\u003E $story-\\u003Etitle, \\u0027!url\\u0027 =\\u003E url(\\u0027node\\/\\u0027 . $node-\\u003Enid, array(\\u0027absolute\\u0027 =\\u003E TRUE, \\u0027alias\\u0027 =\\u003E TRUE)), \\u0027!site\\u0027 =\\u003E variable_get(\\u0027site_name\\u0027, \\u0027Checkdesk\\u0027), \\u0027!recipient_name\\u0027 =\\u003E \\u0027[recipient:name]\\u0027, \\u0027!recipient_url\\u0027 =\\u003E \\u0027[recipient:edit-url]\\u0027)); \\r\\n?\\u003E"
          }
        }
      ]
    }
  }');
  $items['rules_notify_subscribed_users_new_user'] = entity_import('rules_config', '{ "rules_notify_subscribed_users_new_user" : {
      "LABEL" : "Notify subscribed users: new user",
      "PLUGIN" : "action set",
      "OWNER" : "rules",
      "TAGS" : [ "checkdesk" ],
      "REQUIRES" : [ "php", "rules", "meedan_notifications" ],
      "USES VARIABLES" : { "user" : { "label" : "User", "type" : "user" } },
      "ACTION SET" : [
        { "notify_subscribers" : {
            "object" : [ "user" ],
            "event" : "email_new_user",
            "subject" : "New user",
            "message" : "Hello !recipient_name,\\r\\n\\r\\nA new user \\u003Ca href=\\u0022!url\\u0022\\u003E!name \\u003C\\/a\\u003Ehas registered. If you want to accept this registration, please mark this user as \\u0022active\\u0022.",
            "actor" : [ "user" ],
            "t_args" : "\\u003C?php\\r\\nreturn serialize(array(\\u0027!name\\u0027 =\\u003E $user-\\u003Ename, \\u0027!url\\u0027 =\\u003E url(\\u0027user\\/\\u0027 . $user-\\u003Euid . \\u0027\\/edit\\u0027, array(\\u0027absolute\\u0027 =\\u003E TRUE, \\u0027alias\\u0027 =\\u003E TRUE)), \\u0027!site\\u0027 =\\u003E variable_get(\\u0027site_name\\u0027, \\u0027Checkdesk\\u0027), \\u0027!recipient_name\\u0027 =\\u003E \\u0027[recipient:name]\\u0027, \\u0027!recipient_url\\u0027 =\\u003E \\u0027[recipient:notifications-url]\\u0027)); \\r\\n?\\u003E"
          }
        }
      ]
    }
  }');
  $items['rules_notify_subscribed_users_reply_to_comment'] = entity_import('rules_config', '{ "rules_notify_subscribed_users_reply_to_comment" : {
      "LABEL" : "Notify subscribed users: reply to comment",
      "PLUGIN" : "action set",
      "OWNER" : "rules",
      "TAGS" : [ "checkdesk" ],
      "REQUIRES" : [ "php", "rules", "meedan_notifications" ],
      "USES VARIABLES" : { "comment" : { "label" : "Comment", "type" : "comment" } },
      "ACTION SET" : [
        { "notify_subscribers" : {
            "object" : [ "comment" ],
            "event" : "email_reply_to_comment",
            "subject" : "Comment reply",
            "message" : "Hello !recipient_name,\\r\\n\\r\\n!author has replied to your comment:\\r\\n\\r\\n!body\\r\\n\\r\\n\\u003Ca href=\\u0022!url\\u0022\\u003EClick here\\u003C\\/a\\u003E OR reply to this email to respond. This was an auto-generated email from !site.",
            "actor" : [ "comment:author" ],
            "t_args" : "\\u003C?php\\r\\nreturn serialize(array(\\u0027!body\\u0027 =\\u003E $comment-\\u003Ecomment_body[LANGUAGE_NONE][0][\\u0027value\\u0027], \\u0027!author\\u0027 =\\u003E user_load($comment-\\u003Euid)-\\u003Ename, \\u0027!url\\u0027 =\\u003E url(\\u0027node\\/\\u0027 . $comment-\\u003Enid, array(\\u0027absolute\\u0027 =\\u003E TRUE, \\u0027alias\\u0027 =\\u003E TRUE)), \\u0027!site\\u0027 =\\u003E variable_get(\\u0027site_name\\u0027, \\u0027Checkdesk\\u0027), \\u0027!recipient_name\\u0027 =\\u003E \\u0027[recipient:name]\\u0027)); \\r\\n?\\u003E"
          }
        }
      ]
    }
  }');
  $items['rules_notify_subscribed_users_report_published'] = entity_import('rules_config', '{ "rules_notify_subscribed_users_report_published" : {
      "LABEL" : "Notify subscribed users: report published",
      "PLUGIN" : "action set",
      "OWNER" : "rules",
      "TAGS" : [ "checkdesk" ],
      "REQUIRES" : [ "php", "rules", "meedan_notifications" ],
      "USES VARIABLES" : {
        "node" : { "label" : "Node", "type" : "node" },
        "report" : { "label" : "Report", "type" : "node" }
      },
      "ACTION SET" : [
        { "notify_subscribers" : {
            "object" : [ "report" ],
            "event" : "email_report_published_in_update",
            "subject" : "Report published",
            "message" : "Hello !recipient_name,\\r\\n\\r\\nA \\u003Ca href=\\u0022!report_url\\u0022\\u003Ereport\\u003C\\/a\\u003E which you have submitted has been published in an \\u003Ca href=\\u0022!node_url\\u0022\\u003Eupdate\\u003C\\/a\\u003E.",
            "actor" : [ "node:author" ],
            "t_args" : "\\u003C?php\\r\\nreturn serialize(array(\\u0027!report_url\\u0027 =\\u003E url(\\u0027node\\/\\u0027 . $report-\\u003Enid, array(\\u0027absolute\\u0027 =\\u003E TRUE, \\u0027alias\\u0027 =\\u003E TRUE)), \\u0027!node_url\\u0027 =\\u003E url(\\u0027node\\/\\u0027 . $node-\\u003Enid, array(\\u0027absolute\\u0027 =\\u003E TRUE, \\u0027alias\\u0027 =\\u003E TRUE)),\\u0027!site\\u0027 =\\u003E variable_get(\\u0027site_name\\u0027, \\u0027Checkdesk\\u0027), \\u0027!recipient_name\\u0027 =\\u003E \\u0027[recipient:name]\\u0027, \\u0027!recipient_url\\u0027 =\\u003E \\u0027[recipient:edit-url]\\u0027)); \\r\\n?\\u003E"
          }
        }
      ]
    }
  }');
  $items['rules_notify_subscribed_users_report_suggested_to_story'] = entity_import('rules_config', '{ "rules_notify_subscribed_users_report_suggested_to_story" : {
      "LABEL" : "Notify subscribed users: report suggested to story",
      "PLUGIN" : "action set",
      "OWNER" : "rules",
      "TAGS" : [ "checkdesk" ],
      "REQUIRES" : [ "php", "rules", "meedan_notifications" ],
      "USES VARIABLES" : {
        "node" : { "label" : "Node", "type" : "node" },
        "list_item" : { "label" : "List item", "type" : "node" }
      },
      "ACTION SET" : [
        { "notify_subscribers" : {
            "object" : [ "node" ],
            "event" : "email_report_suggested",
            "subject" : "Report added to story",
            "message" : "Hello !recipient_name,\\r\\n\\r\\n!actor has added a new report \\u0022!node_title\\u0022 to this story \\u0022!story_title\\u0022.\\r\\n\\r\\nGo to !story_url to compose a new update to the story using that report.\\r\\n\\r\\nYou can edit your notification settings from !recipient_url.\\r\\n\\r\\nThis was an auto-generated email from !site, please do not respond directly to this email.",
            "actor" : [ "node:author" ],
            "t_args" : "\\u003C?php\\r\\nreturn serialize(array(\\u0027!actor\\u0027 =\\u003E user_load($node-\\u003Euid)-\\u003Ename, \\u0027!story_title\\u0027 =\\u003E $list_item-\\u003Etitle, \\u0027!node_title\\u0027 =\\u003E $node-\\u003Etitle, \\u0027!story_url\\u0027 =\\u003E url(\\u0027node\\/\\u0027 . $list_item-\\u003Enid, array(\\u0027absolute\\u0027 =\\u003E TRUE, \\u0027alias\\u0027 =\\u003E TRUE)), \\u0027!site\\u0027 =\\u003E variable_get(\\u0027site_name\\u0027, \\u0027Checkdesk\\u0027), \\u0027!recipient_name\\u0027 =\\u003E \\u0027[recipient:name]\\u0027, \\u0027!recipient_url\\u0027 =\\u003E \\u0027[recipient:edit-url]\\u0027)); \\r\\n?\\u003E"
          }
        },
        { "notify_subscribers" : {
            "object" : [ "node" ],
            "event" : "email_report_on_story_i_followed",
            "subject" : "Report added to story",
            "message" : "Hello !recipient_name,\\r\\n\\r\\n!actor has added a new report \\u0022!node_title\\u0022 to this story \\u0022!story_title\\u0022.\\r\\n\\r\\nGo to !story_url to compose a new update to the story using that report.",
            "actor" : [ "node:author" ],
            "t_args" : "\\u003C?php\\r\\nreturn serialize(array(\\u0027!actor\\u0027 =\\u003E user_load($node-\\u003Euid)-\\u003Ename, \\u0027!story_title\\u0027 =\\u003E $list_item-\\u003Etitle, \\u0027!node_title\\u0027 =\\u003E $node-\\u003Etitle, \\u0027!story_url\\u0027 =\\u003E url(\\u0027node\\/\\u0027 . $list_item-\\u003Enid, array(\\u0027absolute\\u0027 =\\u003E TRUE, \\u0027alias\\u0027 =\\u003E TRUE)), \\u0027!site\\u0027 =\\u003E variable_get(\\u0027site_name\\u0027, \\u0027Checkdesk\\u0027), \\u0027!recipient_name\\u0027 =\\u003E \\u0027[recipient:name]\\u0027, \\u0027!recipient_url\\u0027 =\\u003E \\u0027[recipient:edit-url]\\u0027)); \\r\\n?\\u003E"
          }
        }
      ]
    }
  }');
  $items['rules_notify_subscribed_users_report_was_flagged'] = entity_import('rules_config', '{ "rules_notify_subscribed_users_report_was_flagged" : {
      "LABEL" : "Notify subscribed users: report was flagged",
      "PLUGIN" : "action set",
      "OWNER" : "rules",
      "TAGS" : [ "checkdesk" ],
      "REQUIRES" : [ "php", "rules", "meedan_notifications" ],
      "USES VARIABLES" : {
        "flagged_node" : { "label" : "Flagged node", "type" : "node" },
        "flagging_user" : { "label" : "Flagging user", "type" : "user" },
        "flag" : { "label" : "Flag", "type" : "text" },
        "reason" : { "label" : "Reason", "type" : "text" }
      },
      "ACTION SET" : [
        { "notify_subscribers" : {
            "object" : [ "flagged-node" ],
            "event" : "email_report_flagged",
            "subject" : "Report flagged",
            "message" : "Hello !recipient_name,\\r\\n\\r\\n!flagging_user_name has flagged the following \\u003Ca href=\\u0022!flagged_node_url\\u0022\\u003Ereport\\u003C\\/a\\u003E under \\u0022!flag_title\\u0022:\\r\\n\\r\\n!flagged_node_title\\r\\n\\r\\nThey provided the following explanation for flagging:\\r\\n!reason\\r\\n\\r\\n\\u003Ca href=\\u0022!flagged_node_edit_url\\u0022\\u003EClick here\\u003C\\/a\\u003E to review.",
            "actor" : [ "flagging-user" ],
            "t_args" : "\\u003C?php\\r\\nreturn serialize(array(\\r\\n\\u0027!flagging_user_name\\u0027 =\\u003E $flagging_user-\\u003Ename,\\r\\n\\u0027!flagged_node_url\\u0027 =\\u003E url(\\u0027node\\/\\u0027 . $flagged_node-\\u003Enid, array(\\u0027absolute\\u0027 =\\u003E TRUE, \\u0027alias\\u0027 =\\u003E TRUE)),\\r\\n\\u0027!flag_title\\u0027 =\\u003E flag_get_flag($flag)-\\u003Etitle,\\r\\n\\u0027!flagged_node_title\\u0027 =\\u003E $flagged_node-\\u003Etitle,\\r\\n\\u0027!reason\\u0027 =\\u003E ($reason == \\u0022[flagging:field_reason]\\u0022 ? \\u0022\\u0022 : $reason),\\r\\n\\u0027!flagged_node_edit_url\\u0027 =\\u003E url(\\u0027node\\/\\u0027 . $flagged_node-\\u003Enid . \\u0027\\/edit\\u0027, array(\\u0027absolute\\u0027 =\\u003E TRUE, \\u0027alias\\u0027 =\\u003E TRUE)),\\r\\n\\u0027!site\\u0027 =\\u003E variable_get(\\u0027site_name\\u0027, \\u0027Checkdesk\\u0027),\\r\\n\\u0027!recipient_name\\u0027 =\\u003E \\u0027[recipient:name]\\u0027,\\r\\n\\u0027!recipient_url\\u0027 =\\u003E \\u0027[recipient:edit-url]\\u0027)); \\r\\n?\\u003E"
          }
        }
      ]
    }
  }');
  $items['rules_publish_report'] = entity_import('rules_config', '{ "rules_publish_report" : {
      "LABEL" : "Publish report",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "checkdesk" ],
      "REQUIRES" : [ "rules", "heartbeat_rules" ],
      "ON" : { "node_insert--post" : { "bundle" : "post" } },
      "IF" : [ { "NOT data_is_empty" : { "data" : [ "node:field_desk" ] } } ],
      "DO" : [
        { "LOOP" : {
            "USING" : { "list" : [ "node:reports" ] },
            "ITEM" : { "report" : "Report" },
            "DO" : [
              { "heartbeat_activity_publish_report" : {
                  "nid" : [ "report:nid" ],
                  "uid" : [ "site:current-user:uid" ],
                  "nid_target" : [ "node:field-desk:nid" ],
                  "message_id" : { "value" : { "publish_report" : "publish_report" } },
                  "!publisher" : [ "site:current-user:name" ],
                  "!story_url" : [ "node:field_desk:url" ],
                  "!story" : [ "node:field_desk:title" ]
                }
              }
            ]
          }
        }
      ]
    }
  }');
  $items['rules_replies_to_a_comment'] = entity_import('rules_config', '{ "rules_replies_to_a_comment" : {
      "LABEL" : "Replies to a comment",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "checkdesk" ],
      "REQUIRES" : [ "rules", "heartbeat_rules", "rules_scheduler", "comment" ],
      "ON" : { "comment_insert" : [] },
      "IF" : [
        { "entity_is_of_type" : { "entity" : [ "comment:parent" ], "type" : "comment" } }
      ],
      "DO" : [
        { "heartbeat_activity_checkdesk_reply_to_comment" : {
            "nid" : [ "comment:parent:cid" ],
            "uid" : [ "comment:author:uid" ],
            "nid_target" : "0",
            "uid_target" : "0",
            "cid" : [ "comment:cid" ],
            "message_id" : { "value" : { "checkdesk_reply_to_comment" : "checkdesk_reply_to_comment" } },
            "!user_url" : [ "comment:author:url" ],
            "!username" : [ "comment:author:name" ],
            "!comment_url" : [ "comment:parent:url" ]
          }
        },
        { "schedule" : {
            "component" : "rules_notify_subscribed_users_reply_to_comment",
            "date" : "now",
            "param_comment" : [ "comment" ]
          }
        }
      ]
    }
  }');
  $items['rules_report_published_in_a_new_update'] = entity_import('rules_config', '{ "rules_report_published_in_a_new_update" : {
      "LABEL" : "Report published in a new update",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "checkdesk" ],
      "REQUIRES" : [ "rules", "heartbeat_rules", "rules_scheduler" ],
      "ON" : { "node_insert--post" : { "bundle" : "post" } },
      "IF" : [ { "NOT data_is_empty" : { "data" : [ "node:reports:0:nid" ] } } ],
      "DO" : [
        { "LOOP" : {
            "USING" : { "list" : [ "node:reports" ] },
            "ITEM" : { "report" : "Current report" },
            "DO" : [
              { "heartbeat_activity_checkdesk_report_published_in_update" : {
                  "nid" : [ "report:nid" ],
                  "uid" : [ "site:current-user:uid" ],
                  "nid_target" : [ "node:field-desk:nid" ],
                  "uid_target" : [ "report:author:uid" ],
                  "message_id" : { "value" : { "checkdesk_report_published_in_update" : "checkdesk_report_published_in_update" } },
                  "!report_url" : [ "report:url" ],
                  "!update_url" : [ "node:url" ]
                }
              },
              { "schedule" : {
                  "component" : "rules_notify_subscribed_users_report_published",
                  "date" : "now",
                  "param_node" : [ "node" ],
                  "param_report" : [ "report" ]
                }
              }
            ]
          }
        }
      ]
    }
  }');
  $items['rules_report_published_in_an_update'] = entity_import('rules_config', '{ "rules_report_published_in_an_update" : {
      "LABEL" : "Report published in an update",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "checkdesk" ],
      "REQUIRES" : [ "rules", "php", "heartbeat_rules", "rules_scheduler" ],
      "ON" : { "node_update" : [] },
      "IF" : [
        { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "post" : "post" } } } },
        { "NOT data_is_empty" : { "data" : [ "node:reports:0:nid" ] } },
        { "php_eval" : { "code" : "$wrapper = entity_metadata_wrapper(\\u0027node\\u0027, $node);\\r\\n$new = array();\\r\\nforeach ($wrapper-\\u003Ereports-\\u003EgetIterator() as $delta =\\u003E $report) {\\r\\n  $new[] = $report-\\u003Evalue()-\\u003Enid;\\r\\n}\\r\\n$wrapper = entity_metadata_wrapper(\\u0027node\\u0027, $node_unchanged);\\r\\n$old = array();\\r\\nforeach ($wrapper-\\u003Ereports-\\u003EgetIterator() as $delta =\\u003E $report) {\\r\\n  $old[] = $report-\\u003Evalue()-\\u003Enid;\\r\\n}\\r\\n$diff = array_diff($new, $old);\\r\\nreturn count($diff) \\u003E 0; " } }
      ],
      "DO" : [
        { "LOOP" : {
            "USING" : { "list" : [ "node:reports" ] },
            "ITEM" : { "report" : "Current report" },
            "DO" : [
              { "heartbeat_activity_checkdesk_report_published_in_update" : {
                  "nid" : [ "report:nid" ],
                  "uid" : [ "site:current-user:uid" ],
                  "nid_target" : [ "node:nid" ],
                  "uid_target" : [ "report:author:uid" ],
                  "message_id" : { "value" : { "checkdesk_report_published_in_update" : "checkdesk_report_published_in_update" } },
                  "!report_url" : [ "report:url" ],
                  "!update_url" : [ "node:url" ]
                }
              },
              { "schedule" : {
                  "component" : "rules_notify_subscribed_users_report_published",
                  "date" : "now",
                  "param_node" : [ "node" ],
                  "param_report" : [ "report" ]
                }
              }
            ]
          }
        }
      ]
    }
  }');
  $items['rules_report_suggested_to_a_story'] = entity_import('rules_config', '{ "rules_report_suggested_to_a_story" : {
      "LABEL" : "Report suggested to a story",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "checkdesk" ],
      "REQUIRES" : [ "rules", "heartbeat_rules", "rules_scheduler", "checkdesk_core" ],
      "ON" : { "node_insert--media" : { "bundle" : "media" } },
      "IF" : [ { "NOT data_is_empty" : { "data" : [ "node:field-stories:nid" ] } } ],
      "DO" : [
        { "heartbeat_activity_checkdesk_report_suggested_to_story" : {
            "nid" : "[node:nid]",
            "uid" : "[site:current-user:uid]",
            "nid_target" : [ "node:field-stories:nid" ],
            "uid_target" : "0",
            "message_id" : { "value" : { "checkdesk_report_suggested_to_story" : "checkdesk_report_suggested_to_story" } },
            "!user_url" : "[site:current-user:url]",
            "!username" : "[site:current-user:name]",
            "!report_url" : "[node:url]",
            "!story_url" : [ "node:field-stories:url" ],
            "!story" : [ "node:field-stories:title" ]
          }
        },
        { "schedule" : {
            "component" : "rules_notify_subscribed_users_report_suggested_to_story",
            "date" : "now",
            "param_node" : [ "node" ],
            "param_list_item" : [ "node:field-stories" ]
          }
        },
        { "checkdesk_core_actions_set_followers" : { "node" : [ "node:field-stories" ] } }
      ]
    }
  }');
  $items['rules_report_was_flagged_under_fact_checking_'] = entity_import('rules_config', '{ "rules_report_was_flagged_under_fact_checking_" : {
      "LABEL" : "Fact-checking turned on for report",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "checkdesk" ],
      "REQUIRES" : [ "rules", "php", "heartbeat_rules", "rules_scheduler", "flag" ],
      "ON" : { "flag_flagged_factcheck_journalist" : [] },
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "flagged-node" ],
            "type" : { "value" : { "media" : "media" } }
          }
        }
      ],
      "DO" : [
        { "heartbeat_activity_checkdesk_fact_checking_on" : {
            "nid" : [ "flagged-node:nid" ],
            "uid" : [ "flagging-user:uid" ],
            "nid_target" : "\\u003C?php\\r\\nif (isset($flagged_node-\\u003Efield_stories[LANGUAGE_NONE][0][\\u0027target_id\\u0027])) {\\r\\n     echo $flagged_node-\\u003Efield_stories[LANGUAGE_NONE][0][\\u0027target_id\\u0027];\\r\\n}\\r\\nelse {\\r\\n    echo 0;\\r\\n}\\r\\n?\\u003E",
            "message_id" : { "value" : { "checkdesk_fact_checking_on" : "checkdesk_fact_checking_on" } },
            "!user_url" : [ "flagging-user:url" ],
            "!username" : [ "flagging-user:name" ],
            "!report_url" : [ "flagged-node:url" ]
          }
        },
        { "schedule" : {
            "component" : "rules_notify_subscribed_users",
            "date" : "now",
            "param_flagged_node" : [ "flagged-node" ],
            "param_flagging_user" : [ "flagging-user" ]
          }
        },
        { "data_set" : { "data" : [ "flagged-node:field-rating" ], "value" : "2" } },
        { "php_eval" : { "code" : "$flagged_node-\\u003Eskip_status_change_notification = TRUE;" } }
      ]
    }
  }');
  $items['rules_report_was_flagged_under_graphic_content_'] = entity_import('rules_config', '{ "rules_report_was_flagged_under_graphic_content_" : {
      "LABEL" : "Report was flagged",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "checkdesk" ],
      "REQUIRES" : [
        "rules",
        "php",
        "heartbeat_rules",
        "rules_scheduler",
        "checkdesk_core",
        "flag"
      ],
      "ON" : {
        "flag_flagged_factcheck" : [],
        "flag_flagged_graphic_journalist" : [],
        "flag_flagged_spam" : [],
        "flag_flagged_graphic" : [],
        "flag_flagged_delete" : []
      },
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "flagged-node" ],
            "type" : { "value" : { "media" : "media" } }
          }
        }
      ],
      "DO" : [
        { "heartbeat_activity_checkdesk_flag_report" : {
            "nid" : "[flagged-node:nid]",
            "uid" : "[flagging-user:uid]",
            "nid_target" : "\\u003C?php\\r\\nif (isset($flagged_node-\\u003Efield_stories[LANGUAGE_NONE][0][\\u0027target_id\\u0027])) {\\r\\n     echo $flagged_node-\\u003Efield_stories[LANGUAGE_NONE][0][\\u0027target_id\\u0027];\\r\\n}\\r\\nelse {\\r\\n    echo 0;\\r\\n}\\r\\n?\\u003E",
            "uid_target" : [ "flagging-user:uid" ],
            "message_id" : { "value" : { "checkdesk_flag_report" : "checkdesk_flag_report" } },
            "!flag_author_url" : [ "flagging-user:url" ],
            "!flag_author_name" : [ "flagging-user:name" ],
            "!report_url" : [ "flagged-node:url" ],
            "!flag_type" : "\\u003C?php print $flag-\\u003Etitle; ?\\u003E"
          }
        },
        { "schedule" : {
            "component" : "rules_notify_subscribed_users_report_was_flagged",
            "date" : "now",
            "param_flagged_node" : [ "flagged-node" ],
            "param_flagging_user" : [ "flagging-user" ],
            "param_flag" : "[flag:name]",
            "param_reason" : "[flagging:field_reason]"
          }
        },
        { "checkdesk_core_actions_set_followers" : { "node" : [ "flagged-node:field-stories" ] } }
      ]
    }
  }');
  $items['rules_status_report'] = entity_import('rules_config', '{ "rules_status_report" : {
      "LABEL" : "Status report",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "checkdesk" ],
      "REQUIRES" : [ "rules", "php", "heartbeat_rules", "rules_scheduler" ],
      "ON" : { "node_update" : [] },
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
            "uid" : [ "site:current-user:uid" ],
            "nid_target" : "\\u003C?php\\r\\nif (isset($node-\\u003Efield_stories[LANGUAGE_NONE][0][\\u0027target_id\\u0027])) {\\r\\n     echo $node-\\u003Efield_stories[LANGUAGE_NONE][0][\\u0027target_id\\u0027];\\r\\n}\\r\\nelse {\\r\\n    echo 0;\\r\\n}\\r\\n?\\u003E",
            "message_id" : { "value" : { "status_report" : "status_report" } },
            "!editor_url" : [ "site:current-user:url" ],
            "!editor" : [ "site:current-user:name" ],
            "!report_url" : [ "node:url" ],
            "!status" : [ "node:field-rating:name" ]
          }
        },
        { "schedule" : {
            "component" : "rules_notify_follower_users_change_report_status",
            "date" : "now",
            "param_node" : [ "node" ],
            "param_story" : [ "node:field-stories" ],
            "param_current_user" : [ "site:current-user" ]
          }
        }
      ]
    }
  }');
  $items['rules_unfollow_story'] = entity_import('rules_config', '{ "rules_unfollow_story" : {
      "LABEL" : "unfollow story",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "checkdesk" ],
      "REQUIRES" : [ "rules", "php", "flag" ],
      "ON" : { "flag_unflagged_follow_story" : [] },
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "flagged-node" ],
            "type" : { "value" : { "discussion" : "discussion" } }
          }
        }
      ],
      "DO" : [
        { "php_eval" : { "code" : "_checkdesk_delete_follow_story_activity($flagged_node-\\u003Enid);" } }
      ]
    }
  }');
  $items['rules_user_banned_and_comments_deleted'] = entity_import('rules_config', '{ "rules_user_banned_and_comments_deleted" : {
      "LABEL" : "User banned and comments deleted",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
      "OWNER" : "rules",
      "TAGS" : [ "checkdesk" ],
      "REQUIRES" : [ "rules" ],
      "ON" : { "user_update" : [] },
      "IF" : [
        { "data_is" : { "data" : [ "account:status" ], "value" : "0" } },
        { "data_is" : { "data" : [ "account-unchanged:status" ], "value" : "1" } }
      ],
      "DO" : [
        { "mail" : {
            "to" : [ "account:mail" ],
            "subject" : "Banned",
            "message" : "Your comment was deleted and you have been banned by a moderator for violating terms of service or comment policy. If you think this decision was an error you can contact us at: [site:mail]\\r\\nNote from moderator:\\r\\n\\r\\nRegards,\\r\\n[site:name]",
            "from" : "[site:mail]",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_user_follow_story'] = entity_import('rules_config', '{ "rules_user_follow_story" : {
      "LABEL" : "User follow story",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "checkdesk" ],
      "REQUIRES" : [ "rules", "php", "heartbeat_rules", "flag" ],
      "ON" : { "flag_flagged_follow_story" : [] },
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "flagged-node" ],
            "type" : { "value" : { "discussion" : "discussion" } }
          }
        },
        { "php_eval" : { "code" : "if (isset($flag-\\u003Eskip_heartbeat_log) \\u0026\\u0026 $flag-\\u003Eskip_heartbeat_log) {\\r\\n    return FALSE;\\r\\n}\\r\\nreturn TRUE;" } }
      ],
      "DO" : [
        { "heartbeat_activity_checkdesk_follow_story" : {
            "nid" : [ "flagged-node:nid" ],
            "uid" : [ "flagging-user:uid" ],
            "nid_target" : [ "flagged-node:nid" ],
            "message_id" : { "value" : { "checkdesk_follow_story" : "checkdesk_follow_story" } },
            "!flag_author_url" : [ "flagging-user:url" ],
            "!flag_author_name" : [ "flagging-user:name" ]
          }
        }
      ]
    }
  }');
  return $items;
}
