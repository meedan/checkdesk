WhatSite
========

Helps web developers and administrators quickly distinguish dev and test
sites from the production site.


Usage
=====

Basic usage:

    <script src="WhatSite/whatsite.js" />
    <script>
      WhatSite().apply();
    </script>

Or, if you use jQuery in your project:

    <script src="WhatSite/whatsite.js" />
    <script>
    $(function () {
        WhatSite.apply();
    });
    </script>

More advanced usage:

    <!-- Example #1: Affect the favicon only, not the body. -->
    <script>
      WhatSite
        .init({
            "affects": [
                "favicon",
            ]
        })
        .apply();
    </script>
    
    <!-- Example #2: Create a new "local" realm with a unique color and 
                     have "dev" no longer match local domains.
                     
                     Note, settings are additive so the "test" realm is
                     unaffected.  -->
    <script>
      WhatSite
          .init({
              "local": {
                  "host": "\\.local(host)?",
                  "color": "#66ccff"
              },
              "dev": {
                  "host": "\\.dev\\.",
                  "color": "#66ccff"
              },
          })
          .apply();
    </script>

