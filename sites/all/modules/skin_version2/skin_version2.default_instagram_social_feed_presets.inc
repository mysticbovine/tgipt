<?php
/**
 * @file
 * skin_version2.default_instagram_social_feed_presets.inc
 */

/**
 * Implements hook_default_nitf_xml_preset().
 */
function skin_version2_default_nitf_xml_preset() {
  $export = array();

  $preset = new stdClass();
  $preset->disabled = FALSE; /* Edit this to true to make a default preset disabled initially */
  $preset->api_version = 1;
  $preset->name = 'TGIPT';
  $preset->feed_type = 2;
  $preset->search_term = '';
  $preset->user_id = '';
  $preset->auto_publish = 1;
  $preset->enabled = 1;
  $export['TGIPT'] = $preset;

  $preset = new stdClass();
  $preset->disabled = FALSE; /* Edit this to true to make a default preset disabled initially */
  $preset->api_version = 1;
  $preset->name = 'pettreatery';
  $preset->feed_type = 1;
  $preset->search_term = '#pettreatery';
  $preset->user_id = '';
  $preset->auto_publish = 1;
  $preset->enabled = 1;
  $export['pettreatery'] = $preset;

  return $export;
}
