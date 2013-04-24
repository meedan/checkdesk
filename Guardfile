
guard 'livereload', :latency => '0.5', :host => '127.0.0.1', :api_version => '2.0.9', :port => '35729', :apply_css_live => true  do
  # this is a bit overspecified but without the specific filename I can't get it to properly live reload without a full refresh
  watch(%r{\.(css)$}) { |m| "/sites/all/themes/checkdesk/assets/#{m[1]}/style.css" }
  watch(%r{\.(php|js)$})

end

guard 'compass' do
  watch(%r{^drupal/sites/all/themes/checkdesk/assets/scss/.+\.(scss)$})
  watch(%r{^drupal/sites/all/themes/checkdesk/assets/extensions/bowerbird/stylesheets/.+\.(scss)$})
end

guard 'uglify', :input => 'drupal/sites/all/modules/meedan/meedan_iframes/js/meedan_iframes.parent.js', :output => 'drupal/sites/all/modules/meedan/meedan_iframes/js/meedan_iframes.parent.min.js' do
  watch 'drupal/sites/all/modules/meedan/meedan_iframes/js/meedan_iframes.parent.js'
end
