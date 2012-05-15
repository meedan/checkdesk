# WhatSite?
A development helper tool which enables quick visual differentiation between dev, testing, and live versions of a project.

For example, consider a Drupal project which is running on:

 * myproj.dev.agency.com,
 * myproj.testing.agency.com, and
 * www.myproj.com

Wouldn't it be nice if at a glance you could tell the sites apart?  Wouldn't it be great if you could also tell the browser tabs apart!

The WhatSite plugin makes this possible.


## Installation

 1. Move the what_site module files into the usual location (eg: sites/all/modules)
 2. Download the [WhatSite plugin from GitHub](https://github.com/jamesandres/WhatSite) and unzip it into sites/all/libraries.
 3. If everything has gone well you should be able to install the module.  If you have placed the WhatSite plugin in the wrong directory the module will fail to install (hint: read the error message)
 4. Grant appropriate users on your site the 'can see whatsite' permission

## TODOs

 * The WhatSite plugin is configurable in several ways but currently the Drupal module does not hook into this
