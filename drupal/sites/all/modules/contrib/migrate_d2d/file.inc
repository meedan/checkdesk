<?php
/**
 * @file
 * Base class for migrating files into Drupal.
 */

/**
 * Base class for all file migrations - handles commonalities across all
 * supported source Drupal versions.
 *
 * In addition to the arguments supported by DrupalMigration, the following
 * must be passed in the $arguments array:
 *  source_dir: Path to folder containing files to be migrated.
 *
 * The following optional arguments may be passed:
 * user_migration - Machine name of a user migration, used to establish
 *   dependencies and a sourceMigration for the uid mapping.
 * default_uid - Drupal 7 (destination) uid of the user account to use as
 *   the default.
 * file_class - Override for the default MigrateFileUri file class.
 * destination_dir - Destination directory for the files (defaults to public://).
 */
abstract class DrupalFileMigration extends DrupalMigration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);
    if (!empty($arguments['user_migration'])) {
       $user_migration = $arguments['user_migration'];
       $this->dependencies[] = $user_migration;
    }
    if (empty($arguments['file_class'])) {
      $arguments['file_class'] = 'MigrateFileUri';
    }
    if (empty($arguments['destination_dir'])) {
      $arguments['destination_dir'] = 'public://';
    }
    $this->sourceFields += $this->version->getSourceFields('file', 'file');
    // Allow derived classes to override this definition by setting it before
    // calling their parent constructor
    if (!isset($this->map)) {
      $this->map = new MigrateSQLMap($this->machineName,
        array(
          'fid' => array(
            'type' => 'int',
            'unsigned' => TRUE,
            'not null' => TRUE,
            'description' => 'Source file ID',
            'alias' => 'f',
          ),
        ),
        MigrateDestinationFile::getKeySchema()
      );
    }
    $this->source = new MigrateSourceSQL($this->query(),
      $this->sourceFields, NULL, $this->sourceOptions);

    $this->destination = new MigrateDestinationFile('file', $arguments['file_class']);

    // Setup common mappings
    $this->addFieldMapping('destination_dir')
         ->defaultValue($arguments['destination_dir']);
    $this->addFieldMapping('source_dir')
         ->defaultValue($arguments['source_dir']);
    $this->addFieldMapping('file_replace')
         ->defaultValue(MigrateFile::FILE_EXISTS_REUSE);
    $this->addFieldmapping('preserve_files')
          ->defaultValue(TRUE);

    if (!empty($arguments['default_uid'])) {
      $default_uid = $arguments['default_uid'];
    }
    else {
      $default_uid = 1;
    }
    if (isset($user_migration)) {
      $this->addFieldMapping('uid', 'uid')
           ->sourceMigration($user_migration)
           ->defaultValue($default_uid);
    }
    else {
      $this->addFieldMapping('uid')
           ->defaultValue($default_uid);
    }
    $this->addUnmigratedSources(array('filename', 'filemime', 'filesize'));
  }
}
