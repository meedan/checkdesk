### Checkdesk theme implementing Bowerbird the Compass Framework (BCF)

Hello! You have arrived at the Checkdesk theme by Meedan.

This is a client theme of Bowerbird, a parent theme which provides the framework for several helper libraries we're written or customized to create a stock HTML theme that is responsive, fluid and bidirectional.

### Get the Compass framwework loaded 
    
    git submodule update --init

Our parent theme Bowerbird is a Drupal nest with a single giant Compass framework egg. Note that you don't need to use Drupal to use the Bowerbird Sass framework (or the Checkdesk "client" Sass).

As explained on the Compass site: "The Compass core framework is a design-agnostic framework that provides common code that would otherwise be duplicated across other frameworks and extensions."

The Bowerbird framework follows Sass conventions from Compass and Susy.

## Bowerbird is a Sass library managed by Compass.

[Compass](http://compass-style.org) and [Susy]("http://susy.oddbird.net") are ruby gems you must install before you can compile your stylesheets:

    gem install compass
    gem install susy 

or if you use [Bundler]("http://gembundler.com/") you can just do:

    bundle install

Once you get compass and susy gems installed, you can ...

### Read the libraries we are utilizing

You are really super-duper really seriously encouraged to `gem unpack compass susy` and `gem unpack compass susy` and read the source code — especially for these two libraries which implement the framwork we're working in. Read the frameworks/compass and the Susy _grid.scss.

You do unpack them both at once:

     gem unpack susy compass

### Bowerbird packages Twitter Bootstrap and other libraries

- We use the compass_twitter_bootstrap gem to provide access to Compass-compatible Twitter Bootstrap modules which are packaged in a way that is designed to be overridden and selectively included. This allows us to mix in other libraries and maintain velocity without regression bugs. Various snapshots of our themes will have various configurations of which Bootstrap modules are supported, and we will be forking/modifying them rapidly. 
- Susy layout integration: We make responsive, fluid, bidirectional grids and Susy handles all the math.
- Bidirectional layouts: all mixins are bidirectional using $from-direction and opposite-position($from-direction);
- A unfied Sass method for multiple icon libraries like Fontawesome.
- Customized fork of fancy-buttons plugin .
- Guard preconfigured with Livereload (so you don't have to refresh the page).

#### Differences from Twitter Bootstrap
- the main difference is that we don't require the use of nonsemantic class names in the markup. That is, you don't have to create classes like ".span-12" or ".icon-thumb." All of those classes are still supported but their use is deprecated in favor of [@extend]("http://sass-lang.com/docs/yardoc/file.SASS_REFERENCE.html#extend") or repackaging as native Compass or Sass functions. (You can still use nonsemantic classes if you want.)
- There is some delay in the port from the original .less. 
- Compass-ported mixins are all indicated with a "ctb-" prefix.
- TB grid variables are all overridden or replaces by Susy fluid grid.
- Improved button support as a mixin.
- Improved icon handling with helper mixins.

### Strong cross-browser support and documentation
- *WIP* We want to have module-level validation of our CSS for each browser.

### Standardized CSS syntax with KSS
- *WIP* https://github.com/kneath/kss/blob/master/SPEC.md

### Proportion-based grid
- Checkdesk uses a proportion-based grid which adapts to many sizes and configurations. We use Susy for the Math.

### Responsive
- Checkdesk uses Susy's at-breakpoint(); mixin, which we use to configure layouts and typography for a given viewport width.

### Usage notes

- The Compass configuration file is in config.rb, which is in sites/all/themes/checkdesk
- First compile the stylesheets: `cd sites/all/themes/checkdesk && compass watch`
- /assets/scss/ renders into /assets/css/.
- The primary stylesheet is style.scss, think from there.
- The order of the import statements is very important.
- use _base.scss for core configuration.
- Everything is commented, please annotate and cleanup comments constantly.
- All stylesheets that start with an underscore are partials, they might contain mixins or complete modules, but they will *not be rendered as .css files* and can not be used to emit styles to the application.
- Try to avoid dupilcation with mixins and configuration variables, but try to reduce complication.

#### Special points about the layout 

- The Susy way is: every CSS width is a percentage, but every Sass width is a column (or a ratio of columns). 
- `gem unpack susy` and keep the source code at hand while working, especially layout.scss.
- learn to love display: inline.
- There should only be one container element.
- At least once, do the layout math by hand to verify it.
- Make good use of the @debug and @warn function on sensitive layout configuration

## Four types of Sass libraries used in Checkdesk

- First, custom Sass files created by Meedan. These live in ./scss/. For example: 
      
      @import "navigation" => renders ./_navigation.scss

- Then, customizations of Twitter Bootstrap which live in ./scss/override_ctb. To use them, use an @import statement. For example:

      @import "override_ctb/alerts" => compiles into ./alerts.scss into your stylesheet

- Also, libraries which are stored in Bowerbird framework: 

      @import "bowerbird/";
      // Note the bowerbird framework must be loaded in your config.rb like this: 
      load "sites/all/themes/bowerbird/framework"

- Lastly, libraries which are stored on the development machine as gems: 

      @import "susy";
      // Note this must also be required in your config.rb
      require "susy"
      // Additionally it must be installed with rubygems or bundler.
      `gem install susy`

Therefore Some @imports will @import Sass directly and some will @import mixins you can then @include with parameters.