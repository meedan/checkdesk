Encoding.default_external = "utf-8"
require "compass_twitter_bootstrap"

line_comments = false

drupal_dir = "drupal"
themes_dir = "sites/all/themes/"
assets_dir = "checkdesk/assets"
full_assets_dir = File.join(drupal_dir, themes_dir, assets_dir)
http_path = "/"
css_dir = File.join(full_assets_dir, "css")
sass_dir = File.join(full_assets_dir, "scss")
images_dir = File.join(full_assets_dir, "imgs")
javascripts_dir = File.join(full_assets_dir, "js")

# icon webfonts from bowerbird
fonts_dir = File.join(full_assets_dir, "scss/bowerbird/fonts")
http_fonts_path = File.join(http_path, themes_dir, assets_dir, "scss/bowerbird/fonts")
relative_assets = false

# puts fonts_dir
# puts http_fonts_path

# Add bower components to our path
add_import_path "drupal/sites/all/themes/checkdesk/assets/bower_components/susy/sass"
add_import_path "drupal/sites/all/themes/checkdesk/assets/bower_components/modular-scale/stylesheets"

output_style = (environment == :production) ? :compressed : :expanded