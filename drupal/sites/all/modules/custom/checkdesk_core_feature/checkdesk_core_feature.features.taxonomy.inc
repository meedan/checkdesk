<?php
/**
 * @file
 * checkdesk_core_feature.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function checkdesk_core_feature_taxonomy_default_vocabularies() {
  return array(
    'media_rating' => array(
      'name' => 'Media Rating',
      'machine_name' => 'media_rating',
      'description' => 'The rating for a single piece of media.',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 1,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
