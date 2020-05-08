<?php

/**
 * @file
 * skin_version2.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function skin_version2_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'uc_catalog_image'.
  $field_bases['uc_catalog_image'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'uc_catalog_image',
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => 0,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'image',
  );

  return $field_bases;
}
