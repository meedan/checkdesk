# Checkdesk User Interface

The AngularJS based user interface for the Checkdesk project.


## Set up

### Building the project

1. Get the project dependencies, you will need node.js and npm. Use [Homebrew](http://mxcl.github.io/homebrew/), [Macports](http://www.macports.org/), [Apt](https://help.ubuntu.com/community/AptGet/Howto) or similar to retrieve these.
2. If you haven't already, install grunt globally via `sudo npm -g install grunt`.
3. Install required npm dependencies by running `npm install` in the project root.
4. Build the code by running `grunt build`.
5. You should now have a fresh copy of `build/checkdesk.js`.


### Project documentation

Build fresh documentation with `grunt ngdocs` View the documentation in `docs/public`.


### Server Configuration

The checkdesk project uses Drupal as a back-end, see the 'drupal' directory in the project root.

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
        root   /Users/james/Code/Meedan/Checkdesk/ng-ui/public;
    
        # misc, modules, sites, themes all contain Drupal static content
        # it is important to proxy these.
        #
        # api and admin are the two paths we really want to proxy.
        location ~ /(misc|modules|sites|themes|services|api|admin) {
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

**Example configuration for Apache:**

    RewriteEngine On

    # You MUST have mod_proxy and mod_proxy_http for this to work, else you
    # will get a 404
    RewriteCond %{REQUEST_URI} ^/(misc|modules|sites|themes|services|api|admin)
    RewriteRule ^(.*)$ http://checkdesk.local/$1 [L,P]

    RewriteCond %{REQUEST_FILENAME} !-f
    RewriteCond %{REQUEST_FILENAME} !-d
    RewriteCond %{REQUEST_URI} !=/favicon.ico
    RewriteRule ^(.*)$ index.html?q=$1 [L]


## Project layout

    meedan-checkdesk/ng-ui
       |-build                             # Compiled files, eg: checkdesk.js
       |-docs                              # Project documentation
       |-docs/public                       # Browseable documentation
       |-libs                              # Libraries, eg: angular, jquery
       |-public                            # WWW served documents
       |---css
       |---img
       |---js
       |...libs (../libs)
       |...template (../src/templates)
       |-scripts                           # Scripts, eg: nodejs, bash, python
       |-snapshots                         # Static site snapshots
       |-src                               # The source code for the application
       |---controllers
       |---modules
       |---scss
       |---templates
       |-test                              # Testing code, eg: unit tests
       |---unit


## Snapshotting For Robots

Accommodating search engine spiders and other robots can be tricky for sites with a Javascript heavy front-end. For this reason static snapshots of the site are captured at intervals.

When a robot is detected (eg: Nginx, Varnish) the request is rewritten to serve the snapshot rather than the dynamic page.



### PhantomJS Snapshot Script

    Sript: scripts/phantomjs-snapshot.js

PhantomJS is used to capture the static site snapshots.

It is important to ensure the page has fully loaded before each snapshot is taken. A special  `<body data-status="ready">` flag is used to inform the PhantomJS script when the snapshot can be taken. The PhantomJS script polls every few milliseconds waiting for this flag to be set.

It is important that each new site page take this special flag into account. It can easily be set using the PageState service.
