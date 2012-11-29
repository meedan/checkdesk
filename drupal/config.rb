require "susy" # how to require this in bowerbird?

load "sites/all/themes/bowerbird/framework"
debug_info = 
# Set this to the root of your project when deployed:
http_path = "/"
css_dir 				= "sites/all/themes/checkdesk/assets/css"
sass_dir 				= "sites/all/themes/checkdesk/assets/scss"
images_dir 			= "sites/all/themes/checkdesk/assets/img"
javascripts_dir = "sites/all/themes/checkdesk/assets/js"

# icon webfonts from bowerbird (by contrast typography fonts are from google)
font_dir 				= "/sites/all/themes/bowerbird/framework/fonts"
http_fonts_path = "/sites/all/themes/bowerbird/framework/fonts"
relative_assets = false

# module Sass::Script::Functions
#   def reverse(string)
#     assert_type string, :String
#     Sass::Script::String.new(string.value.reverse)
#   end

#   def random_color
#     colors = ["#FF628C", "#3AD900", "#0088FF", "#80FFC2", "#FFDD00", "#FF9D00"]
#     arr = colors.dup
    
#     Sass::Script::String.new(colors.collect { arr.slice!(rand(arr.length)) }.first);
#   end
# end