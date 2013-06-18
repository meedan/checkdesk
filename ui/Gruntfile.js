module.exports = function(grunt) {

  grunt.loadNpmTasks('grunt-contrib-concat');
  grunt.loadNpmTasks('grunt-contrib-jshint');
  grunt.loadNpmTasks('grunt-contrib-uglify');
  grunt.loadNpmTasks('grunt-docular');
  grunt.loadNpmTasks('grunt-karma');
  grunt.loadNpmTasks('grunt-ngmin');

  // Project configuration.
  grunt.initConfig({
    pkg: grunt.file.readJSON('package.json'),
    jshint: {
      all: ['Gruntfile.js', 'src/**/*.js', 'test/**/*.js'],
      options: {
        eqeqeq: true,
        globals: {
          angular: true
        }
      }
    },
    concat: {
      options: {
        banner: '/*! <%= pkg.title || pkg.name %> - v<%= pkg.version %> - ' +
                '<%= grunt.template.today("yyyy-mm-dd") %>\n' +
                '<%= pkg.homepage ? " *  " + pkg.homepage + "\\n" : "" %>' +
                ' *  Copyright (c) <%= grunt.template.today("yyyy") %> <%= pkg.author %> | Licensed <%= pkg.license %>\n' +
                ' */\n'
      },
      src: {
        src: [
          'src/app.js',
          'src/app.router.js',
          'src/modules/**/*.js',
          'src/**/*.js'
        ],
        dest: 'build/<%= pkg.name %>.js'
      }
    },
    uglify: {
      options: {
        banner: '/*! <%= pkg.name %> - v<%= pkg.version %> */\n'
      },
      build: {
        src: 'build/<%= pkg.name %>.js',
        dest: 'build/<%= pkg.name %>.min.js'
      }
    },
    docular: {
      groups: [
        {
          groupTitle: 'Checkdesk App',
          groupId: 'app',
          groupIcon: 'icon-ok',
          sections: [
            {
              id: 'cd',
              title: 'cd',
              scripts: ['src'],
              docs: ['src/docs']
            }
          ]
        }
      ],
      showDocularDocs: false,
      showAngularDocs: false
    },
    ngmin: {
      src: {
        src: '<%= concat.src.dest %>',
        dest: '<%= concat.src.dest %>'
      }
    }
  });

  // Load the plugin that provides the "uglify" task.
  grunt.loadNpmTasks('grunt-contrib-uglify');

  // Default task(s).
  // grunt.registerTask('default', ['jshint', 'karma']);
  // grunt.registerTask('build', ['jshint', 'karma', 'concat', 'ngmin', 'uglify']);
  grunt.registerTask('default', ['jshint']);
  grunt.registerTask('build', ['jshint', 'concat', 'uglify']);

  // Note, use 'grunt docular-server' to view the compiled documentation
  grunt.registerTask('docs', ['jshint', 'docular']);

};
