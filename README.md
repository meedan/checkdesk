Checkdesk is a multilingual custom CMS tailored for the verification and liveblogging of social media. It is built upon the [Drupal 7](http://drupal.org) PHP content management platform. Technically speaking, Checkdesk is a [Drupal distribution](https://drupal.org/documentation/build/distributions).

# Application model
Checkdesk allows *citizen journalists* to submit social media links for *verification*. The purpose of verification is to check the veracity of the information presented by the media item. On Checkdesk, verification is a social activity that is carried out by the users. 

A new media link becomes a *report* around which the verification activity is conducted. A *professional journalist* is notified of the submission of a new report, and upon examination, can decide to publish it in an *update* to one of the running *stories* on the site. 

The community of users can then proceed to add *verification footnotes* to the report, where they discuss the veracity of the information. Users can also *flag* the report for spam, graphic scenes, etc. Journalists can change the *verification status* of the report to such states as "verified", "false", "pending verification", etc.

A published update shows up on the public view of the associated story, which is a *liveblog*. The public landing page is an aggregated liveblog of all running stories.

# Installation
Checkdesk installation is similar to a [standard Drupal installation](https://drupal.org/documentation/install). When the Drupal installer runs, choose the *Checkdesk* installation profile.

During installation, you will be prompted for a few 3rd party keys:

* Twitter, to allow logging in through Twitter
* Facebook, for the same purpose
* [Embedly](http://embed.ly/), which is a web service that renders links into embeddable HTML components using oEmbed.

# Project layout

    meedan-checkdesk/
       |-config                                      # configuration files
       |-drupal                                      # Drupal application root
       |-patches                                     # patches to Drupal core, modules, other components
       |-test                                        # testing files
       |---behat                                     # Behat tests
       |---html                                      # HTML tests
       |-ui                                          # experimental Angular.js front-end
      
# Feedback
Please [submit issues](https://github.com/meedan/meedan-checkdesk/issues) to report problems.
