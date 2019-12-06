<?php

/**
 * @file
 *
 * Misc helper functions.
 */

/**
 * Filter non-empty values from formaapi checkboxes.
 *
 * @param $array source array
 * @return formapi checkboxes
 */
function _filebrowser_filter_checkboxes_result($array) {
  $result = array();
  if ($array) {
    foreach ($array as $key => $value) {
      if (!empty($value)) {
        $result[$key] = TRUE;
      }
    }
  }
  return $result;
}

/**
 * Convert an array for formapi checkboxes comatibiility.
 *
 * @param $properties source array
 * @return formapi checkboxes
 */
function _filebrowser_properties_to_checkboxes(& $properties) {
  $result = array();
  if ($properties) {
    foreach ($properties as $key => $value) {
      if ($value) {
        $result[$key] = $key;
      }
    }
  }
  return $result;
}

/**
 * UTF8 bullet-proof basename replacement.
 */
function _filebrowser_safe_basename($path) {
  $path = rtrim($path, '/');
  $path = explode('/', $path);
  return end($path);
}

/**
 * UTF8 bullet-proof dirname replacement.
 */
function _filebrowser_safe_dirname($path) {
  $path = rtrim($path, '/');
  $path = explode('/', $path);
  array_pop($path);
  $result = implode("/", $path);
  if ($result == '') {
    return '/';
  }
  return $result;
}

/**
 * Helper function to match a pattern on the path
 * @param string $path path to process
 * @param string $patterns to search (seperated by cr)
 * @return TRUE if at least one pattern is found
 */
function _filebrowser_match_path($path, $patterns) {
  static $regexps = NULL;

  if (!isset($regexps[$patterns])) {
    $regexps[$patterns] = '/^(' . preg_replace(array(
        '/(\r\n?|\n)/',
        '/\\\\\*/'
    ), array(
        '|',
        '.*'
    ), preg_quote($patterns, '/')) . ')$/';
  }
  $result = preg_match($regexps[$patterns], _filebrowser_safe_basename($path)) == 1;
  return $result;
}

function _filebrowser_set_default(&$field, $value) {
  if (!isset($field)) {
    $field = $value;
  }
}

function &_filebrowser_options($source) {
  foreach ($source as $key => &$value) {
    $value = $value['title'];
  }
  return $source;
}

/**  Check the end of a string
 * @param $str source string
 * @param $sub element to search
 * @return return TRUE is a string ends with another string.
 */
function _filebrowser_ends_with($str, $sub) {
  return (substr($str, strlen($str) - strlen($sub)) == $sub);
}

/**
 * Converts a pattern to a filter for use with the file upload widget
 * The allowed file types are inserted as a pattern  on the node create form.
 * The pattern is a string separated by new lines
 * @param string $pattern
 * @return string
 */
function _filebrowser_pattern_to_filter($pattern) {
  $extensions = array();
  $filters = preg_split('/\R/', $pattern);
  foreach ($filters as $item) {
    $extensions[] = substr(strrchr($item, '.'), 1);
  }
  return implode(' ', $extensions);
}