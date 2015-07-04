/*
* Embed Media Dialog based on http://www.fluidbyte.net/embed-youtube-vimeo-etc-into-ckeditor
*
* Plugin name:      mediaembed
* Menu button name: MediaEmbed
*
* Youtube Editor Icon
* http://paulrobertlloyd.com/
*
* @author Fabian Vogelsteller [frozeman.de]
* @version 0.6
*/
CKEDITOR.plugins.add( 'mediaembed',
    {
        icons: 'mediaembed', // %REMOVE_LINE_CORE%
        hidpi: true, // %REMOVE_LINE_CORE%
        lang: 'en,ar',
        init: function( editor )
        {
           var me = this;
           CKEDITOR.dialog.add( 'MediaEmbedDialog', function (instance)
           {
              return {
                 title : editor.lang.mediaembed.dialogTitle,
                 minWidth : 550,
                 minHeight : 200,
                 contents :
                       [
                          {
                             id : 'iframe',
                             expand : true,
                             elements :[{
                                id : 'embedArea',
                                type : 'textarea',
                                label : editor.lang.mediaembed.dialogLabel,
                                'autofocus':'autofocus',
                                setup: function(element){
                                },
                                commit: function(element){
                                }
                              }]
                          }
                       ],
                  onOk: function() {
                        var div = instance.document.createElement('div');
                        div.addClass('media_embed');
                        var embedCode = this.getContentElement('iframe', 'embedArea').getValue();
                        var videoRegExp = new RegExp('(<iframe.*src=(\"|\')https?\:\/\/)?((www\.)?youtube\.com|youtu\.?be|player.vimeo\.com)')
                        if (videoRegExp.test(embedCode)) {
                          div.addClass('video');
                        }
                        div.setHtml(embedCode);
                        instance.insertElement(div);
                  }
              };
           } );

            editor.addCommand( 'MediaEmbed', new CKEDITOR.dialogCommand( 'MediaEmbedDialog',
                { allowedContent: 'iframe[*]' }
            ) );

            editor.ui.addButton( 'MediaEmbed',
            {
                label: editor.lang.mediaembed.toolbar,
                command: 'MediaEmbed',
                toolbar: 'mediaembed'
            } );
        }
    } );
