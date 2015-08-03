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
                        instance.dataProcessor.writer.setRules( 'figure', {
                            indent: false,
                            breakBeforeOpen: false,
                            breakAfterOpen: false,
                            breakBeforeClose: false,
                            breakAfterClose: false
                        });
                        var div = instance.document.createElement('div');
                        var figure = instance.document.createElement('figure');
                        div.addClass('media');
                        figure.addClass('element');
                        var embedCode = this.getContentElement('iframe', 'embedArea').getValue();
                        var videoRegExp = new RegExp('(<iframe.*src=(\"|\')https?\:\/\/)?((www\.)?youtube\.com|youtu\.?be|.*\.vimeo\.com/)');
                        if (videoRegExp.test(embedCode)) {
                          div.addClass('video-holder');
                          div.addClass('media-16by9');
                          figure.addClass('element-video');
                        }
                        div.setHtml(embedCode);
                        figure.append(div);
                        instance.insertHtml(figure.getOuterHtml() + '<p></p>');
                  }
              };
           } );

            editor.addCommand( 'MediaEmbed', new CKEDITOR.dialogCommand( 'MediaEmbedDialog',
            {
                allowedContent:
                {
                    'iframe figure div blockquote': {
                        classes: '*',
                        attributes: '*'
                    },
                    'script': {
                        match: function(el) {
                            if (!el.attributes.src) return false;

                            // Parse script source.
                            // @see https://gist.github.com/jlong/2428561
                            var parser = document.createElement('a');
                            parser.href = el.attributes.src;

                            // TODO Allow white-listed script sources or some other way to validate scripts.
                            var match = parser.hostname.match(/twitter.com$/i);
                            return match && match.length > 0;
                        },
                        attributes: '*'
                    }
                }
            } ) );

            editor.ui.addButton( 'MediaEmbed',
            {
                label: editor.lang.mediaembed.toolbar,
                command: 'MediaEmbed',
                toolbar: 'mediaembed'
            } );
        }
    } );
