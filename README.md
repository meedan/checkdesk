Checkdesk is a multilingual custom CMS tailored for the verification and liveblogging of social media. It is built upon the [Drupal 7](http://drupal.org) PHP content management platform. Technically speaking, Checkdesk is a [Drupal distribution](https://drupal.org/documentation/build/distributions).

# Application model
Checkdesk allows *citizen journalists* to submit social media links for *verification*. The purpose of verification is to check the veracity of the information presented by the media item. On Checkdesk, verification is a social activity that is carried out by the users. 

A new media link becomes a *report* around which the verification activity is conducted. A *professional journalist* is notified of the submission of a new report, and upon review, can decide to publish it in an *update* to one of the running *stories* on the site. 

The community of users can then proceed to add *verification footnotes* to the report, where they discuss the veracity of the information. Users can also *flag* the report for spam, graphic scenes, etc. Journalists can change the *verification status* of the report to such states as "verified", "false", "pending verification", etc. The report's *verification log* reflects this fact-checking activity.

A published update shows up on the public view of the associated story, which is a *liveblog*. The public landing page is an aggregated liveblog of all running stories.

Users and visitors can *share* stories, updates and reports to various social networks, as well as *embed* those objects on their own pages, using oEmbed codes.

# Installation
Checkdesk installation is similar to a [standard Drupal installation](https://drupal.org/documentation/install), with minor twists:

1. Create a blank MySQL database, e.g. `checkdesk` and grant all permissions to some user, e.g. `'checkdesk'@'localhost'`.
2. In your `/drupal/sites/default` folder (where your `settings.php` file resides), create a new file `settings.local.php` where you enter your database configuration, e.g.:

    <?php

    $databases['default']['default'] = array(
      'driver'   => 'mysql',
      'database' => 'checkdesk',
      'username' => 'checkdesk',
      'password' => '',
      'host'     => 'localhost',
      'prefix'   => '',
    );

3. You're now ready to run the Drupal installer. Choose the **Checkdesk** installation profile. During installation, you will be asked to configure a few Web services:

* [Embedly](http://embed.ly/), a service that renders links into embeddable HTML components using oEmbed. Sign up for a free account and copy your account's **API Key** to the corresponding form field.
* Twitter, to allow logging in through Twitter. To fill in:
  * Create a new Twitter application 
  * Set the **Callback URL** is set to `http://<checkdesk.domain.name>/twitter/oauth`
  * Set the **Access level** to `Read-only`
  * Turn ON the option **Allow this application to be used to Sign in with Twitter**
  * Once the application is saved, copy the **API key** and **API secret** to the corresponding form fields
* Facebook, to allow logging in through Facebook. To fill in:
  * Create a new Facebook application
  * Add a **Website** Platform
  * Set the **Site URL** to `http://<checkdesk.domain.name>`
  * Turn ON **Advanced >> Client OAuth Login** and **Embedded browser OAuth Login**
  * Once the application is saved, copy the **App ID** and **App Secret** to the corresponding form fields

# Project layout

    meedan-checkdesk/
       |-config                                      # configuration files
       |-drupal                                      # Drupal application root
       |-patches                                     # patches to Drupal core, modules, other components
       |-test                                        # testing files
       |---behat                                     # Behat tests
       |---html                                      # HTML tests
       |-ng-ui                                       # experimental Angular.js front-end

# Compiling SASS
The Checkdesk theme uses [SASS](http://sass-lang.com/). Although the repo contains the pre-compiled CSS files, you will need to setup a working SASS development environment if you wish to modify the theme. Install [Ruby](https://www.ruby-lang.org) then type the following in a console from the Checkdesk root folder:
    
    > gem install bundler
    > bundle install
    > bundle exec guard start 

The last command should start a script that watches the contents of the SCSS files in the Checkdesk theme folder, and trigger a recompilation of the CSS if the files are changed.

# Running a development environment
While developing, it is useful to turn on debugging features on Drupal and modules. Debugging settings are all bundled in a configuration feature called *Checkdesk Devel*. To turn it on, install [Drush](https://github.com/drush-ops/drush) then type the following from the Checkdesk `/drupal` folder:
    
    > drush en -y checkdesk_devel_feature

# Running Behat tests
Checkdesk comes with a number of [Behat](http://behat.org/) test cases, and allows more cases to be written and ran via the Drupal admin interface. Refer to [TESTING.txt](https://github.com/meedan/meedan-checkdesk/blob/master/TESTING.txt) for instructions on setting up and running Behat tests.

# Feedback
Please [submit issues](https://github.com/meedan/meedan-checkdesk/issues) to report problems. Pull requests are welcome!
