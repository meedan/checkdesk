// Some CSS for the widget to make it more visible.

CKEDITOR.plugins.add('reportembed', {
  requires: 'widget',
  init: function(editor) {
  // Just a button to show that "reportembed" 
  // becomes a command.
  editor.ui.addButton && editor.ui.addButton( 'reportembed', {
    label: Drupal.t('Report Embed'),
    command: 'reportembed',
    icon : this.path + 'icon-reportembed.png',
  });

  // Register the widget.
  editor.widgets.add( 'reportembed', {
    // This will be inserted into the editor if the button is clicked.
    template: '<xcheckdeskreport class="tagReportEmbedClass" datasource="0"></xcheckdeskreport>',
    // A rule for ACF, which permits span.tagSpecialClass in this editor.
    allowedContent: 'xcheckdeskreport(tagReportEmbedClass)[!datasource];iframe span img div(*)[*]',

    // When editor is initialized, this function will be called
    // for every single element. If element matches, it will be
    // upcasted as a "reportembed".
    upcast: function( el ) {
      return el.name == 'xcheckdeskreport' && el.hasClass( 'tagReportEmbedClass' );
    },

    // This is what happens with existing widget, when
    // editor data is returned (called editor.getData() or viewing source).
    downcast: function( el ) {
      media_ref = el.attributes.media_ref;
      if (media_ref) {
        el.setHtml( media_ref );
      }
    },
    // This could be done in upcast. But let's do it here
    // to show that there's init function, which, unlike
    // upcast, works on real DOM elements.
    init: function() {
      var self = this;
      var datasource = this.element.getAttribute('datasource');
      if (datasource > 0) {
        var mediapreview = this.element;
        jQuery.ajax({
          url: Drupal.settings.basePath + Drupal.settings.pathPrefix + 'checkdesk/media-widget/' + datasource,
          dataType: 'json',
          success: function (data) {
            // <testing>
            data.preview = '';
            data.preview += '<blockquote class="twitter-tweet" lang="en"><p lang="en" dir="ltr">Thank you <a href="https://twitter.com/MrStanleyClarke">@MrStanleyClarke</a> for an amazing show tonight <a href="https://twitter.com/VogueTheatre">@VogueTheatre</a> <a href="https://twitter.com/coastaljazz">@coastaljazz</a> Always inspiring! <a href="https://twitter.com/hashtag/jazz?src=hash">#jazz</a> <a href="https://twitter.com/hashtag/art?src=hash">#art</a> <a href="https://twitter.com/hashtag/bass?src=hash">#bass</a> <a href="http://t.co/w0rzu79kdl">pic.twitter.com/w0rzu79kdl</a></p>&mdash; Robert Edmonds (@robert_edmonds) <a href="https://twitter.com/robert_edmonds/status/613232701768732672">June 23, 2015</a></blockquote><script async src="//platform.twitter.com/widgets.js" charset="utf-8"></script><script>twttr.widgets.load();</script>';
            data.preview += '<div id="fb-root"></div><script>(function(d, s, id) {  var js, fjs = d.getElementsByTagName(s)[0];  if (d.getElementById(id)) return;  js = d.createElement(s); js.id = id;  js.src = "//connect.facebook.net/en_US/sdk.js#xfbml=1&version=v2.3";  fjs.parentNode.insertBefore(js, fjs);}(document, "script", "facebook-jssdk"));</script><div class="fb-post" data-href="https://www.facebook.com/tarekamr/posts/10153320026960944" data-width="500"><div class="fb-xfbml-parse-ignore"><blockquote cite="https://www.facebook.com/tarekamr/posts/10153320026960944"><p>&#x634;&#x64a;&#x62e; &#x627;&#x644;&#x623;&#x632;&#x647;&#x631; &#x628;&#x64a;&#x633;&#x62a;&#x623;&#x630;&#x646; &#x645;&#x646; &#x627;&#x644;&#x633;&#x639;&#x648;&#x62f;&#x64a;&#x629; &#x64a;&#x639;&#x645;&#x644; &#x62a;&#x642;&#x627;&#x631;&#x628; &#x628;&#x64a;&#x646; &#x627;&#x644;&#x645;&#x630;&#x627;&#x647;&#x628; &#x648;&#x644;&#x627; &#x644;&#x623;&#x60c; &#x639;&#x646; &#x627;&#x644;&#x623;&#x632;&#x647;&#x631; &#x627;&#x644;&#x648;&#x633;&#x637;&#x64a; &#x627;&#x644;&#x643;&#x64a;&#x648;&#x62a; &#x646;&#x62a;&#x62d;&#x62f;&#x62b;</p>Posted by <a href="https://www.facebook.com/tarekamr">Tarek Amr</a> on <a href="https://www.facebook.com/tarekamr/posts/10153320026960944">Monday, June 22, 2015</a></blockquote></div></div><script>FB.XFBML.parse();</script>';
            data.preview += '<script>alert("hi!")</script><script src="/sites/all/modules/custom/checkdesk_core/ckeditor/plugins/reportembed/test.js"></script>';
            // </testing>
            mediapreview.setAttribute('media_ref', data.media_ref);
            mediapreview.setHtml(data.preview);
            jQuery(mediapreview.$).find('script').each(function() {
              if (this.src) {
                var script = jQuery(this).clone();
                jQuery(this).replaceWith(script);
              }
              else {
                var globalEval = function(code, context) {
                  context = context || document;
                  var script = context.createElement("script");
                  
                  script.text = code;
                  context.head.appendChild(script).parentNode.removeChild(script);
                }
                var ck = CKEDITOR.instances['edit-body-und-0-value'],
                    txt = this.text || this.textContent || this.innerHTML || '';
                globalEval(txt, ck.document.$);
              }
            });
          },
          error: function (xhr, textStatus, error) {
          },
        });
      }
    }
  } );
}
});
