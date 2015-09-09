
Save_draft adds a 'Save as Draft' Button to the node_form for content types,
allowing the user to click the 'Save as Draft' button to save the node as a
draft.  This helps improve usability, as the content creator no longer has to
search for the published checkbox as they can just click the 'Save as Draft'
Button.

Install
-------

1) Copy the save_draft folder to the modules folder in your installation.

2) For Drupal 6: Enable the module using Administer -> Site building -> Modules
   (/admin/build/modules) and for Drupal 7, go to admin/modules.

3) Now when you create a new node, a 'Save as Draft' button will be
   added to the form.


Developers
----------
If your module adds a button to the node form module and are using the
"Skip required validation" option you can allow your button to also skip
required validation by adding the #skip_required_validation property to your
button. For example, if you are adding a button 'my_button' to the form actions
you would add this property also:
$form['actions']['my_button']['#skip_required_validation'] = TRUE;

Note: Once the module is enabled, all the content types have "save draft" button
enabled and the published checkbox in the node create form will be hidden.
