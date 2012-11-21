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
      \'vid\' => \'208\',
      \'uid\' => \'1\',
      \'title\' => \'Install Bookmarklet\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'1\',
      \'promote\' => \'0\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'dbc22e67-cc5a-acf4-a504-6c5e9b04fb6b\',
      \'nid\' => \'208\',
      \'type\' => \'page\',
      \'language\' => \'und\',
      \'created\' => \'1353376399\',
      \'changed\' => \'1353466854\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'1244c020-f663-b564-b94c-2cf29b12afa4\',
      \'revision_timestamp\' => \'1353466854\',
      \'revision_uid\' => \'1\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => "<div id=\\"info-page-install-bookmarklet\\" class=\\"info-page\\">\\r\\n<div style=\\"float: left;\\">\\r\\n<p><a id=\\"install-bookmarklet-button\\">Send to <?php echo variable_get(\'site_name\', \'this site\'); ?></a></p>\\r\\n<h3>Drag this button to your bookmarks bar.</h3>\\r\\n<p>Show extra instructions for:</p>\\r\\n<ul>\\r\\n<li><a href=\\"/content/info/bookmarklet/ie\\">Internet Explorer</a></li>\\r\\n<li><a href=\\"/content/info/bookmarklet/firefox\\">Firefox</a></li>\\r\\n<li><a href=\\"/content/info/bookmarklet/safari\\">Safari</a></li>\\r\\n<li><a href=\\"/content/info/bookmarklet/chrome\\">Chrome</a></li>\\r\\n</ul>\\r\\n</div>\\r\\n<div style=\\"float: right;\\">\\r\\n<h2>Install Bookmarklet</h2>\\r\\n<p>The browser bookmarklet allows you to send us reports from any page.</p>\\r\\n<p>Once you install it, you can click it, preview how the report will appear, and send it to one of our stories.</p>\\r\\n<p>To install the bookmarklet, drag the button into your browser\'s bookmarks toolbar.</p>\\r\\n</div>\\r\\n</div>",
            \'summary\' => \'\',
            \'format\' => \'php_code\',
          ),
        ),
      ),
      \'rdf_mapping\' => array(
        \'rdftype\' => array(
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
      \'last_comment_timestamp\' => \'1353376399\',
      \'last_comment_name\' => NULL,
      \'last_comment_uid\' => \'1\',
      \'comment_count\' => \'0\',
      \'name\' => \'admin\',
      \'picture\' => \'30\',
      \'data\' => \'a:3:{s:17:"sensitive_content";i:0;s:20:"meedan_notifications";a:20:{s:19:"site_report_flagged";s:19:"site_report_flagged";s:21:"site_report_suggested";s:21:"site_report_suggested";s:22:"site_comment_on_update";s:22:"site_comment_on_update";s:42:"site_update_on_story_i_commented_on_update";s:42:"site_update_on_story_i_commented_on_update";s:31:"site_report_published_in_update";s:31:"site_report_published_in_update";s:22:"site_comment_on_report";s:22:"site_comment_on_report";s:21:"site_reply_to_comment";s:21:"site_reply_to_comment";s:21:"site_fact_checking_on";s:21:"site_fact_checking_on";s:22:"site_fact_checking_set";s:22:"site_fact_checking_set";s:38:"site_fact_status_changed_for_commenter";s:38:"site_fact_status_changed_for_commenter";s:20:"email_report_flagged";s:20:"email_report_flagged";s:22:"email_report_suggested";s:22:"email_report_suggested";s:23:"email_comment_on_update";s:23:"email_comment_on_update";s:43:"email_update_on_story_i_commented_on_update";s:43:"email_update_on_story_i_commented_on_update";s:32:"email_report_published_in_update";s:32:"email_report_published_in_update";s:23:"email_comment_on_report";s:23:"email_comment_on_report";s:22:"email_reply_to_comment";s:22:"email_reply_to_comment";s:22:"email_fact_checking_on";s:22:"email_fact_checking_on";s:23:"email_fact_checking_set";s:23:"email_fact_checking_set";s:39:"email_fact_status_changed_for_commenter";s:39:"email_fact_status_changed_for_commenter";}s:11:"remember_me";b:1;}\',
      \'path\' => array(
        \'pid\' => \'208\',
        \'source\' => \'node/208\',
        \'alias\' => \'content/info/install-bookmarklet\',
        \'language\' => \'und\',
      ),
      \'menu\' => NULL,
      \'node_export_drupal_version\' => \'7\',
    ),
)',
);
  return $node_export;
}
