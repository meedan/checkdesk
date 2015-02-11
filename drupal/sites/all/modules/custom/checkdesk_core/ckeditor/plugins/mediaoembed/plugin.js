// Some CSS for the widget to make it more visible.

CKEDITOR.plugins.add('mediaoembed', {
  requires: 'widget',
  init: function(editor) {
  // Just a button to show that "mediaoembed" 
  // becomes a command.
  editor.ui.addButton && editor.ui.addButton( 'mediaoembed', {
    label: Drupal.t('Media Oembed'),
    command: 'mediaoembed',
    icon : this.path + 'icon-mediaoembed.png',
  });

  // Register the widget.
  editor.widgets.add( 'mediaoembed', {
    // This will be inserted into the editor if the button is clicked.
    template: '<md class="tagMediaOembedClass" datasource="0"></md>',
    // A rule for ACF, which permits span.tagSpecialClass in this editor.
    allowedContent: 'md(tagMediaOembedClass)[!datasource];iframe span img div(*)[*]',

    // When editor is initialized, this function will be called
    // for every single element. If element matches, it will be
    // upcasted as a "mediaoembed".
    upcast: function( el ) {
      return el.name == 'md' && el.hasClass( 'tagMediaOembedClass' );
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
      //console.log(this.element);
      var datasource = this.element.getAttribute('datasource');
      if (datasource > 0) {
        var mediapreview = this.element;
        jQuery.ajax({
          url: Drupal.settings.basePath + Drupal.settings.pathPrefix + 'checkdesk/media-widget/' + datasource,
          dataType: 'json',
          success: function (data) {
            mediapreview.setHtml(data.preview);
            mediapreview.setAttribute('media_ref', data.media_ref);
          },
          error: function (xhr, textStatus, error) {
          },
        });
      }
    }
  } );
}
});


