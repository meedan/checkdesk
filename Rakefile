annotated_stylesheets = "drupal/sites/all/themes/checkdesk/assets/scss/"
project_name = "Checkdesk"

task :default => [:compile]

desc "Compile stylesheets"
task :compile do
  system "compass compile"
end

desc "Render docs directory"
task :docs do
  puts "Going to build docs from #{annotated_stylesheets} "
  system "styledocco -n '#{project_name} docs' --preprocessor 'sass --compass' #{annotated_stylesheets} && echo '=============' && ls docs/*" 
end