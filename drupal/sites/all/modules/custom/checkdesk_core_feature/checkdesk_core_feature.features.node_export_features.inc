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
      \'vid\' => \'6\',
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
      \'language\' => \'und\',
      \'created\' => \'1355419134\',
      \'changed\' => \'1355419134\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'1244c020-f663-b564-b94c-2cf29b12afa4\',
      \'revision_timestamp\' => \'1355419134\',
      \'revision_uid\' => \'0\',
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
      \'last_comment_timestamp\' => \'1355255347\',
      \'last_comment_name\' => NULL,
      \'last_comment_uid\' => \'0\',
      \'comment_count\' => \'0\',
      \'name\' => \'\',
      \'picture\' => \'0\',
      \'data\' => NULL,
      \'menu\' => NULL,
      \'path\' => array(
        \'pid\' => \'1\',
        \'source\' => \'node/1\',
        \'alias\' => \'content/install-bookmarklet\',
        \'language\' => \'und\',
      ),
      \'node_export_drupal_version\' => \'7\',
    ),
)',
);
  return $node_export;
}
