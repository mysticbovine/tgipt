<?php
// $Id: uc_po.views_default.inc 1770 2012-05-03 17:28:25Z kevin $
/**
 * Implements hook_views_default_views().
 */
function uc_po_views_default_views() {
  // begin c/p from views

$view = new view;
$view->name = 'uc_po_orders';
$view->description = '';
$view->tag = 'uc_po';
$view->base_table = 'uc_payment_po';
$view->human_name = 'uc_po orders';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'PO Orders';
$handler->display->display_options['use_ajax'] = TRUE;
$handler->display->display_options['access']['type'] = 'none';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['query']['options']['query_comment'] = FALSE;
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '10';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'po_number' => 'po_number',
  'order_id' => 'order_id',
  'billing_company' => 'billing_company',
  'billing_full_name' => 'billing_full_name',
  'order_total' => 'order_total',
  'created' => 'created',
  'order_status' => 'order_status',
);
$handler->display->display_options['style_options']['default'] = 'created';
$handler->display->display_options['style_options']['info'] = array(
  'po_number' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'order_id' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'billing_company' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'billing_full_name' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'order_total' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'created' => array(
    'sortable' => 1,
    'default_sort_order' => 'desc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'order_status' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
$handler->display->display_options['style_options']['override'] = 1;
$handler->display->display_options['style_options']['sticky'] = 0;
$handler->display->display_options['style_options']['empty_table'] = 0;
/* Relationship: UC PO: Order Id */
$handler->display->display_options['relationships']['order_id']['id'] = 'order_id';
$handler->display->display_options['relationships']['order_id']['table'] = 'uc_payment_po';
$handler->display->display_options['relationships']['order_id']['field'] = 'order_id';
$handler->display->display_options['relationships']['order_id']['required'] = 0;
/* Field: UC PO: PO Number */
$handler->display->display_options['fields']['po_number']['id'] = 'po_number';
$handler->display->display_options['fields']['po_number']['table'] = 'uc_payment_po';
$handler->display->display_options['fields']['po_number']['field'] = 'po_number';
/* Field: Order: Order ID */
$handler->display->display_options['fields']['order_id']['id'] = 'order_id';
$handler->display->display_options['fields']['order_id']['table'] = 'uc_orders';
$handler->display->display_options['fields']['order_id']['field'] = 'order_id';
$handler->display->display_options['fields']['order_id']['relationship'] = 'order_id';
$handler->display->display_options['fields']['order_id']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['order_id']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['order_id']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['order_id']['alter']['external'] = 0;
$handler->display->display_options['fields']['order_id']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['order_id']['alter']['trim_whitespace'] = 0;
$handler->display->display_options['fields']['order_id']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['order_id']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['order_id']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['order_id']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['order_id']['alter']['trim'] = 0;
$handler->display->display_options['fields']['order_id']['alter']['html'] = 0;
$handler->display->display_options['fields']['order_id']['element_label_colon'] = 1;
$handler->display->display_options['fields']['order_id']['element_default_classes'] = 1;
$handler->display->display_options['fields']['order_id']['hide_empty'] = 0;
$handler->display->display_options['fields']['order_id']['empty_zero'] = 0;
$handler->display->display_options['fields']['order_id']['hide_alter_empty'] = 1;
$handler->display->display_options['fields']['order_id']['link_to_order'] = 1;
/* Field: Order: Billing address: Company */
$handler->display->display_options['fields']['billing_company']['id'] = 'billing_company';
$handler->display->display_options['fields']['billing_company']['table'] = 'uc_orders';
$handler->display->display_options['fields']['billing_company']['field'] = 'billing_company';
$handler->display->display_options['fields']['billing_company']['relationship'] = 'order_id';
$handler->display->display_options['fields']['billing_company']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['billing_company']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['billing_company']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['billing_company']['alter']['external'] = 0;
$handler->display->display_options['fields']['billing_company']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['billing_company']['alter']['trim_whitespace'] = 0;
$handler->display->display_options['fields']['billing_company']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['billing_company']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['billing_company']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['billing_company']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['billing_company']['alter']['trim'] = 0;
$handler->display->display_options['fields']['billing_company']['alter']['html'] = 0;
$handler->display->display_options['fields']['billing_company']['element_label_colon'] = 1;
$handler->display->display_options['fields']['billing_company']['element_default_classes'] = 1;
$handler->display->display_options['fields']['billing_company']['hide_empty'] = 0;
$handler->display->display_options['fields']['billing_company']['empty_zero'] = 0;
$handler->display->display_options['fields']['billing_company']['hide_alter_empty'] = 1;
/* Field: Order: Billing address: Full name */
$handler->display->display_options['fields']['billing_full_name']['id'] = 'billing_full_name';
$handler->display->display_options['fields']['billing_full_name']['table'] = 'uc_orders';
$handler->display->display_options['fields']['billing_full_name']['field'] = 'billing_full_name';
$handler->display->display_options['fields']['billing_full_name']['relationship'] = 'order_id';
$handler->display->display_options['fields']['billing_full_name']['label'] = 'Name';
$handler->display->display_options['fields']['billing_full_name']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['billing_full_name']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['billing_full_name']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['billing_full_name']['alter']['external'] = 0;
$handler->display->display_options['fields']['billing_full_name']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['billing_full_name']['alter']['trim_whitespace'] = 0;
$handler->display->display_options['fields']['billing_full_name']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['billing_full_name']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['billing_full_name']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['billing_full_name']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['billing_full_name']['alter']['trim'] = 0;
$handler->display->display_options['fields']['billing_full_name']['alter']['html'] = 0;
$handler->display->display_options['fields']['billing_full_name']['element_label_colon'] = 1;
$handler->display->display_options['fields']['billing_full_name']['element_default_classes'] = 1;
$handler->display->display_options['fields']['billing_full_name']['hide_empty'] = 0;
$handler->display->display_options['fields']['billing_full_name']['empty_zero'] = 0;
$handler->display->display_options['fields']['billing_full_name']['hide_alter_empty'] = 1;
/* Field: Order: Order total */
$handler->display->display_options['fields']['order_total']['id'] = 'order_total';
$handler->display->display_options['fields']['order_total']['table'] = 'uc_orders';
$handler->display->display_options['fields']['order_total']['field'] = 'order_total';
$handler->display->display_options['fields']['order_total']['relationship'] = 'order_id';
$handler->display->display_options['fields']['order_total']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['order_total']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['order_total']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['order_total']['alter']['external'] = 0;
$handler->display->display_options['fields']['order_total']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['order_total']['alter']['trim_whitespace'] = 0;
$handler->display->display_options['fields']['order_total']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['order_total']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['order_total']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['order_total']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['order_total']['alter']['trim'] = 0;
$handler->display->display_options['fields']['order_total']['alter']['html'] = 0;
$handler->display->display_options['fields']['order_total']['element_label_colon'] = 1;
$handler->display->display_options['fields']['order_total']['element_default_classes'] = 1;
$handler->display->display_options['fields']['order_total']['hide_empty'] = 0;
$handler->display->display_options['fields']['order_total']['empty_zero'] = 0;
$handler->display->display_options['fields']['order_total']['hide_alter_empty'] = 1;
$handler->display->display_options['fields']['order_total']['set_precision'] = 0;
$handler->display->display_options['fields']['order_total']['precision'] = '0';
$handler->display->display_options['fields']['order_total']['format_plural'] = 0;
/* Field: Order: Creation date */
$handler->display->display_options['fields']['created']['id'] = 'created';
$handler->display->display_options['fields']['created']['table'] = 'uc_orders';
$handler->display->display_options['fields']['created']['field'] = 'created';
$handler->display->display_options['fields']['created']['relationship'] = 'order_id';
$handler->display->display_options['fields']['created']['label'] = 'Order Date';
$handler->display->display_options['fields']['created']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['created']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['created']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['created']['alter']['external'] = 0;
$handler->display->display_options['fields']['created']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['created']['alter']['trim_whitespace'] = 0;
$handler->display->display_options['fields']['created']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['created']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['created']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['created']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['created']['alter']['trim'] = 0;
$handler->display->display_options['fields']['created']['alter']['html'] = 0;
$handler->display->display_options['fields']['created']['element_label_colon'] = 1;
$handler->display->display_options['fields']['created']['element_default_classes'] = 1;
$handler->display->display_options['fields']['created']['hide_empty'] = 0;
$handler->display->display_options['fields']['created']['empty_zero'] = 0;
$handler->display->display_options['fields']['created']['hide_alter_empty'] = 1;
$handler->display->display_options['fields']['created']['date_format'] = 'uc_store';
/* Field: Order: Order status */
$handler->display->display_options['fields']['order_status']['id'] = 'order_status';
$handler->display->display_options['fields']['order_status']['table'] = 'uc_orders';
$handler->display->display_options['fields']['order_status']['field'] = 'order_status';
$handler->display->display_options['fields']['order_status']['relationship'] = 'order_id';
$handler->display->display_options['fields']['order_status']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['order_status']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['order_status']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['order_status']['alter']['external'] = 0;
$handler->display->display_options['fields']['order_status']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['order_status']['alter']['trim_whitespace'] = 0;
$handler->display->display_options['fields']['order_status']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['order_status']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['order_status']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['order_status']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['order_status']['alter']['trim'] = 0;
$handler->display->display_options['fields']['order_status']['alter']['html'] = 0;
$handler->display->display_options['fields']['order_status']['element_label_colon'] = 1;
$handler->display->display_options['fields']['order_status']['element_default_classes'] = 1;
$handler->display->display_options['fields']['order_status']['hide_empty'] = 0;
$handler->display->display_options['fields']['order_status']['empty_zero'] = 0;
$handler->display->display_options['fields']['order_status']['hide_alter_empty'] = 1;
/* Filter criterion: UC PO: PO Number */
$handler->display->display_options['filters']['po_number']['id'] = 'po_number';
$handler->display->display_options['filters']['po_number']['table'] = 'uc_payment_po';
$handler->display->display_options['filters']['po_number']['field'] = 'po_number';
$handler->display->display_options['filters']['po_number']['operator'] = 'contains';
$handler->display->display_options['filters']['po_number']['group'] = 0;
$handler->display->display_options['filters']['po_number']['exposed'] = TRUE;
$handler->display->display_options['filters']['po_number']['expose']['operator_id'] = 'po_number_op';
$handler->display->display_options['filters']['po_number']['expose']['label'] = 'PO Number';
$handler->display->display_options['filters']['po_number']['expose']['operator'] = 'po_number_op';
$handler->display->display_options['filters']['po_number']['expose']['identifier'] = 'po_number';
$handler->display->display_options['filters']['po_number']['expose']['required'] = 0;
$handler->display->display_options['filters']['po_number']['expose']['multiple'] = FALSE;
/* Filter criterion: Order: Billing address: Company */
$handler->display->display_options['filters']['billing_company']['id'] = 'billing_company';
$handler->display->display_options['filters']['billing_company']['table'] = 'uc_orders';
$handler->display->display_options['filters']['billing_company']['field'] = 'billing_company';
$handler->display->display_options['filters']['billing_company']['relationship'] = 'order_id';
$handler->display->display_options['filters']['billing_company']['operator'] = 'contains';
$handler->display->display_options['filters']['billing_company']['group'] = 0;
$handler->display->display_options['filters']['billing_company']['exposed'] = TRUE;
$handler->display->display_options['filters']['billing_company']['expose']['operator_id'] = 'billing_company_op';
$handler->display->display_options['filters']['billing_company']['expose']['label'] = 'Company';
$handler->display->display_options['filters']['billing_company']['expose']['operator'] = 'billing_company_op';
$handler->display->display_options['filters']['billing_company']['expose']['identifier'] = 'billing_company';
$handler->display->display_options['filters']['billing_company']['expose']['required'] = 0;
$handler->display->display_options['filters']['billing_company']['expose']['multiple'] = FALSE;
/* Filter criterion: Order: Billing address: First name */
$handler->display->display_options['filters']['billing_first_name']['id'] = 'billing_first_name';
$handler->display->display_options['filters']['billing_first_name']['table'] = 'uc_orders';
$handler->display->display_options['filters']['billing_first_name']['field'] = 'billing_first_name';
$handler->display->display_options['filters']['billing_first_name']['relationship'] = 'order_id';
$handler->display->display_options['filters']['billing_first_name']['operator'] = 'contains';
$handler->display->display_options['filters']['billing_first_name']['group'] = 0;
$handler->display->display_options['filters']['billing_first_name']['exposed'] = TRUE;
$handler->display->display_options['filters']['billing_first_name']['expose']['operator_id'] = 'billing_first_name_op';
$handler->display->display_options['filters']['billing_first_name']['expose']['label'] = 'First name';
$handler->display->display_options['filters']['billing_first_name']['expose']['operator'] = 'billing_first_name_op';
$handler->display->display_options['filters']['billing_first_name']['expose']['identifier'] = 'billing_first_name';
$handler->display->display_options['filters']['billing_first_name']['expose']['required'] = 0;
$handler->display->display_options['filters']['billing_first_name']['expose']['multiple'] = FALSE;
/* Filter criterion: Order: Billing address: Last name */
$handler->display->display_options['filters']['billing_last_name']['id'] = 'billing_last_name';
$handler->display->display_options['filters']['billing_last_name']['table'] = 'uc_orders';
$handler->display->display_options['filters']['billing_last_name']['field'] = 'billing_last_name';
$handler->display->display_options['filters']['billing_last_name']['relationship'] = 'order_id';
$handler->display->display_options['filters']['billing_last_name']['operator'] = 'contains';
$handler->display->display_options['filters']['billing_last_name']['group'] = 0;
$handler->display->display_options['filters']['billing_last_name']['exposed'] = TRUE;
$handler->display->display_options['filters']['billing_last_name']['expose']['operator_id'] = 'billing_last_name_op';
$handler->display->display_options['filters']['billing_last_name']['expose']['label'] = 'Last name';
$handler->display->display_options['filters']['billing_last_name']['expose']['operator'] = 'billing_last_name_op';
$handler->display->display_options['filters']['billing_last_name']['expose']['identifier'] = 'billing_last_name';
$handler->display->display_options['filters']['billing_last_name']['expose']['required'] = 0;
$handler->display->display_options['filters']['billing_last_name']['expose']['multiple'] = FALSE;

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['path'] = 'admin/store/orders/po/view';
  
  // end c/p from views
  
  // Add view to list of views to provide.
  $views[$view->name] = $view;

  // ...Repeat all of the above for each view the module should provide.

  // At the end, return array of default views.
  return $views;
}
