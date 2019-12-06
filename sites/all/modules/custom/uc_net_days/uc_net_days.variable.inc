<?php

/**
 * @file
 * Variable module hook implementations.
 */


/**
 * Implements hook_variable_group_info().
 */
function uc_net_days_variable_group_info() {
  $groups['uc_net_days'] = array(
    'title' => t('Ubercart Net 7 Days payment settings'),
    'access' => 'administer store',
    'path' => array('admin/store/settings/payment/method'),
  );
  return $groups;
}

/**
 * Implements hook_variable_info().
 */
function uc_net_days_variable_info($options) {
  $variables['uc_net_days_policy'] = array(
    'type' => 'text',
    'title' => t('Net 7 Days policy message', array(), $options),
    'description' => t('Policy message for Net 7 Days payment', array(), $options),
    'group' => 'uc_net_days',
    'default' => t('Full payment will be due per agreed upon terms.', array(), $options),
  );
  return $variables;
}
