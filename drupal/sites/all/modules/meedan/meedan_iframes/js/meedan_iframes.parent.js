/*jslint nomen: true, plusplus: true, todo: true, white: true, browser: true, indent: 2 */

/**
 * Parent component for Meedan seamless IFRAME support.
 */
(function () {

  // Based on aspects of http://benvinegar.github.com/seamless-talk/.
  // This script must be placed immediately after the IFRAME for the embed.
  'use strict';

  // Find the DOM node for THIS current script tag
  // See: http://stackoverflow.com/a/3326554/806988
  var scripts   = document.getElementsByTagName('script'),
      script    = scripts[scripts.length - 1],
      hashToken = '#' + Math.random().toString(36).substring(2),
      params, url, iframe, i;

  // See: http://stackoverflow.com/a/2880929/806988
  function getParams(query) {
    var match,
        pl     = /\+/g,  // Regex for replacing addition symbol with a space
        search = /([^&=]+)=?([^&]*)/g,
        decode = function (s) { return decodeURIComponent(s.replace(pl, " ")); },
        p = {};

    while (match = search.exec(query)) {
      p[decode(match[1])] = decode(match[2]);
    }

    return p;
  }

  params = /\?/.test(script.src) ? getParams(script.src.split('?')[1]) : false;

  if (!params || !params.u) {
    throw("Meedan: No embeddable URL provided.");
  }

  url = params.u;
  delete params.u;

  if (!/:\/\//.test(url)) {
    url = window.location.origin + url;
  }

  url = /\?/.test(url) ? url.replace(/\?/, '#' + hashToken) : url + hashToken;

  // Create an insert the iframe
  iframe = document.createElement('IFRAME');
  iframe.setAttribute('src', url);
  iframe.setAttribute('frameborder', '0');
  iframe.setAttribute('scrolling', 'no');
  iframe.setAttribute('seamless', '');

  for (i in params) {
    if (params.hasOwnProperty(i)) {
      iframe.setAttribute(i, params[i]);
    }
  }

  // Insert the iframe after the script tag
  script.parentNode.insertBefore(iframe, script.nextSibling);


  // Define the MessageHandler singleton object
  var MessageHandler = {

    // Handles messages conforming to one of two formats:
    //
    // A) e.data = 'message-type';
    // B) e.data = 'message-type;foo;bar;baz'
    handleMessage: function(e) {
      var data = e.data.split(';'),
          childToken = data.shift(),
          type = data.shift();

      // This message is not intended for us
      if (!childToken || childToken !== hashToken) {
        return;
      }

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
