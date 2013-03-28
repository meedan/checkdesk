require "susy" # how to require this in bowerbird?
require "logger" # custom logger with pass/fail
require "pry" # ruby REPL debugger mode
require "rake" # for filelist
require "modular-scale" #for ratios
# require "animation" # experimental https://github.com/ericam/compass-animate

line_comments = false

drupal_dir = "drupal"
themes_dir = "sites/all/themes/"
extensions_dir = "checkdesk/assets/extensions/"
bowerbird_extension_dir = "bowerbird/"
full_bowerbird_extension_dir = File.join(drupal_dir, themes_dir, extensions_dir, bowerbird_extension_dir)

assets_dir = "checkdesk/assets"
full_assets_dir = File.join(drupal_dir, themes_dir, assets_dir)
http_path       = "/"
css_dir         = File.join(full_assets_dir, "css")
sass_dir        = File.join(full_assets_dir, "scss")
images_dir      = File.join(full_assets_dir, "imgs")
javascripts_dir = File.join(full_assets_dir, "js")

bb_background_path = "sites/all/themes/bowerbird/images/bkgs/"

# icon webfonts from bowerbird
fonts_dir = File.join("fonts")
http_fonts_path = File.join(http_path, themes_dir, extensions_dir, bowerbird_extension_dir, "fonts")
relative_assets = false

#load bowerbird
Sass.load_paths << File.join(full_bowerbird_extension_dir, "stylesheets")

# For more about Sass functions: 
# http://sass-lang.com/docs/yardoc/Sass/Script/Functions.html
module Sass::Script::Functions
  
  def pry
    binding.pry
  end

  def bb_random_color
    colors = ["#FF628C", "#3AD900", "#0088FF", "#80FFC2", "#FFDD00", "#FF9D00"]
    arr = colors.dup    
    Sass::Script::String.new(colors.collect { arr.slice!(rand(arr.length)) }.first);
  end
end

output_style = (environment == :production) ? :compressed : :expanded
# sass_options = (environment == :production) ? { :debug_info => false } : { :debug_info => true } 
