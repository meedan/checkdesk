### Ensure the encoding
# 
Encoding.default_external = "utf-8"

require "susy"
require "modular-scale"

http_path = "/"
css_dir = "css"
sass_dir = "sass"
images_dir = "img"
javascripts_dir = "js"
line_comments = false

### Twitter Bower 
# 
# For Sass libraries without all the ruby
# Also not installed in the public assets dir, but rather above it.
bower_path = "bower_components"

# Load our bower path in compass so we can do @import statements
add_import_path bower_path

### Output style
# 
# Configure this with the command line during the build/test routine
# Assumes develop mode unless you declare otherwise
# 
relative_assets = false

# You can select your preferred output style here (can be overridden via the command line):
#
# output_style = :expanded or :nested or :compact or :compressed
#
if environment != :production
  output_style = :expanded
  line_comments = false
  disable_warnings = false
  sass_options = { :quiet => true }
end

if environment == :production 
  output_style = :compressed
  line_comments = false
  disable_warnings = true
  sass_options = { :quiet => true }
end
