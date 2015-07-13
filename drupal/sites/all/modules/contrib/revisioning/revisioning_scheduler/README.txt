
DESCRIPTION
===========
The Revisioning Scheduler is an optional add-on for the Revisioning module.
It allows users to schedule a publication date for a new or existing content
revision (in the latter case we speak of reversion rather than publication).

The publication date and time may be set when clicking the Publish or Revert
links or on the content edit form prior to pressing Save.

The publication date text field on the content edit form appears only when:
o the user has publish or "administer content" permission for this piece of
  content
o "Auto-publish drafts of type ..." is NOT ticked on the content type edit form
  (or it is ticked, but the user does not have permission to publish)
o a) the node is currently not published yet (Published box NOT ticked), or
  b) if it is published, "Create new revision and moderate" IS ticked
     under "Publishing options".

INSTALLATION & CONFIGURATION
============================
Enable like any other module. Then have a look at the self-explanatory
configuration options at Configurartion >> Revisioning Scheduler.

CHANGELOG
=========
http://drupalcode.org/project/revisioning.git/shortlog/refs/heads/7.x-1.x

AUTHORS
=======
Original version by Adam Bramley, adam at catalyst dot net dot nz
Edit form extension by Zvi Epner (zepner on http://drupal.org)
Further developed by Rik de Boer, rik at flink dot com dot au
