<?php
/**
 * @file
 * checkdesk_core_feature.features.translations.inc
 */

/**
 * Implements hook_translations_defaults().
 */
function checkdesk_core_feature_translations_defaults() {
  $translations = array();
  $translatables = array();
  $translations['ar:default']['0015b64f0747dd1206adf2a68995fd6a'] = array(
    'source' => 'Source frequency of reports in any given month.',
    'context' => '',
    'location' => '/checkdesk/ar/admin/meedan/reports',
    'translation' => 'تعداد المصادر المختلفة في شهر معين',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Source frequency of reports in any given month.', array(), array('context' => ''));
  $translations['ar:default']['0046311d21a0ef8a6b714966cd1ccfd3'] = array(
    'source' => 'The module\'s database schema version number. -1 if the module is not installed (its tables do not exist); 0 or the largest N of the module\'s hook_update_N() function that has either been run or existed when the module was first installed.',
    'context' => '',
    'location' => '',
    'translation' => 'الوحدة النمطية إصدار المخطط قاعدة بيانات الرقم. -1 إذا لم يتم تثبيت وحدة (الجداول الخاصة به غير موجودة)؛ 0 أو أكبر من N ظيفة hook_update_N () الوحدة النمطية التي إما تم تشغيل أو كانت موجودة عندما تم تثبيت وحدة لأول مرة.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The module\'s database schema version number. -1 if the module is not installed (its tables do not exist); 0 or the largest N of the module\'s hook_update_N() function that has either been run or existed when the module was first installed.', array(), array('context' => ''));
  $translations['ar:default']['0127f2be472a7ec6c4bea159a1d4e591'] = array(
    'source' => 'Add Report "!title" to Story',
    'context' => '',
    'location' => '/ar/node/63/checkdesk/modal/suggest/ajax',
    'translation' => 'أضف التقرير "!title" إلى موضوع',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Add Report "!title" to Story', array(), array('context' => ''));
  $translations['ar:default']['0130b123aeb9373a1f6d376d61ca8a53'] = array(
    'source' => 'Hello !recipient_name,

!author has added a <a href="!url">new update</a> to the story "!title".
',
    'context' => '',
    'location' => '/index.php',
    'translation' => 'مرحباً !recipient_name،

قام !author بإضافة  <a href="!url"> تحديث </a> للموضوع "!title".
',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Hello !recipient_name,

!author has added a <a href="!url">new update</a> to the story "!title".
', array(), array('context' => ''));
  $translations['ar:default']['0175dd5c43229b54c942ecc26a34185e'] = array(
    'source' => 'Translate Text',
    'context' => '',
    'location' => 'sites/all/modules/contrib/l10n_client/l10n_client.js',
    'translation' => 'ترجمة النص',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Translate Text', array(), array('context' => ''));
  $translations['ar:default']['019d3a9016bc113135b655858ecbbcfa'] = array(
    'source' => 'User page',
    'context' => '',
    'location' => '',
    'translation' => 'صفحة المستخدم',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('User page', array(), array('context' => ''));
  $translations['ar:default']['01a569ddc6cf67ddec2a683f0a5f5956'] = array(
    'source' => 'Forgot your password?',
    'context' => '',
    'location' => '/ar/user/login',
    'translation' => 'هل نسيت كلمة السر؟',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Forgot your password?', array(), array('context' => ''));
  $translations['ar:default']['01cfad95e7698dba435c638164db02d9'] = array(
    'source' => 'Next - <span>@step</span>',
    'context' => '',
    'location' => 'sites/all/themes/checkdesk/assets/js/tour.js; sites/all/modules/custom/checkdesk_tour/js/tour.js',
    'translation' => '<span>@step</span> - التالي
',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Next - <span>@step</span>', array(), array('context' => ''));
  $translations['ar:default']['02684cc6b6ea1811a064f475a5fd1d18'] = array(
    'source' => 'Authors',
    'context' => '',
    'location' => '/ar/search?type=discussion',
    'translation' => 'المؤلفين',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Authors', array(), array('context' => ''));
  $translations['ar:default']['027743ed356b26d5fc78bd42eee42896'] = array(
    'source' => 'The name of the author of the last posted comment.',
    'context' => '',
    'location' => '',
    'translation' => 'اسم كاتب آخر تعليق ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The name of the author of the last posted comment.', array(), array('context' => ''));
  $translations['ar:default']['02b272d291df1e1627f01ce3262b4a84'] = array(
    'source' => 'Add new view',
    'context' => '',
    'location' => '',
    'translation' => 'إضافة رؤية جديدة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Add new view', array(), array('context' => ''));
  $translations['ar:default']['02f3f89d7acb7536a8a2085625824420'] = array(
    'source' => 'Flagged for spam',
    'context' => '',
    'location' => '/ar/node/flag/confirm/flag/spam/14/ajax',
    'translation' => 'تم تنبيه السخام',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Flagged for spam', array(), array('context' => ''));
  $translations['ar:default']['02f95718ac97a9690023f25cff58cc0c'] = array(
    'source' => 'User target ID,  addressee in the activity message',
    'context' => '',
    'location' => '/ar',
    'translation' => 'ID المستخدم المستهدف في النص المفعل ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('User target ID,  addressee in the activity message', array(), array('context' => ''));
  $translations['ar:default']['034a9d61a9484ff68025fb7e0a6e43c1'] = array(
    'source' => 'Fact-checking set on a report by citizen journalist',
    'context' => '',
    'location' => '',
    'translation' => 'تفعيل تقصي صحة المعلومات على تقرير من قبل مواطن صحفى',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Fact-checking set on a report by citizen journalist', array(), array('context' => ''));
  $translations['ar:default']['0379554cecb3334c680d03942465f821'] = array(
    'source' => 'Save translation',
    'context' => '',
    'location' => '',
    'translation' => 'حفظ الترجمة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Save translation', array(), array('context' => ''));
  $translations['ar:default']['03d947a2158373c3b9d74325850cb8b9'] = array(
    'source' => 'Post',
    'context' => '',
    'location' => '',
    'translation' => 'مقالة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Post', array(), array('context' => ''));
  $translations['ar:default']['03dc80844bd839d93772def8cd727bc6'] = array(
    'source' => ' Users',
    'context' => '',
    'location' => '',
    'translation' => 'المستخدمون',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t(' Users', array(), array('context' => ''));
  $translations['ar:default']['03fa5c741291620f0297f5740db0f662'] = array(
    'source' => 'A file that is associated with this node, usually because it is in a field on the node.',
    'context' => '',
    'location' => '',
    'translation' => 'ملف مقترن بهذه العقدة، لأنه عادة في حقل على العقدة.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('A file that is associated with this node, usually because it is in a field on the node.', array(), array('context' => ''));
  $translations['ar:default']['0423256c9dd56eaaabb61a7342935886'] = array(
    'source' => 'Filter value type',
    'context' => '',
    'location' => '',
    'translation' => 'نوع قيمة المرشح',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Filter value type', array(), array('context' => ''));
  $translations['ar:default']['0464d6d0accb32575a705f88c04ec7d9'] = array(
    'source' => 'Render Views filters as select list',
    'context' => '',
    'location' => '',
    'translation' => 'فلاتر العرض كقائمة اختيار',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Render Views filters as select list', array(), array('context' => ''));
  $translations['ar:default']['048c4ecb256dc6934f8f9af161438c37'] = array(
    'source' => 'Provide a simple link to the content.',
    'context' => '',
    'location' => '',
    'translation' => 'تقديم وصلة بسيطة إلى المحتوى.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Provide a simple link to the content.', array(), array('context' => ''));
  $translations['ar:default']['04ec3b36351857d6430b295f91a19688'] = array(
    'source' => 'Liveblog update',
    'context' => '',
    'location' => '',
    'translation' => 'مدونة مباشرة تحديث',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Liveblog update', array(), array('context' => ''));
  $translations['ar:default']['051e5ce1a082d4902dec835df60f1d1a'] = array(
    'source' => 'Flaggable node',
    'context' => '',
    'location' => '',
    'translation' => 'عقده قابله للتنبيه',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Flaggable node', array(), array('context' => ''));
  $translations['ar:default']['053aba5308c5224ef53d2011dd824e03'] = array(
    'source' => 'Approve link',
    'context' => '',
    'location' => '',
    'translation' => 'رابط الموافقة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Approve link', array(), array('context' => ''));
  $translations['ar:default']['054944c7b24f864b989be188f80e3112'] = array(
    'source' => '!field_name',
    'context' => '',
    'location' => '',
    'translation' => 'اسم الحقل ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('!field_name', array(), array('context' => ''));
  $translations['ar:default']['054a78c1caeec3f8c15eebfa9de7105c'] = array(
    'source' => 'The language code of the current user interface language.',
    'context' => '',
    'location' => '',
    'translation' => 'رمز اللغة من لغة واجهة المستخدم الحالية.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The language code of the current user interface language.', array(), array('context' => ''));
  $translations['ar:default']['0590a7b5f472aa655c16a8106410676b'] = array(
    'source' => 'Attachments added to other displays to achieve multiple views in the same view.',
    'context' => '',
    'location' => '',
    'translation' => 'Attachments added to other displays to achieve multiple views in the same view.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Attachments added to other displays to achieve multiple views in the same view.', array(), array('context' => ''));
  $translations['ar:default']['05a4dcfc8838f777d78edfaf09d2e901'] = array(
    'source' => 'Paged output, full pager',
    'context' => '',
    'location' => '',
    'translation' => 'Paged output, full pager',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Paged output, full pager', array(), array('context' => ''));
  $translations['ar:default']['05c89373892514c01a51a8e1584146a3'] = array(
    'source' => 'The unique ID of the object that has been flagged.',
    'context' => '',
    'location' => '',
    'translation' => 'المعرف الفريد للكائن الذي تم وضع علامة عليه.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The unique ID of the object that has been flagged.', array(), array('context' => ''));
  $translations['ar:default']['05fdb5ab6645a8f6632ad0555752cab9'] = array(
    'source' => 'The weight of the term, which is used for ordering terms during display.',
    'context' => '',
    'location' => '',
    'translation' => 'وزن للمصطلح، والذي يستخدم لترتيب الشروط خلال العرض.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The weight of the term, which is used for ordering terms during display.', array(), array('context' => ''));
  $translations['ar:default']['066476372ecb5f1ee900a8b6a504c0e3'] = array(
    'source' => 'The user ID',
    'context' => '',
    'location' => '',
    'translation' => ' هوية المستخدم',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The user ID', array(), array('context' => ''));
  $translations['ar:default']['066db78bcad0674d9d1375265ae729ed'] = array(
    'source' => 'Has taxonomy term ID (with depth)',
    'context' => '',
    'location' => '',
    'translation' => 'Has taxonomy term ID (with depth)',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Has taxonomy term ID (with depth)', array(), array('context' => ''));
  $translations['ar:default']['06a8886071c2de2ab6933f68d9b9958f'] = array(
    'source' => 'Title, as plain text',
    'context' => '',
    'location' => '',
    'translation' => 'العنوان، كنص عادي',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Title, as plain text', array(), array('context' => ''));
  $translations['ar:default']['06b86dc8517cde8e5e9249e9964b2a49'] = array(
    'source' => 'Math expression',
    'context' => '',
    'location' => '',
    'translation' => 'تعابير رياضيه ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Math expression', array(), array('context' => ''));
  $translations['ar:default']['06c6b44282c2e576425a93e101a7f3ba'] = array(
    'source' => 'Is one of',
    'context' => '',
    'location' => '',
    'translation' => 'هي واحدة من',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Is one of', array(), array('context' => ''));
  $translations['ar:default']['06d6c98f323c049ed4d828c0b6674973'] = array(
    'source' => 'Social user mode',
    'context' => '',
    'location' => '/ar',
    'translation' => 'وضع المستخدم الاجتماعي',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Social user mode', array(), array('context' => ''));
  $translations['ar:default']['06e3d36fa30cea095545139854ad1fb9'] = array(
    'source' => 'field',
    'context' => '',
    'location' => '',
    'translation' => 'حقل',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('field', array(), array('context' => ''));
  $translations['ar:default']['06ef34a61e8b3d9b95e3bd115d089b08'] = array(
    'source' => 'Name of the vocabulary a term is a member of. This will be the vocabulary that whichever term the "Taxonomy: Term" field is; and can similarly cause duplicates.',
    'context' => '',
    'location' => '',
    'translation' => 'اسم المفردات مصطلح عضو. وستكون هذه المفردات التي أيهما مصطلح  "للتصنيف: مصطلح " الحقل، وبالمثل يمكن أن يسبب التكرارات.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Name of the vocabulary a term is a member of. This will be the vocabulary that whichever term the "Taxonomy: Term" field is; and can similarly cause duplicates.', array(), array('context' => ''));
  $translations['ar:default']['0719cfa6d7799fec6a6562d6e298dd75'] = array(
    'source' => 'You can edit your notification settings from your <a href="!recipient_url">profile page</a>.',
    'context' => '',
    'location' => '/index.php',
    'translation' => 'بإمكانك تعديل إعدادات التنبيهات الخاصة بك من صفحة <a href="!recipient_url">الحساب الشخصي</a> الخاصة بك.
',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('You can edit your notification settings from your <a href="!recipient_url">profile page</a>.', array(), array('context' => ''));
  $translations['ar:default']['0748856bca50f42e2abd5b36ca083bae'] = array(
    'source' => 'Hierarchy',
    'context' => '',
    'location' => '',
    'translation' => 'التدرج',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Hierarchy', array(), array('context' => ''));
  $translations['ar:default']['0776b448ce5219c496a22dbca35fdbf8'] = array(
    'source' => 'added by !link',
    'context' => '',
    'location' => '',
    'translation' => 'أضيف من قبل !link',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('added by !link', array(), array('context' => ''));
  $translations['ar:default']['07c85e5b12c43c323e6c6e0d62e7a367'] = array(
    'source' => 'View description',
    'context' => '',
    'location' => '',
    'translation' => 'مشاهدة الوصف',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('View description', array(), array('context' => ''));
  $translations['ar:default']['0800dea6c0d5a973c444dda9ff97e598'] = array(
    'source' => 'Taxonomy vocabularies',
    'context' => '',
    'location' => '',
    'translation' => ' مفردات التصنيف',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Taxonomy vocabularies', array(), array('context' => ''));
  $translations['ar:default']['083f62fcae98023532c130f6c6506bd5'] = array(
    'source' => 'Add a link',
    'context' => '',
    'location' => '/ar/node/add/media?meedan_bookmarklet=1&meedan_bookmarklet_prepopulate[body]=&meedan_bookmarklet_prepopulate[field_link]=http://checkdesk.localhost/ar',
    'translation' => 'أضف رابطاً',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Add a link', array(), array('context' => ''));
  $translations['ar:default']['08e6b221979cfb3b1b97c5f622877590'] = array(
    'source' => 'Displays rows one after another.',
    'context' => '',
    'location' => '',
    'translation' => 'يعرض الصفوف بطريقة متتاليه ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Displays rows one after another.', array(), array('context' => ''));
  $translations['ar:default']['08f9e649a8bad98db68b4e8e5770d219'] = array(
    'source' => '<time datetime="!date">!interval ago</time>',
    'context' => '',
    'location' => '/',
    'translation' => '<time datetime="!date">منذ !interval</time>',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('<time datetime="!date">!interval ago</time>', array(), array('context' => ''));
  $translations['ar:default']['0932388ad460202b7fe491686b8a664d'] = array(
    'source' => 'Tid',
    'context' => '',
    'location' => '',
    'translation' => 'Tid',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Tid', array(), array('context' => ''));
  $translations['ar:default']['094bbf80f2ce96fd4ef71a0b153a43ff'] = array(
    'source' => '@counts',
    'context' => '',
    'location' => '/checkdesk/ar',
    'translation' => '@countثا',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('@counts', array(), array('context' => ''));
  $translations['ar:default']['095c57c38c272a3ea10428c626b98da9'] = array(
    'source' => '@count[4] rows',
    'context' => '',
    'location' => '',
    'translation' => '@count[4] سطر',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('@count[4] rows', array(), array('context' => ''));
  $translations['ar:default']['099fb995346f31c749f6e40db0f395e3'] = array(
    'source' => 'header',
    'context' => '',
    'location' => '',
    'translation' => 'ترويسة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('header', array(), array('context' => ''));
  $translations['ar:default']['09ac620b2f001b0f0fa33e9189a35f8a'] = array(
    'source' => 'The \'Body\' field of the e-mail.',
    'context' => '',
    'location' => '/ar',
    'translation' => 'و\'الهيئة\' في مجال البريد الإلكتروني.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The \'Body\' field of the e-mail.', array(), array('context' => ''));
  $translations['ar:default']['0a426adb3ec0ea76d29dc2f2650bf2d2'] = array(
    'source' => 'The universally unique ID.',
    'context' => '',
    'location' => '/ar',
    'translation' => 'المعرف الفريد عالميا.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The universally unique ID.', array(), array('context' => ''));
  $translations['ar:default']['0a68d22be870153de4534b3c2d053cff'] = array(
    'source' => 'Relate all media sources on the node. This can produce duplicate entries if a node includes multiple media sources.',
    'context' => '',
    'location' => '/ar',
    'translation' => 'تتصل جميع مصادر إعلامية على العقدة. وهذا يمكن أن ينتج إدخالات مكررة إذا عقدة يتضمن عدة مصادر إعلامية.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Relate all media sources on the node. This can produce duplicate entries if a node includes multiple media sources.', array(), array('context' => ''));
  $translations['ar:default']['0ae2ebb9f6f20fce75fab2ddeb730f05'] = array(
    'source' => 'The original-language version of this node, if one exists.',
    'context' => '',
    'location' => '',
    'translation' => 'النص الأصلي باللغة من هذه العقدة، إذا وجدت.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The original-language version of this node, if one exists.', array(), array('context' => ''));
  $translations['ar:default']['0b4db271fc4624853e634ef6882ea8be'] = array(
    'source' => 'View all',
    'context' => '',
    'location' => '/ar',
    'translation' => 'عرض الكل',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('View all', array(), array('context' => ''));
  $translations['ar:default']['0b79795d3efc95b9976c7c5b933afce2'] = array(
    'source' => 'Introduction',
    'context' => '',
    'location' => '/ar/node/add/discussion',
    'translation' => 'المقدمة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Introduction', array(), array('context' => ''));
  $translations['ar:default']['0b90582f4589d84be89f5b847d4d1ed1'] = array(
    'source' => 'Highlight',
    'context' => '',
    'location' => '/ar',
    'translation' => 'تسليط الضوء',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Highlight', array(), array('context' => ''));
  $translations['ar:default']['0b98b46436389e9a4fdac115a7105819'] = array(
    'source' => 'Write text and drag reports here to compose the update',
    'context' => '',
    'location' => '/ar/node/add/post',
    'translation' => 'اكتب النص واسحب التقارير هنا لإنشاء التحديث',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Write text and drag reports here to compose the update', array(), array('context' => ''));
  $translations['ar:default']['0b9dbff101eb8cc6a90677677cb83167'] = array(
    'source' => 'Uses reports added by !users',
    'context' => '',
    'location' => '/ar/story-collaboration/112',
    'translation' => 'يحتوي على تقارير من !users',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Uses reports added by !users', array(), array('context' => ''));
  $translations['ar:default']['0c44eee1298157ea76fa8600aaa6dc85'] = array(
    'source' => 'Shows result summary, for example the items per page.',
    'context' => '',
    'location' => '',
    'translation' => 'يظهر ملخص ذلك، على سبيل المثال العناصر في الصفحة.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Shows result summary, for example the items per page.', array(), array('context' => ''));
  $translations['ar:default']['0c501c199fe9a43f4139e8baa1f03f50'] = array(
    'source' => 'Show reports from this source',
    'context' => '',
    'location' => '',
    'translation' => 'اعرض تقارير من هذا المصدر',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Show reports from this source', array(), array('context' => ''));
  $translations['ar:default']['0cf51369fcd5f2440ee5701261ee0b3e'] = array(
    'source' => 'Result summary',
    'context' => '',
    'location' => '',
    'translation' => 'ملخص النتيجة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Result summary', array(), array('context' => ''));
  $translations['ar:default']['0cf9ee97116b4d1161865cc3a6ea64da'] = array(
    'source' => '@countm',
    'context' => '',
    'location' => '/checkdesk/ar',
    'translation' => '@countد',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('@countm', array(), array('context' => ''));
  $translations['ar:default']['0d015d96f63a8c12d96b8399482b593f'] = array(
    'source' => 'Uncategorized',
    'context' => '',
    'location' => '',
    'translation' => 'غير مصنف',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Uncategorized', array(), array('context' => ''));
  $translations['ar:default']['0d250bc0efe3cc1b9740a8ec333ef899'] = array(
    'source' => 'Flag counter',
    'context' => '',
    'location' => '',
    'translation' => 'عداد التحذيرات',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Flag counter', array(), array('context' => ''));
  $translations['ar:default']['0d3683fe6ae8331e39e360490ae2b41e'] = array(
    'source' => '@count[4] more updates',
    'context' => '',
    'location' => '/meedan/meedan-checkdesk/drupal/',
    'translation' => '@count[4] تحديثات أخرى',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('@count[4] more updates', array(), array('context' => ''));
  $translations['ar:default']['0d6ef183b909622b9467eb011ca633a7'] = array(
    'source' => 'Send us newsworthy links from social media; we\'ll fact-check and publish them.',
    'context' => '',
    'location' => '/ar/user',
    'translation' => 'ابعث لنا روابط تستحق التغطية الإعلامية من الشبكات الاجتماعية؛ سنتحقق من صحتها وننشرها.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Send us newsworthy links from social media; we\'ll fact-check and publish them.', array(), array('context' => ''));
  $translations['ar:default']['0d98f23eefd51d229d0e47f4ae58d68a'] = array(
    'source' => 'Content with term',
    'context' => '',
    'location' => '',
    'translation' => 'المحتوى مع مصطلح',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Content with term', array(), array('context' => ''));
  $translations['ar:default']['0e7c87e41a688c405efa166c0b8c981c'] = array(
    'source' => 'Jerusalem, Palestine',
    'context' => '',
    'location' => '/meedan/meedan-checkdesk/drupal/ar/node/15692',
    'translation' => 'القدس',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Jerusalem, Palestine', array(), array('context' => ''));
  $translations['ar:default']['0f0722e40879e7ec7dc025953732e76a'] = array(
    'source' => 'The media source URL',
    'context' => '',
    'location' => '/ar',
    'translation' => 'وURL مصدر وسائل الاعلام',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The media source URL', array(), array('context' => ''));
  $translations['ar:default']['0f4b6239381f5c56d5831751a96e1e74'] = array(
    'source' => '!results found',
    'context' => '',
    'location' => '/ar/search',
    'translation' => 'تم العثور على !results ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('!results found', array(), array('context' => ''));
  $translations['ar:default']['0f6969d7052da9261e31ddb6e88c136e'] = array(
    'source' => 'remove',
    'context' => '',
    'location' => '',
    'translation' => 'إزالة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('remove', array(), array('context' => ''));
  $translations['ar:default']['0f9d51c9cb4b5cee06a676a45110f955'] = array(
    'source' => 'Roles that a user belongs to.',
    'context' => '',
    'location' => '',
    'translation' => 'الأدوار التي ينتمي إليها المستخدم.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Roles that a user belongs to.', array(), array('context' => ''));
  $translations['ar:default']['0fc915d84f28907f093624f8c498d4dd'] = array(
    'source' => 'Report submitted, thanks!',
    'context' => '',
    'location' => '/ar/meedan_bookmarklet/message?meedan_bookmarklet=1&meedan_bookmarklet_submitted=1&meedan_bookmarklet_nid=236',
    'translation' => 'تم إرسال التقرير، شكراً!',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Report submitted, thanks!', array(), array('context' => ''));
  $translations['ar:default']['0ff05cf7cd12d0e9065b434347ff3413'] = array(
    'source' => '<a href="!user_url" class="actor">!username</a> has turned on fact-checking for a <a href="!report_url">report</a> they submitted. Fact checking is in progress.',
    'context' => '',
    'location' => '/ar/flag/flag/factcheck_journalist/12312?destination=story-collaboration/12311&token=HZIGWOz96F2ZQRh8YYhqs1any5x1BiNmA9ybc8HnFNo',
    'translation' => 'قام <a href="!user_url">!username</a> بتفعيل التحقق من صحة المعلومات <a href="!report_url">للتقرير</a> الذي تم انشائه. التحقق من صحة المعلومات جارٍ.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('<a href="!user_url" class="actor">!username</a> has turned on fact-checking for a <a href="!report_url">report</a> they submitted. Fact checking is in progress.', array(), array('context' => ''));
  $translations['ar:default']['102cd9777c5cb9b3fdff5c8c1fcccf5f'] = array(
    'source' => 'Note: Your story won\'t be published to the liveblog homepage until you add an update to your story.',
    'context' => '',
    'location' => '/ar/node/add/discussion',
    'translation' => 'ملحوظة: لن يتم نشر موضوعك إلا بعد إضافة تحديث له.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Note: Your story won\'t be published to the liveblog homepage until you add an update to your story.', array(), array('context' => ''));
  $translations['ar:default']['1046841c157b3047c1f4066a7c50adda'] = array(
    'source' => 'Users who have created accounts on your site.',
    'context' => '',
    'location' => '',
    'translation' => 'المستخدمون الذين قاموا بإنشاء حسابات على موقعك.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Users who have created accounts on your site.', array(), array('context' => ''));
  $translations['ar:default']['10486303f428334ad108f820a97323b9'] = array(
    'source' => 'Hello !recipient_name,

!flagging_user_name has flagged the following <a href="!flagged_node_url">report</a> under "!flag_title":

!flagged_node_title

They provided the following explanation for flagging:
!reason

<a href="!flagged_node_edit_url">Click here</a> to review.',
    'context' => '',
    'location' => '/meedan/meedan-checkdesk/drupal/index.php',
    'translation' => 'مرحباً !recipient_name،

قام !flagging_user_name بتنبيه فريق العمل عن <a href="!flagged_node_url">التقرير الآتي</a> بأنه "!flag_title": !flagged_node_title

وأعطى سبب التنبيه قائلاً:
!reason

<a href="!flagged_node_edit_url">انقر هنا</a> لمراجعة التقرير.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Hello !recipient_name,

!flagging_user_name has flagged the following <a href="!flagged_node_url">report</a> under "!flag_title":

!flagged_node_title

They provided the following explanation for flagging:
!reason

<a href="!flagged_node_edit_url">Click here</a> to review.', array(), array('context' => ''));
  $translations['ar:default']['10aec35353f9c4096a71c38654c3d402'] = array(
    'source' => 'cancel',
    'context' => '',
    'location' => '',
    'translation' => 'إلغاء',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('cancel', array(), array('context' => ''));
  $translations['ar:default']['10f062a633811c3cda06571c77699c81'] = array(
    'source' => 'Add new user',
    'context' => '',
    'location' => '',
    'translation' => 'أضف مستخدماً جديداً',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Add new user', array(), array('context' => ''));
  $translations['ar:default']['110a5d5506a61b6c1f281b035f9c9fbf'] = array(
    'source' => 'Created year',
    'context' => '',
    'location' => '',
    'translation' => 'سنة الإنشاء',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Created year', array(), array('context' => ''));
  $translations['ar:default']['119c7e70192829bf606e3774254c6167'] = array(
    'source' => 'By e-mail',
    'context' => '',
    'location' => '/ar/user/1/notifications',
    'translation' => 'بالبريد الإلكتروني',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('By e-mail', array(), array('context' => ''));
  $translations['ar:default']['11f30c5526ab77c65b37c59103588d4a'] = array(
    'source' => 'Block current user',
    'context' => '',
    'location' => '',
    'translation' => 'احظر المستخدم',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Block current user', array(), array('context' => ''));
  $translations['ar:default']['125ce8d8bf84f42d2df0c5261b05544d'] = array(
    'source' => 'Display flag/unflag link.',
    'context' => '',
    'location' => '',
    'translation' => 'عرض رابط التحذيرإلغاء التحذير.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Display flag/unflag link.', array(), array('context' => ''));
  $translations['ar:default']['125ed52de579304e14dc79afcf9d83a0'] = array(
    'source' => 'The roles of the user.',
    'context' => '',
    'location' => '',
    'translation' => 'أدوار المستخدم.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The roles of the user.', array(), array('context' => ''));
  $translations['ar:default']['12874425e4a040c9dd8a17665c076aad'] = array(
    'source' => 'The media source ID.',
    'context' => '',
    'location' => '/ar',
    'translation' => 'معرف المصدرلوسائل الاعلام.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The media source ID.', array(), array('context' => ''));
  $translations['ar:default']['1293380c9ccdc42afaa87add98d8ab99'] = array(
    'source' => 'By story',
    'context' => '',
    'location' => '',
    'translation' => 'الموضوع',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('By story', array(), array('context' => ''));
  $translations['ar:default']['130d74c3ba60e43c646b8d2ae2e189f7'] = array(
    'source' => 'Add tags',
    'context' => '',
    'location' => '/ar/node/add/media',
    'translation' => 'أضف وسومات',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Add tags', array(), array('context' => ''));
  $translations['ar:default']['13112f6f4b2f0874ed895ba8f7b60a75'] = array(
    'source' => 'Inline fields',
    'context' => '',
    'location' => '',
    'translation' => 'الحقول المضمنة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Inline fields', array(), array('context' => ''));
  $translations['ar:default']['13aa8652e950bb7c4b9b213e6d8d0dc5'] = array(
    'source' => 'Current page',
    'context' => '',
    'location' => '',
    'translation' => 'الصفحة الحالية',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Current page', array(), array('context' => ''));
  $translations['ar:default']['13ae14ee51fca38a78b7567206b1dd6d'] = array(
    'source' => 'The login account of the Twitter user.',
    'context' => '',
    'location' => '',
    'translation' => 'حساب تسجيل الدخول للمستخدم تويتر.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The login account of the Twitter user.', array(), array('context' => ''));
  $translations['ar:default']['13b5bfe96f3e2fe411c9f66f4a582adf'] = array(
    'source' => 'in',
    'context' => '',
    'location' => '',
    'translation' => 'في',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('in', array(), array('context' => ''));
  $translations['ar:default']['13bb599ce20de3a62b44ea1578761fe6'] = array(
    'source' => '@entity:@bundle',
    'context' => '',
    'location' => '',
    'translation' => '@entity:@bundle',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('@entity:@bundle', array(), array('context' => ''));
  $translations['ar:default']['13d494fd35f9f5b14309b84466cbddf2'] = array(
    'source' => 'loading...',
    'context' => '',
    'location' => 'sites/all/modules/meedan/meedan_livefyre/meedan_livefyre.js',
    'translation' => 'تحميل ...',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('loading...', array(), array('context' => ''));
  $translations['ar:default']['13f08c4bacc86b3ea9ba0eca7586df7f'] = array(
    'source' => '<a href="[node:url:unaliased]">[node:author]\'s report</a> was unflagged for fact-checking.',
    'context' => '',
    'location' => '/ar/node/flag/confirm/unflag/factcheck/2447/ajax',
    'translation' => 'تم إلغاء تنبيه المشرف للتحقق من صحة معلومات  <a href="[node:url:unaliased]"> تقرير [node:author] </a>.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('<a href="[node:url:unaliased]">[node:author]\'s report</a> was unflagged for fact-checking.', array(), array('context' => ''));
  $translations['ar:default']['13f131ac47a403e108211065942625a5'] = array(
    'source' => 'Display all items that this view might find',
    'context' => '',
    'location' => '',
    'translation' => 'عرض كافة العناصر التي توجد في العرض',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Display all items that this view might find', array(), array('context' => ''));
  $translations['ar:default']['13f9c194a1611a0822b6422faead39fe'] = array(
    'source' => 'User posted or commented',
    'context' => '',
    'location' => '',
    'translation' => 'المستخدم نشر أو علّق',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('User posted or commented', array(), array('context' => ''));
  $translations['ar:default']['142d516175ccf300a48783cb8a58f6dd'] = array(
    'source' => 'Fixed value',
    'context' => '',
    'location' => '',
    'translation' => 'قيمة ثابتة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Fixed value', array(), array('context' => ''));
  $translations['ar:default']['1442d3819f05ac0a87e5e953060fff43'] = array(
    'source' => 'New report on a story I followed',
    'context' => '',
    'location' => '/ar/node/add/discussion',
    'translation' => 'تقرير جديد لموضوع متابع',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('New report on a story I followed', array(), array('context' => ''));
  $translations['ar:default']['14716d659ee5dee91975bd3ace40d9b8'] = array(
    'source' => 'Provide a simple link to the revision.',
    'context' => '',
    'location' => '',
    'translation' => 'تقديم وصلة بسيطة إلى مراجعة.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Provide a simple link to the revision.', array(), array('context' => ''));
  $translations['ar:default']['14d689fddaa880338635bba21203eab3'] = array(
    'source' => 'Creates revision',
    'context' => '',
    'location' => '',
    'translation' => 'ينشئ مراجعة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Creates revision', array(), array('context' => ''));
  $translations['ar:default']['15562434eca08a6e897a0166d0ffa14e'] = array(
    'source' => 'The media source parent ID.',
    'context' => '',
    'location' => '/ar',
    'translation' => 'الأصل مصدر اعلامي ID.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The media source parent ID.', array(), array('context' => ''));
  $translations['ar:default']['1563084d9dc34d2498544308f0f2c6be'] = array(
    'source' => 'Cannot add field %table.%field: field already exists.',
    'context' => '',
    'location' => '',
    'translation' => 'لا يمكن إضافة الحقل %table.%field : الحقل موجود من قبل.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Cannot add field %table.%field: field already exists.', array(), array('context' => ''));
  $translations['ar:default']['1584da00089b7891f0c6ea54e3998cf3'] = array(
    'source' => 'filter criteria',
    'context' => '',
    'location' => '',
    'translation' => 'تصفية معايير',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('filter criteria', array(), array('context' => ''));
  $translations['ar:default']['15e2e38189dd8d6b714b8979b3da9284'] = array(
    'source' => 'Node ID used in the activity message',
    'context' => '',
    'location' => '/ar',
    'translation' => 'هوية العقدة المستخدمة في نشاط',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Node ID used in the activity message', array(), array('context' => ''));
  $translations['ar:default']['16356638a5eda6ffe47028f13974b764'] = array(
    'source' => 'Add \'@term\' as a tag',
    'context' => '',
    'location' => '',
    'translation' => 'أضف \'@term\' كمصطلح',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Add \'@term\' as a tag', array(), array('context' => ''));
  $translations['ar:default']['16bfd56de1d327250fc059e785fc59f6'] = array(
    'source' => 'Hello !recipient_name,

!flagging_user_name has flagged the following <a href="!flagged_node_url">report</a> under "!flag_title":

!flagged_node_title

They provided the following explanation for flagging:
!reason

<a href="!flagged_node_edit_url">Click here</a> to review.

You can edit your notification settings from your <a href="!recipient_url">profile page</a>.

This was an auto-generated email from !site, please do not respond directly to this email.',
    'context' => '',
    'location' => '/meedan/meedan-checkdesk/drupal/index.php',
    'translation' => 'مرحباً !recipient_name،

قام !flagging_user_name بتنبيه فريق العمل عن <a href="!flagged_node_url">التقرير الآتي</a> بأنه "!flag_title": !flagged_node_title

وأعطى سبب التنبيه قائلاً:
!reason

<a href="!flagged_node_edit_url">انقر هنا</a> لمراجعة التقرير.

بإمكانك تعديل إعدادات التنبيهات الخاصة بك من صفحة <a href="!recipient_url">الحساب الشخصي</a> الخاصة بك.

هذه رسالة مولدة بشكل تلقائي من !site، يرجى عدم الرد على هذه الرسالة.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Hello !recipient_name,

!flagging_user_name has flagged the following <a href="!flagged_node_url">report</a> under "!flag_title":

!flagged_node_title

They provided the following explanation for flagging:
!reason

<a href="!flagged_node_edit_url">Click here</a> to review.

You can edit your notification settings from your <a href="!recipient_url">profile page</a>.

This was an auto-generated email from !site, please do not respond directly to this email.', array(), array('context' => ''));
  $translations['ar:default']['16d73e61e27ea523e65e071f262b710e'] = array(
    'source' => 'Any flag',
    'context' => '',
    'location' => '/ar/search?field_tags_tid=1327',
    'translation' => 'أي تحذير',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Any flag', array(), array('context' => ''));
  $translations['ar:default']['1743d8e43a40d31cdeeebc5016b7127e'] = array(
    'source' => 'Copy source',
    'context' => '',
    'location' => '',
    'translation' => 'نسخ المصدر',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Copy source', array(), array('context' => ''));
  $translations['ar:default']['1759bc73458a5d7081f8b76decde93eb'] = array(
    'source' => 'Provide a simple link to view the comment.',
    'context' => '',
    'location' => '',
    'translation' => 'ضع رابط بسيط لاستعراض التعليق.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Provide a simple link to view the comment.', array(), array('context' => ''));
  $translations['ar:default']['178df7ae3ec428e6f98afc55738dae17'] = array(
    'source' => 'Add to',
    'context' => '',
    'location' => '',
    'translation' => 'أضف إلى',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Add to', array(), array('context' => ''));
  $translations['ar:default']['178e84b351f09391daf957dc8183149a'] = array(
    'source' => 'The number of comments a node has.',
    'context' => '',
    'location' => '',
    'translation' => 'عدد التعليقات عند العقده',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The number of comments a node has.', array(), array('context' => ''));
  $translations['ar:default']['17c1368bee1672b30ce969c5524dee40'] = array(
    'source' => 'sort criterion',
    'context' => '',
    'location' => '',
    'translation' => 'نوع المعيار',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('sort criterion', array(), array('context' => ''));
  $translations['ar:default']['1802aa08edc72d0b67d2798133bc7479'] = array(
    'source' => 'verification footnotes',
    'context' => '',
    'location' => '',
    'translation' => 'ملاحظات التحقق',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('verification footnotes', array(), array('context' => ''));
  $translations['ar:default']['185e7b2c7281084a50b7f214b0603d52'] = array(
    'source' => 'Files maintained by Drupal and various modules.',
    'context' => '',
    'location' => '',
    'translation' => 'الملفات التي تحتفظ بها وحدات دروبال المختلفة.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Files maintained by Drupal and various modules.', array(), array('context' => ''));
  $translations['ar:default']['189cd66b996b9e0f6e38bbd84042922c'] = array(
    'source' => '@count[3] more updates',
    'context' => '',
    'location' => '',
    'translation' => '@count[3] تحديثات أخرى',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('@count[3] more updates', array(), array('context' => ''));
  $translations['ar:default']['18e821ad4693d1cb959c2640b3fb0067'] = array(
    'source' => 'Report flagged',
    'context' => '',
    'location' => '/ar',
    'translation' => 'تنبيه على تقرير',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Report flagged', array(), array('context' => ''));
  $translations['ar:default']['19305646be81ef0adcc4dee8098023b3'] = array(
    'source' => 'The module managing this file relationship.',
    'context' => '',
    'location' => '',
    'translation' => ' إدارة  الوحده للملف المتعلق به',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The module managing this file relationship.', array(), array('context' => ''));
  $translations['ar:default']['19436a571361a0491aee27693da58b6c'] = array(
    'source' => 'Source URL',
    'context' => '',
    'location' => '/ar',
    'translation' => 'مصدر URL',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Source URL', array(), array('context' => ''));
  $translations['ar:default']['1b23ba65c850a287808c474da5871a68'] = array(
    'source' => 'Exposed Form',
    'context' => '',
    'location' => '',
    'translation' => 'الاستمارة المكشوفة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Exposed Form', array(), array('context' => ''));
  $translations['ar:default']['1b441c8fe9efc3b5947f881337fe06e6'] = array(
    'source' => 'HTML list',
    'context' => '',
    'location' => '',
    'translation' => 'قائمة HTML',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('HTML list', array(), array('context' => ''));
  $translations['ar:default']['1b4905c3f9ec26bd2fc9af209d20cc8b'] = array(
    'source' => 'See the new report',
    'context' => '',
    'location' => '/ar/meedan_bookmarklet/message?meedan_bookmarklet=1&meedan_bookmarklet_submitted=1&meedan_bookmarklet_nid=236',
    'translation' => 'استعرض التقرير الذي أرسلته',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('See the new report', array(), array('context' => ''));
  $translations['ar:default']['1b8140bf508214dde3ed7de36d189dd6'] = array(
    'source' => 'New story created',
    'context' => '',
    'location' => '/ar',
    'translation' => 'تم إضافة موضوع جديد',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('New story created', array(), array('context' => ''));
  $translations['ar:default']['1b932f22bc5477535987fbb24ea8e001'] = array(
    'source' => 'The node ID.',
    'context' => '',
    'location' => '',
    'translation' => 'معرف العقدة.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The node ID.', array(), array('context' => ''));
  $translations['ar:default']['1b9abf135ccb7ed2f2cd9c155137c351'] = array(
    'source' => 'Browse',
    'context' => '',
    'location' => 'sites/all/modules/custom/checkdesk_core/js/fileinput.js; sites/all/modules/custom/checkdesk_core/js/checkdesk_core.js',
    'translation' => 'استعراض',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Browse', array(), array('context' => ''));
  $translations['ar:default']['1bea3d99d5ba0de3a88cafd80ddd58bc'] = array(
    'source' => 'Whether the user is active or blocked.',
    'context' => '',
    'location' => '',
    'translation' => 'ما إذا كان المستخدم نشطاً أو محظوراً',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Whether the user is active or blocked.', array(), array('context' => ''));
  $translations['ar:default']['1c2f2e6087f298122994f15da2350859'] = array(
    'source' => 'Full activity message',
    'context' => '',
    'location' => '/ar',
    'translation' => 'رساله نشطه',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Full activity message', array(), array('context' => ''));
  $translations['ar:default']['1c3e2cc794ce43af2ad3b27f8fbc117b'] = array(
    'source' => 'Story page',
    'context' => '',
    'location' => '',
    'translation' => 'صفحة الموضوع',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Story page', array(), array('context' => ''));
  $translations['ar:default']['1cd90ce849f88146bb22c76857c596fa'] = array(
    'source' => 'by <span class="checkdesk-status-partner">@partner</span>',
    'context' => '',
    'location' => '/ar/report/twitter-mohamed-salah-%D8%A7%D9%84%D9%86%D9%87%D8%A7%D8%B1%D8%AF%D8%A9-%D8%A8%D8%A7%D9%82%D9%88%D9%84-%D9%84%D9%88%D8%A7%D8%AD%D8%AF',
    'translation' => 'من قبل <span class="checkdesk-status-partner">@partner</span>',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('by <span class="checkdesk-status-partner">@partner</span>', array(), array('context' => ''));
  $translations['ar:default']['1d1c5b76da944b44db42c9d0558021c5'] = array(
    'source' => 'mismatch',
    'context' => '',
    'location' => '/ar/user/register',
    'translation' => 'عدم تطابق ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('mismatch', array(), array('context' => ''));
  $translations['ar:default']['1d46eb6bc4ccae90dacb2fe8dff1e339'] = array(
    'source' => 'Flag link',
    'context' => '',
    'location' => '',
    'translation' => 'رابط التحذير',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Flag link', array(), array('context' => ''));
  $translations['ar:default']['1d7706d43d883747fb606cd85aca843c'] = array(
    'source' => 'Cannot add field %table.%field: table doesn\'t exist.',
    'context' => '',
    'location' => '',
    'translation' => 'لا يمكن إضافة الحقل %table.%field : الجدول غير موجود.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Cannot add field %table.%field: table doesn\'t exist.', array(), array('context' => ''));
  $translations['ar:default']['1d951d9b21da3a1d8de14c19b3238cf1'] = array(
    'source' => 'Share on Twitter',
    'context' => '',
    'location' => '',
    'translation' => 'شارك على تويتر',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Share on Twitter', array(), array('context' => ''));
  $translations['ar:default']['1da4fba22d4a9fd64cb478dd31ad7b25'] = array(
    'source' => 'Node export link',
    'context' => '',
    'location' => '/ar',
    'translation' => 'رابط اصدار العقده ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Node export link', array(), array('context' => ''));
  $translations['ar:default']['1e067ac485fd2a9edad9f1b50e3a13f8'] = array(
    'source' => 'Sign In with Twitter',
    'context' => '',
    'location' => '/ar/user/login',
    'translation' => 'تسجيل الدخول مع تويتر',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Sign In with Twitter', array(), array('context' => ''));
  $translations['ar:default']['1eb0cc534cd16bdd458c37100e844868'] = array(
    'source' => 'Comments allowed',
    'context' => '',
    'location' => '',
    'translation' => 'التعليقات مسموحه',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Comments allowed', array(), array('context' => ''));
  $translations['ar:default']['1ef35c9c579b714584b7395cb3fd8137'] = array(
    'source' => 'Published on update',
    'context' => '',
    'location' => '/ar/node/add/post',
    'translation' => 'نُشر بتحديث',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Published on update', array(), array('context' => ''));
  $translations['ar:default']['1f549ff725079e2a389bfd2f1f822966'] = array(
    'source' => 'Updated day',
    'context' => '',
    'location' => '',
    'translation' => 'تم تحديث اليوم',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Updated day', array(), array('context' => ''));
  $translations['ar:default']['1f849344c4b62f6480058291b8a7d21b'] = array(
    'source' => 'Add optional feature image',
    'context' => '',
    'location' => '/ar/liveblog',
    'translation' => 'أضف صورة واجهة اختيارية',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Add optional feature image', array(), array('context' => ''));
  $translations['ar:default']['1f8bb561bc5da17f030762d77f854112'] = array(
    'source' => 'Basic exposed form',
    'context' => '',
    'location' => '',
    'translation' => 'شكل اساسي مكشوف ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Basic exposed form', array(), array('context' => ''));
  $translations['ar:default']['1fe76fd81831f70d2773f3ac1fc6c1b2'] = array(
    'source' => 'Fact-checking turned on on a report I submitted',
    'context' => '',
    'location' => '/ar',
    'translation' => 'تفعيل تقصي صحة المعلومات على تقرير قمت بإرساله',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Fact-checking turned on on a report I submitted', array(), array('context' => ''));
  $translations['ar:default']['2004af4cf1c8e825dcd464a0e9bf6a7f'] = array(
    'source' => 'Updated week',
    'context' => '',
    'location' => '',
    'translation' => 'تم تحديث الأسبوع',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Updated week', array(), array('context' => ''));
  $translations['ar:default']['204211fa22eeb23c3c02fa07da86fb00'] = array(
    'source' => 'Current node\'s creation time',
    'context' => '',
    'location' => '',
    'translation' => 'تاريخ إنشاء العقدة الحالية',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Current node\'s creation time', array(), array('context' => ''));
  $translations['ar:default']['204cbc1c401261484ae52f5f5deca7f9'] = array(
    'source' => 'The \'To\' field of the e-mail address.',
    'context' => '',
    'location' => '/ar',
    'translation' => 'و\'إلى\' حقل من عنوان البريد الإلكتروني.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The \'To\' field of the e-mail address.', array(), array('context' => ''));
  $translations['ar:default']['2078bbb7b0a42e7feb1a365ad453bde5'] = array(
    'source' => 'Display the referenced entities rendered by entity_view().',
    'context' => '',
    'location' => '',
    'translation' => 'عرض الكيانات المشار إليها التي يقدمها entity_view ().',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Display the referenced entities rendered by entity_view().', array(), array('context' => ''));
  $translations['ar:default']['208376a2c80b47f62ae9e8be05485063'] = array(
    'source' => 'Author uid',
    'context' => '',
    'location' => '',
    'translation' => 'كاتب UID',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Author uid', array(), array('context' => ''));
  $translations['ar:default']['208d260b042b9c61e0f4d002dc751a3c'] = array(
    'source' => 'Hello !recipient_name,

!actor has changed the fact-checking status for a <a href="!url">report</a> you added footnote to to !rating.',
    'context' => '',
    'location' => '/meedan/meedan-checkdesk/drupal/index.php',
    'translation' => 'مرحباً !recipient_name،

قام !actor بتغيير حالة التحقق من صحة المعلومات <a href="!url">للتقرير</a> الذي أضفت إليه ملاحظات إلى !rating.
',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Hello !recipient_name,

!actor has changed the fact-checking status for a <a href="!url">report</a> you added footnote to to !rating.', array(), array('context' => ''));
  $translations['ar:default']['209e387d30351d7a458131a33b5c8269'] = array(
    'source' => 'The user\'s signature.',
    'context' => '',
    'location' => '',
    'translation' => 'توقيع المستخدم ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The user\'s signature.', array(), array('context' => ''));
  $translations['ar:default']['209f2daea3b29461c4664437ec341034'] = array(
    'source' => 'The primary key of the maillog table.',
    'context' => '',
    'location' => '/ar',
    'translation' => 'المفتاح الأساسي للجدول maillog.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The primary key of the maillog table.', array(), array('context' => ''));
  $translations['ar:default']['20af0cb4e4439e82090b117774abc4f0'] = array(
    'source' => 'The machine-readable name identifying this @entity.',
    'context' => '',
    'location' => '',
    'translation' => 'The machine-readable name identifying this @entity.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The machine-readable name identifying this @entity.', array(), array('context' => ''));
  $translations['ar:default']['20b3b3d1f12eb60f1a24be72fba01a2c'] = array(
    'source' => 'Hello !recipient_name,

!actor has added a new report "!node_title" to this story "!story_title".

Go to !story_url to compose a new update to the story using that report.

You can edit your notification settings from !recipient_url.

This was an auto-generated email from !site, please do not respond directly to this email.',
    'context' => '',
    'location' => '/index.php',
    'translation' => 'مرحباً !recipient_name،

قام !actor بإضافة تقرير جديد "!node_title" إلى هذا الموضوع "!story_title".

<a href="!story_url">اضغط هنا</a> لكتابة تحديث جديد على ذلك الخبر باستخدام ذاك التقرير.

بإمكانك تعديل إعدادات التنبيهات الخاصة بك من صفحة <a href="!recipient_url">الحساب الشخصي</a> الخاصة بك.

هذه رسالة مولدة بشكل تلقائي من !site، يرجى عدم الرد على هذه الرسالة.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Hello !recipient_name,

!actor has added a new report "!node_title" to this story "!story_title".

Go to !story_url to compose a new update to the story using that report.

You can edit your notification settings from !recipient_url.

This was an auto-generated email from !site, please do not respond directly to this email.', array(), array('context' => ''));
  $translations['ar:default']['2182a74bab7188d959e795d9301e87ff'] = array(
    'source' => 'Markdown',
    'context' => '',
    'location' => '/ar',
    'translation' => 'تاشير ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Markdown', array(), array('context' => ''));
  $translations['ar:default']['218d58ac62e5f29316a9ff5714b3bbf5'] = array(
    'source' => 'Added by <a class="contributor" href="@user">!user</a> <span class="separator">&#9679;</span> <time class="date-time" datetime="!timestamp">!interval ago</time>',
    'context' => '',
    'location' => NULL,
    'translation' => 'أضيف من قبل <a class="contributor" href="@user">!user</a> <span class="separator">&#9679;</span> <time class="date-time" datetime="!timestamp">منذ !interval </time>',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Added by <a class="contributor" href="@user">!user</a> <span class="separator">&#9679;</span> <time class="date-time" datetime="!timestamp">!interval ago</time>', array(), array('context' => ''));
  $translations['ar:default']['21c44f5a36a950e0ce1db65ea3d12dbc'] = array(
    'source' => 'Parent comment',
    'context' => '',
    'location' => '',
    'translation' => 'التعليق الام',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Parent comment', array(), array('context' => ''));
  $translations['ar:default']['220f3d3750583b9db48568a0b5b9a5f1'] = array(
    'source' => 'Keyword',
    'context' => '',
    'location' => '',
    'translation' => 'كلمة مفتاحية',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Keyword', array(), array('context' => ''));
  $translations['ar:default']['222a267cc5778206b253be35ee3ddab5'] = array(
    'source' => 'Current',
    'context' => '',
    'location' => '',
    'translation' => 'الحالي',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Current', array(), array('context' => ''));
  $translations['ar:default']['225b6437ee76635c21d22fe8fdf83bbe'] = array(
    'source' => 'Language settings for the user account.',
    'context' => '',
    'location' => '',
    'translation' => 'إعدادات اللغة لحساب المستخدم.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Language settings for the user account.', array(), array('context' => ''));
  $translations['ar:default']['22bd28abbfb0e80fd367dc636074db9e'] = array(
    'source' => 'Combine two fields together and search by them.',
    'context' => '',
    'location' => '',
    'translation' => 'الجمع بين حقلين معا والبحث بها.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Combine two fields together and search by them.', array(), array('context' => ''));
  $translations['ar:default']['230f3b2f93ecaf7d826afe0e7d2d6ffd'] = array(
    'source' => 'g:ia',
    'context' => '',
    'location' => '',
    'translation' => 'g:i a',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('g:ia', array(), array('context' => ''));
  $translations['ar:default']['232055e598e3b5a36e199043cc0b1460'] = array(
    'source' => 'In reply to status ID',
    'context' => '',
    'location' => '/ar',
    'translation' => 'ردا على وضع الهوية',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('In reply to status ID', array(), array('context' => ''));
  $translations['ar:default']['23a0ddded91ad00e0c26dd30bba062b7'] = array(
    'source' => 'Filter criteria',
    'context' => '',
    'location' => '',
    'translation' => 'تصفية معايير',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Filter criteria', array(), array('context' => ''));
  $translations['ar:default']['23bf1b8cc5d28f5ed04236bbd7383864'] = array(
    'source' => '<p><strong><a href="!user_url">!username</a></strong> has turned on fact-checking for a <strong><a href="!report_url">report</a></strong> you submitted. Fact checking is in progress.</p>',
    'context' => '',
    'location' => '/ar/user',
    'translation' => '<p>قام <strong><a href="!user_url">!username</a></strong> بتفعيل التحقق من صحة المعلومات <strong><a href="!report_url">للتقرير</a></strong> الذي انشأته. التحقق من صحة المعلومات جارٍ.</p>',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('<p><strong><a href="!user_url">!username</a></strong> has turned on fact-checking for a <strong><a href="!report_url">report</a></strong> you submitted. Fact checking is in progress.</p>', array(), array('context' => ''));
  $translations['ar:default']['2407287cd0a442536b9b841d42cfffc8'] = array(
    'source' => 'Request deletion',
    'context' => '',
    'location' => '',
    'translation' => 'اطلب حذفه',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Request deletion', array(), array('context' => ''));
  $translations['ar:default']['2415f5b4485bdc0a4d5cb9312e847485'] = array(
    'source' => 'Displays rows as an HTML list.',
    'context' => '',
    'location' => '',
    'translation' => 'يعرض صفوف القائمة HTML.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Displays rows as an HTML list.', array(), array('context' => ''));
  $translations['ar:default']['2417cf1a77df45442370973d12cdbb9d'] = array(
    'source' => 'The name of the file.',
    'context' => '',
    'location' => '',
    'translation' => 'اسم الملف.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The name of the file.', array(), array('context' => ''));
  $translations['ar:default']['2429e79d8a4f5e8e9855ea15f59db882'] = array(
    'source' => 'The taxonomy vocabulary name',
    'context' => '',
    'location' => '',
    'translation' => 'اسم مفردات التصنيف',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The taxonomy vocabulary name', array(), array('context' => ''));
  $translations['ar:default']['243df61e7143e64758d62174b95fbc35'] = array(
    'source' => 'Modify user roles',
    'context' => '',
    'location' => '',
    'translation' => 'عدّل أدوار المستخدمين',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Modify user roles', array(), array('context' => ''));
  $translations['ar:default']['2443bda544a5189c28ba7c1408e285f3'] = array(
    'source' => 'Following story',
    'context' => '',
    'location' => 'sites/all/modules/custom/checkdesk_core/js/checkdesk_core.js',
    'translation' => 'موضوع مُتابَع',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Following story', array(), array('context' => ''));
  $translations['ar:default']['2491bc9c7d8731e1ae33124093bc7026'] = array(
    'source' => 'Twitter',
    'context' => '',
    'location' => '',
    'translation' => 'تويتر',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Twitter', array(), array('context' => ''));
  $translations['ar:default']['24c714ccb3857346b52bfe17e287d210'] = array(
    'source' => 'Followers',
    'context' => '',
    'location' => '',
    'translation' => 'أتباع',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Followers', array(), array('context' => ''));
  $translations['ar:default']['24cc4a7e556c707c30e35ea5e80867f8'] = array(
    'source' => 'No content available',
    'context' => '',
    'location' => '',
    'translation' => 'لا يوجد محتوى.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('No content available', array(), array('context' => ''));
  $translations['ar:default']['251d164643533a527361dbe1a7b9235d'] = array(
    'source' => 'footer',
    'context' => '',
    'location' => '',
    'translation' => 'تذييل الصفحة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('footer', array(), array('context' => ''));
  $translations['ar:default']['2584887d16047739f8d80750cec2cc52'] = array(
    'source' => 'The term weight field',
    'context' => '',
    'location' => '',
    'translation' => 'مجال الوزن على المدى',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The term weight field', array(), array('context' => ''));
  $translations['ar:default']['259105640412c0ed952d4bb7a9dbc0ff'] = array(
    'source' => 'Image must be less than !size.',
    'context' => '',
    'location' => '/',
    'translation' => 'يجب أن يكون حجم الصورة أقل من !size.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Image must be less than !size.', array(), array('context' => ''));
  $translations['ar:default']['262afba2a47467cfd1fa3e12f6079f5c'] = array(
    'source' => 'The date the node was last updated.',
    'context' => '',
    'location' => '',
    'translation' => 'تاريخ آخر تحديث العقدة.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The date the node was last updated.', array(), array('context' => ''));
  $translations['ar:default']['266ab0dfecae318b43d96b010ba3171b'] = array(
    'source' => '!username said: !comment',
    'context' => '',
    'location' => '',
    'translation' => '!username قال: !comment',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('!username said: !comment', array(), array('context' => ''));
  $translations['ar:default']['2687fbba2477b26c82b2d967aa892ffa'] = array(
    'source' => 'Provide a simple link to delete an eMail entry from the maillog table.',
    'context' => '',
    'location' => '/ar',
    'translation' => 'تقديم وصلة بسيطة لحذف إدخال البريد الإلكتروني من الجدول maillog.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Provide a simple link to delete an eMail entry from the maillog table.', array(), array('context' => ''));
  $translations['ar:default']['268a563dd927e741e93e5f9b6d7223ff'] = array(
    'source' => 'Inherit exposed filters',
    'context' => '',
    'location' => '',
    'translation' => 'وراثة المرشحات المكشوفة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Inherit exposed filters', array(), array('context' => ''));
  $translations['ar:default']['26b4cec891bcc9f4cd0ee8e85c5024a6'] = array(
    'source' => 'Fact-checking has been disabled for <a href="[node:url:unaliased]">[node:author]\'s report</a>.',
    'context' => '',
    'location' => '/ar/flag/unflag/factcheck_journalist/2447?destination=node/2447&token=KPFawrLou6qfujz-SsQucRW0B_4hr8CIbDcZBfbnrBo',
    'translation' => 'تم إلغاء التحقق من صحة معلومات <a href="[node:url:unaliased]"> تقرير [node:author] </a>.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Fact-checking has been disabled for <a href="[node:url:unaliased]">[node:author]\'s report</a>.', array(), array('context' => ''));
  $translations['ar:default']['26c74bae40dd5787582282381adf0254'] = array(
    'source' => '<a href="[node:url:unaliased]">[node:author]\'s report</a> was flagged as containing graphic content.',
    'context' => '',
    'location' => '/ar/node/flag/confirm/flag/graphic/2442/ajax',
    'translation' => 'تم تنبيه المشرف على احتواء <a href="[node:url:unaliased]"> تقرير [node:author] </a> على محتوى أو صور صادمة.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('<a href="[node:url:unaliased]">[node:author]\'s report</a> was flagged as containing graphic content.', array(), array('context' => ''));
  $translations['ar:default']['271706be657491fb758afdb1b34a34a3'] = array(
    'source' => 'Last Comment',
    'context' => '',
    'location' => '',
    'translation' => 'التعليق الأخير',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Last Comment', array(), array('context' => ''));
  $translations['ar:default']['274d0fa8838447f084a0eb00f3f50a58'] = array(
    'source' => 'Nodes represent the main site content items.',
    'context' => '',
    'location' => '',
    'translation' => 'العقد تمثل محتوى الموقع الرئيسي البنود.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Nodes represent the main site content items.', array(), array('context' => ''));
  $translations['ar:default']['27c9d130ea5fb8c3ba5eecb1b8f753bd'] = array(
    'source' => '<a href="!url">@count more updates</a> related to <a href="!url">this story</a>. <a href="!url">View all</a>',
    'context' => '',
    'location' => '',
    'translation' => '<a href="!url">@count تحديثات أخرى</a> مرتبطة <a href="!url">بهذا الموضوع</a>. <a href="!url">عرض الكل</a>',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('<a href="!url">@count more updates</a> related to <a href="!url">this story</a>. <a href="!url">View all</a>', array(), array('context' => ''));
  $translations['ar:default']['284746bfb01438b6e62245ba95be1734'] = array(
    'source' => 'Powered by ',
    'context' => '',
    'location' => '/',
    'translation' => 'مشغل بواسطة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Powered by ', array(), array('context' => ''));
  $translations['ar:default']['2874a4ad712362a0be269d9b1895574c'] = array(
    'source' => 'Display on separate page',
    'context' => '',
    'location' => '',
    'translation' => 'في صفحة منفصلة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Display on separate page', array(), array('context' => ''));
  $translations['ar:default']['2899a088c8f70f1d255b74775d765b91'] = array(
    'source' => 'Citizen Reports',
    'context' => '',
    'location' => '/checkdesk/ar/admin/meedan/reports',
    'translation' => 'تقارير المواطنين',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Citizen Reports', array(), array('context' => ''));
  $translations['ar:default']['28fcca0aa4d724a66a3afca960a279d4'] = array(
    'source' => 'Language of the user',
    'context' => '',
    'location' => '',
    'translation' => 'لغة المستخدم',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Language of the user', array(), array('context' => ''));
  $translations['ar:default']['294daf1e61f01f61bf6c51423f65fc3d'] = array(
    'source' => 'Fact-checking has been disabled for this report.',
    'context' => '',
    'location' => '/ar/flag/unflag/factcheck_journalist/260?destination=liveblog&token=3ML56ORB55jqX1rG5redvvYz5BH76c7TAPQpU-p_9eA',
    'translation' => ' تم إلغاء التحقق من صحة المعلومات لهذا التقرير. ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Fact-checking has been disabled for this report.', array(), array('context' => ''));
  $translations['ar:default']['2a10349b073655795c63abb12c53dc39'] = array(
    'source' => 'Protected status',
    'context' => '',
    'location' => '',
    'translation' => 'حاله محفوظه ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Protected status', array(), array('context' => ''));
  $translations['ar:default']['2a95eb3f69304fe9a8dd858f041b8dbc'] = array(
    'source' => 'Media source information.',
    'context' => '',
    'location' => '/ar',
    'translation' => 'معلومات المصدر الإعلامي',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Media source information.', array(), array('context' => ''));
  $translations['ar:default']['2b3077f16d277c79a4f54126f6881450'] = array(
    'source' => 'This image style is being provided by %module module and may not be renamed.',
    'context' => '',
    'location' => '',
    'translation' => 'نمط هذه الصورة موفر من طرف وحدة %module ولا يجب تعديل اسمه.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('This image style is being provided by %module module and may not be renamed.', array(), array('context' => ''));
  $translations['ar:default']['2bda2998d9b0ee197da142a0447f6725'] = array(
    'source' => 'wrong',
    'context' => '',
    'location' => 'sites/all/modules/custom/checkdesk_core/js/checkdesk_core.js',
    'translation' => 'إجابة خاطئة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('wrong', array(), array('context' => ''));
  $translations['ar:default']['2bf802fe1cf9aba0ad608a49d515c022'] = array(
    'source' => 'Receive notifications',
    'context' => '',
    'location' => '/ar/user/1/notifications',
    'translation' => 'تلقّي التنبيهات',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Receive notifications', array(), array('context' => ''));
  $translations['ar:default']['2c201f8beeb3ada3433ce42344dc16be'] = array(
    'source' => 'The node ID to which the comment is a reply to.',
    'context' => '',
    'location' => '',
    'translation' => 'معرف العقدة التي التعليق هو الرد على.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The node ID to which the comment is a reply to.', array(), array('context' => ''));
  $translations['ar:default']['2c42d7d277f63fcbe64b041b997ceaed'] = array(
    'source' => 'Promoted',
    'context' => '',
    'location' => '',
    'translation' => 'مقالة مختارة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Promoted', array(), array('context' => ''));
  $translations['ar:default']['2cc1cf82510b534181f876c00e4edeca'] = array(
    'source' => 'Display fields in a contextual links menu.',
    'context' => '',
    'location' => '',
    'translation' => 'عرض الحقول في قائمة الروابط السياقية.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Display fields in a contextual links menu.', array(), array('context' => ''));
  $translations['ar:default']['2dbfbe1444514a7c655f3868e8cf45bb'] = array(
    'source' => 'Exposed Filters',
    'context' => '',
    'location' => '',
    'translation' => 'المرشحات المكشوفة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Exposed Filters', array(), array('context' => ''));
  $translations['ar:default']['2dd4afe88efc789474a5cefb80e0f2ff'] = array(
    'source' => 'Display the comment as RSS.',
    'context' => '',
    'location' => '',
    'translation' => 'عرض التعليق كما RSS.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Display the comment as RSS.', array(), array('context' => ''));
  $translations['ar:default']['2dd6fa37aa69a17270d3f448fa19e7bb'] = array(
    'source' => 'The ID of the file.',
    'context' => '',
    'location' => '',
    'translation' => 'هويه او معرف الملف ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The ID of the file.', array(), array('context' => ''));
  $translations['ar:default']['2e056a65e6419d748bba034dc45d44ff'] = array(
    'source' => 'Sticky in lists',
    'context' => '',
    'location' => '',
    'translation' => 'مثبت في القوائم',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Sticky in lists', array(), array('context' => ''));
  $translations['ar:default']['2e363c8250d6fa32bd8fc648bd4e128a'] = array(
    'source' => 'Whether or not the content is promoted to the front page.',
    'context' => '',
    'location' => '',
    'translation' => 'ما إذا كانت المقالة تم اختيارها لتكون مقالة مختارة.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Whether or not the content is promoted to the front page.', array(), array('context' => ''));
  $translations['ar:default']['2ef10c388ea575acd3293484ec89f3a0'] = array(
    'source' => 'Email of user that posted the comment. Will be empty if the author is a registered user.',
    'context' => '',
    'location' => '',
    'translation' => 'البريد الإلكتروني للمستخدم الذي نشر التعليق. وسوف يكون فارغا إذا كان المؤلف مستخدما مسجلا.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Email of user that posted the comment. Will be empty if the author is a registered user.', array(), array('context' => ''));
  $translations['ar:default']['2f34677639721a7767ff1926c10e04d0'] = array(
    'source' => 'LID',
    'context' => '',
    'location' => '',
    'translation' => 'LID',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('LID', array(), array('context' => ''));
  $translations['ar:default']['2f3678ab682f4e03642df37460c6c24e'] = array(
    'source' => 'Unflag for fact-checking',
    'context' => '',
    'location' => '/ar/admin/content',
    'translation' => 'إلغاء تنبيه التحقق من صحة المعلومات',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Unflag for fact-checking', array(), array('context' => ''));
  $translations['ar:default']['2f3c3082abe80f4d4c9b48fceef56e61'] = array(
    'source' => 'Follow story',
    'context' => '',
    'location' => '/ar/node/add/discussion',
    'translation' => 'تابع الموضوع',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Follow story', array(), array('context' => ''));
  $translations['ar:default']['2fb58660fd44cbdef76a54519a9a9737'] = array(
    'source' => 'Created time',
    'context' => '',
    'location' => '',
    'translation' => 'وقت الانشاء',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Created time', array(), array('context' => ''));
  $translations['ar:default']['2fb7698764564daeb22537a48a545c9d'] = array(
    'source' => 'User has a revision',
    'context' => '',
    'location' => '',
    'translation' => 'المستخدم لديه مراجعة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('User has a revision', array(), array('context' => ''));
  $translations['ar:default']['2fdfd506efea08144c0794c32ca8250a'] = array(
    'source' => 'Create an account',
    'context' => '',
    'location' => '/ar/user/register',
    'translation' => 'أنشئ حسابا جديدا',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Create an account', array(), array('context' => ''));
  $translations['ar:default']['3006d30ccd8d97b4bd95821f305aa27a'] = array(
    'source' => '<a href="@url"><time class="date-time" datetime="!timestamp">!daydatetime</time></a> added by <a class="contributor" href="@user">!user</a>',
    'context' => '',
    'location' => '/ar/story/13',
    'translation' => '<a href="@url"><time class="date-time" datetime="!timestamp">!daydatetime</time></a> من قبل <a class="contributor" href="@user">!user</a>',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('<a href="@url"><time class="date-time" datetime="!timestamp">!daydatetime</time></a> added by <a class="contributor" href="@user">!user</a>', array(), array('context' => ''));
  $translations['ar:default']['302f1ba02f197fead45de2a82fdb0296'] = array(
    'source' => 'Display the content with standard node view.',
    'context' => '',
    'location' => '',
    'translation' => 'عرض المحتوى مع وجهة نظر العقدة القياسية.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Display the content with standard node view.', array(), array('context' => ''));
  $translations['ar:default']['30463d4a350f7a8b53acdb91328f25fb'] = array(
    'source' => 'Is not one of',
    'context' => '',
    'location' => '',
    'translation' => 'ليست واحدة من',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Is not one of', array(), array('context' => ''));
  $translations['ar:default']['305139cae3b32e34fb008ea091d29c7e'] = array(
    'source' => 'Store a date in the database as a datetime field, recommended for complete dates and times that may need timezone conversion.',
    'context' => '',
    'location' => '',
    'translation' => 'تخزين التاريخ في قاعدة البيانات كحقل التاريخ والوقت، وأوصت لتواريخ وأوقات كاملة التي قد تحتاج إلى تحويل منطقة زمنية.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Store a date in the database as a datetime field, recommended for complete dates and times that may need timezone conversion.', array(), array('context' => ''));
  $translations['ar:default']['30caf76a24921da406e7b808d3e18301'] = array(
    'source' => 'The internal ID of the scheduled component',
    'context' => '',
    'location' => '',
    'translation' => 'معرف الداخلية للمكون المقرر',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The internal ID of the scheduled component', array(), array('context' => ''));
  $translations['ar:default']['30f1073e733585cf8ee806ad790651bd'] = array(
    'source' => 'Revision UUID',
    'context' => '',
    'location' => '/ar',
    'translation' => 'مراجعة UUID',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Revision UUID', array(), array('context' => ''));
  $translations['ar:default']['310931092e7a3a3dd516be482dbe1620'] = array(
    'source' => 'Demonstrate block regions (@theme)',
    'context' => '',
    'location' => '',
    'translation' => 'معاينة مناطق الصناديق (@theme)',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Demonstrate block regions (@theme)', array(), array('context' => ''));
  $translations['ar:default']['3112209b2dd9b55cf5dbc4865dd15afd'] = array(
    'source' => 'Creation date',
    'context' => '',
    'location' => '',
    'translation' => 'تاريخ الإنشاء',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Creation date', array(), array('context' => ''));
  $translations['ar:default']['3119702f30af3faaa07258b10ba7dbae'] = array(
    'source' => 'Other nodes that are linked from the node.',
    'context' => '',
    'location' => '',
    'translation' => 'العقد الأخرى التي تم ربطها من العقدة.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Other nodes that are linked from the node.', array(), array('context' => ''));
  $translations['ar:default']['3122f8e23f63bcd5f270215fb465457a'] = array(
    'source' => 'Fact-checking activity',
    'context' => '',
    'location' => '',
    'translation' => 'نشاط التحقق من صحة المعلومات',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Fact-checking activity', array(), array('context' => ''));
  $translations['ar:default']['315d64063febfbf9dc1688c690210345'] = array(
    'source' => 'The type of entity that is related to the file.',
    'context' => '',
    'location' => '',
    'translation' => 'نوع الكيان الذي يرتبط  بالملف.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The type of entity that is related to the file.', array(), array('context' => ''));
  $translations['ar:default']['3275a766e2cb580dadaadd4978a5c9b0'] = array(
    'source' => 'Blogged by ',
    'context' => '',
    'location' => '/ar',
    'translation' => 'تدوينة من',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Blogged by ', array(), array('context' => ''));
  $translations['ar:default']['327a6c4304ad5938eaf0efb6cc3e53dc'] = array(
    'source' => 'flag',
    'context' => '',
    'location' => '',
    'translation' => 'منبه  ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('flag', array(), array('context' => ''));
  $translations['ar:default']['328efbdcd88b8229d03d3572d99a27ca'] = array(
    'source' => 'This report is no longer available. It could have been deleted by the user or host service.',
    'context' => '',
    'location' => '',
    'translation' => 'هذا التقرير غير موجود. قد يكون تم إزالته من قبل المستخدم أو المنصة المقدمة للخدمة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('This report is no longer available. It could have been deleted by the user or host service.', array(), array('context' => ''));
  $translations['ar:default']['32cc6878b4e213bb98bf0870384d97ea'] = array(
    'source' => 'Language negotiation',
    'context' => '',
    'location' => '',
    'translation' => 'انتقاء اللغة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Language negotiation', array(), array('context' => ''));
  $translations['ar:default']['33173aa7d8ee25654236f372dd8a28c5'] = array(
    'source' => 'Hello !recipient_name,

A new user called <a href="!url">!name </a>has registered. If you want to accept this registration, please mark this user as "active".

You can edit your notification settings from your <a href="!recipient_url">profile page</a>.

This was an auto-generated email from !site; please do not respond directly to this email.',
    'context' => '',
    'location' => '/index.php',
    'translation' => 'مرحباً !recipient_name،

لقد سجل مستخدم جديد باسم "<a href="!url">!name</a>". إذا كت تريد قبول تسجيله يرجى تغيير حالة حسابه إلى  "نشط". 

يمكنك تغيير إعدادات التنبيهات من <a href="!recipient_url">هنا</a>. هذه رسالة تلقائية من !site ويرجى عدم الرد عليها.
',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Hello !recipient_name,

A new user called <a href="!url">!name </a>has registered. If you want to accept this registration, please mark this user as "active".

You can edit your notification settings from your <a href="!recipient_url">profile page</a>.

This was an auto-generated email from !site; please do not respond directly to this email.', array(), array('context' => ''));
  $translations['ar:default']['33235e680d5086275b36d4695c09d046'] = array(
    'source' => 'Story title',
    'context' => '',
    'location' => '/ar/node/add/discussion',
    'translation' => 'عنوان الموضوع',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Story title', array(), array('context' => ''));
  $translations['ar:default']['337352d39aaae32683fb7feeaa0e9771'] = array(
    'source' => 'Source ID',
    'context' => '',
    'location' => '/ar',
    'translation' => ' هوية المصدر',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Source ID', array(), array('context' => ''));
  $translations['ar:default']['33ba2886eae2bbca019c6d3e28495e25'] = array(
    'source' => 'There are no results that match your search.',
    'context' => '',
    'location' => '/ar/search?status=All&keys=meme&type=All&field_tags_tid=All&field_rating_tid=All&flagged_spam=All&flagged_gc=All&sort_bef_combine=created+DESC',
    'translation' => 'لم يتم العثور على نتائج مطابقة للبحث',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('There are no results that match your search.', array(), array('context' => ''));
  $translations['ar:default']['33f07de8b8ce6be62c459fb62b30bf52'] = array(
    'source' => 'The content title.',
    'context' => '',
    'location' => '',
    'translation' => 'عنوان المضمون ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The content title.', array(), array('context' => ''));
  $translations['ar:default']['349ac84ef965fc55f2ef34b094144ae6'] = array(
    'source' => 'Locale target',
    'context' => '',
    'location' => '',
    'translation' => 'لغة الهدف',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Locale target', array(), array('context' => ''));
  $translations['ar:default']['352dcb967ffa1d84db03e7ecbda27898'] = array(
    'source' => 'Hostname of user that posted the comment.',
    'context' => '',
    'location' => '',
    'translation' => 'اسم المضيف للمستخدم الذي نشر التعليق.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Hostname of user that posted the comment.', array(), array('context' => ''));
  $translations['ar:default']['3568269b8cdffad1e0aca1480a50ae2c'] = array(
    'source' => 'Standard derivation',
    'context' => '',
    'location' => '/ar',
    'translation' => 'معيار الاشتقاق',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Standard derivation', array(), array('context' => ''));
  $translations['ar:default']['35a59c437a063351bef16b30c1582491'] = array(
    'source' => 'Logged in user',
    'context' => '',
    'location' => '',
    'translation' => 'مستخدم قام بتسجيل الدخول',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Logged in user', array(), array('context' => ''));
  $translations['ar:default']['35ea3e21be52282a67fe0c0ec73dd5dd'] = array(
    'source' => 'Create another story',
    'context' => '',
    'location' => '/ar/system/ajax',
    'translation' => 'أنشئ خبراً آخر',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Create another story', array(), array('context' => ''));
  $translations['ar:default']['362c7d20562a8d2d4c8453e35c68698b'] = array(
    'source' => 'Last Post',
    'context' => '',
    'location' => '',
    'translation' => 'آخر مقالة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Last Post', array(), array('context' => ''));
  $translations['ar:default']['3633637efbab23daca2b051dea4939b7'] = array(
    'source' => 'Taxonomy Vocabulary',
    'context' => '',
    'location' => '',
    'translation' => 'مفرات التصنيف',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Taxonomy Vocabulary', array(), array('context' => ''));
  $translations['ar:default']['368064525e8d8079ae3419d85bf9fdce'] = array(
    'source' => 'Module/Theme/Theme engine name',
    'context' => '',
    'location' => '',
    'translation' => 'Module/Theme/Theme engine name',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Module/Theme/Theme engine name', array(), array('context' => ''));
  $translations['ar:default']['36b4f478ccdf0d3a6515f875037db0bf'] = array(
    'source' => 'Dashboard (main)',
    'context' => '',
    'location' => '',
    'translation' => 'لوحة التحكم (رئيسي)',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Dashboard (main)', array(), array('context' => ''));
  $translations['ar:default']['36ba42c568da2cae48ef6190790ad045'] = array(
    'source' => 'Now Editing: ',
    'context' => '',
    'location' => 'sites/all/modules/contrib/context/plugins/context_reaction_block.js',
    'translation' => 'جار تحرير: ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Now Editing: ', array(), array('context' => ''));
  $translations['ar:default']['3707d24a00963ce1d8c0d5ff43031c80'] = array(
    'source' => 'Allows content to be submitted using Markdown, a simple plain-text syntax that is filtered into valid XHTML.',
    'context' => '',
    'location' => '/ar',
    'translation' => 'Allows content to be submitted using Markdown, a simple plain-text syntax that is filtered into valid XHTML.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Allows content to be submitted using Markdown, a simple plain-text syntax that is filtered into valid XHTML.', array(), array('context' => ''));
  $translations['ar:default']['370f6af6cbc5b4822fb47d8dc69a70ed'] = array(
    'source' => 'added this report',
    'context' => '',
    'location' => '/ar',
    'translation' => 'أضاف هذا التقرير',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('added this report', array(), array('context' => ''));
  $translations['ar:default']['3710562ccfb57f5402d86b1519385b6e'] = array(
    'source' => 'Add a report',
    'context' => '',
    'location' => '/ar/story-collaboration/35',
    'translation' => 'أضف تقرير',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Add a report', array(), array('context' => ''));
  $translations['ar:default']['37c485c8d229d4b72128bc0e06b6064f'] = array(
    'source' => 'Facebook login',
    'context' => '',
    'location' => '',
    'translation' => 'تسجيل الدخول عبر فيس بوك',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Facebook login', array(), array('context' => ''));
  $translations['ar:default']['37d3c40f259bd2b0fea0006209595e25'] = array(
    'source' => 'Created month',
    'context' => '',
    'location' => '',
    'translation' => 'شهر الإنشاء',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Created month', array(), array('context' => ''));
  $translations['ar:default']['37f118c132659296ae366bd1ddb34eea'] = array(
    'source' => 'Heartbeat activity content to form a news feed or heartbeat stream.',
    'context' => '',
    'location' => '/ar',
    'translation' => 'Heartbeat activity content to form a news feed or heartbeat stream.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Heartbeat activity content to form a news feed or heartbeat stream.', array(), array('context' => ''));
  $translations['ar:default']['38559c871fba28d992ead51549367f83'] = array(
    'source' => '<>',
    'context' => '',
    'location' => '',
    'translation' => '<>',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('<>', array(), array('context' => ''));
  $translations['ar:default']['38d054c965be09541c7c458e7c6ad2aa'] = array(
    'source' => 'Profile image',
    'context' => '',
    'location' => '',
    'translation' => 'صورة الملف الشخصي',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Profile image', array(), array('context' => ''));
  $translations['ar:default']['39784f95bf5789e14539eebec9a8ba53'] = array(
    'source' => 'Manage general Checkdesk configuration.',
    'context' => '',
    'location' => '/ar',
    'translation' => 'Manage general Checkdesk configuration.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Manage general Checkdesk configuration.', array(), array('context' => ''));
  $translations['ar:default']['398e2880f76a64629d159199ecfa3bda'] = array(
    'source' => 'Registered Users',
    'context' => '',
    'location' => '/checkdesk/ar/admin/meedan/reports',
    'translation' => 'المستخدمون المسجلون',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Registered Users', array(), array('context' => ''));
  $translations['ar:default']['39b4022ca6555741f998cbf041c67f5e'] = array(
    'source' => 'Please log in or register to relate your Twitter account with a user.',
    'context' => '',
    'location' => '/ar/twitter/oauth?oauth_token=AgIUgQoAq4MhXrZP2fa8X8tpvUZIDoGZwJyQmaTqubA&oauth_verifier=CyRpb9VadZP6bvsZRALrMrdjGI131Q6lsBiFMv8',
    'translation' => 'برجاء تسجيل الدخول أو إنشاء حساباً جديداً لربط حساب تويتر الخاص بك.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Please log in or register to relate your Twitter account with a user.', array(), array('context' => ''));
  $translations['ar:default']['39cefe43c52a470c8ab66090e564095a'] = array(
    'source' => 'If you want to submit a Facebook link, you need to <a href="@url">connect to your Facebook account first</a>.',
    'context' => '',
    'location' => '/ar/node/add/media?meedan_bookmarklet=1&meedan_bookmarklet_prepopulate[body]=%D8%A3%D8%AE%D8%A8%D8%A7%D8%B1%20|%20Meedan%20Checkdesk&meedan_bookmarklet_prepopulate[field_link]=http://qa.checkdesk.org/ar',
    'translation' => 'إن كنت تريد إضافة رابط من فيس بوك، عليك <a href="@url">ربط حسابك على فيس بوك أولاً</a>.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('If you want to submit a Facebook link, you need to <a href="@url">connect to your Facebook account first</a>.', array(), array('context' => ''));
  $translations['ar:default']['3a58f57aef975a7533f35955f9716813'] = array(
    'source' => 'User who uploaded',
    'context' => '',
    'location' => '',
    'translation' => 'المستخدم الذي قام بالتحميل ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('User who uploaded', array(), array('context' => ''));
  $translations['ar:default']['3ac7daea61ddafebf577f6fd661b2711'] = array(
    'source' => 'Heartbeat activity time element',
    'context' => '',
    'location' => '/ar',
    'translation' => 'Heartbeat activity time element',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Heartbeat activity time element', array(), array('context' => ''));
  $translations['ar:default']['3acba010fafb6611b49620a321f7b270'] = array(
    'source' => 'User role',
    'context' => '',
    'location' => '',
    'translation' => 'دور المستخدم',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('User role', array(), array('context' => ''));
  $translations['ar:default']['3b4a7c287763d99a180f2e57f9d27b48'] = array(
    'source' => 'The name of the application that posted the Twitter message.',
    'context' => '',
    'location' => '',
    'translation' => 'اسم التطبيق الذي نشر رسالة تويتر.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The name of the application that posted the Twitter message.', array(), array('context' => ''));
  $translations['ar:default']['3bcc67d68bdef48a3bc5766693afbd49'] = array(
    'source' => 'Edit Status',
    'context' => '',
    'location' => 'sites/all/themes/checkdesk/assets/js/report.js',
    'translation' => 'غيّر الحالة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Edit Status', array(), array('context' => ''));
  $translations['ar:default']['3bd812ed80baf9c3e02643d14d4e9939'] = array(
    'source' => 'Combine fields filter',
    'context' => '',
    'location' => '',
    'translation' => 'الجمع بين حقول التصفية',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Combine fields filter', array(), array('context' => ''));
  $translations['ar:default']['3bd8402f605286062e5d9964a802d6c1'] = array(
    'source' => 'The name of the component',
    'context' => '',
    'location' => '',
    'translation' => 'اسم العنصر',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The name of the component', array(), array('context' => ''));
  $translations['ar:default']['3c4c5251bd7dc489b0530e40a8bdd54e'] = array(
    'source' => 'A boolean field to show whether the flag is set or not.',
    'context' => '',
    'location' => '',
    'translation' => 'حقل منطقية لإظهار ما إذا تم تعيين العلم أم لا.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('A boolean field to show whether the flag is set or not.', array(), array('context' => ''));
  $translations['ar:default']['3c5680ededfddb1846f0b7fef356c547'] = array(
    'source' => 'A source string for translation, in English or the default site language.',
    'context' => '',
    'location' => '',
    'translation' => 'مقطع مصدري للترجمة، بالإنكليزية أو اللغة الافتراضية للموقع.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('A source string for translation, in English or the default site language.', array(), array('context' => ''));
  $translations['ar:default']['3c72d40a8413900b7fd6147dd5e7d3d2'] = array(
    'source' => 'The current date and time.',
    'context' => '',
    'location' => '',
    'translation' => 'التاريخ والوقت الحالي',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The current date and time.', array(), array('context' => ''));
  $translations['ar:default']['3cc07d689390bf91c539eb791510f964'] = array(
    'source' => 'cancel account',
    'context' => '',
    'location' => '',
    'translation' => 'إلغاء الحساب',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('cancel account', array(), array('context' => ''));
  $translations['ar:default']['3cca452b26a98e0e61597cb62062931f'] = array(
    'source' => '@count[4] collaborators',
    'context' => '',
    'location' => '/ar/story-collaboration/12404',
    'translation' => '@count[4] مشاركين',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('@count[4] collaborators', array(), array('context' => ''));
  $translations['ar:default']['3d21531686999c4fcddef6c5092407b9'] = array(
    'source' => 'Hello !recipient_name,

A new user <a href="!url">!name </a>has registered. If you want to accept this registration, please mark this user as "active".

You can edit your notification settings from your <a href="!recipient_url">profile page</a>.

This was an auto-generated email from !site; please do not respond directly to this email.',
    'context' => '',
    'location' => '/index.php',
    'translation' => 'مرحباً !recipient_name،

لقد سجل مستخدم جديد باسم "<a href="!url">!name</a>". إذا كت تريد قبول تسجيله يرجى تغيير حالة حسابه إلى  "نشط". 

يمكنك تغيير إعدادات التنبيهات من <a href="!recipient_url">هنا</a>. هذه رسالة تلقائية من !site ويرجى عدم الرد عليها.
',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Hello !recipient_name,

A new user <a href="!url">!name </a>has registered. If you want to accept this registration, please mark this user as "active".

You can edit your notification settings from your <a href="!recipient_url">profile page</a>.

This was an auto-generated email from !site; please do not respond directly to this email.', array(), array('context' => ''));
  $translations['ar:default']['3d39d265a220809f8715d0f0057aed3e'] = array(
    'source' => 'Default settings for this view.',
    'context' => '',
    'location' => '',
    'translation' => 'الإعدادات الافتراضية لهذا العرض',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Default settings for this view.', array(), array('context' => ''));
  $translations['ar:default']['3d56d2c7c8387b4c0708d8e5a5599f16'] = array(
    'source' => 'Fact-checking status',
    'context' => '',
    'location' => '',
    'translation' => 'حالة التحقق من صحة المعلومات',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Fact-checking status', array(), array('context' => ''));
  $translations['ar:default']['3dad41aae7826fb78c85588838316f37'] = array(
    'source' => 'Updated year + month',
    'context' => '',
    'location' => '',
    'translation' => 'تم تحديث العام + شهر',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Updated year + month', array(), array('context' => ''));
  $translations['ar:default']['3db0c54dffde09a0db39936fc396425c'] = array(
    'source' => 'The \'From\' field of the e-mail address.',
    'context' => '',
    'location' => '/ar',
    'translation' => 'The \'From\' field of the e-mail address.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The \'From\' field of the e-mail address.', array(), array('context' => ''));
  $translations['ar:default']['3dbfb850e497fad6fd14109558197b80'] = array(
    'source' => 'A blog by <a href="@url">!owner</a>.',
    'context' => '',
    'location' => '',
    'translation' => 'مدوّنة من <a href="@url">!owner</a>.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('A blog by <a href="@url">!owner</a>.', array(), array('context' => ''));
  $translations['ar:default']['3e0fa00ee2fba747e8419e80c1da2d72'] = array(
    'source' => 'Share on Facebook',
    'context' => '',
    'location' => '',
    'translation' => 'شارك على فيس بوك',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Share on Facebook', array(), array('context' => ''));
  $translations['ar:default']['3e11279e7c70337430ef8086f9d69de1'] = array(
    'source' => 'Taxonomy term name.',
    'context' => '',
    'location' => '',
    'translation' => 'مصطلح اسم التصنيف.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Taxonomy term name.', array(), array('context' => ''));
  $translations['ar:default']['3e1b5bd4be1a3fc40e9b59a21af13948'] = array(
    'source' => 'Source name',
    'context' => '',
    'location' => '/ar',
    'translation' => ' اسم المصدر',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Source name', array(), array('context' => ''));
  $translations['ar:default']['3e5ee10537dd32df4c4d7e5d54f269f4'] = array(
    'source' => 'Navigation bar',
    'context' => '',
    'location' => '/ar',
    'translation' => 'شريط التنقل',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Navigation bar', array(), array('context' => ''));
  $translations['ar:default']['3e6848016309c5ca93805ab4c51b149b'] = array(
    'source' => 'changed status to ',
    'context' => '',
    'location' => '/ar',
    'translation' => 'غيّر الحالة إلى',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('changed status to ', array(), array('context' => ''));
  $translations['ar:default']['3eb0e3f642ee1365f197e6104d7cf17d'] = array(
    'source' => 'Module/Theme/Theme engine filename',
    'context' => '',
    'location' => '',
    'translation' => 'وحدة / سمة / اسم ملف سمة المحرك ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Module/Theme/Theme engine filename', array(), array('context' => ''));
  $translations['ar:default']['3eb2f3bea511ad4d4ab98586b8fdb3a3'] = array(
    'source' => '1 report',
    'context' => '',
    'location' => '/ar/story-collaboration/10970',
    'translation' => '1 تقرير',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('1 report', array(), array('context' => ''));
  $translations['ar:default']['3f1141a40c80035667e6111ae4728a3e'] = array(
    'source' => ' new',
    'context' => '',
    'location' => '',
    'translation' => 'جديد',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t(' new', array(), array('context' => ''));
  $translations['ar:default']['3f2e83c44c65f0ff283ee70f21d348b9'] = array(
    'source' => 'Provide a simple link to delete the content.',
    'context' => '',
    'location' => '',
    'translation' => 'تقديم وصلة بسيطة لحذف المحتوى.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Provide a simple link to delete the content.', array(), array('context' => ''));
  $translations['ar:default']['3f5fe08db784512169086d9b23b6466a'] = array(
    'source' => 'Cancel deletion request',
    'context' => '',
    'location' => '/ar/admin/content',
    'translation' => 'إلغاء طلب الحذف',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Cancel deletion request', array(), array('context' => ''));
  $translations['ar:default']['3f687252bd7220346dea8d1c30a66eef'] = array(
    'source' => 'Date Desc',
    'context' => '',
    'location' => '',
    'translation' => 'التاريخ تنازلي',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Date Desc', array(), array('context' => ''));
  $translations['ar:default']['3f68e67dc6c397aaa9d1c24c356f754f'] = array(
    'source' => 'Verified',
    'context' => '',
    'location' => '',
    'translation' => 'صحيح',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Verified', array(), array('context' => ''));
  $translations['ar:default']['3f93adb4b5aca6af484647dce57f7bfc'] = array(
    'source' => 'Group results together',
    'context' => '',
    'location' => '',
    'translation' => 'جمع النتائج معاً',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Group results together', array(), array('context' => ''));
  $translations['ar:default']['3fb3f7c0f7a24b5658740a6617447393'] = array(
    'source' => 'All displays (except overridden)',
    'context' => '',
    'location' => '',
    'translation' => 'كل العروض (عدا المتجاوزة)',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('All displays (except overridden)', array(), array('context' => ''));
  $translations['ar:default']['3fbd510a0c085d2022fccd6b3cf6206c'] = array(
    'source' => 'Submit a new report',
    'context' => '',
    'location' => '/ar/meedan_bookmarklet/message?meedan_bookmarklet=1&meedan_bookmarklet_submitted=1&meedan_bookmarklet_nid=236',
    'translation' => 'أرسل تقريراً آخر',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Submit a new report', array(), array('context' => ''));
  $translations['ar:default']['3ff0ffb7cc38d60dd2b90799d8a7d836'] = array(
    'source' => 'views_load_more',
    'context' => '',
    'location' => '/ar',
    'translation' => 'views_load_more',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('views_load_more', array(), array('context' => ''));
  $translations['ar:default']['3fff900ef37b2133ec3c9b9719ecc409'] = array(
    'source' => 'fact-checking footnotes',
    'context' => '',
    'location' => '',
    'translation' => 'ملاحظات للتحقق من صحة المعلومات',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('fact-checking footnotes', array(), array('context' => ''));
  $translations['ar:default']['402251116006c23306e2d518c56b15a9'] = array(
    'source' => 'The user that flagged an item. If you need more fields than the uid add the "Flags: User" relationship.',
    'context' => '',
    'location' => '',
    'translation' => 'The user that flagged an item. If you need more fields than the uid add the "Flags: User" relationship.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The user that flagged an item. If you need more fields than the uid add the "Flags: User" relationship.', array(), array('context' => ''));
  $translations['ar:default']['40425d31e4af1bc23499494b8f91a25f'] = array(
    'source' => 'Allow multiple values',
    'context' => '',
    'location' => '',
    'translation' => 'السماح بتعدد القيم',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Allow multiple values', array(), array('context' => ''));
  $translations['ar:default']['405dcdcb91b3b5d0b0a84b6584742ffe'] = array(
    'source' => 'Heartbeat activity message element',
    'context' => '',
    'location' => '/ar',
    'translation' => 'Heartbeat activity message element',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Heartbeat activity message element', array(), array('context' => ''));
  $translations['ar:default']['4064f35ed2b1c1450c9aa4a0796eae85'] = array(
    'source' => 'A file that is associated with this taxonomy vocabulary, usually because it is in a field on the taxonomy vocabulary.',
    'context' => '',
    'location' => '',
    'translation' => 'ملف مقترن هذه المفردات التصنيف، لأنها عادة ما تكون في حقل على مفردات التصنيف.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('A file that is associated with this taxonomy vocabulary, usually because it is in a field on the taxonomy vocabulary.', array(), array('context' => ''));
  $translations['ar:default']['40a1f4762e4c516e5babfdae8e8512c5'] = array(
    'source' => 'Randomize the display order.',
    'context' => '',
    'location' => '',
    'translation' => 'ترتيب العرض بطريقة عشوائية.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Randomize the display order.', array(), array('context' => ''));
  $translations['ar:default']['40c44639652564e97b4d8e1a93b56160'] = array(
    'source' => 'I\'m online.',
    'context' => '',
    'location' => '',
    'translation' => 'أنا متصل',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('I\'m online.', array(), array('context' => ''));
  $translations['ar:default']['40cd014b7b6251e3a22e6a45a73a64e1'] = array(
    'source' => 'Execute',
    'context' => '',
    'location' => '',
    'translation' => 'تنفيذ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Execute', array(), array('context' => ''));
  $translations['ar:default']['411abaca0bf1440a8c91ee0dab9fa5f2'] = array(
    'source' => 'Display the time the content was flagged by a user.',
    'context' => '',
    'location' => '',
    'translation' => 'عرض وقت قيام المستخدم بتحذير المشرف حول المحتوى.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Display the time the content was flagged by a user.', array(), array('context' => ''));
  $translations['ar:default']['416715195fdd9088b0faf749847924d1'] = array(
    'source' => 'By source',
    'context' => '',
    'location' => '',
    'translation' => 'المصدر',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('By source', array(), array('context' => ''));
  $translations['ar:default']['41931d2a363d3be3b44f788c7225edc7'] = array(
    'source' => 'Last comment time',
    'context' => '',
    'location' => '',
    'translation' => 'توقيت اخر تعليق',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Last comment time', array(), array('context' => ''));
  $translations['ar:default']['41af5405dbddfcabff34af1143014564'] = array(
    'source' => ' added this ',
    'context' => '',
    'location' => '',
    'translation' => 'اضافه',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t(' added this ', array(), array('context' => ''));
  $translations['ar:default']['4218cb6af61563d123fed63f858da62a'] = array(
    'source' => 'ID to recognize this specific scheduled task',
    'context' => '',
    'location' => '',
    'translation' => 'الهويه للتعرف على المهمه المقرره ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('ID to recognize this specific scheduled task', array(), array('context' => ''));
  $translations['ar:default']['42686997e2f6b9d9aaa86c475f0722c2'] = array(
    'source' => 'Display a specified number of items',
    'context' => '',
    'location' => '',
    'translation' => 'عرض عدد محدد من العناصر',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Display a specified number of items', array(), array('context' => ''));
  $translations['ar:default']['428ac54f2c15951ae90ea57be364545b'] = array(
    'source' => 'Add more info or write a description. What\'s the context? Does this link need to be fact-checked? What evidence do you have?',
    'context' => '',
    'location' => '/ar/node/add/media?meedan_bookmarklet=1',
    'translation' => 'اكتب وصفاً أو أضف المزيد من المعلومات. ما هو السياق؟ هل يحتاج هذا الرابط إلى التحقق من صحته؟ هل لديك أدلة على ذلك؟',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Add more info or write a description. What\'s the context? Does this link need to be fact-checked? What evidence do you have?', array(), array('context' => ''));
  $translations['ar:default']['42a41547108cf6e465536fed2a68c1ac'] = array(
    'source' => 'Create a Story',
    'context' => '',
    'location' => 'sites/all/themes/checkdesk/assets/js/tour.js; sites/all/modules/custom/checkdesk_tour/js/tour.js',
    'translation' => 'أضف موضوع',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Create a Story', array(), array('context' => ''));
  $translations['ar:default']['42aeb4e610e1f0dd100cbad25a013643'] = array(
    'source' => 'Update preview',
    'context' => '',
    'location' => '',
    'translation' => 'تحديث المعاينة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Update preview', array(), array('context' => ''));
  $translations['ar:default']['4368d7c3326661e7b36dcd2ca243a606'] = array(
    'source' => 'User activity ID',
    'context' => '',
    'location' => '/ar',
    'translation' => 'هوية نشاط المستخدم',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('User activity ID', array(), array('context' => ''));
  $translations['ar:default']['43dc4c29d59c2c845bbb01ce770692f5'] = array(
    'source' => 'Uid',
    'context' => '',
    'location' => '',
    'translation' => 'Uid',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Uid', array(), array('context' => ''));
  $translations['ar:default']['43ec3e5dee6e706af7766fffea512721'] = array(
    'source' => '=',
    'context' => '',
    'location' => '',
    'translation' => '=',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('=', array(), array('context' => ''));
  $translations['ar:default']['43ee9333b43f4c88983708f4954f35c3'] = array(
    'source' => 'The language the content is in.',
    'context' => '',
    'location' => '',
    'translation' => 'لغة المحتوى',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The language the content is in.', array(), array('context' => ''));
  $translations['ar:default']['43efe0a13f5e3ed356f742abcfeffb47'] = array(
    'source' => 'The number of users who have submitted a report in any given month',
    'context' => '',
    'location' => '/checkdesk/ar/admin/meedan/reports',
    'translation' => 'عدد المستخدمين الذين قاموا بإرسال التقارير في شهر معين',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The number of users who have submitted a report in any given month', array(), array('context' => ''));
  $translations['ar:default']['449dd4a2a06c5dda6b0ad3048bec37bf'] = array(
    'source' => 'This report contains graphic content',
    'context' => '',
    'location' => '/ar/node/add/media?meedan_bookmarklet=1&meedan_bookmarklet_prepopulate[body]=%D8%A3%D8%AE%D8%A8%D8%A7%D8%B1%20|%20Meedan%20Checkdesk&meedan_bookmarklet_prepopulate[field_link]=http://qa.checkdesk.org/ar',
    'translation' => 'هذا التقرير يتضمن محتوى أو صوراً صادمة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('This report contains graphic content', array(), array('context' => ''));
  $translations['ar:default']['44d3396dca6297a9f757b976960849cb'] = array(
    'source' => 'Modules/Themes/Theme engines in your codebase.',
    'context' => '',
    'location' => '',
    'translation' => 'Modules/Themes/Theme engines in your codebase.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Modules/Themes/Theme engines in your codebase.', array(), array('context' => ''));
  $translations['ar:default']['456bb04b612ffde1138e866bc92433f7'] = array(
    'source' => 'Content with media sources',
    'context' => '',
    'location' => '/ar',
    'translation' => 'المحتوى مع مصادر إعلامية',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Content with media sources', array(), array('context' => ''));
  $translations['ar:default']['458f9b75b4154ad31a4a408f3c860372'] = array(
    'source' => 'The taxonomy vocabulary weight',
    'context' => '',
    'location' => '',
    'translation' => 'وزن مفردات التصنيف',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The taxonomy vocabulary weight', array(), array('context' => ''));
  $translations['ar:default']['462a3069e4fd95d9a9ed8ca8a80a6442'] = array(
    'source' => 'Include this to gain access to the flag counter field.',
    'context' => '',
    'location' => '',
    'translation' => 'Include this to gain access to the flag counter field.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Include this to gain access to the flag counter field.', array(), array('context' => ''));
  $translations['ar:default']['4656bdc32e6d19e394697cc8a18f25d8'] = array(
    'source' => 'A @flag-type has been flagged, under "@flag-title"',
    'context' => '',
    'location' => '',
    'translation' => 'تم تنبيه المشرف على @flag-type، تحت "@flag-title" ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('A @flag-type has been flagged, under "@flag-title"', array(), array('context' => ''));
  $translations['ar:default']['466dc76f1649600955cab2a4f2ed150b'] = array(
    'source' => 'Attachments for the activity message',
    'context' => '',
    'location' => '/ar',
    'translation' => 'مرفقات رسالة النشاط',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Attachments for the activity message', array(), array('context' => ''));
  $translations['ar:default']['468581c520cf8cf9bc2aeb1d5833e950'] = array(
    'source' => 'Date in the form of CCYYMMDD.',
    'context' => '',
    'location' => '',
    'translation' => 'التاريخ بصيغة يوم شهر سنة CCYYMMDD',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Date in the form of CCYYMMDD.', array(), array('context' => ''));
  $translations['ar:default']['4698ee3fcd8d278acafe4d91ac5adada'] = array(
    'source' => 'Uploaded file.',
    'context' => '',
    'location' => '',
    'translation' => 'الملف المرفوع',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Uploaded file.', array(), array('context' => ''));
  $translations['ar:default']['46aa89deb6e2e18377994f52358e8227'] = array(
    'source' => 'Pick the status that reflects the state of the verification process',
    'context' => '',
    'location' => '/ar/node/1993',
    'translation' => 'TODO',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Pick the status that reflects the state of the verification process', array(), array('context' => ''));
  $translations['ar:default']['46bc9efa9c8ee4653322b503a493a190'] = array(
    'source' => ' verification footnotes',
    'context' => '',
    'location' => '/ar',
    'translation' => 'ملاحظات التحقق ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t(' verification footnotes', array(), array('context' => ''));
  $translations['ar:default']['46bf19d972b59af496cf97139850ae39'] = array(
    'source' => 'Store a date in the database as a timestamp, deprecated format to support legacy data.',
    'context' => '',
    'location' => '',
    'translation' => 'Store a date in the database as a timestamp, deprecated format to support legacy data.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Store a date in the database as a timestamp, deprecated format to support legacy data.', array(), array('context' => ''));
  $translations['ar:default']['4700c47fcd5dd07cb982f1e082b5e4eb'] = array(
    'source' => 'Follow a story to stay up to date with the latest developments',
    'context' => '',
    'location' => '/ar',
    'translation' => 'تابع الموضوع للحصول على تنبيهات حول التحديثات الجديدة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Follow a story to stay up to date with the latest developments', array(), array('context' => ''));
  $translations['ar:default']['4730a2e2bdbe422b0346efc8ff0927a6'] = array(
    'source' => 'Display the user with standard user view.',
    'context' => '',
    'location' => '',
    'translation' => 'عرض المستخدم مع المستخدم القياسي ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Display the user with standard user view.', array(), array('context' => ''));
  $translations['ar:default']['4757d5f38751ddf49d704e92e83af499'] = array(
    'source' => 'New footnote',
    'context' => '',
    'location' => '/ar/reports',
    'translation' => 'معلومات جديدة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('New footnote', array(), array('context' => ''));
  $translations['ar:default']['475b9c5f346939dfe65a719b27545da1'] = array(
    'source' => 'Auto-Refresh',
    'context' => '',
    'location' => '',
    'translation' => 'تحديث تلقائي',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Auto-Refresh', array(), array('context' => ''));
  $translations['ar:default']['47cc2d3ae9ee63b2ad6922ef67ae39f2'] = array(
    'source' => '<a class="actor" href="!flag_author_url">!flag_author_name</a> has flagged a <a href="!report_url">report</a> as <span class="notification-flag">!flag_type</span>',
    'context' => '',
    'location' => '/ar/story-collaboration/12289',
    'translation' => 'قام <a href="!flag_author_url">!flag_author_name</a>  بتنبيه فريق العمل عن <a href="!report_url">التقرير الآتي</a> بأنه <span class="notification-flag">!flag_type</span>',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('<a class="actor" href="!flag_author_url">!flag_author_name</a> has flagged a <a href="!report_url">report</a> as <span class="notification-flag">!flag_type</span>', array(), array('context' => ''));
  $translations['ar:default']['47dd36999849370d5f86e6aa873fafa7'] = array(
    'source' => 'Theme key "@key" not found.',
    'context' => '',
    'location' => '',
    'translation' => 'مفتاح القالب "@key" غير موجود.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Theme key "@key" not found.', array(), array('context' => ''));
  $translations['ar:default']['480a9c797b810ce66797ca27786033dd'] = array(
    'source' => 'Load more updates',
    'context' => '',
    'location' => '',
    'translation' => 'تحميل المزيد',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Load more updates', array(), array('context' => ''));
  $translations['ar:default']['4812662d52f49fddda9719bd375005b4'] = array(
    'source' => 'You can follow <a href="!link"> @Checkdesk on Twitter </a>.',
    'context' => '',
    'location' => '/index.php',
    'translation' => 'يمكنك متابعة<a href="!link"> @تشك دسك على تويتر </a>.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('You can follow <a href="!link"> @Checkdesk on Twitter </a>.', array(), array('context' => ''));
  $translations['ar:default']['483419bf948f62a3495739e8c420d38c'] = array(
    'source' => 'The revision ID of the content revision.',
    'context' => '',
    'location' => '',
    'translation' => 'هوية مراجعة المحتوى.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The revision ID of the content revision.', array(), array('context' => ''));
  $translations['ar:default']['4837660e9060332de249fc67f71f30a3'] = array(
    'source' => 'Click to show',
    'context' => '',
    'location' => '/ar/node/add/media?meedan_bookmarklet=1&meedan_bookmarklet_prepopulate[body]=%D8%A3%D8%AE%D8%A8%D8%A7%D8%B1%20|%20Meedan%20Checkdesk&meedan_bookmarklet_prepopulate[field_link]=http://qa.checkdesk.org/ar',
    'translation' => 'انقر للعرض',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Click to show', array(), array('context' => ''));
  $translations['ar:default']['48b69e6bbf2706ecd6b2d14a95ae9bd8'] = array(
    'source' => '- No value -',
    'context' => '',
    'location' => '',
    'translation' => '- لا قيمة -',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('- No value -', array(), array('context' => ''));
  $translations['ar:default']['48ca3d61a9a07cb830df5a78fa6b7462'] = array(
    'source' => 'Filter by access.',
    'context' => '',
    'location' => '',
    'translation' => 'التصفية حسب الوصول.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Filter by access.', array(), array('context' => ''));
  $translations['ar:default']['490081f2e725278d6d4f3ba2311689b5'] = array(
    'source' => 'Rendered entity',
    'context' => '',
    'location' => '',
    'translation' => 'Rendered entity',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Rendered entity', array(), array('context' => ''));
  $translations['ar:default']['4928c90a78c988e778fef497e3855f2d'] = array(
    'source' => 'Unflag graphic content',
    'context' => '',
    'location' => '/ar/admin/content',
    'translation' => 'إلغاء تنبيه المحتوى الصادم',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Unflag graphic content', array(), array('context' => ''));
  $translations['ar:default']['492bd7d43cf30113c8071f97e310ff2f'] = array(
    'source' => 'Authentication name',
    'context' => '',
    'location' => '',
    'translation' => 'الاسم المصادق ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Authentication name', array(), array('context' => ''));
  $translations['ar:default']['493333d343788a39e8cfdb74bb8d2a7a'] = array(
    'source' => 'Renders a single entity in a specific view mode (e.g. teaser).',
    'context' => '',
    'location' => '',
    'translation' => 'Renders a single entity in a specific view mode (e.g. teaser).',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Renders a single entity in a specific view mode (e.g. teaser).', array(), array('context' => ''));
  $translations['ar:default']['4970a2098caaebbacf74df1005702c85'] = array(
    'source' => '<a href="@user">!user</a> submitted this <time class="date-time" datetime="!timestamp">!datetime_ago ago</time>',
    'context' => '',
    'location' => '/',
    'translation' => 'اضافه <a href="@user">!user</a> <time class="date-time" datetime="!timestamp">منذ !datetime_ago</time>',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('<a href="@user">!user</a> submitted this <time class="date-time" datetime="!timestamp">!datetime_ago ago</time>', array(), array('context' => ''));
  $translations['ar:default']['498fe1443c27a54d4720db75ce63985d'] = array(
    'source' => 'You can submit a Facebook link above.',
    'context' => '',
    'location' => '/ar/node/add/media?meedan_bookmarklet=1&meedan_bookmarklet_prepopulate[body]=%D8%A3%D9%86%D8%B4%D8%A6%20%D8%AE%D8%A8%D8%B1%20|%20Meedan%20Checkdesk&meedan_bookmarklet_prepopulate[field_link]=http://qa.checkdesk.org/ar/node/add/discussion',
    'translation' => 'بإمكانك إرسال رابط من الفيس بوك هنا.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('You can submit a Facebook link above.', array(), array('context' => ''));
  $translations['ar:default']['4a0d7cfb81a42ddcfa269d248c79d099'] = array(
    'source' => 'An update has been drafted to a story',
    'context' => '',
    'location' => '/index.php',
    'translation' => 'تم إضافة مسودة جديدة لموضوع',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('An update has been drafted to a story', array(), array('context' => ''));
  $translations['ar:default']['4a169763e9dc163461589d93ac7cd520'] = array(
    'source' => 'Display the comment with standard comment view.',
    'context' => '',
    'location' => '',
    'translation' => 'عرض التعليق مع وجهة نظر تعليق قياسية.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Display the comment with standard comment view.', array(), array('context' => ''));
  $translations['ar:default']['4a2480e3d9ce54d9d6d44c81b8825d1a'] = array(
    'source' => 'The ID of the Twitter status this message is replying to.',
    'context' => '',
    'location' => '',
    'translation' => 'The ID of the Twitter status this message is replying to.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The ID of the Twitter status this message is replying to.', array(), array('context' => ''));
  $translations['ar:default']['4a3f0ef42a646fd681e1abaada3d4c3e'] = array(
    'source' => '<p><strong><a href="!user_url">!username</a></strong> has added footnote to report <strong><a href="!report_url">!report_title</a></strong></p>',
    'context' => '',
    'location' => '/ar/comment/reply/260',
    'translation' => '<p>قام <strong><a href="!user_url">!username</a></strong> بإضافة معلومات جديدة للتحقق من صحة المعلومات في التقرير <strong><a href="!report_url">!report_title</a></strong>.</p>',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('<p><strong><a href="!user_url">!username</a></strong> has added footnote to report <strong><a href="!report_url">!report_title</a></strong></p>', array(), array('context' => ''));
  $translations['ar:default']['4a4c6e96d995fe553dc624469260f636'] = array(
    'source' => 'Sign in with :',
    'context' => '',
    'location' => '/ar/user',
    'translation' => 'تسجيل الدخول عبر:',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Sign in with :', array(), array('context' => ''));
  $translations['ar:default']['4b1b4dc8cf38b3c64b1d657da8f5ac8c'] = array(
    'source' => 'Report',
    'context' => '',
    'location' => '/ar',
    'translation' => 'تقرير',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Report', array(), array('context' => ''));
  $translations['ar:default']['4b2b12df7ff671c75022f6769b728238'] = array(
    'source' => 'This report was flagged for fact-checking.',
    'context' => '',
    'location' => '/ar/node/flag/confirm/flag/factcheck/236/ajax',
    'translation' => 'تم تنبيه المشرف للتحقق من صحة المعلومات في هذا التقرير.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('This report was flagged for fact-checking.', array(), array('context' => ''));
  $translations['ar:default']['4b2d409cedb1b9fa83986ea457a0c075'] = array(
    'source' => 'Embed this story',
    'context' => '',
    'location' => '/ar',
    'translation' => 'ضمّن هذا الموضوع على موقعك',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Embed this story', array(), array('context' => ''));
  $translations['ar:default']['4bff05535aee5c43bfb8048e0a48a39d'] = array(
    'source' => 'Cannot rename field %table.%name to %name_new: target field already exists.',
    'context' => '',
    'location' => '',
    'translation' => 'لا يمكن إعادة تسمية الحقل %table.%name إلى %name_new: الحقل موجود مسبقاً.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Cannot rename field %table.%name to %name_new: target field already exists.', array(), array('context' => ''));
  $translations['ar:default']['4c3d15bfe463d7a26ca6041afe0bab45'] = array(
    'source' => 'Needing deletion',
    'context' => '',
    'location' => '/ar/user/577/notifications',
    'translation' => 'يحتاج الحذف',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Needing deletion', array(), array('context' => ''));
  $translations['ar:default']['4c45bf6d26fa54e8ac221af873df9ca7'] = array(
    'source' => 'This report was flagged for deletion.',
    'context' => '',
    'location' => '/ar/node/flag/confirm/flag/delete/259/ajax',
    'translation' => 'تم تنبيه المشرف لحذف التقرير.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('This report was flagged for deletion.', array(), array('context' => ''));
  $translations['ar:default']['4c580417b4022143285f7caf92c6205f'] = array(
    'source' => 'Hello !recipient_name,

!actor has changed report "!node_title"  status.

<a href="!story_url">Click here</a> to compose a new update to the story using that report.

You can edit your notification settings from your <a href="!recipient_url">profile page</a>.

This was an auto-generated email from !site, please do not respond directly to this email.',
    'context' => '',
    'location' => '/index.php',
    'translation' => 'مرحباً !recipient_name،

قام !actor بتغيير حالة هذا التقرير "!node_title" .

<a href="!story_url">اضغط هنا</a> لكتابة تحديث جديد على ذلك الخبر باستخدام ذاك التقرير.

بإمكانك تعديل إعدادات التنبيهات الخاصة بك من صفحة <a href="!recipient_url">الحساب الشخصي</a> الخاصة بك.

هذه رسالة مولدة بشكل تلقائي من !site، يرجى عدم الرد على هذه الرسالة.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Hello !recipient_name,

!actor has changed report "!node_title"  status.

<a href="!story_url">Click here</a> to compose a new update to the story using that report.

You can edit your notification settings from your <a href="!recipient_url">profile page</a>.

This was an auto-generated email from !site, please do not respond directly to this email.', array(), array('context' => ''));
  $translations['ar:default']['4cc6684df7b4a92b1dec6fce3264fac8'] = array(
    'source' => 'Global',
    'context' => '',
    'location' => '',
    'translation' => 'عالمي',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Global', array(), array('context' => ''));
  $translations['ar:default']['4cd8413207629a963225f4314b53adcd'] = array(
    'source' => 'Plain',
    'context' => '',
    'location' => '',
    'translation' => 'عادي',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Plain', array(), array('context' => ''));
  $translations['ar:default']['4d275d21286e875863aea98339ce331f'] = array(
    'source' => 'Contextual Links',
    'context' => '',
    'location' => '',
    'translation' => 'الخيارات السياقية',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Contextual Links', array(), array('context' => ''));
  $translations['ar:default']['4d368011dc96ac37729e360140979678'] = array(
    'source' => 'The date the file was uploaded.',
    'context' => '',
    'location' => '',
    'translation' => 'التاريخ الذي تم تحميل الملف فيه',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The date the file was uploaded.', array(), array('context' => ''));
  $translations['ar:default']['4d4b639a13cac5a634a5b4e56b1fa0a4'] = array(
    'source' => 'Content access',
    'context' => '',
    'location' => '',
    'translation' => 'الوصول إلى المحتوى',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Content access', array(), array('context' => ''));
  $translations['ar:default']['4df211924b23a31142bb7a6ac9a33832'] = array(
    'source' => 'Oldest',
    'context' => '',
    'location' => '/ar/search?field_tags_tid=1327',
    'translation' => 'الأقدم',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Oldest', array(), array('context' => ''));
  $translations['ar:default']['4dfbb099eafd3c82e033bf92946d3ce6'] = array(
    'source' => 'Mail',
    'context' => '',
    'location' => '',
    'translation' => 'بريد إلكتروني',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Mail', array(), array('context' => ''));
  $translations['ar:default']['4e072f064047f71141e715f0f1ab09f0'] = array(
    'source' => 'Fact-checking set on a report I submitted',
    'context' => '',
    'location' => '/ar',
    'translation' => 'تغيير حالة تقصي صحة المعلومات على تقرير قمت بإرساله',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Fact-checking set on a report I submitted', array(), array('context' => ''));
  $translations['ar:default']['4e7385f8cdc8abea9b5c02a4a21e0081'] = array(
    'source' => 'Hello !recipient_name,

!author has drafted a <a href="!url">new update</a> to the story "!title".
',
    'context' => '',
    'location' => '/index.php',
    'translation' => 'مرحباً !recipient_name،

قام !author بكتابة <a href="!url"> مسودة تحديث </a> للموضوع "!title".',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Hello !recipient_name,

!author has drafted a <a href="!url">new update</a> to the story "!title".
', array(), array('context' => ''));
  $translations['ar:default']['4ea2a22ce80f704919492b0836fa9cf2'] = array(
    'source' => 'Thank you for applying for an account. Your account is currently pending approval by the site administrator.<br />Once it has been approved, you will receive an e-mail containing further instructions.',
    'context' => '',
    'location' => '/ar/user/register',
    'translation' => 'نشكرك لطلبك حسابا. حسابك حاليا بانتظار موافقة مشرف الموقع.<br /> حتى يحين ذلك، أرسلت رسالة ترحيب تحوي المزيد من المعلومات إلى عنوان بريدك الإلكتروني.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Thank you for applying for an account. Your account is currently pending approval by the site administrator.<br />Once it has been approved, you will receive an e-mail containing further instructions.', array(), array('context' => ''));
  $translations['ar:default']['4ea7801f17a4e5485e8b050c052fb443'] = array(
    'source' => 'Flags',
    'context' => '',
    'location' => '',
    'translation' => 'تحذيرات المشرف',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Flags', array(), array('context' => ''));
  $translations['ar:default']['4f57fc5ca51ab75d72cfe9dcd1ed89f5'] = array(
    'source' => 'Provide a checkbox to select the row for bulk operations.',
    'context' => '',
    'location' => '',
    'translation' => 'توفير مربع لتحديد الصف لمجمل العمليات ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Provide a checkbox to select the row for bulk operations.', array(), array('context' => ''));
  $translations['ar:default']['4f5d26af458c303621f8785bd477a9ac'] = array(
    'source' => 'Go to story',
    'context' => '',
    'location' => '/',
    'translation' => 'إذهب إلى الخبر',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Go to story', array(), array('context' => ''));
  $translations['ar:default']['4f8e7e26a8243eec1e248a31c209c3c9'] = array(
    'source' => 'Time last flagged',
    'context' => '',
    'location' => '',
    'translation' => 'وقت آخر تحذير',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Time last flagged', array(), array('context' => ''));
  $translations['ar:default']['50372d299af1f3015d02bfb77e34e582'] = array(
    'source' => 'Internal, numeric @entity ID',
    'context' => '',
    'location' => '',
    'translation' => 'Internal, numeric @entity ID',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Internal, numeric @entity ID', array(), array('context' => ''));
  $translations['ar:default']['50480f331dd88099c20ce87ca097e9f2'] = array(
    'source' => 'Time ago',
    'context' => '',
    'location' => '',
    'translation' => 'منذ فترة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Time ago', array(), array('context' => ''));
  $translations['ar:default']['508462d2ba5e6dbffab4367ef4bdd091'] = array(
    'source' => '@label:delta',
    'context' => '',
    'location' => '',
    'translation' => '@label:delta',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('@label:delta', array(), array('context' => ''));
  $translations['ar:default']['5147fbd39d622c85601910b9e9c25495'] = array(
    'source' => 'View: @view - Display: @display',
    'context' => '',
    'location' => '',
    'translation' => 'الرؤية: @view - العرض: @display',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('View: @view - Display: @display', array(), array('context' => ''));
  $translations['ar:default']['5174d1309f275ba6f275db3af9eb3e18'] = array(
    'source' => 'Grid',
    'context' => '',
    'location' => '',
    'translation' => 'شبكة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Grid', array(), array('context' => ''));
  $translations['ar:default']['518ca5411699c1ca9d809e1478169790'] = array(
    'source' => 'The time the Twitter message was posted.',
    'context' => '',
    'location' => '',
    'translation' => 'الوقت الذي تم نشر رسالة تويتر.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The time the Twitter message was posted.', array(), array('context' => ''));
  $translations['ar:default']['51b6093b29b6739824b68c062ad0e788'] = array(
    'source' => 'Capitalize first letter',
    'context' => '',
    'location' => '',
    'translation' => 'تكبير أول حرف',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Capitalize first letter', array(), array('context' => ''));
  $translations['ar:default']['51dabffb3dcea503340620699d6cb1bf'] = array(
    'source' => 'Vid',
    'context' => '',
    'location' => '',
    'translation' => 'Vid',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Vid', array(), array('context' => ''));
  $translations['ar:default']['520438859648141df4665aae9574246e'] = array(
    'source' => 'Default sort',
    'context' => 'Sort order',
    'location' => '',
    'translation' => 'الترتيب الافتراضي',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Default sort', array(), array('context' => 'Sort order'));
  $translations['ar:default']['528d47c4e82bf6c33174ff79e93408fc'] = array(
    'source' => 'RSS description',
    'context' => '',
    'location' => '',
    'translation' => 'وصف الـRSS',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('RSS description', array(), array('context' => ''));
  $translations['ar:default']['5293888dd00925c656143823fe07d5e3'] = array(
    'source' => 'Date and time of when the comment was last updated.',
    'context' => '',
    'location' => '',
    'translation' => 'تاريخ ووقت آخر تحديث للتعليق.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Date and time of when the comment was last updated.', array(), array('context' => ''));
  $translations['ar:default']['52c776fe967024a9e6f0cee882323de9'] = array(
    'source' => 'Provide a simple link to reply to the comment.',
    'context' => '',
    'location' => '',
    'translation' => 'ضع رابط بسيط للرد على التعليق.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Provide a simple link to reply to the comment.', array(), array('context' => ''));
  $translations['ar:default']['5310c8574ebd63ece56b597c16adfbdc'] = array(
    'source' => '(Linked accounts)',
    'context' => '',
    'location' => '/ar/node/add/post',
    'translation' => '(حسابات مرتبطة)',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('(Linked accounts)', array(), array('context' => ''));
  $translations['ar:default']['532220dbf680ea98d665427b145e72ca'] = array(
    'source' => 'Translated',
    'context' => '',
    'location' => '',
    'translation' => 'مترجم',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Translated', array(), array('context' => ''));
  $translations['ar:default']['53244674c1ec336f38c4fdf9364ac2bd'] = array(
    'source' => '<span>@count[3]</span> results. Drag and drop the best ones.',
    'context' => '',
    'location' => '/ar/node/add/post?sort_order=DESC&title=cazuza&title_op=contains&source=&source_op=contains',
    'translation' => '<span>@count[3]</span> نتائج. يمكنك سحب تقاريرك المفضلة لاستخدامها. ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('<span>@count[3]</span> results. Drag and drop the best ones.', array(), array('context' => ''));
  $translations['ar:default']['532d4042c1a9447d390a27cad366a95f'] = array(
    'source' => 'Whether posts from this Twitter account should be imported automatically.',
    'context' => '',
    'location' => '',
    'translation' => 'ما إذا كان سيتم استيراده مشاركات من هذا الحساب في تويتر تلقائيا.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Whether posts from this Twitter account should be imported automatically.', array(), array('context' => ''));
  $translations['ar:default']['53cced8d281a1a0ace3cb6594daaa4f7'] = array(
    'source' => 'low',
    'context' => '',
    'location' => '',
    'translation' => 'منخفضة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('low', array(), array('context' => ''));
  $translations['ar:default']['53de38019d82947638e19eede01cbb0c'] = array(
    'source' => 'Hello !recipient_name,

A new user <a href="!url">!name </a>has registered. If you want to accept this registration, please mark this user as "active".',
    'context' => '',
    'location' => '/index.php',
    'translation' => 'مرحباً !recipient_name،

لقد سجل مستخدم جديد باسم "<a href="!url">!name</a>". إذا كت تريد قبول تسجيله يرجى تغيير حالة حسابه إلى  "نشط". 
',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Hello !recipient_name,

A new user <a href="!url">!name </a>has registered. If you want to accept this registration, please mark this user as "active".', array(), array('context' => ''));
  $translations['ar:default']['53e4233bc8d228a29c739d8217a5412a'] = array(
    'source' => 'Please <a href="@login_url">login</a> to be able to add footnotes and contribute to the fact-checking of this report.',
    'context' => '',
    'location' => '/meedan/meedan-checkdesk/drupal/ar/node/886',
    'translation' => 'يرجى <a href="@login_url">تسجيل الدخول</a> لتتمكن من إضافة الملاحظات والمساهمة في التحقق من صحة المعلومات لهذا التقرير',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Please <a href="@login_url">login</a> to be able to add footnotes and contribute to the fact-checking of this report.', array(), array('context' => ''));
  $translations['ar:default']['53eb8dc10383325f4acdf55e8508c9cc'] = array(
    'source' => 'Flagged for fact-checking',
    'context' => '',
    'location' => '/ar/node/flag/confirm/flag/factcheck/14/ajax',
    'translation' => 'تم تنبيه التحقق',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Flagged for fact-checking', array(), array('context' => ''));
  $translations['ar:default']['54088ddd65b9ab4a650de36c2e883946'] = array(
    'source' => 'Search for author',
    'context' => '',
    'location' => '/ar/search',
    'translation' => 'البحث عن مؤلف',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Search for author', array(), array('context' => ''));
  $translations['ar:default']['5452b3f35f985e9728adfaa872992198'] = array(
    'source' => 'Fluid grid',
    'context' => '',
    'location' => '/ar',
    'translation' => 'سيولة الشبكه ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Fluid grid', array(), array('context' => ''));
  $translations['ar:default']['54b491a485803ad8ac1a03cf4fc5cd9b'] = array(
    'source' => 'Pick the appropriate verification status',
    'context' => '',
    'location' => '/ar/node/1993',
    'translation' => 'اختر حالة التحقق المناسبة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Pick the appropriate verification status', array(), array('context' => ''));
  $translations['ar:default']['54f6c88d951b7b791f8fc1253e554d07'] = array(
    'source' => 'Add unrestricted, custom text or markup. This is similar to the custom text field.',
    'context' => '',
    'location' => '',
    'translation' => 'إضافة غير مقيدة، أو نص مخصص العلامات. هذا هو مماثل لحقل النص المخصص.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Add unrestricted, custom text or markup. This is similar to the custom text field.', array(), array('context' => ''));
  $translations['ar:default']['553edaa445c153674ca749a9ffeb5b77'] = array(
    'source' => 'Active Users',
    'context' => '',
    'location' => '/checkdesk/ar/admin/meedan/reports',
    'translation' => 'المستخدمون النشطون',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Active Users', array(), array('context' => ''));
  $translations['ar:default']['55642fb5f45a7ee4218655c0cecf2389'] = array(
    'source' => 'If you need to translate Views labels into other languages, consider installing the <a href="!path">Internationalization</a> package\'s Views translation module.',
    'context' => '',
    'location' => '',
    'translation' => 'If you need to translate Views labels into other languages, consider installing the <a href="!path">Internationalization</a> package\'s Views translation module.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('If you need to translate Views labels into other languages, consider installing the <a href="!path">Internationalization</a> package\'s Views translation module.', array(), array('context' => ''));
  $translations['ar:default']['556f57b539f7ac0892424cafee0c0a2e'] = array(
    'source' => 'The @entity-type of the current relationship rendered using a view mode.',
    'context' => '',
    'location' => '',
    'translation' => 'أصدرت @ كيان من نوع من العلاقة الحالية باستخدام وضع العرض.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The @entity-type of the current relationship rendered using a view mode.', array(), array('context' => ''));
  $translations['ar:default']['55901b62d63361b92266d2c0f24cf59e'] = array(
    'source' => 'The UID of the Twitter account.',
    'context' => '',
    'location' => '',
    'translation' => 'موقع حساب تويتر.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The UID of the Twitter account.', array(), array('context' => ''));
  $translations['ar:default']['55f61235ee00ef017c524c615f09111c'] = array(
    'source' => 'Submit a report to our team',
    'context' => '',
    'location' => '/ar/node/add/media?meedan_bookmarklet=1&meedan_bookmarklet_prepopulate[body]=%D8%A3%D8%AE%D8%A8%D8%A7%D8%B1%20|%20Meedan%20Checkdesk&meedan_bookmarklet_prepopulate[field_link]=http://qa.checkdesk.org/ar',
    'translation' => 'أضف تقريراً لفريق العمل',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Submit a report to our team', array(), array('context' => ''));
  $translations['ar:default']['55fd42f424d5885f56ac0b31fe1db676'] = array(
    'source' => 'Draft updates',
    'context' => '',
    'location' => '/ar/search?type=update&status=0',
    'translation' => 'تحديثات غير منشورة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Draft updates', array(), array('context' => ''));
  $translations['ar:default']['561c656355848140a39601f8de9714ed'] = array(
    'source' => '@view : @display',
    'context' => '',
    'location' => '',
    'translation' => '@view : @display',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('@view : @display', array(), array('context' => ''));
  $translations['ar:default']['56777dcfc058388b2a91b3ba480fbd52'] = array(
    'source' => 'Autorefresh',
    'context' => '',
    'location' => '/ar',
    'translation' => 'تحديث تلقائي',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Autorefresh', array(), array('context' => ''));
  $translations['ar:default']['5688343e16b3e73a17444b3e7895a7c4'] = array(
    'source' => 'Maillog',
    'context' => '',
    'location' => '/ar',
    'translation' => 'Maillog',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Maillog', array(), array('context' => ''));
  $translations['ar:default']['572a593770f2b6f22ab3252e4e9ccad3'] = array(
    'source' => 'The login account of the Twitter user this message is replying to.',
    'context' => '',
    'location' => '',
    'translation' => 'حساب تسجيل الدخول لمستخدم تويتر الذي ترد هذه الرسالة عليه.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The login account of the Twitter user this message is replying to.', array(), array('context' => ''));
  $translations['ar:default']['573ba994c3e5d492d87175614cb0bf17'] = array(
    'source' => 'Upper case',
    'context' => '',
    'location' => '',
    'translation' => 'حروف كبيرة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Upper case', array(), array('context' => ''));
  $translations['ar:default']['573c3cdf38e035ed843fa6b18a815357'] = array(
    'source' => 'The date the user last accessed the site.',
    'context' => '',
    'location' => '',
    'translation' => 'تاريخ اخر دخول للمستخدم للموقع',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The date the user last accessed the site.', array(), array('context' => ''));
  $translations['ar:default']['5762b40feefe848f0307dc6aebdf42c0'] = array(
    'source' => 'Relate content to the user who created it.',
    'context' => '',
    'location' => '',
    'translation' => 'اربط المحتوى بالمستخدم الذي أنشأه.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Relate content to the user who created it.', array(), array('context' => ''));
  $translations['ar:default']['576a6a6c2f89493475786dcf050a318f'] = array(
    'source' => 'Fact-checking',
    'context' => '',
    'location' => '',
    'translation' => 'التحقق من صحة المعلومات',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Fact-checking', array(), array('context' => ''));
  $translations['ar:default']['579906fd6d9e0aa1942f05d509001430'] = array(
    'source' => '<p>A <strong><a href="!report_url">report</a></strong> which you have submitted has been published in an <strong><a href="!update_url">update</a></strong></p>',
    'context' => '',
    'location' => '',
    'translation' => '<p>لقد تم نشر <strong><a href="!report_url">تقريرك</a></strong> في <strong><a href="!update_url">تحديث جديد</a></strong></p>.
',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('<p>A <strong><a href="!report_url">report</a></strong> which you have submitted has been published in an <strong><a href="!update_url">update</a></strong></p>', array(), array('context' => ''));
  $translations['ar:default']['579d90941917d935f5e92a496d75e2f2'] = array(
    'source' => 'A Checkdesk live blog by <a href="@partner_url" target="_blank"><span class="checkdesk-slogan-partner">@partner</span></a>',
    'context' => '',
    'location' => '/',
    'translation' => 'مدونة Checkdesk مباشرة من <a href="@partner_url" target="_blank"><span class="checkdesk-slogan-partner">@partner</span></a> ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('A Checkdesk live blog by <a href="@partner_url" target="_blank"><span class="checkdesk-slogan-partner">@partner</span></a>', array(), array('context' => ''));
  $translations['ar:default']['57c37f0965364db27543f04520990ca6'] = array(
    'source' => 'Most Active Users',
    'context' => '',
    'location' => '/checkdesk/ar/admin/meedan/reports',
    'translation' => 'أكثر المستخدمين نشاطاً',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Most Active Users', array(), array('context' => ''));
  $translations['ar:default']['57f5ece3d05aeae1c56a6fcf524c8016'] = array(
    'source' => '@group (historical data): @field',
    'context' => '',
    'location' => '',
    'translation' => '@group (historical data): @field',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('@group (historical data): @field', array(), array('context' => ''));
  $translations['ar:default']['5811a3a308bfcb02893999ac5934183b'] = array(
    'source' => '!username said: <div class="message">!comment</div>',
    'context' => '',
    'location' => '',
    'translation' => '!username قال: <span class="message">!comment</span>',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('!username said: <div class="message">!comment</div>', array(), array('context' => ''));
  $translations['ar:default']['58386165340f3d9e5278a5c96e28da03'] = array(
    'source' => 'The currently logged in user.',
    'context' => '',
    'location' => '',
    'translation' => 'المستخدم الحالي ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The currently logged in user.', array(), array('context' => ''));
  $translations['ar:default']['5845a388e0d02a2050ec5c8d5721557e'] = array(
    'source' => 'Added by <a class="contributor" href="@user">!user</a> <span class="separator">&#9679;</span> <a href="@url"><time class="date-time" datetime="!timestamp">!interval ago</time></a>',
    'context' => '',
    'location' => '/ar/',
    'translation' => 'أضيف من قبل <a class="contributor" href="@user">!user</a> <span class="separator">&#9679;</span> <a href="@url"><time class="date-time" datetime="!timestamp">منذ !interval </time></a>',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Added by <a class="contributor" href="@user">!user</a> <span class="separator">&#9679;</span> <a href="@url"><time class="date-time" datetime="!timestamp">!interval ago</time></a>', array(), array('context' => ''));
  $translations['ar:default']['584eb6f7d1a4d1adc21871f67671c1e2'] = array(
    'source' => 'The revision\'s universally unique ID.',
    'context' => '',
    'location' => '/ar',
    'translation' => 'المراجعة الفريدة من نوعها عالميا ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The revision\'s universally unique ID.', array(), array('context' => ''));
  $translations['ar:default']['58a0ea95c8240cb7dca6ffff6b024986'] = array(
    'source' => 'Cannot add index %name to table %table: table doesn\'t exist.',
    'context' => '',
    'location' => '',
    'translation' => 'لا يمكن إضافة الفهرس %name للجدول %table : الجدول غير موجود.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Cannot add index %name to table %table: table doesn\'t exist.', array(), array('context' => ''));
  $translations['ar:default']['590cc198b971e4c56d8b3b03743db969'] = array(
    'source' => '@count[4] updates',
    'context' => '',
    'location' => '/ar/search?field_tags_tid=1327',
    'translation' => '@count[4] تحديثات',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('@count[4] updates', array(), array('context' => ''));
  $translations['ar:default']['59cb4ef4643aa67122f558366d2d5eea'] = array(
    'source' => 'The full original string.',
    'context' => '',
    'location' => '',
    'translation' => 'السلسلة الكاملة الأصليه',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The full original string.', array(), array('context' => ''));
  $translations['ar:default']['59cbf571f74daa5c5fcd07a2e7af229d'] = array(
    'source' => 'contextual filters',
    'context' => '',
    'location' => '',
    'translation' => 'contextual filters',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('contextual filters', array(), array('context' => ''));
  $translations['ar:default']['59dd8a082f7dd9734f7508cc8b5abe74'] = array(
    'source' => 'Simple time-based caching of data.',
    'context' => '',
    'location' => '',
    'translation' => 'وقت مستند بسيط لتخزين البيانات ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Simple time-based caching of data.', array(), array('context' => ''));
  $translations['ar:default']['5a4d451e61bf90a18ae5c8e512cc8e89'] = array(
    'source' => 'Hello !recipient_name,

!author has updated the story !story.

<a href="!url">Click here </a> to view or update this story.
',
    'context' => '',
    'location' => '',
    'translation' => 'مرحباً !recipient_name, 

قام !author بتحديث الموضوع !story.

 <a href="!url"> اضغط هنا </a> لمعرفة أو تحديث هذا الموضوع.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Hello !recipient_name,

!author has updated the story !story.

<a href="!url">Click here </a> to view or update this story.
', array(), array('context' => ''));
  $translations['ar:default']['5a598edac7133a65ae8f38fdabe1d8ae'] = array(
    'source' => 'New user',
    'context' => '',
    'location' => '/ar/user/16/notifications',
    'translation' => 'مستخدم جديد',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('New user', array(), array('context' => ''));
  $translations['ar:default']['5a6880987acadc6982361063495aae82'] = array(
    'source' => 'The results of a search using keywords.',
    'context' => '',
    'location' => '',
    'translation' => 'نتائج البحث باستخدام كلمات مفتاحية.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The results of a search using keywords.', array(), array('context' => ''));
  $translations['ar:default']['5a95a425f74314a96f13a2f136992178'] = array(
    'source' => 'Share',
    'context' => '',
    'location' => '',
    'translation' => 'شارك',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Share', array(), array('context' => ''));
  $translations['ar:default']['5b3aa1adbaacecbc861957db6caec50c'] = array(
    'source' => 'Hello !recipient_name,

!actor has changed report "!node_title"  status.

You can edit your notification settings from your <a href="!recipient_url">profile page</a>.

This was an auto-generated email from !site, please do not respond directly to this email.',
    'context' => '',
    'location' => '/index.php',
    'translation' => 'مرحباً !recipient_name،

قام !actor بتغيير حالة هذا التقرير "!node_title" .

بإمكانك تعديل إعدادات التنبيهات الخاصة بك من صفحة <a href="!recipient_url">الحساب الشخصي</a> الخاصة بك.

هذه رسالة مولدة بشكل تلقائي من !site، يرجى عدم الرد على هذه الرسالة.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Hello !recipient_name,

!actor has changed report "!node_title"  status.

You can edit your notification settings from your <a href="!recipient_url">profile page</a>.

This was an auto-generated email from !site, please do not respond directly to this email.', array(), array('context' => ''));
  $translations['ar:default']['5b3ec15499a125805b5bbf8e4afcec8c'] = array(
    'source' => 'Buttons',
    'context' => '',
    'location' => '',
    'translation' => 'أزرار',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Buttons', array(), array('context' => ''));
  $translations['ar:default']['5b48bd04a8325b597a8e5174296aa5c2'] = array(
    'source' => 'To help verify this report, please <a href="@login_url">sign in</a>',
    'context' => '',
    'location' => '/ar',
    'translation' => 'للمساعدة في التحقق من صحة هذا التقرير, يرجى <a href="@login_url">تسجيل الدخول</a>',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('To help verify this report, please <a href="@login_url">sign in</a>', array(), array('context' => ''));
  $translations['ar:default']['5b8a1cc18efbfbb8a83b37fc9a9eb5b8'] = array(
    'source' => 'Message text',
    'context' => '',
    'location' => '',
    'translation' => 'رسالة نصية',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Message text', array(), array('context' => ''));
  $translations['ar:default']['5bb1581957111fc7938efa74d236b8b5'] = array(
    'source' => 'Media sources of the node',
    'context' => '',
    'location' => '/ar',
    'translation' => 'مصادر إعلامية للعقده ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Media sources of the node', array(), array('context' => ''));
  $translations['ar:default']['5bb83dca81a18faf985a56391dec55f1'] = array(
    'source' => '<?php
global $user;
$interval = 5000;
$path = drupal_get_path(\'module\', \'checkdesk_notifications\') . \'/ping.php?user=\' . $user->uid;
print theme(\'views_autorefresh\', array(\'interval\' => $interval, \'use_base_field\' => TRUE, \'incremental\' => FALSE, \'ping\' => array(\'ping_base_path\' =>  $path)));
?>',
    'context' => '',
    'location' => '/ar',
    'translation' => '<?php
global $user;
$interval = 5000;
$path = drupal_get_path(\'module\', \'checkdesk_notifications\') . \'/ping.php?user=\' . $user->uid;
print theme(\'views_autorefresh\', array(\'interval\' => $interval, \'use_base_field\' => TRUE, \'incremental\' => FALSE, \'ping\' => array(\'ping_base_path\' =>  $path)));
?>',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('<?php
global $user;
$interval = 5000;
$path = drupal_get_path(\'module\', \'checkdesk_notifications\') . \'/ping.php?user=\' . $user->uid;
print theme(\'views_autorefresh\', array(\'interval\' => $interval, \'use_base_field\' => TRUE, \'incremental\' => FALSE, \'ping\' => array(\'ping_base_path\' =>  $path)));
?>', array(), array('context' => ''));
  $translations['ar:default']['5bd7326b4cb86a6b0ceefd9ad5668d5d'] = array(
    'source' => 'Alphabetical',
    'context' => 'Sort order',
    'location' => '',
    'translation' => 'أبجدي',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Alphabetical', array(), array('context' => 'Sort order'));
  $translations['ar:default']['5c246b1880f334c71d2596c79884d9eb'] = array(
    'source' => 'Entity Reference Source',
    'context' => '',
    'location' => '',
    'translation' => 'مصدر مرجع الكيان',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Entity Reference Source', array(), array('context' => ''));
  $translations['ar:default']['5c5606c4bc9a6b24c4f6bdf5b1eabf4f'] = array(
    'source' => 'Cannot add primary key to table %table: primary key already exists.',
    'context' => '',
    'location' => '',
    'translation' => 'لا يمكن إضافة المفتاح الرئيسي للجدول %table: هذا المفتاح موجود مسبقاً.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Cannot add primary key to table %table: primary key already exists.', array(), array('context' => ''));
  $translations['ar:default']['5c731164ca57de48677fdc131fc5eece'] = array(
    'source' => 'Node target ID',
    'context' => '',
    'location' => '/ar',
    'translation' => 'العقدة الهدف ID',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Node target ID', array(), array('context' => ''));
  $translations['ar:default']['5c7b91f2f9493dd9e530c32cb1907c84'] = array(
    'source' => 'Fact-checking has been enabled for <a href="[node:url:unaliased]">[node:author]\'s report</a>.',
    'context' => '',
    'location' => '/ar/flag/flag/factcheck_journalist/2447?destination=report-view-modal/ajax/2447&token=KPFawrLou6qfujz-SsQucRW0B_4hr8CIbDcZBfbnrBo',
    'translation' => 'تم تفعيل التحقق من صحة معلومات <a href="[node:url:unaliased]"> تقرير [node:author] </a>.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Fact-checking has been enabled for <a href="[node:url:unaliased]">[node:author]\'s report</a>.', array(), array('context' => ''));
  $translations['ar:default']['5caa90bd0bad9b86a3904caea31ee740'] = array(
    'source' => 'Number of reports submitted by the most active user in any given month.',
    'context' => '',
    'location' => '/checkdesk/ar/admin/meedan/reports',
    'translation' => 'عدد التقارير المرسلة من أكثر المستخدمين نشاطاً في شهر معين',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Number of reports submitted by the most active user in any given month.', array(), array('context' => ''));
  $translations['ar:default']['5caf2c71bce4d608dd2e78ccfb82f859'] = array(
    'source' => 'Display the view as a feed, such as an RSS feed.',
    'context' => '',
    'location' => '',
    'translation' => 'Display the view as a feed, such as an RSS feed.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Display the view as a feed, such as an RSS feed.', array(), array('context' => ''));
  $translations['ar:default']['5cdd6717b7bc1abb0df56fa95c282ac8'] = array(
    'source' => 'M d, Y \\a\\t g:ia',
    'context' => '',
    'location' => '',
    'translation' => '\\ف\\ي M d, Y \\ا\\ل\\س\\ا\\ع\\ة g:i a',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('M d, Y \a\t g:ia', array(), array('context' => ''));
  $translations['ar:default']['5ce82814580c8d18af7c4278af5bbacd'] = array(
    'source' => 'Share on Google+',
    'context' => '',
    'location' => '',
    'translation' => 'شارك على جوجل+',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Share on Google+', array(), array('context' => ''));
  $translations['ar:default']['5cf05ea9f1a7397d6e62a06ecc50676f'] = array(
    'source' => 'The date the content was last updated.',
    'context' => '',
    'location' => '',
    'translation' => 'تاريخ آخر تحديث للمحتوى.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The date the content was last updated.', array(), array('context' => ''));
  $translations['ar:default']['5d7359ba86ccf769406a7cc574be5374'] = array(
    'source' => 'The URL of the link.',
    'context' => '',
    'location' => '/ar',
    'translation' => 'عنوان URL للرابط.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The URL of the link.', array(), array('context' => ''));
  $translations['ar:default']['5dae9c01b5059f60e02f14ab078c7904'] = array(
    'source' => 'Post Date',
    'context' => '',
    'location' => '',
    'translation' => 'تاريخ النشر',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Post Date', array(), array('context' => ''));
  $translations['ar:default']['5dd135d1bcfa7f63c3b7f25425c2a4a1'] = array(
    'source' => 'Score',
    'context' => '',
    'location' => '',
    'translation' => 'نتيجة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Score', array(), array('context' => ''));
  $translations['ar:default']['5dd6fb02f3cb5664273770d932feb5ae'] = array(
    'source' => '<p><strong><a href="!user_url">!username</a></strong> has suggested a <strong><a href="!report_url">report</a></strong> to <strong><a href="!story_url">!story</a></strong></p>',
    'context' => '',
    'location' => '',
    'translation' => '<p><strong><a href="!user_url">!username</a></strong> قد اقترح إضافة <strong><a href="!report_url">تقرير</a></strong> إلى <strong><a href="!story_url">!story</a></strong></p>',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('<p><strong><a href="!user_url">!username</a></strong> has suggested a <strong><a href="!report_url">report</a></strong> to <strong><a href="!story_url">!story</a></strong></p>', array(), array('context' => ''));
  $translations['ar:default']['5e473e5f2715c95941c47c266b8d189e'] = array(
    'source' => 'The unique ID of the node\'s revision.',
    'context' => '',
    'location' => '',
    'translation' => 'المعرف الفريد من مراجعة العقده',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The unique ID of the node\'s revision.', array(), array('context' => ''));
  $translations['ar:default']['5e75d7b2a1e5b3f6af7f98edbbd8d946'] = array(
    'source' => 'This report was unflagged as spam.',
    'context' => '',
    'location' => '/ar/node/flag/confirm/unflag/spam/293/ajax',
    'translation' => 'تم إلغاء تنبيه المشرف على السبام (سخام).',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('This report was unflagged as spam.', array(), array('context' => ''));
  $translations['ar:default']['5ebcc178a048c12be3b2bf0d9c274eb1'] = array(
    'source' => 'Rendered العقد',
    'context' => '',
    'location' => '/ar',
    'translation' => 'المقدمة العقد',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Rendered العقد', array(), array('context' => ''));
  $translations['ar:default']['5ee2f2fcb3d71a961e2a5d80d13d5a55'] = array(
    'source' => 'When you submit a report it becomes available for fact-checking and may be included in a blog post by our team.',
    'context' => '',
    'location' => '/ar/node/add/media?meedan_bookmarklet=1&meedan_bookmarklet_prepopulate[body]=%D8%A3%D8%AE%D8%A8%D8%A7%D8%B1%20|%20Meedan%20Checkdesk&meedan_bookmarklet_prepopulate[field_link]=http://qa.checkdesk.org/ar',
    'translation' => ' بعد إضافة التقرير سوف يُطرح للتحقق من المعلومات و سيتمكن فريق العمل من نشره على المدونة المباشرة.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('When you submit a report it becomes available for fact-checking and may be included in a blog post by our team.', array(), array('context' => ''));
  $translations['ar:default']['5f3c8731a79ed693f8d11e6e450ca6f1'] = array(
    'source' => 'Approved comment',
    'context' => '',
    'location' => '',
    'translation' => 'تعليق موافق عليه',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Approved comment', array(), array('context' => ''));
  $translations['ar:default']['5f5456af761ccf81095f759ed910f996'] = array(
    'source' => 'No file selected...',
    'context' => '',
    'location' => '/ar/user',
    'translation' => 'لم يتم إختيار أي ملف...',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('No file selected...', array(), array('context' => ''));
  $translations['ar:default']['5f8bd95a1e903625d00ac9835128dbf0'] = array(
    'source' => 'Submit report',
    'context' => '',
    'location' => '',
    'translation' => 'تقرير جديد',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Submit report', array(), array('context' => ''));
  $translations['ar:default']['5ff3e7ec03a244eae7345d2d7e7a40aa'] = array(
    'source' => 'Filter criterion',
    'context' => '',
    'location' => '',
    'translation' => 'مرشح المعيار',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Filter criterion', array(), array('context' => ''));
  $translations['ar:default']['6003a462f5d10bb649f5d2160e02da78'] = array(
    'source' => 'The website address of the comment\'s author. Can be rendered as a link. Will be empty if the author is a registered user.',
    'context' => '',
    'location' => '',
    'translation' => 'عنوان الموقع الإلكتروني لكاتب التعليق. كما يمكن عرضه كوصلة. وسوف يكون فارغا إذا كان المؤلف مستخدما مسجلا.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The website address of the comment\'s author. Can be rendered as a link. Will be empty if the author is a registered user.', array(), array('context' => ''));
  $translations['ar:default']['60a06262e83184ccd729b572b1fe2384'] = array(
    'source' => 'A @flag-type has been unflagged, under "@flag-title"',
    'context' => '',
    'location' => '',
    'translation' => 'تم إلغاء تنبيه المشرف على @flag-type، تحت "@flag-title" ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('A @flag-type has been unflagged, under "@flag-title"', array(), array('context' => ''));
  $translations['ar:default']['60efd1a42c6351ef1fc1dc275a984041'] = array(
    'source' => 'A Checkdesk live blog by <span class="checkdesk-slogan-partner">@partner</span>',
    'context' => '',
    'location' => '/',
    'translation' => 'مدونة Checkdesk مباشرة من <span class="checkdesk-slogan-partner">@partner</span>',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('A Checkdesk live blog by <span class="checkdesk-slogan-partner">@partner</span>', array(), array('context' => ''));
  $translations['ar:default']['6136261711c49bf0e8e1dcb22a2c524f'] = array(
    'source' => 'Not Applicable',
    'context' => '',
    'location' => '/ar/views/ajax',
    'translation' => 'لا ينطبق',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Not Applicable', array(), array('context' => ''));
  $translations['ar:default']['61604d2e596c8ca07c63b9b1bbc0ed09'] = array(
    'source' => 'Administrative overlay',
    'context' => '',
    'location' => '',
    'translation' => 'واجهة إدارية',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Administrative overlay', array(), array('context' => ''));
  $translations['ar:default']['6186166618d5122ab1c6609652744aed'] = array(
    'source' => 'Taxonomy terms on node',
    'context' => '',
    'location' => '',
    'translation' => 'شروط التصنيف على العقده ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Taxonomy terms on node', array(), array('context' => ''));
  $translations['ar:default']['61892ebf26f15026b12840651d7cfa90'] = array(
    'source' => 'Flagged for fact-checking.',
    'context' => '',
    'location' => '',
    'translation' => 'تم تنبيه التحقق',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Flagged for fact-checking.', array(), array('context' => ''));
  $translations['ar:default']['619af966133ad2174db8122ecaf6fb48'] = array(
    'source' => 'Complete your profile (add a profile pic!) and edit your settings.',
    'context' => '',
    'location' => 'sites/all/modules/custom/checkdesk_core/js/tour/checkdesk-tour.js; sites/all/modules/custom/checkdesk_core/js/checkdesk_tour.js; sites/all/themes/checkdesk/assets/js/tour.js',
    'translation' => 'أكمل ملفك الشخصي (أضف صورتك!) واضبط إعداداتك كما تريد.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Complete your profile (add a profile pic!) and edit your settings.', array(), array('context' => ''));
  $translations['ar:default']['61a819b4db863f7c03f93ce6006b3e45'] = array(
    'source' => 'Path module form elements',
    'context' => '',
    'location' => '',
    'translation' => 'Path module form elements',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Path module form elements', array(), array('context' => ''));
  $translations['ar:default']['620c0e2624a5a25c2240bea3cf66a418'] = array(
    'source' => 'Published in ',
    'context' => '',
    'location' => '/ar/report/12301',
    'translation' => 'نُشر في ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Published in ', array(), array('context' => ''));
  $translations['ar:default']['621b4a72b1516a94b6b6fae36485acce'] = array(
    'source' => 'Second sidebar',
    'context' => '',
    'location' => '/ar',
    'translation' => '  الشريط الجانبي الثاني',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Second sidebar', array(), array('context' => ''));
  $translations['ar:default']['621ebe2b4a966a675256eb9509f466ba'] = array(
    'source' => '- Choose an operation -',
    'context' => '',
    'location' => '',
    'translation' => '- اختر عملية -',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('- Choose an operation -', array(), array('context' => ''));
  $translations['ar:default']['6222b334ea9a1953eb242bd4b9750400'] = array(
    'source' => 'This field reference another entity.',
    'context' => '',
    'location' => '',
    'translation' => 'هذه الإشارة حقل كيان آخر.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('This field reference another entity.', array(), array('context' => ''));
  $translations['ar:default']['62659c7f7ff53bcdc22ed92b77679cb8'] = array(
    'source' => 'Created week',
    'context' => '',
    'location' => '',
    'translation' => 'أسبوع الانشاء',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Created week', array(), array('context' => ''));
  $translations['ar:default']['63e4e92bb7d207ca577b11c07f827279'] = array(
    'source' => 'Extension',
    'context' => '',
    'location' => '',
    'translation' => 'تمديد',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Extension', array(), array('context' => ''));
  $translations['ar:default']['642c6976e823b1232fcda41c141a007b'] = array(
    'source' => 'The singular activity message',
    'context' => '',
    'location' => '/ar',
    'translation' => 'رسالة النشاط المنفرد',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The singular activity message', array(), array('context' => ''));
  $translations['ar:default']['64384e10d876a1b9a318a7b2206d1ba4'] = array(
    'source' => ' ago',
    'context' => '',
    'location' => '',
    'translation' => 'منذ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t(' ago', array(), array('context' => ''));
  $translations['ar:default']['6469e9b92e49454ba23a13ced1ca03aa'] = array(
    'source' => '<p>A new user called <strong><a href="!url">!name</a></strong> has registered. Please mark him as <em>active</em>, if you want to accept this registration.</p>',
    'context' => '',
    'location' => '/ar/user',
    'translation' => '<p>لقد سجل مستخدم جديد باسم "<a href="!url">!name</a>". إذا كت تريد قبول تسجيله يرجى تغيير حالة حسابه إلى  "نشط".</p>',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('<p>A new user called <strong><a href="!url">!name</a></strong> has registered. Please mark him as <em>active</em>, if you want to accept this registration.</p>', array(), array('context' => ''));
  $translations['ar:default']['649b8abc9366fc00530a3ede5f40b0c9'] = array(
    'source' => 'I\'m offline.',
    'context' => '',
    'location' => '',
    'translation' => 'أنا غير متصل',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('I\'m offline.', array(), array('context' => ''));
  $translations['ar:default']['64d078b1c25bef74be73246bbd8169e6'] = array(
    'source' => 'Hello !recipient_name,

!actor has changed the fact-checking status for a <a href="!url">report</a> you submitted to !rating.',
    'context' => '',
    'location' => '/index.php',
    'translation' => 'مرحباً !recipient_name،

قام !actor بتغيير حالة التحقق من صحة المعلومات <a href="!url">للتقرير</a> الذي أضفته إلى !rating.
',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Hello !recipient_name,

!actor has changed the fact-checking status for a <a href="!url">report</a> you submitted to !rating.', array(), array('context' => ''));
  $translations['ar:default']['64fedb8480bf91b576ebce505642a27b'] = array(
    'source' => 'The Comment ID of the parent comment.',
    'context' => '',
    'location' => '',
    'translation' => 'معرف تعليق من التعليق الأصل.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The Comment ID of the parent comment.', array(), array('context' => ''));
  $translations['ar:default']['653777801f96237326d65205bc9129e3'] = array(
    'source' => 'Select language',
    'context' => '',
    'location' => '',
    'translation' => 'اختر اللغة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Select language', array(), array('context' => ''));
  $translations['ar:default']['65432fe6377d231e4a3b5f95842b1abc'] = array(
    'source' => 'Delta - Appears in: @bundles.',
    'context' => '',
    'location' => '',
    'translation' => 'Delta - Appears in: @bundles.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Delta - Appears in: @bundles.', array(), array('context' => ''));
  $translations['ar:default']['65829faaff5956b12c5b204ee07f7386'] = array(
    'source' => 'Comments of the node',
    'context' => '',
    'location' => '',
    'translation' => 'تعليقات العقدة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Comments of the node', array(), array('context' => ''));
  $translations['ar:default']['65ca1960c302380349ee212d4d07e5c4'] = array(
    'source' => 'Amman',
    'context' => '',
    'location' => '/meedan/meedan-checkdesk/drupal/ar/node/15692',
    'translation' => 'عمان',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Amman', array(), array('context' => ''));
  $translations['ar:default']['65ef0b3b38f54f6e8a3c8eaad2882f5a'] = array(
    'source' => 'Member for @time',
    'context' => '',
    'location' => '/ar/user/4482',
    'translation' => 'مسجل بالموقع منذ @time',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Member for @time', array(), array('context' => ''));
  $translations['ar:default']['662ba34e66dfb016bd7bf2b7c8bde389'] = array(
    'source' => 'Time-based',
    'context' => '',
    'location' => '',
    'translation' => 'وقت مسند ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Time-based', array(), array('context' => ''));
  $translations['ar:default']['6648afb0479dbe97e75b84243cd6a3d4'] = array(
    'source' => '<p>A new user <strong><a href="!url">!name</a></strong> has registered. Please mark him as <em>active</em>, if you want to accept this registration.</p>',
    'context' => '',
    'location' => '/ar/user',
    'translation' => '<p>لقد سجل مستخدم جديد باسم "<a href="!url">!name</a>". إذا كت تريد قبول تسجيله يرجى تغيير حالة حسابه إلى  "نشط".</p>',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('<p>A new user <strong><a href="!url">!name</a></strong> has registered. Please mark him as <em>active</em>, if you want to accept this registration.</p>', array(), array('context' => ''));
  $translations['ar:default']['66cdd7d0c2bc30847880f7c5ded58ccc'] = array(
    'source' => 'Entity id',
    'context' => '',
    'location' => '',
    'translation' => 'معرّف الكيان',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Entity id', array(), array('context' => ''));
  $translations['ar:default']['670b4363765cdc620f5933213858d913'] = array(
    'source' => 'Filter the view to the currently logged in user.',
    'context' => '',
    'location' => '',
    'translation' => 'تصفية طريقة العرض لدخوله حاليا في المستخدم.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Filter the view to the currently logged in user.', array(), array('context' => ''));
  $translations['ar:default']['6719e5c7b417d7e9c39709068a338718'] = array(
    'source' => 'Fact-checking set on a report I added footnote to',
    'context' => '',
    'location' => '/ar',
    'translation' => 'تغيير حالة تقصي صحة المعلومات على تقرير أضفت حاشية له',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Fact-checking set on a report I added footnote to', array(), array('context' => ''));
  $translations['ar:default']['671b1a35cce27dc63b27963546b301ab'] = array(
    'source' => 'Added by <a href="@user">!user</a> <span class="separator">&#9679;</span> <time class="date-time" datetime="!timestamp">!interval ago</time>',
    'context' => '',
    'location' => '/',
    'translation' => 'اضافه <a href="@user">!user</a> <span class="separator">&#9679;</span> <time class="date-time" datetime="!timestamp"> منذ !interval</time>',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Added by <a href="@user">!user</a> <span class="separator">&#9679;</span> <time class="date-time" datetime="!timestamp">!interval ago</time>', array(), array('context' => ''));
  $translations['ar:default']['672d953cdbfdc0fae52aba5d9f702d2a'] = array(
    'source' => 'File Usage',
    'context' => '',
    'location' => '',
    'translation' => 'استخدام الملف ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('File Usage', array(), array('context' => ''));
  $translations['ar:default']['6768cefde500c7b2339404f7c6c2f75c'] = array(
    'source' => 'Locale source',
    'context' => '',
    'location' => '',
    'translation' => 'لغة مصدر',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Locale source', array(), array('context' => ''));
  $translations['ar:default']['676f0ea99b3228f2c4aad928c92063f6'] = array(
    'source' => 'Provide a simple link to delete the content revision.',
    'context' => '',
    'location' => '',
    'translation' => 'تقديم وصلة بسيطة لحذف مراجعة المحتوى.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Provide a simple link to delete the content revision.', array(), array('context' => ''));
  $translations['ar:default']['6777a8b1406959377916485974419445'] = array(
    'source' => 'Add footnote',
    'context' => '',
    'location' => '',
    'translation' => 'أضف ملاحظة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Add footnote', array(), array('context' => ''));
  $translations['ar:default']['6778e332c1f1e52038f0d7b44fdde1ae'] = array(
    'source' => 'Fact-checking status changed',
    'context' => '',
    'location' => '/ar/user/2/notifications',
    'translation' => 'تغيير حالة التحقق من صحة المعلومات',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Fact-checking status changed', array(), array('context' => ''));
  $translations['ar:default']['6799d254cccb162b22f1d053dc048dd3'] = array(
    'source' => 'Provide a simple link to the user.',
    'context' => '',
    'location' => '',
    'translation' => 'ضع وصلة بسيطة إلى المستخدم.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Provide a simple link to the user.', array(), array('context' => ''));
  $translations['ar:default']['67f115c1fddc4ce1aeb1c754001585bc'] = array(
    'source' => 'Reverse',
    'context' => '',
    'location' => '',
    'translation' => 'عكسي',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Reverse', array(), array('context' => ''));
  $translations['ar:default']['682146f9fc27f463cd874d5bd14a618a'] = array(
    'source' => 'Search result',
    'context' => '',
    'location' => '',
    'translation' => 'نتيجة البحث',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Search result', array(), array('context' => ''));
  $translations['ar:default']['68d14b7f276640e6c6b4440bea4155e6'] = array(
    'source' => 'Comments are responses to node content.',
    'context' => '',
    'location' => '',
    'translation' => 'التعليقات هي الردود على محتوى العقدة.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Comments are responses to node content.', array(), array('context' => ''));
  $translations['ar:default']['68f70606a82c054962767b683b9970cb'] = array(
    'source' => 'Hello !recipient_name,

!actor has changed report "!node_title"  status.

<a href="!story_url">Click here</a> to compose a new update to the story using that report.',
    'context' => '',
    'location' => '/index.php',
    'translation' => 'مرحباً !recipient_name،

قام !actor بتغيير حالة هذا التقرير "!node_title" .

<a href="!story_url">اضغط هنا</a> لكتابة تحديث جديد على ذلك الخبر باستخدام ذاك التقرير.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Hello !recipient_name,

!actor has changed report "!node_title"  status.

<a href="!story_url">Click here</a> to compose a new update to the story using that report.', array(), array('context' => ''));
  $translations['ar:default']['68ff7cb937fbac2695ea1e68722970f8'] = array(
    'source' => 'This was an auto-generated email from !site; please do not respond directly to this email.',
    'context' => '',
    'location' => '/index.php',
    'translation' => 'هذه رسالة مولدة بشكل تلقائي من !site، يرجى عدم الرد على هذه الرسالة.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('This was an auto-generated email from !site; please do not respond directly to this email.', array(), array('context' => ''));
  $translations['ar:default']['6927285a86f499a4b94de59bd593770b'] = array(
    'source' => 'Dashboard (sidebar)',
    'context' => '',
    'location' => '/ar',
    'translation' => 'Dashboard (sidebar)',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Dashboard (sidebar)', array(), array('context' => ''));
  $translations['ar:default']['693e14c3c0dd3757d95b4ee5cf0d7bb3'] = array(
    'source' => 'Comment status',
    'context' => '',
    'location' => '',
    'translation' => 'وضع التعليق',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Comment status', array(), array('context' => ''));
  $translations['ar:default']['69652d7a875cc15d21ce2b08eec82d68'] = array(
    'source' => 'Links from',
    'context' => '',
    'location' => '',
    'translation' => 'وصلات من',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Links from', array(), array('context' => ''));
  $translations['ar:default']['6a43b06cfc71e060914b649c9fcd5905'] = array(
    'source' => 'Hello !recipient_name,

!author has added a footnote to the following report "!title":

!body

<a href="!url">Click here</a> to respond or change the status of the report.',
    'context' => '',
    'location' => '/index.php',
    'translation' => 'مرحباً !recipient_name،

لقد قام !author بإضافة معلومات جديدة للتحقق من صحة المعلومات في التقرير التالي "!title":

!body

<a href="!url">اضغط هنا</a> لترد أو تغير حالة التقرير.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Hello !recipient_name,

!author has added a footnote to the following report "!title":

!body

<a href="!url">Click here</a> to respond or change the status of the report.', array(), array('context' => ''));
  $translations['ar:default']['6a63be43cf34e6896278862b6064d866'] = array(
    'source' => 'Appears in: @bundles.',
    'context' => '',
    'location' => '',
    'translation' => 'يظهر في: @bundles.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Appears in: @bundles.', array(), array('context' => ''));
  $translations['ar:default']['6a8c1892cf9488435c6f8344b35689c6'] = array(
    'source' => 'The parent comment.',
    'context' => '',
    'location' => '',
    'translation' => 'اصل التعليق',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The parent comment.', array(), array('context' => ''));
  $translations['ar:default']['6ac2c69b148a083bb0af8736e08bca09'] = array(
    'source' => 'Queue \'Featured Stories\'',
    'context' => '',
    'location' => '/',
    'translation' => 'قائمة المواضيع المختارة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Queue \'Featured Stories\'', array(), array('context' => ''));
  $translations['ar:default']['6b336a64d562a29dbb027124bdcd20d3'] = array(
    'source' => 'You have related a Twitter account with your user. Next time you can sign in with Twitter.',
    'context' => '',
    'location' => '/ar/user/login?destination=liveblog',
    'translation' => 'لفد ربطت حساب تويتر مع حسابك على الموقع. يمكنك تسجيل الدخول في المرة القادمة باستخدام حساب تويتر خاصتك.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('You have related a Twitter account with your user. Next time you can sign in with Twitter.', array(), array('context' => ''));
  $translations['ar:default']['6b49035518f9ce1e4c4510776c450564'] = array(
    'source' => 'too short',
    'context' => '',
    'location' => '/ar/user/register',
    'translation' => 'قصيرة جداً',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('too short', array(), array('context' => ''));
  $translations['ar:default']['6b86db7e25193e054877b6d3c2f05f29'] = array(
    'source' => 'The time a piece of content was most recently flagged by any user.',
    'context' => '',
    'location' => '',
    'translation' => 'وقت آخر تحذير للمشرف حول المحتوى من قبل أي مستخدم.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The time a piece of content was most recently flagged by any user.', array(), array('context' => ''));
  $translations['ar:default']['6b9975372751315e96edf323efc52d2e'] = array(
    'source' => 'View: !view: !display',
    'context' => '',
    'location' => '',
    'translation' => 'عرض: !view: !display',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('View: !view: !display', array(), array('context' => ''));
  $translations['ar:default']['6ba2874a03562cd6be5a6ea0de729fda'] = array(
    'source' => 'New Status',
    'context' => '',
    'location' => 'sites/all/themes/checkdesk/assets/js/report.js',
    'translation' => 'حالة جديدة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('New Status', array(), array('context' => ''));
  $translations['ar:default']['6bb24396d8e3d9690c8c2668b58432ba'] = array(
    'source' => 'Displays the actual position of the view result',
    'context' => '',
    'location' => '',
    'translation' => 'يعرض الموقف الفعلي لنتيجة الراي ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Displays the actual position of the view result', array(), array('context' => ''));
  $translations['ar:default']['6bb32db99101b079974ebba7ae4013fd'] = array(
    'source' => 'The subject of the comment.',
    'context' => '',
    'location' => '',
    'translation' => 'موضوع التعليق.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The subject of the comment.', array(), array('context' => ''));
  $translations['ar:default']['6bf2b66c6c68f5e36d9134eacb6aa378'] = array(
    'source' => 'The image used by the Twitter account.',
    'context' => '',
    'location' => '',
    'translation' => 'الصورة المستخدمة من حساب تويتر.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The image used by the Twitter account.', array(), array('context' => ''));
  $translations['ar:default']['6c186cdebc80c5846611029eda9865f5'] = array(
    'source' => 'The parent terms of the taxonomy term.',
    'context' => '',
    'location' => '',
    'translation' => 'شروط الأم لمدة التصنيف.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The parent terms of the taxonomy term.', array(), array('context' => ''));
  $translations['ar:default']['6c2255ea2a234ddab9eb64ac729cbeb6'] = array(
    'source' => 'Unfiltered text',
    'context' => '',
    'location' => '',
    'translation' => 'نص غير مصنف ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Unfiltered text', array(), array('context' => ''));
  $translations['ar:default']['6c311e9e2c9d2390316fdc4c7066c8d7'] = array(
    'source' => 'Reply-to link',
    'context' => '',
    'location' => '',
    'translation' => 'رابط الرد',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Reply-to link', array(), array('context' => ''));
  $translations['ar:default']['6c9a23eaeb00919052b742ea29cff589'] = array(
    'source' => 'Verification status',
    'context' => '',
    'location' => '/ar/search?field_tags_tid=1327',
    'translation' => ' حالة التحقق',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Verification status', array(), array('context' => ''));
  $translations['ar:default']['6cae2b6a5e5ec78a6658b7fb92a59af2'] = array(
    'source' => 'Organic groups',
    'context' => '',
    'location' => '',
    'translation' => 'مجموعات',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Organic groups', array(), array('context' => ''));
  $translations['ar:default']['6d0a578ca2f2c0e792fc923002fccbe3'] = array(
    'source' => 'ago',
    'context' => '',
    'location' => '',
    'translation' => 'منذ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('ago', array(), array('context' => ''));
  $translations['ar:default']['6d405cbc3a5502f24398d75313cd732c'] = array(
    'source' => 'Transform spaces to dashes in URL',
    'context' => '',
    'location' => '',
    'translation' => 'تغيير المسافات إلى عوارض في المسارات URL',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Transform spaces to dashes in URL', array(), array('context' => ''));
  $translations['ar:default']['6dbd5bece4cf4281ca73d5e8e43f0262'] = array(
    'source' => 'This is an alias of @group: @field.',
    'context' => '',
    'location' => '',
    'translation' => 'This is an alias of @group: @field.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('This is an alias of @group: @field.', array(), array('context' => ''));
  $translations['ar:default']['6dc6588082dc88833401181950b1775a'] = array(
    'source' => 'العنوان',
    'context' => '',
    'location' => '/ar',
    'translation' => 'العنوان',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('العنوان', array(), array('context' => ''));
  $translations['ar:default']['6de2027c264cd01ac26487c58994d039'] = array(
    'source' => 'Whether posts from this Twitter account should be visible to the general public.',
    'context' => '',
    'location' => '',
    'translation' => 'ما إذا كان ينبغي مشاركات من هذا الحساب تويتر تكون مرئية للجمهور العام.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Whether posts from this Twitter account should be visible to the general public.', array(), array('context' => ''));
  $translations['ar:default']['6dfc5893928cd474ad430776909691fb'] = array(
    'source' => 'Display the last comment of a node',
    'context' => '',
    'location' => '',
    'translation' => 'عرض التعليق الأخير من عقدة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Display the last comment of a node', array(), array('context' => ''));
  $translations['ar:default']['6e3afc6db5b86d790de679dd64f46129'] = array(
    'source' => 'Content authored',
    'context' => '',
    'location' => '',
    'translation' => 'تأليف المحتوى',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Content authored', array(), array('context' => ''));
  $translations['ar:default']['6e8dbf791eda0e86fbe0ef2279c6b0f8'] = array(
    'source' => 'OEmbed',
    'context' => '',
    'location' => '/ar',
    'translation' => 'OEmbed',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('OEmbed', array(), array('context' => ''));
  $translations['ar:default']['6ea8be7df43297d7ad0bb6543a985b09'] = array(
    'source' => 'Provide a simple link to approve the comment.',
    'context' => '',
    'location' => '',
    'translation' => 'ضع رابط بسيط للموافقة على تعليق.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Provide a simple link to approve the comment.', array(), array('context' => ''));
  $translations['ar:default']['6eae9890a67464b8b23390c936587f20'] = array(
    'source' => 'The number of users following this Twitter account.',
    'context' => '',
    'location' => '',
    'translation' => 'عدد مستخدمي تويتر الذين يتابعون هذا الحساب.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The number of users following this Twitter account.', array(), array('context' => ''));
  $translations['ar:default']['6ede21148df5693c70cdf8ff066fe658'] = array(
    'source' => 'Load more stories',
    'context' => '',
    'location' => '',
    'translation' => 'تحميل المزيد',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Load more stories', array(), array('context' => ''));
  $translations['ar:default']['6f22594d7c46d9c944320df281ef9769'] = array(
    'source' => 'Twitter @username converter',
    'context' => '',
    'location' => '',
    'translation' => 'محول @username الخاص بتويتر',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Twitter @username converter', array(), array('context' => ''));
  $translations['ar:default']['6f50ede78277226f2743d806b03106dc'] = array(
    'source' => '@count[2] collaborators',
    'context' => '',
    'location' => '/ar/story-collaboration/13',
    'translation' => 'مشاركان',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('@count[2] collaborators', array(), array('context' => ''));
  $translations['ar:default']['6f8063417ab31f38d864c28302f3de2f'] = array(
    'source' => 'Approved',
    'context' => '',
    'location' => '',
    'translation' => 'موافق عليه',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Approved', array(), array('context' => ''));
  $translations['ar:default']['6fa791bce0cecdffe5a61be38f69b257'] = array(
    'source' => 'Display the id of the referenced entities.',
    'context' => '',
    'location' => '',
    'translation' => 'عرض معرف الكيانات المشار إليه.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Display the id of the referenced entities.', array(), array('context' => ''));
  $translations['ar:default']['6fc6e16959f4d57088d33d70c6fe06e9'] = array(
    'source' => 'Select all !row_count in this view.',
    'context' => '',
    'location' => '',
    'translation' => 'اختر كل الـ !row_count في هذا العرض',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Select all !row_count in this view.', array(), array('context' => ''));
  $translations['ar:default']['6feee9b34d6453a7a5ebd77174736455'] = array(
    'source' => 'wrong answer',
    'context' => '',
    'location' => '/ar/user/register',
    'translation' => 'إجابة خاطئة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('wrong answer', array(), array('context' => ''));
  $translations['ar:default']['70034e7ee92ca1531bdae9be59b1f3c4'] = array(
    'source' => 'Meedan oEmbed',
    'context' => '',
    'location' => '/ar',
    'translation' => 'ميدان oEmbed',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Meedan oEmbed', array(), array('context' => ''));
  $translations['ar:default']['703557f86db513d50f9e29e4621d06d0'] = array(
    'source' => 'Updated month',
    'context' => '',
    'location' => '',
    'translation' => 'تم تحديث الشهر',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Updated month', array(), array('context' => ''));
  $translations['ar:default']['70364a3d2257b5ef588c0c2c16ac5b80'] = array(
    'source' => 'The extension of the file.',
    'context' => '',
    'location' => '',
    'translation' => 'تمديد الملف.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The extension of the file.', array(), array('context' => ''));
  $translations['ar:default']['7060e0481896e00b3f7d20f1e8e2749a'] = array(
    'source' => 'unavailable',
    'context' => '',
    'location' => 'sites/all/modules/custom/checkdesk_core/js/checkdesk_core.js',
    'translation' => 'غير متوفر',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('unavailable', array(), array('context' => ''));
  $translations['ar:default']['70814608904418b313b0a36759ecf2de'] = array(
    'source' => 'Hide view',
    'context' => '',
    'location' => '',
    'translation' => 'إخفاء الرؤية',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Hide view', array(), array('context' => ''));
  $translations['ar:default']['709468af25e91284821d1bdbfdded24c'] = array(
    'source' => 'Everything',
    'context' => '',
    'location' => '/ar/search?field_tags_tid=1327',
    'translation' => 'كل المحتوى',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Everything', array(), array('context' => ''));
  $translations['ar:default']['70d6db966e020e3bf716aca27a7e8996'] = array(
    'source' => 'The ID of the parent translation.',
    'context' => '',
    'location' => '',
    'translation' => 'معرف الترجمة الأصل.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The ID of the parent translation.', array(), array('context' => ''));
  $translations['ar:default']['70e6b52c9c8f526ed52da17bc5d8db39'] = array(
    'source' => 'Add a block here.',
    'context' => '',
    'location' => '',
    'translation' => 'إضافة  حقل هنا.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Add a block here.', array(), array('context' => ''));
  $translations['ar:default']['714ac0f08dacad0d55d804e28888769e'] = array(
    'source' => '@entity_label flag',
    'context' => '',
    'location' => '',
    'translation' => '@entity_label flag',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('@entity_label flag', array(), array('context' => ''));
  $translations['ar:default']['715ba75a01d791d33350d6e0f9982ef7'] = array(
    'source' => 'Translation source node',
    'context' => '',
    'location' => '',
    'translation' => 'ترجمة مصدر العقدة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Translation source node', array(), array('context' => ''));
  $translations['ar:default']['715cbe04ef1c0b3cba20a8536d210262'] = array(
    'source' => 'Display the message of the activity view.',
    'context' => '',
    'location' => '/ar',
    'translation' => 'عرض رسالة نشاط العرض',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Display the message of the activity view.', array(), array('context' => ''));
  $translations['ar:default']['71aa9c0f6976229acca55c971f1d9404'] = array(
    'source' => 'User\'s flaggings',
    'context' => '',
    'location' => '',
    'translation' => 'تاشيرات المستخدم ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('User\'s flaggings', array(), array('context' => ''));
  $translations['ar:default']['71b024bf94fdf30de0b560cd1b6abca5'] = array(
    'source' => 'Change report status on a story I followed',
    'context' => '',
    'location' => '/ar/node/add/discussion',
    'translation' => 'تم تعديل حالة تقرير لموضوع متابع',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Change report status on a story I followed', array(), array('context' => ''));
  $translations['ar:default']['71c38a4f1c7a08ffcf93504ff5da004b'] = array(
    'source' => 'The score of the search item. This will not be used if the search filter is not also present.',
    'context' => '',
    'location' => '',
    'translation' => 'النتيجة في البند البحث. لن يتم استخدام هذا إذا تصفية البحث ليست موجودة أيضا.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The score of the search item. This will not be used if the search filter is not also present.', array(), array('context' => ''));
  $translations['ar:default']['722ad2d05ecf4868b00c5484b82fd808'] = array(
    'source' => 'Queue',
    'context' => '',
    'location' => '',
    'translation' => 'القائمة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Queue', array(), array('context' => ''));
  $translations['ar:default']['72479edc47496f5961ee85cc2af6d19e'] = array(
    'source' => 'Administer Users',
    'context' => '',
    'location' => '',
    'translation' => 'إدارة المستخدمين',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Administer Users', array(), array('context' => ''));
  $translations['ar:default']['727bb439a93de85ab5474e725e080b62'] = array(
    'source' => 'Sort criteria',
    'context' => '',
    'location' => '',
    'translation' => 'نوع المعيار',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Sort criteria', array(), array('context' => ''));
  $translations['ar:default']['72832f8aec446ec011f705b2a41e7458'] = array(
    'source' => 'The user authoring the content. If you need more fields than the uid add the content: author relationship',
    'context' => '',
    'location' => '',
    'translation' => 'The user authoring the content. If you need more fields than the uid add the content: author relationship',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The user authoring the content. If you need more fields than the uid add the content: author relationship', array(), array('context' => ''));
  $translations['ar:default']['72c76294cdbbaae7faf530d5bf8fd4dd'] = array(
    'source' => 'Exclude from display',
    'context' => '',
    'location' => '',
    'translation' => 'إقصاء من العرض',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Exclude from display', array(), array('context' => ''));
  $translations['ar:default']['72ce768bf2d60163542ed4bc3bbd1c9d'] = array(
    'source' => 'If you want to submit a Facebook link, you need to <a href="@url" onclick="!onclick" target="_blank">connect to your Facebook account first</a>.',
    'context' => '',
    'location' => '/ar/node/add/media?meedan_bookmarklet=1&meedan_bookmarklet_prepopulate[body]=Noha%20Journ%20|%20Meedan%20Checkdesk&meedan_bookmarklet_prepopulate[field_link]=http://qa.checkdesk.org/ar/users/noha-journ',
    'translation' => 'إن كنت تريد إضافة رابط من فيس بوك، عليك <a href="@url" target="_blank">ربط حسابك على فيس بوك أولاً</a>.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('If you want to submit a Facebook link, you need to <a href="@url" onclick="!onclick" target="_blank">connect to your Facebook account first</a>.', array(), array('context' => ''));
  $translations['ar:default']['72d68acd07c783e657e2d2a9c50f16df'] = array(
    'source' => 'Flagged',
    'context' => '',
    'location' => '',
    'translation' => 'تم تحذير المشرف',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Flagged', array(), array('context' => ''));
  $translations['ar:default']['7316812cdfd44c01c31a59d52c8a353b'] = array(
    'source' => '@type is flagged',
    'context' => '',
    'location' => '',
    'translation' => 'تم تنبيه المشرف على @type',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('@type is flagged', array(), array('context' => ''));
  $translations['ar:default']['73207364a9aa954bcee69586521d3c44'] = array(
    'source' => 'The taxonomy term name.',
    'context' => '',
    'location' => '',
    'translation' => 'اسم تصنيف الأجل.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The taxonomy term name.', array(), array('context' => ''));
  $translations['ar:default']['73d46138362a59b3d793263ceed4ae14'] = array(
    'source' => 'Content that is associated with this file, usually because this file is in a field on the content.',
    'context' => '',
    'location' => '',
    'translation' => 'المحتوى الذي يرتبط مع هذا الملف، لأن هذا الملف عادة في حقل المحتوى.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Content that is associated with this file, usually because this file is in a field on the content.', array(), array('context' => ''));
  $translations['ar:default']['73ef9f98106997f0c3778af2d7a6950a'] = array(
    'source' => 'Follow us on:',
    'context' => '',
    'location' => '',
    'translation' => 'تابعنا على:',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Follow us on:', array(), array('context' => ''));
  $translations['ar:default']['7427fa24e05cc44d3b71636a72e4626c'] = array(
    'source' => 'Add comment link',
    'context' => '',
    'location' => '',
    'translation' => 'إضافة رابط التعليق',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Add comment link', array(), array('context' => ''));
  $translations['ar:default']['74893d149ba7016b529ef06480bb3756'] = array(
    'source' => 'A file that is associated with this taxonomy term, usually because it is in a field on the taxonomy term.',
    'context' => '',
    'location' => '',
    'translation' => 'ملف مقترن بمصطلح التصنيف، لأنها عادة ما تكون في حقل على مصطلح  التصنيف.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('A file that is associated with this taxonomy term, usually because it is in a field on the taxonomy term.', array(), array('context' => ''));
  $translations['ar:default']['74a123e8b1e69b74268be68db119746d'] = array(
    'source' => 'Number of different sources',
    'context' => '',
    'location' => '/checkdesk/ar/admin/meedan/reports',
    'translation' => 'عدد المصادر المختلفة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Number of different sources', array(), array('context' => ''));
  $translations['ar:default']['74c70868f6fc4b73184d322ddfceb152'] = array(
    'source' => 'Capitalize each word',
    'context' => '',
    'location' => '',
    'translation' => 'تكبير كل كلمة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Capitalize each word', array(), array('context' => ''));
  $translations['ar:default']['752f27a027dac7d25574b59f180f833a'] = array(
    'source' => 'The name of the item; e.g. node.',
    'context' => '',
    'location' => '',
    'translation' => 'اسم البند؛ عقدة على سبيل المثال.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The name of the item; e.g. node.', array(), array('context' => ''));
  $translations['ar:default']['7557c89a2fd156ac65d4908ecd6b6e21'] = array(
    'source' => 'All related updates will be deleted. Are you sure you want to proceed?',
    'context' => '',
    'location' => '/ar/node/844/delete?destination=node/844',
    'translation' => 'سيتم حذف جميع التحديثات المرتبطة! هل أنت متأكد من أنك تريد الحذف؟ ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('All related updates will be deleted. Are you sure you want to proceed?', array(), array('context' => ''));
  $translations['ar:default']['755f85c2723bb39381c7379a604160d8'] = array(
    'source' => 'good',
    'context' => '',
    'location' => 'sites/all/modules/custom/checkdesk_core/js/checkdesk_core.js',
    'translation' => 'جيد',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('good', array(), array('context' => ''));
  $translations['ar:default']['756779262bd438b1cc519bda1523dde0'] = array(
    'source' => 'The user\'s last login date.',
    'context' => '',
    'location' => '',
    'translation' => ' تاريخ آخر دخول للمستخدم ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The user\'s last login date.', array(), array('context' => ''));
  $translations['ar:default']['7577dca3122fc58a66e2f66cd51c30ea'] = array(
    'source' => 'Node target ID used in the activity message',
    'context' => '',
    'location' => '/ar',
    'translation' => 'هوية العقدة الهدف  المستخدمة في نشاط',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Node target ID used in the activity message', array(), array('context' => ''));
  $translations['ar:default']['758cf77cef9014e9b6b4e110bf448a64'] = array(
    'source' => 'Last comment CID',
    'context' => '',
    'location' => '',
    'translation' => 'اخر تعليق CID',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Last comment CID', array(), array('context' => ''));
  $translations['ar:default']['75a03a1bc54f450015368f021c1d9e25'] = array(
    'source' => 'Puts all of the results into a select box and allows the user to go to a different page based upon the results.',
    'context' => '',
    'location' => '',
    'translation' => 'Puts all of the results into a select box and allows the user to go to a different page based upon the results.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Puts all of the results into a select box and allows the user to go to a different page based upon the results.', array(), array('context' => ''));
  $translations['ar:default']['75fef99c1c25f947292fcc5aeb733ef0'] = array(
    'source' => 'Heartbeat Activity Stream to alter the query',
    'context' => '',
    'location' => '/ar',
    'translation' => 'Heartbeat Activity Stream to alter the query',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Heartbeat Activity Stream to alter the query', array(), array('context' => ''));
  $translations['ar:default']['76761bf4bd769b01af2bc9fe48b62681'] = array(
    'source' => '@entity entity referenced from !field_name',
    'context' => '',
    'location' => '',
    'translation' => '@entity entity referenced from !field_name',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('@entity entity referenced from !field_name', array(), array('context' => ''));
  $translations['ar:default']['768659acf473fc220c4c80b85a772187'] = array(
    'source' => 'Now let\'s <a href="!fact_check_url" !attributes>fact-check it</a> and <a href="!blog_url" !attributes>blog about it</a>.',
    'context' => '',
    'location' => '/ar/meedan_bookmarklet/message?meedan_bookmarklet=1&meedan_bookmarklet_submitted=1&meedan_bookmarklet_nid=15631&meedan_bookmarklet_url=http%3A//www.youtube.com/watch',
    'translation' => 'TODO',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Now let\'s <a href="!fact_check_url" !attributes>fact-check it</a> and <a href="!blog_url" !attributes>blog about it</a>.', array(), array('context' => ''));
  $translations['ar:default']['76cb169d83a9992c65c18ebadbbb9af0'] = array(
    'source' => 'Allow a contextual filter value to be ignored. The query will not be altered by this contextual filter value. Can be used when contextual filter values come from the URL, and a part of the URL needs to be ignored.',
    'context' => '',
    'location' => '',
    'translation' => 'السماح لقيمة التصفية لالسياقية يمكن تجاهلها. لن يتم تغيير الاستعلام من حيث القيمة هذا المرشح السياقية. يمكن استخدامها عند تصفية القيم السياقية تأتي من URL، وجزء من URL يجب تجاهلها.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Allow a contextual filter value to be ignored. The query will not be altered by this contextual filter value. Can be used when contextual filter values come from the URL, and a part of the URL needs to be ignored.', array(), array('context' => ''));
  $translations['ar:default']['76d1048c452cefa5c6fe82d7edc0a7e0'] = array(
    'source' => 'Edit link',
    'context' => '',
    'location' => '',
    'translation' => 'رابط  التحرير',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Edit link', array(), array('context' => ''));
  $translations['ar:default']['76e2af349a5662fb6b6950866c0994d0'] = array(
    'source' => '- Use default -',
    'context' => '',
    'location' => '',
    'translation' => '- استخدام الافتراضي -',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('- Use default -', array(), array('context' => ''));
  $translations['ar:default']['770de6de43a08d0ff184fc3803480d93'] = array(
    'source' => 'The URL given by the Twitter account user.',
    'context' => '',
    'location' => '',
    'translation' => ' URL من قبل المستخدم  في حساب تويتر.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The URL given by the Twitter account user.', array(), array('context' => ''));
  $translations['ar:default']['771cf8713d7235475b2eb87f35503994'] = array(
    'source' => 'Twitter status message ID',
    'context' => '',
    'location' => '/ar',
    'translation' => 'وضع هوية رسالة المغرد',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Twitter status message ID', array(), array('context' => ''));
  $translations['ar:default']['773c80d6eb7d09c28d7c8223cb305c55'] = array(
    'source' => 'View original',
    'context' => '',
    'location' => '/',
    'translation' => 'عرض الأصل',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('View original', array(), array('context' => ''));
  $translations['ar:default']['774fef33e3357957d36a6fc1d2be18ab'] = array(
    'source' => 'The path of the file.',
    'context' => '',
    'location' => '',
    'translation' => 'مسار الملف.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The path of the file.', array(), array('context' => ''));
  $translations['ar:default']['7794377a7085fa6560238aaa4389abfd'] = array(
    'source' => 'Load More Pager',
    'context' => '',
    'location' => '/ar',
    'translation' => 'تحميل المزيد من الصفحة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Load More Pager', array(), array('context' => ''));
  $translations['ar:default']['78156455c083c9cf3a0d199373dcd76e'] = array(
    'source' => 'Buttons associated with activity messages',
    'context' => '',
    'location' => '/ar',
    'translation' => 'الأزراير المرتبطة بالنصوص النشطه',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Buttons associated with activity messages', array(), array('context' => ''));
  $translations['ar:default']['782a07bb30b6ee7ac9fa8631e5b13d37'] = array(
    'source' => '(Has one or more drafted updates)',
    'context' => '',
    'location' => '',
    'translation' => '(يحتوي على مسودة واحدة أو أكثر)',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('(Has one or more drafted updates)', array(), array('context' => ''));
  $translations['ar:default']['783629eac11c29aba252459a8be71bbd'] = array(
    'source' => '(forgot?)',
    'context' => '',
    'location' => '/ar/user',
    'translation' => '(نسيت كلمة السر؟)',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('(forgot?)', array(), array('context' => ''));
  $translations['ar:default']['7901a0bd3fbd1f9cc16572783dc29ba0'] = array(
    'source' => 'Compose Update',
    'context' => '',
    'location' => '/ar/node/add/post',
    'translation' => 'اكتب تحديث',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Compose Update', array(), array('context' => ''));
  $translations['ar:default']['790578ed750fea27c87083c20aa4ba9d'] = array(
    'source' => 'Location of comment submission form',
    'context' => '',
    'location' => '',
    'translation' => 'موضع استمارة التعليق',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Location of comment submission form', array(), array('context' => ''));
  $translations['ar:default']['79368fc57de2ab81970580eb42efc2bf'] = array(
    'source' => 'Heartbeat activity avatar element',
    'context' => '',
    'location' => '/ar',
    'translation' => 'Heartbeat activity avatar element',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Heartbeat activity avatar element', array(), array('context' => ''));
  $translations['ar:default']['794c76ab6adcd94c7e215f11e764f4d1'] = array(
    'source' => 'Boolean indicating whether or not this item is enabled.',
    'context' => '',
    'location' => '',
    'translation' => 'Boolean indicating whether or not this item is enabled.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Boolean indicating whether or not this item is enabled.', array(), array('context' => ''));
  $translations['ar:default']['7992dc88dfd9c51da61a604222701008'] = array(
    'source' => 'Display nodes only if a user posted the node or commented on the node.',
    'context' => '',
    'location' => '',
    'translation' => 'عرض العقد  فقط  إذا المستخدم نشر  العقده أو علق عليها ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Display nodes only if a user posted the node or commented on the node.', array(), array('context' => ''));
  $translations['ar:default']['79a56a34c4bd2d4bd74b22d305a827d5'] = array(
    'source' => 'View area',
    'context' => '',
    'location' => '',
    'translation' => 'عرض المنطقة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('View area', array(), array('context' => ''));
  $translations['ar:default']['7a2fc6a931906d2c180c647b73a2d310'] = array(
    'source' => 'The user\'s last access date.',
    'context' => '',
    'location' => '',
    'translation' => 'تاريخ اخر وصول للمستخدم ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The user\'s last access date.', array(), array('context' => ''));
  $translations['ar:default']['7a52e36bf4a1caa031c75a742fb9927a'] = array(
    'source' => 'Powered by',
    'context' => '',
    'location' => '/index.php',
    'translation' => 'مشغل بواسطة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Powered by', array(), array('context' => ''));
  $translations['ar:default']['7a803f79addebadbebc457f24f6de1b2'] = array(
    'source' => 'View all @total footnotes',
    'context' => '',
    'location' => '',
    'translation' => 'عرض جميع الملاحظات',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('View all @total footnotes', array(), array('context' => ''));
  $translations['ar:default']['7aefaa0e44a5357451f661648f216eeb'] = array(
    'source' => 'Change report status',
    'context' => '',
    'location' => '/index.php',
    'translation' => 'تم تعديل حالة التقرير',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Change report status', array(), array('context' => ''));
  $translations['ar:default']['7afd7aba8803ac172a1862b6b37e1c3b'] = array(
    'source' => 'Selected <strong>!row_count</strong> in this page.',
    'context' => '',
    'location' => '',
    'translation' => 'تم اختيار <strong>!row_count</strong> في هذه الصفحة.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Selected <strong>!row_count</strong> in this page.', array(), array('context' => ''));
  $translations['ar:default']['7b4634378941aa906d76815b07995b6d'] = array(
    'source' => 'The User ID of the author of the last comment of a node.',
    'context' => '',
    'location' => '',
    'translation' => 'هوية المستخدم صاحب التعليق الأخير من عقدة.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The User ID of the author of the last comment of a node.', array(), array('context' => ''));
  $translations['ar:default']['7b47abc73113e9c2a1ac5239c7d4af7d'] = array(
    'source' => 'Don\'t have an account? ',
    'context' => '',
    'location' => '/ar/user/login',
    'translation' => 'ليس لديك حساب؟',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Don\'t have an account? ', array(), array('context' => ''));
  $translations['ar:default']['7b7bb0eb1c8e4160eba1c49fb815a719'] = array(
    'source' => 'User module timezone form element.',
    'context' => '',
    'location' => '',
    'translation' => 'User module timezone form element.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('User module timezone form element.', array(), array('context' => ''));
  $translations['ar:default']['7be3573887a3f2e57b20a4f7631807b7'] = array(
    'source' => '@label:!column',
    'context' => '',
    'location' => '',
    'translation' => '@label:!column',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('@label:!column', array(), array('context' => ''));
  $translations['ar:default']['7c22279a45bab9651eebc6630c312105'] = array(
    'source' => 'Unflag spam',
    'context' => '',
    'location' => '/ar/admin/content',
    'translation' => 'إلغاء تنبيه السخام (سبام)',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Unflag spam', array(), array('context' => ''));
  $translations['ar:default']['7c7b946c84548fd276db868bfc879b84'] = array(
    'source' => 'Whether the node is published or unpublished.',
    'context' => '',
    'location' => '',
    'translation' => 'إذا ما كانت  العقده منشورة أو غير منشورة ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Whether the node is published or unpublished.', array(), array('context' => ''));
  $translations['ar:default']['7c9481230b37c69d35aaec5a13f5e230'] = array(
    'source' => '@group: @field',
    'context' => '',
    'location' => '',
    'translation' => '@group: @field',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('@group: @field', array(), array('context' => ''));
  $translations['ar:default']['7c974872c2c935b0609a863f553352e2'] = array(
    'source' => 'Select only !row_count in this page.',
    'context' => '',
    'location' => '',
    'translation' => 'اختر فقط السطور على هذه الصفحة ( !row_count )',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Select only !row_count in this page.', array(), array('context' => ''));
  $translations['ar:default']['7cae5d0bc46adffc66831eaf472b7d6a'] = array(
    'source' => 'My Notifications',
    'context' => '',
    'location' => '/ar',
    'translation' => 'تنبيهاتي ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('My Notifications', array(), array('context' => ''));
  $translations['ar:default']['7ccf75fa7498152efe4e152833455c67'] = array(
    'source' => 'Login name',
    'context' => '',
    'location' => '',
    'translation' => 'اسم الدخول',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Login name', array(), array('context' => ''));
  $translations['ar:default']['7cd0e8b6b4a3d90b08aa81fa21843fa0'] = array(
    'source' => 'Twitter message',
    'context' => '',
    'location' => '',
    'translation' => 'رسالة تويتر',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Twitter message', array(), array('context' => ''));
  $translations['ar:default']['7d05651964ed5972e49a4b3fceb4f354'] = array(
    'source' => 'Options for the administrative overlay',
    'context' => '',
    'location' => '',
    'translation' => 'خيارات للتراكب الاداري ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Options for the administrative overlay', array(), array('context' => ''));
  $translations['ar:default']['7d063973485125fe316714495899a082'] = array(
    'source' => 'Bring in data about the main node.',
    'context' => '',
    'location' => '/ar',
    'translation' => 'جلب بيانات حول العقدة الرئيسية.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Bring in data about the main node.', array(), array('context' => ''));
  $translations['ar:default']['7dd7cd514726666cfc5ca33ade85447f'] = array(
    'source' => 'The language the comment is in.',
    'context' => '',
    'location' => '',
    'translation' => 'لغة التعليق ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The language the comment is in.', array(), array('context' => ''));
  $translations['ar:default']['7deb43a7df608085ef813006e55caf63'] = array(
    'source' => 'Converts Twitter-style @usernames into links to Twitter account pages.',
    'context' => '',
    'location' => '',
    'translation' => 'Converts Twitter-style @usernames into links to Twitter account pages.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Converts Twitter-style @usernames into links to Twitter account pages.', array(), array('context' => ''));
  $translations['ar:default']['7e335301c328706aff83a28be9988e21'] = array(
    'source' => 'user flagged content',
    'context' => '',
    'location' => '',
    'translation' => 'تنبيه المستخدم على المحتوى',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('user flagged content', array(), array('context' => ''));
  $translations['ar:default']['7e62e8cdb2bf4ddf44da2c9908a44b45'] = array(
    'source' => 'User target ID',
    'context' => '',
    'location' => '/ar',
    'translation' => 'المستخدم المستهدف ID',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('User target ID', array(), array('context' => ''));
  $translations['ar:default']['7e883a2ff2cc6401d9be80e4ea35be4b'] = array(
    'source' => 'Provide a simple link to delete the comment.',
    'context' => '',
    'location' => '',
    'translation' => 'ضع رابط بسيط لحذف التعليق.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Provide a simple link to delete the comment.', array(), array('context' => ''));
  $translations['ar:default']['7ec3740c3874bcbf762029d0752e383a'] = array(
    'source' => 'Has taxonomy term ID depth modifier',
    'context' => '',
    'location' => '',
    'translation' => 'Has taxonomy term ID depth modifier',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Has taxonomy term ID depth modifier', array(), array('context' => ''));
  $translations['ar:default']['7ec82ba2a797c3493855ca3762b660d4'] = array(
    'source' => 'The text of the Twitter message.',
    'context' => '',
    'location' => '',
    'translation' => 'نص رسالة تويتر.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The text of the Twitter message.', array(), array('context' => ''));
  $translations['ar:default']['7eca39de358415bfb69b727a9557cd1c'] = array(
    'source' => 'RSS Feed',
    'context' => '',
    'location' => '',
    'translation' => 'RSS موجز',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('RSS Feed', array(), array('context' => ''));
  $translations['ar:default']['7ed244f203b4020b15e2e39633d0d146'] = array(
    'source' => 'Not sticky',
    'context' => '',
    'location' => '',
    'translation' => 'غير مثبت',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Not sticky', array(), array('context' => ''));
  $translations['ar:default']['7f7293ac018a207e1243f07ad3b846fa'] = array(
    'source' => 'Display the depth of the comment if it is threaded.',
    'context' => '',
    'location' => '',
    'translation' => 'عرض عمق التعليق إذا كانت متتاليه',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Display the depth of the comment if it is threaded.', array(), array('context' => ''));
  $translations['ar:default']['7f9d837b006d9f6bdef040a7dfa60181'] = array(
    'source' => 'Scheduled Rules components',
    'context' => '',
    'location' => '/ar',
    'translation' => 'المقرر قوانين مكونات',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Scheduled Rules components', array(), array('context' => ''));
  $translations['ar:default']['7fc40673157c8dc04e155414d571363d'] = array(
    'source' => 'Every instance of [media-title:$nid] will be replaced with the corresponding Meedan oEmbed node view.',
    'context' => '',
    'location' => '/ar',
    'translation' => 'Every instance of [media-title:$nid] will be replaced with the corresponding Meedan oEmbed node view.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Every instance of [media-title:$nid] will be replaced with the corresponding Meedan oEmbed node view.', array(), array('context' => ''));
  $translations['ar:default']['7fcccd82de0536f3d05d5db6bf724e1c'] = array(
    'source' => 'The ID of the source string.',
    'context' => '',
    'location' => '',
    'translation' => 'معرف سلسلة المصدر.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The ID of the source string.', array(), array('context' => ''));
  $translations['ar:default']['7fe6e55d426818cc747b9a3eaecbb81a'] = array(
    'source' => 'The main body text',
    'context' => '',
    'location' => '',
    'translation' => 'النص الأساسي الرئيسي',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The main body text', array(), array('context' => ''));
  $translations['ar:default']['80491ff868103036d079dd4a6225c287'] = array(
    'source' => 'User ID from logged in user',
    'context' => '',
    'location' => '',
    'translation' => 'User ID from logged in user',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('User ID from logged in user', array(), array('context' => ''));
  $translations['ar:default']['804a5cb9b02690768a53f59044d84c61'] = array(
    'source' => 'Date the activity was registered',
    'context' => '',
    'location' => '/ar',
    'translation' => 'تاريخ تسجيل النشاط',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Date the activity was registered', array(), array('context' => ''));
  $translations['ar:default']['80b2c2498f5d0d32e2881aedadf79f37'] = array(
    'source' => '<p><strong><a href="!user_url">!username</a></strong> has turned on fact-checking for a <strong><a href="!report_url">report</a></strong> they submitted. Fact checking is in progress.</p>',
    'context' => '',
    'location' => '/checkdesk-p/ar',
    'translation' => '<p>قام <strong><a href="!user_url">!username</a></strong> بتفعيل التحقق من صحة المعلومات <strong><a href="!report_url">للتقرير</a></strong> الذي تم انشائه. التحقق من صحة المعلومات جارٍ.</p>',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('<p><strong><a href="!user_url">!username</a></strong> has turned on fact-checking for a <strong><a href="!report_url">report</a></strong> they submitted. Fact checking is in progress.</p>', array(), array('context' => ''));
  $translations['ar:default']['80c9379f5bc0f2b7a6650a0b898dfc94'] = array(
    'source' => 'Text area',
    'context' => '',
    'location' => '/ar',
    'translation' => 'منطقة النص',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Text area', array(), array('context' => ''));
  $translations['ar:default']['80e2d4481655ca0acdad92a1872e4f12'] = array(
    'source' => 'Query will be generated and run using the Drupal database API.',
    'context' => '',
    'location' => '',
    'translation' => 'Query will be generated and run using the Drupal database API.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Query will be generated and run using the Drupal database API.', array(), array('context' => ''));
  $translations['ar:default']['80eadec2a1f9a0047dec31f55bbcf489'] = array(
    'source' => 'Cannot add primary key to table %table: table doesn\'t exist.',
    'context' => '',
    'location' => '',
    'translation' => 'لا يمكن إضافة المفتاح الأساسي للجدول %table : الجدول غير موجود.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Cannot add primary key to table %table: table doesn\'t exist.', array(), array('context' => ''));
  $translations['ar:default']['8101f4b0f1f6acfec4e1de3b39ebe4e5'] = array(
    'source' => 'The unique authentication name.',
    'context' => '',
    'location' => '',
    'translation' => 'اسم المصادقة الفريدة من نوعها.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The unique authentication name.', array(), array('context' => ''));
  $translations['ar:default']['8139011e0206a59a0e90a567e769ddbe'] = array(
    'source' => '@count[2] reports',
    'context' => '',
    'location' => '/ar/story-collaboration/12183',
    'translation' => 'تقريران',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('@count[2] reports', array(), array('context' => ''));
  $translations['ar:default']['81658e723498b806a42aa7f578056dcf'] = array(
    'source' => 'SQL Query',
    'context' => '',
    'location' => '',
    'translation' => 'استعلام SQL',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('SQL Query', array(), array('context' => ''));
  $translations['ar:default']['817d0d047646491387d41e77e6b0bcd0'] = array(
    'source' => 'Cannot add unique key %name to table %table: unique key already exists.',
    'context' => '',
    'location' => '',
    'translation' => 'لا يمكن إضافة المفتاح الفريد للجدول %table: هذا المفتاح موجود مسبقاً.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Cannot add unique key %name to table %table: unique key already exists.', array(), array('context' => ''));
  $translations['ar:default']['81887062a01efc80192587b906a4b177'] = array(
    'source' => 'Upload date',
    'context' => '',
    'location' => '',
    'translation' => 'تاريخ التحميل ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Upload date', array(), array('context' => ''));
  $translations['ar:default']['819435a40717b38800b17c9d4d83a1fa'] = array(
    'source' => '<a href="!user_url" class="actor">!username</a> has turned on fact-checking for a <a href="!report_url">report</a> you added',
    'context' => '',
    'location' => '/ar/story-collaboration/12289',
    'translation' => 'لقد فعل <a href="!user_url">!username</a>التحقق من صحة المعلومات لدى <a href="!report_url">تقريرك</a>',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('<a href="!user_url" class="actor">!username</a> has turned on fact-checking for a <a href="!report_url">report</a> you added', array(), array('context' => ''));
  $translations['ar:default']['83096ba59f603818f57fc934d22cb270'] = array(
    'source' => 'Has Avatar',
    'context' => '',
    'location' => '',
    'translation' => 'يحوي صورة شخصية',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Has Avatar', array(), array('context' => ''));
  $translations['ar:default']['833de5744e6bbe4aec33af8795c80e25'] = array(
    'source' => 'The raw numeric user ID.',
    'context' => '',
    'location' => '',
    'translation' => 'الخام هوية المستخدم الرقمية.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The raw numeric user ID.', array(), array('context' => ''));
  $translations['ar:default']['834d02549162cb039cd7199d3f532c2e'] = array(
    'source' => 'Thank you for applying for an account. Your account is currently pending approval by the site administrator.',
    'context' => '',
    'location' => '/ar/user/register',
    'translation' => 'نشكرك لطلبك حسابا. حسابك حاليا بانتظار موافقة مشرف الموقع.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Thank you for applying for an account. Your account is currently pending approval by the site administrator.', array(), array('context' => ''));
  $translations['ar:default']['8366ee26cfb407ef55685715b3322b01'] = array(
    'source' => 'Hello !recipient_name,

!author has added a footnote to the following report "!title":

!body

<a href="!url">Click here</a> to respond or change the status of the report.

You can edit your notification settings from your <a href="!recipient_url">profile page</a>.

This was an auto-generated email from !site; please do not respond directly to this email.',
    'context' => '',
    'location' => '/index.php',
    'translation' => 'مرحباً !recipient_name،

لقد قام !author بإضافة معلومات جديدة للتحقق من صحة المعلومات في التقرير التالي "!title":

!body

<a href="!url">اضغط هنا</a> لترد أو تغير حالة التقرير.

بإمكانك تعديل إعدادات التنبيهات الخاصة بك من صفحة <a href="!recipient_url">الحساب الشخصي</a> الخاصة بك.

هذه رسالة مولدة بشكل تلقائي من !site، يرجى عدم الرد على هذه الرسالة.
',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Hello !recipient_name,

!author has added a footnote to the following report "!title":

!body

<a href="!url">Click here</a> to respond or change the status of the report.

You can edit your notification settings from your <a href="!recipient_url">profile page</a>.

This was an auto-generated email from !site; please do not respond directly to this email.', array(), array('context' => ''));
  $translations['ar:default']['8371d13f0990707879c1e3e0d0835cf1'] = array(
    'source' => 'Evaluates a mathematical expression and displays it.',
    'context' => '',
    'location' => '',
    'translation' => 'يقيم تعباير رياضية ويعرضها.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Evaluates a mathematical expression and displays it.', array(), array('context' => ''));
  $translations['ar:default']['843f2812f595e7ec7c5036e89fde02d6'] = array(
    'source' => 'Exclude',
    'context' => '',
    'location' => '',
    'translation' => 'إقصاء',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Exclude', array(), array('context' => ''));
  $translations['ar:default']['84b2182feb78efd88020558fde1faa7b'] = array(
    'source' => 'Provide a simple link to edit the user.',
    'context' => '',
    'location' => '',
    'translation' => 'تقديم وصلة بسيطة لتحرير المحتوى.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Provide a simple link to edit the user.', array(), array('context' => ''));
  $translations['ar:default']['84c1a9f47dd1b85710fe93c2f0558f3a'] = array(
    'source' => 'Provide custom text or link.',
    'context' => '',
    'location' => '',
    'translation' => 'تقديم نص مخصص أو رابط',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Provide custom text or link.', array(), array('context' => ''));
  $translations['ar:default']['84c4dfc8fccf9350a9610e366ae769a5'] = array(
    'source' => 'Reply To',
    'context' => '',
    'location' => '/ar',
    'translation' => 'الرد على',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Reply To', array(), array('context' => ''));
  $translations['ar:default']['84f5c0535b465c484db4d5787eca2c60'] = array(
    'source' => 'The aliased path to this content.',
    'context' => '',
    'location' => '',
    'translation' => 'The aliased path to this content.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The aliased path to this content.', array(), array('context' => ''));
  $translations['ar:default']['84f83bc640fb8de5e4c4551106b65f22'] = array(
    'source' => 'Autocomplete',
    'context' => '',
    'location' => '',
    'translation' => 'الإكمال التلقائي',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Autocomplete', array(), array('context' => ''));
  $translations['ar:default']['851f023be781bbc9ee2154b7db28d1f3'] = array(
    'source' => 'Added ',
    'context' => '',
    'location' => '/',
    'translation' => 'أضاف ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Added ', array(), array('context' => ''));
  $translations['ar:default']['8567d06b436c06938d4d20225c9ea85c'] = array(
    'source' => 'Beirut',
    'context' => '',
    'location' => '/meedan/meedan-checkdesk/drupal/ar/node/15692',
    'translation' => 'بيروت',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Beirut', array(), array('context' => ''));
  $translations['ar:default']['85981ed9fa73535ed55bb6ca15cc2988'] = array(
    'source' => 'Content ID from URL',
    'context' => '',
    'location' => '',
    'translation' => 'Content ID from URL',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Content ID from URL', array(), array('context' => ''));
  $translations['ar:default']['85eb6423b752c09262d8263767619d0d'] = array(
    'source' => 'Add feature image',
    'context' => '',
    'location' => '/ar//',
    'translation' => 'أضف الصورة الرئيسية',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Add feature image', array(), array('context' => ''));
  $translations['ar:default']['85fbb96c2a77c6214cf159a974dbf7a1'] = array(
    'source' => '<a href="@user">!user</a> added this <time class="time-ago" datetime="!timestamp">!interval ago</time>',
    'context' => '',
    'location' => '',
    'translation' => 'أضيف من قبل <a href="@user">!user</a> <time class="time-ago" datetime="!timestamp">منذ !interval</time>',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('<a href="@user">!user</a> added this <time class="time-ago" datetime="!timestamp">!interval ago</time>', array(), array('context' => ''));
  $translations['ar:default']['86166cf4a2baf2f56212bd94fe7dbbaa'] = array(
    'source' => 'Display even if view has no result',
    'context' => '',
    'location' => '',
    'translation' => 'عرضه ولو كانت الرؤية دون نتائج',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Display even if view has no result', array(), array('context' => ''));
  $translations['ar:default']['86358986e193af6647aa496bdf6c2e06'] = array(
    'source' => 'oEmbed legacy filter',
    'context' => '',
    'location' => '/ar',
    'translation' => 'oEmbed legacy filter',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('oEmbed legacy filter', array(), array('context' => ''));
  $translations['ar:default']['868c0684fb7feae71c3e68d95a21839d'] = array(
    'source' => 'Change theme',
    'context' => '',
    'location' => '',
    'translation' => 'تغيير الحلة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Change theme', array(), array('context' => ''));
  $translations['ar:default']['86c386d14ae325895843e01abe75e7b4'] = array(
    'source' => 'The user that uploaded the file.',
    'context' => '',
    'location' => '',
    'translation' => 'المستخدم الذي  قام بتحميل الملف.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The user that uploaded the file.', array(), array('context' => ''));
  $translations['ar:default']['86d0c38ffaf0a2efc7ded8cf886c6d0e'] = array(
    'source' => 'A taxonomy vocabulary that is associated with this file, usually because this file is in a field on the taxonomy vocabulary.',
    'context' => '',
    'location' => '',
    'translation' => 'A المفردات التصنيف مقترن هذا الملف، لأن هذا الملف عادة في حقل على مفردات التصنيف.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('A taxonomy vocabulary that is associated with this file, usually because this file is in a field on the taxonomy vocabulary.', array(), array('context' => ''));
  $translations['ar:default']['86e513c1d0a97d91321f8d37df2ee933'] = array(
    'source' => 'Flagged as spam.',
    'context' => '',
    'location' => '',
    'translation' => 'تم تنبيه السخام',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Flagged as spam.', array(), array('context' => ''));
  $translations['ar:default']['87322391cc6e8948ce9fd5d6cb84fced'] = array(
    'source' => 'Numeric',
    'context' => '',
    'location' => '',
    'translation' => 'رقمية',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Numeric', array(), array('context' => ''));
  $translations['ar:default']['876e98a9409d0d59a83ecdd0562411da'] = array(
    'source' => 'Add to Story',
    'context' => '',
    'location' => '',
    'translation' => 'أضف إلى موضوع',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Add to Story', array(), array('context' => ''));
  $translations['ar:default']['878530871f0db73f004f5bd6591eeb76'] = array(
    'source' => 'Remember me',
    'context' => '',
    'location' => '',
    'translation' => 'تذكّرني',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Remember me', array(), array('context' => ''));
  $translations['ar:default']['87c01892c628e1c8ab32210ebd1a5e54'] = array(
    'source' => 'Compose update',
    'context' => '',
    'location' => '',
    'translation' => 'أكتب تحديث',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Compose update', array(), array('context' => ''));
  $translations['ar:default']['880743a68fc07244feb7ba13a7e7d4c0'] = array(
    'source' => 'Administer views',
    'context' => '',
    'location' => '',
    'translation' => 'إدارة الرؤى',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Administer views', array(), array('context' => ''));
  $translations['ar:default']['881a91ac9ec32915d7356e99c63af43e'] = array(
    'source' => 'Sorry, @site can only handle public Facebook content. Please ensure you can access this URL when logged out of Facebook.',
    'context' => '',
    'location' => '/checkdesk/media-preview',
    'translation' => 'عذراً، @site يمكنه استخدام محتوى فيسبوك العلني فقط. يرجى التأكد من أنك يمكنك الوصول إلى تلك الصفحة عندما تقوم بتسجيل الخروج من فيسبوك.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Sorry, @site can only handle public Facebook content. Please ensure you can access this URL when logged out of Facebook.', array(), array('context' => ''));
  $translations['ar:default']['882928697e3d8a553d9e5dc9b940009d'] = array(
    'source' => 'Show a marker if the content is new or updated.',
    'context' => '',
    'location' => '',
    'translation' => 'إظهار علامة إذا ما كان المحتوى جديداً أو تم تحديثه.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Show a marker if the content is new or updated.', array(), array('context' => ''));
  $translations['ar:default']['886bb73b3156b0aa24aac99d2de0b238'] = array(
    'source' => 'counter',
    'context' => '',
    'location' => '',
    'translation' => 'مواجهة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('counter', array(), array('context' => ''));
  $translations['ar:default']['887496e1745a28a577e43c42e5fe1223'] = array(
    'source' => 'Schema version',
    'context' => '',
    'location' => '',
    'translation' => 'Schema version',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Schema version', array(), array('context' => ''));
  $translations['ar:default']['8880936a6b90433892ad4d76dc9fae14'] = array(
    'source' => 'Cancel link',
    'context' => '',
    'location' => '',
    'translation' => 'إلغاء الرابط',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Cancel link', array(), array('context' => ''));
  $translations['ar:default']['889c030d2cd90ec5e662dadd6319ba57'] = array(
    'source' => 'Field "@name".',
    'context' => '',
    'location' => '',
    'translation' => 'حقل "@name".',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Field "@name".', array(), array('context' => ''));
  $translations['ar:default']['88acb68b6e0aa55e8af07acfed9ce05e'] = array(
    'source' => 'User Tweets',
    'context' => '',
    'location' => '',
    'translation' => 'تغريدات المستخدم',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('User Tweets', array(), array('context' => ''));
  $translations['ar:default']['88ef7cd2222c28268ba6cc138fdc5bd5'] = array(
    'source' => '(No information available)',
    'context' => '',
    'location' => '',
    'translation' => '(لا توجد معلومات متاحة)',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('(No information available)', array(), array('context' => ''));
  $translations['ar:default']['89a7f1a5bfd330630c185b1140f1c5df'] = array(
    'source' => 'Featured stories',
    'context' => '',
    'location' => '/index.php',
    'translation' => 'مواضيع مختارة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Featured stories', array(), array('context' => ''));
  $translations['ar:default']['89c5c42f458a86f6108c22ec89f9b7c4'] = array(
    'source' => 'Where reports are verified and blog posts created.',
    'context' => '',
    'location' => '/ar',
    'translation' => 'مكان التحقق من التقارير وإنشاء التدوينات.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Where reports are verified and blog posts created.', array(), array('context' => ''));
  $translations['ar:default']['89ef73d0cd41601da06f2e63a26e6360'] = array(
    'source' => 'Scheduled date and time stamp',
    'context' => '',
    'location' => '',
    'translation' => 'المقرر طابع التاريخ والوقت',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Scheduled date and time stamp', array(), array('context' => ''));
  $translations['ar:default']['8a0e2b549d223aba55a866c38d1c9275'] = array(
    'source' => ', and',
    'context' => '',
    'location' => '/ar/search',
    'translation' => 'و',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t(', and', array(), array('context' => ''));
  $translations['ar:default']['8a103f1691c806d1d65ff45c6e039fff'] = array(
    'source' => 'Converts Twitter-style #hashtags into links to hashtags.org.',
    'context' => '',
    'location' => '',
    'translation' => 'Converts Twitter-style #hashtags into links to hashtags.org.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Converts Twitter-style #hashtags into links to hashtags.org.', array(), array('context' => ''));
  $translations['ar:default']['8a4ea684f4d991746ac1bda0dc4f3463'] = array(
    'source' => 'Input required',
    'context' => '',
    'location' => '',
    'translation' => 'تدخل مطلوب ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Input required', array(), array('context' => ''));
  $translations['ar:default']['8a6715c91831cb5ef87045f742fa9b00'] = array(
    'source' => '<span>@count[2]</span> results. Drag and drop the best ones.',
    'context' => '',
    'location' => '/ar/node/add/post?sort_order=DESC&title=universidade&title_op=contains&source=&source_op=contains',
    'translation' => '<span>@count[2]</span> نتائج. يمكنك سحب تقاريرك المفضلة لاستخدامها. ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('<span>@count[2]</span> results. Drag and drop the best ones.', array(), array('context' => ''));
  $translations['ar:default']['8a791f2d7d4a526939ff7ac05b7c0d52'] = array(
    'source' => 'Add authenticated Twitter accounts',
    'context' => '',
    'location' => '/index.php',
    'translation' => 'أضف حسابات تويتر مصدقة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Add authenticated Twitter accounts', array(), array('context' => ''));
  $translations['ar:default']['8aad4c7588229fa1678a1c07bfdc2c10'] = array(
    'source' => '<a href="[node:url:unaliased]">[node:author]\'s report</a> was unflagged as containing graphic content.',
    'context' => '',
    'location' => '/ar/flag/unflag/graphic_journalist/2447?destination=node/2447&token=KPFawrLou6qfujz-SsQucRW0B_4hr8CIbDcZBfbnrBo',
    'translation' => 'تم إلغاء تنبيه المشرف على احتواء <a href="[node:url:unaliased]"> تقرير [node:author] </a> على محتوى أو صور صادمة.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('<a href="[node:url:unaliased]">[node:author]\'s report</a> was unflagged as containing graphic content.', array(), array('context' => ''));
  $translations['ar:default']['8b9b82bdef7910e04be780d11dac62b5'] = array(
    'source' => 'Twitter status messages.',
    'context' => '',
    'location' => '',
    'translation' => 'حالة رسائل المغرد',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Twitter status messages.', array(), array('context' => ''));
  $translations['ar:default']['8bb89935c67ac7fc29c2d9e8ca0afdea'] = array(
    'source' => 'The language this translation is in.',
    'context' => '',
    'location' => '',
    'translation' => 'لغة الترجمة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The language this translation is in.', array(), array('context' => ''));
  $translations['ar:default']['8c00a9fe6213e6dcf1648d5fe5d89d1b'] = array(
    'source' => 'Success: Report created',
    'context' => '',
    'location' => '/ar/meedan_bookmarklet/message?meedan_bookmarklet=1&meedan_bookmarklet_submitted=1&meedan_bookmarklet_nid=15631&meedan_bookmarklet_url=http%3A//www.youtube.com/watch',
    'translation' => 'تم إنشاء التقرير بنجاح',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Success: Report created', array(), array('context' => ''));
  $translations['ar:default']['8c49ede7a0f50afb693ea079a8d8df85'] = array(
    'source' => 'Published or admin',
    'context' => '',
    'location' => '',
    'translation' => 'منشور أو مشرف',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Published or admin', array(), array('context' => ''));
  $translations['ar:default']['8c8b55002410f288cc22c00a353b70f4'] = array(
    'source' => 'Allows the "depth" for Taxonomy: Term ID (with depth) to be modified via an additional contextual filter value.',
    'context' => '',
    'location' => '',
    'translation' => 'يسمح لل "العمق " للتصنيف: ID الأجل (مع العمق) إلى تعديل قيمة إضافية عن طريق تصفية المحتوى.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Allows the "depth" for Taxonomy: Term ID (with depth) to be modified via an additional contextual filter value.', array(), array('context' => ''));
  $translations['ar:default']['8cc5a32952d5e1d48d8224c7b4385d67'] = array(
    'source' => 'Report published',
    'context' => '',
    'location' => '/meedan/meedan-checkdesk/drupal/index.php',
    'translation' => 'نشر تقرير',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Report published', array(), array('context' => ''));
  $translations['ar:default']['8d05a78720c9c754b3aa1b7db0dfd788'] = array(
    'source' => 'Auto Refresh',
    'context' => '',
    'location' => '/ar',
    'translation' => 'تحديث تلقائي',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Auto Refresh', array(), array('context' => ''));
  $translations['ar:default']['8d87e457a96018ef2c72fdc606a34e1a'] = array(
    'source' => '@count[3] rows',
    'context' => '',
    'location' => '',
    'translation' => '@count[3] سطر',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('@count[3] rows', array(), array('context' => ''));
  $translations['ar:default']['8d966b2253a917086c8604959e152243'] = array(
    'source' => 'high',
    'context' => '',
    'location' => '',
    'translation' => 'عالية',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('high', array(), array('context' => ''));
  $translations['ar:default']['8ddb0031cb1abd8e5129c6eef899dce4'] = array(
    'source' => 'Provide default value',
    'context' => '',
    'location' => '',
    'translation' => 'توفير قيمة افتراضية',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Provide default value', array(), array('context' => ''));
  $translations['ar:default']['8e053fe43d6d251516d791765835791d'] = array(
    'source' => 'Obtains a single representative node for each user, according to a chosen sort criterion.',
    'context' => '',
    'location' => '/ar',
    'translation' => 'يحصل على عقدة ممثل واحد لكل مستخدم، وفقا لمعيار النوع المختار.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Obtains a single representative node for each user, according to a chosen sort criterion.', array(), array('context' => ''));
  $translations['ar:default']['8e14bbb8b6b927fe4f950b848f96f894'] = array(
    'source' => 'The parent term of the term. This can produce duplicate entries if you are using a vocabulary that allows multiple parents.',
    'context' => '',
    'location' => '',
    'translation' => 'على المدى الأم لهذا المصطلح. وهذا يمكن أن ينتج إدخالات مكررة إذا كنت تستخدم المفردات التي يسمح الوالدين متعددة.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The parent term of the term. This can produce duplicate entries if you are using a vocabulary that allows multiple parents.', array(), array('context' => ''));
  $translations['ar:default']['8e291e7134a4259cc5d4a92324ff011b'] = array(
    'source' => 'Revision comparison',
    'context' => '',
    'location' => '/ar',
    'translation' => 'مقارنة المراجعات',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Revision comparison', array(), array('context' => ''));
  $translations['ar:default']['8ec99a7264620677dfdaba9785a62dc4'] = array(
    'source' => 'Invalid input',
    'context' => '',
    'location' => '',
    'translation' => 'معلومة مدخلة غير صالحة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Invalid input', array(), array('context' => ''));
  $translations['ar:default']['8f0da435078e7e8bca1694970cab739e'] = array(
    'source' => 'Comment on update',
    'context' => '',
    'location' => '/ar',
    'translation' => 'تعليق جديد على تحديث',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Comment on update', array(), array('context' => ''));
  $translations['ar:default']['8f35d2b1a92822a8ea66fc3c719c7e3a'] = array(
    'source' => 'Paged output, full Drupal style',
    'context' => '',
    'location' => '',
    'translation' => 'Paged output, full Drupal style',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Paged output, full Drupal style', array(), array('context' => ''));
  $translations['ar:default']['8f5ad54de24412fdf7d877d842a9ab2b'] = array(
    'source' => 'Display content if it has the selected taxonomy terms, or children of the selected terms. Due to additional complexity, this has fewer options than the versions without depth.',
    'context' => '',
    'location' => '',
    'translation' => 'عرض المحتوى إذا كان لديه شروط التصنيف المحدد، أو الأطفال من حيث المحددة. نظرا لتعقيد إضافي، وهذا له عدد أقل من الخيارات من الإصدارات دون العمق.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Display content if it has the selected taxonomy terms, or children of the selected terms. Due to additional complexity, this has fewer options than the versions without depth.', array(), array('context' => ''));
  $translations['ar:default']['8f5d9cd911a7678ce7dd9410fdacc764'] = array(
    'source' => 'A story begins with your first update. Then add more updates as the story evolves.',
    'context' => '',
    'location' => 'sites/all/modules/custom/checkdesk_core/js/tour/checkdesk-tour.js; sites/all/modules/custom/checkdesk_core/js/checkdesk_tour.js; sites/all/themes/checkdesk/assets/js/tour.js',
    'translation' => 'ابدأ الموضوع بكتابة أول تحديث. أضف المزيد من التحديثات لاحقاً لتغطية تطورات الموضوع.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('A story begins with your first update. Then add more updates as the story evolves.', array(), array('context' => ''));
  $translations['ar:default']['911482c6aecc4cc54ba5a82a0971ec5b'] = array(
    'source' => '@count[3] reports',
    'context' => '',
    'location' => '/ar/story-collaboration/10970',
    'translation' => '@count[3] تقريرات',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('@count[3] reports', array(), array('context' => ''));
  $translations['ar:default']['91388d8cfd7e9e0721bc7a9aea157854'] = array(
    'source' => 'The taxonomy vocabulary ID',
    'context' => '',
    'location' => '',
    'translation' => 'معرف مفردات التصنيف',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The taxonomy vocabulary ID', array(), array('context' => ''));
  $translations['ar:default']['9181935f4d698bf7281dd1660f3d360d'] = array(
    'source' => 'Sort criterion',
    'context' => '',
    'location' => '',
    'translation' => 'نوع المعيار',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Sort criterion', array(), array('context' => ''));
  $translations['ar:default']['919fa6cb938ad41e8af74c8dcd59f37b'] = array(
    'source' => 'Queue empty',
    'context' => '',
    'location' => '',
    'translation' => 'القائمة خالية',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Queue empty', array(), array('context' => ''));
  $translations['ar:default']['91a7feb42adb098cdcc178311e75d834'] = array(
    'source' => '<a href="[node:url:unaliased]">[node:author]\'s report</a> was unflagged as spam.',
    'context' => '',
    'location' => '/ar/node/flag/confirm/unflag/spam/2447/ajax',
    'translation' => 'تم إلغاء تنبيه المشرف على أن <a href="[node:url:unaliased]"> تقرير [node:author] </a>  سبام (سخام).',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('<a href="[node:url:unaliased]">[node:author]\'s report</a> was unflagged as spam.', array(), array('context' => ''));
  $translations['ar:default']['91ef1f164f1c23e4fc84f5978c6fe571'] = array(
    'source' => 'Activity message',
    'context' => '',
    'location' => '/ar',
    'translation' => 'رسالة النشاط',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Activity message', array(), array('context' => ''));
  $translations['ar:default']['91fce3d1354bf41e78b34246c413c6bf'] = array(
    'source' => 'Cannot add index %name to table %table: index already exists.',
    'context' => '',
    'location' => '',
    'translation' => 'لا يمكن إضافة الفهرس %name للجدول %table: الفهرس موجود مسبقاً.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Cannot add index %name to table %table: index already exists.', array(), array('context' => ''));
  $translations['ar:default']['92155f3fbeb14b34b3fe022f18859290'] = array(
    'source' => 'Displays the fields with an optional template.',
    'context' => '',
    'location' => '',
    'translation' => 'يعرض الحقول مع قالب اختياري',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Displays the fields with an optional template.', array(), array('context' => ''));
  $translations['ar:default']['928b0f4d797f95cb8429e86b3e0adbcb'] = array(
    'source' => 'Any status',
    'context' => '',
    'location' => '/ar/search?field_tags_tid=1327',
    'translation' => 'أي حالة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Any status', array(), array('context' => ''));
  $translations['ar:default']['92ddf975b48818fa61a45896684cb337'] = array(
    'source' => '<a class="actor" href="!user_url">!username</a> update <a href="!story_url">story</a>',
    'context' => '',
    'location' => '/ar/node/add/post',
    'translation' => 'قام <a class="actor" href="!user_url">!username</a> بتحديث <a href="!story_url"> هذا الموضوع </a>',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('<a class="actor" href="!user_url">!username</a> update <a href="!story_url">story</a>', array(), array('context' => ''));
  $translations['ar:default']['9300fe8efb8c91a29f7582c8539b79b7'] = array(
    'source' => 'Update headline',
    'context' => '',
    'location' => '/ar/node/add/post',
    'translation' => 'عنوان التحديث',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Update headline', array(), array('context' => ''));
  $translations['ar:default']['93935b770e5254fea51e01a17c591296'] = array(
    'source' => 'Hello !recipient_name,

!author has added footnote to the following report "!title":

!body

<a href="!url">Click here</a> to respond or change the status of the report.

You can edit your notification settings from your <a href="!recipient_url">profile page</a>.

This was an auto-generated email from !site; please do not respond directly to this email.',
    'context' => '',
    'location' => '/meedan/meedan-checkdesk/drupal/index.php',
    'translation' => 'مرحباً !recipient_name،

لقد قام !author بإضافة معلومات جديدة للتحقق من صحة المعلومات في التقرير التالي "!title":

!body

<a href="!url">اضغط هنا</a> لترد أو تغير حالة التقرير.

بإمكانك تعديل إعدادات التنبيهات الخاصة بك من صفحة <a href="!recipient_url">الحساب الشخصي</a> الخاصة بك.

هذه رسالة مولدة بشكل تلقائي من !site، يرجى عدم الرد على هذه الرسالة.
',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Hello !recipient_name,

!author has added footnote to the following report "!title":

!body

<a href="!url">Click here</a> to respond or change the status of the report.

You can edit your notification settings from your <a href="!recipient_url">profile page</a>.

This was an auto-generated email from !site; please do not respond directly to this email.', array(), array('context' => ''));
  $translations['ar:default']['93f40afd04f0b6da1a069734c016b928'] = array(
    'source' => 'Fact-checking has been enabled for this report.',
    'context' => '',
    'location' => '/ar/flag/flag/factcheck_journalist/236?destination=reports&token=cq66hVGBpwEbqZAoxwlCaVuAIJUzr17bkL6XpEe40Pg',
    'translation' => ' تم تفعيل التحقق من صحة المعلومات لهذا التقرير. ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Fact-checking has been enabled for this report.', array(), array('context' => ''));
  $translations['ar:default']['9440be265ad05e22301246dde76200ed'] = array(
    'source' => '<span>@count[4]</span> results. Drag and drop the best ones.',
    'context' => '',
    'location' => '/ar/node/add/post',
    'translation' => '<span>@count[4]</span> نتائج. يمكنك سحب تقاريرك المفضلة لاستخدامها. ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('<span>@count[4]</span> results. Drag and drop the best ones.', array(), array('context' => ''));
  $translations['ar:default']['945c8caa41aa52daf318b2c1ce1624c7'] = array(
    'source' => 'Translation to %language',
    'context' => '',
    'location' => '',
    'translation' => 'ترجمة إلى %language',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Translation to %language', array(), array('context' => ''));
  $translations['ar:default']['94667114cc7b885cd8f3a13bcee1d0c9'] = array(
    'source' => 'Hello !recipient_name,

!actor has suggested this report "!node_title" to this story "!story_title".

<a href="!story_url">Click here</a> to compose a new update to the story using that report.

You can edit your notification settings from your <a href="!recipient_url">profile page</a>.

This was an auto-generated email from !site, please do not respond directly to this email.',
    'context' => '',
    'location' => '/meedan/meedan-checkdesk/drupal/index.php',
    'translation' => 'مرحباً !recipient_name،

قام !actor باقتراح إضافة هذا التقرير "!node_title" إلى هذا الموضوع "!story_title".

<a href="!story_url">اضغط هنا</a> لكتابة تحديث جديد على ذلك الخبر باستخدام ذاك التقرير.

بإمكانك تعديل إعدادات التنبيهات الخاصة بك من صفحة <a href="!recipient_url">الحساب الشخصي</a> الخاصة بك.

هذه رسالة مولدة بشكل تلقائي من !site، يرجى عدم الرد على هذه الرسالة.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Hello !recipient_name,

!actor has suggested this report "!node_title" to this story "!story_title".

<a href="!story_url">Click here</a> to compose a new update to the story using that report.

You can edit your notification settings from your <a href="!recipient_url">profile page</a>.

This was an auto-generated email from !site, please do not respond directly to this email.', array(), array('context' => ''));
  $translations['ar:default']['946ce64056038a79c2d3c21412947b51'] = array(
    'source' => 'Add report to story',
    'context' => '',
    'location' => '',
    'translation' => 'أضف التقرير إلى موضوع',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Add report to story', array(), array('context' => ''));
  $translations['ar:default']['94f5ee7db89178971fc45408f7f52dfc'] = array(
    'source' => 'The unique ID of the node.',
    'context' => '',
    'location' => '',
    'translation' => 'المعرف الفريد للعقدة.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The unique ID of the node.', array(), array('context' => ''));
  $translations['ar:default']['95dde73a585eac2097df097b183832be'] = array(
    'source' => 'Whether a user is active or blocked.',
    'context' => '',
    'location' => '',
    'translation' => 'ما إذا كان المستخدم نشطاً أو محظوراً.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Whether a user is active or blocked.', array(), array('context' => ''));
  $translations['ar:default']['95f5c4482c77c923376526729740bd80'] = array(
    'source' => 'The comment ID of the field',
    'context' => '',
    'location' => '',
    'translation' => 'The comment ID of the field',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The comment ID of the field', array(), array('context' => ''));
  $translations['ar:default']['9614febe881de1a6e6b2b3d7664f2689'] = array(
    'source' => 'Twitter accounts',
    'context' => '',
    'location' => '',
    'translation' => 'حسابات تويتر',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Twitter accounts', array(), array('context' => ''));
  $translations['ar:default']['9628e2a2013f2467d07e01be30e41aea'] = array(
    'source' => 'Post new comment',
    'context' => '',
    'location' => '',
    'translation' => 'أضف تعليقاً جديداً',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Post new comment', array(), array('context' => ''));
  $translations['ar:default']['963c7a14230202ce49d37186997f7593'] = array(
    'source' => 'The user or author name. This filter does not check if the user exists and allows partial matching. Does not utilize autocomplete.',
    'context' => '',
    'location' => '',
    'translation' => 'المستخدم أو اسم المؤلف. هذا الفلتر لا تحقق مما إذا كان المستخدم موجودا ويسمح مطابقة جزئية. لا تستخدم الإكمال التلقائي.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The user or author name. This filter does not check if the user exists and allows partial matching. Does not utilize autocomplete.', array(), array('context' => ''));
  $translations['ar:default']['967652722fbd48c3c8535599e05bf5b1'] = array(
    'source' => 'All nodes where a certain user has a revision',
    'context' => '',
    'location' => '',
    'translation' => 'جميع العقد حيث مستخدم معينة لديه مراجعة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('All nodes where a certain user has a revision', array(), array('context' => ''));
  $translations['ar:default']['969ac229cf3686787813b5749760a4f1'] = array(
    'source' => '!title added by !username.',
    'context' => '',
    'location' => '',
    'translation' => '!title أضيف من قبل !username.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('!title added by !username.', array(), array('context' => ''));
  $translations['ar:default']['96ba4941bfc8c5d185cbca4b8226ed38'] = array(
    'source' => '<Hidden>',
    'context' => '',
    'location' => '',
    'translation' => '<مخفي>',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('<Hidden>', array(), array('context' => ''));
  $translations['ar:default']['96d008db67fc0b5551a926842bbb6a71'] = array(
    'source' => 'Notification',
    'context' => '',
    'location' => 'sites/all/modules/custom/checkdesk_notifications/js/notifications_menu.js',
    'translation' => 'تنبيه',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Notification', array(), array('context' => ''));
  $translations['ar:default']['9702d6df178b1fefb34c5a7f7c00c60e'] = array(
    'source' => '@count[3] updates',
    'context' => '',
    'location' => '/ar/search?type=discussion',
    'translation' => '@count[3] تحديثات',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('@count[3] updates', array(), array('context' => ''));
  $translations['ar:default']['970db4474d1ac19c6580b32573b4da91'] = array(
    'source' => 'Label, as link with label as title',
    'context' => '',
    'location' => '',
    'translation' => 'التسمية، وتسمية الارتباط مع كعنوان',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Label, as link with label as title', array(), array('context' => ''));
  $translations['ar:default']['9718430c2551563193f5e9cc4d8b0a85'] = array(
    'source' => 'Created year + month',
    'context' => '',
    'location' => '',
    'translation' => '+ إنشاء السنة الشهر',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Created year + month', array(), array('context' => ''));
  $translations['ar:default']['9768248772252d7e6a5c86bf989f43fc'] = array(
    'source' => '@entity referencing @target_entity from !field_name',
    'context' => '',
    'location' => '',
    'translation' => '@entity referencing @target_entity from !field_name',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('@entity referencing @target_entity from !field_name', array(), array('context' => ''));
  $translations['ar:default']['9771a75dc7f592fffc492a1cf7aa9444'] = array(
    'source' => 'Singular LID',
    'context' => '',
    'location' => '',
    'translation' => 'Singular LID',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Singular LID', array(), array('context' => ''));
  $translations['ar:default']['97bc592b27a9ada2d9a4bb418ed0ebed'] = array(
    'source' => 'now',
    'context' => '',
    'location' => '/checkdesk/ar/system/ajax',
    'translation' => 'اﻵن',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('now', array(), array('context' => ''));
  $translations['ar:default']['984a7717d7dbfd4aa04f3d1082d36026'] = array(
    'source' => 'Get an overview of all content.',
    'context' => '',
    'location' => '',
    'translation' => 'الحصول على نظرة عامة إلى كل المحتوى.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Get an overview of all content.', array(), array('context' => ''));
  $translations['ar:default']['988fe3b3a50fcfa5f21db5e41051e2a1'] = array(
    'source' => 'The date the user was created.',
    'context' => '',
    'location' => '',
    'translation' => 'تاريخ إنشاء المستخدم.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The date the user was created.', array(), array('context' => ''));
  $translations['ar:default']['98b3009e61879600839e1ee486bb3282'] = array(
    'source' => 'Close window',
    'context' => '',
    'location' => '',
    'translation' => 'إغلاق النافذة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Close window', array(), array('context' => ''));
  $translations['ar:default']['9912cddd630e8c50e329254e08e08927'] = array(
    'source' => 'Provide a simple link to edit the comment.',
    'context' => '',
    'location' => '',
    'translation' => 'ضع رابط بسيط لتحرير التعليق.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Provide a simple link to edit the comment.', array(), array('context' => ''));
  $translations['ar:default']['99671e921962029822d89ff6ec5273d7'] = array(
    'source' => 'Relate all content tagged with a term.',
    'context' => '',
    'location' => '',
    'translation' => 'تتصل جميع المحتويات ذات الكلمات الدلالية مع مصطلح.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Relate all content tagged with a term.', array(), array('context' => ''));
  $translations['ar:default']['997ee8b98498f404c8813296aa0db2fa'] = array(
    'source' => 'Relate users to the flaggings they have made on objects, using a particular flag.',
    'context' => '',
    'location' => '/ar',
    'translation' => 'Relate users to the flaggings they have made on objects, using a particular flag.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Relate users to the flaggings they have made on objects, using a particular flag.', array(), array('context' => ''));
  $translations['ar:default']['99a030b5fbb6b7423aba0dca066e1366'] = array(
    'source' => 'Sorted by time and filtered by current story',
    'context' => '',
    'location' => '',
    'translation' => 'مرتبة حسب التاريخ ومفلترة بحسب الموضوع الحالي',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Sorted by time and filtered by current story', array(), array('context' => ''));
  $translations['ar:default']['99c88bad4ef73b69d8d3c165b3be8240'] = array(
    'source' => 'The user\'s default theme.',
    'context' => '',
    'location' => '',
    'translation' => 'السمة الافتراضية للمستخدم.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The user\'s default theme.', array(), array('context' => ''));
  $translations['ar:default']['9a60f0eb9ac56f02ae70a53e230a7f9d'] = array(
    'source' => 'New update on a story I commented on an update before',
    'context' => '',
    'location' => '/ar',
    'translation' => 'تحديث جديد على موضوع علقت على أحد تحديثاته في السابق',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('New update on a story I commented on an update before', array(), array('context' => ''));
  $translations['ar:default']['9a834e7046636c78f60eacb9161801ba'] = array(
    'source' => 'Search for tag',
    'context' => '',
    'location' => '/ar/search',
    'translation' => 'البحث عن وسم',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Search for tag', array(), array('context' => ''));
  $translations['ar:default']['9aae87fda5e8adbd7c8eceac62730910'] = array(
    'source' => 'A story contains one or more liveblog updates. The story will remain unpublished until the first update is created.',
    'context' => '',
    'location' => '/',
    'translation' => 'يجب أن يحتوي الموضوع تحديثاً واحداً أو أكثر. سيبقى هذا الموضوع غير منشور حتى تكتب أول تحديث.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('A story contains one or more liveblog updates. The story will remain unpublished until the first update is created.', array(), array('context' => ''));
  $translations['ar:default']['9ac41b6a577daadd588f0fcde0071e8b'] = array(
    'source' => 'Updates',
    'context' => '',
    'location' => '/ar/story/35',
    'translation' => 'تحديثات',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Updates', array(), array('context' => ''));
  $translations['ar:default']['9ac723d332fe0dd76b7c322c3dee9664'] = array(
    'source' => '<p><strong><a href="!flag_author_url">!flag_author_name</a></strong> has flagged a <strong><a href="!report_url">report</a></strong> !preposition !flag_type</p>',
    'context' => '',
    'location' => '/ar',
    'translation' => ' <p><strong><a href="!flag_author_url">!flag_author_name</a></strong> قام بتنبيهك على <strong><a href="!report_url">تقرير</a></strong> !preposition !flag_type</p> ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('<p><strong><a href="!flag_author_url">!flag_author_name</a></strong> has flagged a <strong><a href="!report_url">report</a></strong> !preposition !flag_type</p>', array(), array('context' => ''));
  $translations['ar:default']['9b23d4958922528abd4e6b307e62a1c1'] = array(
    'source' => 'Heartbeat activity username',
    'context' => '',
    'location' => '/ar',
    'translation' => 'Heartbeat activity username',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Heartbeat activity username', array(), array('context' => ''));
  $translations['ar:default']['9bebc34a2552fbf70fa3a8d9e7d972b5'] = array(
    'source' => 'The universally unique ID of the @type.',
    'context' => '',
    'location' => '/ar',
    'translation' => 'The universally unique ID of the @type.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The universally unique ID of the @type.', array(), array('context' => ''));
  $translations['ar:default']['9c09d66db4be5a97ae64e42e68654744'] = array(
    'source' => 'Please select the events for which you wish to be notified',
    'context' => '',
    'location' => '/ar/user/16/notifications',
    'translation' => 'يرجى اختيار الأحداث التي ترغب بالحصول على التنبيهات عليها',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Please select the events for which you wish to be notified', array(), array('context' => ''));
  $translations['ar:default']['9c43106d3724aa859b1aef83d8f5b6af'] = array(
    'source' => 'Display a limited number items that this view might find.',
    'context' => '',
    'location' => '',
    'translation' => 'عرض  عدد  محدود للعانصر التي قد توجد في العرض',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Display a limited number items that this view might find.', array(), array('context' => ''));
  $translations['ar:default']['9c4557cc214d21b55880fdb2ac2f66cc'] = array(
    'source' => 'Display content if it has the selected taxonomy terms.',
    'context' => '',
    'location' => '',
    'translation' => 'عرض المحتوى إذا كان لديه شروط التصنيف المحددة.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Display content if it has the selected taxonomy terms.', array(), array('context' => ''));
  $translations['ar:default']['9c4fd78f14b79eb3995867191a7f48fc'] = array(
    'source' => 'Display all taxonomy terms associated with a node from specified vocabularies.',
    'context' => '',
    'location' => '',
    'translation' => 'عرض جميع الشروط  التصنيف المرتبطة  بالعقدة من مفردات محددة.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Display all taxonomy terms associated with a node from specified vocabularies.', array(), array('context' => ''));
  $translations['ar:default']['9c4fdb87d8e393d3a29e0de953d16c8c'] = array(
    'source' => '!title created successfully.',
    'context' => '',
    'location' => '/ar/system/ajax',
    'translation' => 'تم إنشاء !title',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('!title created successfully.', array(), array('context' => ''));
  $translations['ar:default']['9c79f970fadd4da639cd7ca891892c88'] = array(
    'source' => 'Date in the form of YYYY.',
    'context' => '',
    'location' => '',
    'translation' => 'التاريخ بصيغة YYYY.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Date in the form of YYYY.', array(), array('context' => ''));
  $translations['ar:default']['9c84a9092405eb7bf3dbe58763174f8b'] = array(
    'source' => '<a href="[node:url:unaliased]">[node:author]\'s report</a> was flagged as spam.',
    'context' => '',
    'location' => '/ar/node/flag/confirm/flag/spam/2447/ajax',
    'translation' => 'تم تنبيه المشرف على أن <a href="[node:url:unaliased]"> تقرير [node:author] </a>  سبام (سخام).',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('<a href="[node:url:unaliased]">[node:author]\'s report</a> was flagged as spam.', array(), array('context' => ''));
  $translations['ar:default']['9c8e6d76aecb40eeeec24d50f8337f69'] = array(
    'source' => 'The mime type of the file.',
    'context' => '',
    'location' => '',
    'translation' => 'نوع MIME من الملف.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The mime type of the file.', array(), array('context' => ''));
  $translations['ar:default']['9c9f249fab1553fa0ae168a863bcf76a'] = array(
    'source' => 'Last refresh',
    'context' => '',
    'location' => '',
    'translation' => 'اخر تحديث',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Last refresh', array(), array('context' => ''));
  $translations['ar:default']['9cc1936edbaa6eec106a53425bea55a8'] = array(
    'source' => '@count more updates',
    'context' => '',
    'location' => '',
    'translation' => '@count تحديثات أخرى',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('@count more updates', array(), array('context' => ''));
  $translations['ar:default']['9d24a2be51a7ca2c56bddc8064fddf82'] = array(
    'source' => 'The \'Date\' field of the e-mail.',
    'context' => '',
    'location' => '/ar',
    'translation' => 'و\'تاريخ\' مجال البريد الإلكتروني.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The \'Date\' field of the e-mail.', array(), array('context' => ''));
  $translations['ar:default']['9d4c49b40cd8baa11e872a6ae8c39201'] = array(
    'source' => 'The full URL of the current page request.',
    'context' => '',
    'location' => '',
    'translation' => 'العنوان URL الكامل لطلب الصفحة الحالية.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The full URL of the current page request.', array(), array('context' => ''));
  $translations['ar:default']['9d65ae4246d70c132328d10033678e49'] = array(
    'source' => 'Lower case',
    'context' => '',
    'location' => '',
    'translation' => 'حروف صغيرة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Lower case', array(), array('context' => ''));
  $translations['ar:default']['9e227bf89226aa5759ea96de7a7f92f6'] = array(
    'source' => 'E-mail address <span>(never shared)</span>',
    'context' => '',
    'location' => '/ar/user/register',
    'translation' => 'البريد الإلكتروني <span>(لا تتم مشاركته أبداٌ) </span>',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('E-mail address <span>(never shared)</span>', array(), array('context' => ''));
  $translations['ar:default']['9e99bf59780cdc6507fb83605400e268'] = array(
    'source' => 'Has new content',
    'context' => '',
    'location' => '',
    'translation' => 'فيه محتوى جديد',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Has new content', array(), array('context' => ''));
  $translations['ar:default']['9ea2e2a7c7f03cbc798eceb2dd21069c'] = array(
    'source' => 'Hello !recipient_name,

!actor has changed report "!node_title"  status.',
    'context' => '',
    'location' => '/index.php',
    'translation' => 'مرحباً !recipient_name،

قام !actor بتغيير حالة هذا التقرير "!node_title" .',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Hello !recipient_name,

!actor has changed report "!node_title"  status.', array(), array('context' => ''));
  $translations['ar:default']['9f2de89369f7cb3e26773ed3091f0c9f'] = array(
    'source' => 'Remove all filters',
    'context' => '',
    'location' => '',
    'translation' => 'إزالة جميع الفلاتر',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Remove all filters', array(), array('context' => ''));
  $translations['ar:default']['9f3b01b0a5769cdeb2eb02426bf54745'] = array(
    'source' => 'Pen a headline and brief intro about the topic. Include a featured image, and start adding updates!',
    'context' => '',
    'location' => 'sites/all/modules/custom/checkdesk_core/js/tour/checkdesk-tour.js; sites/all/modules/custom/checkdesk_core/js/checkdesk_tour.js; sites/all/themes/checkdesk/assets/js/tour.js; sites/all/modules/custom/checkdesk_tour/js/tour.js',
    'translation' => 'اكتب عنوان الموضوع ومقدمة مختصرة. أضف صورة مختارة وابدأ بإضافة التحديثات!',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Pen a headline and brief intro about the topic. Include a featured image, and start adding updates!', array(), array('context' => ''));
  $translations['ar:default']['9f542b8f518c7e9119f9fb5a4814f5c6'] = array(
    'source' => 'PHP Code',
    'context' => '',
    'location' => '',
    'translation' => 'PHP Code',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('PHP Code', array(), array('context' => ''));
  $translations['ar:default']['9f7884f96ac8b4ef29a7ea56b354d0ba'] = array(
    'source' => 'Rendered @entity-type',
    'context' => '',
    'location' => '',
    'translation' => 'تم إصدار @entity-type',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Rendered @entity-type', array(), array('context' => ''));
  $translations['ar:default']['9fa984e816f2e22c70dc6916afae3cbf'] = array(
    'source' => 'Hello !recipient_name,

!author has added a new story !story.

<a href="!url">Click here </a> to view or update this story.
',
    'context' => '',
    'location' => '/index.php',
    'translation' => 'مرحباً !recipient_name, 

قام !author بإضافة موضوع جديد !story.

 <a href="!url"> اضغط هنا </a> لمعرفة أو تحديث هذا الموضوع.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Hello !recipient_name,

!author has added a new story !story.

<a href="!url">Click here </a> to view or update this story.
', array(), array('context' => ''));
  $translations['ar:default']['9fb17d168ec32414787e4f47ccd3812c'] = array(
    'source' => 'Attached files',
    'context' => '',
    'location' => '',
    'translation' => 'ملف مرفق',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Attached files', array(), array('context' => ''));
  $translations['ar:default']['9fe9f09793f82c6333c8477b239c2cd5'] = array(
    'source' => '<a class="actor" href="!user_url">!username</a> added an <a href="!update_url">update</a> to <a href="!story_url">!story</a>',
    'context' => '',
    'location' => '/ar/story/36',
    'translation' => '<a class="actor" href="!user_url">!username</a> أضاف <a href="!update_url">تحديثاً</a> للموضوع <a href="!story_url">!story</a>',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('<a class="actor" href="!user_url">!username</a> added an <a href="!update_url">update</a> to <a href="!story_url">!story</a>', array(), array('context' => ''));
  $translations['ar:default']['a0448ff71e1ef8ffc22797a82aba270a'] = array(
    'source' => 'A file that is associated with this user, usually because it is in a field on the user.',
    'context' => '',
    'location' => '',
    'translation' => 'ملف مقترن بالمستخدم ، عادة لأنه في حقل على المستخدم.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('A file that is associated with this user, usually because it is in a field on the user.', array(), array('context' => ''));
  $translations['ar:default']['a06798dc50935c327f7e7cfad562829f'] = array(
    'source' => 'The type of the item, either module, theme, or theme_engine.',
    'context' => '',
    'location' => '',
    'translation' => 'نوع من هذا البند، إما وحدة، والفكرة، أو theme_engine.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The type of the item, either module, theme, or theme_engine.', array(), array('context' => ''));
  $translations['ar:default']['a0e633512fa11e82abaadf76f99e62bb'] = array(
    'source' => '<strong>@user\'s</strong> reports',
    'context' => '',
    'location' => '/ar/user/4482',
    'translation' => 'تقارير <strong>@user</strong>',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('<strong>@user\'s</strong> reports', array(), array('context' => ''));
  $translations['ar:default']['a0e7642fb04ea92afc1d861f614fe75a'] = array(
    'source' => '- Any -',
    'context' => '',
    'location' => '',
    'translation' => '- أي -',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('- Any -', array(), array('context' => ''));
  $translations['ar:default']['a0ec87054b5e5b7847d0d8780a01a3d5'] = array(
    'source' => 'Sum',
    'context' => '',
    'location' => '',
    'translation' => 'المجموع',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Sum', array(), array('context' => ''));
  $translations['ar:default']['a130eb3c777b06c096fa972c0e7c0cf6'] = array(
    'source' => 'Flaggable user',
    'context' => '',
    'location' => '',
    'translation' => 'مستخدم قابل للتنبيه ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Flaggable user', array(), array('context' => ''));
  $translations['ar:default']['a14895f8ac0def38ae8567713e24f277'] = array(
    'source' => 'Turn on fact-checking',
    'context' => '',
    'location' => '',
    'translation' => 'تفعيل التحقق من صحة المعلومات',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Turn on fact-checking', array(), array('context' => ''));
  $translations['ar:default']['a14b5913b6d147220ff55c26e3b96520'] = array(
    'source' => 'Last comment author',
    'context' => '',
    'location' => '',
    'translation' => 'كاتب آخر تعليق',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Last comment author', array(), array('context' => ''));
  $translations['ar:default']['a1e0a77aed455d7980c81f3df282e997'] = array(
    'source' => 'Relate a content revision to the user who created the revision.',
    'context' => '',
    'location' => '',
    'translation' => 'تتعلق بمراجعة المحتوى للمستخدم الذي قام بإنشاء مراجعة.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Relate a content revision to the user who created the revision.', array(), array('context' => ''));
  $translations['ar:default']['a274f4d4670213a9045ce258c6c56b80'] = array(
    'source' => 'Notifications',
    'context' => '',
    'location' => 'sites/all/modules/custom/checkdesk_notifications/js/notifications_menu.js',
    'translation' => 'التنبيهات',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Notifications', array(), array('context' => ''));
  $translations['ar:default']['a28afdd5ece450079a5e62d539888b3a'] = array(
    'source' => 'The User ID of the comment\'s author.',
    'context' => '',
    'location' => '',
    'translation' => 'هوية المستخدم كاتب التعليق',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The User ID of the comment\'s author.', array(), array('context' => ''));
  $translations['ar:default']['a2aec0884e45e0b4646d84ba789d0002'] = array(
    'source' => 'Exposed form options',
    'context' => '',
    'location' => '',
    'translation' => 'إعدادات الاستمارة المكشوفة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Exposed form options', array(), array('context' => ''));
  $translations['ar:default']['a2c6642b2fce57be7d9063e8ee06b1d8'] = array(
    'source' => 'Do not pass admin strings for translation.',
    'context' => '',
    'location' => '',
    'translation' => 'لا تمرر سلاسل المشرف للترجمه',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Do not pass admin strings for translation.', array(), array('context' => ''));
  $translations['ar:default']['a2f3cafe558b203c53ece00d2aae9a07'] = array(
    'source' => 'Bring in data about the node being addressed.',
    'context' => '',
    'location' => '/ar',
    'translation' => 'جلب بيانات حول تعريف العقده',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Bring in data about the node being addressed.', array(), array('context' => ''));
  $translations['ar:default']['a324e673a1ee2b00ad5b6e1311f9ad24'] = array(
    'source' => 'No transform',
    'context' => '',
    'location' => '',
    'translation' => 'بدون تغيير',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('No transform', array(), array('context' => ''));
  $translations['ar:default']['a34320a85d88183ecc594b6a123a2677'] = array(
    'source' => 'Sort by whether entities have or have not been flagged.',
    'context' => '',
    'location' => '',
    'translation' => 'حسب ما إذا كان لديك أو كيانات لم تكن ترفع علم.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Sort by whether entities have or have not been flagged.', array(), array('context' => ''));
  $translations['ar:default']['a364d59e1108301501a9280484be32d2'] = array(
    'source' => 'User profile',
    'context' => '',
    'location' => '',
    'translation' => 'الملف الشخصي للمستخدم',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('User profile', array(), array('context' => ''));
  $translations['ar:default']['a38632fde688c278e1df03b3ffb3b41f'] = array(
    'source' => 'A <span class="checkdesk-slogan-logo">Checkdesk</span> Liveblog by <span class="checkdesk-slogan-partner">@partner</span>',
    'context' => '',
    'location' => '/ar/user',
    'translation' => 'مدونة <span class="checkdesk-slogan-logo">Checkdesk</span> مباشرة من <span class="checkdesk-slogan-partner">@partner</span>',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('A <span class="checkdesk-slogan-logo">Checkdesk</span> Liveblog by <span class="checkdesk-slogan-partner">@partner</span>', array(), array('context' => ''));
  $translations['ar:default']['a391fe1a385bc7b71dd5d013f4ecb28b'] = array(
    'source' => 'Access will be granted to users with the specified permission string.',
    'context' => '',
    'location' => '',
    'translation' => 'سيتم منح الوصول للمستخدمين مع سلسلة الإذن المحدد.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Access will be granted to users with the specified permission string.', array(), array('context' => ''));
  $translations['ar:default']['a3eca0388071827f8138c7f4b2b7f1f5'] = array(
    'source' => 'No results behavior',
    'context' => '',
    'location' => '',
    'translation' => 'No results behavior',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('No results behavior', array(), array('context' => ''));
  $translations['ar:default']['a4532350f25675a952b1908dcb0655c1'] = array(
    'source' => 'Display all items',
    'context' => '',
    'location' => '',
    'translation' => 'عرض كافة العناصر ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Display all items', array(), array('context' => ''));
  $translations['ar:default']['a4595a95c6a3b954eb1fe6d567a4982c'] = array(
    'source' => 'Report suggested to story',
    'context' => '',
    'location' => '/ar',
    'translation' => 'اقتراح تقرير لإدراجه ضمن موضوع',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Report suggested to story', array(), array('context' => ''));
  $translations['ar:default']['a47ce07b552bc9a528d15a63f34080ed'] = array(
    'source' => '<span>1</span> result. You can drag and drop it.',
    'context' => '',
    'location' => '/ar/node/add/post?sort_order=DESC&title=universidade&title_op=contains&source=&source_op=contains; sites/all/themes/checkdesk/assets/js/report.js',
    'translation' => '<span>1</span> نتيجة. يمكنك سحب التقرير واستخدامه.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('<span>1</span> result. You can drag and drop it.', array(), array('context' => ''));
  $translations['ar:default']['a487130ef4a3a4a9575fac6e554e86e3'] = array(
    'source' => 'You will be notified here when users submit reports to a story, or flag published reports for fact-checking.',
    'context' => '',
    'location' => 'sites/all/modules/custom/checkdesk_core/js/tour/checkdesk-tour.js; sites/all/modules/custom/checkdesk_core/js/checkdesk_tour.js; sites/all/themes/checkdesk/assets/js/tour.js',
    'translation' => 'ستظهر التنبيهات هنا عندما يرسل المستخدمون تقريراً لموضوع معين، أو يطلبون التحقق من صحة المعلومات.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('You will be notified here when users submit reports to a story, or flag published reports for fact-checking.', array(), array('context' => ''));
  $translations['ar:default']['a4f11f7a14f41cd7c3486e6d42be355b'] = array(
    'source' => 'Update a Story',
    'context' => '',
    'location' => '/ar/user',
    'translation' => 'قم بتحديث الموضوع',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Update a Story', array(), array('context' => ''));
  $translations['ar:default']['a500c56fbcf63dc1a33fc8726b5fdb53'] = array(
    'source' => 'Flagged time',
    'context' => '',
    'location' => '',
    'translation' => 'وقت تحذير المشرف',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Flagged time', array(), array('context' => ''));
  $translations['ar:default']['a53fb706552a60af2c243a54e2263dee'] = array(
    'source' => 'filter criterion',
    'context' => '',
    'location' => '',
    'translation' => 'filter criterion',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('filter criterion', array(), array('context' => ''));
  $translations['ar:default']['a5662e78a477cfd4d7ab4bfdd80039da'] = array(
    'source' => 'Submit Report',
    'context' => '',
    'location' => '/ar/user',
    'translation' => 'أضف تقريراً',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Submit Report', array(), array('context' => ''));
  $translations['ar:default']['a56cf4bed42ec135fd8fb697b8e72e50'] = array(
    'source' => 'Better Exposed Filters',
    'context' => '',
    'location' => '',
    'translation' => 'Better Exposed Filters',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Better Exposed Filters', array(), array('context' => ''));
  $translations['ar:default']['a6af0fec6f2a41469733524357bbfe92'] = array(
    'source' => 'And/Or, Rearrange',
    'context' => '',
    'location' => '',
    'translation' => 'أو/و، إعادة الترتيب',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('And/Or, Rearrange', array(), array('context' => ''));
  $translations['ar:default']['a6b98cd3261325359c64d9b1b60f6534'] = array(
    'source' => 'Automatically update preview on changes',
    'context' => '',
    'location' => '',
    'translation' => 'تحديث المعاينة تلقائيا عند التغيير',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Automatically update preview on changes', array(), array('context' => ''));
  $translations['ar:default']['a6d5461a6302d7fc14f55fc703408795'] = array(
    'source' => 'Hello !recipient_name,

A <a href="!report_url">report</a> which you have submitted has been published in an <a href="!node_url">update</a>.

You can edit your notification settings from your <a href="!recipient_url">profile page</a>.

This was an auto-generated email from !site; please do not respond directly to this email.',
    'context' => '',
    'location' => '/meedan/meedan-checkdesk/drupal/index.php',
    'translation' => 'مرحباً !recipient_name،

تم نشر <a href="!report_url">التقرير</a> الذي أرسلته في <a href="!node_url">تحديث</a> جديد.

بإمكانك تعديل إعدادات التنبيهات الخاصة بك من صفحة <a href="!recipient_url">الحساب الشخصي</a> الخاصة بك.

هذه رسالة مولدة بشكل تلقائي من !site، يرجى عدم الرد على هذه الرسالة.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Hello !recipient_name,

A <a href="!report_url">report</a> which you have submitted has been published in an <a href="!node_url">update</a>.

You can edit your notification settings from your <a href="!recipient_url">profile page</a>.

This was an auto-generated email from !site; please do not respond directly to this email.', array(), array('context' => ''));
  $translations['ar:default']['a70bf5b15f959872a625d3adfcbf7781'] = array(
    'source' => 'New update',
    'context' => '',
    'location' => '/index.php',
    'translation' => 'تحديث جديد',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('New update', array(), array('context' => ''));
  $translations['ar:default']['a7967160b9cad0eec7927abe41b2da42'] = array(
    'source' => 'Taxonomy terms are used for classifying content.',
    'context' => '',
    'location' => '',
    'translation' => 'حيث يتم استخدام التصنيف لتصنيف المحتوى.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Taxonomy terms are used for classifying content.', array(), array('context' => ''));
  $translations['ar:default']['a7eebe34180ee2ee0e116dd4a9b90af2'] = array(
    'source' => 'Scheduled Rules components that are executed based on time and cron',
    'context' => '',
    'location' => '/ar',
    'translation' => 'المقرر قوانين المكونات التي يتم تنفيذها بناء على الوقت وكرون',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Scheduled Rules components that are executed based on time and cron', array(), array('context' => ''));
  $translations['ar:default']['a8190ecc778bd938e7e402fc77c0df07'] = array(
    'source' => 'Vocabularies contain related taxonomy terms, which are used for classifying content.',
    'context' => '',
    'location' => '',
    'translation' => 'مفردات تحتوي على شروط تتعلق بالتصنيف، والتي تستخدم لتصنيف المحتوى.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Vocabularies contain related taxonomy terms, which are used for classifying content.', array(), array('context' => ''));
  $translations['ar:default']['a82be0f551b8708bc08eb33cd9ded0cf'] = array(
    'source' => 'Information',
    'context' => '',
    'location' => '',
    'translation' => 'معلومات',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Information', array(), array('context' => ''));
  $translations['ar:default']['a838e5e26d7b0764692c9885bff79a34'] = array(
    'source' => 'A taxonomy term that is associated with this file, usually because this file is in a field on the taxonomy term.',
    'context' => '',
    'location' => '',
    'translation' => 'مصطلح التصنيف مقترن بهذا الملف، لأن هذا الملف عادة في حقل على مصطلح التصنيف.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('A taxonomy term that is associated with this file, usually because this file is in a field on the taxonomy term.', array(), array('context' => ''));
  $translations['ar:default']['a83a231380fed31ae6c508f3a52ad8e5'] = array(
    'source' => 'Relate nodes to taxonomy terms, specifiying which vocabulary or vocabularies to use. This relationship will cause duplicated records if there are multiple terms.',
    'context' => '',
    'location' => '',
    'translation' => 'تتصل العقد على شروط التصنيف، specifiying التي المفردات أو استخدام المفردات. وهذه العلاقة يسبب تكرار السجلات في حالة وجود شروط متعددة.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Relate nodes to taxonomy terms, specifiying which vocabulary or vocabularies to use. This relationship will cause duplicated records if there are multiple terms.', array(), array('context' => ''));
  $translations['ar:default']['a843fd5f0855c590fb21c9d91e6a5cf5'] = array(
    'source' => 'Provide a simple link to edit the content.',
    'context' => '',
    'location' => '',
    'translation' => 'تقديم وصلة بسيطة لتحرير المحتوى.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Provide a simple link to edit the content.', array(), array('context' => ''));
  $translations['ar:default']['a87cf9e9eeb45555e6b3c13002d15f28'] = array(
    'source' => 'Bring in data about the user being addressed.',
    'context' => '',
    'location' => '/ar',
    'translation' => 'جلب بيانات حول المستخدم المعرف',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Bring in data about the user being addressed.', array(), array('context' => ''));
  $translations['ar:default']['a88a7634ef70dd3aa8cf7927e5ea7e14'] = array(
    'source' => 'View incoming citizen reports',
    'context' => '',
    'location' => '',
    'translation' => 'عرض التقارير الواردة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('View incoming citizen reports', array(), array('context' => ''));
  $translations['ar:default']['a8a5e0404bb9fe6796c746deb319387f'] = array(
    'source' => '@counth',
    'context' => '',
    'location' => '/checkdesk/ar',
    'translation' => '@countسا',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('@counth', array(), array('context' => ''));
  $translations['ar:default']['a8c8a4d254b6dc6f300c63e45288b422'] = array(
    'source' => 'The description of the Twitter account.',
    'context' => '',
    'location' => '',
    'translation' => 'حساب تسجيل الدخول للمستخدم تويتر.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The description of the Twitter account.', array(), array('context' => ''));
  $translations['ar:default']['a8dd148dd7601a6f54dc10a64dfc1c27'] = array(
    'source' => 'All taxonomy terms',
    'context' => '',
    'location' => '',
    'translation' => 'جميع مصطلحات التصنيف',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('All taxonomy terms', array(), array('context' => ''));
  $translations['ar:default']['a919a968a1bf0bfc2fb9aeff69f06300'] = array(
    'source' => '(Linked account)',
    'context' => '',
    'location' => '/ar/node/add/discussion',
    'translation' => '(حساب مرتبط)',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('(Linked account)', array(), array('context' => ''));
  $translations['ar:default']['a981fa6d40cc987dab1166dc59b347a5'] = array(
    'source' => 'Log message',
    'context' => '',
    'location' => '',
    'translation' => 'رسالة السجل',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Log message', array(), array('context' => ''));
  $translations['ar:default']['a995fa1e9ab46c0b0df121a81675150e'] = array(
    'source' => '<a class="actor" href="!editor_url">!editor</a> changed <a href="!report_url">report</a> status to !status',
    'context' => '',
    'location' => '/ar',
    'translation' => '<a class="actor" href="!editor_url">!editor</a> غيّر حالة<a href="!report_url"> التقربر</a> إلى !status',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('<a class="actor" href="!editor_url">!editor</a> changed <a href="!report_url">report</a> status to !status', array(), array('context' => ''));
  $translations['ar:default']['a9a784bb8330097e7b3673fe29a30b9c'] = array(
    'source' => 'Provide markup text for the area.',
    'context' => '',
    'location' => '',
    'translation' => 'توفر النص توصيف للمنطقة.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Provide markup text for the area.', array(), array('context' => ''));
  $translations['ar:default']['a9c0267144d01f9c65a532c37f672ceb'] = array(
    'source' => 'Update user alias',
    'context' => '',
    'location' => '',
    'translation' => 'حدّث اسم المستخدم',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Update user alias', array(), array('context' => ''));
  $translations['ar:default']['a9cdbc6d19884d7715cfc07654008fe9'] = array(
    'source' => 'Updated/commented date',
    'context' => '',
    'location' => '',
    'translation' => 'تحديث تاريخ التعليق ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Updated/commented date', array(), array('context' => ''));
  $translations['ar:default']['a9d4effb8f2bd07807ba263dc8df27fd'] = array(
    'source' => 'The title of the link.',
    'context' => '',
    'location' => '',
    'translation' => 'عنوان الرابط',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The title of the link.', array(), array('context' => ''));
  $translations['ar:default']['a9da1f71c31952705fcb27c2a4326738'] = array(
    'source' => 'Existing story updated',
    'context' => '',
    'location' => '/ar',
    'translation' => 'تحرير موضوع منشور',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Existing story updated', array(), array('context' => ''));
  $translations['ar:default']['a9dc8e0fff2461a872c47678b7d5ae7e'] = array(
    'source' => 'Currently @date in !city, !country.',
    'context' => '',
    'location' => '',
    'translation' => 'حالياً @date في !city، !country',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Currently @date in !city, !country.', array(), array('context' => ''));
  $translations['ar:default']['aa37bd770e5585ac302cdb81d8b5fb70'] = array(
    'source' => 'Sign in with Twitter',
    'context' => '',
    'location' => '',
    'translation' => 'تسجيل الدخول باستخدام تويتر',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Sign in with Twitter', array(), array('context' => ''));
  $translations['ar:default']['aa71cee30bdfded18dac91d31ed57e75'] = array(
    'source' => 'Whether comments are enabled or disabled on the node.',
    'context' => '',
    'location' => '',
    'translation' => 'ما إذا كان  التعليق ممكن او غير ممكن على العقده ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Whether comments are enabled or disabled on the node.', array(), array('context' => ''));
  $translations['ar:default']['aa726ccd8785ceaba9a4efbb288d160d'] = array(
    'source' => 'Sorry, Facebook won\'t allow you to re-post content that isn\'t public. Try using a publicly accessible post, or request that your friend make the post public on Facebook.',
    'context' => '',
    'location' => '/ar/node/add/post',
    'translation' => 'عذراً، فيسبوك لا يسمح لك بإعادة نشر المواد الخاصة. يرجى أن تستخدم مادة علنية أو أن تطلب من صديقك أن يجعل المادة التي تريد نشرها متوفرة بشكل علني.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Sorry, Facebook won\'t allow you to re-post content that isn\'t public. Try using a publicly accessible post, or request that your friend make the post public on Facebook.', array(), array('context' => ''));
  $translations['ar:default']['aaaa3c0a0086a0eedaf3350d3cfe92c1'] = array(
    'source' => 'Items per page',
    'context' => '',
    'location' => '',
    'translation' => 'العناصر في كل صفحة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Items per page', array(), array('context' => ''));
  $translations['ar:default']['aabf2431bef947fade90ca6dede2161d'] = array(
    'source' => 'Store a date in the database as an ISO date, recommended for historical or partial dates.',
    'context' => '',
    'location' => '',
    'translation' => 'تخزين التاريخ في قاعدة البيانات كما موعد ISO، وأوصت لتواريخ تاريخية أو جزئية.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Store a date in the database as an ISO date, recommended for historical or partial dates.', array(), array('context' => ''));
  $translations['ar:default']['aadecd85e1eca293143e07c5c665177e'] = array(
    'source' => 'Insert a view inside an area.',
    'context' => '',
    'location' => '',
    'translation' => 'إدراج وجهة نظر داخل المنطقة.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Insert a view inside an area.', array(), array('context' => ''));
  $translations['ar:default']['ab36d220dc05a11ea5df07ac1e98ab01'] = array(
    'source' => 'Hello !recipient_name,

Story "!title" which you followed has a <a href="!url">new update</a>.

You can edit your notification settings from your <a href="!recipient_url">profile page</a>.

This was an auto-generated email from !site; please do not respond directly to this email.',
    'context' => '',
    'location' => '/index.php',
    'translation' => 'مرحباً !recipient_name،

 تم إضافة <a href="!url">تحديث جديد</a>  لموضوع متابع "!title" .

بإمكانك تعديل إعدادات التنبيهات الخاصة بك من صفحة <a href="!recipient_url">الحساب الشخصي</a> الخاصة بك.

هذه رسالة مولدة بشكل تلقائي من !site، يرجى عدم الرد على هذه الرسالة.
',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Hello !recipient_name,

Story "!title" which you followed has a <a href="!url">new update</a>.

You can edit your notification settings from your <a href="!recipient_url">profile page</a>.

This was an auto-generated email from !site; please do not respond directly to this email.', array(), array('context' => ''));
  $translations['ar:default']['ab4705beb0922152da0fcbb94eaafdca'] = array(
    'source' => 'All parent terms',
    'context' => '',
    'location' => '',
    'translation' => 'جميع المصطلحات الام ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('All parent terms', array(), array('context' => ''));
  $translations['ar:default']['ab7cb98473ea152bb1ac81191f621bee'] = array(
    'source' => 'On site: ',
    'context' => '',
    'location' => '/ar',
    'translation' => 'على الموقع: ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('On site: ', array(), array('context' => ''));
  $translations['ar:default']['abf45282aeeaaf5247b0024b49c5ad7e'] = array(
    'source' => 'Remove from queue',
    'context' => '',
    'location' => '',
    'translation' => 'إزالة من القائمة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Remove from queue', array(), array('context' => ''));
  $translations['ar:default']['ac1fbce25a0d31c7290525dcd74cdb4d'] = array(
    'source' => 'Provide title',
    'context' => '',
    'location' => '',
    'translation' => 'توفير عنوان',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Provide title', array(), array('context' => ''));
  $translations['ar:default']['ac67ede5a84eb5a1add7ff4440e9a485'] = array(
    'source' => 'required',
    'context' => '',
    'location' => '/ar/user/register',
    'translation' => 'مطلوب ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('required', array(), array('context' => ''));
  $translations['ar:default']['ac71d8452c267207bcf9f1c93c6419e8'] = array(
    'source' => 'Newest',
    'context' => '',
    'location' => '/ar/search?field_tags_tid=1327',
    'translation' => 'الأحدث',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Newest', array(), array('context' => ''));
  $translations['ar:default']['aca111b03c221b4e02a19cd527775c61'] = array(
    'source' => 'Referenced Entity',
    'context' => '',
    'location' => '',
    'translation' => 'الكيان المشار إليه',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Referenced Entity', array(), array('context' => ''));
  $translations['ar:default']['acb2783ca7decaceb39c10ecebc5287d'] = array(
    'source' => 'Simple (with optional filter by bundle)',
    'context' => '',
    'location' => '',
    'translation' => 'بسيطة مع فلتر اختياري من قبل حزمة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Simple (with optional filter by bundle)', array(), array('context' => ''));
  $translations['ar:default']['acdb16b45137f9a153b05d4699b889aa'] = array(
    'source' => 'Hello !recipient_name,

!actor has turned on fact-checking for a <a href="!url">report</a> .',
    'context' => '',
    'location' => '/index.php',
    'translation' => 'مرحباً !recipient_name،

قام !actor بتفعيل التحقق من صحة المعلومات لهذا <a href="!url">التقرير</a>.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Hello !recipient_name,

!actor has turned on fact-checking for a <a href="!url">report</a> .', array(), array('context' => ''));
  $translations['ar:default']['acef393abfae25dd69f35dc50bda3b9d'] = array(
    'source' => 'Whether saving this node creates a new revision.',
    'context' => '',
    'location' => '',
    'translation' => 'سواء إنقاذ هذه العقدة يخلق تنقيح جديد.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Whether saving this node creates a new revision.', array(), array('context' => ''));
  $translations['ar:default']['acfa4546121d8dd1013723e5bf164071'] = array(
    'source' => 'Meedan oEmbed filter',
    'context' => '',
    'location' => '/ar',
    'translation' => 'ميدان تصفية oEmbed',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Meedan oEmbed filter', array(), array('context' => ''));
  $translations['ar:default']['ad4e1d81af78b2418d7b99c538d8b5b0'] = array(
    'source' => 'Displays rows in a grid.',
    'context' => '',
    'location' => '',
    'translation' => 'يعرض الصفوف في الشبكة.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Displays rows in a grid.', array(), array('context' => ''));
  $translations['ar:default']['ad513e4f467bdbd8b7e6a7ed511f7fa3'] = array(
    'source' => 'Close Window',
    'context' => '',
    'location' => '',
    'translation' => 'أغلق النافذة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Close Window', array(), array('context' => ''));
  $translations['ar:default']['ad59a52e4c74b7388e32b8dcccf3fed4'] = array(
    'source' => 'Max nodes',
    'context' => '',
    'location' => '',
    'translation' => 'الحد الأقصى',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Max nodes', array(), array('context' => ''));
  $translations['ar:default']['adfe01e03e975b02a325e7bf335c722e'] = array(
    'source' => 'If you need more fields than the uid add the comment: author relationship',
    'context' => '',
    'location' => '',
    'translation' => 'إذا كنت بحاجة إلى المزيد من المجالات من إضافة تعليق UID: علاقة المؤلف',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('If you need more fields than the uid add the comment: author relationship', array(), array('context' => ''));
  $translations['ar:default']['ae07246fa724b5920065e22077d8c090'] = array(
    'source' => '<p><strong><a href="!user_url">!username</a></strong> has changed the fact-checking status for a <strong><a href="!report_url">report</a></strong> you submitted to <strong>!fact_checking_status</strong></p>',
    'context' => '',
    'location' => '',
    'translation' => '<p>لقد عدّل <strong><a href="!user_url">!username</a></strong> حالة التحقق لدى <strong><a href="!report_url">تقريرك</a></strong> إلى <strong>!fact_checking_status</strong></p>',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('<p><strong><a href="!user_url">!username</a></strong> has changed the fact-checking status for a <strong><a href="!report_url">report</a></strong> you submitted to <strong>!fact_checking_status</strong></p>', array(), array('context' => ''));
  $translations['ar:default']['ae105885430d5d637a855a20b8c588a1'] = array(
    'source' => 'Incoming Reports',
    'context' => '',
    'location' => '',
    'translation' => 'التقارير الواردة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Incoming Reports', array(), array('context' => ''));
  $translations['ar:default']['ae590c0423e6f2b19ff721f75dd69900'] = array(
    'source' => 'The parent term of the term.',
    'context' => '',
    'location' => '',
    'translation' => 'The parent term of the term.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The parent term of the term.', array(), array('context' => ''));
  $translations['ar:default']['ae766c52d24c1f3978ad7ecd07f8745e'] = array(
    'source' => 'Entity Reference',
    'context' => '',
    'location' => '',
    'translation' => 'الكيان المرجعي',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Entity Reference', array(), array('context' => ''));
  $translations['ar:default']['aebaa13c501bcad7dae3a08ca3192dfe'] = array(
    'source' => 'Add headline',
    'context' => '',
    'location' => '',
    'translation' => 'أضف عنوان',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Add headline', array(), array('context' => ''));
  $translations['ar:default']['aefdfe63621d0cfedbd1628185b9b3bd'] = array(
    'source' => 'Use Drupal core t() function. Not recommended, as it doesn\'t support updates to existing strings.',
    'context' => '',
    'location' => '',
    'translation' => 'Use Drupal core t() function. Not recommended, as it doesn\'t support updates to existing strings.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Use Drupal core t() function. Not recommended, as it doesn\'t support updates to existing strings.', array(), array('context' => ''));
  $translations['ar:default']['af07ea0d50ed8cbb5a3f147085866792'] = array(
    'source' => 'Edit description',
    'context' => '',
    'location' => '/ar/node/add/media?meedan_bookmarklet=1&meedan_bookmarklet_prepopulate[body]=%D8%A3%D8%AE%D8%A8%D8%A7%D8%B1%20|%20Meedan%20Checkdesk&meedan_bookmarklet_prepopulate[field_link]=http://qa.checkdesk.org/ar',
    'translation' => 'حرر الوصف',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Edit description', array(), array('context' => ''));
  $translations['ar:default']['af7c1edfee7bdc1f8e9ef7b7fa5377ad'] = array(
    'source' => 'Reports flagged as spam cannot be unflagged.',
    'context' => '',
    'location' => '/ar/liveblog',
    'translation' => 'لا يمكن إلغاء تنبيه المشرف على التقارير التي صنفتها كسبام (سخام).',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Reports flagged as spam cannot be unflagged.', array(), array('context' => ''));
  $translations['ar:default']['aff68a5a38953a62748b240971fd8028'] = array(
    'source' => 'Checkdesk Reports',
    'context' => '',
    'location' => '/checkdesk/ar/admin/meedan/reports',
    'translation' => 'تقارير تشك دسك',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Checkdesk Reports', array(), array('context' => ''));
  $translations['ar:default']['aff98cd42460859e99447afb1831872a'] = array(
    'source' => 'Rearrange',
    'context' => '',
    'location' => '',
    'translation' => 'أعد الترتيب',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Rearrange', array(), array('context' => ''));
  $translations['ar:default']['b10b8bdfffa84e0f75fc4501b6b666f1'] = array(
    'source' => 'Check your e-mail to confirm your account',
    'context' => '',
    'location' => '/ar/user/register',
    'translation' => 'تحقق من بريدك الإلكتروني لتفعّل حسابك',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Check your e-mail to confirm your account', array(), array('context' => ''));
  $translations['ar:default']['b10e24496ff8fec66189548a92a67045'] = array(
    'source' => 'Infinite',
    'context' => '',
    'location' => '',
    'translation' => 'لا نهائي',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Infinite', array(), array('context' => ''));
  $translations['ar:default']['b12f9025f7cb70c5d73a4d0f3147cc6c'] = array(
    'source' => 'The tag \'@term\' will be added.',
    'context' => '',
    'location' => '/ar/node/add/discussion',
    'translation' => 'سوف يتم إضافة المصطلح \'@term\'',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The tag \'@term\' will be added.', array(), array('context' => ''));
  $translations['ar:default']['b16f3e39aa6c0a2257a55fd0a873a4fc'] = array(
    'source' => 'Short, as link with title "Link"',
    'context' => '',
    'location' => '',
    'translation' => 'Short, as link with title "Link"',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Short, as link with title "Link"', array(), array('context' => ''));
  $translations['ar:default']['b181c43993de481ea462a2bfe11f0a1b'] = array(
    'source' => 'Cairo',
    'context' => '',
    'location' => '/meedan/meedan-checkdesk/drupal/ar/node/15692',
    'translation' => 'القاهرة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Cairo', array(), array('context' => ''));
  $translations['ar:default']['b1897515d548a960afe49ecf66a29021'] = array(
    'source' => 'Average',
    'context' => '',
    'location' => '',
    'translation' => 'متوسط',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Average', array(), array('context' => ''));
  $translations['ar:default']['b18c866be19aa3e85b34e3a37c3ec05c'] = array(
    'source' => 'View result counter',
    'context' => '',
    'location' => '',
    'translation' => 'عرض عداد النتيجة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('View result counter', array(), array('context' => ''));
  $translations['ar:default']['b1a354a45cfa77e27eb8ab0c37a6a3f3'] = array(
    'source' => 'Access will be granted to users with any of the specified roles.',
    'context' => '',
    'location' => '',
    'translation' => 'سيتم منح الوصول  للمستخدمين مع أي من الأدوار المحددة.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Access will be granted to users with any of the specified roles.', array(), array('context' => ''));
  $translations['ar:default']['b202a8fcff391bf8ea52e8ff76ead85e'] = array(
    'source' => 'Provide a simple link to cancel the user.',
    'context' => '',
    'location' => '',
    'translation' => 'ضع وصلة بسيطة لإلغاء المستخدم.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Provide a simple link to cancel the user.', array(), array('context' => ''));
  $translations['ar:default']['b2642bccc109595873d249d8735497a6'] = array(
    'source' => 'Save as draft',
    'context' => '',
    'location' => '',
    'translation' => 'احفظ مسودة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Save as draft', array(), array('context' => ''));
  $translations['ar:default']['b2c93b15ea09dc70240c044f1cdce63d'] = array(
    'source' => 'Information menu',
    'context' => '',
    'location' => '/ar',
    'translation' => 'معلومات القائمة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Information menu', array(), array('context' => ''));
  $translations['ar:default']['b2dbb1fc1f4005cab4b00f3a8dea684b'] = array(
    'source' => '<a href="[node:url:unaliased]">[node:author]\'s report</a> was flagged for deletion.',
    'context' => '',
    'location' => '/checkdesk/ar/node/flag/confirm/flag/delete/2453/ajax',
    'translation' => 'تم تنبيه المشرف لحذف <a href="[node:url:unaliased]"> تقرير [node:author] </a>.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('<a href="[node:url:unaliased]">[node:author]\'s report</a> was flagged for deletion.', array(), array('context' => ''));
  $translations['ar:default']['b3269346fdd2abc9437ba233fee5d15f'] = array(
    'source' => 'A liveblog post.',
    'context' => '',
    'location' => '/ar',
    'translation' => 'مقالة على المدونة المباشرة.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('A liveblog post.', array(), array('context' => ''));
  $translations['ar:default']['b3390ceed0a956631a2a49dc19c3342a'] = array(
    'source' => 'Add Twitter accounts',
    'context' => '',
    'location' => '/ar/modal/ajax/content/%D8%AA%D9%86%D8%B5%D9%8A%D8%A8-%D8%A5%D8%B6%D8%A7%D9%81%D8%A9-%D8%A7%D9%84%D9%85%D8%AA%D8%B5%D9%81%D8%AD',
    'translation' => 'أضف حسابات تويتر',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Add Twitter accounts', array(), array('context' => ''));
  $translations['ar:default']['b343ee5148968e3bfe5b4025bea8aacc'] = array(
    'source' => '<p><strong><a href="!user_url">!username</a></strong> has turned on fact-checking for a <strong><a href="!report_url">report</a></strong> you submitted</p>',
    'context' => '',
    'location' => '',
    'translation' => '<p>لقد فعل <strong><a href="!user_url">!username</a></strong> التحقق من صحة المعلومات لدى <strong><a href="!report_url">تقريرك</a></strong>.</p>
',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('<p><strong><a href="!user_url">!username</a></strong> has turned on fact-checking for a <strong><a href="!report_url">report</a></strong> you submitted</p>', array(), array('context' => ''));
  $translations['ar:default']['b35d3191d8e15a07fd55cc4ad1b68a20'] = array(
    'source' => 'Name (raw)',
    'context' => '',
    'location' => '',
    'translation' => 'اسم (الخام)',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Name (raw)', array(), array('context' => ''));
  $translations['ar:default']['b3b60b7a5e7f9977461d42a94bf2c761'] = array(
    'source' => 'Created date',
    'context' => '',
    'location' => '',
    'translation' => 'تاريخ الإنشاء',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Created date', array(), array('context' => ''));
  $translations['ar:default']['b3bede4a591aff48611fb65340bedf88'] = array(
    'source' => 'Updated at ',
    'context' => '',
    'location' => '/ar/story/%D8%A7%D9%84%D8%B4%D8%B9%D8%A8-%D9%8A%D8%B1%D9%8A%D8%AF-%D8%A5%D9%82%D8%A7%D9%84%D8%A9%D8%A7%D9%84%D9%88%D8%B2%D9%8A%D8%B1-%D8%A7%D9%84%D9%85%D8%AA%D8%AD%D8%B1%D8%B4',
    'translation' => 'آخر تحديث ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Updated at ', array(), array('context' => ''));
  $translations['ar:default']['b3c30cba88d63f6f7832b8438185db94'] = array(
    'source' => 'Hello !recipient_name,

Story "!title" which you followed has a <a href="!url">new update</a>.',
    'context' => '',
    'location' => '/index.php',
    'translation' => 'مرحباً !recipient_name،

 تم إضافة <a href="!url">تحديث جديد</a>  لموضوع متابع "!title" .
',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Hello !recipient_name,

Story "!title" which you followed has a <a href="!url">new update</a>.', array(), array('context' => ''));
  $translations['ar:default']['b3cbb92204212724a1cef5d1e8c2354a'] = array(
    'source' => 'Cannot rename %table to %table_new: table %table_new already exists.',
    'context' => '',
    'location' => '',
    'translation' => 'لا يمكن إعادة تسمية الجدول %table إلى %table_new : الجدول %table_new موجود مسبقا.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Cannot rename %table to %table_new: table %table_new already exists.', array(), array('context' => ''));
  $translations['ar:default']['b4d2551a80a816e681d18f3473a87817'] = array(
    'source' => 'Show only content that is new or updated.',
    'context' => '',
    'location' => '',
    'translation' => 'عرض المحتوى فقط ما هو جديد أو تحديث.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Show only content that is new or updated.', array(), array('context' => ''));
  $translations['ar:default']['b4e7219ac5ff3182191461f648694dbc'] = array(
    'source' => 'Turn off fact-checking',
    'context' => '',
    'location' => '',
    'translation' => 'إلغاء التحقق من صحة المعلومات',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Turn off fact-checking', array(), array('context' => ''));
  $translations['ar:default']['b54c9d4daccc9a6f489c2209348432aa'] = array(
    'source' => 'Changed status to ',
    'context' => '',
    'location' => '/',
    'translation' => 'غيّر الحالة إلى ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Changed status to ', array(), array('context' => ''));
  $translations['ar:default']['b55e509c697e4cca0e1d160a7806698f'] = array(
    'source' => 'Hour',
    'context' => '',
    'location' => '',
    'translation' => 'الساعة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Hour', array(), array('context' => ''));
  $translations['ar:default']['b57382dfeb88bbe1c199e82ae4503e47'] = array(
    'source' => 'Hello !recipient_name,

!actor has added a new report "!node_title" to this story "!story_title".

Go to !story_url to compose a new update to the story using that report.',
    'context' => '',
    'location' => '/index.php',
    'translation' => 'مرحباً !recipient_name،

قام !actor بإضافة تقرير جديد "!node_title" إلى هذا الموضوع "!story_title".

<a href="!story_url">اضغط هنا</a> لكتابة تحديث جديد على ذلك الخبر باستخدام ذاك التقرير.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Hello !recipient_name,

!actor has added a new report "!node_title" to this story "!story_title".

Go to !story_url to compose a new update to the story using that report.', array(), array('context' => ''));
  $translations['ar:default']['b5ca46625fd570744643befe7c73679c'] = array(
    'source' => '@count Comments (Be the first!)',
    'context' => '',
    'location' => '/checkdesk/ar',
    'translation' => 'التعليقات 0 (أضف تعليقك!)',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('@count Comments (Be the first!)', array(), array('context' => ''));
  $translations['ar:default']['b5e4a71c2db71f5e2a42c43b02f39657'] = array(
    'source' => 'Interface language',
    'context' => '',
    'location' => '',
    'translation' => 'واجهة اللغة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Interface language', array(), array('context' => ''));
  $translations['ar:default']['b62f0b9e8181466783dfd7ef791d9a73'] = array(
    'source' => 'Complete Your Profile',
    'context' => '',
    'location' => '/ar/user',
    'translation' => 'أكمل ملفك الشخصي',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Complete Your Profile', array(), array('context' => ''));
  $translations['ar:default']['b6385392862119f3df0acbbb2cd9db36'] = array(
    'source' => 'Representative node',
    'context' => '',
    'location' => '/ar',
    'translation' => 'عقدة ممثله',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Representative node', array(), array('context' => ''));
  $translations['ar:default']['b63bc6c033363c8ee66beaf4ea4d5bc3'] = array(
    'source' => 'Author\'s website',
    'context' => '',
    'location' => '',
    'translation' => 'موقع الكاتب',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Author\'s website', array(), array('context' => ''));
  $translations['ar:default']['b654546df4ebb62a392730e0b0f4e087'] = array(
    'source' => 'Draft stories',
    'context' => '',
    'location' => '/ar/search?type=update&status=0',
    'translation' => 'موضوعات غير منشورة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Draft stories', array(), array('context' => ''));
  $translations['ar:default']['b6789ee62b48435545654a6aa13b39b7'] = array(
    'source' => 'Show reports with this keyword',
    'context' => '',
    'location' => '',
    'translation' => 'اعرض تقارير تحوي هذه الكلمة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Show reports with this keyword', array(), array('context' => ''));
  $translations['ar:default']['b6967e02cd075afa2c640f4da5c3e05e'] = array(
    'source' => '1 update',
    'context' => '',
    'location' => '/ar/search?field_tags_tid=All&type=discussion',
    'translation' => '1 تحديث',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('1 update', array(), array('context' => ''));
  $translations['ar:default']['b6a8ba8de426ed66c0d6622bfff30d1b'] = array(
    'source' => 'Updated year',
    'context' => '',
    'location' => '',
    'translation' => 'تم تحديث العام',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Updated year', array(), array('context' => ''));
  $translations['ar:default']['b6c91c8f6bbf6beecb6a3dfadaee0939'] = array(
    'source' => 'Created day',
    'context' => '',
    'location' => '',
    'translation' => 'يوم الإنشاء',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Created day', array(), array('context' => ''));
  $translations['ar:default']['b6d4223e60986fa4c9af77ee5f7149c5'] = array(
    'source' => 'Sign in',
    'context' => '',
    'location' => '/ar/modal/ajax/content/%D8%AA%D9%86%D8%B5%D9%8A%D8%A8-%D8%A5%D8%B6%D8%A7%D9%81%D8%A9-%D8%A7%D9%84%D9%85%D8%AA%D8%B5%D9%81%D8%AD',
    'translation' => 'تسجيل الدخول',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Sign in', array(), array('context' => ''));
  $translations['ar:default']['b718adec73e04ce3ec720dd11a06a308'] = array(
    'source' => 'ID',
    'context' => '',
    'location' => '',
    'translation' => 'ID',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('ID', array(), array('context' => ''));
  $translations['ar:default']['b73c2ae6b27bd1777ecadbf28c2361d7'] = array(
    'source' => 'A search form with advanced options.',
    'context' => '',
    'location' => '',
    'translation' => 'مربع بحث ذو خيارات متقدمة.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('A search form with advanced options.', array(), array('context' => ''));
  $translations['ar:default']['b7496876dd2ceeaba72db5dcd85d5421'] = array(
    'source' => 'Has taxonomy terms (with depth)',
    'context' => '',
    'location' => '',
    'translation' => 'لديه شروط تصنيف بعمق',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Has taxonomy terms (with depth)', array(), array('context' => ''));
  $translations['ar:default']['b77e2e32584ffc6c1464351ddd6cbeb5'] = array(
    'source' => 'Sort by the threaded order. This will keep child comments together with their parents.',
    'context' => '',
    'location' => '',
    'translation' => 'فرز حسب الترتيب الموضوعي. هذا وسوف يبقي تعليق الطفل مع والديه ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Sort by the threaded order. This will keep child comments together with their parents.', array(), array('context' => ''));
  $translations['ar:default']['b7bfc0b30547f33e37eb504dba244af5'] = array(
    'source' => 'The group the translation is in.',
    'context' => '',
    'location' => '',
    'translation' => 'المجموعة كانت الترجمة فيها',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The group the translation is in.', array(), array('context' => ''));
  $translations['ar:default']['b7d1a8788d2d31421f4d54ee88a37248'] = array(
    'source' => 'Whether or not the content is sticky. To list sticky content first, set this to descending.',
    'context' => '',
    'location' => '',
    'translation' => 'ما إذا كان المحتوى مثبتاً. لعرض المحتوى المثبت أولاً، اضبط هذه إلى تنازلي.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Whether or not the content is sticky. To list sticky content first, set this to descending.', array(), array('context' => ''));
  $translations['ar:default']['b8d5baf5ad540cc8fe0f63cea026c324'] = array(
    'source' => 'oEmbed filter',
    'context' => '',
    'location' => '/ar',
    'translation' => 'oEmbed filter',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('oEmbed filter', array(), array('context' => ''));
  $translations['ar:default']['b90c3af75d64aab28c0a12ed5770720e'] = array(
    'source' => 'User uid',
    'context' => '',
    'location' => '',
    'translation' => 'المستخدم UID',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('User uid', array(), array('context' => ''));
  $translations['ar:default']['b94ee5e0c13ff4c52ef22df7e194c4c9'] = array(
    'source' => 'The media source name.',
    'context' => '',
    'location' => '/ar',
    'translation' => 'مصدر اسم الاعلام',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The media source name.', array(), array('context' => ''));
  $translations['ar:default']['b99d25b9273affbf4492086d540188d0'] = array(
    'source' => 'Provide a simple link to revert to the revision.',
    'context' => '',
    'location' => '',
    'translation' => 'تقديم وصلة بسيطة للعودة إلى مراجعة.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Provide a simple link to revert to the revision.', array(), array('context' => ''));
  $translations['ar:default']['b9d57d18f7a2558f110f3bd8b0a9cf26'] = array(
    'source' => 'A bridge to the @entity entity that is referencing @target_entity via !field_name',
    'context' => '',
    'location' => '',
    'translation' => 'A bridge to the @entity entity that is referencing @target_entity via !field_name',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('A bridge to the @entity entity that is referencing @target_entity via !field_name', array(), array('context' => ''));
  $translations['ar:default']['b9fce7dd396201da250ef3a832ba23e5'] = array(
    'source' => '@label (!name:!column)',
    'context' => '',
    'location' => '',
    'translation' => '@label (!name:!column)',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('@label (!name:!column)', array(), array('context' => ''));
  $translations['ar:default']['ba29c8b1e3ef39b207c9fa45c06704d1'] = array(
    'source' => 'Scheduled date',
    'context' => '',
    'location' => '',
    'translation' => 'التاريخ المقرر',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Scheduled date', array(), array('context' => ''));
  $translations['ar:default']['ba42dd4cad9f1916a6cd37fd07c33aa3'] = array(
    'source' => 'Not Approved',
    'context' => '',
    'location' => '',
    'translation' => 'مرفوض',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Not Approved', array(), array('context' => ''));
  $translations['ar:default']['ba4532fe5ecfa04fa454d5d0ffaa5fa6'] = array(
    'source' => 'The author of the comment.',
    'context' => '',
    'location' => '',
    'translation' => 'كاتب التعليق.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The author of the comment.', array(), array('context' => ''));
  $translations['ar:default']['ba591c4dd718e282a2973e42d2daedcf'] = array(
    'source' => 'Parent CID',
    'context' => '',
    'location' => '',
    'translation' => 'CID الأم',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Parent CID', array(), array('context' => ''));
  $translations['ar:default']['ba5ea2bfa79aeec98b0425a390b467db'] = array(
    'source' => '@label (!name)',
    'context' => '',
    'location' => '',
    'translation' => '@label (!name)',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('@label (!name)', array(), array('context' => ''));
  $translations['ar:default']['bad41e54a801d7bb6ded7f345ebcd5ad'] = array(
    'source' => 'Graphic content',
    'context' => '',
    'location' => '/ar/node/22/edit?destination=liveblog',
    'translation' => 'محتوى صادم',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Graphic content', array(), array('context' => ''));
  $translations['ar:default']['bb0e35e9412670db47aa472a41b9269f'] = array(
    'source' => 'List of reports in this post.',
    'context' => '',
    'location' => '/ar',
    'translation' => 'قائمة التقارير في هذه النشره ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('List of reports in this post.', array(), array('context' => ''));
  $translations['ar:default']['bbb93ef26e3c101ff11cdd21cab08a94'] = array(
    'source' => 'Null',
    'context' => '',
    'location' => '',
    'translation' => 'فارغة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Null', array(), array('context' => ''));
  $translations['ar:default']['bbd47109890259c0127154db1af26c75'] = array(
    'source' => 'Full',
    'context' => '',
    'location' => '',
    'translation' => 'كامل',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Full', array(), array('context' => ''));
  $translations['ar:default']['bbedc33707577d8a764f85f758dbc803'] = array(
    'source' => 'Reports flagged for fact-checking cannot be unflagged.',
    'context' => '',
    'location' => '',
    'translation' => 'لا يمكن إلغاء تنبيه المشرف للتقارير التي تم طلب التحقق من صحتها',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Reports flagged for fact-checking cannot be unflagged.', array(), array('context' => ''));
  $translations['ar:default']['bbee0efd59195347615163a821cab0fd'] = array(
    'source' => 'Displays a single chosen entity.',
    'context' => '',
    'location' => '',
    'translation' => 'عرض الكيان المختار',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Displays a single chosen entity.', array(), array('context' => ''));
  $translations['ar:default']['bc2bac341b425e0d7721e4218aad5b03'] = array(
    'source' => 'The human readable label.',
    'context' => '',
    'location' => '',
    'translation' => 'الوسم القابل للقراءة من قبل البشر.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The human readable label.', array(), array('context' => ''));
  $translations['ar:default']['bc6d0054ee4f0107579e619dbd22dd0c'] = array(
    'source' => 'By keyword',
    'context' => '',
    'location' => '',
    'translation' => 'الكلمات المفتاحية',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('By keyword', array(), array('context' => ''));
  $translations['ar:default']['bca00e69c9fceca60bd307c9a6aba07c'] = array(
    'source' => 'Is new',
    'context' => '',
    'location' => '',
    'translation' => 'جديد',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Is new', array(), array('context' => ''));
  $translations['ar:default']['bcb471ab149452f3050d9403daa3ca78'] = array(
    'source' => 'Heartbeat activity template form element.',
    'context' => '',
    'location' => '/ar',
    'translation' => 'Heartbeat activity template form element.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Heartbeat activity template form element.', array(), array('context' => ''));
  $translations['ar:default']['bcd6f2217246f54cb4e37684de5188ae'] = array(
    'source' => 'no results behavior',
    'context' => '',
    'location' => '',
    'translation' => 'no results behavior',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('no results behavior', array(), array('context' => ''));
  $translations['ar:default']['bce46bafce92be3557f73d7e33ba5d3b'] = array(
    'source' => 'Highlighted content',
    'context' => '',
    'location' => '',
    'translation' => 'محتوى مميز',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Highlighted content', array(), array('context' => ''));
  $translations['ar:default']['bd84c64dcb3251b7099d303fda85546c'] = array(
    'source' => 'Provide a simple link to edit the translations.',
    'context' => '',
    'location' => '',
    'translation' => 'ضع وصلة بسيطة لتحرير الترجمات.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Provide a simple link to edit the translations.', array(), array('context' => ''));
  $translations['ar:default']['bdff3b5f5585a252d03b09c770c84e1a'] = array(
    'source' => 'An autocomplete text field.',
    'context' => '',
    'location' => '',
    'translation' => 'حقل نص الإكمال التلقائي.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('An autocomplete text field.', array(), array('context' => ''));
  $translations['ar:default']['be11c74c1dd7f307bb80183a90dc2067'] = array(
    'source' => 'Get started',
    'context' => '',
    'location' => 'sites/all/themes/checkdesk/assets/js/tour.js; sites/all/modules/custom/checkdesk_tour/js/tour.js; sites/all/modules/contrib/demo_tour/js/tour.js',
    'translation' => 'ابدأ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Get started', array(), array('context' => ''));
  $translations['ar:default']['be322ae4d6efb6e95187b3184a7bc3c9'] = array(
    'source' => 'Flagging',
    'context' => '',
    'location' => '',
    'translation' => 'تحذير المشرف',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Flagging', array(), array('context' => ''));
  $translations['ar:default']['be6e48e34132a77c158eabf862fa7a05'] = array(
    'source' => 'Featured Stories',
    'context' => '',
    'location' => '',
    'translation' => 'مواضيع مختارة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Featured Stories', array(), array('context' => ''));
  $translations['ar:default']['be705f107b0d4146ba3e084de882ad39'] = array(
    'source' => 'Published to liveblog by !publisher to <a href="!story_url">!story</a>',
    'context' => '',
    'location' => '',
    'translation' => 'قام !publisher بنشره على المدونة المباشرة في خبر <a href="!story_url">!story</a>
',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Published to liveblog by !publisher to <a href="!story_url">!story</a>', array(), array('context' => ''));
  $translations['ar:default']['be80e17e7a78fada1f5c8ca0655bae99'] = array(
    'source' => '<span>Note:</span> Your story won\'t be published to the liveblog homepage until you add an update to your story.',
    'context' => '',
    'location' => '/ar/node/add/discussion',
    'translation' => '<span>ملحوظة:</span> لن يتم نشر موضوعك إلا بعد إضافة تحديث له.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('<span>Note:</span> Your story won\'t be published to the liveblog homepage until you add an update to your story.', array(), array('context' => ''));
  $translations['ar:default']['bea40602b351578b6063122dfb53fe23'] = array(
    'source' => '<a href="!url" target="_blank">Content</a> created successfully.',
    'context' => '',
    'location' => '/ar/node/add/media?meedan_bookmarklet=1&meedan_bookmarklet_prepopulate[body]=%D8%A3%D9%86%D8%B4%D8%A6%20%D8%AE%D8%A8%D8%B1%20|%20Meedan%20Checkdesk&meedan_bookmarklet_prepopulate[field_link]=http://qa.checkdesk.org/ar/node/add/discussion',
    'translation' => 'تم إنشاء <a href="!url" target="_blank">المحتوى</a>',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('<a href="!url" target="_blank">Content</a> created successfully.', array(), array('context' => ''));
  $translations['ar:default']['bebcd9a72cb2a4858a97c449b79c292b'] = array(
    'source' => 'Display fields as RSS items.',
    'context' => '',
    'location' => '',
    'translation' => 'Display fields as RSS items.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Display fields as RSS items.', array(), array('context' => ''));
  $translations['ar:default']['bec60391604287aee5be8e970f2486a6'] = array(
    'source' => 'Post date',
    'context' => '',
    'location' => '',
    'translation' => 'تاريخ النشر',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Post date', array(), array('context' => ''));
  $translations['ar:default']['bed29dbeb951801e7609cfa404b29b11'] = array(
    'source' => 'No caching of Views data.',
    'context' => '',
    'location' => '',
    'translation' => 'لا تخزين للبيانات المشاهده',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('No caching of Views data.', array(), array('context' => ''));
  $translations['ar:default']['befe6a958892cd5affecc940d2a89935'] = array(
    'source' => 'Store a title, href, and attributes in the database to assemble a link.',
    'context' => '',
    'location' => '',
    'translation' => 'Store a title, href, and attributes in the database to assemble a link.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Store a title, href, and attributes in the database to assemble a link.', array(), array('context' => ''));
  $translations['ar:default']['bf0cc61c8c663c23f5941b3838816660'] = array(
    'source' => 'Custom text',
    'context' => '',
    'location' => '',
    'translation' => 'نص مخصص',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Custom text', array(), array('context' => ''));
  $translations['ar:default']['bf733d8a933c1601697f364223fc7ecb'] = array(
    'source' => 'Access',
    'context' => '',
    'location' => '',
    'translation' => 'وصول',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Access', array(), array('context' => ''));
  $translations['ar:default']['bf899e1fe3039ab3aebca3969dfbefb5'] = array(
    'source' => 'Cannot use %author token in this context.',
    'context' => '',
    'location' => '',
    'translation' => 'لا يمكن استخدام %author في هذا السياق.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Cannot use %author token in this context.', array(), array('context' => ''));
  $translations['ar:default']['bf94ca6b335c9ac417993f9ad4116e45'] = array(
    'source' => 'Date in the form of WW (01 - 53).',
    'context' => '',
    'location' => '',
    'translation' => 'التاريخ في شكل WW (01 - 53).',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Date in the form of WW (01 - 53).', array(), array('context' => ''));
  $translations['ar:default']['bfec5ee001db25aba728f0f09c284b93'] = array(
    'source' => 'The ID of the entity that is related to the file.',
    'context' => '',
    'location' => '',
    'translation' => 'هوية الكيان المتعلق بالملف',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The ID of the entity that is related to the file.', array(), array('context' => ''));
  $translations['ar:default']['c0336e2de48dc711fcef456ba1be5052'] = array(
    'source' => 'A description of the location or context of the string.',
    'context' => '',
    'location' => '',
    'translation' => 'وصف لمكان أو سياق السلسلة.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('A description of the location or context of the string.', array(), array('context' => ''));
  $translations['ar:default']['c07736b1657715825204f8076d61f8ce'] = array(
    'source' => 'The name of the module managing the authentication entry.',
    'context' => '',
    'location' => '',
    'translation' => 'اسم وحدة إدارة الدخول المصادقة.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The name of the module managing the authentication entry.', array(), array('context' => ''));
  $translations['ar:default']['c0cb5f0fcf239ab3d9c1fcd31fff1efc'] = array(
    'source' => ',',
    'context' => '',
    'location' => '',
    'translation' => '،',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t(',', array(), array('context' => ''));
  $translations['ar:default']['c0e1b98e691fda18f04d8851697fc080'] = array(
    'source' => 'Import status',
    'context' => '',
    'location' => '',
    'translation' => 'استيراد الوضع',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Import status', array(), array('context' => ''));
  $translations['ar:default']['c1603e3ef425bf4385676bdb5a712388'] = array(
    'source' => 'Selected <strong>!row_count</strong> in this view.',
    'context' => '',
    'location' => '',
    'translation' => 'تم اختيار <strong>!row_count</strong> في هذا العرض.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Selected <strong>!row_count</strong> in this view.', array(), array('context' => ''));
  $translations['ar:default']['c1905c3a9c2a91009fd0774a9a7e6d37'] = array(
    'source' => 'Content revision',
    'context' => '',
    'location' => '',
    'translation' => 'مراجعة المحتوى',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Content revision', array(), array('context' => ''));
  $translations['ar:default']['c1a1a2fb2022498c285572f1278d56d0'] = array(
    'source' => '<a href="[node:url:unaliased]">[node:author]\'s report</a> was flagged for fact-checking.',
    'context' => '',
    'location' => '/ar/node/flag/confirm/flag/factcheck/2441/ajax',
    'translation' => 'تم تنبيه المشرف للتحقق من صحة معلومات  <a href="[node:url:unaliased]"> تقرير [node:author] </a>.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('<a href="[node:url:unaliased]">[node:author]\'s report</a> was flagged for fact-checking.', array(), array('context' => ''));
  $translations['ar:default']['c1c9e5617e7c90882f29ead1945f1308'] = array(
    'source' => 'Exposed form: @view-@display_id',
    'context' => '',
    'location' => '',
    'translation' => 'الاستمارة المكشوفة: @view-@display_id',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Exposed form: @view-@display_id', array(), array('context' => ''));
  $translations['ar:default']['c1f666ec4f45f5db52a8572d6297df13'] = array(
    'source' => 'The user\'s picture, if allowed.',
    'context' => '',
    'location' => '',
    'translation' => 'صور للمستخدم، إذا سمح بها.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The user\'s picture, if allowed.', array(), array('context' => ''));
  $translations['ar:default']['c22727ce5fa75940fa7f2b31832c032b'] = array(
    'source' => 'Now let\'s !fact_check and !blog.',
    'context' => '',
    'location' => '/ar/meedan_bookmarklet/message?meedan_bookmarklet=1&meedan_bookmarklet_submitted=1&meedan_bookmarklet_nid=1785&meedan_bookmarklet_url=http%3A//www.google.com',
    'translation' => 'الآن يمكنك !fact_check أو !blog.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Now let\'s !fact_check and !blog.', array(), array('context' => ''));
  $translations['ar:default']['c25e57e2341e66806cc34b7c332a2ae8'] = array(
    'source' => 'The total number of reports submitted in any given month.',
    'context' => '',
    'location' => '/checkdesk/ar/admin/meedan/reports',
    'translation' => 'العدد الكلي للتقارير في شهر معين',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The total number of reports submitted in any given month.', array(), array('context' => ''));
  $translations['ar:default']['c28517c56d669b4ce6c8db6adfcb62e9'] = array(
    'source' => 'The last comment of a node.',
    'context' => '',
    'location' => '',
    'translation' => 'التعليق الأخير من العقدة.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The last comment of a node.', array(), array('context' => ''));
  $translations['ar:default']['c28d6d4409f06914e34b543144cb9f03'] = array(
    'source' => 'Updated date',
    'context' => '',
    'location' => '',
    'translation' => 'تاريخ محدّث',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Updated date', array(), array('context' => ''));
  $translations['ar:default']['c2af2fffda728eb34088060253ad9c52'] = array(
    'source' => 'URL, as plain text',
    'context' => '',
    'location' => '',
    'translation' => 'URL، كنص عادي',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('URL, as plain text', array(), array('context' => ''));
  $translations['ar:default']['c2d103dccf7bd51ed1c820c3e0435b13'] = array(
    'source' => 'Are you sure you want to unflag this report?',
    'context' => '',
    'location' => '/ar/node/flag/confirm/unflag/graphic/236/ajax',
    'translation' => 'هل أنت متأكد من أنك تريد إلغاء تنبيه المشرف حول هذا التقرير؟',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Are you sure you want to unflag this report?', array(), array('context' => ''));
  $translations['ar:default']['c3c83f0953544f4d0987cf41cf094787'] = array(
    'source' => 'User ID from URL',
    'context' => '',
    'location' => '',
    'translation' => 'User ID from URL',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('User ID from URL', array(), array('context' => ''));
  $translations['ar:default']['c44c057c133b96f9e6084e36ce4e54dc'] = array(
    'source' => 'Checkdesk reports',
    'context' => '',
    'location' => '/checkdesk/ar/admin/meedan/reports',
    'translation' => 'تقارير تشك دسك',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Checkdesk reports', array(), array('context' => ''));
  $translations['ar:default']['c481995ffe0ca005e3bfebdc63f71d49'] = array(
    'source' => 'Displays rows in a table.',
    'context' => '',
    'location' => '',
    'translation' => 'يعرض الصفوف في جدول.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Displays rows in a table.', array(), array('context' => ''));
  $translations['ar:default']['c49820865b7a9ce52c5d4fd43cf5709a'] = array(
    'source' => 'Activity Stream',
    'context' => '',
    'location' => '/ar',
    'translation' => 'مسار النشاط',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Activity Stream', array(), array('context' => ''));
  $translations['ar:default']['c49f2f83d053546675e569fbe03f24db'] = array(
    'source' => 'Filters out unpublished content if the current user cannot view it.',
    'context' => '',
    'location' => '',
    'translation' => 'مرشحات من أصل غير منشورة المحتوى إذا كان المستخدم الحالي لا يمكن مشاهدته.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Filters out unpublished content if the current user cannot view it.', array(), array('context' => ''));
  $translations['ar:default']['c4d528655989f630a8d00b93658291dc'] = array(
    'source' => 'A report containing a media item.',
    'context' => '',
    'location' => '/ar',
    'translation' => 'تقرير يحتوي وسائط متعددة.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('A report containing a media item.', array(), array('context' => ''));
  $translations['ar:default']['c4f1d6fc103b47f2fcc24cd750716c9b'] = array(
    'source' => 'An update has been added to a story',
    'context' => '',
    'location' => '/index.php',
    'translation' => 'تم إضافة تحديث جديد لموضوع',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('An update has been added to a story', array(), array('context' => ''));
  $translations['ar:default']['c53ff9166279d8a681a476a0fa02b62f'] = array(
    'source' => 'Displays the default summary as a list.',
    'context' => '',
    'location' => '',
    'translation' => 'يعرض الملخص الافتراضي كقائمة.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Displays the default summary as a list.', array(), array('context' => ''));
  $translations['ar:default']['c5836008c1649301e29351a55db8f65c'] = array(
    'source' => 'Flag',
    'context' => '',
    'location' => '',
    'translation' => 'تنبيه المشرف',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Flag', array(), array('context' => ''));
  $translations['ar:default']['c5cafc6c618240b02de9483a400c0a1a'] = array(
    'source' => 'Compose new update',
    'context' => '',
    'location' => '',
    'translation' => 'اكتب تحديثاً جديداً',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Compose new update', array(), array('context' => ''));
  $translations['ar:default']['c600e1c14837eea04bf6b37d10f44146'] = array(
    'source' => 'Graphic content (journalist)',
    'context' => '',
    'location' => '/ar/node/22/edit?destination=liveblog',
    'translation' => 'محتوى صادم (صحفي)',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Graphic content (journalist)', array(), array('context' => ''));
  $translations['ar:default']['c633174be171bb10874104d5176929c1'] = array(
    'source' => '- Mine -',
    'context' => '',
    'location' => '/ar/search?field_tags_tid=122',
    'translation' => '- مشاركاتي -',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('- Mine -', array(), array('context' => ''));
  $translations['ar:default']['c6568e77f61109390e82d035aaacaef0'] = array(
    'source' => 'Headline',
    'context' => '',
    'location' => '/ar',
    'translation' => 'العنوان الرئيسي',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Headline', array(), array('context' => ''));
  $translations['ar:default']['c67a90a8a9be712d946f7d406ded4827'] = array(
    'source' => 'User picture',
    'context' => '',
    'location' => '',
    'translation' => 'صورة المستخدم',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('User picture', array(), array('context' => ''));
  $translations['ar:default']['c684eaaf428ef3ce8aa94755f2cedc51'] = array(
    'source' => 'Not promoted',
    'context' => '',
    'location' => '; sites/all/modules/contrib/save_draft/save_draft.js',
    'translation' => 'غير مختارة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Not promoted', array(), array('context' => ''));
  $translations['ar:default']['c6beff574b370ac2ac70ad570091e252'] = array(
    'source' => 'Limit results to only those entity flagged by a certain flag; Or display information about the flag set on a entity.',
    'context' => '',
    'location' => '',
    'translation' => 'تحديد نتائج تلك فقط لكيان ترفع علم من علم معين، أو عرض معلومات حول العلم تعيين على الكيان.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Limit results to only those entity flagged by a certain flag; Or display information about the flag set on a entity.', array(), array('context' => ''));
  $translations['ar:default']['c6c33b9ff2d0201dce3261df1938b551'] = array(
    'source' => 'Term edit link',
    'context' => '',
    'location' => '',
    'translation' => 'مصطلح تحرير الرابط',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Term edit link', array(), array('context' => ''));
  $translations['ar:default']['c6f1cb7c03586aa62b057f7ed049a72d'] = array(
    'source' => 'The name of the comment\'s author. Can be rendered as a link to the author\'s homepage.',
    'context' => '',
    'location' => '',
    'translation' => 'اسم مؤلف التعليق. يمكن عرضه كوصلة إلى الموقع الخاص بالكاتب.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The name of the comment\'s author. Can be rendered as a link to the author\'s homepage.', array(), array('context' => ''));
  $translations['ar:default']['c74bdc61eab14f26f5c4a2bbe47c0560'] = array(
    'source' => 'Filter to ensure content has or has not been flagged.',
    'context' => '',
    'location' => '',
    'translation' => 'تصفية المحتوى لضمان ديها أو لم يكن ترفع علم.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Filter to ensure content has or has not been flagged.', array(), array('context' => ''));
  $translations['ar:default']['c7899a1bc38e20bd6777827b8ef29685'] = array(
    'source' => 'Displays the summary unformatted, with option for one after another or inline.',
    'context' => '',
    'location' => '',
    'translation' => 'يعرض الملخص غير منسق، مع خيار لواحدا تلو الآخر أو مضمنة.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Displays the summary unformatted, with option for one after another or inline.', array(), array('context' => ''));
  $translations['ar:default']['c795d4e0668588f6a2890f67713dd723'] = array(
    'source' => 'حَدِّث',
    'context' => '',
    'location' => NULL,
    'translation' => 'تحديث',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('حَدِّث', array(), array('context' => ''));
  $translations['ar:default']['c7b3f63fe8766fd1fb3468c19e1230f8'] = array(
    'source' => '@current of @max',
    'context' => '',
    'location' => '',
    'translation' => '@current من @max',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('@current of @max', array(), array('context' => ''));
  $translations['ar:default']['c7c79368c46ca7b3f5f640e0e937eb60'] = array(
    'source' => 'Relate each @entity with a @field set to the term.',
    'context' => '',
    'location' => '',
    'translation' => 'Relate each @entity with a @field set to the term.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Relate each @entity with a @field set to the term.', array(), array('context' => ''));
  $translations['ar:default']['c7ffdcda0c54d0ed8119beb8df520943'] = array(
    'source' => 'The url of the account edit page.',
    'context' => '',
    'location' => '',
    'translation' => 'عنوان URL لحساب تحرير صفحة.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The url of the account edit page.', array(), array('context' => ''));
  $translations['ar:default']['c8bf8d8a56cce26dceb4ac55cd33070d'] = array(
    'source' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
    'context' => '',
    'location' => '/; sites/all/modules/contrib/maxlength/js/maxlength.js',
    'translation' => 'المحتوى محصور بـ @limit حرف، باق: <strong>@remaining</strong>
‏',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Content limited to @limit characters, remaining: <strong>@remaining</strong>', array(), array('context' => ''));
  $translations['ar:default']['c8e666e771511b47514d9fc7ad3455c3'] = array(
    'source' => 'Activity on',
    'context' => '',
    'location' => '',
    'translation' => 'نشاط على',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Activity on', array(), array('context' => ''));
  $translations['ar:default']['c8eb7c7555661c616b2a40bccb51cb2f'] = array(
    'source' => 'Followed stories',
    'context' => '',
    'location' => '/index.php',
    'translation' => 'موضوعات متتبعه',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Followed stories', array(), array('context' => ''));
  $translations['ar:default']['c8eea2a43198f3c1243fd0cde6464b6e'] = array(
    'source' => 'View your reports.',
    'context' => '',
    'location' => '/ar/meedan_bookmarklet/message?meedan_bookmarklet=1&meedan_bookmarklet_submitted=1&meedan_bookmarklet_nid=15648&meedan_bookmarklet_url=http%3A//www.flickr.com/photos/axemann/9185859240/',
    'translation' => 'إستعرض تقاريرك.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('View your reports.', array(), array('context' => ''));
  $translations['ar:default']['c8ef1aecbd4980a757dbb03c395123a7'] = array(
    'source' => '<a href="!flag_author_url" class="actor">!flag_author_name</a> followed this story',
    'context' => '',
    'location' => '/ar/story-collaboration/112',
    'translation' => '<a href="!flag_author_url" class="actor">!flag_author_name</a> تابع هذا الموضوع',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('<a href="!flag_author_url" class="actor">!flag_author_name</a> followed this story', array(), array('context' => ''));
  $translations['ar:default']['c9093ae39a3e21c99a7f6ebd38fb1376'] = array(
    'source' => 'Are you sure you want to flag this report?',
    'context' => '',
    'location' => '/ar/node/flag/confirm/flag/graphic/11/ajax',
    'translation' => 'هل أنت متأكد من أنك تريد تنبيه المشرف حول هذا التقرير؟',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Are you sure you want to flag this report?', array(), array('context' => ''));
  $translations['ar:default']['c9266039677d85728d48d01d61a49bc4'] = array(
    'source' => 'Date in the form of MM (01 - 12).',
    'context' => '',
    'location' => '',
    'translation' => 'التاريخ بصيغة MM (القيم المسموحة 01-12)',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Date in the form of MM (01 - 12).', array(), array('context' => ''));
  $translations['ar:default']['c9413dd7682a45da9ecc9efa8cea47d7'] = array(
    'source' => 'In Progress',
    'context' => '',
    'location' => '',
    'translation' => 'جارٍ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('In Progress', array(), array('context' => ''));
  $translations['ar:default']['c974d6d1ee16df174cd3620eb8cadd99'] = array(
    'source' => '<span class="fb-commentscount" data-url="@url" id="fb-commentscount-@nid">No comments</span>',
    'context' => '',
    'location' => '',
    'translation' => '<span class="fb-commentscount" data-url="@url" id="fb-commentscount-@nid">لا تعليقات</span>',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('<span class="fb-commentscount" data-url="@url" id="fb-commentscount-@nid">No comments</span>', array(), array('context' => ''));
  $translations['ar:default']['c9755f2fcfe04bd1c16c77a3314d476d'] = array(
    'source' => 'Relate all comments on the node. This will create 1 duplicate record for every comment. Usually if you need this it is better to create a comment view.',
    'context' => '',
    'location' => '',
    'translation' => 'تتصل جميع التعليقات على العقدة. هذا سيخلق 1 الإجابات المكررة للكل تعليق. إذا كنت بحاجة إلى هذا عادة أنه من الأفضل لإنشاء طريقة عرض تعليق.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Relate all comments on the node. This will create 1 duplicate record for every comment. Usually if you need this it is better to create a comment view.', array(), array('context' => ''));
  $translations['ar:default']['c97620ba52e9aa9f07a0699ce9939d48'] = array(
    'source' => 'revision user',
    'context' => '',
    'location' => '',
    'translation' => 'مستخدم المراجعة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('revision user', array(), array('context' => ''));
  $translations['ar:default']['c97ade01809d57372263ec1f9beb6b14'] = array(
    'source' => 'Content language',
    'context' => '',
    'location' => '',
    'translation' => 'محتوى اللغة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Content language', array(), array('context' => ''));
  $translations['ar:default']['c99d139812d53cc57e0bf67a071d93e4'] = array(
    'source' => 'Title, as link (default)',
    'context' => '',
    'location' => '',
    'translation' => 'العنوان، كرابط (الافتراضي)',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Title, as link (default)', array(), array('context' => ''));
  $translations['ar:default']['c9d1f9f4d2689cb3917ac0117bcae674'] = array(
    'source' => 'Flag user',
    'context' => '',
    'location' => '',
    'translation' => 'تحذير المشرف حول المستخدم',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Flag user', array(), array('context' => ''));
  $translations['ar:default']['ca0dc3f6fa13bf355ddd6048553a3e2d'] = array(
    'source' => 'The ID used to identify this @entity internally.',
    'context' => '',
    'location' => '',
    'translation' => 'The ID used to identify this @entity internally.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The ID used to identify this @entity internally.', array(), array('context' => ''));
  $translations['ar:default']['ca100ca3af10708906ee0806443449a5'] = array(
    'source' => 'Provide serialized data of the user',
    'context' => '',
    'location' => '',
    'translation' => 'توفير البيانات المتسلسلة للمستخدم',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Provide serialized data of the user', array(), array('context' => ''));
  $translations['ar:default']['ca15fd43dfaeb80eb8c125735e0479b0'] = array(
    'source' => 'nodes',
    'context' => '',
    'location' => '',
    'translation' => 'العقد',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('nodes', array(), array('context' => ''));
  $translations['ar:default']['ca2df34e694a9409b9a1271a32dfd7d4'] = array(
    'source' => 'Paged output, mini pager',
    'context' => '',
    'location' => '',
    'translation' => 'Paged output, mini pager',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Paged output, mini pager', array(), array('context' => ''));
  $translations['ar:default']['ca3c0035b5370bdc2d6d9a5bd565797e'] = array(
    'source' => '@group (historical data)',
    'context' => '',
    'location' => '',
    'translation' => '@group (historical data)',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('@group (historical data)', array(), array('context' => ''));
  $translations['ar:default']['cbaaeca438c03039dbe4d94987e4a3ad'] = array(
    'source' => '<a class="actor" href="!user_url">!username</a> added a new  <a href="!report_url">report</a> to <a href="!story_url">!story</a>',
    'context' => '',
    'location' => '/ar',
    'translation' => '<a class="actor" href="!user_url">!username</a> أضاف  <a href="!report_url">تقريراً</a> جديداً للموضوع <a href="!story_url">!story</a>',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('<a class="actor" href="!user_url">!username</a> added a new  <a href="!report_url">report</a> to <a href="!story_url">!story</a>', array(), array('context' => ''));
  $translations['ar:default']['cbb37401d648375c9a32619279b03418'] = array(
    'source' => 'Stories',
    'context' => '',
    'location' => '',
    'translation' => 'أخبار',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Stories', array(), array('context' => ''));
  $translations['ar:default']['cd04986fed9f2447e44dcf509c121e72'] = array(
    'source' => 'Taxonomy Term',
    'context' => '',
    'location' => '',
    'translation' => 'التصنيف الأجل',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Taxonomy Term', array(), array('context' => ''));
  $translations['ar:default']['cd28f83a2015c0ec0632dca0c20f3e01'] = array(
    'source' => 'The signature of a user.',
    'context' => '',
    'location' => '',
    'translation' => 'توقيع المستخدم.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The signature of a user.', array(), array('context' => ''));
  $translations['ar:default']['cda0ecb07fc4c29572ea4712219b822c'] = array(
    'source' => 'Email address for a given user. This field is normally not shown to users, so be cautious when using it.',
    'context' => '',
    'location' => '',
    'translation' => 'عنوان البريد الإلكتروني لمستخدم معين. وعادة لا يظهر هذا المجال للمستخدمين، لذا يجب الحذر عند استخدامه.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Email address for a given user. This field is normally not shown to users, so be cautious when using it.', array(), array('context' => ''));
  $translations['ar:default']['ce0570baa693338d4c57f7543737d942'] = array(
    'source' => 'Other nodes that link to the node.',
    'context' => '',
    'location' => '',
    'translation' => 'العقد الأخرى التي تصل إلى العقدة.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Other nodes that link to the node.', array(), array('context' => ''));
  $translations['ar:default']['ce186dee47f34c7886dd08552aebc6e8'] = array(
    'source' => 'The number of new comments on the node.',
    'context' => '',
    'location' => '',
    'translation' => 'عدد التعليقات على العقدة.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The number of new comments on the node.', array(), array('context' => ''));
  $translations['ar:default']['ce6103890e53a115b49c178f5f6bfe89'] = array(
    'source' => 'Get the actual content from a content revision.',
    'context' => '',
    'location' => '',
    'translation' => 'الحصول على المحتوى الفعلي من مراجعة المحتوى.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Get the actual content from a content revision.', array(), array('context' => ''));
  $translations['ar:default']['ce9cabcdfc4476e6f338471b753f980f'] = array(
    'source' => 'Administer Twitter accounts',
    'context' => '',
    'location' => '/index.php',
    'translation' => 'أدر حسابات تويتر',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Administer Twitter accounts', array(), array('context' => ''));
  $translations['ar:default']['cef932f678ad3188ab46051ae381a2e4'] = array(
    'source' => 'Report added to story',
    'context' => '',
    'location' => '/index.php',
    'translation' => 'تم إضافة تقرير لموضوع',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Report added to story', array(), array('context' => ''));
  $translations['ar:default']['cf25052c564a43b6c3c374e323b38aef'] = array(
    'source' => 'Hello !recipient_name,

A <a href="!report_url">report</a> which you have submitted has been published in an <a href="!node_url">update</a>.',
    'context' => '',
    'location' => '/meedan/meedan-checkdesk/drupal/index.php',
    'translation' => 'مرحباً !recipient_name،

تم نشر <a href="!report_url">التقرير</a> الذي أرسلته في <a href="!node_url">تحديث</a> جديد.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Hello !recipient_name,

A <a href="!report_url">report</a> which you have submitted has been published in an <a href="!node_url">update</a>.', array(), array('context' => ''));
  $translations['ar:default']['cf2eb5da15ebe266946c23948f0e2812'] = array(
    'source' => 'Whether the node is displayed at the top of lists in which it appears.',
    'context' => '',
    'location' => '',
    'translation' => 'ما إذا كان يتم عرض العقدة في الجزء العلوي من قوائم ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Whether the node is displayed at the top of lists in which it appears.', array(), array('context' => ''));
  $translations['ar:default']['cf3d593a2c8b745903dc3f57b7eecfe8'] = array(
    'source' => 'Status set to !status by !editor.',
    'context' => '',
    'location' => '',
    'translation' => 'قام !editor بتغيير حالة التحقق إلى !status',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Status set to !status by !editor.', array(), array('context' => ''));
  $translations['ar:default']['cf46f52efc00c03d2368448377b6ccb0'] = array(
    'source' => 'A user that is associated with this file, usually because this file is in a field on the user.',
    'context' => '',
    'location' => '',
    'translation' => 'المستخدم الذي يرتبط مع هذا الملف، لأن هذا الملف عادة في حقل المستخدم.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('A user that is associated with this file, usually because this file is in a field on the user.', array(), array('context' => ''));
  $translations['ar:default']['cf52a4580e6cce9d3e7a2d0d02898247'] = array(
    'source' => 'The content to which the comment is a reply to.',
    'context' => '',
    'location' => '',
    'translation' => 'المحتوى الذي هو التعليق ردا علىيه',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The content to which the comment is a reply to.', array(), array('context' => ''));
  $translations['ar:default']['cf556fc31bc8ac91a95cbfc22eea6b9f'] = array(
    'source' => 'Has taxonomy term ID',
    'context' => '',
    'location' => '',
    'translation' => 'لديه هوية التصنيف',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Has taxonomy term ID', array(), array('context' => ''));
  $translations['ar:default']['cf55a95dddfc154975f6e6bf1299aa48'] = array(
    'source' => 'If you have problems accessing administrative pages on this site, disable the overlay on your profile page.',
    'context' => '',
    'location' => '',
    'translation' => 'إذا كان لديك مشاكل في الوصول إلى الصفحات الإدارية على هذا الموقع،  قم بتعطيل التراكم على صفحة ملفك الشخصي.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('If you have problems accessing administrative pages on this site, disable the overlay on your profile page.', array(), array('context' => ''));
  $translations['ar:default']['cf6a72dd0ab0eb4ae9a804925b62fd71'] = array(
    'source' => '<p><strong><a href="!flag_author_url">!flag_author_name</a></strong> has flagged a <strong><a href="!report_url">report</a></strong> as <span class="notification-flag">!flag_type</span>.</p>',
    'context' => '',
    'location' => '/ar/user/577/notifications',
    'translation' => '<p>قام <strong><a href="!flag_author_url">!flag_author_name</a></strong>  بتنبيه فريق العمل عن <strong><a href="!report_url">التقرير الآتي</a></strong> بأنه <span class="notification-flag">!flag_type</span>.</p>',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('<p><strong><a href="!flag_author_url">!flag_author_name</a></strong> has flagged a <strong><a href="!report_url">report</a></strong> as <span class="notification-flag">!flag_type</span>.</p>', array(), array('context' => ''));
  $translations['ar:default']['cfb419015894037e95a82d8b1cde1527'] = array(
    'source' => 'Has taxonomy term',
    'context' => '',
    'location' => '',
    'translation' => 'لديه هوية التصنيف',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Has taxonomy term', array(), array('context' => ''));
  $translations['ar:default']['cfc0c00635860e0ad3688d7d318a9e76'] = array(
    'source' => 'Relate an item to the user that flagged it.',
    'context' => '',
    'location' => '',
    'translation' => 'انساب عنصر إلى المستخدم الذي قام بالتنبيه',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Relate an item to the user that flagged it.', array(), array('context' => ''));
  $translations['ar:default']['d05d3904ba30bc21349b360f9dd90724'] = array(
    'source' => 'The terms to search for.',
    'context' => '',
    'location' => '',
    'translation' => 'الشروط التي تبحث عنها ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The terms to search for.', array(), array('context' => ''));
  $translations['ar:default']['d0fc074d327380040687f5da68277507'] = array(
    'source' => 'In case a new revision is to be saved, the log entry explaining the changes for this version.',
    'context' => '',
    'location' => '',
    'translation' => 'في حالة مراجعة جديدة ليتم حفظها، وإدخال سجل شرح التغييرات لهذا الإصدار.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('In case a new revision is to be saved, the log entry explaining the changes for this version.', array(), array('context' => ''));
  $translations['ar:default']['d11f766265dd49905c290d654ef52bb7'] = array(
    'source' => 'Please <a href="@register_url">register</a> or <a href="@login_url">login</a> to be able to add footnotes and contribute to the fact-checking of this report.',
    'context' => '',
    'location' => '/meedan/meedan-checkdesk/drupal/ar/liveblog/one-more-test',
    'translation' => 'الرجاء <a href="@register_url">إنشاء حساباً جديداً</a> أو <a href="@login_url">تسجيل الدخول</a> لإضافة ملاحظات والمشاركة في التحقق من صحة المعلومات.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Please <a href="@register_url">register</a> or <a href="@login_url">login</a> to be able to add footnotes and contribute to the fact-checking of this report.', array(), array('context' => ''));
  $translations['ar:default']['d1457b72c3fb323a2671125aef3eab5d'] = array(
    'source' => '?',
    'context' => '',
    'location' => '/ar/user',
    'translation' => '؟',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('?', array(), array('context' => ''));
  $translations['ar:default']['d16344015b39a0a65f672d2a130e6417'] = array(
    'source' => 'The full name Twitter account user.',
    'context' => '',
    'location' => '',
    'translation' => 'الاسم الكامل لمستخدم تويتر ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The full name Twitter account user.', array(), array('context' => ''));
  $translations['ar:default']['d187fd165d03d5abd3b5b9a49018d472'] = array(
    'source' => 'Current node\'s update time',
    'context' => '',
    'location' => '',
    'translation' => 'تاريخ تحديث العقدة الحالية',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Current node\'s update time', array(), array('context' => ''));
  $translations['ar:default']['d1a4512ffdb35c86a4830a91764190d9'] = array(
    'source' => 'Undetermined',
    'context' => '',
    'location' => '/ar/liveblog',
    'translation' => 'غير معروف',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Undetermined', array(), array('context' => ''));
  $translations['ar:default']['d1b4de9815e66734ee25d06be65753a7'] = array(
    'source' => 'Ancestors of the term, i.e. parent of all above hierarchy levels.',
    'context' => '',
    'location' => '',
    'translation' => 'أسلاف الأصل، أي مصطلح من جميع مستويات التسلسل الهرمي أعلاه.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Ancestors of the term, i.e. parent of all above hierarchy levels.', array(), array('context' => ''));
  $translations['ar:default']['d1c143ad303bf2330329f045e5421d27'] = array(
    'source' => 'The tid of a taxonomy term.',
    'context' => '',
    'location' => '',
    'translation' => 'The tid of a taxonomy term.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The tid of a taxonomy term.', array(), array('context' => ''));
  $translations['ar:default']['d1ce4d839e77a189fe2a0dd471eb0576'] = array(
    'source' => 'Flag graphic content',
    'context' => '',
    'location' => '',
    'translation' => 'تنبيه حول محتوى صادم',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Flag graphic content', array(), array('context' => ''));
  $translations['ar:default']['d1f0603536edac04a8ec8f0aa1288e8e'] = array(
    'source' => 'The status of the file.',
    'context' => '',
    'location' => '',
    'translation' => 'حالة الملف.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The status of the file.', array(), array('context' => ''));
  $translations['ar:default']['d20702f1d84629cfc5aa658521affa87'] = array(
    'source' => '@countd',
    'context' => '',
    'location' => '/checkdesk/ar',
    'translation' => '@countي',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('@countd', array(), array('context' => ''));
  $translations['ar:default']['d22208aa0b7f1847ab9afdfbd24b44d5'] = array(
    'source' => 'URL, as link',
    'context' => '',
    'location' => '',
    'translation' => 'URL كرابط',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('URL, as link', array(), array('context' => ''));
  $translations['ar:default']['d23808be4cf3016a3c9d1982cd7d5915'] = array(
    'source' => '@count[3] collaborators',
    'context' => '',
    'location' => '/ar/story-collaboration/13',
    'translation' => '@count[3] مشاركين',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('@count[3] collaborators', array(), array('context' => ''));
  $translations['ar:default']['d2536fa35a304b26c1c9f510c71b0386'] = array(
    'source' => '@label (!name:delta)',
    'context' => '',
    'location' => '',
    'translation' => '@label (!name:delta)',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('@label (!name:delta)', array(), array('context' => ''));
  $translations['ar:default']['d25e93d56f6dcb139f14879fc47414f2'] = array(
    'source' => 'Exclude report with this keyword',
    'context' => '',
    'location' => '',
    'translation' => 'استثنِ التقارير التي تحوي هذه الكلمة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Exclude report with this keyword', array(), array('context' => ''));
  $translations['ar:default']['d2b98e321d2f5ee8ac9241ebd85522b7'] = array(
    'source' => 'Hello !recipient_name,

!actor has turned on fact-checking for a <a href="!url">report</a> you submitted.',
    'context' => '',
    'location' => '/meedan/meedan-checkdesk/drupal/index.php',
    'translation' => 'مرحباً !recipient_name،

قام !actor بتفعيل التحقق من صحة المعلومات على <a href="!url">التقرير</a> الذي أرسلته.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Hello !recipient_name,

!actor has turned on fact-checking for a <a href="!url">report</a> you submitted.', array(), array('context' => ''));
  $translations['ar:default']['d2bbda0f72011454f75c2fa946e4f2e0'] = array(
    'source' => '!city, !country',
    'context' => '',
    'location' => '/meedan/meedan-checkdesk/drupal/ar/node/15692',
    'translation' => '!city، !country',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('!city, !country', array(), array('context' => ''));
  $translations['ar:default']['d30e5c7ec6dbe9e6fc82878260632b38'] = array(
    'source' => 'A comment that is associated with this file, usually because this file is in a field on the comment.',
    'context' => '',
    'location' => '',
    'translation' => 'تعليق مقترن  بالملف لأن هذا الملف عادة في حقل على تعليق.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('A comment that is associated with this file, usually because this file is in a field on the comment.', array(), array('context' => ''));
  $translations['ar:default']['d3be1a3fefd816aa1f649585cd2e96bc'] = array(
    'source' => 'Hello !recipient_name,

!actor has changed the fact-checking status for a <a href="!url">report</a> you added footnote to to !rating.

You can edit your notification settings from your <a href="!recipient_url">profile page</a>.

This was an auto-generated email from !site; please do not respond directly to this email.',
    'context' => '',
    'location' => '/meedan/meedan-checkdesk/drupal/index.php',
    'translation' => 'مرحباً !recipient_name،

قام !actor بتغيير حالة التحقق من صحة المعلومات <a href="!url">للتقرير</a> الذي أضفت إليه ملاحظات إلى !rating.

بإمكانك تعديل إعدادات التنبيهات الخاصة بك من صفحة <a href="!recipient_url">الحساب الشخصي</a> الخاصة بك.

هذه رسالة مولدة بشكل تلقائي من !site، يرجى عدم الرد على هذه الرسالة.
',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Hello !recipient_name,

!actor has changed the fact-checking status for a <a href="!url">report</a> you added footnote to to !rating.

You can edit your notification settings from your <a href="!recipient_url">profile page</a>.

This was an auto-generated email from !site; please do not respond directly to this email.', array(), array('context' => ''));
  $translations['ar:default']['d3ccca2b5ec2adee40e95e7bc262f5b3'] = array(
    'source' => 'Add a brief description of the story (optional)',
    'context' => '',
    'location' => '/',
    'translation' => 'أضف تلخيصاً موجزاً للموضوع (اختياري)',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Add a brief description of the story (optional)', array(), array('context' => ''));
  $translations['ar:default']['d3d2e617335f08df83599665eef8a418'] = array(
    'source' => 'Close',
    'context' => '',
    'location' => '/ar/meedan_bookmarklet/message?meedan_bookmarklet=1&meedan_bookmarklet_submitted=1&meedan_bookmarklet_nid=236',
    'translation' => 'أغلق',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Close', array(), array('context' => ''));
  $translations['ar:default']['d3d5b2e9cc26e07d9bf4ebfbab15fda4'] = array(
    'source' => 'Mini',
    'context' => '',
    'location' => '',
    'translation' => 'صغيرة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Mini', array(), array('context' => ''));
  $translations['ar:default']['d43152e05d041d9ce5b892b5c9731032'] = array(
    'source' => 'Apply and continue',
    'context' => '',
    'location' => '',
    'translation' => 'تطبيق واستمرار',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Apply and continue', array(), array('context' => ''));
  $translations['ar:default']['d45b4f6e492f52f7b506f6094861be76'] = array(
    'source' => 'Create story',
    'context' => '',
    'location' => '',
    'translation' => 'أضف موضوع',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Create story', array(), array('context' => ''));
  $translations['ar:default']['d45edf6c0246717ae211f343a29ceb8b'] = array(
    'source' => 'Published ',
    'context' => '',
    'location' => '/ar/search?field_tags_tid=1327',
    'translation' => 'تم نشره',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Published ', array(), array('context' => ''));
  $translations['ar:default']['d488220f075f7ea939ba38af817613ca'] = array(
    'source' => '<a class="actor" href="!user_url">!username</a> added footnote to <a href="!report_url">report</a>',
    'context' => '',
    'location' => '/ar/story-collaboration/12289',
    'translation' => 'قام <a href="!user_url">!username</a> بإضافة معلومات جديدة للتحقق من صحة المعلومات في  <a href="!report_url">هذا التقرير</a>',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('<a class="actor" href="!user_url">!username</a> added footnote to <a href="!report_url">report</a>', array(), array('context' => ''));
  $translations['ar:default']['d4911f5a88a53cd565d1e05265874a49'] = array(
    'source' => 'Message_ID',
    'context' => '',
    'location' => '/ar',
    'translation' => 'Message_ID',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Message_ID', array(), array('context' => ''));
  $translations['ar:default']['d551a90cf17f924c4a028b8c483b9515'] = array(
    'source' => 'Also known as: !also.',
    'context' => '',
    'location' => '',
    'translation' => 'المعروف أيضا بـ: !also.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Also known as: !also.', array(), array('context' => ''));
  $translations['ar:default']['d59a5592f36ed8471cbac01d4628a596'] = array(
    'source' => 'In queue',
    'context' => '',
    'location' => '',
    'translation' => 'في القائمة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('In queue', array(), array('context' => ''));
  $translations['ar:default']['d5b90697882cf5d308d9f4b3175a35d1'] = array(
    'source' => 'term from !field_name',
    'context' => '',
    'location' => '',
    'translation' => 'term from !field_name',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('term from !field_name', array(), array('context' => ''));
  $translations['ar:default']['d5c20a760c506d4b9085e9b24cdeeb03'] = array(
    'source' => 'Number of users who register to use Checkdesk in any given month.',
    'context' => '',
    'location' => '/checkdesk/ar/admin/meedan/reports',
    'translation' => 'عدد المستخدمين الذين أنشؤوا حساباً على تشك دسك في شهر معين',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Number of users who register to use Checkdesk in any given month.', array(), array('context' => ''));
  $translations['ar:default']['d5c34c3920aac6484a88000f1278d380'] = array(
    'source' => '1 collaborator',
    'context' => '',
    'location' => '/ar/story-collaboration/35',
    'translation' => '1 مشارك',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('1 collaborator', array(), array('context' => ''));
  $translations['ar:default']['d5f1381c5f97f928df4ef8d18c2a27c0'] = array(
    'source' => 'Exceptions',
    'context' => '',
    'location' => '',
    'translation' => 'استثناءات',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Exceptions', array(), array('context' => ''));
  $translations['ar:default']['d61650d88e852cdc4213995f096efb42'] = array(
    'source' => 'Enter the title of a node to add it to the queue',
    'context' => '',
    'location' => '',
    'translation' => 'أدخل عنوان الموضوع لاضافته للقائمة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Enter the title of a node to add it to the queue', array(), array('context' => ''));
  $translations['ar:default']['d61f90998759fbe0853b5a139e1b27b5'] = array(
    'source' => '@count[2] more updates',
    'context' => '',
    'location' => '/meedan/meedan-checkdesk/drupal/ar/views/ajax',
    'translation' => '@count[2] تحديثات أخرى',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('@count[2] more updates', array(), array('context' => ''));
  $translations['ar:default']['d6221cced4d50d57423d2f7ad2cd73b1'] = array(
    'source' => 'Authmap ID',
    'context' => '',
    'location' => '',
    'translation' => 'Authmap ID',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Authmap ID', array(), array('context' => ''));
  $translations['ar:default']['d627c54e1f82fee9633f676861461102'] = array(
    'source' => 'Content revision is a history of changes to content.',
    'context' => '',
    'location' => '',
    'translation' => 'مراجعة المحتوى هي تاريخ التغييرات على المحتوى.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Content revision is a history of changes to content.', array(), array('context' => ''));
  $translations['ar:default']['d6310eebfab65d8526d101c39436a794'] = array(
    'source' => 'Cannot remove default value of field %table.%field: field doesn\'t exist.',
    'context' => '',
    'location' => '',
    'translation' => 'لا يمكن حذف القيمة المبدئية للحقل %table.%field : الحقل عير موجود.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Cannot remove default value of field %table.%field: field doesn\'t exist.', array(), array('context' => ''));
  $translations['ar:default']['d63152288f09c7b0f3bd0e20c458f759'] = array(
    'source' => 'Last comment uid',
    'context' => '',
    'location' => '',
    'translation' => 'اخر تعليق uid',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Last comment uid', array(), array('context' => ''));
  $translations['ar:default']['d653807c92fe0861047b2ae810672322'] = array(
    'source' => 'The time the Twitter account statuses were retrieved.',
    'context' => '',
    'location' => '',
    'translation' => 'الوقت الذي تم فيه حالات استرداد حساب تويتر.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The time the Twitter account statuses were retrieved.', array(), array('context' => ''));
  $translations['ar:default']['d6560dc5aa5225fe6a131656f7134c15'] = array(
    'source' => 'Whether or not the content is published.',
    'context' => '',
    'location' => '',
    'translation' => 'ما إذا نشر المحتوى أم لا.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Whether or not the content is published.', array(), array('context' => ''));
  $translations['ar:default']['d67850bd126f070221dcfd5fa6317043'] = array(
    'source' => 'Sign Up',
    'context' => '',
    'location' => '/ar/user/login',
    'translation' => 'أنشئ حسابا جديدا',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Sign Up', array(), array('context' => ''));
  $translations['ar:default']['d7a9b98095d75260203d6ee1129b3a4f'] = array(
    'source' => 'Relate content to the user who created it. This relationship will create one record for each content item created by the user.',
    'context' => '',
    'location' => '',
    'translation' => 'تتعلق المحتوى إلى المستخدم الذي أنشأه. وهذه العلاقة إنشاء سجل واحد لكل عنصر المحتوى الذي تم إنشاؤه من قبل المستخدم.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Relate content to the user who created it. This relationship will create one record for each content item created by the user.', array(), array('context' => ''));
  $translations['ar:default']['d7eecd470361c10a07f61185c6e7d8d8'] = array(
    'source' => 'By status',
    'context' => '',
    'location' => '',
    'translation' => 'الحالة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('By status', array(), array('context' => ''));
  $translations['ar:default']['d8314c5fa90e746b8f7d16cfd34d1374'] = array(
    'source' => 'Notify me by e-mail or on site when...',
    'context' => '',
    'location' => '/ar/user/1/notifications',
    'translation' => 'نبهني عبر البريد الإلكتروني أو على الموقع عندما...',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Notify me by e-mail or on site when...', array(), array('context' => ''));
  $translations['ar:default']['d846c284f573f71aa559b497b67a77b7'] = array(
    'source' => 'Unformatted list',
    'context' => '',
    'location' => '',
    'translation' => 'قائمه غير منسقه ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Unformatted list', array(), array('context' => ''));
  $translations['ar:default']['d85544fce402c7a2a96a48078edaf203'] = array(
    'source' => 'Facebook',
    'context' => '',
    'location' => '',
    'translation' => 'فيس بوك',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Facebook', array(), array('context' => ''));
  $translations['ar:default']['d8580f815b6c3fca34da24b45567a5b6'] = array(
    'source' => 'Automatic alias',
    'context' => '',
    'location' => '; sites/all/modules/contrib/pathauto/pathauto.js',
    'translation' => 'Automatic alias',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Automatic alias', array(), array('context' => ''));
  $translations['ar:default']['d87f8afac5e872899ecbf58386fe0ef3'] = array(
    'source' => 'Hello !recipient_name,

!actor has suggested this report "!node_title" to this story "!story_title".

Go to !story_url to compose a new update to the story using that report.

You can edit your notification settings from !recipient_url.

This was an auto-generated email from !site, please do not respond directly to this email.',
    'context' => '',
    'location' => '/meedan/meedan-checkdesk/drupal/index.php',
    'translation' => 'مرحباً !recipient_name،

قام !actor باقتراح إضافة هذا التقرير "!node_title" إلى هذا الموضوع "!story_title".

إذهب إلى !story_url لكتابة تحديث جديد على الخبر باستخدام ذاك التقرير.

بإمكانك تعديل إعدادات التنبيهات الخاصة بك من صفحة <a href="!recipient_url">الحساب الشخصي</a> الخاصة بك.

هذه رسالة مولدة بشكل تلقائي من !site، يرجى عدم الرد على هذه الرسالة.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Hello !recipient_name,

!actor has suggested this report "!node_title" to this story "!story_title".

Go to !story_url to compose a new update to the story using that report.

You can edit your notification settings from !recipient_url.

This was an auto-generated email from !site, please do not respond directly to this email.', array(), array('context' => ''));
  $translations['ar:default']['d8a95c40617a5beddfdf78958c1fd1b4'] = array(
    'source' => 'Flag spam',
    'context' => '',
    'location' => '',
    'translation' => 'تنبيه على سخام (سبام)',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Flag spam', array(), array('context' => ''));
  $translations['ar:default']['d8ad80fc484cbeb3ab8cbfd32b85affd'] = array(
    'source' => 'The picture of a user.',
    'context' => '',
    'location' => '',
    'translation' => 'صورة المستخدم',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The picture of a user.', array(), array('context' => ''));
  $translations['ar:default']['d8b2dc79341a8604e25015629916937b'] = array(
    'source' => 'Will be available to all users.',
    'context' => '',
    'location' => '',
    'translation' => 'سوف تكون متاحة لجميع المستخدمين.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Will be available to all users.', array(), array('context' => ''));
  $translations['ar:default']['d8cd31c2c86fd22b603fc5a3ff1cf1df'] = array(
    'source' => 'Separate title and URL',
    'context' => '',
    'location' => '',
    'translation' => 'عنوان  منفصل URL ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Separate title and URL', array(), array('context' => ''));
  $translations['ar:default']['d8da6e034b869c4d8e41074dc41ba845'] = array(
    'source' => 'Drag and drop reports here to compose your update',
    'context' => '',
    'location' => '',
    'translation' => 'إسحب التقارير هنا لإنشاء التحديث',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Drag and drop reports here to compose your update', array(), array('context' => ''));
  $translations['ar:default']['d8eb2d3eaaf091c42168abaca5bbae8a'] = array(
    'source' => 'Plural',
    'context' => '',
    'location' => '',
    'translation' => 'صيغة الجمع',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Plural', array(), array('context' => ''));
  $translations['ar:default']['d8f6d391ba573fe747a3360afb99904d'] = array(
    'source' => 'Sticky',
    'context' => '',
    'location' => '',
    'translation' => 'مثبّت',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Sticky', array(), array('context' => ''));
  $translations['ar:default']['d907c78fc2624acc9d788751db0a14b2'] = array(
    'source' => 'Display the view as a page, with a URL and menu links.',
    'context' => '',
    'location' => '',
    'translation' => 'Display the view as a page, with a URL and menu links.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Display the view as a page, with a URL and menu links.', array(), array('context' => ''));
  $translations['ar:default']['d918f99442796e88b6fe5ad32c217f76'] = array(
    'source' => 'Follow us',
    'context' => '',
    'location' => '/',
    'translation' => 'تابعنا',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Follow us', array(), array('context' => ''));
  $translations['ar:default']['d91935108ba692a3b09c881664d94581'] = array(
    'source' => 'Exclude report from this source',
    'context' => '',
    'location' => '',
    'translation' => 'استثنِ التقارير من هذا المصدر',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Exclude report from this source', array(), array('context' => ''));
  $translations['ar:default']['d91e1f6e1dc8ef8c7bc0b0e3b7371401'] = array(
    'source' => 'Taxonomy term chosen from autocomplete or select widget.',
    'context' => '',
    'location' => '',
    'translation' => 'مصطلح التصنيف المختار من الإكمال التلقائي أو القطعة المختارة.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Taxonomy term chosen from autocomplete or select widget.', array(), array('context' => ''));
  $translations['ar:default']['d94ac20de8b69547db523d3a835f4155'] = array(
    'source' => 'Flag for fact-checking',
    'context' => '',
    'location' => '',
    'translation' => 'تنبيه للتحقق من صحة المعلومات',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Flag for fact-checking', array(), array('context' => ''));
  $translations['ar:default']['d97477d6d8a838ead9348185bb5b6742'] = array(
    'source' => 'Thread',
    'context' => '',
    'location' => '',
    'translation' => 'خيط',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Thread', array(), array('context' => ''));
  $translations['ar:default']['d98632f555f6bc0890ccb620a6c6d27b'] = array(
    'source' => 'Contextual filter',
    'context' => '',
    'location' => '',
    'translation' => 'Contextual filter',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Contextual filter', array(), array('context' => ''));
  $translations['ar:default']['d9ad9cd108ce715c87eac04c727919b8'] = array(
    'source' => 'The \'Message_ID\' e-mail address.',
    'context' => '',
    'location' => '/ar',
    'translation' => 'The \'Message_ID\' e-mail address.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The \'Message_ID\' e-mail address.', array(), array('context' => ''));
  $translations['ar:default']['d9c008df0b90b1e6cc061784c26e73d2'] = array(
    'source' => 'Wrong username or password.',
    'context' => '',
    'location' => '',
    'translation' => 'خطأ في اسم المستخدم أو كلمة المرور.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Wrong username or password.', array(), array('context' => ''));
  $translations['ar:default']['d9e8945a7b0e43bcac1b8b4f7f18fff7'] = array(
    'source' => 'Queue title',
    'context' => '',
    'location' => '',
    'translation' => 'عنوان القائمة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Queue title', array(), array('context' => ''));
  $translations['ar:default']['da1cf52839afbcda4c25d4b68b0feb0d'] = array(
    'source' => 'The profile of a user.',
    'context' => '',
    'location' => '',
    'translation' => 'الملف الشخصي للمستخدم',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The profile of a user.', array(), array('context' => ''));
  $translations['ar:default']['da583538f76deb6e2defe0ed3dcdf350'] = array(
    'source' => '<a href="!user_url" class="actor">!username</a> has turned on fact-checking for a <a href="!report_url">report</a>',
    'context' => '',
    'location' => '/ar/story-collaboration/12311',
    'translation' => 'لقد فعل <a href="!user_url">!username</a>التحقق من صحة المعلومات  <a href="!report_url">للتقرير</a>',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('<a href="!user_url" class="actor">!username</a> has turned on fact-checking for a <a href="!report_url">report</a>', array(), array('context' => ''));
  $translations['ar:default']['da73d250a9609866bd3e3ba11d7180f1'] = array(
    'source' => 'Obtains a single representative node for each term, according to a chosen sort criterion.',
    'context' => '',
    'location' => '/ar',
    'translation' => 'Obtains a single representative node for each term, according to a chosen sort criterion.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Obtains a single representative node for each term, according to a chosen sort criterion.', array(), array('context' => ''));
  $translations['ar:default']['da83080ddaefc008f3de01b20a111043'] = array(
    'source' => 'Search Terms',
    'context' => '',
    'location' => '',
    'translation' => 'مصطلحات البحث',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Search Terms', array(), array('context' => ''));
  $translations['ar:default']['db3af42ba64b595db6ab3ea999fe0bb1'] = array(
    'source' => 'Drafts',
    'context' => '',
    'location' => '/ar/search?field_tags_tid=All&type=post',
    'translation' => 'مسودات',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Drafts', array(), array('context' => ''));
  $translations['ar:default']['dbbd2a35bb08788c9180b67dd1e86a95'] = array(
    'source' => 'Reply to',
    'context' => '',
    'location' => '',
    'translation' => 'الرد على',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Reply to', array(), array('context' => ''));
  $translations['ar:default']['dbcd2a2e0c7efa9ebf624acf34765919'] = array(
    'source' => 'Quickly add newsworthy links from social media. Then you can fact-check and publish them.',
    'context' => '',
    'location' => 'sites/all/modules/custom/checkdesk_core/js/tour/checkdesk-tour.js; sites/all/modules/custom/checkdesk_core/js/checkdesk_tour.js; sites/all/themes/checkdesk/assets/js/tour.js; sites/all/modules/custom/checkdesk_tour/js/tour.js',
    'translation' => 'أضف روابط تستحق التغطية الإعلامية من الشبكات الاجتماعية بسهولة. من ثم يمكنك التحقق من صحتها ونشرها.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Quickly add newsworthy links from social media. Then you can fact-check and publish them.', array(), array('context' => ''));
  $translations['ar:default']['dbd729afa8c883173551f24d134396dd'] = array(
    'source' => 'Autocomplete (Tags style)',
    'context' => '',
    'location' => '',
    'translation' => 'الإكمال التلقائي (نمط الكلمات)',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Autocomplete (Tags style)', array(), array('context' => ''));
  $translations['ar:default']['dc210c8f3bf13f3402fa2304500b6fa6'] = array(
    'source' => 'The date the content was posted.',
    'context' => '',
    'location' => '',
    'translation' => 'التاريخ الذي تم نشر المحتوى فيه ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The date the content was posted.', array(), array('context' => ''));
  $translations['ar:default']['dc5b21fbcb352459af80afaa18e22ebe'] = array(
    'source' => 'Jump menu',
    'context' => '',
    'location' => '',
    'translation' => 'قائمة القفز',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Jump menu', array(), array('context' => ''));
  $translations['ar:default']['dca21c097a636a622d51837672257170'] = array(
    'source' => 'Published on live blog under ',
    'context' => '',
    'location' => '/',
    'translation' => 'نُشر على المدونة المباشرة في ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Published on live blog under ', array(), array('context' => ''));
  $translations['ar:default']['dcb8e44eea738fd288d71953cc35a46b'] = array(
    'source' => 'Allow use of checkboxes/radio buttons for exposed filters',
    'context' => '',
    'location' => '',
    'translation' => 'السماح باستخدام خانات / أزارير الراديو يتعرض للمرشحات',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Allow use of checkboxes/radio buttons for exposed filters', array(), array('context' => ''));
  $translations['ar:default']['dd1f775e443ff3b9a89270713580a51b'] = array(
    'source' => 'Previous',
    'context' => '',
    'location' => '',
    'translation' => 'السابق',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Previous', array(), array('context' => ''));
  $translations['ar:default']['dd88b939f40b727789c7df4711a1ed10'] = array(
    'source' => 'The machine name of the taxonomy vocabulary.',
    'context' => '',
    'location' => '',
    'translation' => 'اسم الجهاز من مفردات التصنيف.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The machine name of the taxonomy vocabulary.', array(), array('context' => ''));
  $translations['ar:default']['ddb67f6cad9d36d2acf42898c4fe58f5'] = array(
    'source' => 'Component name',
    'context' => '',
    'location' => '',
    'translation' => 'اسم العنصر',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Component name', array(), array('context' => ''));
  $translations['ar:default']['de296b5c9e80f87c9aa0bdc1e4ab54a5'] = array(
    'source' => 'Date and time of when the comment was created.',
    'context' => '',
    'location' => '',
    'translation' => 'تاريخ ووقت إنشاء التعليق.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Date and time of when the comment was created.', array(), array('context' => ''));
  $translations['ar:default']['de7412cdfd3fe1d94e10cb1cd5eccf21'] = array(
    'source' => 'Entity Reference list',
    'context' => '',
    'location' => '',
    'translation' => ' القائمة المرجعيه للكيان',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Entity Reference list', array(), array('context' => ''));
  $translations['ar:default']['de9d51d3a0f3e07e9705830c4750d992'] = array(
    'source' => 'Expose operator',
    'context' => '',
    'location' => '',
    'translation' => 'كشف العامل',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Expose operator', array(), array('context' => ''));
  $translations['ar:default']['dece33f40b906dff54d607ff1fea5648'] = array(
    'source' => 'Heartbeat activity buttons',
    'context' => '',
    'location' => '/ar',
    'translation' => 'Heartbeat activity buttons',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Heartbeat activity buttons', array(), array('context' => ''));
  $translations['ar:default']['def87142a83fd7ddf453137abca671c4'] = array(
    'source' => 'The description associated with a taxonomy term.',
    'context' => '',
    'location' => '',
    'translation' => 'الوصف المرتبط بمصطلح التصنيف',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The description associated with a taxonomy term.', array(), array('context' => ''));
  $translations['ar:default']['df8cbabeb6dc92bc93fb409a5bcab4d9'] = array(
    'source' => 'URL path',
    'context' => '',
    'location' => '',
    'translation' => 'مسار الرابط',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('URL path', array(), array('context' => ''));
  $translations['ar:default']['dfad28130ea167c858a35aacbf372209'] = array(
    'source' => 'By e-mail: ',
    'context' => '',
    'location' => '/ar',
    'translation' => 'عن طريق البريد الالكتروني: ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('By e-mail: ', array(), array('context' => ''));
  $translations['ar:default']['dfafb9f1cf74ea1a357330e935a6e793'] = array(
    'source' => 'The \'Subject\' field of the e-mail.',
    'context' => '',
    'location' => '/ar',
    'translation' => 'و\'الموضوع\' الميدانية للبريد الإلكتروني.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The \'Subject\' field of the e-mail.', array(), array('context' => ''));
  $translations['ar:default']['dfba89a600b608b2b724efe1f06f599a'] = array(
    'source' => 'Story',
    'context' => '',
    'location' => '/ar',
    'translation' => 'موضوع',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Story', array(), array('context' => ''));
  $translations['ar:default']['dfd0a82c4bf37b1e90b690a22a20692e'] = array(
    'source' => 'Offset',
    'context' => '',
    'location' => '',
    'translation' => 'عوض',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Offset', array(), array('context' => ''));
  $translations['ar:default']['dfd87bd34b4599aaaef6d0f2c8b6e3d7'] = array(
    'source' => 'Edit profile',
    'context' => '',
    'location' => '/ar/user',
    'translation' => 'تحرير ملف المستخدم',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Edit profile', array(), array('context' => ''));
  $translations['ar:default']['e0070a483b18685510cb5d1be6bdbf7a'] = array(
    'source' => 'New update on a story I followed',
    'context' => '',
    'location' => '/ar/node/add/discussion',
    'translation' => 'تحديث جديد لموضوع متابع',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('New update on a story I followed', array(), array('context' => ''));
  $translations['ar:default']['e0315a8fafe9227d25c5783f0598a12a'] = array(
    'source' => 'This report was flagged as spam.',
    'context' => '',
    'location' => '/ar/node/flag/confirm/flag/spam/249/ajax',
    'translation' => 'تم تنبيه المشرف على أن هذا التقرير سبام (سخام).',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('This report was flagged as spam.', array(), array('context' => ''));
  $translations['ar:default']['e07379d3f0614a4e80924dde9abc613a'] = array(
    'source' => 'The user activity ID',
    'context' => '',
    'location' => '/ar',
    'translation' => 'هوية المستخدم النشط',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The user activity ID', array(), array('context' => ''));
  $translations['ar:default']['e0ba496c9db89536b9432cd9e8d82e82'] = array(
    'source' => 'Whether the node is promoted to the frontpage.',
    'context' => '',
    'location' => '',
    'translation' => 'ما إذا كان يتم ترويج العقدة إلى صفحتها الاولى.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Whether the node is promoted to the frontpage.', array(), array('context' => ''));
  $translations['ar:default']['e1334ffe1bbc972f1bb751a5c5604877'] = array(
    'source' => '<span>@count</span> results. Drag and drop the best ones.',
    'context' => '',
    'location' => '/ar/node/add/post?sort_order=DESC&title=rancid&title_op=contains&source=&source_op=contains; sites/all/themes/checkdesk/assets/js/report.js',
    'translation' => '<span>@count</span> نتائج. يمكنك سحب تقاريرك المفضلة لاستخدامها. ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('<span>@count</span> results. Drag and drop the best ones.', array(), array('context' => ''));
  $translations['ar:default']['e1ba2665bdacc1fee125d13ae7a2310f'] = array(
    'source' => 'Entity ID',
    'context' => '',
    'location' => '',
    'translation' => 'هوية الكيان ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Entity ID', array(), array('context' => ''));
  $translations['ar:default']['e2222b34c48c46b1107ef459e4b675bc'] = array(
    'source' => 'Bring in data about the user in the activity.',
    'context' => '',
    'location' => '/ar',
    'translation' => 'جلب بيانات عن المستخدم في النشاط.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Bring in data about the user in the activity.', array(), array('context' => ''));
  $translations['ar:default']['e24d432a27f16b44c4428b0b9d34a775'] = array(
    'source' => 'When content is viewed by an authenticated user',
    'context' => '',
    'location' => '',
    'translation' => 'عندما يعرض مستخدم مستوثق المحتوى',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('When content is viewed by an authenticated user', array(), array('context' => ''));
  $translations['ar:default']['e25f7169df87db65d143834798c0f5b7'] = array(
    'source' => 'Date',
    'context' => 'Sort order',
    'location' => '',
    'translation' => 'التاريخ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Date', array(), array('context' => 'Sort order'));
  $translations['ar:default']['e28dbc93928c82849c99bd101ddb78ce'] = array(
    'source' => 'Cannot set default value of field %table.%field: field doesn\'t exist.',
    'context' => '',
    'location' => '',
    'translation' => 'لا يمكن تعيين القيمة المبدئية للحقل %table.%field : الحقل عير موجود.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Cannot set default value of field %table.%field: field doesn\'t exist.', array(), array('context' => ''));
  $translations['ar:default']['e2c0dc35d49a73ac9aaf127f81045531'] = array(
    'source' => 'Hello !recipient_name,

!actor has turned on fact-checking for a <a href="!url">report</a> you submitted.

You can edit your notification settings from your <a href="!recipient_url">profile page</a>.

This was an auto-generated email from !site; please do not respond directly to this email.',
    'context' => '',
    'location' => '/meedan/meedan-checkdesk/drupal/index.php',
    'translation' => 'مرحباً !recipient_name،

قام !actor بتفعيل التحقق من صحة المعلومات على <a href="!url">التقرير</a> الذي أرسلته.

بإمكانك تعديل إعدادات التنبيهات الخاصة بك من صفحة <a href="!recipient_url">الحساب الشخصي</a> الخاصة بك.

هذه رسالة مولدة بشكل تلقائي من !site، يرجى عدم الرد على هذه الرسالة.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Hello !recipient_name,

!actor has turned on fact-checking for a <a href="!url">report</a> you submitted.

You can edit your notification settings from your <a href="!recipient_url">profile page</a>.

This was an auto-generated email from !site; please do not respond directly to this email.', array(), array('context' => ''));
  $translations['ar:default']['e2cd09bde3b359b598993d1cee141dc2'] = array(
    'source' => 'To add a link, you need to log in.',
    'context' => '',
    'location' => '/ar/user/login?destination=node/add/media%3Fmeedan_bookmarklet%3D1%26meedan_bookmarklet_prepopulate%5Bbody%5D%3D%26meedan_bookmarklet_prepopulate%5Bfield_link%5D%3Dhttp%253A//www.youtube.com/&meedan_bookmarklet=1&meedan_bookmarklet_prepopulate[body]=&meedan_bookmarklet_prepopulate[field_link]=http%3A//www.youtube.com/',
    'translation' => 'لإضافة رابط، الرجاء تسجيل الدخول.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('To add a link, you need to log in.', array(), array('context' => ''));
  $translations['ar:default']['e3572c6da47f7f14b8d4617bc844d408'] = array(
    'source' => 'In reply to user name',
    'context' => '',
    'location' => '/ar',
    'translation' => 'ردا على اسم المستخدم',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('In reply to user name', array(), array('context' => ''));
  $translations['ar:default']['e391af11b84bbb4b2a74954dd40a6362'] = array(
    'source' => 'Module/Theme/Theme engine',
    'context' => '',
    'location' => '',
    'translation' => 'وحدة / سمة / سمة المحرك',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Module/Theme/Theme engine', array(), array('context' => ''));
  $translations['ar:default']['e3ac3a2a46ddcbbd7d1d77290c3efd8c'] = array(
    'source' => 'You will be notified here when your reports are published or fact-checked.',
    'context' => '',
    'location' => '/ar/user',
    'translation' => 'سيتم تنبيهك هنا عندما ننشر تقاريرك أو نقوم بالتحقق من صحتها.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('You will be notified here when your reports are published or fact-checked.', array(), array('context' => ''));
  $translations['ar:default']['e3c6938d86ee2808c22d4389ead30229'] = array(
    'source' => 'Fact-checking has been disabled for <a href="[node:url:unaliased]"> [node:author] report </a>. ',
    'context' => '',
    'location' => '/ar/flag/unflag/factcheck_journalist/1922?destination=liveblog&token=Zs8iOqhZDL6DkX0iupYAwjtKIR9PJQffS_SJuh2VuQg',
    'translation' => 'تم إلغاء التحقق من صحة معلومات <a href="[node:url:unaliased]"> تقرير [node:author] </a>.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Fact-checking has been disabled for <a href="[node:url:unaliased]"> [node:author] report </a>. ', array(), array('context' => ''));
  $translations['ar:default']['e3c79b7f9f0952f9c388ab05aff77a99'] = array(
    'source' => 'l M d, Y \\a\\t g:ia',
    'context' => '',
    'location' => '/',
    'translation' => '\\ف\\ي M d, Y \\ا\\ل\\س\\ا\\ع\\ة g:i a',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('l M d, Y \a\t g:ia', array(), array('context' => ''));
  $translations['ar:default']['e3ddbb8664fe7abd838fbb801b08dd10'] = array(
    'source' => 'Access the views administration pages.',
    'context' => '',
    'location' => '',
    'translation' => 'الوصول إلى صفحات إدارة الرؤى.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Access the views administration pages.', array(), array('context' => ''));
  $translations['ar:default']['e3fda75fb6db965037686426fee5973b'] = array(
    'source' => 'Dashboard (inactive)',
    'context' => '',
    'location' => '/ar',
    'translation' => 'لوحة التحكم (غير نشط)',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Dashboard (inactive)', array(), array('context' => ''));
  $translations['ar:default']['e43347b663b27dfa588df4e4501269d2'] = array(
    'source' => 'The full translation string.',
    'context' => '',
    'location' => '',
    'translation' => 'الترجمه الكامله للمقطع',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The full translation string.', array(), array('context' => ''));
  $translations['ar:default']['e495d98202a6becb3d35f6c64f6aa159'] = array(
    'source' => 'The taxonomy vocabulary description',
    'context' => '',
    'location' => '',
    'translation' => 'وصف مفردات التصنيف',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The taxonomy vocabulary description', array(), array('context' => ''));
  $translations['ar:default']['e4b7709df76cd16f5ca44273fb9973a8'] = array(
    'source' => 'This media contains graphic imagery which may be considered offensive.',
    'context' => '',
    'location' => '/ar/reports',
    'translation' => 'هذا التقرير يحتوي صوراً صادمة يمكن أن تعتبر مسيئة أو جارحة.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('This media contains graphic imagery which may be considered offensive.', array(), array('context' => ''));
  $translations['ar:default']['e55f75a29310d7b60f7ac1d390c8ae42'] = array(
    'source' => 'Module',
    'context' => '',
    'location' => '',
    'translation' => 'وحدة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Module', array(), array('context' => ''));
  $translations['ar:default']['e59278675b8f1e052b22b7e5e7d65da7'] = array(
    'source' => 'Day of week',
    'context' => '',
    'location' => '',
    'translation' => 'يوم الأسبوع',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Day of week', array(), array('context' => ''));
  $translations['ar:default']['e5ef68ea3f0d4fd4bba79bf8259e5b87'] = array(
    'source' => 'Report I submitted is published in an update',
    'context' => '',
    'location' => '/ar',
    'translation' => 'نشر تقرير أرسلته',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Report I submitted is published in an update', array(), array('context' => ''));
  $translations['ar:default']['e62e49d2da72ebb9e88ed8f7c1e1433a'] = array(
    'source' => 'Whether or not the content is sticky.',
    'context' => '',
    'location' => '',
    'translation' => 'ما إذا كان المحتوى مثبتاً أعلى الصفحة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Whether or not the content is sticky.', array(), array('context' => ''));
  $translations['ar:default']['e6379631a3783ffe1a076b941c93f264'] = array(
    'source' => 'Heartbeat activity',
    'context' => '',
    'location' => '/ar',
    'translation' => 'Heartbeat activity',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Heartbeat activity', array(), array('context' => ''));
  $translations['ar:default']['e63c4d4f19d79e32fa4ca3eee94ba383'] = array(
    'source' => 'Reset all filters',
    'context' => '',
    'location' => '/ar',
    'translation' => 'أعد الضبط',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Reset all filters', array(), array('context' => ''));
  $translations['ar:default']['e6ada1d33039346f785b17150e35d02e'] = array(
    'source' => 'blog about it',
    'context' => '',
    'location' => '/ar/meedan_bookmarklet/message?meedan_bookmarklet=1&meedan_bookmarklet_submitted=1&meedan_bookmarklet_nid=1785&meedan_bookmarklet_url=http%3A//www.google.com',
    'translation' => 'التدوين عنه',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('blog about it', array(), array('context' => ''));
  $translations['ar:default']['e6b0ce57d13d4c7225f0328163a1f91d'] = array(
    'source' => '@entity using @field',
    'context' => '',
    'location' => '',
    'translation' => '@entity using @field',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('@entity using @field', array(), array('context' => ''));
  $translations['ar:default']['e6c3cfc2542b6d5bdb3f1feca21a1f11'] = array(
    'source' => 'Provide a link to export the node with Node export.',
    'context' => '',
    'location' => '/ar',
    'translation' => 'تقديم وصلة لتصدير العقدة مع عقدة التصدير.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Provide a link to export the node with Node export.', array(), array('context' => ''));
  $translations['ar:default']['e6cab9b855af4f8c9576d0c9cc58a3f5'] = array(
    'source' => 'User module history view element.',
    'context' => '',
    'location' => '',
    'translation' => 'User module history view element.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('User module history view element.', array(), array('context' => ''));
  $translations['ar:default']['e6e9421ff606ed4230654acce957b4db'] = array(
    'source' => 'Suggest Report "!title" to Story',
    'context' => '',
    'location' => '/ar/node/240/checkdesk/modal/suggest/ajax',
    'translation' => 'اقترح إضافة التقرير "!title" إلى موضوع',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Suggest Report "!title" to Story', array(), array('context' => ''));
  $translations['ar:default']['e721cc8bb94a894b16b35e09729327bb'] = array(
    'source' => 'Filter the results of "Taxonomy: Term" by the parent pid.',
    'context' => '',
    'location' => '',
    'translation' => 'Filter the results of "Taxonomy: Term" by the parent pid.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Filter the results of "Taxonomy: Term" by the parent pid.', array(), array('context' => ''));
  $translations['ar:default']['e74dd916dd0283bbf57a4a8685b46e67'] = array(
    'source' => 'An exposed form that only renders a view if the form contains user input.',
    'context' => '',
    'location' => '',
    'translation' => 'نموذج يتعرض يجعل فقط وجهة نظر إذا كان النموذج يحتوي على إدخال المستخدم.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('An exposed form that only renders a view if the form contains user input.', array(), array('context' => ''));
  $translations['ar:default']['e779b81af9f84624ad8bccb442987fef'] = array(
    'source' => 'The version of Drupal core that this string is for.',
    'context' => '',
    'location' => '',
    'translation' => 'The version of Drupal core that this string is for.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The version of Drupal core that this string is for.', array(), array('context' => ''));
  $translations['ar:default']['e8063efa59202f5ec51bd5598c49a38f'] = array(
    'source' => 'Link class',
    'context' => '',
    'location' => '',
    'translation' => 'صنف الرابط',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Link class', array(), array('context' => ''));
  $translations['ar:default']['e88b8b07c61f8b60c559a5f19ef180e8'] = array(
    'source' => 'Revert link',
    'context' => '',
    'location' => '',
    'translation' => 'رابط الإعادة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Revert link', array(), array('context' => ''));
  $translations['ar:default']['e8b4b40ec3622e371789b790caabc083'] = array(
    'source' => 'Shuffle',
    'context' => '',
    'location' => '',
    'translation' => 'تبديل عشوائي',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Shuffle', array(), array('context' => ''));
  $translations['ar:default']['e8cf85cec621489ec026f7e06c67eb4e'] = array(
    'source' => 'Delete item',
    'context' => '',
    'location' => '',
    'translation' => 'احذف العنصر',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Delete item', array(), array('context' => ''));
  $translations['ar:default']['e90e718445f3644ed84f8237defb9f53'] = array(
    'source' => 'Heartbeat Activity Entity',
    'context' => '',
    'location' => '/ar',
    'translation' => 'نبضات نشاط الكيان',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Heartbeat Activity Entity', array(), array('context' => ''));
  $translations['ar:default']['e952fc49a16abb3562e0e3d202557c28'] = array(
    'source' => 'Replies to my comments',
    'context' => '',
    'location' => '/ar',
    'translation' => 'الردود على تعليقاتي',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Replies to my comments', array(), array('context' => ''));
  $translations['ar:default']['e958bec948086a4d0460b487867ecba2'] = array(
    'source' => 'Exception value',
    'context' => '',
    'location' => '',
    'translation' => 'قيمة الاستثناء',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Exception value', array(), array('context' => ''));
  $translations['ar:default']['e96a26985f47a8b0545d3ec16b59c204'] = array(
    'source' => 'Fact-checking has been enabled for <a href="[node:url:unaliased]"> [node:author] report </a>. ',
    'context' => '',
    'location' => '/ar/flag/flag/factcheck_journalist/1922?destination=liveblog&token=Zs8iOqhZDL6DkX0iupYAwjtKIR9PJQffS_SJuh2VuQg',
    'translation' => 'تم تفعيل التحقق من صحة معلومات <a href="[node:url:unaliased]"> تقرير [node:author] </a>.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Fact-checking has been enabled for <a href="[node:url:unaliased]"> [node:author] report </a>. ', array(), array('context' => ''));
  $translations['ar:default']['e98579af2360a4d255009907e3f19427'] = array(
    'source' => 'Display the view as a block.',
    'context' => '',
    'location' => '',
    'translation' => 'عرض طريقة العرض بشكل غير متاح ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Display the view as a block.', array(), array('context' => ''));
  $translations['ar:default']['e9dfd31cc505d51fc26975250750deab'] = array(
    'source' => 'Spam',
    'context' => '',
    'location' => '/ar/node/22/edit?destination=liveblog',
    'translation' => 'سخام (سبام)',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Spam', array(), array('context' => ''));
  $translations['ar:default']['ea2337393dd487ccd50084e2506638b8'] = array(
    'source' => '<a class="actor" href="!user_url">!username</a> added a new <a href="!story_url">story</a>',
    'context' => '',
    'location' => '/ar',
    'translation' => 'قام <a class="actor" href="!user_url">!username</a> بإضافة <a href="!story_url">موضوع جديد</a>',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('<a class="actor" href="!user_url">!username</a> added a new <a href="!story_url">story</a>', array(), array('context' => ''));
  $translations['ar:default']['ea37eca0174afc54031c5874e7d8f90e'] = array(
    'source' => 'The most recent of last comment posted or node updated time.',
    'context' => '',
    'location' => '',
    'translation' => 'نشر أحدث تعليق مشاركة أو عقدة الوقت المحدثة.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The most recent of last comment posted or node updated time.', array(), array('context' => ''));
  $translations['ar:default']['ea4a2f365b746aaea658037876ebd11b'] = array(
    'source' => 'Display the standard add comment link used on regular nodes, which will only display if the viewing user has access to add a comment.',
    'context' => '',
    'location' => '',
    'translation' => 'عرض اضف تعليق القياسية المستخدمة في العقد الرابط العادية، التي سيتم عرض فقط إذا كان المستخدم لديه حق الوصول إلى الملف إضافة تعليق.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Display the standard add comment link used on regular nodes, which will only display if the viewing user has access to add a comment.', array(), array('context' => ''));
  $translations['ar:default']['ea96be9e75d8d3d690aedae5040edf2f'] = array(
    'source' => 'Relationships',
    'context' => '',
    'location' => '',
    'translation' => 'علاقات',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Relationships', array(), array('context' => ''));
  $translations['ar:default']['eaa7c88f5c12467242826acb2d7a3ea7'] = array(
    'source' => 'relationships',
    'context' => '',
    'location' => '',
    'translation' => 'علاقات',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('relationships', array(), array('context' => ''));
  $translations['ar:default']['eaa9fe407fdfe0eb43e52cdd784267f0'] = array(
    'source' => '<?php
print theme(\'views_autorefresh\', array(
  \'interval\' => 5000, 
  \'ping\' => array(\'ping_base_path\' => drupal_get_path(\'module\', \'checkdesk_core\') . \'/autorefresh/liveblog.php?type=post\'),
  \'incremental\' => FALSE,
));
?>',
    'context' => '',
    'location' => '/ar',
    'translation' => '<?php
print theme(\'views_autorefresh\', array(
  \'interval\' => 5000, 
  \'ping\' => array(\'ping_base_path\' => drupal_get_path(\'module\', \'checkdesk_core\') . \'/autorefresh/liveblog.php?type=post\'),
  \'incremental\' => FALSE,
));
?>',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('<?php
print theme(\'views_autorefresh\', array(
  \'interval\' => 5000, 
  \'ping\' => array(\'ping_base_path\' => drupal_get_path(\'module\', \'checkdesk_core\') . \'/autorefresh/liveblog.php?type=post\'),
  \'incremental\' => FALSE,
));
?>', array(), array('context' => ''));
  $translations['ar:default']['eaaad63b44506169bd67fd4a4f668f3d'] = array(
    'source' => 'fact-check it',
    'context' => '',
    'location' => '/ar/meedan_bookmarklet/message?meedan_bookmarklet=1&meedan_bookmarklet_submitted=1&meedan_bookmarklet_nid=1785&meedan_bookmarklet_url=http%3A//www.google.com',
    'translation' => 'التحقق من صحة المعلومات',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('fact-check it', array(), array('context' => ''));
  $translations['ar:default']['eace7c32b0eb64e3f90799506bb3ec2c'] = array(
    'source' => '<a href="@user">!user</a> added this on <time class="date-time" datetime="!timestamp">!datetime</time>',
    'context' => '',
    'location' => '',
    'translation' => '<a href="@user">!user</a> أضاف هذا التقرير <time class="date-time" datetime="!timestamp">!datetime</time>',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('<a href="@user">!user</a> added this on <time class="date-time" datetime="!timestamp">!datetime</time>', array(), array('context' => ''));
  $translations['ar:default']['eb2a81b101ab8989ff5b1c54990c87e9'] = array(
    'source' => 'User provided identifier',
    'context' => '',
    'location' => '',
    'translation' => 'المعرّف المقدم من المستخدم',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('User provided identifier', array(), array('context' => ''));
  $translations['ar:default']['eb5694d7430dcdf414e8d64bd6557f81'] = array(
    'source' => 'Date in the form of YYYYMM.',
    'context' => '',
    'location' => '',
    'translation' => 'التاريخ بصيغة YYYYMM.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Date in the form of YYYYMM.', array(), array('context' => ''));
  $translations['ar:default']['eba67aa97f2707e6248c4f2e9814ae3b'] = array(
    'source' => 'Suggest to Story',
    'context' => '',
    'location' => '/ar/reports',
    'translation' => 'اقترح الإضافة إلى موضوع',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Suggest to Story', array(), array('context' => ''));
  $translations['ar:default']['ebb6654d52f77404a016380817b2b5fe'] = array(
    'source' => 'Provides a select list for Views filters on this field. This should not be used when there are over 100 entities, as it might cause an out of memory error.',
    'context' => '',
    'location' => '',
    'translation' => 'يوفر قائمة مختارة للمرشحات المشاهدات في هذا المجال. هذا لا ينبغي أن تستخدم عندما يكون هناك أكثر من 100 جهة، كما أنه قد يسبب خطأ من الذاكرة.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Provides a select list for Views filters on this field. This should not be used when there are over 100 entities, as it might cause an out of memory error.', array(), array('context' => ''));
  $translations['ar:default']['ebbeb4e92439545bc499bc30123cef1f'] = array(
    'source' => 'Mime type',
    'context' => '',
    'location' => '',
    'translation' => 'نوع MIME',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Mime type', array(), array('context' => ''));
  $translations['ar:default']['ebfeefb07a6d2be499d178c3aa6e70cb'] = array(
    'source' => 'Display the message of the activity rss.',
    'context' => '',
    'location' => '/ar',
    'translation' => 'Display the message of the activity rss.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Display the message of the activity rss.', array(), array('context' => ''));
  $translations['ar:default']['ec2b507ed98722eed260843920bacb9d'] = array(
    'source' => 'Edit @type <em>@title</em>',
    'context' => '',
    'location' => '/meedan/meedan-checkdesk/drupal/ar/node/886/edit',
    'translation' => 'تعديل @type <em>@title</em>',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Edit @type <em>@title</em>', array(), array('context' => ''));
  $translations['ar:default']['ec2d438797f112f9fb29ae41ca42256a'] = array(
    'source' => 'Embeds content for oEmbed-enabled web addresses and turns the rest, and e-mail addresses, into clickable links.',
    'context' => '',
    'location' => '/ar',
    'translation' => 'Embeds content for oEmbed-enabled web addresses and turns the rest, and e-mail addresses, into clickable links.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Embeds content for oEmbed-enabled web addresses and turns the rest, and e-mail addresses, into clickable links.', array(), array('context' => ''));
  $translations['ar:default']['ec415c2d442855d1cb085cf5cdaedfc8'] = array(
    'source' => 'Whether comments are allowed on this node: 0 = no, 1 = closed (read only), 2 = open (read/write).',
    'context' => '',
    'location' => '',
    'translation' => 'Whether comments are allowed on this node: 0 = no, 1 = closed (read only), 2 = open (read/write).',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Whether comments are allowed on this node: 0 = no, 1 = closed (read only), 2 = open (read/write).', array(), array('context' => ''));
  $translations['ar:default']['ec6780d4cb4e18b6408dfe7295be6869'] = array(
    'source' => 'Relate all content associated with a media source. This can produce duplicate entries if a source is used in multiple nodes.',
    'context' => '',
    'location' => '/ar',
    'translation' => 'تتصل جميع المحتويات المرتبطة مصدر إعلامي. وهذا يمكن أن ينتج إدخالات مكررة إذا تم استخدام مصدر في العقد متعددة.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Relate all content associated with a media source. This can produce duplicate entries if a source is used in multiple nodes.', array(), array('context' => ''));
  $translations['ar:default']['ecc0c39a0c302406fcf99a09ad47d8ee'] = array(
    'source' => 'Referencing entity',
    'context' => '',
    'location' => '',
    'translation' => 'مراجعة الكيان ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Referencing entity', array(), array('context' => ''));
  $translations['ar:default']['ecd5dedd78f53a64220296d51c7b41cb'] = array(
    'source' => 'Retrieve lost password',
    'context' => '',
    'location' => '/ar/user/password',
    'translation' => 'إسترجع كلمة السر',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Retrieve lost password', array(), array('context' => ''));
  $translations['ar:default']['ed42606c7c0b96f4b4106330a94e22a5'] = array(
    'source' => 'Date and time of when the last comment was posted.',
    'context' => '',
    'location' => '',
    'translation' => 'تاريخ ووقت نشر آخر تعليق.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Date and time of when the last comment was posted.', array(), array('context' => ''));
  $translations['ar:default']['ed5e362bcdc4e0c0e70a24adfdeb54de'] = array(
    'source' => 'Bulk operations',
    'context' => '',
    'location' => '',
    'translation' => ' مجمل العمليات',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Bulk operations', array(), array('context' => ''));
  $translations['ar:default']['ed5e3ef6d80ebd48bd11cb863e64c7db'] = array(
    'source' => 'The message template',
    'context' => '',
    'location' => '/ar',
    'translation' => 'قالب الرسالة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The message template', array(), array('context' => ''));
  $translations['ar:default']['ed7fe09c26c31543399629e0f4bfe42c'] = array(
    'source' => '@entity_label flag counter',
    'context' => '',
    'location' => '',
    'translation' => '@entity_label flag counter',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('@entity_label flag counter', array(), array('context' => ''));
  $translations['ar:default']['ed8f37420215baa5c661ef7b9fbc2447'] = array(
    'source' => 'Embed this report',
    'context' => '',
    'location' => '/ar/node/15423',
    'translation' => 'ضمّن هذا التقرير على موقعك',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Embed this report', array(), array('context' => ''));
  $translations['ar:default']['ed97ff1d54fdc7567dbf4a49346a7e0a'] = array(
    'source' => 'Remark or note that refers to a node.',
    'context' => '',
    'location' => '',
    'translation' => 'ملاحظة أو ملاحظة يشير إلى العقدة.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Remark or note that refers to a node.', array(), array('context' => ''));
  $translations['ar:default']['eddce90451691eaf62085b5b8d004f73'] = array(
    'source' => 'A file that is associated with this comment, usually because it is in a field on the comment.',
    'context' => '',
    'location' => '',
    'translation' => 'ملف مقترن بهذا التعليق، لأنه عادة في حقل على التعليق.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('A file that is associated with this comment, usually because it is in a field on the comment.', array(), array('context' => ''));
  $translations['ar:default']['edfc4d97ab67e3bbf00018eba2b5a09c'] = array(
    'source' => 'Unfollow story',
    'context' => '',
    'location' => '/ar/flag/flag/follow_story/13?destination=story-collaboration/13&token=oLBeN_SG-PkEhp5jsIeZ4spHgNg_cDe-bTzZ685AYow; sites/all/modules/custom/checkdesk_core/js/checkdesk_core.js',
    'translation' => 'إيقاف متابعة الموضوع',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Unfollow story', array(), array('context' => ''));
  $translations['ar:default']['edff786c3f366ccad145d1bad032f55e'] = array(
    'source' => 'Table %name already exists.',
    'context' => '',
    'location' => '',
    'translation' => 'الجدول %name موجود بالفعل.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Table %name already exists.', array(), array('context' => ''));
  $translations['ar:default']['ee13e991d8700e7f18ac59a497a6034a'] = array(
    'source' => 'Date in the form of DD (01 - 31).',
    'context' => '',
    'location' => '',
    'translation' => 'التاريخ بصيغة DD (القيم المسموحة 01 - 31)',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Date in the form of DD (01 - 31).', array(), array('context' => ''));
  $translations['ar:default']['ee1c74ab64e551140e4ad0d60349682b'] = array(
    'source' => 'The following numbers control which properties the content search should favor when ordering the results. Higher numbers mean more influence, zero means the property is ignored. Changing these numbers does not require the search index to be rebuilt. Changes take effect immediately.',
    'context' => '',
    'location' => '',
    'translation' => 'الأرقام التالية تتحكم في الخصائص التي سيفاضل على أساسها البحث في المحتوى عند ترتيب النتائج. الأرقام الأكبر تعني تأثيرا أكبر؛ الصفر يعني أن الخاصية ستهمل؛ لا يتطلب تغيير هذه الأرقام إعادة بناء الفهرس. التغييرات تأخذ أثرها فورا.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The following numbers control which properties the content search should favor when ordering the results. Higher numbers mean more influence, zero means the property is ignored. Changing these numbers does not require the search index to be rebuilt. Changes take effect immediately.', array(), array('context' => ''));
  $translations['ar:default']['ee3542667776dff9b96dce2a73a23646'] = array(
    'source' => 'Promoted to frontpage',
    'context' => '',
    'location' => '',
    'translation' => 'مرقّى إلى الصفحة الرئيسية',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Promoted to frontpage', array(), array('context' => ''));
  $translations['ar:default']['ee4181df7255f98ce59f28ece4dd1f39'] = array(
    'source' => '@count[2] updates',
    'context' => '',
    'location' => '/ar/search?field_tags_tid=1328',
    'translation' => 'تحديثان',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('@count[2] updates', array(), array('context' => ''));
  $translations['ar:default']['ef046ed7ba54bb4a4cb6a461d84fa689'] = array(
    'source' => 'published on ',
    'context' => '',
    'location' => '/ar',
    'translation' => 'نُشر على المدونة المباشرة في ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('published on ', array(), array('context' => ''));
  $translations['ar:default']['ef0f9fda86453946af024f9ceb3f311c'] = array(
    'source' => 'Cannot add unique key %name to table %table: table doesn\'t exist.',
    'context' => '',
    'location' => '',
    'translation' => 'لا يمكن إضافة المفتاح الفريد للجدول %table: هذا المفتاح موجود مسبقاً.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Cannot add unique key %name to table %table: table doesn\'t exist.', array(), array('context' => ''));
  $translations['ar:default']['ef4634ce6c43ef4a80dddba74ed2177e'] = array(
    'source' => 'Taxonomy term ID from URL',
    'context' => '',
    'location' => '',
    'translation' => 'Taxonomy term ID from URL',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Taxonomy term ID from URL', array(), array('context' => ''));
  $translations['ar:default']['f01b872dcf10aaf381792d09a8334a00'] = array(
    'source' => 'The \'Reply-To\' field of the e-mail address.',
    'context' => '',
    'location' => '/ar',
    'translation' => '"الرد إلى" حقل من عنوان البريد الإلكتروني.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The \'Reply-To\' field of the e-mail address.', array(), array('context' => ''));
  $translations['ar:default']['f02171c2ff236c0a120bd171bdf67c31'] = array(
    'source' => 'Use count',
    'context' => '',
    'location' => '',
    'translation' => 'استخدام الاعتماد',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Use count', array(), array('context' => ''));
  $translations['ar:default']['f02b6fafe4d743a9527fc300c28842d6'] = array(
    'source' => 'This report was flagged as containing graphic content.',
    'context' => '',
    'location' => '/ar/node/flag/confirm/flag/graphic/11/ajax',
    'translation' => 'تم تنبيه المشرف على احتواء التقرير على محتوى أو صور صادمة.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('This report was flagged as containing graphic content.', array(), array('context' => ''));
  $translations['ar:default']['f03ab16cd58372c77ba45a3d9a5a1cb9'] = array(
    'source' => 'Draft',
    'context' => '',
    'location' => '/ar/search?field_tags_tid=All',
    'translation' => 'مسودة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Draft', array(), array('context' => ''));
  $translations['ar:default']['f042e6d8f73e050a9e81d0d2843c9a2e'] = array(
    'source' => 'Date Asc',
    'context' => '',
    'location' => '',
    'translation' => 'التاريخ تصاعدي',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Date Asc', array(), array('context' => ''));
  $translations['ar:default']['f0444a6fc8e8a4066a9c2c896322fe3c'] = array(
    'source' => 'On site',
    'context' => '',
    'location' => '/ar/user/1/notifications',
    'translation' => 'على الموقع',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('On site', array(), array('context' => ''));
  $translations['ar:default']['f08166019bdbf3d6c641a4344858c491'] = array(
    'source' => 'Display contents of "No results found"',
    'context' => '',
    'location' => '',
    'translation' => 'إظهار محتوى "لا توجد نتائج"',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Display contents of "No results found"', array(), array('context' => ''));
  $translations['ar:default']['f0cb3ce782fd681f3088eaa14abfc3e3'] = array(
    'source' => 'The number of times the file is used by this entity.',
    'context' => '',
    'location' => '',
    'translation' => 'عدد مرات استخدام الملف عن طريق هذا الكيان.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The number of times the file is used by this entity.', array(), array('context' => ''));
  $translations['ar:default']['f11b368cddfe37c47af9b9d91c6ba4f0'] = array(
    'source' => 'Full name',
    'context' => '',
    'location' => '',
    'translation' => 'الاسم الكامل ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Full name', array(), array('context' => ''));
  $translations['ar:default']['f16497d32010b3ecf480030bf46463dc'] = array(
    'source' => '<a href="[node:url:unaliased]">[node:author]\'s report</a> was unflagged for deletion.',
    'context' => '',
    'location' => '/ar/node/flag/confirm/flag/delete/259/ajax',
    'translation' => 'تم إلغاء تنبيه المشرف لحذف <a href="[node:url:unaliased]"> تقرير [node:author] </a>.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('<a href="[node:url:unaliased]">[node:author]\'s report</a> was unflagged for deletion.', array(), array('context' => ''));
  $translations['ar:default']['f1bc903aa485e451bf7fcc17d44579fc'] = array(
    'source' => 'The user or author name.',
    'context' => '',
    'location' => '',
    'translation' => 'المستخدم أو اسم المؤلف.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The user or author name.', array(), array('context' => ''));
  $translations['ar:default']['f1fe73b00e016482103356b34828e7f7'] = array(
    'source' => 'Displays items in a fluid grid.',
    'context' => '',
    'location' => '',
    'translation' => 'Displays items in a fluid grid.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Displays items in a fluid grid.', array(), array('context' => ''));
  $translations['ar:default']['f210e321d18ec88515188cb044834bc5'] = array(
    'source' => 'Embed',
    'context' => '',
    'location' => '',
    'translation' => 'مضمن',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Embed', array(), array('context' => ''));
  $translations['ar:default']['f27ca2f706d3a14af60118b237958295'] = array(
    'source' => 'Empty display extender',
    'context' => '',
    'location' => '',
    'translation' => 'موسع العرض الفارغ ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Empty display extender', array(), array('context' => ''));
  $translations['ar:default']['f292a1f39ef5f823ff5ac87c5b9fdade'] = array(
    'source' => 'Fact-checking turned on',
    'context' => '',
    'location' => '/ar/user/2/notifications',
    'translation' => 'تم تفعيل التحقق من صحة المعلومات',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Fact-checking turned on', array(), array('context' => ''));
  $translations['ar:default']['f2981d64c74cb84aee181bd09890e818'] = array(
    'source' => 'No role',
    'context' => '',
    'location' => '',
    'translation' => 'لا يوجد دور ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('No role', array(), array('context' => ''));
  $translations['ar:default']['f29af52fb52ff9e4db07e0b79ea3d761'] = array(
    'source' => 'Show "Page not found"',
    'context' => '',
    'location' => '',
    'translation' => 'إظهار محتوى "الصفحة غير موجودة"',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Show "Page not found"', array(), array('context' => ''));
  $translations['ar:default']['f2a04d1deb2414d8bce2527a517546e6'] = array(
    'source' => 'Heartbeat activity attachments',
    'context' => '',
    'location' => '/ar',
    'translation' => 'Heartbeat activity attachments',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Heartbeat activity attachments', array(), array('context' => ''));
  $translations['ar:default']['f2bededa6accdb01b96e27aa17223052'] = array(
    'source' => 'Compose update here...',
    'context' => '',
    'location' => '',
    'translation' => 'اكتب التحديث هنا',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Compose update here...', array(), array('context' => ''));
  $translations['ar:default']['f2fdea440d768b85591e936a803c3631'] = array(
    'source' => 'Sign In',
    'context' => '',
    'location' => '/ar/user/login',
    'translation' => 'تسجيل الدخول',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Sign In', array(), array('context' => ''));
  $translations['ar:default']['f31bbdd1b3e85bccd652680e16935819'] = array(
    'source' => 'Source',
    'context' => '',
    'location' => '/ar',
    'translation' => 'مصدر',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Source', array(), array('context' => ''));
  $translations['ar:default']['f337e0102fb270c38ef94c0180bd546b'] = array(
    'source' => 'The language code of the current content language.',
    'context' => '',
    'location' => '',
    'translation' => 'رمز اللغة من لغة المحتوى الحالي.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The language code of the current content language.', array(), array('context' => ''));
  $translations['ar:default']['f38bebc01f7d6f4c965604a1e6ea1e7d'] = array(
    'source' => 'Provide a simple link to edit the term.',
    'context' => '',
    'location' => '',
    'translation' => 'تقديم وصلة بسيطة لتحرير المصطلح',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Provide a simple link to edit the term.', array(), array('context' => ''));
  $translations['ar:default']['f39a6420e5e5eff9d1d093c5ac93eac2'] = array(
    'source' => 'Comment on report',
    'context' => '',
    'location' => '/ar',
    'translation' => 'تعليق جديد على تقرير',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Comment on report', array(), array('context' => ''));
  $translations['ar:default']['f3f505f5721a6a06394bce974c39e87d'] = array(
    'source' => 'Whether the comment is published or unpublished.',
    'context' => '',
    'location' => '',
    'translation' => 'إذا ما كان التعليق منشوراً أو غير منشور.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Whether the comment is published or unpublished.', array(), array('context' => ''));
  $translations['ar:default']['f4040f71a7d553f2519487070892b115'] = array(
    'source' => 'User roles',
    'context' => '',
    'location' => '',
    'translation' => ' أدوار المستخدم',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('User roles', array(), array('context' => ''));
  $translations['ar:default']['f4dc020f50664a70b23db8dbd5db986c'] = array(
    'source' => 'Display the label of the referenced entities.',
    'context' => '',
    'location' => '',
    'translation' => 'عرض تسمية الكيانات المشار إليه.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Display the label of the referenced entities.', array(), array('context' => ''));
  $translations['ar:default']['f4ec5f57bd4d31b803312d873be40da9'] = array(
    'source' => 'Change',
    'context' => '',
    'location' => '',
    'translation' => 'تغيير',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Change', array(), array('context' => ''));
  $translations['ar:default']['f4ec92e47344650ac562b0710f3c9e80'] = array(
    'source' => 'The ID of the Twitter status message.',
    'context' => '',
    'location' => '',
    'translation' => 'معرف رسالة الحالة تويتر.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The ID of the Twitter status message.', array(), array('context' => ''));
  $translations['ar:default']['f5db16406645e065e8a25fd3ff40e891'] = array(
    'source' => 'Hello !recipient_name,

!actor has changed the fact-checking status for a <a href="!url">report</a> you submitted to !rating.

You can edit your notification settings from your <a href="!recipient_url">profile page</a>.

This was an auto-generated email from !site; please do not respond directly to this email.',
    'context' => '',
    'location' => '/index.php',
    'translation' => 'مرحباً !recipient_name،

قام !actor بتغيير حالة التحقق من صحة المعلومات <a href="!url">للتقرير</a> الذي أضفته إلى !rating.

بإمكانك تعديل إعدادات التنبيهات الخاصة بك من صفحة <a href="!recipient_url">الحساب الشخصي</a> الخاصة بك.

هذه رسالة مولدة بشكل تلقائي من !site، يرجى عدم الرد على هذه الرسالة.
',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Hello !recipient_name,

!actor has changed the fact-checking status for a <a href="!url">report</a> you submitted to !rating.

You can edit your notification settings from your <a href="!recipient_url">profile page</a>.

This was an auto-generated email from !site; please do not respond directly to this email.', array(), array('context' => ''));
  $translations['ar:default']['f6268934c100ffceec0830f5e8eb37dc'] = array(
    'source' => 'Cannot change the definition of field %table.%name: field doesn\'t exist.',
    'context' => '',
    'location' => '',
    'translation' => 'لا يمكن تغيير تعريف الحقل %table.%name : الحقل غير موجود.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Cannot change the definition of field %table.%name: field doesn\'t exist.', array(), array('context' => ''));
  $translations['ar:default']['f6861770bdf2fb702a665f1b34e4f9ed'] = array(
    'source' => 'Tokens',
    'context' => '',
    'location' => '',
    'translation' => 'رموز',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Tokens', array(), array('context' => ''));
  $translations['ar:default']['f6b5f35f6564a567f1810df0b730e3dc'] = array(
    'source' => 'Load more',
    'context' => '',
    'location' => '/ar',
    'translation' => 'تحميل المزيد',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Load more', array(), array('context' => ''));
  $translations['ar:default']['f7070be7ec7d2443714a2e5dc63f4de2'] = array(
    'source' => 'Links to',
    'context' => '',
    'location' => '',
    'translation' => 'وصلات إلى',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Links to', array(), array('context' => ''));
  $translations['ar:default']['f73c3f216744004b851195d71a55a5c3'] = array(
    'source' => 'The number of times a piece of content is flagged by any user.',
    'context' => '',
    'location' => '',
    'translation' => 'عدد مرات تحذير المشرف حول عنصر من المحتوى من قبل أي مستخدم.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The number of times a piece of content is flagged by any user.', array(), array('context' => ''));
  $translations['ar:default']['f741840fb6f8bf6a54efc82d3b68bb5f'] = array(
    'source' => 'View link',
    'context' => '',
    'location' => '',
    'translation' => 'رابط العرض',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('View link', array(), array('context' => ''));
  $translations['ar:default']['f7b9522333ea3fbdb6d3965b40b1f6c8'] = array(
    'source' => 'Media sources',
    'context' => '',
    'location' => '/ar',
    'translation' => 'مصادر إعلامية',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Media sources', array(), array('context' => ''));
  $translations['ar:default']['f7ba58dabcb7d1cad4f236dd25497dbd'] = array(
    'source' => 'Embeds links if possible - otherwise just links them.',
    'context' => '',
    'location' => '/ar',
    'translation' => 'Embeds links if possible - otherwise just links them.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Embeds links if possible - otherwise just links them.', array(), array('context' => ''));
  $translations['ar:default']['f7bd81b028bb8262dd4bfa9de9d09a3c'] = array(
    'source' => 'The \'Header\' field of the e-mail.',
    'context' => '',
    'location' => '/ar',
    'translation' => 'و\'رأس\' مجال البريد الإلكتروني.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The \'Header\' field of the e-mail.', array(), array('context' => ''));
  $translations['ar:default']['f83ffc8e80cd46e7d624c6e6e92e2ec3'] = array(
    'source' => 'The date the user last logged in to the site.',
    'context' => '',
    'location' => '',
    'translation' => 'تاريخ آخر دخول المستخدم إلى الموقع.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The date the user last logged in to the site.', array(), array('context' => ''));
  $translations['ar:default']['f89fbcc552048d8dbbb85545f288c480'] = array(
    'source' => 'Desired block weight exceeds available weight options, please check weights for blocks before saving',
    'context' => '',
    'location' => 'sites/all/modules/contrib/context/plugins/context_reaction_block.js',
    'translation' => 'المطلوب يتجاوز الوزن كتلة خيارات المتاحة الوزن، يرجى مراجعة أوزان للبنات قبل حفظ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Desired block weight exceeds available weight options, please check weights for blocks before saving', array(), array('context' => ''));
  $translations['ar:default']['f8fb29d251b28c12207eb5a92d9a116a'] = array(
    'source' => '1 more update',
    'context' => '',
    'location' => '',
    'translation' => 'تحديث 1 آخر',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('1 more update', array(), array('context' => ''));
  $translations['ar:default']['f9087af03968b9a75a67376447f88bcf'] = array(
    'source' => 'Damascus',
    'context' => '',
    'location' => '/meedan/meedan-checkdesk/drupal/ar/node/15692',
    'translation' => 'دمشق',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Damascus', array(), array('context' => ''));
  $translations['ar:default']['f90d22b9ac85ad72b568d5f9f26d9d63'] = array(
    'source' => 'Whether the node is new and not saved to the database yet.',
    'context' => '',
    'location' => '',
    'translation' => 'ما إذا كانت العقدة هو جديد وغير محفوظه في  قاعدة البيانات',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Whether the node is new and not saved to the database yet.', array(), array('context' => ''));
  $translations['ar:default']['f91aa8ebc714718eba6f8d2aabd042d8'] = array(
    'source' => 'not in',
    'context' => '',
    'location' => '',
    'translation' => 'ليس في',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('not in', array(), array('context' => ''));
  $translations['ar:default']['f94acc13bf0416ce7254be71a36e40aa'] = array(
    'source' => 'User who flagged the content',
    'context' => '',
    'location' => '/ar/i18n_string/save',
    'translation' => 'المستخدمون الذين نبهوا المشرف حول هذا التقرير',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('User who flagged the content', array(), array('context' => ''));
  $translations['ar:default']['f96407a378b4e27cd96cccc4ce82691c'] = array(
    'source' => 'Liveblog',
    'context' => '',
    'location' => '/ar',
    'translation' => 'مدونة مباشرة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Liveblog', array(), array('context' => ''));
  $translations['ar:default']['f9fea3ece53b876b7c5f491e98b30535'] = array(
    'source' => 'Contextual filters',
    'context' => '',
    'location' => '',
    'translation' => 'مرشحات قياسيه ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Contextual filters', array(), array('context' => ''));
  $translations['ar:default']['fa01f2b94ae043cf471496e27241f920'] = array(
    'source' => 'The location of the Twitter account.',
    'context' => '',
    'location' => '',
    'translation' => 'موقع حساب تويتر.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The location of the Twitter account.', array(), array('context' => ''));
  $translations['ar:default']['fa2211483f76f6df081e4d34ecbd3bfa'] = array(
    'source' => 'Whether or not the translation is plural.',
    'context' => '',
    'location' => '',
    'translation' => 'ما إذا كانت الترجمة بصيغة الجمع.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Whether or not the translation is plural.', array(), array('context' => ''));
  $translations['ar:default']['fb65cf2afb08915737b223b747c872b3'] = array(
    'source' => 'This table contains the logged e-mails.',
    'context' => '',
    'location' => '/ar',
    'translation' => 'هذا الجدول يحتوي على تسجيل رسائل البريد الإلكتروني.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('This table contains the logged e-mails.', array(), array('context' => ''));
  $translations['ar:default']['fb66db3b60429cd6c40dbd1a9183f05b'] = array(
    'source' => 'Needing fact-checking',
    'context' => '',
    'location' => '/ar/user/577/notifications',
    'translation' => 'يحتاج التقصي',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Needing fact-checking', array(), array('context' => ''));
  $translations['ar:default']['fb79134be1172c1a5814eddc5c44993b'] = array(
    'source' => 'Whether the comment is approved (or still in the moderation queue).',
    'context' => '',
    'location' => '',
    'translation' => 'ما إذا تمت الموافقة على التعليق (أو لا يزال في قائمة الإشراف على التعليقات).',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Whether the comment is approved (or still in the moderation queue).', array(), array('context' => ''));
  $translations['ar:default']['fb7a87ba1c0886827ea2791ccad8ef9d'] = array(
    'source' => 'Information related to the current page request.',
    'context' => '',
    'location' => '',
    'translation' => 'المعلومات المتعلقة بالطلب للصفحة الحالية.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Information related to the current page request.', array(), array('context' => ''));
  $translations['ar:default']['fba3b32bfd7d1ba0db045c369f457567'] = array(
    'source' => 'Update by <a href="@user">!user</a> <time datetime="!date">!datetime</time>',
    'context' => '',
    'location' => '',
    'translation' => 'نشره <a href="@user">!user</a> <time datetime="!date">!datetime</time>',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Update by <a href="@user">!user</a> <time datetime="!date">!datetime</time>', array(), array('context' => ''));
  $translations['ar:default']['fbc97786af4bf30dc5b07809a950792c'] = array(
    'source' => 'Relationship',
    'context' => '',
    'location' => '',
    'translation' => 'علاقة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Relationship', array(), array('context' => ''));
  $translations['ar:default']['fbed6b28a604dc0b0b7adca4f635133f'] = array(
    'source' => 'Authentication module',
    'context' => '',
    'location' => '',
    'translation' => 'وحدة المصادقه ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Authentication module', array(), array('context' => ''));
  $translations['ar:default']['fc19eb1709ba222b11d449b5036a2796'] = array(
    'source' => 'sort criteria',
    'context' => '',
    'location' => '',
    'translation' => 'sort criteria',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('sort criteria', array(), array('context' => ''));
  $translations['ar:default']['fc1a3b277535ec0b318dd5d97bddd775'] = array(
    'source' => 'The user permissions.',
    'context' => '',
    'location' => '',
    'translation' => 'أذونات المستخدم',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The user permissions.', array(), array('context' => ''));
  $translations['ar:default']['fcd1ba561bcd5b3c9a715c2763092d30'] = array(
    'source' => 'The path of the primary file for this item, relative to the Drupal root; e.g. modules/node/node.module.',
    'context' => '',
    'location' => '',
    'translation' => 'The path of the primary file for this item, relative to the Drupal root; e.g. modules/node/node.module.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The path of the primary file for this item, relative to the Drupal root; e.g. modules/node/node.module.', array(), array('context' => ''));
  $translations['ar:default']['fcde5191dc6f00c373997498f60d3204'] = array(
    'source' => 'Cannot rename %table to %table_new: table %table doesn\'t exist.',
    'context' => '',
    'location' => '',
    'translation' => 'لا يمكن إعادة تسمية الجدول %table إلى %table_new : الجدول %table غير موجود.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Cannot rename %table to %table_new: table %table doesn\'t exist.', array(), array('context' => ''));
  $translations['ar:default']['fdffbb203193714a9e8a3db8d2f49825'] = array(
    'source' => 'Machine-Name of the vocabulary a term is a member of. This will be the vocabulary that whichever term the "Taxonomy: Term" field is; and can similarly cause duplicates.',
    'context' => '',
    'location' => '',
    'translation' => 'Machine-Name of the vocabulary a term is a member of. This will be the vocabulary that whichever term the "Taxonomy: Term" field is; and can similarly cause duplicates.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Machine-Name of the vocabulary a term is a member of. This will be the vocabulary that whichever term the "Taxonomy: Term" field is; and can similarly cause duplicates.', array(), array('context' => ''));
  $translations['ar:default']['fe11cbd83f7d98326b0bbd78f8ebdf7c'] = array(
    'source' => 'Edit this view to add a display.',
    'context' => '',
    'location' => '',
    'translation' => 'تحرير هذه الرؤية لإضافة عرض.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Edit this view to add a display.', array(), array('context' => ''));
  $translations['ar:default']['fe24939470ca06681c136494a5b37813'] = array(
    'source' => 'Count DISTINCT',
    'context' => '',
    'location' => '',
    'translation' => 'Count DISTINCT',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Count DISTINCT', array(), array('context' => ''));
  $translations['ar:default']['fea087517c26fadd409bd4b9dc642555'] = array(
    'source' => 'normal',
    'context' => '',
    'location' => '',
    'translation' => 'عادية',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('normal', array(), array('context' => ''));
  $translations['ar:default']['fedb2d84cafe20862cb4399751a8a7e3'] = array(
    'source' => 'invalid',
    'context' => '',
    'location' => '/ar/user/register',
    'translation' => 'غير صالح',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('invalid', array(), array('context' => ''));
  $translations['ar:default']['feee3e5c6d02d73f8506d88a11f8851d'] = array(
    'source' => 'Taxonomy terms are attached to nodes.',
    'context' => '',
    'location' => '',
    'translation' => ' شروط التصنيف للعقد.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Taxonomy terms are attached to nodes.', array(), array('context' => ''));
  $translations['ar:default']['feefc8d71a7bb64b3c3537aa5d62fb70'] = array(
    'source' => 'Queue \'@queue\'',
    'context' => '',
    'location' => '',
    'translation' => 'قائمة \'@queue\'',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Queue \'@queue\'', array(), array('context' => ''));
  $translations['ar:default']['ff1c5438feed00f19d54c7c95503e0cb'] = array(
    'source' => 'Number of records',
    'context' => '',
    'location' => '',
    'translation' => 'عدد التسجيلات',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Number of records', array(), array('context' => ''));
  $translations['ar:default']['ff8e2305d2b56a0069c1e572ee7bc739'] = array(
    'source' => 'Add to queue',
    'context' => '',
    'location' => '',
    'translation' => 'إضافة إلى القائمة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Add to queue', array(), array('context' => ''));
  $translations['ar:default']['ffbd5c618fda7a18463f225c3b7a1d22'] = array(
    'source' => 'The log message entered when the revision was created.',
    'context' => '',
    'location' => '',
    'translation' => 'دخلت رسالة سجل عندما تم إنشاء مراجعة.',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('The log message entered when the revision was created.', array(), array('context' => ''));
  $translations['ar:default']['ffdf628e5d8c2722f8386823eb7c7c48'] = array(
    'source' => 'A new user <a href="!url">!name</a> has registered. Please mark him as <em>active</em>, if you want to accept this registration.',
    'context' => '',
    'location' => '/ar/views/ajax',
    'translation' => 'لقد سجل مستخدم جديد باسم "<a href="!url">!name</a>". إذا كت تريد قبول تسجيله يرجى تغيير حالة حسابه إلى  "نشط".',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('A new user <a href="!url">!name</a> has registered. Please mark him as <em>active</em>, if you want to accept this registration.', array(), array('context' => ''));
  $translations['ar:default']['ffe61bebc32cf64ade7789514bd34f88'] = array(
    'source' => 'All pages',
    'context' => '',
    'location' => '',
    'translation' => 'جميع الصفحات',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('All pages', array(), array('context' => ''));
  $translations['ar:default']['fffcb4d1e12c96b2f571f77ad25878b8'] = array(
    'source' => 'Reason',
    'context' => '',
    'location' => '/ar/modal/ajax/content/%D8%AA%D9%86%D8%B5%D9%8A%D8%A8-%D8%A5%D8%B6%D8%A7%D9%81%D8%A9-%D8%A7%D9%84%D9%85%D8%AA%D8%B5%D9%81%D8%AD',
    'translation' => 'السبب',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Reason', array(), array('context' => ''));
  $translations['ar:field']['0367519a2eeb0f7c3317ae7732f8e523'] = array(
    'source' => 'Body',
    'context' => 'body:page:label',
    'location' => 'field:body:page:label',
    'translation' => 'المحتوى',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Body', array(), array('context' => 'body:page:label'));
  $translations['ar:field']['0858ab2077ed271bb86d469d83bc6499'] = array(
    'source' => 'Comment',
    'context' => 'comment_body:comment_node_article:label',
    'location' => 'field:comment_body:comment_node_article:label',
    'translation' => 'التعليق',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Comment', array(), array('context' => 'comment_body:comment_node_article:label'));
  $translations['ar:field']['10f0a1d9e764e142178fcc7b87447fdd'] = array(
    'source' => 'Comment',
    'context' => 'comment_body:comment_node_media:label',
    'location' => 'field:comment_body:comment_node_media:label',
    'translation' => 'التعليق',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Comment', array(), array('context' => 'comment_body:comment_node_media:label'));
  $translations['ar:field']['125f56179b693b24fdde52339970b200'] = array(
    'source' => 'Comment',
    'context' => 'comment_body:comment_node_post:label',
    'location' => 'field:comment_body:comment_node_post:label',
    'translation' => 'التعليق',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Comment', array(), array('context' => 'comment_body:comment_node_post:label'));
  $translations['ar:field']['199b1a676eb1d459b958f4d3353ceb98'] = array(
    'source' => 'Comment',
    'context' => 'comment_body:comment_node_discussion:label',
    'location' => 'field:comment_body:comment_node_discussion:label',
    'translation' => 'التعليق',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Comment', array(), array('context' => 'comment_body:comment_node_discussion:label'));
  $translations['ar:field']['1a206884c12fc2eb51849b188507640f'] = array(
    'source' => 'Comment',
    'context' => 'comment_body:comment_node_page:label',
    'location' => 'field:comment_body:comment_node_page:label',
    'translation' => 'التعليق',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Comment', array(), array('context' => 'comment_body:comment_node_page:label'));
  $translations['ar:field']['1b0ff4dd282a9f2e6ebbc631b8cc581a'] = array(
    'source' => 'Attachment',
    'context' => 'field_attachment:comment_node_discussion:label',
    'location' => 'field:field_attachment:comment_node_discussion:label',
    'translation' => 'مرفقات',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Attachment', array(), array('context' => 'field_attachment:comment_node_discussion:label'));
  $translations['ar:field']['2d291378a8a29af401a45aec8688733a'] = array(
    'source' => 'Tags',
    'context' => 'field_tags:media:label',
    'location' => 'field:field_tags:media:label',
    'translation' => 'وسومات',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Tags', array(), array('context' => 'field_tags:media:label'));
  $translations['ar:field']['33895ff9c24f27f9070d8a905e6b1e08'] = array(
    'source' => 'Body',
    'context' => 'body:article:label',
    'location' => 'field:body:article:label',
    'translation' => 'المحتوى',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Body', array(), array('context' => 'body:article:label'));
  $translations['ar:field']['506d65ddd7b5fbd4b76b1ae0b9461216'] = array(
    'source' => 'Description',
    'context' => 'body:media:label',
    'location' => 'field:body:media:label',
    'translation' => 'الوصف',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Description', array(), array('context' => 'body:media:label'));
  $translations['ar:field']['56d713560c0681c819be51b9f6caf91f'] = array(
    'source' => 'Tags',
    'context' => 'field_tags:discussion:label',
    'location' => 'field:field_tags:discussion:label',
    'translation' => 'وسومات',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Tags', array(), array('context' => 'field_tags:discussion:label'));
  $translations['ar:field']['5af8ee85abe76eb31c17c7dd48fee8f3'] = array(
    'source' => 'Reason',
    'context' => 'field_reason:spam:label',
    'location' => 'field:field_reason:spam:label',
    'translation' => 'السبب',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Reason', array(), array('context' => 'field_reason:spam:label'));
  $translations['ar:field']['66b873725237788cb3f1ed4a89a95988'] = array(
    'source' => 'Fact-checking status',
    'context' => 'field_rating:media:label',
    'location' => 'field:field_rating:media:label',
    'translation' => 'حالة التحقق من صحة المعلومات',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Fact-checking status', array(), array('context' => 'field_rating:media:label'));
  $translations['ar:field']['6caecad86e78083b9cf8525bc53ca181'] = array(
    'source' => 'Body',
    'context' => 'body:post:label',
    'location' => 'field:body:post:label',
    'translation' => 'المحتوى',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Body', array(), array('context' => 'body:post:label'));
  $translations['ar:field']['7684a7df2325f2729e7de796f3ca1899'] = array(
    'source' => 'Story',
    'context' => 'field_desk:post:label',
    'location' => 'field:field_desk:post:label',
    'translation' => 'الموضوع',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Story', array(), array('context' => 'field_desk:post:label'));
  $translations['ar:field']['9810583d5816898e30b4c16172caf32a'] = array(
    'source' => 'Media',
    'context' => 'field_link:media:label',
    'location' => 'field:field_link:media:label',
    'translation' => 'رابط الميديا',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Media', array(), array('context' => 'field_link:media:label'));
  $translations['ar:field']['ae3d8c1a1b2798487836735a185857b3'] = array(
    'source' => 'Reason',
    'context' => 'field_reason:factcheck:label',
    'location' => 'field:field_reason:factcheck:label',
    'translation' => 'السبب',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Reason', array(), array('context' => 'field_reason:factcheck:label'));
  $translations['ar:field']['ae936378eee55faa55542ca5161f26fd'] = array(
    'source' => 'Story',
    'context' => 'field_stories:media:label',
    'location' => 'field:field_stories:media:label',
    'translation' => 'الخبر',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Story', array(), array('context' => 'field_stories:media:label'));
  $translations['ar:field']['c6dca5331105c2ae1c8e54c19f424767'] = array(
    'source' => 'Story',
    'context' => 'body:discussion:label',
    'location' => 'field:body:discussion:label',
    'translation' => 'الموضوع',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Story', array(), array('context' => 'body:discussion:label'));
  $translations['ar:field']['ce712a6b64fc4b03e3e3bb31c91590db'] = array(
    'source' => 'Reason',
    'context' => 'field_reason:graphic:label',
    'location' => 'field:field_reason:graphic:label',
    'translation' => 'السبب',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Reason', array(), array('context' => 'field_reason:graphic:label'));
  $translations['ar:menu']['088c54353062fa1753915940e4554a57'] = array(
    'source' => 'Supported by Meedan',
    'context' => 'item:93091458-8370-4ca5-9fae-2ac710021e68:title',
    'location' => 'menu:item:93091458-8370-4ca5-9fae-2ac710021e68:title',
    'translation' => 'بدعم من ميدان',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Supported by Meedan', array(), array('context' => 'item:93091458-8370-4ca5-9fae-2ac710021e68:title'));
  $translations['ar:menu']['17e27e281a78c343adb7d06e100ebe3f'] = array(
    'source' => 'Notifications',
    'context' => 'item:5626ddfd-e3f6-7ba4-f9ff-f8c36ff9d636:title',
    'location' => 'menu:item:5626ddfd-e3f6-7ba4-f9ff-f8c36ff9d636:title',
    'translation' => 'تنبيهات',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Notifications', array(), array('context' => 'item:5626ddfd-e3f6-7ba4-f9ff-f8c36ff9d636:title'));
  $translations['ar:menu']['45faaba81f618ac1d4e843e6cdc83305'] = array(
    'source' => 'Powered by',
    'context' => 'item:46a9effa-0a43-41c2-a150-dee7ed74c01f:title',
    'location' => 'menu:item:46a9effa-0a43-41c2-a150-dee7ed74c01f:title',
    'translation' => 'تطوير',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Powered by', array(), array('context' => 'item:46a9effa-0a43-41c2-a150-dee7ed74c01f:title'));
  $translations['ar:menu']['52ba2c9f975966a942f5583ae8fd5453'] = array(
    'source' => 'Logout',
    'context' => 'item:391be377-17db-a134-4d21-c6742d07ca4e:title',
    'location' => 'menu:item:391be377-17db-a134-4d21-c6742d07ca4e:title',
    'translation' => 'تسجيل خروج',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Logout', array(), array('context' => 'item:391be377-17db-a134-4d21-c6742d07ca4e:title'));
  $translations['ar:menu']['5cf36afb9ce6ecdf2895b7b364262da2'] = array(
    'source' => 'Main menu',
    'context' => 'menu:main-menu:title',
    'location' => 'menu:menu:main-menu:title',
    'translation' => 'القائمة الرئيسية',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Main menu', array(), array('context' => 'menu:main-menu:title'));
  $translations['ar:menu']['5d1ed88d7b62faf70088c982fa425477'] = array(
    'source' => 'My account',
    'context' => 'item:42e9e86e-42ae-8d04-0d50-e42bde8cbbda:title',
    'location' => 'menu:item:42e9e86e-42ae-8d04-0d50-e42bde8cbbda:title',
    'translation' => 'حسابي',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('My account', array(), array('context' => 'item:42e9e86e-42ae-8d04-0d50-e42bde8cbbda:title'));
  $translations['ar:menu']['66124c1bf88fc3c69212b7baa7ec4020'] = array(
    'source' => 'Create story',
    'context' => 'item:c4c92459-99c2-52b4-958e-8c889d557fed:title',
    'location' => 'checkdesk_core_feature.features.translations.inc:12120',
    'translation' => 'أنشئ خبر',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Create story', array(), array('context' => 'item:c4c92459-99c2-52b4-958e-8c889d557fed:title'));
  $translations['ar:menu']['6af2b2a74a46e161bf78b738d6778c87'] = array(
    'source' => 'Update story',
    'context' => 'item:d1a4a4e9-b0c3-8d94-11a4-34f35bda25c1:title',
    'location' => 'menu:item:d1a4a4e9-b0c3-8d94-11a4-34f35bda25c1:title',
    'translation' => 'تحديث موضوع',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Update story', array(), array('context' => 'item:d1a4a4e9-b0c3-8d94-11a4-34f35bda25c1:title'));
  $translations['ar:menu']['7190454c99aee4c465d058e2ead671b5'] = array(
    'source' => 'Edit fact-checking statement',
    'context' => 'item:2643d8bd-eb4d-16f4-1928-3013705c11af:title',
    'location' => 'menu:item:2643d8bd-eb4d-16f4-1928-3013705c11af:title',
    'translation' => 'حرر بيان التحقق من صحة المعلومات',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Edit fact-checking statement', array(), array('context' => 'item:2643d8bd-eb4d-16f4-1928-3013705c11af:title'));
  $translations['ar:menu']['7d2e19a2830737e72b8ccbb648fca6fc'] = array(
    'source' => 'Draft  updates',
    'context' => 'item:5452488b-84b8-4398-9078-9814050cc153:title',
    'location' => 'menu:item:5452488b-84b8-4398-9078-9814050cc153:title',
    'translation' => 'تحديثات غير منشورة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Draft  updates', array(), array('context' => 'item:5452488b-84b8-4398-9078-9814050cc153:title'));
  $translations['ar:menu']['844ea0efec81ac18372868128eab065f'] = array(
    'source' => 'Compose update',
    'context' => 'item:bd1dbda7-948e-7ab4-2541-f97399a649fd:title',
    'location' => 'menu:item:bd1dbda7-948e-7ab4-2541-f97399a649fd:title',
    'translation' => 'اكتب تحديث',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Compose update', array(), array('context' => 'item:bd1dbda7-948e-7ab4-2541-f97399a649fd:title'));
  $translations['ar:menu']['84b3c2c103f5c88ee8936d99839a16f2'] = array(
    'source' => 'Create story',
    'context' => 'item:edc54df9-4aa8-bf84-dd89-ca0a351af23b:title',
    'location' => 'checkdesk_core_feature.features.translations.inc:12165',
    'translation' => 'أنشئ موضوع',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Create story', array(), array('context' => 'item:edc54df9-4aa8-bf84-dd89-ca0a351af23b:title'));
  $translations['ar:menu']['875392f6b441fe4092a9a4c9225be661'] = array(
    'source' => 'Administer users',
    'context' => 'item:485c5e2e-cc65-4904-91e1-1ec580b522d5:title',
    'location' => 'menu:item:485c5e2e-cc65-4904-91e1-1ec580b522d5:title',
    'translation' => 'إدارة المستخدمين',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Administer users', array(), array('context' => 'item:485c5e2e-cc65-4904-91e1-1ec580b522d5:title'));
  $translations['ar:menu']['99587ebeab067902fc9abbe600007820'] = array(
    'source' => 'Submit report',
    'context' => 'item:0bc3af5d-28a8-c864-bd93-f17d8bea2366:title',
    'location' => 'menu:item:0bc3af5d-28a8-c864-bd93-f17d8bea2366:title',
    'translation' => 'أضف تقرير',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Submit report', array(), array('context' => 'item:0bc3af5d-28a8-c864-bd93-f17d8bea2366:title'));
  $translations['ar:menu']['a219f581ced256135e3d808db622e0d9'] = array(
    'source' => 'View incoming citizen reports',
    'context' => 'item:e48d5c0f-0c1a-49ca-8a8d-b785b7bc8514:title',
    'location' => 'menu:item:e48d5c0f-0c1a-49ca-8a8d-b785b7bc8514:title',
    'translation' => 'عرض التقارير الواردة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('View incoming citizen reports', array(), array('context' => 'item:e48d5c0f-0c1a-49ca-8a8d-b785b7bc8514:title'));
  $translations['ar:menu']['b2d30a94203b8b6f25b7e1c4d6f4dd6a'] = array(
    'source' => 'Draft  stories',
    'context' => 'item:2821e682-4a21-4a62-87b5-9c98675c7813:title',
    'location' => 'menu:item:2821e682-4a21-4a62-87b5-9c98675c7813:title',
    'translation' => 'موضوعات غير منشورة',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Draft  stories', array(), array('context' => 'item:2821e682-4a21-4a62-87b5-9c98675c7813:title'));
  $translations['ar:menu']['b48b9a053ce15999a9da52bbe0a59d88'] = array(
    'source' => 'Sign in',
    'context' => 'item:9a684326-a352-d454-517b-878bb9468e91:title',
    'location' => 'menu:item:9a684326-a352-d454-517b-878bb9468e91:title',
    'translation' => 'تسجيل دخول',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Sign in', array(), array('context' => 'item:9a684326-a352-d454-517b-878bb9468e91:title'));
  $translations['ar:menu']['ccad5ea8329325c1f37b39e288708bcc'] = array(
    'source' => 'Update story',
    'context' => 'item::title',
    'location' => 'menu:item::title',
    'translation' => 'تحديث موضوع',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Update story', array(), array('context' => 'item::title'));
  $translations['ar:menu']['d018096dec8b344b7ebb52b9633093e4'] = array(
    'source' => 'Take tour',
    'context' => 'item::title',
    'location' => 'menu:item::title',
    'translation' => 'تحديث موضوع',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Take tour', array(), array('context' => 'item::title'));
  $translations['ar:menu']['d992247deb6fe04e5f08c9bf081af1f4'] = array(
    'source' => 'Submit report',
    'context' => 'item:6c3c1244-f5c9-64f4-4575-27d76fef7679:title',
    'location' => 'menu:item:6c3c1244-f5c9-64f4-4575-27d76fef7679:title',
    'translation' => 'أضف تقرير',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Submit report', array(), array('context' => 'item:6c3c1244-f5c9-64f4-4575-27d76fef7679:title'));
  $translations['ar:menu']['f474d46deac46f4afa0574c64664d368'] = array(
    'source' => 'Information',
    'context' => 'item:02e041f6-6c32-c594-8d35-79cb52a371d8:title',
    'location' => 'menu:item:02e041f6-6c32-c594-8d35-79cb52a371d8:title',
    'translation' => 'معلومات',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Information', array(), array('context' => 'item:02e041f6-6c32-c594-8d35-79cb52a371d8:title'));
  $translations['ar:menu']['f62799e0b42171ab73ee0e833dabe923'] = array(
    'source' => 'Edit fact-checking statement',
    'context' => 'item:4099b12c-67ba-76a4-95fc-7aedf02ef067:title',
    'location' => 'menu:item:4099b12c-67ba-76a4-95fc-7aedf02ef067:title',
    'translation' => 'حرر بيان التحقق من صحة المعلومات',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Edit fact-checking statement', array(), array('context' => 'item:4099b12c-67ba-76a4-95fc-7aedf02ef067:title'));
  $translations['ar:taxonomy']['12813189e549be09a79e6442d4671fac'] = array(
    'source' => 'Undetermined',
    'context' => 'term:ba27bacf-4d99-4c1d-bdce-a7fb35fafd43:name',
    'location' => 'taxonomy:term:ba27bacf-4d99-4c1d-bdce-a7fb35fafd43:name',
    'translation' => 'غير معروف',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Undetermined', array(), array('context' => 'term:ba27bacf-4d99-4c1d-bdce-a7fb35fafd43:name'));
  $translations['ar:taxonomy']['1a58c846423a41abf4262dc9e2c4b61f'] = array(
    'source' => 'In Progress',
    'context' => 'term:502ab059-26b9-4947-92e5-3e1a6de4d91e:name',
    'location' => 'taxonomy:term:502ab059-26b9-4947-92e5-3e1a6de4d91e:name',
    'translation' => 'جارٍ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('In Progress', array(), array('context' => 'term:502ab059-26b9-4947-92e5-3e1a6de4d91e:name'));
  $translations['ar:taxonomy']['1c2b3ccbfcd5f6eee5394ab2a9f89e5f'] = array(
    'source' => 'False',
    'context' => 'term:3:name',
    'location' => 'taxonomy:term:3:name',
    'translation' => 'خطأ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('False', array(), array('context' => 'term:3:name'));
  $translations['ar:taxonomy']['1ce09cf2f73f699d9eeda14385be399c'] = array(
    'source' => 'Verified',
    'context' => 'term:3c7ab283-8d43-4913-a293-0db16f025fb1:name',
    'location' => 'taxonomy:term:3c7ab283-8d43-4913-a293-0db16f025fb1:name',
    'translation' => 'صحيح',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Verified', array(), array('context' => 'term:3c7ab283-8d43-4913-a293-0db16f025fb1:name'));
  $translations['ar:taxonomy']['2498d77005c1421b9b649187d404882f'] = array(
    'source' => 'False',
    'context' => 'term:547bb9d2-1dd3-4116-9001-61dfdf877a78:name',
    'location' => 'taxonomy:term:547bb9d2-1dd3-4116-9001-61dfdf877a78:name',
    'translation' => 'خطأ',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('False', array(), array('context' => 'term:547bb9d2-1dd3-4116-9001-61dfdf877a78:name'));
  $translations['ar:taxonomy']['35af701ac47f0324dd10422ce1bfcdb4'] = array(
    'source' => 'Homs',
    'context' => 'term:4f914782-a8c4-4979-b93b-a5a1ebf12998:name',
    'location' => 'taxonomy:term:4f914782-a8c4-4979-b93b-a5a1ebf12998:name',
    'translation' => 'حمص',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Homs', array(), array('context' => 'term:4f914782-a8c4-4979-b93b-a5a1ebf12998:name'));
  $translations['ar:taxonomy']['5d80392aa8a464926f90ec69314df555'] = array(
    'source' => 'Undetermined',
    'context' => 'term:5:name',
    'location' => 'taxonomy:term:5:name',
    'translation' => 'لا يمكن التأكد من صحة المعلومات',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Undetermined', array(), array('context' => 'term:5:name'));
  $translations['ar:taxonomy']['6a9bd15a2dbd2b910f9533044fa3e01b'] = array(
    'source' => 'Tags',
    'context' => 'vocabulary:1:name',
    'location' => 'taxonomy:vocabulary:1:name',
    'translation' => 'وسومات',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Tags', array(), array('context' => 'vocabulary:1:name'));
  $translations['ar:taxonomy']['e0614833806d7345c3147ae56df31c6a'] = array(
    'source' => 'Not Applicable',
    'context' => 'term:4:name',
    'location' => 'taxonomy:term:4:name',
    'translation' => 'لا ينطبق',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Not Applicable', array(), array('context' => 'term:4:name'));
  $translations['ar:taxonomy']['e183e793254d72dba9d591f1c500f24e'] = array(
    'source' => 'In Progress',
    'context' => 'term:2:name',
    'location' => 'taxonomy:term:2:name',
    'translation' => 'جار',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('In Progress', array(), array('context' => 'term:2:name'));
  $translations['ar:taxonomy']['f5573f68669e8dadaa039f1125401556'] = array(
    'source' => 'Verified',
    'context' => 'term:1:name',
    'location' => 'taxonomy:term:1:name',
    'translation' => 'صحيح',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Verified', array(), array('context' => 'term:1:name'));
  $translations['ar:taxonomy']['ff776b8cf6a645e574b270dff9ad105e'] = array(
    'source' => 'Not Applicable',
    'context' => 'term:a312dcad-5904-423c-9be9-d8537a2e72cb:name',
    'location' => 'taxonomy:term:a312dcad-5904-423c-9be9-d8537a2e72cb:name',
    'translation' => 'لا ينطبق',
    'plid' => 0,
    'plural' => 0,
  );
  $translatables[] = t('Not Applicable', array(), array('context' => 'term:a312dcad-5904-423c-9be9-d8537a2e72cb:name'));
  return $translations;
}
