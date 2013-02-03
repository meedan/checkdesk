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
      \'vid\' => \'259\',
      \'uid\' => \'1\',
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
      \'created\' => \'1359866745\',
      \'changed\' => \'1359867071\',
      \'tnid\' => \'1\',
      \'translate\' => \'0\',
      \'uuid\' => \'1244c020-f663-b564-b94c-2cf29b12afa4\',
      \'revision_timestamp\' => \'1359867071\',
      \'revision_uid\' => \'1\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => "<div id=\\"info-page-install-bookmarklet\\" class=\\"info-page\\">\\r\\n<div class=\\"install-bookmarklet-col\\">\\r\\n<p><a id=\\"install-bookmarklet-button\\" href=\\"<?php print variable_get(\'meedan_bookmarklet_code\', _meedan_bookmarklet_default_code()); ?>\\"><span>Send to <?php print variable_get(\'site_name\', \'this site\'); ?></span></a></p>\\r\\n<h3>Drag this button <br /> to your bookmarks bar.</h3>\\r\\n<p>Show extra instructions for:</p>\\r\\n<ul>\\r\\n<li><a href=\\"#\\">Internet Explorer</a></li>\\r\\n<li><a href=\\"#\\">Firefox</a></li>\\r\\n<li><a href=\\"#\\">Safari</a></li>\\r\\n<li><a href=\\"#\\">Chrome</a></li>\\r\\n</ul>\\r\\n</div>\\r\\n<div class=\\"install-bookmarklet-col\\">\\r\\n<h2>Install Bookmarklet</h2>\\r\\n<p>The browser bookmarklet allows you to send us reports from any page.</p>\\r\\n<p>Once you install it, you can click it, preview how the report will appear, and send it to one of our stories.</p>\\r\\n<p>To install the bookmarklet, drag the button into your browser\'s bookmarks toolbar.</p>\\r\\n</div>\\r\\n</div>\\r\\n<script type=\\"text/javascript\\">\\r\\njQuery(\\"#modalContent, #modalBackdrop\\").addClass(\\"modal-install-bookmarklet\\");\\r\\n</script>",
            \'summary\' => \'\',
            \'format\' => \'php_code\',
          ),
        ),
      ),
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
      \'name\' => \'admin\',
      \'picture\' => \'4\',
      \'data\' => \'a:6:{s:17:"sensitive_content";i:0;s:7:"overlay";i:0;s:11:"remember_me";b:1;s:18:"htmlmail_plaintext";i:0;s:20:"l10n_client_disabled";b:0;s:20:"meedan_notifications";a:20:{s:19:"site_report_flagged";s:19:"site_report_flagged";s:21:"site_report_suggested";s:21:"site_report_suggested";s:22:"site_comment_on_update";s:22:"site_comment_on_update";s:42:"site_update_on_story_i_commented_on_update";s:42:"site_update_on_story_i_commented_on_update";s:31:"site_report_published_in_update";s:31:"site_report_published_in_update";s:22:"site_comment_on_report";s:22:"site_comment_on_report";s:21:"site_reply_to_comment";s:21:"site_reply_to_comment";s:21:"site_fact_checking_on";s:21:"site_fact_checking_on";s:22:"site_fact_checking_set";s:22:"site_fact_checking_set";s:38:"site_fact_status_changed_for_commenter";s:38:"site_fact_status_changed_for_commenter";s:20:"email_report_flagged";s:20:"email_report_flagged";s:22:"email_report_suggested";s:22:"email_report_suggested";s:23:"email_comment_on_update";s:23:"email_comment_on_update";s:43:"email_update_on_story_i_commented_on_update";s:43:"email_update_on_story_i_commented_on_update";s:32:"email_report_published_in_update";s:32:"email_report_published_in_update";s:23:"email_comment_on_report";s:23:"email_comment_on_report";s:22:"email_reply_to_comment";s:22:"email_reply_to_comment";s:22:"email_fact_checking_on";s:22:"email_fact_checking_on";s:23:"email_fact_checking_set";s:23:"email_fact_checking_set";s:39:"email_fact_status_changed_for_commenter";s:39:"email_fact_status_changed_for_commenter";}}\',
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
      \'vid\' => \'260\',
      \'uid\' => \'1\',
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
      \'created\' => \'1359866745\',
      \'changed\' => \'1359867174\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'31710726-27dc-4c80-99fc-cb2c79a84053\',
      \'revision_timestamp\' => \'1359867174\',
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
      \'name\' => \'admin\',
      \'picture\' => \'4\',
      \'data\' => \'a:6:{s:17:"sensitive_content";i:0;s:7:"overlay";i:0;s:11:"remember_me";b:1;s:18:"htmlmail_plaintext";i:0;s:20:"l10n_client_disabled";b:0;s:20:"meedan_notifications";a:20:{s:19:"site_report_flagged";s:19:"site_report_flagged";s:21:"site_report_suggested";s:21:"site_report_suggested";s:22:"site_comment_on_update";s:22:"site_comment_on_update";s:42:"site_update_on_story_i_commented_on_update";s:42:"site_update_on_story_i_commented_on_update";s:31:"site_report_published_in_update";s:31:"site_report_published_in_update";s:22:"site_comment_on_report";s:22:"site_comment_on_report";s:21:"site_reply_to_comment";s:21:"site_reply_to_comment";s:21:"site_fact_checking_on";s:21:"site_fact_checking_on";s:22:"site_fact_checking_set";s:22:"site_fact_checking_set";s:38:"site_fact_status_changed_for_commenter";s:38:"site_fact_status_changed_for_commenter";s:20:"email_report_flagged";s:20:"email_report_flagged";s:22:"email_report_suggested";s:22:"email_report_suggested";s:23:"email_comment_on_update";s:23:"email_comment_on_update";s:43:"email_update_on_story_i_commented_on_update";s:43:"email_update_on_story_i_commented_on_update";s:32:"email_report_published_in_update";s:32:"email_report_published_in_update";s:23:"email_comment_on_report";s:23:"email_comment_on_report";s:22:"email_reply_to_comment";s:22:"email_reply_to_comment";s:22:"email_fact_checking_on";s:22:"email_fact_checking_on";s:23:"email_fact_checking_set";s:23:"email_fact_checking_set";s:39:"email_fact_status_changed_for_commenter";s:39:"email_fact_status_changed_for_commenter";}}\',
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
      \'vid\' => \'261\',
      \'uid\' => \'1\',
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
      \'created\' => \'1359866745\',
      \'changed\' => \'1359867138\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'9ff42c15-5459-4a62-94c2-f45fe8aab3d5\',
      \'revision_timestamp\' => \'1359867138\',
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
      \'name\' => \'admin\',
      \'picture\' => \'4\',
      \'data\' => \'a:6:{s:17:"sensitive_content";i:0;s:7:"overlay";i:0;s:11:"remember_me";b:1;s:18:"htmlmail_plaintext";i:0;s:20:"l10n_client_disabled";b:0;s:20:"meedan_notifications";a:20:{s:19:"site_report_flagged";s:19:"site_report_flagged";s:21:"site_report_suggested";s:21:"site_report_suggested";s:22:"site_comment_on_update";s:22:"site_comment_on_update";s:42:"site_update_on_story_i_commented_on_update";s:42:"site_update_on_story_i_commented_on_update";s:31:"site_report_published_in_update";s:31:"site_report_published_in_update";s:22:"site_comment_on_report";s:22:"site_comment_on_report";s:21:"site_reply_to_comment";s:21:"site_reply_to_comment";s:21:"site_fact_checking_on";s:21:"site_fact_checking_on";s:22:"site_fact_checking_set";s:22:"site_fact_checking_set";s:38:"site_fact_status_changed_for_commenter";s:38:"site_fact_status_changed_for_commenter";s:20:"email_report_flagged";s:20:"email_report_flagged";s:22:"email_report_suggested";s:22:"email_report_suggested";s:23:"email_comment_on_update";s:23:"email_comment_on_update";s:43:"email_update_on_story_i_commented_on_update";s:43:"email_update_on_story_i_commented_on_update";s:32:"email_report_published_in_update";s:32:"email_report_published_in_update";s:23:"email_comment_on_report";s:23:"email_comment_on_report";s:22:"email_reply_to_comment";s:22:"email_reply_to_comment";s:22:"email_fact_checking_on";s:22:"email_fact_checking_on";s:23:"email_fact_checking_set";s:23:"email_fact_checking_set";s:39:"email_fact_status_changed_for_commenter";s:39:"email_fact_status_changed_for_commenter";}}\',
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
      \'vid\' => \'246\',
      \'uid\' => \'1\',
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
      \'created\' => \'1359861563\',
      \'changed\' => \'1359861563\',
      \'tnid\' => \'1\',
      \'translate\' => \'0\',
      \'uuid\' => \'b9dfa9a5-9654-8894-d51b-027bff47c7f1\',
      \'revision_timestamp\' => \'1359861563\',
      \'revision_uid\' => \'1\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => "<div id=\\"info-page-install-bookmarklet\\" class=\\"info-page\\">\\r\\n<div class=\\"install-bookmarklet-col\\">\\r\\n<p><a id=\\"install-bookmarklet-button\\" href=\\"<?php print variable_get(\'meedan_bookmarklet_code\', _meedan_bookmarklet_default_code()); ?>\\"><span>أضف تقرير إلى <?php print variable_get(\'site_name\', \'this site\'); ?></span></a></p>\\r\\n<h3>إسحب هذا الزر <br /> إلى شريط الروابط.</h3>\\r\\n<p>إظهر تعليمات إضافية لمتصفح:</p>\\r\\n<ul>\\r\\n<li><a href=\\"#\\">انترنت اكسبلورر</a></li>\\r\\n<li><a href=\\"#\\">فايرفوكس</a></li>\\r\\n<li><a href=\\"#\\">سفاري</a></li>\\r\\n<li><a href=\\"#\\">كروم</a></li>\\r\\n</ul>\\r\\n</div>\\r\\n<div class=\\"install-bookmarklet-col\\">\\r\\n<h2>تنصيب إضافة المتصفح</h2>\\r\\n<p>زر إضافة المتصفح يمكنك من إضافة تقارير من أي صفحة.</p>\\r\\n<p>بعد التنصيب، انقر الزر وعاين تقريرك الجديد قبل إرساله إلى أحد الأخبار.</p>\\r\\n<p>للتنصيب، إسحب الزر إلى شريط الروابط لدى المتصفح.</p>\\r\\n</div>\\r\\n</div>\\r\\n<script type=\\"text/javascript\\">\\r\\njQuery(\\"#modalContent, #modalBackdrop\\").addClass(\\"modal-install-bookmarklet\\");\\r\\n</script>",
            \'summary\' => \'\',
            \'format\' => \'php_code\',
          ),
        ),
      ),
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
      \'name\' => \'admin\',
      \'picture\' => \'4\',
      \'data\' => \'a:6:{s:17:"sensitive_content";i:0;s:7:"overlay";i:0;s:11:"remember_me";b:1;s:18:"htmlmail_plaintext";i:0;s:20:"l10n_client_disabled";b:0;s:20:"meedan_notifications";a:20:{s:19:"site_report_flagged";s:19:"site_report_flagged";s:21:"site_report_suggested";s:21:"site_report_suggested";s:22:"site_comment_on_update";s:22:"site_comment_on_update";s:42:"site_update_on_story_i_commented_on_update";s:42:"site_update_on_story_i_commented_on_update";s:31:"site_report_published_in_update";s:31:"site_report_published_in_update";s:22:"site_comment_on_report";s:22:"site_comment_on_report";s:21:"site_reply_to_comment";s:21:"site_reply_to_comment";s:21:"site_fact_checking_on";s:21:"site_fact_checking_on";s:22:"site_fact_checking_set";s:22:"site_fact_checking_set";s:38:"site_fact_status_changed_for_commenter";s:38:"site_fact_status_changed_for_commenter";s:20:"email_report_flagged";s:20:"email_report_flagged";s:22:"email_report_suggested";s:22:"email_report_suggested";s:23:"email_comment_on_update";s:23:"email_comment_on_update";s:43:"email_update_on_story_i_commented_on_update";s:43:"email_update_on_story_i_commented_on_update";s:32:"email_report_published_in_update";s:32:"email_report_published_in_update";s:23:"email_comment_on_report";s:23:"email_comment_on_report";s:22:"email_reply_to_comment";s:22:"email_reply_to_comment";s:22:"email_fact_checking_on";s:22:"email_fact_checking_on";s:23:"email_fact_checking_set";s:23:"email_fact_checking_set";s:39:"email_fact_status_changed_for_commenter";s:39:"email_fact_status_changed_for_commenter";}}\',
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
      \'vid\' => \'262\',
      \'uid\' => \'1\',
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
      \'created\' => \'1359866745\',
      \'changed\' => \'1359867110\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'d3c58330-cc88-4e2c-8cc5-e60c4cac0803\',
      \'revision_timestamp\' => \'1359867110\',
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
      \'name\' => \'admin\',
      \'picture\' => \'4\',
      \'data\' => \'a:6:{s:17:"sensitive_content";i:0;s:7:"overlay";i:0;s:11:"remember_me";b:1;s:18:"htmlmail_plaintext";i:0;s:20:"l10n_client_disabled";b:0;s:20:"meedan_notifications";a:20:{s:19:"site_report_flagged";s:19:"site_report_flagged";s:21:"site_report_suggested";s:21:"site_report_suggested";s:22:"site_comment_on_update";s:22:"site_comment_on_update";s:42:"site_update_on_story_i_commented_on_update";s:42:"site_update_on_story_i_commented_on_update";s:31:"site_report_published_in_update";s:31:"site_report_published_in_update";s:22:"site_comment_on_report";s:22:"site_comment_on_report";s:21:"site_reply_to_comment";s:21:"site_reply_to_comment";s:21:"site_fact_checking_on";s:21:"site_fact_checking_on";s:22:"site_fact_checking_set";s:22:"site_fact_checking_set";s:38:"site_fact_status_changed_for_commenter";s:38:"site_fact_status_changed_for_commenter";s:20:"email_report_flagged";s:20:"email_report_flagged";s:22:"email_report_suggested";s:22:"email_report_suggested";s:23:"email_comment_on_update";s:23:"email_comment_on_update";s:43:"email_update_on_story_i_commented_on_update";s:43:"email_update_on_story_i_commented_on_update";s:32:"email_report_published_in_update";s:32:"email_report_published_in_update";s:23:"email_comment_on_report";s:23:"email_comment_on_report";s:22:"email_reply_to_comment";s:22:"email_reply_to_comment";s:22:"email_fact_checking_on";s:22:"email_fact_checking_on";s:23:"email_fact_checking_set";s:23:"email_fact_checking_set";s:39:"email_fact_status_changed_for_commenter";s:39:"email_fact_status_changed_for_commenter";}}\',
      \'path\' => array(
        \'pid\' => \'203\',
        \'source\' => \'node/155\',
        \'alias\' => \'content/about\',
        \'language\' => \'und\',
      ),
      \'menu\' => NULL,
      \'node_export_drupal_version\' => \'7\',
    ),
)',
);
  return $node_export;
}
