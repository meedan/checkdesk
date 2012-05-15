var WhatSite = (function () {
  // See: http://ejohn.org/blog/ecmascript-5-strict-mode-json-and-more/
  "use strict";

  //
  // The WhatSite object
  //
  var WhatSite = function () {
                   return this.init();
                 },
      _WhatSite = null;

  WhatSite.prototype.init = function (userOpts) {
    if (typeof userOpts !== "undefined" && typeof userOpts !== "object") {
      if (console && console.log) {
        console.log("WhatSite: invalid options passed to WhatSite().");
      }
      return false;
    }

    this.defaults = {
      "affects": [
        "favicon",
        "body"
      ],
      "sites": {
        "dev": {
          "host": "\\.dev\\.|\\.local(host)?",
          "color": "#66ccff" // Sky
        },
        "test": {
          "host": "\\.(test|qa)\\.",
          "color": "#ffcc66" // Cantaloupe
        }
      }
    };

    this.opts = this.extend(this.defaults, userOpts);

    return this;
  };


  // Affect the site NOW.
  WhatSite.prototype.apply = function () {
    var realm = this.thisSite();

    if (realm !== false) {
      this.affect(realm);
    }

    return this;
  };


  // Should this site be affected?
  WhatSite.prototype.thisSite = function () {
    var realm, host, patt;

    for (realm in this.opts.sites) {
      if (this.opts.sites.hasOwnProperty(realm)) {
        host = this.opts.sites[realm].host;

        if (typeof host !== "undefined") {
          patt = new RegExp(host);

          if (window.location.hostname.match(patt) !== -1) {
            return realm;
          }
        }
      }
    }

    return false;
  };


  // Apply changes
  WhatSite.prototype.affect = function (realm) {
    var affects = this.extend(this.opts.affects, this.opts.sites[realm].affects),
        color = this.opts.sites[realm].color,
        i;

    for (i = affects.length; i >= 0; i -= 1) {
      if (typeof affects[i] === "undefined") {
        continue;
      } else if (typeof affects[i] === "function") {
        affects[i](color, realm);
      } else {
        switch (affects[i]) {
          case "favicon": this.affectFavicon(color); break;
          case "body":    this.affectBody(color); break;
        }
      }
    }

    return this;
  };


  // Applies a coloured bar to the favicon
  WhatSite.prototype.affectFavicon = function (color) {
    var i,
        linkTags = document.getElementsByTagName("link"),
        icon = null,
        rel,
        iconImg,
        flatColor;

    for (i = linkTags.length; i >= 0; i -= 1) {
      if (typeof linkTags[i] !== "object") {
        continue;
      }
      rel = linkTags[i].getAttribute("rel");
      if (typeof rel === "undefined") {
        continue;
      }

      if (rel === "shortcut icon") {
        icon = linkTags[i];
        break;
      }
    }

    iconImg = new Image();
    flatColor = this.splitColor(color).join(",");

    // See: https://developer.mozilla.org/en/Canvas_tutorial/Using_images
    iconImg.onload = function () {
      var canvas, ctx, newIcon;

      canvas = document.createElement("canvas");
      canvas.setAttribute("width", "16px");
      canvas.setAttribute("height", "16px");
      ctx = canvas.getContext("2d");  

      ctx.lineCap = "butt";
      ctx.drawImage(iconImg, 0, 0);  

      ctx.beginPath();
        ctx.strokeStyle = "rgba(" + flatColor + ",1)";
        ctx.lineWidth = 4;
        ctx.moveTo(0, 0);
        ctx.lineTo(canvas.width, 0);
      ctx.stroke();

      ctx.beginPath();
        ctx.strokeStyle = "rgba(0,0,0,0.7)";
        ctx.lineWidth = 1;
        ctx.moveTo(0, 2.5);
        ctx.lineTo(canvas.width, 2.5);
      ctx.stroke();

      // See: http://www.p01.org/releases/DEFENDER_of_the_favicon/
      try {
        (newIcon = icon.cloneNode(true)).setAttribute("href", ctx.canvas.toDataURL());
        icon.parentNode.replaceChild(newIcon, icon);
      } catch (e) {
        // Nobody cares if a favicon goes untweaked
      }
    };

    iconImg.src = icon.href;

    return this;
  };


  // Applies coloured bar to the body element
  WhatSite.prototype.affectBody = function (color) {
    var stripe, body;

    stripe = document.createElement("div");
    stripe.style.backgroundColor = color;
    stripe.style.zIndex = 1000; // Ensure it is higher than 999 for Drupal's admin_menu
    stripe.style.position = "absolute";
    stripe.style.top = "0px";
    stripe.style.left = "0px";
    stripe.style.width = "100%";
    stripe.style.height = "3px";

    body = document.getElementsByTagName("body")[0];
    body.insertBefore(stripe, body.childNodes[0]);

    return this;
  };


  // See: http://stackoverflow.com/a/383245/806988
  WhatSite.prototype.extend = function (obj, defaults) {
    var p;

    for (p in defaults) {
      if (defaults.hasOwnProperty(p)) {
        try {
          // Property in destination object set; update its value.
          if (defaults[p].constructor === Object) {
            obj[p] = this.extend(obj[p], defaults[p]);
          } else {
            obj[p] = defaults[p];
          }
        } catch (e) {
          // Property in destination object not set; create it and set its value.
          obj[p] = defaults[p];
        }
      }
    }

    return obj;
  };


  // See: http://stackoverflow.com/questions/5623838/rgb-to-hex-and-hex-to-rgb
  WhatSite.prototype.splitColor = function (color) {
    var result = /^#?([a-f\d]{2})([a-f\d]{2})([a-f\d]{2})$/i.exec(color);

    return result ? [
      parseInt(result[1], 16),
      parseInt(result[2], 16),
      parseInt(result[3], 16)
    ] : null;
  };

  if (!_WhatSite) {
    _WhatSite = new WhatSite();
  }

  return _WhatSite;

}());
