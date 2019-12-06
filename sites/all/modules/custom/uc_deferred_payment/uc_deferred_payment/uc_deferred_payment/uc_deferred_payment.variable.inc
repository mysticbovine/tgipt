<?php

/**
 * @file
 * Variable module hook implementations.
 */


/**
 * Implements hook_variable_group_info().
 */
function uc_deferred_payment_variable_group_info() {
  $groups['uc_deferred_payment'] = array(
    'title' => t('Ubercart deffered payment settings'),
    'access' => 'administer store',
    'path' => array('admin/store/settings/payment/method'),
  );
  return $groups;
}

/**
 * Implements hook_variable_info().
 */
function uc_deferred_payment_variable_info($options) {
  $variables['uc_deferred_payment_policy'] = array(
    'type' => 'text',
    'title' => t('Deferred payment policy message', array(), $options),
    'description' => t('Policy message for deferred payment', array(), $options),
    'group' => 'uc_deferred_payment',
    'default' => t('Full payment will be charged to the credit card on file 21 days after the order is placed.', array(), $options),
  );
  return $variables;
}
