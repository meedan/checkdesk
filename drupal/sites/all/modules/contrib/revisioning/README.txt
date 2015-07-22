
DESCRIPTION
===========
This module channels unpublished content as well as edits to current content
into a queue for review by a moderator/publisher prior to becoming "live", i.e.
visible to the public.

We took our inspiration from the Revision Moderation module by Angie Byron,
but found that a patch could not implement the deviating functionality our
customers required, which would change the current behaviour of the RM module
and surprise existing users.

The Revisioning module now comes with two user interface models to chose from:
"traditional" and "updated".

Traditional: The traditional UI model is enabled by default. With the standard
UI, the emphasis is on minimizing the number of controls, so each page is free
of buttons and links that are not immediately relevant.

Updated: The updated UI model can be selected by enabling the "revisioning_ux"
submodule. In the updated UI, the emphasis is on maintaining consistent
navigation controls.  This allows revision moderators to flip between the tabs
on the revisions operations page without ending up on a page that no longer
contains all of the tabs formerly available.

There are no database schema differences between the two UI models; you may
enable revisioning_ux, try it out, and later go back to the traditional model
without any difficulty.


INSTALLATION & CONFIGURATION
============================
Step-by-step instructions can be found in the tutorials listed on the
Revisioning project page, http://drupal.org/project/revisioning.

AUTHORS
=======
Main module: Rik de Boer, Melbourne, Australia.
Revisioning UX: Greg Anderson, USA
