CheckDesk installation profile allow you to install checkdesk in four steps:
 1 - configure site
 2 - checkdesk configuration form
 3 - checkdesk apps configuration [facebook and twitter]
 4 - Import translation for arabic interface.
 
 = How to install checkdesk
 A - visit install.php page and select Meedan Checkdesk then process with above four steps.
 B - using drush site-install

 B = Install checkdesk via drush site-install checkdesk.
B.1 pass configuration to drush site-install
 
;database configuration
--db-url=mysql://[username]:[password]@[host]/[database]      database configuration  

; site configuration
--site-name                                                   site name
--account-mail                                                uid1 mail
--account-name                                                uid1 username
--account-pass                                                uid1 password

; checkdesk configuration
cd_configration_form.site_name_ar                             arabic site name
cd_configration_form.site_slogan                              english slogan
cd_configration_form.site_slogan_ar                           arabic slogan
cd_configration_form.checkdesk_site_owner                     english site owner
cd_configration_form.checkdesk_site_owner_ar                  arabic site owner
cd_configration_form.checkdesk_site_owner_url                 site owner URL

;checkdesk apps configuration
cd_apps_form.twitter_consumer_key                             Twitter Key
cd_apps_form.twitter_consumer_secret                          Twitter Secret
cd_apps_form.fboauth_secret                                   Facebook Secret
cd_apps_form.fboauth_id                                       Facebook ID

B.2 run drush fra -y

DRUSH SITE-INSTALL EXAMPLE
drush site-install checkdesk --db-url=mysql://[username]:[password]@[host]/[database] --site-name=CheckDesk --account-mail=test@example.com --account-name=admin --account-pass=admin cd_configration_form.site_name_ar=ميدان cd_configration_form.checkdesk_site_owner=meedan cd_configration_form.checkdesk_site_owner_ar=ميدان cd_configration_form.checkdesk_site_owner_url=http://meedan.org cd_apps_form.twitter_consumer_key=key cd_apps_form.twitter_consumer_secret=value cd_apps_form.fboauth_secret=value cd_apps_form.fboauth_id=value
