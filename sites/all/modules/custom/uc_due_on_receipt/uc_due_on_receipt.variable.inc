<?php

/**
 * @file
 * Variable module hook implementations.
 */


/**
 * Implements hook_variable_group_info().
 */
function uc_due_on_receipt_variable_group_info() {
  $groups['uc_due_on_receipt'] = array(
    'title' => t('Ubercart Due on Receipt payment settings'),
    'access' => 'administer store',
    'path' => array('admin/store/settings/payment/method'),
  );
  return $groups;
}

/**
 * Implements hook_variable_info().
 */
function uc_due_on_receipt_variable_info($options) {
  $variables['uc_due_on_receipt_policy'] = array(
    'type' => 'text',
    'title' => t('Due on Receipt policy message', array(), $options),
    'description' => t('Policy message for Due on Recipt payment', array(), $options),
    'group' => 'uc_due_on_receipt',
    'default' => t('Full payment will be due on reciept of products or per agreed upon terms.', array(), $options),
  );
  return $variables;
}
