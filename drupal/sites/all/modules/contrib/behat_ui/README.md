Behat UI
========

The Behat UI module lets any person to run automated tests and create new tests (and also run them while they are being created).
The user can later download the updated feature with the newly created test.
It's fully customizable and the interface is very interactive/intuitive.

Features on running an existing test suite:

* The Behat binary and behat.yml can be located at any place, you just need to provide the path to them
* HTTP authentication, for both headless testing and real browser testing (Selenium)
* Tests run on background, the module checks for the process periodically and the output is updated on the screen (because some large test suites can take even hours to run)
* Kill execution
* Colored and meaningful output
* You can run the testing suite using Drush: `drush bui` or `drush behat-ui`

Features on creating a new test (scenario) through the interface:

* Choose feature (among the existing ones), title and whether it requires a real browser (i.e., needs JavaScript or not)
* Check available step types
* Choose step type from select field ("given", "when", "and" and "then")
* Auto-complete and syntax highlighting on the step fields
* Add new steps
* Remove a step
* Reorder steps
* Run test at any time (even if it's not completed yet)
* Download the updated feature with the new scenario

YAML extension is required. You can install it through PECL: `# pecl install yaml`

Check the example FeatureContext.php file for two examples of useful steps:

* Take screenshot (very useful for debugging specially if you run Selenium headless, using XVFB or something like that)
* HTTP authentication

If you don't know from where to start, please check the file sample-test-suite.zip.

Check [this video](http://ca.ios.ba/files/drupal/behatui.ogv) to understand better how it works.

Check the module on [Drupal.org](https://www.drupal.org/project/behat_ui).

This module was sponsored by [Meedan](http://meedan.org).
