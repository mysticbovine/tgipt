<?php

/**
 * @file
 * Payment pack administration menu items.
 */

/**
 * Receives a deferred payment for an order and put in a deferred date.
 *
 * @see uc_deferred_payment_received_form_submit()
 * @ingroup forms
 */
function uc_deferred_payment_received_form($form, &$form_state, $order) {
  $balance = uc_payment_balance($order);
  $form['balance'] = array(
    '#prefix' => '<strong>' . t('Order balance:') . '</strong> ',
    '#markup' => uc_currency_format($balance),
  );
  $form['order_id'] = array(
    '#type' => 'hidden',
    '#value' => $order->order_id,
  );
  $form['amount'] = array(
    '#type' => 'uc_price',
    '#title' => t('Amount'),
    '#default_value' => $balance,
  );
  $form['comment'] = array(
    '#type' => 'textfield',
    '#title' => t('Comment'),
    '#description' => t('Any notes about the payment.'),
    '#size' => 64,
    '#maxlength' => 256,
  );
  $form['deferred'] = array(
    '#type' => 'fieldset',
    '#title' => t('Date card was charged'),
    '#attributes' => array('class' => array('uc-inline-form', 'clearfix')),
  );
  $form['deferred']['deferred_month'] = uc_select_month(NULL, format_date(REQUEST_TIME, 'custom', 'n'));
  $form['deferred']['deferred_day'] = uc_select_day(NULL, format_date(REQUEST_TIME, 'custom', 'j'));
  $form['deferred']['deferred_year'] = uc_select_year(NULL, format_date(REQUEST_TIME, 'custom', 'Y'), format_date(REQUEST_TIME, 'custom', 'Y'), format_date(REQUEST_TIME, 'custom', 'Y') + 1);

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Receive deferred payment'),
  );

  return $form;
}

/**
 * Submit handler for uc_deferred_payment_received_form().
 *
 * @see uc_deferred_payment_received_form()
 */
function uc_deferred_payment_received_form_submit($form, &$form_state) {
  global $user;

  uc_payment_enter($form_state['values']['order_id'], 'deferred', $form_state['values']['amount'], $user->uid, '', $form_state['values']['comment']);

  db_insert('uc_payment_check')
    ->fields(array(
      'order_id' => $form_state['values']['order_id'],
      'deferred_date' => mktime(12, 0, 0, $form_state['values']['deferred_month'], $form_state['values']['deferred_day'], $form_state['values']['deferred_year']),
    ))
    ->execute();

  drupal_set_message(t('Deffered payment received on @date.', array('@date' => uc_date_format($form_state['values']['clear_month'], $form_state['values']['clear_day'], $form_state['values']['clear_year']))));

  $form_state['redirect'] = 'admin/store/orders/' . $form_state['values']['order_id'];
}
