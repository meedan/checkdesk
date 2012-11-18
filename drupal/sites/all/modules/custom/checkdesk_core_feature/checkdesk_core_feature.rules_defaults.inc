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
  $items['rules_comment_deleted'] = entity_import('rules_config', '{ "rules_comment_deleted" : {
      "LABEL" : "Comment deleted",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "checkdesk" ],
      "REQUIRES" : [ "rules", "comment" ],
      "ON" : [ "comment_delete" ],
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
      "TAGS" : [ "checkdesk" ],
      "REQUIRES" : [ "rules", "heartbeat_rules", "meedan_notifications", "comment" ],
      "ON" : [ "comment_insert" ],
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
            "nid_target" : "0",
            "uid_target" : "0",
            "cid" : [ "comment:cid" ],
            "message_id" : { "value" : { "checkdesk_comment_on_report" : "checkdesk_comment_on_report" } },
            "!user_url" : [ "comment:author:url" ],
            "!username" : [ "comment:author:name" ],
            "!report_url" : [ "comment:node:url" ],
            "!report_title" : [ "comment:node:title" ]
          }
        },
        { "notify_subscribers" : {
            "object" : [ "comment:node" ],
            "event" : "email_comment_on_report",
            "subject" : "New footnote",
            "message" : "Hello [recipient:name],\\r\\n\\r\\n[comment:author:name] has added footnote to the following report \\u0022[comment:node:title]\\u0022:\\r\\n\\r\\n[comment:body]\\r\\n\\r\\n\\u003Ca href=\\u0022[comment:node:url]\\u0022\\u003EClick here\\u003C\\/a\\u003E to respond or change the status of the report.\\r\\n\\r\\nYou can edit your notification settings from your \\u003Ca href=\\u0022[recipient:edit-url]\\u0022\\u003Eprofile page\\u003C\\/a\\u003E.\\r\\n\\r\\nThis was an auto-generated email from [site:name]; please do not respond directly to this email."
          }
        }
      ]
    }
  }');
  $items['rules_comment_on_an_update'] = entity_import('rules_config', '{ "rules_comment_on_an_update" : {
      "LABEL" : "Comment on an update",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "checkdesk" ],
      "REQUIRES" : [ "rules", "heartbeat_rules", "meedan_notifications", "comment" ],
      "ON" : [ "comment_insert" ],
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
            "nid_target" : "0",
            "uid_target" : "0",
            "cid" : [ "comment:cid" ],
            "message_id" : { "value" : { "checkdesk_comment_on_update" : "checkdesk_comment_on_update" } },
            "!user_url" : [ "comment:author:url" ],
            "!username" : [ "comment:author:name" ],
            "!update_url" : [ "comment:node:url" ],
            "!update_title" : [ "comment:node:title" ]
          }
        },
        { "notify_subscribers" : {
            "object" : [ "comment" ],
            "event" : "email_comment_on_update",
            "subject" : "Comment on an update",
            "message" : "Hello [recipient:name],\\r\\n\\r\\n[comment:author:name] has \\u003Ca href=\\u0022[comment:url]\\u0022\\u003Ecommented\\u003C\\/a\\u003E on \\u003Ca href=\\u0022[comment:node:url]\\u0022\\u003E[comment:node:title]\\u003C\\/a\\u003E:\\r\\n[comment:body]\\r\\n\\r\\nYou can edit your notification settings from your \\u003Ca href=\\u0022[recipient:edit-url]\\u0022\\u003Eprofile page\\u003C\\/a\\u003E.\\r\\n\\r\\nThis was an auto-generated email from [site:name]; please do not respond directly to this email."
          }
        }
      ]
    }
  }');
  $items['rules_existing_report_suggested_to_a_story'] = entity_import('rules_config', '{ "rules_existing_report_suggested_to_a_story" : {
      "LABEL" : "Existing report suggested to a story",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "checkdesk" ],
      "REQUIRES" : [ "rules", "php", "heartbeat_rules", "meedan_notifications" ],
      "ON" : [ "node_update" ],
      "IF" : [
        { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "media" : "media" } } } },
        { "entity_has_field" : { "entity" : [ "node" ], "field" : "field_stories" } },
        { "php_eval" : { "code" : "$obj = entity_metadata_wrapper(\\u0027node\\u0027, $node);\\r\\n$new = array();\\r\\n$values = $obj-\\u003Efield_stories-\\u003Evalue();\\r\\nforeach ($values as $value) {\\r\\n  $new[] = $value-\\u003Enid;\\r\\n}\\r\\n$obj = entity_metadata_wrapper(\\u0027node\\u0027, $node_unchanged);\\r\\n$old = array();\\r\\n$values = $obj-\\u003Efield_stories-\\u003Evalue();\\r\\nforeach ($values as $value) {\\r\\n  $old[] = $value-\\u003Enid;\\r\\n}\\r\\n$diff = array_diff($new, $old);\\r\\nreturn count($diff) \\u003E 0;" } }
      ],
      "DO" : [
        { "LOOP" : {
            "USING" : { "list" : [ "node:field-stories" ] },
            "ITEM" : { "list_item" : "Current list item" },
            "DO" : [
              { "heartbeat_activity_checkdesk_report_suggested_to_story" : {
                  "nid" : "[node:nid]",
                  "uid" : "[site:current-user:uid]",
                  "uid_target" : "0",
                  "message_id" : { "value" : { "checkdesk_report_suggested_to_story" : "checkdesk_report_suggested_to_story" } },
                  "!user_url" : "[site:current-user:url]",
                  "!username" : "[site:current-user:name]",
                  "!report_url" : "[node:url]",
                  "!story_url" : "[list-item:url]",
                  "!story" : "[list-item:title]"
                }
              },
              { "notify_subscribers" : {
                  "object" : [ "node" ],
                  "event" : "email_report_suggested",
                  "subject" : "Report suggested to story",
                  "message" : "Hello [recipient:name],\\r\\n\\r\\n[node:author:name] has suggested this report \\u0022[node:title]\\u0022 to this story \\u0022[list-item:title]\\u0022.\\r\\n\\r\\n\\u003Ca href=\\u0022[list-item:url]\\u0022\\u003EClick here\\u003C\\/a\\u003E to compose a new update to the story using that report.\\r\\n\\r\\nYou can edit your notification settings from your \\u003Ca href=\\u0022[recipient:edit-url]\\u0022\\u003Eprofile page\\u003C\\/a\\u003E.\\r\\n\\r\\nThis was an auto-generated email from [site:name], please do not respond directly to this email."
                }
              }
            ]
          }
        }
      ]
    }
  }');
  $items['rules_fact_checking_status_changed'] = entity_import('rules_config', '{ "rules_fact_checking_status_changed" : {
      "LABEL" : "Fact-checking status changed",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "checkdesk" ],
      "REQUIRES" : [ "rules", "heartbeat_rules", "meedan_notifications" ],
      "ON" : [ "node_update" ],
      "IF" : [
        { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "media" : "media" } } } },
        { "entity_has_field" : { "entity" : [ "node" ], "field" : "field_rating" } },
        { "NOT data_is" : {
            "data" : [ "node:field-rating:tid" ],
            "value" : [ "node-unchanged:field-rating:tid" ]
          }
        }
      ],
      "DO" : [
        { "heartbeat_activity_checkdesk_fact_checking_set" : {
            "nid" : [ "node:nid" ],
            "uid" : [ "site:current-user:uid" ],
            "nid_target" : "0",
            "uid_target" : "0",
            "message_id" : { "value" : { "checkdesk_fact_checking_set" : "checkdesk_fact_checking_set" } },
            "!user_url" : [ "site:current-user:uid" ],
            "!username" : [ "site:current-user:name" ],
            "!report_url" : [ "node:url" ],
            "!fact_checking_status" : [ "node:field-rating:name" ]
          }
        },
        { "notify_subscribers" : {
            "object" : [ "node" ],
            "event" : "email_fact_checking_set",
            "subject" : "Fact-checking status changed",
            "message" : "Hello [recipient:name],\\r\\n\\r\\n[site:current-user:name] has changed the fact-checking status for a \\u003Ca href=\\u0022[node:url]\\u0022\\u003Ereport\\u003C\\/a\\u003E you submitted to [node:field-rating].\\r\\n\\r\\nYou can edit your notification settings from your \\u003Ca href=\\u0022[recipient:edit-url]\\u0022\\u003Eprofile page\\u003C\\/a\\u003E.\\r\\n\\r\\nThis was an auto-generated email from [site:name]; please do not respond directly to this email."
          }
        },
        { "heartbeat_activity_checkdesk_fact_status_changed_for_commenter" : {
            "nid" : [ "node:nid" ],
            "uid" : [ "site:current-user:uid" ],
            "nid_target" : "0",
            "uid_target" : "0",
            "message_id" : { "value" : { "checkdesk_fact_status_changed_for_commenter" : "checkdesk_fact_status_changed_for_commenter" } },
            "!user_url" : [ "site:current-user:uid" ],
            "!username" : [ "site:current-user:name" ],
            "!report_url" : [ "node:url" ],
            "!fact_checking_status" : [ "node:field-rating:name" ]
          }
        },
        { "notify_subscribers" : {
            "object" : [ "node" ],
            "event" : "email_fact_status_changed_for_commenter",
            "subject" : "Fact-checking status changed",
            "message" : "Hello [recipient:name],\\r\\n\\r\\n[site:current-user:name] has changed the fact-checking status for a \\u003Ca href=\\u0022[node:url]\\u0022\\u003Ereport\\u003C\\/a\\u003E you added footnote to to [node:field-rating].\\r\\n\\r\\nYou can edit your notification settings from your \\u003Ca href=\\u0022[recipient:edit-url]\\u0022\\u003Eprofile page\\u003C\\/a\\u003E.\\r\\n\\r\\nThis was an auto-generated email from [site:name]; please do not respond directly to this email."
          }
        }
      ]
    }
  }');
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
  $items['rules_new_update'] = entity_import('rules_config', '{ "rules_new_update" : {
      "LABEL" : "New update",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "checkdesk" ],
      "REQUIRES" : [ "rules", "heartbeat_rules", "meedan_notifications" ],
      "ON" : [ "node_insert" ],
      "IF" : [
        { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "post" : "post" } } } }
      ],
      "DO" : [
        { "heartbeat_activity_checkdesk_new_update_on_story_i_commented_on_update" : {
            "nid" : [ "node:nid" ],
            "uid" : [ "node:author:uid" ],
            "nid_target" : [ "node:field-desk:nid" ],
            "uid_target" : "0",
            "message_id" : { "value" : { "checkdesk_new_update_on_story_i_commented_on_update" : "checkdesk_new_update_on_story_i_commented_on_update" } },
            "!story_url" : [ "node:field-desk:url" ],
            "!story_title" : [ "node:field-desk:title" ],
            "!update_url" : [ "node:url" ]
          }
        },
        { "notify_subscribers" : {
            "object" : [ "node:field-desk" ],
            "event" : "email_update_on_story_i_commented_on_update",
            "subject" : "New update",
            "message" : "Hello [recipient:name],\\r\\n\\r\\nStory \\u0022[node:field-desk:title]\\u0022 which you commented on has a \\u003Ca href=\\u0022[node:url]\\u0022\\u003Enew update\\u003C\\/a\\u003E.\\r\\n\\r\\nYou can edit your notification settings from your \\u003Ca href=\\u0022[recipient:edit-url]\\u0022\\u003Eprofile page\\u003C\\/a\\u003E.\\r\\n\\r\\nThis was an auto-generated email from [site:name]; please do not respond directly to this email."
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
  $items['rules_replies_to_a_comment'] = entity_import('rules_config', '{ "rules_replies_to_a_comment" : {
      "LABEL" : "Replies to a comment",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "checkdesk" ],
      "REQUIRES" : [ "rules", "heartbeat_rules", "meedan_notifications", "comment" ],
      "ON" : [ "comment_insert" ],
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
        { "notify_subscribers" : {
            "object" : [ "comment" ],
            "event" : "email_reply_to_comment",
            "subject" : "Comment replied",
            "message" : "Hello [recipient:name],\\r\\n\\r\\n[comment:author:name] has replied to your comment:\\r\\n\\r\\n[comment:body]\\r\\n\\r\\n\\u003Ca href=\\u0022[comment:url]\\u0022\\u003EClick here\\u003C\\/a\\u003E OR reply to this email to respond. This was an auto-generated email from [site:name]."
          }
        }
      ]
    }
  }');
  $items['rules_report_published_in_a_new_update'] = entity_import('rules_config', '{ "rules_report_published_in_a_new_update" : {
      "LABEL" : "Report published in a new update",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "checkdesk" ],
      "REQUIRES" : [ "rules", "heartbeat_rules", "meedan_notifications" ],
      "ON" : [ "node_insert" ],
      "IF" : [
        { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "post" : "post" } } } },
        { "NOT data_is_empty" : { "data" : [ "node:reports:0:nid" ] } }
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
              { "notify_subscribers" : {
                  "object" : [ "report" ],
                  "event" : "email_report_published_in_update",
                  "subject" : "Report published",
                  "message" : "Hello [recipient:name],\\r\\n\\r\\nA \\u003Ca href=\\u0022[report:url]\\u0022\\u003Ereport\\u003C\\/a\\u003E which you have submitted has been published in an \\u003Ca href=\\u0022[node:url]\\u0022\\u003Eupdate\\u003C\\/a\\u003E.\\r\\n\\r\\nYou can edit your notification settings from your \\u003Ca href=\\u0022[recipient:edit-url]\\u0022\\u003Eprofile page\\u003C\\/a\\u003E.\\r\\n\\r\\nThis was an auto-generated email from [site:name]; please do not respond directly to this email."
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
      "TAGS" : [ "checkdesk" ],
      "REQUIRES" : [ "rules", "php", "heartbeat_rules", "meedan_notifications" ],
      "ON" : [ "node_update" ],
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
              { "notify_subscribers" : {
                  "object" : [ "report" ],
                  "event" : "email_report_published_in_update",
                  "subject" : "Report published",
                  "message" : "Hello [recipient:name],\\r\\n\\r\\nA \\u003Ca href=\\u0022[report:url]\\u0022\\u003Ereport\\u003C\\/a\\u003E which you have submitted has been published in an \\u003Ca href=\\u0022[node:url]\\u0022\\u003Eupdate\\u003C\\/a\\u003E.\\r\\n\\r\\nYou can edit your notification settings from your \\u003Ca href=\\u0022[recipient:edit-url]\\u0022\\u003Eprofile page\\u003C\\/a\\u003E.\\r\\n\\r\\nThis was an auto-generated email from [site:name]; please do not respond directly to this email."
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
      "TAGS" : [ "checkdesk" ],
      "REQUIRES" : [ "rules", "php", "meedan_notifications", "heartbeat_rules" ],
      "ON" : [ "node_insert" ],
      "IF" : [
        { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "media" : "media" } } } },
        { "entity_has_field" : { "entity" : [ "node" ], "field" : "field_stories" } },
        { "php_eval" : { "code" : "$obj = entity_metadata_wrapper(\\u0027node\\u0027, $node);\\r\\n$field = $obj-\\u003Efield_stories-\\u003Evalue();\\r\\nreturn count($field) \\u003E 0;" } }
      ],
      "DO" : [
        { "LOOP" : {
            "USING" : { "list" : [ "node:field-stories" ] },
            "ITEM" : { "list_item" : "Current list item" },
            "DO" : [
              { "notify_subscribers" : {
                  "object" : [ "node" ],
                  "event" : "email_report_suggested",
                  "subject" : "Report suggested to story",
                  "message" : "Hello [recipient:name],\\r\\n\\r\\n[node:author:name] has suggested this report \\u0022[node:title]\\u0022 to this story \\u0022[list-item:title]\\u0022.\\r\\n\\r\\nGo to [list-item:url] to compose a new update to the story using that report.\\r\\n\\r\\nYou can edit your notification settings from [recipient:edit-url].\\r\\n\\r\\nThis was an auto-generated email from [site:name], please do not respond directly to this email."
                }
              },
              { "heartbeat_activity_checkdesk_report_suggested_to_story" : {
                  "nid" : "[node:nid]",
                  "uid" : "[site:current-user:uid]",
                  "nid_target" : "[list-item:nid]",
                  "uid_target" : "0",
                  "message_id" : { "value" : { "checkdesk_report_suggested_to_story" : "checkdesk_report_suggested_to_story" } },
                  "!user_url" : "[site:current-user:url]",
                  "!username" : "[site:current-user:name]",
                  "!report_url" : "[node:url]",
                  "!story_url" : "[list-item:url]",
                  "!story" : "[list-item:title]"
                }
              }
            ]
          }
        }
      ]
    }
  }');
  $items['rules_report_was_flagged_under_fact_checking_'] = entity_import('rules_config', '{ "rules_report_was_flagged_under_fact_checking_" : {
      "LABEL" : "Fact-checking turned on for report",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "checkdesk" ],
      "REQUIRES" : [ "rules", "heartbeat_rules", "meedan_notifications", "flag" ],
      "ON" : [ "flag_flagged_factcheckon" ],
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
            "nid_target" : "0",
            "uid_target" : "0",
            "message_id" : { "value" : { "checkdesk_fact_checking_on" : "checkdesk_fact_checking_on" } },
            "!user_url" : [ "flagging-user:url" ],
            "!username" : [ "flagging-user:name" ],
            "!report_url" : [ "flagged-node:url" ]
          }
        },
        { "notify_subscribers" : {
            "object" : [ "flagged-node" ],
            "event" : "email_fact_checking_on",
            "subject" : "Fact-checking turned on",
            "message" : "Hello [recipient:name],\\r\\n\\r\\n[flagging-user:name] has turned on fact-checking for a \\u003Ca href=\\u0022[flagged-node:url]\\u0022\\u003Ereport\\u003C\\/a\\u003E you submitted.\\r\\n\\r\\nYou can edit your notification settings from your \\u003Ca href=\\u0022[recipient:edit-url]\\u0022\\u003Eprofile page\\u003C\\/a\\u003E.\\r\\n\\r\\nThis was an auto-generated email from [site:name]; please do not respond directly to this email."
          }
        }
      ]
    }
  }');
  $items['rules_report_was_flagged_under_graphic_content_'] = entity_import('rules_config', '{ "rules_report_was_flagged_under_graphic_content_" : {
      "LABEL" : "Report was flagged",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "checkdesk" ],
      "REQUIRES" : [ "rules", "heartbeat_rules", "meedan_notifications", "flag" ],
      "ON" : [ "flag_flagged_graphic", "flag_flagged_factcheck", "flag_flagged_spam" ],
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
            "nid_target" : "0",
            "uid_target" : [ "flagging-user:uid" ],
            "message_id" : { "value" : { "checkdesk_flag_report" : "checkdesk_flag_report" } },
            "!flag_author_url" : [ "flagging-user:url" ],
            "!flag_author_name" : [ "flagging-user:name" ],
            "!report_url" : [ "flagged-node:url" ],
            "!flag_type" : "[flag:title]"
          }
        },
        { "notify_subscribers" : {
            "object" : [ "flagged-node" ],
            "event" : "email_report_flagged",
            "subject" : "Report flagged",
            "message" : "Hello [recipient:name],\\r\\n\\r\\n[flagging-user:name] has flagged the following \\u003Ca href=\\u0022[flagged-node:url]\\u0022\\u003Ereport\\u003C\\/a\\u003E as [flag:title]:\\r\\n\\r\\n[flagged-node:title]\\r\\n[flagged-node:summary]\\r\\n\\r\\nThey provided the following explanation for flagging:\\r\\n\\r\\n\\u003Ca href=\\u0022[flagged-node:edit-url]\\u0022\\u003EClick here\\u003C\\/a\\u003E to moderate.\\r\\n\\r\\nYou can edit your notification settings from your \\u003Ca href=\\u0022[recipient:edit-url]\\u0022\\u003Eprofile page\\u003C\\/a\\u003E.\\r\\n\\r\\nThis was an auto-generated email from [site:name], please do not respond directly to this email."
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
  $items['rules_user_banned_and_comments_deleted'] = entity_import('rules_config', '{ "rules_user_banned_and_comments_deleted" : {
      "LABEL" : "User banned and comments deleted",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "checkdesk" ],
      "REQUIRES" : [ "rules" ],
      "ON" : [ "user_update" ],
      "IF" : [ { "data_is" : { "data" : [ "account:status" ], "value" : "0" } } ],
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
  return $items;
}
