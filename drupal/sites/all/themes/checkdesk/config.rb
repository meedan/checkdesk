require "susy" # how to require this in bowerbird?
require "logger" # custom logger with pass/fail
load "../bowerbird/framework" # is this the right way to do this?

# Set this to the root of your project when deployed:
http_path = "/"
css_dir 				= "assets/css"
sass_dir 				= "assets/scss"
images_dir 			= "assets/img"
javascripts_dir = "assets/js"

# icon webfonts from bowerbird (by contrast typography fonts are from google)
font_dir 				= ".../bowerbird/framework/fonts"
http_fonts_path = "/sites/all/themes/bowerbird/framework/fonts"
relative_assets = false

module Sass::Script::Functions
  def random_color
    colors = ["#FF628C", "#3AD900", "#0088FF", "#80FFC2", "#FFDD00", "#FF9D00"]
    arr = colors.dup    
    Sass::Script::String.new(colors.collect { arr.slice!(rand(arr.length)) }.first);
  end
end