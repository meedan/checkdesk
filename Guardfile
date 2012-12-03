notification :growl

guard 'compass' do
  watch(%r{^drupal/sites/all/themes/checkdesk/assets/scss.+\.(scss)$})
  watch(%r{^drupal/sites/all/themes/bowerbird/.+\.(scss)$})
end

guard 'livereload', :host => '127.0.0.1', :api_version => '2.0.8', :port => '35729' do
  watch(%r{drupal/sites/all/themes/checkdesk/assets/scss.+\.(scss|php|js)$})
end 