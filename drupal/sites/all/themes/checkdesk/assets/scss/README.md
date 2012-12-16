[![Build Status](https://travis-ci.org/meedan/meedan-checkdesk.png)](https://travis-ci.org/meedan/meedan-checkdesk)


### Checkdesk theme 
#### implementing Bowerbird the Compass Framework

Hello! You have arrived at the Checkdesk theme by Meedan.

This is a client theme of Bowerbird, a parent theme which provides the framework for several helper libraries we're written or customized to create a stock HTML theme that is responsive, fluid and bidirectional.

### Get the Bowerbird Compass Framwework source code
    
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

### Use the source, Luke

Theme developers really super-duper really seriously encouraged to `gem unpack compass susy` and `gem unpack compass susy` and read the source code — especially for these two libraries which implement the framwork we're working in. Read the frameworks/compass and the Susy _grid.scss.

You can unpack them both at once and keep them handy.

     gem unpack susy compass

### Start compiling

Find your config.rb file which contains:

    load "../bowerbird/framework"

And in that directory run:

    compass watch 

(Or use the `guard` command which should be installed if you used the `bundle install` command to get setup.)


### General usage notes

The overall pattern is to compile stylesheets dynamically using a terminal process (or some other long-running compiler with debugging output) which is triggered by a file save. 

- First compile the stylesheets: `cd sites/all/themes/checkdesk && compass watch`
- /assets/scss/ renders into /assets/css/.
- The Compass configuration file is in config.rb, which is in sites/all/themes/checkdesk
- The primary stylesheet is style.scss.
- Like all CSS the order of the import statements is important for managing which libraries overrule others.
- use _base.scss for core configuration.
- Everything is commented, please annotate and cleanup comments constantly.
- All stylesheets that start with an underscore are partials, they might contain mixins or complete modules, but they will *not be rendered as .css files* and can not be used to emit styles to the application.
- Try to avoid dupilcation with mixins and configuration variables, but try to reduce complication.
- Best served with Guard and Livereload

### Checkdesk theme cheat sheet

This is a list of the most frequent directives, rules, configs, and everything, with brief explanations. When in doubt, consult the mixin definition. 

##### Sass Directives
    @function twelveth-of($width) { @return $width / 12; } 
      #=> function defined and will be executed when called by client Sass at compile time
    @include twelveth-of(12) 
      #=> "1"
    @debug sixth-of(12) #=> path/to/current/file/_name.scss 
      #=> DEBUG: 2
    @warn "#{fifth-of(12)} columns breaks a #{$cw}-part grid." 
      #=> path/to/current/file/_name.scss WARN: 2.4 columns breaks a 24-part grid.

##### Compass utility includes
    @include single-box-shadow(darken($light-grey, 40%)); 
      #=> "#333333"
      # there are lots [more]("http://compass-style.org/index/functions/") 

##### Susy includes
    @include span-columns(12, $cw); 
      #=> span 50% of the total, if $cw is 24. Eg: "it's 12 in 24"
    @include span-columns($center-column-width, $cw, $gw); 
      #=> 12 in 24 but each has gutter width padding
    @include at-breakpoint(12) { div.green {border: 1px soild red;}} 
      #=> Eg. "above the 12 (default) columns breakpoint"
    @include squish(twelveth-of($cw),twelveth-of($cw),$cw); 
      #=> add padding on each side. Be sure to compensate for the children's new $context width.

##### Checkdesk and Bowerbird mixins
- with namespaced includes
    @include bowerbird-backgrounds("cream_dust"); 
    # This is also an example of custom SassScript helper (in config.rb)

##### Sass (.scss dialect using braces and semicolons)

- nested selectors are the basic feature of sass
    .grandpa { .pa { .child { border: 1px solid $shocking-purple; } } }

- we use :before content from CSS with no modifications because Sass is CSS compatible.
    .pa &:before { content: "Hello!" }

- basic variables
    padding: { top: 17px; bottom: $gw; }

- dynamic-ish variables
    margin-top: $gw * 6;

##### CSS (which is often identical to .scss)

- webfonts from google 
  @import url("http://fonts.googleapis.com/css?family=Open+Sans:400italic,400,700,300");
  # (actually a typical CSS import, not a Sass @ directive, and is not Sass-script at all.)

## Four types of Sass libraries used in Checkdesk

A large part of the rationale for the design of this project is to juggle different kinds of Sass.

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


### This project uses as modular scale for some measurments

use the `ms()` function to get steps (in px) along the scale from -4 to about 18.

To see the list of ms scales ... 

    @for $i from -4 through 10 {
    @debug "available as ms(#{$i}) -> #{ms($i)}";
    }

    Based on the following scale of units: 
    When possible units should appear exactly as they apper
    Usually they can be rounded 
    The key values are 18 and 1168
    0.86 -> "harmonic" but missing from ms
    1.39 -> "harmonic" but missing from ms
    2.24 -> "harmonic" but missing from ms
    2.63 -> available as ms(-4) -> 3px
    3.63 -> available as ms(-3) -> 4px
    4.25 -> "harmonic" but missing from ms
    5.87 -> "harmonic" but missing from ms
    6.88 -> available as ms(-2) -> 7px
    9.5 -> "harmonic" but missing from ms
    11.12 -> available as ms(-1) -> 11px -> used in $small->font->size and $gutter->width or $gw
    15.36 -> navigation font size
    18 -> available as ms(0) -> 18px -> $based font size 1 : 0.61803
    24.86 -> available as ms(1) -> 25px
    29.12 -> available as ms(2) ->. 29px
    40.23 -> available as ms(3) -> 40px
    47.12 -> available as ms(4) -> 47px
    65.09 -> available as ms(5) -> 65px -> width of space between primary and secondary columns
    76.25 -> available as ms(6) -> 76px
    105.32 -> available as ms(7) -> 105px
    123.37 -> available as ms(8) -> 123px
    170.4 -> available as ms(9) -> 170px
    199.62 -> available as ms(10) -> 200px
    275.72 -> available as ms(11) -> dropdown login form width
    322.99 -> available as ms(12) -> sidebar width
    446.13 -> available as ms(13)
    522.61-> available as ms(14)
    721.86-> available as ms(15)
    845.6 -> available as ms(16) -> main column width
    1168 -> available as ms(17) -> total width
    1368.21- available as ms(18)
    2213.8- available as ms(19)

