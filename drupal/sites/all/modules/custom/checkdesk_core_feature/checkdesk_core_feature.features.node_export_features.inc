<?php
/**
 * @file
 * checkdesk_core_feature.features.node_export_features.inc
 */

/**
 * Implements hook_node_export_features_default().
 */
function checkdesk_core_feature_node_export_features_default() {
  $node_export = array(
  'code_string' => 'array(
  (object) array(
      \'vid\' => \'385\',
      \'uid\' => \'1\',
      \'title\' => \'شروط الاستخدام\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'1\',
      \'promote\' => \'0\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'a57cb367-19d1-4709-b82b-021ef4f504e0\',
      \'nid\' => \'158\',
      \'type\' => \'page\',
      \'language\' => \'ar\',
      \'created\' => \'1361220445\',
      \'changed\' => \'1361220445\',
      \'tnid\' => \'153\',
      \'translate\' => \'0\',
      \'uuid\' => \'07d83a6f-e26f-4dd6-9002-a7730dc6250f\',
      \'revision_timestamp\' => \'1361220445\',
      \'revision_uid\' => \'1\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => \'To be added.\',
            \'summary\' => \'\',
            \'format\' => \'filtered_html\',
            \'safe_value\' => "<p>To be added.</p>\\n",
            \'safe_summary\' => \'\',
          ),
        ),
      ),
      \'metatags\' => array(),
      \'rdf_mapping\' => array(
        \'rdftype\' => array(
          \'sioc:Item\',
          \'foaf:Document\',
        ),
        \'title\' => array(
          \'predicates\' => array(
            \'dc:title\',
          ),
        ),
        \'created\' => array(
          \'predicates\' => array(
            \'dc:date\',
            \'dc:created\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'changed\' => array(
          \'predicates\' => array(
            \'dc:modified\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'body\' => array(
          \'predicates\' => array(
            \'content:encoded\',
          ),
        ),
        \'uid\' => array(
          \'predicates\' => array(
            \'sioc:has_creator\',
          ),
          \'type\' => \'rel\',
        ),
        \'name\' => array(
          \'predicates\' => array(
            \'foaf:name\',
          ),
        ),
        \'comment_count\' => array(
          \'predicates\' => array(
            \'sioc:num_replies\',
          ),
          \'datatype\' => \'xsd:integer\',
        ),
        \'last_activity\' => array(
          \'predicates\' => array(
            \'sioc:last_activity_date\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
      ),
      \'cid\' => \'0\',
      \'last_comment_timestamp\' => \'1361220445\',
      \'last_comment_name\' => NULL,
      \'last_comment_uid\' => \'1\',
      \'comment_count\' => \'0\',
      \'name\' => \'admin\',
      \'picture\' => \'4\',
      \'data\' => \'a:6:{s:17:"sensitive_content";i:0;s:7:"overlay";i:0;s:11:"remember_me";b:1;s:18:"htmlmail_plaintext";i:0;s:20:"l10n_client_disabled";b:0;s:20:"meedan_notifications";a:20:{s:19:"site_report_flagged";s:19:"site_report_flagged";s:21:"site_report_suggested";s:21:"site_report_suggested";s:22:"site_comment_on_update";s:22:"site_comment_on_update";s:42:"site_update_on_story_i_commented_on_update";s:42:"site_update_on_story_i_commented_on_update";s:31:"site_report_published_in_update";s:31:"site_report_published_in_update";s:22:"site_comment_on_report";s:22:"site_comment_on_report";s:21:"site_reply_to_comment";s:21:"site_reply_to_comment";s:21:"site_fact_checking_on";s:21:"site_fact_checking_on";s:22:"site_fact_checking_set";s:22:"site_fact_checking_set";s:38:"site_fact_status_changed_for_commenter";s:38:"site_fact_status_changed_for_commenter";s:20:"email_report_flagged";s:20:"email_report_flagged";s:22:"email_report_suggested";s:22:"email_report_suggested";s:23:"email_comment_on_update";s:23:"email_comment_on_update";s:43:"email_update_on_story_i_commented_on_update";s:43:"email_update_on_story_i_commented_on_update";s:32:"email_report_published_in_update";s:32:"email_report_published_in_update";s:23:"email_comment_on_report";s:23:"email_comment_on_report";s:22:"email_reply_to_comment";s:22:"email_reply_to_comment";s:22:"email_fact_checking_on";s:22:"email_fact_checking_on";s:23:"email_fact_checking_set";s:23:"email_fact_checking_set";s:39:"email_fact_status_changed_for_commenter";s:39:"email_fact_status_changed_for_commenter";}}\',
      \'path\' => array(
        \'pid\' => \'207\',
        \'source\' => \'node/158\',
        \'alias\' => \'content/شروط-الاستخدام\',
        \'language\' => \'ar\',
      ),
      \'menu\' => NULL,
      \'node_export_drupal_version\' => \'7\',
    ),
  (object) array(
      \'vid\' => \'378\',
      \'uid\' => \'0\',
      \'title\' => \'Install Bookmarklet\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'1\',
      \'promote\' => \'0\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'dbc22e67-cc5a-acf4-a504-6c5e9b04fb6b\',
      \'nid\' => \'1\',
      \'type\' => \'page\',
      \'language\' => \'en\',
      \'created\' => \'1361218508\',
      \'changed\' => \'1361218508\',
      \'tnid\' => \'1\',
      \'translate\' => \'0\',
      \'uuid\' => \'1244c020-f663-b564-b94c-2cf29b12afa4\',
      \'revision_timestamp\' => \'1361218508\',
      \'revision_uid\' => \'0\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => "<div id=\\"info-page-install-bookmarklet\\" class=\\"info-page\\">\\r\\n<div class=\\"install-bookmarklet-col\\">\\r\\n<p><a id=\\"install-bookmarklet-button\\" href=\\"<?php print meedan_bookmarklet_get_code(); ?>\\"><span>Send to <?php print variable_get(\'site_name\', \'this site\'); ?></span></a></p>\\r\\n<h3>Drag this button <br /> to your bookmarks bar.</h3>\\r\\n</div>\\r\\n<div class=\\"install-bookmarklet-col\\">\\r\\n<h2>Install Bookmarklet</h2>\\r\\n<p>The browser bookmarklet allows you to send us reports from any page.</p>\\r\\n<p>Once you install it, you can click it, preview how the report will appear, and send it to one of our stories.</p>\\r\\n<p>To install the bookmarklet, drag the button into your browser\'s bookmarks toolbar.</p>\\r\\n</div>\\r\\n</div>\\r\\n<script type=\\"text/javascript\\">\\r\\njQuery(\\"#modalContent, #modalBackdrop\\").addClass(\\"modal-install-bookmarklet\\");\\r\\n</script>",
            \'summary\' => \'\',
            \'format\' => \'php_code\',
          ),
        ),
      ),
      \'metatags\' => array(),
      \'rdf_mapping\' => array(
        \'rdftype\' => array(
          \'sioc:Item\',
          \'foaf:Document\',
        ),
        \'title\' => array(
          \'predicates\' => array(
            \'dc:title\',
          ),
        ),
        \'created\' => array(
          \'predicates\' => array(
            \'dc:date\',
            \'dc:created\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'changed\' => array(
          \'predicates\' => array(
            \'dc:modified\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'body\' => array(
          \'predicates\' => array(
            \'content:encoded\',
          ),
        ),
        \'uid\' => array(
          \'predicates\' => array(
            \'sioc:has_creator\',
          ),
          \'type\' => \'rel\',
        ),
        \'name\' => array(
          \'predicates\' => array(
            \'foaf:name\',
          ),
        ),
        \'comment_count\' => array(
          \'predicates\' => array(
            \'sioc:num_replies\',
          ),
          \'datatype\' => \'xsd:integer\',
        ),
        \'last_activity\' => array(
          \'predicates\' => array(
            \'sioc:last_activity_date\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
      ),
      \'cid\' => \'0\',
      \'last_comment_timestamp\' => \'1355680954\',
      \'last_comment_name\' => NULL,
      \'last_comment_uid\' => \'0\',
      \'comment_count\' => \'0\',
      \'name\' => \'\',
      \'picture\' => \'0\',
      \'data\' => NULL,
      \'path\' => array(
        \'pid\' => \'6\',
        \'source\' => \'node/1\',
        \'alias\' => \'content/install-bookmarklet\',
        \'language\' => \'en\',
      ),
      \'menu\' => NULL,
      \'node_export_drupal_version\' => \'7\',
    ),
  (object) array(
      \'vid\' => \'379\',
      \'uid\' => \'0\',
      \'title\' => \'Terms of Use\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'1\',
      \'promote\' => \'0\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'b5a5166c-70bc-4230-9978-3d5bba6be921\',
      \'nid\' => \'153\',
      \'type\' => \'page\',
      \'language\' => \'en\',
      \'created\' => \'1361218508\',
      \'changed\' => \'1361218508\',
      \'tnid\' => \'153\',
      \'translate\' => \'0\',
      \'uuid\' => \'31710726-27dc-4c80-99fc-cb2c79a84053\',
      \'revision_timestamp\' => \'1361218508\',
      \'revision_uid\' => \'0\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => \'To be added.\',
            \'summary\' => \'\',
            \'format\' => \'filtered_html\',
            \'safe_value\' => "<p>To be added.</p>\\n",
            \'safe_summary\' => \'\',
          ),
        ),
      ),
      \'metatags\' => array(),
      \'rdf_mapping\' => array(
        \'rdftype\' => array(
          \'sioc:Item\',
          \'foaf:Document\',
        ),
        \'title\' => array(
          \'predicates\' => array(
            \'dc:title\',
          ),
        ),
        \'created\' => array(
          \'predicates\' => array(
            \'dc:date\',
            \'dc:created\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'changed\' => array(
          \'predicates\' => array(
            \'dc:modified\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'body\' => array(
          \'predicates\' => array(
            \'content:encoded\',
          ),
        ),
        \'uid\' => array(
          \'predicates\' => array(
            \'sioc:has_creator\',
          ),
          \'type\' => \'rel\',
        ),
        \'name\' => array(
          \'predicates\' => array(
            \'foaf:name\',
          ),
        ),
        \'comment_count\' => array(
          \'predicates\' => array(
            \'sioc:num_replies\',
          ),
          \'datatype\' => \'xsd:integer\',
        ),
        \'last_activity\' => array(
          \'predicates\' => array(
            \'sioc:last_activity_date\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
      ),
      \'cid\' => \'0\',
      \'last_comment_timestamp\' => \'1359862063\',
      \'last_comment_name\' => NULL,
      \'last_comment_uid\' => \'0\',
      \'comment_count\' => \'0\',
      \'name\' => \'\',
      \'picture\' => \'0\',
      \'data\' => NULL,
      \'path\' => array(
        \'pid\' => \'201\',
        \'source\' => \'node/153\',
        \'alias\' => \'content/terms-use\',
        \'language\' => \'und\',
      ),
      \'menu\' => NULL,
      \'node_export_drupal_version\' => \'7\',
    ),
  (object) array(
      \'vid\' => \'383\',
      \'uid\' => \'1\',
      \'title\' => \'حول\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'1\',
      \'promote\' => \'0\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'79b6bafb-40ac-47ba-a8ac-00f400412c7f\',
      \'nid\' => \'156\',
      \'type\' => \'page\',
      \'language\' => \'ar\',
      \'created\' => \'1361220275\',
      \'changed\' => \'1361220275\',
      \'tnid\' => \'155\',
      \'translate\' => \'0\',
      \'uuid\' => \'698c6a43-1950-4dd4-bcc2-655f08f49cd8\',
      \'revision_timestamp\' => \'1361220275\',
      \'revision_uid\' => \'1\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => \'To be added.\',
            \'summary\' => \'\',
            \'format\' => \'filtered_html\',
            \'safe_value\' => "<p>To be added.</p>\\n",
            \'safe_summary\' => \'\',
          ),
        ),
      ),
      \'metatags\' => array(),
      \'rdf_mapping\' => array(
        \'rdftype\' => array(
          \'sioc:Item\',
          \'foaf:Document\',
        ),
        \'title\' => array(
          \'predicates\' => array(
            \'dc:title\',
          ),
        ),
        \'created\' => array(
          \'predicates\' => array(
            \'dc:date\',
            \'dc:created\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'changed\' => array(
          \'predicates\' => array(
            \'dc:modified\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'body\' => array(
          \'predicates\' => array(
            \'content:encoded\',
          ),
        ),
        \'uid\' => array(
          \'predicates\' => array(
            \'sioc:has_creator\',
          ),
          \'type\' => \'rel\',
        ),
        \'name\' => array(
          \'predicates\' => array(
            \'foaf:name\',
          ),
        ),
        \'comment_count\' => array(
          \'predicates\' => array(
            \'sioc:num_replies\',
          ),
          \'datatype\' => \'xsd:integer\',
        ),
        \'last_activity\' => array(
          \'predicates\' => array(
            \'sioc:last_activity_date\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
      ),
      \'cid\' => \'0\',
      \'last_comment_timestamp\' => \'1361220275\',
      \'last_comment_name\' => NULL,
      \'last_comment_uid\' => \'1\',
      \'comment_count\' => \'0\',
      \'name\' => \'admin\',
      \'picture\' => \'4\',
      \'data\' => \'a:6:{s:17:"sensitive_content";i:0;s:7:"overlay";i:0;s:11:"remember_me";b:1;s:18:"htmlmail_plaintext";i:0;s:20:"l10n_client_disabled";b:0;s:20:"meedan_notifications";a:20:{s:19:"site_report_flagged";s:19:"site_report_flagged";s:21:"site_report_suggested";s:21:"site_report_suggested";s:22:"site_comment_on_update";s:22:"site_comment_on_update";s:42:"site_update_on_story_i_commented_on_update";s:42:"site_update_on_story_i_commented_on_update";s:31:"site_report_published_in_update";s:31:"site_report_published_in_update";s:22:"site_comment_on_report";s:22:"site_comment_on_report";s:21:"site_reply_to_comment";s:21:"site_reply_to_comment";s:21:"site_fact_checking_on";s:21:"site_fact_checking_on";s:22:"site_fact_checking_set";s:22:"site_fact_checking_set";s:38:"site_fact_status_changed_for_commenter";s:38:"site_fact_status_changed_for_commenter";s:20:"email_report_flagged";s:20:"email_report_flagged";s:22:"email_report_suggested";s:22:"email_report_suggested";s:23:"email_comment_on_update";s:23:"email_comment_on_update";s:43:"email_update_on_story_i_commented_on_update";s:43:"email_update_on_story_i_commented_on_update";s:32:"email_report_published_in_update";s:32:"email_report_published_in_update";s:23:"email_comment_on_report";s:23:"email_comment_on_report";s:22:"email_reply_to_comment";s:22:"email_reply_to_comment";s:22:"email_fact_checking_on";s:22:"email_fact_checking_on";s:23:"email_fact_checking_set";s:23:"email_fact_checking_set";s:39:"email_fact_status_changed_for_commenter";s:39:"email_fact_status_changed_for_commenter";}}\',
      \'path\' => array(
        \'pid\' => \'205\',
        \'source\' => \'node/156\',
        \'alias\' => \'content/حول\',
        \'language\' => \'ar\',
      ),
      \'menu\' => NULL,
      \'node_export_drupal_version\' => \'7\',
    ),
  (object) array(
      \'vid\' => \'380\',
      \'uid\' => \'0\',
      \'title\' => \'Fact Checking statement\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'1\',
      \'promote\' => \'0\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'86e41833-6e4d-496e-b2be-11036d7a12b3\',
      \'nid\' => \'154\',
      \'type\' => \'page\',
      \'language\' => \'en\',
      \'created\' => \'1361218508\',
      \'changed\' => \'1361218508\',
      \'tnid\' => \'154\',
      \'translate\' => \'0\',
      \'uuid\' => \'9ff42c15-5459-4a62-94c2-f45fe8aab3d5\',
      \'revision_timestamp\' => \'1361218508\',
      \'revision_uid\' => \'0\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => \'To be added.\',
            \'summary\' => \'\',
            \'format\' => \'filtered_html\',
            \'safe_value\' => "<p>To be added.</p>\\n",
            \'safe_summary\' => \'\',
          ),
        ),
      ),
      \'metatags\' => array(),
      \'rdf_mapping\' => array(
        \'rdftype\' => array(
          \'sioc:Item\',
          \'foaf:Document\',
        ),
        \'title\' => array(
          \'predicates\' => array(
            \'dc:title\',
          ),
        ),
        \'created\' => array(
          \'predicates\' => array(
            \'dc:date\',
            \'dc:created\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'changed\' => array(
          \'predicates\' => array(
            \'dc:modified\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'body\' => array(
          \'predicates\' => array(
            \'content:encoded\',
          ),
        ),
        \'uid\' => array(
          \'predicates\' => array(
            \'sioc:has_creator\',
          ),
          \'type\' => \'rel\',
        ),
        \'name\' => array(
          \'predicates\' => array(
            \'foaf:name\',
          ),
        ),
        \'comment_count\' => array(
          \'predicates\' => array(
            \'sioc:num_replies\',
          ),
          \'datatype\' => \'xsd:integer\',
        ),
        \'last_activity\' => array(
          \'predicates\' => array(
            \'sioc:last_activity_date\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
      ),
      \'cid\' => \'0\',
      \'last_comment_timestamp\' => \'1359862063\',
      \'last_comment_name\' => NULL,
      \'last_comment_uid\' => \'0\',
      \'comment_count\' => \'0\',
      \'name\' => \'\',
      \'picture\' => \'0\',
      \'data\' => NULL,
      \'path\' => array(
        \'pid\' => \'202\',
        \'source\' => \'node/154\',
        \'alias\' => \'content/fact-checking-statement\',
        \'language\' => \'und\',
      ),
      \'menu\' => NULL,
      \'node_export_drupal_version\' => \'7\',
    ),
  (object) array(
      \'vid\' => \'381\',
      \'uid\' => \'0\',
      \'title\' => \'تنصيب إضافة المتصفح\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'1\',
      \'promote\' => \'0\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'310a0c27-0d6b-3344-4d3b-6ce3884081f4\',
      \'nid\' => \'152\',
      \'type\' => \'page\',
      \'language\' => \'ar\',
      \'created\' => \'1361218508\',
      \'changed\' => \'1361218508\',
      \'tnid\' => \'1\',
      \'translate\' => \'0\',
      \'uuid\' => \'b9dfa9a5-9654-8894-d51b-027bff47c7f1\',
      \'revision_timestamp\' => \'1361218508\',
      \'revision_uid\' => \'0\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => "<div id=\\"info-page-install-bookmarklet\\" class=\\"info-page\\">\\r\\n<div class=\\"install-bookmarklet-col\\">\\r\\n<p><a id=\\"install-bookmarklet-button\\" href=\\"<?php print meedan_bookmarklet_get_code(); ?>\\"><span>أضف تقرير إلى <?php print variable_get(\'site_name\', \'this site\'); ?></span></a></p>\\r\\n<h3>إسحب هذا الزر <br /> إلى شريط الروابط.</h3>\\r\\n</div>\\r\\n<div class=\\"install-bookmarklet-col\\">\\r\\n<h2>تنصيب إضافة المتصفح</h2>\\r\\n<p>زر إضافة المتصفح يمكنك من إضافة تقارير من أي صفحة.</p>\\r\\n<p>بعد التنصيب، انقر الزر وعاين تقريرك الجديد قبل إرساله إلى أحد الأخبار.</p>\\r\\n<p>للتنصيب، إسحب الزر إلى شريط الروابط لدى المتصفح.</p>\\r\\n</div>\\r\\n</div>\\r\\n<script type=\\"text/javascript\\">\\r\\njQuery(\\"#modalContent, #modalBackdrop\\").addClass(\\"modal-install-bookmarklet\\");\\r\\n</script>",
            \'summary\' => \'\',
            \'format\' => \'php_code\',
          ),
        ),
      ),
      \'metatags\' => array(),
      \'rdf_mapping\' => array(
        \'rdftype\' => array(
          \'sioc:Item\',
          \'foaf:Document\',
        ),
        \'title\' => array(
          \'predicates\' => array(
            \'dc:title\',
          ),
        ),
        \'created\' => array(
          \'predicates\' => array(
            \'dc:date\',
            \'dc:created\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'changed\' => array(
          \'predicates\' => array(
            \'dc:modified\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'body\' => array(
          \'predicates\' => array(
            \'content:encoded\',
          ),
        ),
        \'uid\' => array(
          \'predicates\' => array(
            \'sioc:has_creator\',
          ),
          \'type\' => \'rel\',
        ),
        \'name\' => array(
          \'predicates\' => array(
            \'foaf:name\',
          ),
        ),
        \'comment_count\' => array(
          \'predicates\' => array(
            \'sioc:num_replies\',
          ),
          \'datatype\' => \'xsd:integer\',
        ),
        \'last_activity\' => array(
          \'predicates\' => array(
            \'sioc:last_activity_date\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
      ),
      \'cid\' => \'0\',
      \'last_comment_timestamp\' => \'1359861563\',
      \'last_comment_name\' => NULL,
      \'last_comment_uid\' => \'1\',
      \'comment_count\' => \'0\',
      \'name\' => \'\',
      \'picture\' => \'0\',
      \'data\' => NULL,
      \'path\' => array(
        \'pid\' => \'199\',
        \'source\' => \'node/152\',
        \'alias\' => \'content/تنصيب-إضافة-المتصفح\',
        \'language\' => \'ar\',
      ),
      \'menu\' => NULL,
      \'node_export_drupal_version\' => \'7\',
    ),
  (object) array(
      \'vid\' => \'382\',
      \'uid\' => \'0\',
      \'title\' => \'About\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'1\',
      \'promote\' => \'0\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'290717c7-aa65-4053-80d2-59c0a35bc43d\',
      \'nid\' => \'155\',
      \'type\' => \'page\',
      \'language\' => \'en\',
      \'created\' => \'1361218508\',
      \'changed\' => \'1361218508\',
      \'tnid\' => \'155\',
      \'translate\' => \'0\',
      \'uuid\' => \'d3c58330-cc88-4e2c-8cc5-e60c4cac0803\',
      \'revision_timestamp\' => \'1361218508\',
      \'revision_uid\' => \'0\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => \'To be added.\',
            \'summary\' => \'\',
            \'format\' => \'filtered_html\',
            \'safe_value\' => "<p>To be added.</p>\\n",
            \'safe_summary\' => \'\',
          ),
        ),
      ),
      \'metatags\' => array(),
      \'rdf_mapping\' => array(
        \'rdftype\' => array(
          \'sioc:Item\',
          \'foaf:Document\',
        ),
        \'title\' => array(
          \'predicates\' => array(
            \'dc:title\',
          ),
        ),
        \'created\' => array(
          \'predicates\' => array(
            \'dc:date\',
            \'dc:created\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'changed\' => array(
          \'predicates\' => array(
            \'dc:modified\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'body\' => array(
          \'predicates\' => array(
            \'content:encoded\',
          ),
        ),
        \'uid\' => array(
          \'predicates\' => array(
            \'sioc:has_creator\',
          ),
          \'type\' => \'rel\',
        ),
        \'name\' => array(
          \'predicates\' => array(
            \'foaf:name\',
          ),
        ),
        \'comment_count\' => array(
          \'predicates\' => array(
            \'sioc:num_replies\',
          ),
          \'datatype\' => \'xsd:integer\',
        ),
        \'last_activity\' => array(
          \'predicates\' => array(
            \'sioc:last_activity_date\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
      ),
      \'cid\' => \'0\',
      \'last_comment_timestamp\' => \'1359862063\',
      \'last_comment_name\' => NULL,
      \'last_comment_uid\' => \'0\',
      \'comment_count\' => \'0\',
      \'name\' => \'\',
      \'picture\' => \'0\',
      \'data\' => NULL,
      \'path\' => array(
        \'pid\' => \'203\',
        \'source\' => \'node/155\',
        \'alias\' => \'content/about\',
        \'language\' => \'und\',
      ),
      \'menu\' => NULL,
      \'node_export_drupal_version\' => \'7\',
    ),
  (object) array(
      \'vid\' => \'384\',
      \'uid\' => \'1\',
      \'title\' => \'بيان التحقق من صحة المعلومات\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'1\',
      \'promote\' => \'0\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'4a98224f-7a94-4a13-8d2c-dd8159180d64\',
      \'nid\' => \'157\',
      \'type\' => \'page\',
      \'language\' => \'ar\',
      \'created\' => \'1361220403\',
      \'changed\' => \'1361220403\',
      \'tnid\' => \'154\',
      \'translate\' => \'0\',
      \'uuid\' => \'f71822ad-79b3-4479-bd09-10a9a8ba1223\',
      \'revision_timestamp\' => \'1361220403\',
      \'revision_uid\' => \'1\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => \'To be added.\',
            \'summary\' => \'\',
            \'format\' => \'filtered_html\',
            \'safe_value\' => "<p>To be added.</p>\\n",
            \'safe_summary\' => \'\',
          ),
        ),
      ),
      \'metatags\' => array(),
      \'rdf_mapping\' => array(
        \'rdftype\' => array(
          \'sioc:Item\',
          \'foaf:Document\',
        ),
        \'title\' => array(
          \'predicates\' => array(
            \'dc:title\',
          ),
        ),
        \'created\' => array(
          \'predicates\' => array(
            \'dc:date\',
            \'dc:created\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'changed\' => array(
          \'predicates\' => array(
            \'dc:modified\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'body\' => array(
          \'predicates\' => array(
            \'content:encoded\',
          ),
        ),
        \'uid\' => array(
          \'predicates\' => array(
            \'sioc:has_creator\',
          ),
          \'type\' => \'rel\',
        ),
        \'name\' => array(
          \'predicates\' => array(
            \'foaf:name\',
          ),
        ),
        \'comment_count\' => array(
          \'predicates\' => array(
            \'sioc:num_replies\',
          ),
          \'datatype\' => \'xsd:integer\',
        ),
        \'last_activity\' => array(
          \'predicates\' => array(
            \'sioc:last_activity_date\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
      ),
      \'cid\' => \'0\',
      \'last_comment_timestamp\' => \'1361220403\',
      \'last_comment_name\' => NULL,
      \'last_comment_uid\' => \'1\',
      \'comment_count\' => \'0\',
      \'name\' => \'admin\',
      \'picture\' => \'4\',
      \'data\' => \'a:6:{s:17:"sensitive_content";i:0;s:7:"overlay";i:0;s:11:"remember_me";b:1;s:18:"htmlmail_plaintext";i:0;s:20:"l10n_client_disabled";b:0;s:20:"meedan_notifications";a:20:{s:19:"site_report_flagged";s:19:"site_report_flagged";s:21:"site_report_suggested";s:21:"site_report_suggested";s:22:"site_comment_on_update";s:22:"site_comment_on_update";s:42:"site_update_on_story_i_commented_on_update";s:42:"site_update_on_story_i_commented_on_update";s:31:"site_report_published_in_update";s:31:"site_report_published_in_update";s:22:"site_comment_on_report";s:22:"site_comment_on_report";s:21:"site_reply_to_comment";s:21:"site_reply_to_comment";s:21:"site_fact_checking_on";s:21:"site_fact_checking_on";s:22:"site_fact_checking_set";s:22:"site_fact_checking_set";s:38:"site_fact_status_changed_for_commenter";s:38:"site_fact_status_changed_for_commenter";s:20:"email_report_flagged";s:20:"email_report_flagged";s:22:"email_report_suggested";s:22:"email_report_suggested";s:23:"email_comment_on_update";s:23:"email_comment_on_update";s:43:"email_update_on_story_i_commented_on_update";s:43:"email_update_on_story_i_commented_on_update";s:32:"email_report_published_in_update";s:32:"email_report_published_in_update";s:23:"email_comment_on_report";s:23:"email_comment_on_report";s:22:"email_reply_to_comment";s:22:"email_reply_to_comment";s:22:"email_fact_checking_on";s:22:"email_fact_checking_on";s:23:"email_fact_checking_set";s:23:"email_fact_checking_set";s:39:"email_fact_status_changed_for_commenter";s:39:"email_fact_status_changed_for_commenter";}}\',
      \'path\' => array(
        \'pid\' => \'206\',
        \'source\' => \'node/157\',
        \'alias\' => \'content/بيان-التحقق-من-صحة-المعلومات\',
        \'language\' => \'ar\',
      ),
      \'menu\' => NULL,
      \'node_export_drupal_version\' => \'7\',
    ),
)',
);
  return $node_export;
}
