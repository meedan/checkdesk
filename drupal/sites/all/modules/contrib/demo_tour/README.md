Demo Tour
=========

This module allows administrators to create tours for a Drupal site. Tours can
show to the users how some features work. This module depends on CTools, so you
can export tours to Features, for example, besides all other benefits that CTools
provides. It's based on Bootstrap Tour.

After enabling the module, go to the administration page (admin/structure/demo_tour) where
you can manage (create, edit, remove, enable, disable, etc.) tours. Tours loaded from files
(e.g., Features) and from the database will be available. Each tour must have both a readable
name and a machine name (unique). Tours can be applied just to users with some roles, and also
can be forced to play automatically only once for each user. You can also provide a list of
path patterns, and so the tour is played only if the current path matches one of the patterns.

A tour is made of steps. Through the UI it's possible to add and remove the steps to each tour. A step
consists of a CSS selector (near which the tooltip will be positioned), a title and a description.

You can also force a tour to be played by appending `?tour=<machine name of the tour>` to the URL.

Check [this video](http://ca.ios.ba/files/drupal/demotour.ogv) to understand better how it works.

Check the module on [Drupal.org](https://www.drupal.org/project/demo_tour).

This module was sponsored by [Meedan](http://meedan.org).
