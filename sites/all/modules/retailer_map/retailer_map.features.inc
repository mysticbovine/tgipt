<?php
/**
 * @file
 * retailer_map.features.inc
 */

/**
 * Implements hook_views_api().
 */
function retailer_map_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_mailchimp_signup().
 */
function retailer_map_default_mailchimp_signup() {
  $items = array();
  $items['retail'] = entity_import('mailchimp_signup', '{
    "name" : "retail",
    "mc_lists" : { "1e3329cad6" : "1e3329cad6" },
    "mode" : "1",
    "title" : "Retail",
    "settings" : {
      "path" : "",
      "submit_button" : "Submit",
      "confirmation_message" : "You have been successfully subscribed.",
      "destination" : "",
      "mergefields" : {
        "EMAIL" : {
          "name" : "Email Address",
          "req" : true,
          "field_type" : "email",
          "public" : true,
          "show" : true,
          "order" : "1",
          "default" : null,
          "helptext" : null,
          "size" : "25",
          "tag" : "EMAIL",
          "id" : 0
        },
        "FNAME" : {
          "name" : "First Name",
          "req" : false,
          "field_type" : "text",
          "public" : true,
          "show" : true,
          "order" : "2",
          "default" : "",
          "helptext" : "",
          "size" : "25",
          "tag" : "FNAME",
          "id" : 1
        },
        "LNAME" : {
          "name" : "Last Name",
          "req" : false,
          "field_type" : "text",
          "public" : true,
          "show" : true,
          "order" : "3",
          "default" : "",
          "helptext" : "",
          "size" : "25",
          "tag" : "LNAME",
          "id" : 2
        }
      },
      "description" : "",
      "doublein" : 1,
      "send_welcome" : 1,
      "include_interest_groups" : 0
    },
    "rdf_mapping" : []
  }');
  return $items;
}
