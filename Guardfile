
guard 'livereload', :latency => '0.5', :host => '127.0.0.1', :api_version => '2.0.9', :port => '35729', :apply_css_live => true  do
  watch(%r{\.(css)$}) { |m| "drupal/sites/all/themes/checkdesk/assets/#{m[1]}/style.css" }
  watch(%r{\.(php|js)$})
end

guard 'uglify', :input => 'drupal/sites/all/modules/meedan/meedan_iframes/js/meedan_iframes.parent.js', :output => 'drupal/sites/all/modules/meedan/meedan_iframes/js/meedan_iframes.parent.min.js' do
  watch 'drupal/sites/all/modules/meedan/meedan_iframes/js/meedan_iframes.parent.js'
end

guard 'livereload' do
  watch(%r{app/views/.+\.(erb|haml|slim)$})
  watch(%r{app/helpers/.+\.rb})
  watch(%r{public/.+\.(css|js|html)})
  watch(%r{config/locales/.+\.yml})
  # Rails Assets Pipeline
  watch(%r{(app|vendor)(/assets/\w+/(.+\.(css|js|html|png|jpg))).*}) { |m| "/assets/#{m[3]}" }
end

guard 'sass', :input => 'sass', :output => 'css', :compass => {
  :images_dir       => "imgs",
  :images_path      => File.join(Dir.pwd, "drupal/sites/all/themes/checkdesk/assets/"),
  :http_images_path => "/sites/all/themes/checkdesk/assets/",
  :http_images_dir  => "/imgs",
  :http_fonts_path  => "/assets",
  :http_fonts_dir   => "/fonts"
}
