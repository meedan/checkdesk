require "compass_twitter_bootstrap"
require "susy"

line_comments = false

drupal_dir = "drupal"
themes_dir = "sites/all/themes/"
assets_dir = "checkdesk/assets"
full_assets_dir = File.join(drupal_dir, themes_dir, assets_dir)
http_path       = "/"
css_dir         = File.join(full_assets_dir, "css")
sass_dir        = File.join(full_assets_dir, "scss")
bower_dir = File.join(full_assets_dir, "bower_components")
images_dir      = File.join(full_assets_dir, "imgs")
javascripts_dir = File.join(full_assets_dir, "js")

# icon webfonts from bowerbird
fonts_dir = File.join(full_assets_dir, "fonts")
http_fonts_path = File.join(http_path, themes_dir, assets_dir, "fonts")
relative_assets = false

output_style = (environment == :production) ? :compressed : :expanded
# sass_options = (environment == :production) ? { :debug_info => false } : { :debug_info => true } 
