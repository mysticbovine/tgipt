<?php

/**
 * @file
 * Payment pack administration menu items.
 */

/**
 * Receives a payment for an 'Due on Receipt' order and put in a payment date.
 *
 * @see uc_due_on_receipt_received_form_submit()
 * @ingroup forms
 */
function uc_due_on_receipt_received_form($form, &$form_state, $order) {
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
  $form['on_receipt'] = array(
    '#type' => 'fieldset',
    '#title' => t('Date card was charged'),
    '#attributes' => array('class' => array('uc-inline-form', 'clearfix')),
  );
  $form['on_receipt']['on_receipt_month'] = uc_select_month(NULL, format_date(REQUEST_TIME, 'custom', 'n'));
  $form['on_receipt']['on_receipt_day'] = uc_select_day(NULL, format_date(REQUEST_TIME, 'custom', 'j'));
  $form['on_receipt']['on_receipt_year'] = uc_select_year(NULL, format_date(REQUEST_TIME, 'custom', 'Y'), format_date(REQUEST_TIME, 'custom', 'Y'), format_date(REQUEST_TIME, 'custom', 'Y') + 1);

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Received payment'),
  );

  return $form;
}

/**
 * Submit handler for uc_due_on_receipt_received_form().
 *
 * @see uc_due_on_receipt_received_form()
 */
function uc_due_on_receipt_received_form_submit($form, &$form_state) {
  global $user;

  uc_payment_enter($form_state['values']['order_id'], 'on_receipt', $form_state['values']['amount'], $user->uid, '', $form_state['values']['comment']);

  db_insert('uc_payment_check')
    ->fields(array(
      'order_id' => $form_state['values']['order_id'],
      'on_receipt_date' => mktime(12, 0, 0, $form_state['values']['on_receipt_month'], $form_state['values']['on_receipt_day'], $form_state['values']['on_receipt_year']),
    ))
    ->execute();

  drupal_set_message(t('Payment received on @date.', array('@date' => uc_date_format($form_state['values']['clear_month'], $form_state['values']['clear_day'], $form_state['values']['clear_year']))));

  $form_state['redirect'] = 'admin/store/orders/' . $form_state['values']['order_id'];
}
