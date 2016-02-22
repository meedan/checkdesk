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
  $items['checkdesk_core_feature_notify_subscribed_update_story_draft'] = entity_import('rules_config', '{ "checkdesk_core_feature_notify_subscribed_update_story_draft" : {
      "LABEL" : "Notify subscribed users: update story (draft)",
      "PLUGIN" : "action set",
      "OWNER" : "rules",
      "TAGS" : [ "checkdesk" ],
      "REQUIRES" : [ "php", "rules", "meedan_notifications" ],
      "USES VARIABLES" : {
        "story" : { "label" : "Story", "type" : "node" },
        "author" : { "label" : "Author", "type" : "user" }
      },
      "ACTION SET" : [
        { "notify_subscribers" : {
            "object" : [ "story" ],
            "event" : "email_update_draft_story",
            "subject" : "Draft story updated",
            "message" : "Hello !recipient_name,\\r\\n\\r\\n!author has created a new draft for story !story.\\r\\n\\r\\n\\u003Ca href=\\u0022!url\\u0022\\u003EClick here \\u003C\\/a\\u003E to edit this draft.\\r\\n",
            "actor" : [ "author" ],
            "t_args" : "\\u003C?php\\r\\nreturn serialize(array(\\u0027!author\\u0027 =\\u003E user_load($author-\\u003Euid)-\\u003Ename, \\u0027!url\\u0027 =\\u003E url(\\u0027node\\/\\u0027 . $story-\\u003Enid . \\u0027\\/edit\\u0027, array(\\u0027absolute\\u0027 =\\u003E TRUE, \\u0027alias\\u0027 =\\u003E TRUE)), \\u0027!story\\u0027 =\\u003E node_load($story-\\u003Enid)-\\u003Etitle, \\u0027!site\\u0027 =\\u003E variable_get(\\u0027site_name\\u0027, \\u0027Checkdesk\\u0027), \\u0027!recipient_name\\u0027 =\\u003E \\u0027[recipient:name]\\u0027, \\u0027!recipient_url\\u0027 =\\u003E \\u0027[recipient:edit-url]\\u0027)); \\r\\n?\\u003E"
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
  $items['checkdesk_core_feature_notify_subscribed_users_story_revision'] = entity_import('rules_config', '{ "checkdesk_core_feature_notify_subscribed_users_story_revision" : {
      "LABEL" : "Notify subscribed users: story revision",
      "PLUGIN" : "action set",
      "OWNER" : "rules",
      "TAGS" : [ "checkdesk" ],
      "REQUIRES" : [ "php", "rules", "meedan_notifications" ],
      "USES VARIABLES" : { "story" : { "label" : "Story", "type" : "node" } },
      "ACTION SET" : [
        { "notify_subscribers" : {
            "object" : [ "story" ],
            "event" : "email_publish_own_story_revision",
            "subject" : "A revision to your story has been published",
            "message" : "Hello !recipient_name,\\r\\n\\r\\nA revision to your \\u003Ca href=\\u0022!url\\u0022\\u003Estory\\u003C\\/a\\u003Ehas been published.\\r\\n",
            "actor" : [ "site:current-user" ],
            "t_args" : "\\u003C?php\\r\\nreturn serialize(array(\\u0027!author\\u0027 =\\u003E user_load($story-\\u003Euid)-\\u003Ename, \\u0027!url\\u0027 =\\u003E url(\\u0027node\\/\\u0027 . $story-\\u003Enid, array(\\u0027absolute\\u0027 =\\u003E TRUE, \\u0027alias\\u0027 =\\u003E TRUE)), \\u0027!site\\u0027 =\\u003E variable_get(\\u0027site_name\\u0027, \\u0027Checkdesk\\u0027), \\u0027!recipient_name\\u0027 =\\u003E \\u0027[recipient:name]\\u0027, \\u0027!recipient_url\\u0027 =\\u003E \\u0027[recipient:edit-url]\\u0027)); \\r\\n?\\u003E"
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
      "USES VARIABLES" : {
        "story" : { "label" : "Story", "type" : "node" },
        "author" : { "label" : "Author", "type" : "user" }
      },
      "ACTION SET" : [
        { "notify_subscribers" : {
            "object" : [ "story" ],
            "event" : "email_update_story",
            "subject" : "Existing story updated",
            "message" : "Hello !recipient_name,\\r\\n\\r\\n!author has updated the story !story.\\r\\n\\r\\n\\u003Ca href=\\u0022!url\\u0022\\u003EClick here \\u003C\\/a\\u003E to view or update this story.\\r\\n",
            "actor" : [ "author" ],
            "t_args" : "\\u003C?php\\r\\nreturn serialize(array(\\u0027!author\\u0027 =\\u003E user_load($author-\\u003Euid)-\\u003Ename, \\u0027!url\\u0027 =\\u003E url(\\u0027node\\/\\u0027 . $story-\\u003Enid, array(\\u0027absolute\\u0027 =\\u003E TRUE, \\u0027alias\\u0027 =\\u003E TRUE)), \\u0027!story\\u0027 =\\u003E node_load($story-\\u003Enid)-\\u003Etitle, \\u0027!site\\u0027 =\\u003E variable_get(\\u0027site_name\\u0027, \\u0027Checkdesk\\u0027), \\u0027!recipient_name\\u0027 =\\u003E \\u0027[recipient:name]\\u0027, \\u0027!recipient_url\\u0027 =\\u003E \\u0027[recipient:edit-url]\\u0027)); \\r\\n?\\u003E"
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
      "REQUIRES" : [ "rules", "php", "heartbeat_rules", "checkdesk_core" ],
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
            "!update_url" : "\\u003C?php\\r\\necho  url(\\u0027node\\/\\u0027 . $node-\\u003Efield_desk[LANGUAGE_NONE][0][\\u0027target_id\\u0027], array(\\u0027fragment\\u0027 =\\u003E \\u0027update-\\u0027.$node-\\u003Enid, \\u0027absolute\\u0027 =\\u003E TRUE, \\u0027alias\\u0027 =\\u003E TRUE));\\r\\n?\\u003E",
            "!story_url" : [ "node:field-desk:url" ],
            "!story" : [ "node:field-desk:title" ]
          }
        },
        { "checkdesk_core_actions_set_followers" : { "node" : [ "node:field-desk" ] } },
        { "php_eval" : { "code" : "_checkdesk_delete_heartbeat_activity($node_unchanged);" } }
      ]
    }
  }');
  $items['checkdesk_core_feature_update_existing_draft_story'] = entity_import('rules_config', '{ "checkdesk_core_feature_update_existing_draft_story" : {
      "LABEL" : "Update existing draft story",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "checkdesk" ],
      "REQUIRES" : [ "revisioning", "heartbeat_rules", "rules", "rules_scheduler" ],
      "ON" : {
        "node_update--discussion" : { "bundle" : "discussion" },
        "node_insert--discussion" : { "bundle" : "discussion" }
      },
      "IF" : [ { "revisioning_node_has_pending" : { "node" : [ "node" ] } } ],
      "DO" : [
        { "heartbeat_activity_checkdesk_update_draft_story" : {
            "nid" : [ "node:nid" ],
            "uid" : [ "site:current-user:uid" ],
            "nid_target" : [ "node:nid" ],
            "message_id" : { "value" : { "checkdesk_update_draft_story" : "checkdesk_update_draft_story" } },
            "!user_url" : [ "site:current-user:url" ],
            "!username" : [ "site:current-user:name" ],
            "!story_url" : [ "node:url" ],
            "!story" : [ "node:title" ]
          }
        },
        { "schedule" : {
            "component" : "checkdesk_core_feature_notify_subscribed_update_story_draft",
            "date" : "now",
            "param_story" : [ "node" ],
            "param_author" : [ "site:current-user" ]
          }
        }
      ]
    }
  }');
  $items['checkdesk_core_feature_update_existing_story'] = entity_import('rules_config', '{ "checkdesk_core_feature_update_existing_story" : {
      "LABEL" : "Update existing story",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "checkdesk" ],
      "REQUIRES" : [
        "rules",
        "revisioning",
        "checkdesk_notifications",
        "heartbeat_rules",
        "rules_scheduler"
      ],
      "ON" : { "node_update--discussion" : { "bundle" : "discussion" } },
      "IF" : [
        { "node_is_published" : { "node" : [ "node" ] } },
        { "NOT revisioning_node_has_pending" : { "node" : [ "node" ] } },
        { "NOT checkdesk_notifications_first_publish" : { "node" : [ "node" ] } }
      ],
      "DO" : [
        { "heartbeat_activity_checkdesk_update_story" : {
            "nid" : [ "node:nid" ],
            "uid" : [ "site:current-user:uid" ],
            "nid_target" : [ "node:nid" ],
            "message_id" : { "value" : { "checkdesk_update_story" : "checkdesk_update_story" } },
            "!user_url" : [ "site:current-user:url" ],
            "!username" : [ "site:current-user:name" ],
            "!story_url" : [ "node:url" ],
            "!story" : [ "node:title" ]
          }
        },
        { "schedule" : {
            "component" : "checkdesk_core_feature_notify_subscribed_users_update_story",
            "date" : "now",
            "param_story" : [ "node" ],
            "param_author" : [ "site:current-user" ]
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
  $items['rules_new_story'] = entity_import('rules_config', '{ "rules_new_story" : {
      "LABEL" : "New story",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "checkdesk" ],
      "REQUIRES" : [
        "revisioning",
        "checkdesk_notifications",
        "heartbeat_rules",
        "rules",
        "rules_scheduler",
        "checkdesk_core"
      ],
      "ON" : {
        "node_insert--discussion" : { "bundle" : "discussion" },
        "node_update--discussion" : { "bundle" : "discussion" }
      },
      "IF" : [
        { "NOT revisioning_node_has_pending" : { "node" : [ "node" ] } },
        { "checkdesk_notifications_first_publish" : { "node" : [ "node" ] } }
      ],
      "DO" : [
        { "heartbeat_activity_checkdesk_add_story" : {
            "nid" : [ "node:nid" ],
            "uid" : [ "site:current-user:uid" ],
            "nid_target" : [ "node:nid" ],
            "message_id" : { "value" : { "checkdesk_add_story" : "checkdesk_add_story" } },
            "!user_url" : [ "site:current-user:url" ],
            "!username" : [ "site:current-user:name" ],
            "!story_url" : [ "node:url" ],
            "!story" : [ "node:title" ]
          }
        },
        { "schedule" : {
            "component" : "checkdesk_core_feature_notify_subscribed_users_new_story",
            "date" : "now",
            "param_story" : [ "node" ]
          }
        },
        { "checkdesk_core_actions_set_followers" : { "node" : [ "node" ] } }
      ]
    }
  }');
  $items['rules_new_update'] = entity_import('rules_config', '{ "rules_new_update" : {
      "LABEL" : "New update",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "checkdesk" ],
      "REQUIRES" : [ "rules", "php", "heartbeat_rules", "rules_scheduler", "checkdesk_core" ],
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
            "!update_url" : "\\u003C?php\\r\\necho url(\\u0027node\\/\\u0027 . $node-\\u003Efield_desk[LANGUAGE_NONE][0][\\u0027target_id\\u0027], array(\\u0027fragment\\u0027 =\\u003E \\u0027update-\\u0027.$node-\\u003Enid, \\u0027absolute\\u0027 =\\u003E TRUE, \\u0027alias\\u0027 =\\u003E TRUE));\\r\\n?\\u003E",
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
            "t_args" : "\\u003C?php\\r\\nreturn serialize(array(\\u0027!title\\u0027 =\\u003E $story-\\u003Etitle, \\u0027!url\\u0027 =\\u003E url(\\u0027node\\/\\u0027 . $story-\\u003Enid, array(\\u0027fragment\\u0027 =\\u003E \\u0027update-\\u0027.$node-\\u003Enid, \\u0027absolute\\u0027 =\\u003E TRUE, \\u0027alias\\u0027 =\\u003E TRUE)), \\u0027!site\\u0027 =\\u003E variable_get(\\u0027site_name\\u0027, \\u0027Checkdesk\\u0027), \\u0027!recipient_name\\u0027 =\\u003E \\u0027[recipient:name]\\u0027, \\u0027!recipient_url\\u0027 =\\u003E \\u0027[recipient:edit-url]\\u0027)); \\r\\n?\\u003E"
          }
        },
        { "notify_subscribers" : {
            "object" : [ "node" ],
            "event" : "email_update_on_story_i_followed",
            "subject" : "New update",
            "message" : "Hello !recipient_name,\\r\\n\\r\\nStory \\u0022!title\\u0022 which you followed has a \\u003Ca href=\\u0022!url\\u0022\\u003Enew update\\u003C\\/a\\u003E.",
            "actor" : [ "node:author" ],
            "t_args" : "\\u003C?php\\r\\nreturn serialize(array(\\u0027!title\\u0027 =\\u003E $story-\\u003Etitle, \\u0027!url\\u0027 =\\u003E url(\\u0027node\\/\\u0027 . $story-\\u003Enid, array(\\u0027fragment\\u0027 =\\u003E \\u0027update-\\u0027.$node-\\u003Enid, \\u0027absolute\\u0027 =\\u003E TRUE, \\u0027alias\\u0027 =\\u003E TRUE)), \\u0027!site\\u0027 =\\u003E variable_get(\\u0027site_name\\u0027, \\u0027Checkdesk\\u0027), \\u0027!recipient_name\\u0027 =\\u003E \\u0027[recipient:name]\\u0027, \\u0027!recipient_url\\u0027 =\\u003E \\u0027[recipient:edit-url]\\u0027)); \\r\\n?\\u003E"
          }
        },
        { "notify_subscribers" : {
            "object" : [ "node" ],
            "event" : "email_new_update",
            "subject" : "An update has been added to a story",
            "message" : "Hello !recipient_name,\\r\\n\\r\\n!author has added a \\u003Ca href=\\u0022!url\\u0022\\u003Enew update\\u003C\\/a\\u003E to the story \\u0022!title\\u0022.\\r\\n",
            "actor" : [ "node:author" ],
            "t_args" : "\\u003C?php\\r\\nreturn serialize(array(\\u0027!author\\u0027 =\\u003E user_load($node-\\u003Euid)-\\u003Ename, \\u0027!title\\u0027 =\\u003E $story-\\u003Etitle, \\u0027!url\\u0027 =\\u003E  url(\\u0027node\\/\\u0027 . $story-\\u003Enid, array(\\u0027fragment\\u0027 =\\u003E \\u0027update-\\u0027.$node-\\u003Enid, \\u0027absolute\\u0027 =\\u003E TRUE, \\u0027alias\\u0027 =\\u003E TRUE)), \\u0027!site\\u0027 =\\u003E variable_get(\\u0027site_name\\u0027, \\u0027Checkdesk\\u0027), \\u0027!recipient_name\\u0027 =\\u003E \\u0027[recipient:name]\\u0027, \\u0027!recipient_url\\u0027 =\\u003E \\u0027[recipient:edit-url]\\u0027)); \\r\\n?\\u003E"
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
  $items['rules_publish_story_revision'] = entity_import('rules_config', '{ "rules_publish_story_revision" : {
      "LABEL" : "Publish story revision",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "checkdesk" ],
      "REQUIRES" : [ "rules", "php", "heartbeat_rules", "rules_scheduler" ],
      "ON" : { "node_update--discussion" : { "bundle" : "discussion" } },
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "discussion" : "discussion" } }
          }
        },
        { "user_has_role" : { "account" : [ "node:author" ], "roles" : { "value" : { "4" : "4" } } } },
        { "php_eval" : { "code" : "$existing_node = node_load($node-\\u003Enid, $node-\\u003Evid);\\r\\nwatchdog(\\u0027Sawy-node\\u0027, \\u0027\\u003Cpre\\u003E\\u0027. print_r($existing_node, true) .\\u0027\\u003C\\/pre\\u003E\\u0027);\\r\\nif ($existing_node-\\u003Eis_current) {\\r\\n   return TRUE;\\r\\n}\\r\\nreturn FALSE;" } }
      ],
      "DO" : [
        { "heartbeat_activity_checkdesk_publish_own_story_revision" : {
            "nid" : [ "node:nid" ],
            "uid" : [ "site:current-user:uid" ],
            "uid_target" : [ "node:author:uid" ],
            "message_id" : { "value" : { "checkdesk_publish_own_story_revision" : "checkdesk_publish_own_story_revision" } },
            "!story_url" : [ "node:url" ],
            "!story" : [ "node:title" ]
          }
        },
        { "schedule" : {
            "component" : "checkdesk_core_feature_notify_subscribed_users_story_revision",
            "date" : "now",
            "param_story" : [ "node" ]
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
