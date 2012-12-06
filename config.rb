require "susy" # how to require this in bowerbird?
require "logger" # custom logger with pass/fail
require "pry"
require "rake" # for filelist

drupal_dir = "drupal"
themes_dir = "sites/all/themes/"
extensions_dir = "bowerbird/extensions/"
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
http_fonts_path = File.join("/", themes_dir, extensions_dir, bowerbird_extension_dir, "fonts")
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

  # def all_bb_backgrounds(path = bb_background_path, size = "default")
  #   puts "================= Using #{path}"
  #   @list = Array.new
  #   FileList[File.join(path, '**', '*.png')].exclude(/.*2X.*/).each { |pathname| 
  #     @list << Sass::Script::String.new((File.basename(pathname)).gsub(".png", ""))
  #   }
  #   Sass::Script::List.new(@list, :comma)
  # end

  # def all_bb_backgrounds_count(path = bb_background_path)
  #   Sass::Script::Number.new(all_bb_backgrounds(path).length.to_i)
  # end

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