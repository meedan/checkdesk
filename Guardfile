
guard 'livereload', :latency => '0.5', :host => '127.0.0.1', :api_version => '2.0.9', :port => '35729', :apply_css_live => true  do
  watch(%r{\.(css)$}) { |m| "drupal/sites/all/themes/checkdesk/assets/#{m[1]}/style.css" }
  watch(%r{\.(php|js)$})
end

guard 'uglify', :input => 'drupal/sites/all/modules/meedan/meedan_iframes/js/meedan_iframes.parent.js', :output => 'drupal/sites/all/modules/meedan/meedan_iframes/js/meedan_iframes.parent.min.js' do
  watch 'drupal/sites/all/modules/meedan/meedan_iframes/js/meedan_iframes.parent.js'
end

guard :compass, configuration_file: 'config.rb', compile_on_start: true do
  watch(%r{.scss$})
end