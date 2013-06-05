var page = require('webpage').create(),
    system = require('system'),
    url, timeout,
    t, delay, checker, html, body;

if (system.args.length <= 1) {
  system.stdout.write('Usage: snapshot.js URL [TIMEOUT]');
  phantom.exit();
}

url     = system.args[1];
timeout = system.args[2] || 30000;

t = Date.now();

page.open(url, function (status) {
  if (status == 'success') {
    checker = function() {
      html = page.evaluate(function () {
        body = document.getElementsByTagName('body')[0];

        if (body.getAttribute('data-status') == 'ready') {
          return document.getElementsByTagName('html')[0].outerHTML;
        }
      });

      if (html) {
        clearTimeout(delay);
        system.stdout.write(html);
        phantom.exit();
      }
      else if (Date.now() - t > timeout) {
        clearTimeout(delay);
        system.stderr.write('ERROR: Snapshot timed out for ' + url);
        phantom.exit();
      }
    };

    delay = setInterval(checker, 100);
  }
});
