<?php
/**
 * @file
 * retailer_map.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function retailer_map_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: management_gmap-location:admin/config/services/gmap_location.
  $menu_links['management_gmap-location:admin/config/services/gmap_location'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/services/gmap_location',
    'router_path' => 'admin/config/services/gmap_location',
    'link_title' => 'GMap Location',
    'options' => array(
      'attributes' => array(
        'title' => 'Configure GMap Location settings.',
      ),
      'identifier' => 'management_gmap-location:admin/config/services/gmap_location',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_web-services:admin/config/services',
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('GMap Location');

  return $menu_links;
}
