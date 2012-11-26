require "susy" # how to require this in bowerbird?
load "sites/all/themes/bowerbird/framework"

# Set this to the root of your project when deployed:
http_path = "/"
css_dir 				= "sites/all/themes/checkdesk/assets/css"
sass_dir 				= "sites/all/themes/checkdesk/assets/scss"
images_dir 			= "sites/all/themes/checkdesk/assets/img"
javascripts_dir = "sites/all/themes/checkdesk/assets/js"
font_dir 				= "sites/all/themes/checkdesk/assets/fonts"

http_fonts_path = "/sites/all/themes/checkdesk/assets/fonts"
relative_assets = false


# Add array randomization support to ruby
class Array
  def randomize
    arr=self.dup
    self.collect { arr.slice!(rand(arr.length)) }
  end
  def random
    self.randomize.first
  end
end

# Bowerbird custom SassScript Functions
module Sass::Script::Functions
  
  module Bowerbird
    def random_color
      color = ["#FF628C", "#3AD900", "#0088FF", "#80FFC2", "#FFDD00", "#FF9D00"].random
      Sass::Script::String.new(color);
    end
  end

  include Bowerbird
end