(function(){
	var v = "1.8.3";

  // Install jQuery and initiate bookmarklet
	if (window.jQuery === undefined || window.jQuery.fn.jquery < v) {
		var done = false;
		var script = document.createElement("script");
		script.src = "http://ajax.googleapis.com/ajax/libs/jquery/" + v + "/jquery.min.js";
		script.onload = script.onreadystatechange = function(){
			if (!done && (!this.readyState || this.readyState == "loaded" || this.readyState == "complete")) {
				done = true;
				initMeedanBookmarklet();
			}
		};
		document.getElementsByTagName("head")[0].appendChild(script);
	} else {
		initMeedanBookmarklet();
	}

  // Initiate bookmarklet
	function initMeedanBookmarklet() {
		(window.meedanBookmarklet = function() {

      var MeedanBookmarklet = {};

      // Function to get information about the page
      function getPageInformation(key) {
        switch(key) {
          case 'url':
            return document.location.href;
            break;
          case 'title':
            return document.title;
            break;
          case 'selected':
            return getSelText();
            break;
        }
        return "";
      }

      // Function to get text selected by the user
			function getSelText() {
				var s = '';
				if (window.getSelection) {
					s = window.getSelection();
				} else if (document.getSelection) {
					s = document.getSelection();
				} else if (document.selection) {
					s = document.selection.createRange().text;
				}
        if (s == "") return document.title;
        else return s;
			}

      // Function that creates the bookmarklet
      function createBookmarklet() {
				var s = getSelText();
        var url = MeedanBookmarklet.settings.url;
        $.each(MeedanBookmarklet.settings.prepopulate, function(field, value) {
          url += '&meedan_bookmarklet_prepopulate[' + field + ']=' + getPageInformation(value);
        });
        $("head").append('<link type="text/css" rel="stylesheet" href="' + MeedanBookmarklet.settings.default_stylesheet + '?' + parseInt(Math.random()*10000000000) + '" media="all" />');
        if (MeedanBookmarklet.settings.stylesheet != '') $("head").append('<link type="text/css" rel="stylesheet" href="' + MeedanBookmarklet.settings.stylesheet + '?' + parseInt(Math.random()*10000000000) + '" media="all" />');
        if (MeedanBookmarklet.settings.javascript != '') $("body").append('<script type="text/javascript" src="' + MeedanBookmarklet.settings.javascript + '?' + parseInt(Math.random()*10000000000) + '"></script>');
				$("body").append("<div id='meedan_bookmarklet_cont'><a id='meedan_bookmarklet_close'><span>[X]</span></a><iframe src='" + url + "' id='meedan_bookmarklet_frame'></iframe></div><div id='meedan_bookmarklet_mask'></div>");
        $('#meedan_bookmarklet_close').click(function() {
          $('#meedan_bookmarklet_cont, #meedan_bookmarklet_mask').fadeOut(500);
        });
        $('body').scrollTop(0);
        $('#meedan_bookmarklet_cont').show();
      }

      // First time, create bookmarklet window
			if ($("#meedan_bookmarklet_cont").length == 0) {

        // Load settings
        var url = window.meedanBookmarkletHost + '/?' + $.param({ q: 'meedan_bookmarklet/js' }) + '&callback=?';
        $.getJSON(url, function(json) {
          MeedanBookmarklet.settings = json;
          createBookmarklet();
        });

      // After the first time, just show and hide the bookmarklet  
			} else {
				$("#meedan_bookmarklet_cont, #meedan_bookmarklet_mask").fadeIn(500);
        $('body').scrollTop(0);
			}

		})();
	}
})();
