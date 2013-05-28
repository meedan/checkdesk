app.config(['$translateProvider', function ($translateProvider) {
  $translateProvider.translations('en_EN', {
    // #/reports
    'CALL_TO_ACTION_HEAD':                 'Help verify this report',
    'CALL_TO_ACTION_TEXT':                 'Checkdesk is a collaborative space for journalist led and citizen participating fact-checking.',
    'LANGUAGE_TOGGLE':                     'Switch to Arabic',
    'WELCOME_USER':                        'Welcome, {{name}}',
    'LOGOUT':                              'Logout',
    'USER_NAME':                           'User name',
    'PASSWORD':                            'Password',
    'LOG_IN':                              'Log in',
    'BOTTOM_CONTENT_GOES_HERE':            'Bottom content goes here.',
    'REALLY_BOTTOM_CONTENT_GOES_HERE':     'Really bottom content goes here.',

    // #/report/:nid
    '#_FACT_CHECKING_FOOTNOTES':           '{{num}} fact-checking footnotes',
    'VERIFIED':                            'Verified',
    'CREATE_NOTE':                         'Create note',
    'PEOPLE_HELPING_VERIFY_THIS_REPORT':   'People helping verify this report:',
    '#_JOURNALISTS':                       '{{num}} journalists',
    '#_CITIZENS':                          '{{num}} citizens',
    'CHANGED_STATUS_TO_VERIFIED':          'Changed status to verified',
    '#_MINUTES_SHORT':                     '{{num}}m',
    '#_HOURS_SHORT':                       '{{num}}h',
    'LOREM_IPSUM':                         'Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.',
    'CHANGED_STATUS_TO':                   'Changed status to',
    'UNDETERMINED':                        'Undetermined',
    'LOAD_MORE':                           'Load more'
  });

  $translateProvider.translations('ar_AR', {
    // #/reports
    'CALL_TO_ACTION_HEAD':                 'مساعدة في التحقق من هذا التقرير',
    'CALL_TO_ACTION_TEXT':                 'Checkdesk هو مساحة تعاونية للصحفي ومواطن قاد المشاركة تدقيق الحقائق.',
    'LANGUAGE_TOGGLE':                     'التبديل إلى الإنجليزية',
    'WELCOME_USER':                        'أهلا، {{name}}',
    'LOGOUT':                              'تسجيل الخروج',
    'USER_NAME':                           'اسم المستخدم',
    'PASSWORD':                            'كلمة السر',
    'LOG_IN':                              'تسجيل الدخول',
    'BOTTOM_CONTENT_GOES_HERE':            'محتوى أسفل يذهب هنا.',
    'REALLY_BOTTOM_CONTENT_GOES_HERE':     'محتوى أسفل حقا يذهب هنا.',

    // #/report/:nid
    '#_FACT_CHECKING_FOOTNOTES':           '{{num}} الحواشي تدقيق الحقائق',
    'VERIFIED':                            'التحقق',
    'CREATE_NOTE':                         'إنشاء حاشية',
    'PEOPLE_HELPING_VERIFY_THIS_REPORT':   'الناس الذين يساعدون تحقق من هذا التقرير:',
    '#_JOURNALISTS':                       '{{num}} الصحفيين',
    '#_CITIZENS':                          '{{num}} مواطنا',
    'CHANGED_STATUS_TO_VERIFIED':          'تغيرت الحالة إلى <em>التحقق</em>',
    '#_MINUTES_SHORT':                     '{{num}} دقيقة',
    '#_HOURS_SHORT':                       '{{num}} ساعات',
    'LOREM_IPSUM':                         'غريمه وحلفاؤها تعد من, جُل لم الذود السبب الأمامية, وبعض شمال فمرّ بحث لم. مما أمدها الأرواح بـ, بالقصف اتفاقية لبولندا بـ حشد, سقط أم الذود للصين للألمان.',
    'CHANGED_STATUS_TO_*':                 'تغيرت الحالة إلى',
    'UNDETERMINED':                        'غير محدد',
    'LOAD_MORE':                           'تحميل أكثر'
  });
  $translateProvider.uses('ar_AR');

  // FIXME: Something is amiss with the cookie thing.
  // $translateProvider.useCookieStorage();

  $translateProvider.useMissingTranslationHandler('cdTranslationUI');
}]);
