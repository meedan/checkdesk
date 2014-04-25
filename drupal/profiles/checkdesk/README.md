# Installation using drush site-install
Run the following commands from the Checkdesk `/drupal` folder to install the Checkdesk installation profile using drush:

		> drush si checkdesk [installation-parameters]`
		> drush fra -y

# Installation parameters

		; database configuration
		--db-url=mysql://[username]:[password]@[host]/[database]      Database configuration  

		; site configuration
		--site-name                                                   Site name (en)
		--account-mail                                                Admin email
		--account-name                                                Admin username
		--account-pass                                                Admin password

		; checkdesk configuration
		cd_configuration_form.site_name_ar                            Site name (ar)
		cd_configuration_form.site_slogan                             Site slogan (en)
		cd_configuration_form.site_slogan_ar                          Site slogan (ar)
		cd_configuration_form.checkdesk_site_owner                    Site owner (en)
		cd_configuration_form.checkdesk_site_owner_ar                 Site owner (ar)
		cd_configuration_form.checkdesk_site_owner_url                Site owner URL

		; web services configuration
		cd_apps_form.oembedembedly_api_key                            Embedly API Key
		cd_apps_form.twitter_consumer_key                             Twitter Key
		cd_apps_form.twitter_consumer_secret                          Twitter Secret
		cd_apps_form.fboauth_secret                                   Facebook Secret
		cd_apps_form.fboauth_id                                       Facebook ID
