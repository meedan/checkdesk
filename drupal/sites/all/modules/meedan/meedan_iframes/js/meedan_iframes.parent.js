/**
 * Parent component for Meedan seamless IFRAME support.
 */
(function () {

  // Based on aspects of http://benvinegar.github.com/seamless-talk/.
  // This script must be placed immediately after the IFRAME for the embed.
  'use strict';

  // Find the DOM node for THIS current script tag
  // See: http://stackoverflow.com/a/3326554/806988
  var scripts = document.getElementsByTagName('script'),
      script  = scripts[scripts.length - 1],
      iframes = document.getElementsByTagName('iframe'),
      iframe  = iframes[iframes.length - 1];

  if (!script || script.tagName !== 'SCRIPT') {
    throw("Meedan: Could not locate embedded widget SCRIPT.");
  }
  if (!iframe || iframe.tagName !== 'IFRAME') {
    throw("Meedan: Could not locate embedded widget IFRAME.");
  }


  // Define the MessageHandler singleton object
  var MessageHandler = {

    // Handles messages conforming to one of two formats:
    //
    // A) e.data = 'message-type';
    // B) e.data = 'message-type;foo;bar;baz'
    handleMessage: function(e) {
      var data = e.data.split(';'),
          type = data.shift();

      switch (type) {
        case 'loaded':    MessageHandler.handleLoadedMessage(data); break;
        case 'setHeight': MessageHandler.handleSetHeightMessage(data); break;
      }
    },

    handleLoadedMessage: function (data) { },

    handleSetHeightMessage: function (data) {
      if (data[0]) {
        iframe.style.height = data[0] + 'px';
      }
      MessageHandler.api('postSetHeight', data);
    },

    api: function (type, data) {
      var event;

      if (document.createEvent) {
        event = document.createEvent("HTMLEvents");
        event.initEvent(type, true, true);
      } else {
        event = document.createEventObject();
        event.eventType = type;
      }

      event.data = data || {};

      if (document.createEvent) {
        iframe.dispatchEvent(event);
      } else {
        iframe.fireEvent("on" + event.eventType, event);
      }
    }
  };


  if (!window.addEventListener) {
    window.attachEvent('onmessage', MessageHandler.handleMessage);
  } else {
    window.addEventListener('message', MessageHandler.handleMessage, false);
  }

}());
