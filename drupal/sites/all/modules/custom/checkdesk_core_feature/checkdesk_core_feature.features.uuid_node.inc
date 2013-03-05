<?php
/**
 * @file
 * checkdesk_core_feature.features.uuid_node.inc
 */

/**
 * Implements hook_uuid_features_default_content().
 */
function checkdesk_core_feature_uuid_features_default_content() {
  $nodes = array();

  $nodes[] = array(
  'uid' => '0',
  'title' => 'شروط الاستخدام',
  'log' => '',
  'status' => '1',
  'comment' => '1',
  'promote' => '0',
  'sticky' => '0',
  'vuuid' => 'a57cb367-19d1-4709-b82b-021ef4f504e0',
  'type' => 'page',
  'language' => 'ar',
  'created' => '1362429920',
  'tnid' => '153',
  'translate' => '0',
  'uuid' => '07d83a6f-e26f-4dd6-9002-a7730dc6250f',
  'revision_uid' => '0',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => 'To be added.',
        'summary' => '',
        'format' => 'filtered_html',
        'safe_value' => '<p>To be added.</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
  'metatags' => array(),
  'rdf_mapping' => array(
    'rdftype' => array(
      0 => 'sioc:Item',
      1 => 'foaf:Document',
    ),
    'title' => array(
      'predicates' => array(
        0 => 'dc:title',
      ),
    ),
    'created' => array(
      'predicates' => array(
        0 => 'dc:date',
        1 => 'dc:created',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'changed' => array(
      'predicates' => array(
        0 => 'dc:modified',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'body' => array(
      'predicates' => array(
        0 => 'content:encoded',
      ),
    ),
    'uid' => array(
      'predicates' => array(
        0 => 'sioc:has_creator',
      ),
      'type' => 'rel',
    ),
    'name' => array(
      'predicates' => array(
        0 => 'foaf:name',
      ),
    ),
    'comment_count' => array(
      'predicates' => array(
        0 => 'sioc:num_replies',
      ),
      'datatype' => 'xsd:integer',
    ),
    'last_activity' => array(
      'predicates' => array(
        0 => 'sioc:last_activity_date',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
  ),
  'cid' => '0',
  'last_comment_name' => NULL,
  'last_comment_uid' => '0',
  'comment_count' => '0',
  'name' => '',
  'picture' => '0',
  'data' => NULL,
  'date' => '2013-03-04 12:45:20 -0800',
);
  $nodes[] = array(
  'uid' => '0',
  'title' => 'Install Bookmarklet',
  'log' => '',
  'status' => '1',
  'comment' => '1',
  'promote' => '0',
  'sticky' => '0',
  'vuuid' => 'dbc22e67-cc5a-acf4-a504-6c5e9b04fb6b',
  'type' => 'page',
  'language' => 'en',
  'created' => '1362429920',
  'tnid' => '1',
  'translate' => '0',
  'uuid' => '1244c020-f663-b564-b94c-2cf29b12afa4',
  'revision_uid' => '0',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '<div id="info-page-install-bookmarklet" class="info-page">
<div class="install-bookmarklet-col">
<p><a id="install-bookmarklet-button" href="<?php print meedan_bookmarklet_get_code(); ?>"><span>Send to <?php print variable_get(\'site_name\', \'this site\'); ?></span></a></p>
<h3>Drag this button <br /> to your bookmarks bar.</h3>
</div>
<div class="install-bookmarklet-col">
<h2>Install Bookmarklet</h2>
<p>The browser bookmarklet allows you to send us reports from any page.</p>
<p>Once you install it, you can click it, preview how the report will appear, and send it to one of our stories.</p>
<p>To install the bookmarklet, drag the button into your browser\'s bookmarks toolbar.</p>
</div>
</div>
<script type="text/javascript">
jQuery("#modalContent, #modalBackdrop").addClass("modal-install-bookmarklet");
</script>',
        'summary' => '',
        'format' => 'php_code',
      ),
    ),
  ),
  'metatags' => array(),
  'rdf_mapping' => array(
    'rdftype' => array(
      0 => 'sioc:Item',
      1 => 'foaf:Document',
    ),
    'title' => array(
      'predicates' => array(
        0 => 'dc:title',
      ),
    ),
    'created' => array(
      'predicates' => array(
        0 => 'dc:date',
        1 => 'dc:created',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'changed' => array(
      'predicates' => array(
        0 => 'dc:modified',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'body' => array(
      'predicates' => array(
        0 => 'content:encoded',
      ),
    ),
    'uid' => array(
      'predicates' => array(
        0 => 'sioc:has_creator',
      ),
      'type' => 'rel',
    ),
    'name' => array(
      'predicates' => array(
        0 => 'foaf:name',
      ),
    ),
    'comment_count' => array(
      'predicates' => array(
        0 => 'sioc:num_replies',
      ),
      'datatype' => 'xsd:integer',
    ),
    'last_activity' => array(
      'predicates' => array(
        0 => 'sioc:last_activity_date',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
  ),
  'cid' => '0',
  'last_comment_name' => NULL,
  'last_comment_uid' => '0',
  'comment_count' => '0',
  'name' => '',
  'picture' => '0',
  'data' => NULL,
  'date' => '2013-03-04 12:45:20 -0800',
);
  $nodes[] = array(
  'uid' => '0',
  'title' => 'Terms of Use',
  'log' => '',
  'status' => '1',
  'comment' => '1',
  'promote' => '0',
  'sticky' => '0',
  'vuuid' => 'b5a5166c-70bc-4230-9978-3d5bba6be921',
  'type' => 'page',
  'language' => 'en',
  'created' => '1362429920',
  'tnid' => '153',
  'translate' => '0',
  'uuid' => '31710726-27dc-4c80-99fc-cb2c79a84053',
  'revision_uid' => '0',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => 'To be added.',
        'summary' => '',
        'format' => 'filtered_html',
        'safe_value' => '<p>To be added.</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
  'metatags' => array(),
  'rdf_mapping' => array(
    'rdftype' => array(
      0 => 'sioc:Item',
      1 => 'foaf:Document',
    ),
    'title' => array(
      'predicates' => array(
        0 => 'dc:title',
      ),
    ),
    'created' => array(
      'predicates' => array(
        0 => 'dc:date',
        1 => 'dc:created',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'changed' => array(
      'predicates' => array(
        0 => 'dc:modified',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'body' => array(
      'predicates' => array(
        0 => 'content:encoded',
      ),
    ),
    'uid' => array(
      'predicates' => array(
        0 => 'sioc:has_creator',
      ),
      'type' => 'rel',
    ),
    'name' => array(
      'predicates' => array(
        0 => 'foaf:name',
      ),
    ),
    'comment_count' => array(
      'predicates' => array(
        0 => 'sioc:num_replies',
      ),
      'datatype' => 'xsd:integer',
    ),
    'last_activity' => array(
      'predicates' => array(
        0 => 'sioc:last_activity_date',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
  ),
  'cid' => '0',
  'last_comment_name' => NULL,
  'last_comment_uid' => '0',
  'comment_count' => '0',
  'name' => '',
  'picture' => '0',
  'data' => NULL,
  'date' => '2013-03-04 12:45:20 -0800',
);
  $nodes[] = array(
  'uid' => '0',
  'title' => 'حول',
  'log' => '',
  'status' => '1',
  'comment' => '1',
  'promote' => '0',
  'sticky' => '0',
  'vuuid' => '79b6bafb-40ac-47ba-a8ac-00f400412c7f',
  'type' => 'page',
  'language' => 'ar',
  'created' => '1362429920',
  'tnid' => '155',
  'translate' => '0',
  'uuid' => '698c6a43-1950-4dd4-bcc2-655f08f49cd8',
  'revision_uid' => '0',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => 'To be added.',
        'summary' => '',
        'format' => 'filtered_html',
        'safe_value' => '<p>To be added.</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
  'metatags' => array(),
  'rdf_mapping' => array(
    'rdftype' => array(
      0 => 'sioc:Item',
      1 => 'foaf:Document',
    ),
    'title' => array(
      'predicates' => array(
        0 => 'dc:title',
      ),
    ),
    'created' => array(
      'predicates' => array(
        0 => 'dc:date',
        1 => 'dc:created',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'changed' => array(
      'predicates' => array(
        0 => 'dc:modified',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'body' => array(
      'predicates' => array(
        0 => 'content:encoded',
      ),
    ),
    'uid' => array(
      'predicates' => array(
        0 => 'sioc:has_creator',
      ),
      'type' => 'rel',
    ),
    'name' => array(
      'predicates' => array(
        0 => 'foaf:name',
      ),
    ),
    'comment_count' => array(
      'predicates' => array(
        0 => 'sioc:num_replies',
      ),
      'datatype' => 'xsd:integer',
    ),
    'last_activity' => array(
      'predicates' => array(
        0 => 'sioc:last_activity_date',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
  ),
  'cid' => '0',
  'last_comment_name' => NULL,
  'last_comment_uid' => '0',
  'comment_count' => '0',
  'name' => '',
  'picture' => '0',
  'data' => NULL,
  'date' => '2013-03-04 12:45:20 -0800',
);
  $nodes[] = array(
  'uid' => '0',
  'title' => 'Fact Checking statement',
  'log' => '',
  'status' => '1',
  'comment' => '1',
  'promote' => '0',
  'sticky' => '0',
  'vuuid' => '86e41833-6e4d-496e-b2be-11036d7a12b3',
  'type' => 'page',
  'language' => 'en',
  'created' => '1362429920',
  'tnid' => '154',
  'translate' => '0',
  'uuid' => '9ff42c15-5459-4a62-94c2-f45fe8aab3d5',
  'revision_uid' => '0',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => 'To be added.',
        'summary' => '',
        'format' => 'filtered_html',
        'safe_value' => '<p>To be added.</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
  'metatags' => array(),
  'rdf_mapping' => array(
    'rdftype' => array(
      0 => 'sioc:Item',
      1 => 'foaf:Document',
    ),
    'title' => array(
      'predicates' => array(
        0 => 'dc:title',
      ),
    ),
    'created' => array(
      'predicates' => array(
        0 => 'dc:date',
        1 => 'dc:created',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'changed' => array(
      'predicates' => array(
        0 => 'dc:modified',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'body' => array(
      'predicates' => array(
        0 => 'content:encoded',
      ),
    ),
    'uid' => array(
      'predicates' => array(
        0 => 'sioc:has_creator',
      ),
      'type' => 'rel',
    ),
    'name' => array(
      'predicates' => array(
        0 => 'foaf:name',
      ),
    ),
    'comment_count' => array(
      'predicates' => array(
        0 => 'sioc:num_replies',
      ),
      'datatype' => 'xsd:integer',
    ),
    'last_activity' => array(
      'predicates' => array(
        0 => 'sioc:last_activity_date',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
  ),
  'cid' => '0',
  'last_comment_name' => NULL,
  'last_comment_uid' => '0',
  'comment_count' => '0',
  'name' => '',
  'picture' => '0',
  'data' => NULL,
  'date' => '2013-03-04 12:45:20 -0800',
);
  $nodes[] = array(
  'uid' => '0',
  'title' => 'تنصيب إضافة المتصفح',
  'log' => '',
  'status' => '1',
  'comment' => '1',
  'promote' => '0',
  'sticky' => '0',
  'vuuid' => '310a0c27-0d6b-3344-4d3b-6ce3884081f4',
  'type' => 'page',
  'language' => 'ar',
  'created' => '1362429920',
  'tnid' => '1',
  'translate' => '0',
  'uuid' => 'b9dfa9a5-9654-8894-d51b-027bff47c7f1',
  'revision_uid' => '0',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '<div id="info-page-install-bookmarklet" class="info-page">
<div class="install-bookmarklet-col">
<p><a id="install-bookmarklet-button" href="<?php print meedan_bookmarklet_get_code(); ?>"><span>أضف تقرير إلى <?php print variable_get(\'site_name\', \'this site\'); ?></span></a></p>
<h3>إسحب هذا الزر <br /> إلى شريط الروابط.</h3>
</div>
<div class="install-bookmarklet-col">
<h2>تنصيب إضافة المتصفح</h2>
<p>زر إضافة المتصفح يمكنك من إضافة تقارير من أي صفحة.</p>
<p>بعد التنصيب، انقر الزر وعاين تقريرك الجديد قبل إرساله إلى أحد الأخبار.</p>
<p>للتنصيب، إسحب الزر إلى شريط الروابط لدى المتصفح.</p>
</div>
</div>
<script type="text/javascript">
jQuery("#modalContent, #modalBackdrop").addClass("modal-install-bookmarklet");
</script>',
        'summary' => '',
        'format' => 'php_code',
      ),
    ),
  ),
  'metatags' => array(),
  'rdf_mapping' => array(
    'rdftype' => array(
      0 => 'sioc:Item',
      1 => 'foaf:Document',
    ),
    'title' => array(
      'predicates' => array(
        0 => 'dc:title',
      ),
    ),
    'created' => array(
      'predicates' => array(
        0 => 'dc:date',
        1 => 'dc:created',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'changed' => array(
      'predicates' => array(
        0 => 'dc:modified',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'body' => array(
      'predicates' => array(
        0 => 'content:encoded',
      ),
    ),
    'uid' => array(
      'predicates' => array(
        0 => 'sioc:has_creator',
      ),
      'type' => 'rel',
    ),
    'name' => array(
      'predicates' => array(
        0 => 'foaf:name',
      ),
    ),
    'comment_count' => array(
      'predicates' => array(
        0 => 'sioc:num_replies',
      ),
      'datatype' => 'xsd:integer',
    ),
    'last_activity' => array(
      'predicates' => array(
        0 => 'sioc:last_activity_date',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
  ),
  'cid' => '0',
  'last_comment_name' => NULL,
  'last_comment_uid' => '0',
  'comment_count' => '0',
  'name' => '',
  'picture' => '0',
  'data' => NULL,
  'date' => '2013-03-04 12:45:20 -0800',
);
  $nodes[] = array(
  'uid' => '0',
  'title' => 'About',
  'log' => '',
  'status' => '1',
  'comment' => '1',
  'promote' => '0',
  'sticky' => '0',
  'vuuid' => '290717c7-aa65-4053-80d2-59c0a35bc43d',
  'type' => 'page',
  'language' => 'en',
  'created' => '1362429920',
  'tnid' => '155',
  'translate' => '0',
  'uuid' => 'd3c58330-cc88-4e2c-8cc5-e60c4cac0803',
  'revision_uid' => '0',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => 'To be added.',
        'summary' => '',
        'format' => 'filtered_html',
        'safe_value' => '<p>To be added.</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
  'metatags' => array(),
  'rdf_mapping' => array(
    'rdftype' => array(
      0 => 'sioc:Item',
      1 => 'foaf:Document',
    ),
    'title' => array(
      'predicates' => array(
        0 => 'dc:title',
      ),
    ),
    'created' => array(
      'predicates' => array(
        0 => 'dc:date',
        1 => 'dc:created',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'changed' => array(
      'predicates' => array(
        0 => 'dc:modified',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'body' => array(
      'predicates' => array(
        0 => 'content:encoded',
      ),
    ),
    'uid' => array(
      'predicates' => array(
        0 => 'sioc:has_creator',
      ),
      'type' => 'rel',
    ),
    'name' => array(
      'predicates' => array(
        0 => 'foaf:name',
      ),
    ),
    'comment_count' => array(
      'predicates' => array(
        0 => 'sioc:num_replies',
      ),
      'datatype' => 'xsd:integer',
    ),
    'last_activity' => array(
      'predicates' => array(
        0 => 'sioc:last_activity_date',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
  ),
  'cid' => '0',
  'last_comment_name' => NULL,
  'last_comment_uid' => '0',
  'comment_count' => '0',
  'name' => '',
  'picture' => '0',
  'data' => NULL,
  'date' => '2013-03-04 12:45:20 -0800',
);
  $nodes[] = array(
  'uid' => '0',
  'title' => 'بيان التحقق من صحة المعلومات',
  'log' => '',
  'status' => '1',
  'comment' => '1',
  'promote' => '0',
  'sticky' => '0',
  'vuuid' => '4a98224f-7a94-4a13-8d2c-dd8159180d64',
  'type' => 'page',
  'language' => 'ar',
  'created' => '1362429920',
  'tnid' => '154',
  'translate' => '0',
  'uuid' => 'f71822ad-79b3-4479-bd09-10a9a8ba1223',
  'revision_uid' => '0',
  'body' => array(
    'und' => array(
      0 => array(
        'value' => 'To be added.',
        'summary' => '',
        'format' => 'filtered_html',
        'safe_value' => '<p>To be added.</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
  'metatags' => array(),
  'rdf_mapping' => array(
    'rdftype' => array(
      0 => 'sioc:Item',
      1 => 'foaf:Document',
    ),
    'title' => array(
      'predicates' => array(
        0 => 'dc:title',
      ),
    ),
    'created' => array(
      'predicates' => array(
        0 => 'dc:date',
        1 => 'dc:created',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'changed' => array(
      'predicates' => array(
        0 => 'dc:modified',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'body' => array(
      'predicates' => array(
        0 => 'content:encoded',
      ),
    ),
    'uid' => array(
      'predicates' => array(
        0 => 'sioc:has_creator',
      ),
      'type' => 'rel',
    ),
    'name' => array(
      'predicates' => array(
        0 => 'foaf:name',
      ),
    ),
    'comment_count' => array(
      'predicates' => array(
        0 => 'sioc:num_replies',
      ),
      'datatype' => 'xsd:integer',
    ),
    'last_activity' => array(
      'predicates' => array(
        0 => 'sioc:last_activity_date',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
  ),
  'cid' => '0',
  'last_comment_name' => NULL,
  'last_comment_uid' => '0',
  'comment_count' => '0',
  'name' => '',
  'picture' => '0',
  'data' => NULL,
  'date' => '2013-03-04 12:45:20 -0800',
);
  return $nodes;
}
