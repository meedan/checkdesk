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
  } );     
  // Register the widget.
  editor.widgets.add( 'mediaoembed', {
    // This will be inserted into the editor if the button is clicked.
    template: '<span class="tagSpecialClass" datasource="20">Add content here</span>',

    // A rule for ACF, which permits span.tagSpecialClass in this editor.
    allowedContent: 'span(tagSpecialClass)',

    editables: {
      contents: {
        selector: '.tagSpecialClass'
      }
    },

    // When editor is initialized, this function will be called
    // for every single element. If element matches, it will be
    // upcasted as a "mediaoembed".
    upcast: function( el ) {
      return el.name == 'span' && el.hasClass( 'tagSpecialClass' );
    },

    // This is what happens with existing widget, when
    // editor data is returned (called editor.getData() or viewing source).
    downcast: function( el ) {
      el.setHtml( '[node-' + el.attributes.datasource + ']' );
    },

    // This could be done in upcast. But let's do it here
    // to show that there's init function, which, unlike
    // upcast, works on real DOM elements.
    init: function() {
      //console.log(this.element);
      var datasource = this.element.getAttribute('datasource');
      this.element.setHtml('Should get thumbnail for node - ' + datasource);
    }

  } );
}
});


