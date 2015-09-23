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
CKEDITOR.plugins.add('mediaembed',
        {
          icons: 'mediaembed', // %REMOVE_LINE_CORE%
          hidpi: true, // %REMOVE_LINE_CORE%
          lang: 'en,ar',
          requires: 'widget,dialog',
          init: function (editor)
          {
            var me = this;
            CKEDITOR.dialog.add('MediaEmbedDialog', function (editor)
            {
              return {
                title: editor.lang.mediaembed.dialogTitle,
                minWidth: 550,
                minHeight: 200,
                contents:
                        [
                          {
                            id: 'iframe',
                            expand: true,
                            elements: [{
                                id: 'embedArea',
                                type: 'textarea',
                                label: editor.lang.mediaembed.dialogLabel,
                                'autofocus': 'autofocus',
                                setup: function (widget) {
                                  this.setValue(widget.data.embedCode);
                                },
                                commit: function (widget) {
                                  widget.setData('embedCode', this.getValue());
                                }
                              }]
                          }
                        ],
              };
            });

            editor.widgets.add('mediaembed', {
              template:
                      '<figure class="element">' +
                      '<div class="media"></div>' +
                      '</figure>',
              parts: {
                wrapper: 'figure.element',
                codeDiv: 'div.media'
              },
              allowedContent:
                      {
                        'iframe figure div blockquote': {
                          classes: '*',
                          attributes: '*'
                        },
                        'script': {
                          match: function (el) {
                            if (!el.attributes.src)
                              return false;

                            // Parse script source.
                            // @see https://gist.github.com/jlong/2428561
                            var parser = document.createElement('a');
                            parser.href = el.attributes.src;

                            // TODO Allow white-listed script sources or some other way to validate scripts.
                            var match = parser.hostname.match(/\.(twitter.com)$/i);
                            return match && match.length > 0;
                          },
                          attributes: '*'
                        }
                      },
              requiredContent: 'div(simplebox)',
              dialog: 'MediaEmbedDialog',
              upcast: function (element) {
                return element.name == 'figure' && element.hasClass('element');
              },
              init: function (widget) {
                this.setData('embedCode','hey');
                embedCode = this.parts.codeDiv.getHtml();
                this.setData('embedCode', embedCode);
              },
              data: function (widget) {
                var embedCode = this.data.embedCode;
                var videoRegExp = new RegExp('(<iframe.*src=(\"|\')https?\:\/\/)?((www\.)?youtube\.com|youtu\.?be|.*\.vimeo\.com/)');
                if (videoRegExp.test(embedCode)) {
                  this.parts.codeDiv.addClass('video-holder');
                  this.parts.codeDiv.addClass('media-16by9');
                  this.parts.wrapper.addClass('element-video');
                }
                this.parts.codeDiv.setHtml(embedCode);
              }
            });
            editor.ui.addButton('MediaEmbed',
                    {
                      label: editor.lang.mediaembed.toolbar,
                      command: 'mediaembed',
                      toolbar: 'mediaembed'
                    });
          }
        });
