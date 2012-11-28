### Checkdesk theme implementing Bowerbird the Compass Framework (BCF)

Hello! 

Bowerbird provides the framework for several helper libraries we're written or customized somehow.

Bowerbird is a Sass library managed by Compass.

More importantly, Compass and Susy are ruby gems you must install before you can run "compass watch". 

    gem install compass
    gem install susy 

or if you use Bundler:

    bundle install

Once you get compass and susy gems installed, you can ...

### Read the source

You are really super-duper seriously encouraged to `gem unpack compass susy` and `gem unpack compass susy` and read the source code — especially for these two libraries which implement the framwork we're working in. Read the frameworks/compass and the Susy _grid.scss before you go to bed tonigh.

## Why do people use this? 

### Full access to (almost the latest version of) Twitter Bootstrap and other libraries

- Uses the compass_twitter_bootstrap gem to provide full access to (almost the latest version of) Twitter Bootstrap modules. There is some delay in the port from the original Less, but it is fully compatible with the .js and compass. There are no namespace collisions among the mixins because they are all prefixed with "ctb-", which has the added benefit of making the original mixins easy to spot.
- Susy layout integration
- a unfied Sass method for multiple icon libraries like fontawesome and foundicons.
- Customized fork of Fancy-buttons for superb buttons.

- Debugging support tools like sparkle_bomb();
- Guard preconfigured with Livereload (so you don't have to refresh the page).

### Amazing cross-browser support and documentation
#TODO

### Proportion-based grid

Checkdesk uses a proportion-based grid which adapts to many sizes and configurations. Susy is a great tool for this.

### Media queries

Checkdesk loves Susy's at-breakpoint(); mixin, which we use to configure layouts and typography for a given viewport width.

### Usage

There are vendored libraries (which would usually be used as gems), notably we are using a vendored version of compass_twitter_bootstrap.

Included in this library:

    - There are some custom Sass files created by Meedan. These live in ./scss/. There are also our customizations (Susy+Sassification?) of Twitter Bootstrap which live in ./scss/override_ctb. To use them, use an @import statement and run the `compass watch` compiler.
      - @import "override_ctb/alerts" => renders alerts.scss into your stylesheet
      - @import "bowerbird/drupal" => renders _drupal.scss
    - Some @imports will @import Sass directly and some will @import mixins you can then @include with parameters. For more 