<?php
/**
 * @file
 * checkdesk_core_feature.variable.inc
 */

/**
 * Implements hook_variable_realm_default_variables().
 */
function checkdesk_core_feature_variable_realm_default_variables() {
$realm_variables = array();
  $realm_variables['language']['ar'] = array(
  'checkdesk_site_owner' => 'ميدان',
  'r4032login_access_denied_message' => 'الوصول ممنوع. سجل دخولك لتصل للصفحة.',
  'site_name' => 'شيخ دسك',
  'site_slogan' => 'افلاج يب شبايس',
  'theme_checkdesk_settings' => array(
    'toggle_favicon' => 1,
    'toggle_main_menu' => 1,
    'default_favicon' => 1,
    'favicon_path' => '',
    'favicon_upload' => '',
    'frontpage_logo_path' => 'public://checkdesk_theme/infinity-curve.png',
    'frontpage_logo_upload' => '',
    'header_logo_path' => 'public://checkdesk_theme/agile-dilbert.gif',
    'header_logo_upload' => '',
    'footer_image_path' => NULL,
    'footer_image_upload' => '',
    'custom_css' => '#partner-header-inner {
  background-position: -100px bottom;
  background-repeat: no-repeat;
  padding: 0;
}

.update-actions {
  display: none;
}

html body div.livefyre-header,
html body div.fb-comments-header {
  padding-left: 0;
}

#partner-header-inner #partner-header-slogan {
  padding-top: 25px;
}

.menu-627 {
  display: none !important;
}',
  ),
  'user_mail_cancel_confirm_body' => '[user:name],

A request to cancel your account has been made at [site:name].

You may now cancel your account on [site:url-brief] by clicking this link or copying and pasting it into your browser:

[user:cancel-url]

NOTE: The cancellation of your account is not reversible.

This link expires in one day and nothing will happen if it is not used.

--  [site:name] team',
  'user_mail_cancel_confirm_subject' => 'طلب إلغاء حساب [user:name] على [site:name]',
  'user_mail_password_reset_body' => '[user:name]، 

لقد تم طلب إعادة ضبط كلمة السر لحسابك على [site:name].

 يمكنك الآن تسجيل الدخول بالضغط على الرابط التالي أو نسخه ولصقه في شريط العنوان في المتصفح:

 [user:one-time-login-url]

يمكن استخدام هذا الرابط لتسجيل الدخول مرة واحد فقط وسيقودك إلى صفحة لتغيير كلمة السر. تنتهي صلاحية الرابط بعد يوم واحد ولن يحصل شيء إذا لم يتم استخدامه.

-- فريق [site:name]',
  'user_mail_password_reset_subject' => 'استبدال معلومات تسجيل دخول [user:name] على موقع [site:name]',
  'user_mail_register_admin_created_body' => '[user:name],

قام إداري بإنشاء حساب لك على [site:name]. يمكنك الآن تسجيل الدخول بالضغط على الرابط التالي أو نسخه ولصقه في شريط العنوان في المتصفح:

 [user:one-time-login-url]

يمكن استخدام هذا الرابط لتسجيل الدخول مرة واحد فقط وسيقودك إلى صفحة لضبط كلمة السر. 

بعد اختيار كلمة السر سيمكنك تسجيل الدخول على هذا الرابط: [site:login-url] بواسطة :

 اسم المستخدم : [user:name] 
وكلمة السر التي اخترتها.

-- فريق [site:name] 
',
  'user_mail_register_admin_created_subject' => 'قام إداري بإنشاء حساب لك على [site:name]',
  'user_mail_register_no_approval_required_body' => '[user:name]، 

شكراً لتسجيلك على [site:name]. يمكنك الآن تسجيل الدخول بالضغط على الرابط التالي أو نسخه ولصقه في شريط العنوان في المتصفح:

 [user:one-time-login-url]

يمكن استخدام هذا الرابط لتسجيل الدخول مرة واحد فقط وسيقودك إلى صفحة لضبط كلمة السر. 

بعد اختيار كلمة السر سيمكنك تسجيل الدخول على هذا الرابط: [site:login-url] بواسطة :

 اسم المستخدم : [user:name] 
وكلمة السر التي اخترتها.

-- فريق [site:name] ',
  'user_mail_register_no_approval_required_subject' => 'تفاصيل حساب [user:name] على [site:name]',
  'user_mail_register_pending_approval_body' => '[user:name]،

شكرا لتسجيلك في موقع [site:name]. طلب تسجيلك حالياً في انتظار الموافقة عليه. بمجرد القبول، ستتلقى رسالة أخرى تحتوي على معلومات الدخول، تعيين كلمة المرور، وتفاصيل أخرى.


-- إدارة موقع [site:name]',
  'user_mail_register_pending_approval_subject' => 'تفاصيل حساب [user:name] على [site:name] (في انتظار الموافقة)',
  'user_mail_status_activated_body' => '[user:name],

تم تفعيل حسابك على [site:name].

 سيمكنك تسجيل الدخول على هذا الرابط: [site:login-url] بواسطة :

اسم المستخدم : [user:name] 
وكلمة السر التي اخترتها.

-- فريق [site:name] ',
  'user_mail_status_activated_subject' => 'تفاصيل حساب [user:name] على [site:name]',
  'user_mail_status_blocked_body' => '[user:name],

Your account on [site:name] has been blocked.

--  [site:name] team',
  'user_mail_status_blocked_subject' => 'Account details for [user:name] at [site:name] (blocked)',
  'user_mail_status_canceled_body' => '[user:name],

Your account on [site:name] has been canceled.

--  [site:name] team',
  'user_mail_status_canceled_subject' => 'Account details for [user:name] at [site:name] (canceled)',
  'user_registrationpassword_register_body' => '[user:name]، 

شكراً لتسجيلك على [site:name]. يمكنك الآن تسجيل الدخول بالضغط على الرابط التالي أو نسخه ولصقه في شريط العنوان في المتصفح: 

[user:registrationpassword-url]

يمكن استخدام هذا الرابط لتسجيل الدخول مرة واحد فقط وسيقودك إلى صفحة لضبط كلمة السر. 

بعد اختيار كلمة السر سيمكنك تسجيل الدخول على هذا الرابط: [site:login-url] بواسطة :

 اسم المستخدم : [user:name] 
وكلمة السر التي اخترتها.

-- فريق [site:name] 
',
  'user_registrationpassword_register_subject' => 'تفاصيل حساب [user:name] على [site:name]',
);

return $realm_variables;
}
