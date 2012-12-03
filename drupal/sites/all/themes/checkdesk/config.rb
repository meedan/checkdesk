require "susy" # how to require this in bowerbird?
require "logger" # custom logger with pass/fail
require "pry"
require "rake" # for filelist

# seems like not an ideal way to load a compass extension
Sass.load_paths << '../bowerbird/extensions/bowerbird/stylesheets'

# Set this to the root of your project when deployed:
http_path       = "/"
css_dir 				= "assets/css"
sass_dir 				= "assets/scss"
images_dir 			= "assets/img"
javascripts_dir = "assets/js"

# environment = :development
# firesass = true

# icon webfonts from bowerbird (by contrast typography fonts are from google)
# font_dir 				= extensions_dir + "fonts"
http_fonts_path = "/sites/all/themes/bowerbird/bowerbird/fonts"
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

  # based on http://www.seancolombo.com/2010/07/28/how-to-make-and-use-a-custom-sass-function/
  # def config_from_cli(c, d="")
  #   o = d.to_s
  #   ARGV.each do |a|
  #     if a =~ /.=./
  #       p = a.split('=')
  #       o = p[1] || d
  #     end
  #   end
  #   begin
  #     Sass::Script::Parser.parse(o, 0, 0)
  #   rescue
  #     Sass::Script::String.new(o)
  #   end
  # end
end