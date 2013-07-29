# A sample Guardfile
# More info at https://github.com/guard/guard#readme

guard 'compass' do
  watch(%r{sass/(.*).scss})
end


guard 'livereload', :latency => '0.3', :host => '127.0.0.1', :api_version => '2.0.9', :port => '35729', :apply_css_live => true  do
  watch(%r{.+\.css})
  watch(%r{.+\.html})
end

