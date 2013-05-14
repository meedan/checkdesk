# Checkdesk User Interface

The AngularJS based user interface for the Checkdesk project.


## Installation and Server Configuration

The checkdesk project uses Drupal as a back-end, see the `drupal` directory in the project root.

The server configuration proxies requests from some paths through to the Drupal back-end. This enables same-domain AJAX requests and gets around AJAX security issues.


**Example configuration for Nginx:**

    #
    # /Applications/MNPP/conf/nginx/sites-available/checkdesk.localhost
    #
    server {
        listen       80;
        server_name  checkdesk.localhost;
        root   /Users/james/Code/Meedan/Checkdesk/drupal;
    
        access_log  /Applications/MNPP/logs/nginx/checkdesk.access.log;
        error_log  /Applications/MNPP/logs/nginx/checkdesk.error.log;
    
        include /Applications/MNPP/conf/nginx/common/drupal;
    }
    server {
        listen       80;
        server_name  angular.checkdesk.localhost;
        root   /Users/james/Code/Meedan/Checkdesk/ui/public;
    
        # misc, modules, sites, themes all contain Drupal static content
        # it is important to proxy these.
        #
        # api and admin are the two paths we really want to proxy.
        location ~ /(misc|modules|sites|themes|api|admin) {
            # Pass to the Drupal site, eg: /Users/james/Code/Meedan/Checkdesk
            proxy_pass  http://checkdesk.localhost;
        }
    
        access_log  /Applications/MNPP/logs/nginx/angular.checkdesk.access.log;
        error_log  /Applications/MNPP/logs/nginx/angular.checkdesk.error.log debug;
    
        include /Applications/MNPP/conf/nginx/common/angular;
    }
    
    
    #
    # /Applications/MNPP/conf/nginx/common/angular
    #
    location = /favicon.ico {
            log_not_found off;
            access_log off;
    }
    
    location = /robots.txt {
            allow all;
            log_not_found off;
            access_log off;
    }
    
    location / {
            try_files $uri @rewrite;
            index  index.html;
    }
    
    location @rewrite {
            # This works for AngularJS as well as Drupal. I don't know
            # how Angular does this with a ?q instead of #!/,
            # it isn't in the docs.
            rewrite ^/(.*)$ /index.html?q=$1;
    }
    
    include /Applications/MNPP/conf/nginx/common/php;
    
    location ~* \.(js|css|png|jpg|jpeg|gif|ico)$ {
            expires max;
            log_not_found off;
    }


## Project layout

    meedan-checkdesk/ui
       |-build                             # Compiled files, eg: checkdesk.js
       |-libs                              # Libraries, eg: angular, jquery
       |-public                            # WWW served documents
       |---css
       |---img
       |---js
       |...libs (../libs)
       |...template (../src/templates)
       |-scripts                           # Scripts, eg: nodejs, bash, python
       |-src                               # The source code for the application
       |---controllers
       |---directives
       |---filters
       |---modules
       |---scss
       |---services
       |---templates
       |-test                              # Testing code, eg: unit tests
       |---unit

