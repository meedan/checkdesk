# Bowerbird Compass Framework
## Manged with a Drupal theme of the same name

#### Bowerbird Compass Sass Framework

Uses the [Susy]("http://susy.oddbird.net") grid framework, [FontAwesome]("http://fortawesome.github.com/Font-Awesome") webfont icons, Twitter bootstrap (via the [compass_twitter_bootstrap]("https://github.com/vwall/compass-twitter-bootstrap") gem, [fancy-buttons]("#") by imathis, as well as some helpful support for often neglected things like colors.

  - Compass Twitter Bootstrap gem, an implementation of Twitter Bootstrap
  - Meedan original Sass modules
    - Our favorite Drupal CSS patches
    - Our colors and preestablished pallets
    - Our version of Drupal tabs 
  - Meedan forks of established Sass modules
    - gradients from fancy-gradients
    - buttons from fancy-buttons
  - Webfont Icon families
    - fontawesome
    - foundicons
    - Bowerbird handler for multiple types of webfont families

## Usage ... 

1. In your sub-theme's config.rb file include a line like this:

         load '../bowerbird/framework'

2. In your sub-theme's SCSS file utilize the framework like this:

         @import "bowerbird";
         @import "bowerbird/filename";

         // Then in your Sass
         @include mixin-name(red);

### Compass Twitter Bootstrap 

We are using very recent custom build of the gem version "2.2.0.36624333"

All of the mixins are scoped with "ctb-" to prevent namespace collisions with other frameworks like the compass mixins.

## Regarding webfont icons

One useful aspect of Bowerbird is the font-icon handling, which can help you to render many webfont-based icons. You can selectively disable the inclusion of fonts to optimize as you grow. 

### Developer support: 
  - There is a Guardfile configured for compiling stylesheets with compass and livereload
  - There is ansible-playbook-based environment setup
  - Debug mixins

### Dependencies:
  - Compass
  - Sass
  - Susy

### For implementation details see Checkdesk 