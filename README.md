# Meedan Drupal 7 Boilerplate

This project is a derivative of the Meedan Drupal Boilerplate.  Please refer to the following files for more information:

 * **database/README.md** regarding SQL snapshots
 * **design/README.md** about designs, wireframe and related assets for this project
 * **patches/README.md** regarding core and contrib module patches practices
 * **patches/PATCHES.md** for a list of reasons why each currently active patch has been applied, and other notes


## Components of Meedan Boilerplate

The boilerplate consists of 3 main components:

 * The overall boilerplate directory structure
 * The Meedan git submodules
 * The separation of site specific settings and code from the boilerplate, integration points are:
   * profiles/meedan_boilerplate which installs the basic boilerplate stuff and kicks off custom installation
   * sites/default/settings.php includes global settings and hooks in custom settings.


## TODO

 * Document:
   * Boilerplate usage best practices / guidelines
   * Boilerplate upgrade guidelines
   