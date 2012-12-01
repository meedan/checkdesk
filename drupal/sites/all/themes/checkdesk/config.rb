require "susy" # how to require this in bowerbird?
require "logger" # custom logger with pass/fail
require "pry"
require "rake" # for filelist

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


# For more about Sass functions: 
# http://sass-lang.com/docs/yardoc/Sass/Script/Functions.html
module Sass::Script::Functions
  def random_color
    colors = ["#FF628C", "#3AD900", "#0088FF", "#80FFC2", "#FFDD00", "#FF9D00"]
    arr = colors.dup    
    Sass::Script::String.new(colors.collect { arr.slice!(rand(arr.length)) }.first);
  end
  
  def show_available_backgrounds(path)
    Dir.glob(path);
  end
  
  @bkgpath = "assets/imgs/bkgs/"
  def all_backgrounds(bkgpath = @bkgpath, size = "default")
    @list = Array.new
    puts "about to go"
    FileList["#{bkgpath}**/*.png"].exclude(/.*2X.*/).each { |pathname| 
      puts pathname
      puts Sass::Script::String.new((File.basename(pathname)).gsub(".png", ""))
      @list << Sass::Script::String.new((File.basename(pathname)).gsub(".png", ""))
    }
    Sass::Script::List.new(@list, :comma)
  end

  def all_backgrounds_count
    # binding.pry
    Sass::Script::Number.new(all_backgrounds(@bkgpath).value.length.to_i)
  end
end