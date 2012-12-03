require "susy" # how to require this in bowerbird?
require "logger" # custom logger with pass/fail
require "pry"
require "rake" # for filelist

drupal_dir = "drupal"
themes_dir = File.join(drupal_dir,"sites/all/themes/")
extensions_dir = File.join(themes_dir, "bowerbird/extensions/")
bowerbird_extension_dir = File.join(extensions_dir,"bowerbird/")
assets_dir = File.join(themes_dir, "checkdesk/assets")

http_path       = "/"
css_dir         = File.join(assets_dir, "css")
sass_dir        = File.join(assets_dir, "scss")
images_dir      = File.join(assets_dir, "img")
javascripts_dir = File.join(assets_dir, "js")

# icon webfonts from bowerbird
http_fonts_path = File.join(bowerbird_extension_dir, "fonts")
relative_assets = false

#load bowerbird
Sass.load_paths << File.join(themes_dir, bowerbird_extension_dir)

# For more about Sass functions: 
# http://sass-lang.com/docs/yardoc/Sass/Script/Functions.html
module Sass::Script::Functions
  def random_color
    colors = ["#FF628C", "#3AD900", "#0088FF", "#80FFC2", "#FFDD00", "#FF9D00"]
    arr = colors.dup    
    Sass::Script::String.new(colors.collect { arr.slice!(rand(arr.length)) }.first);
  end

  @bkgpath = File.join(File.dirname(__FILE__), 'drupal/sites/all/themes/', 'checkdesk/assets/bkgs')
  def all_backgrounds(bkgpath = @bkgpath, size = "default")
    @list = Array.new
    FileList["#{bkgpath}**/*.png"].exclude(/.*2X.*/).each { |pathname| 
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