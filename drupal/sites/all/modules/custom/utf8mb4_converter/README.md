# utf8mb4_converter

This is a Drupal utility module to convert MySQL table COLS from UTF8 to UTF8MB4.

The module will list of the current tables in the database and will highlight COLS that need to be converted in GREEN. 

* COLS that are varchar with size less than 191 will simply be converted to mb4 and their column-length will be unchanged.
* COLS that are varchar with size greater than 191 and are NOT primary keys will be converted and their column-length will be unchanged.
* COLS that are varchar with size greater than 191 that are primary keys will be highlighted for conversion in green if there are no data row values for that column that are greater than 191 characters in length. 
* COLS that are varchar with size greater than 191 that are primary keys and have row values with lengths greater than 191 characters are highlighted in RED and prevent the "convert all" link from appearing. Resolve those by hand and refresh the page to convert all.

In other words, if no data will be lost by truncation, that is the preferred method. Where data will be lost, the row appears in RED and you should resolve by hand.

#BACKUP YOUR DB FIRST AS YOU ARE WORKING WITHOUT A NET

#Supporting

Included with this module is a few "supporting" files. A _.patch_ that allows core to specify `COLLATION` and `CHARSET` vars in the database settings in settings.php.

```PHP

$database = [
  'default' => [
    'default' => [
      'driver' => 'mysql',
      'database' => 'databasename',
      'username' => 'username',
      'password' => 'password',
      'host' => 'localhost',
      'port' => 3306,
      'prefix' => 'myprefix_',
      'collation' => 'utf8mb4_general_ci',
      'charset' => 'utf8mb4'
    ]
  ]
];


```


There are also requisite my.cnf changes that need to be made to your mysql process:

```
[client]
default-character-set = utf8mb4

[mysql]
max_allowed_packet = 128M
default-character-set = utf8mb4
character-set-connection = utf8mb4
character-set-results = utf8mb4

[mysqld]
character-set-client-handshake = FALSE
character-set-server = utf8mb4

collation-server = utf8mb4_unicode_ci

```

as well as the actual settings for settings.php that allows the database to use utf8mb4 in all it's sql calls. Without these three pieces in place, Drupal will not be able to store mb4 values in the database once you have converted the tables.
