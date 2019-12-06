<?php
/**
 * @file
 * skin_version2.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function skin_version2_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "instagram_social_feed" && $api == "default_instagram_social_feed_presets") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function skin_version2_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function skin_version2_image_default_styles() {
  $styles = array();

  // Exported image style: squared.
  $styles['squared'] = array(
    'label' => 'Squared',
    'effects' => array(
      4 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => '',
          'height' => 200,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
      5 => array(
        'name' => 'image_crop',
        'data' => array(
          'width' => 200,
          'height' => 200,
          'anchor' => 'center-center',
        ),
        'weight' => 2,
      ),
    ),
  );

  return $styles;
}
