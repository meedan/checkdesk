### Checkdesk Sass

[Compass](http://compass-style.org) and [Susy]("http://susy.oddbird.net") are ruby gems you must install before you can compile your stylesheets:

    gem install compass
    gem install susy 

or if you use [Bundler]("http://gembundler.com/") you can just do:

    bundle install

Theme developers should `gem unpack compass susy` and `gem unpack compass susy` and read the source code — especially for these two libraries which implement the framwork we're working in. Read the frameworks/compass and the Susy _grid.scss.

You can unpack them both at once and keep them handy.

     gem unpack susy compass

This will give you copies of the Sass files stored inside the stylesheet gems.

### Start compiling

At the project root, run the Sass compiler:

    compass watch 

(Alternatively, use the `guard` command which should be installed if you used the `bundle install` command to get setup.)

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
