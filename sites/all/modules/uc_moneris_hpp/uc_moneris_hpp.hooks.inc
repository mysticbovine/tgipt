<?php

/*
 * Allows modules to set the country code programmatically, so
 * you can use both the USA and Canadian services.
 *
 * @param $country
 *   the country code, passed by reference
 * @param $order_id
 *   the Ubercart order id
 */
function hook_uc_moneris_hpp_alter_country(&$country, $order_id) { }

/*
 * Allows modules to alter the API fields that appear in the checkout
 * review form and that are posted to the Moneris HPP.
 *
 * See uc_moneris_hpp_form_alter() for the available fields.
 *
 * @param $vars
 *   array of API variables, in name => value format, passed by reference
 * @param $order_id
 *   the Ubercart order id
 */
function hook_uc_moneris_hpp_purchase_alter(&$vars, $order_id) { }

/*
 * Allows modules to alter the API fields that are used to verify the
 * transaction. (This is probably necessary if you are also altering the
 * initial form fields above.)
 *
 * See uc_moneris_hpp_return() for the available fields.
 *
 * @param $vars
 *   array of API variables, in name => value format, passed by reference
 * @param $order_id
 *   the cached Ubercart order id that we are *supposed* to be verifying
 */
function hook_uc_moneris_hpp_verify_alter(&$vars, $order_id) { }

/*
 * For example, you might want to direct Canadian customers to the CA
 * API, and USA customers to the American API.
 *
 * The following assumes that the main HPP config holds the USA values,
 * and we set to CA only for Canadian customers.
 *
 * Note the use of uc_moneris_hpp_get_order() to deal with test IDs
 *

 function example_uc_moneris_hpp_alter_country(&$country, $order) {
 $order = uc_moneris_hpp_get_order($order_id);
 if ($order->billing_country == 124) $country = 'ca';
 }

 function example_uc_moneris_hpp_purchase_alter(&$vars, $order) {
 $order = uc_moneris_hpp_get_order($order_id);
 if ($order->billing_country == 124) example_set_cad_keys($vars);
 }

 function example_uc_moneris_hpp_verify_alter(&$vars, $order_id) {
 $order = uc_moneris_hpp_get_order($order_id);
 if ($order->billing_country == 124) example_set_cad_keys($vars);
 }

 function example_set_cad_keys(&$vars) {
 $vars['ps_store_id']  = 'CAD_id';
 $vars['hpp_key']      = 'CAD_key';
 unset($vars['hpp_id']);  // remove USA key variable
 }
 */
