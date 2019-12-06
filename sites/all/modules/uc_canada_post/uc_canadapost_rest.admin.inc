<?php

/**
 * @file
 * Canada Post module administration menu callbacks.
 *
 * @author Tim Rohaly.    <http://drupal.org/user/202830>
 */


/**
 * Canada Post shipping settings.
 *
 * Configures Canada Post CPC ID, available services, and other settings
 * related to shipping quotes.
 */
function uc_canadapost_rest_admin_settings() {

  // Put fieldsets into vertical tabs.
  $form['canadapost-settings'] = array(
    '#type' => 'vertical_tabs',
    '#attached' => array(
      'js' => array(
        'vertical-tabs' => drupal_get_path('module', 'uc_canadapost_rest') . '/uc_canadapost_rest.admin.js',
      ),
    ),
  );

  // Container for credentials forms.
  $form['uc_canadapost_rest_sellonline'] = array(
    '#type'          => 'fieldset',
    '#title'         => t('REST settings'),
    '#description'   => t('Account number and authorization information.'),
    '#collapsible'   => TRUE,
    '#collapsed'     => TRUE,
    '#group'         => 'canadapost-settings',
  );

  // Form to set the merchant API Credentials.
  $form['uc_canadapost_rest_sellonline']['uc_canadapost_rest_userid'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Canada Post API User ID'),
    '#default_value' => variable_get('uc_canadapost_rest_userid', ''),
    '#required'      => TRUE,
    //'#description'   => t('Your Canada Post SellOnline account number. Visit http://sellonline.canadapost.ca to get one.'),
  );

  $form['uc_canadapost_rest_sellonline']['uc_canadapost_rest_password'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Canada Post API User Password'),
    '#default_value' => variable_get('uc_canadapost_rest_password', ''),
    '#required'      => TRUE,
    //'#description'   => t('Your Canada Post SellOnline account number. Visit http://sellonline.canadapost.ca to get one.'),
  );

  // Form to set the Canada Post server URL.
  $form['uc_canadapost_rest_sellonline']['uc_canadapost_rest_endpoint'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Canada Post API Endpoint'),
    '#default_value' => variable_get('uc_canadapost_rest_endpoint', 'https://ct.soa-gw.canadapost.ca/rs/ship/price'),
    '#required'      => TRUE,
    '#description'   => t('The server address to use for shipping calculations.'),
  );

  // Form to specify ship-from postal code.
  $orig = variable_get('uc_quote_store_default_address', new stdClass());
  $form['uc_canadapost_rest_sellonline']['uc_canadapost_rest_postalcode'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Ship from postal code'),
    '#default_value' => variable_get('uc_canadapost_rest_postalcode', isset($orig->postal_code) ? $orig->postal_code : ''),
    '#description'   => t('Postal code to ship from.'),
  );

  // Container for service selection forms.
  $form['uc_canadapost_rest_service_selection'] = array(
    '#type'          => 'fieldset',
    '#title'         => t('Service Options'),
    '#collapsible'   => TRUE,
    '#collapsed'     => TRUE,
    '#group'         => 'canadapost-settings',
  );

  // Form to restrict Canada Post services available to customer.
  $form['uc_canadapost_rest_service_selection']['uc_canadapost_rest_services'] = array(
    '#type'          => 'checkboxes',
    '#title'         => t('Canada Post Services'),
    '#default_value' => variable_get('uc_canadapost_rest_services', _uc_canadapost_rest_service_list()),
    '#options'       => _uc_canadapost_rest_service_list(),
    '#description'   => t('Select the shipping services that are available to customers. This list only serves to further restrict the services as set up in your SellOnline account. If you have not selected a service in your Canada Post account, it will not show up even if it is selected here.'),
  );

  // Container for quote options forms.
  $form['uc_canadapost_rest_quote_options'] = array(
    '#type'          => 'fieldset',
    '#title'         => t('Quote Options'),
    '#description'   => t('Preferences that affect computation of quote.'),
    '#collapsible'   => TRUE,
    '#collapsed'     => TRUE,
    '#group'         => 'canadapost-settings',
  );

  // Form to specify customer number.
  $form['uc_canadapost_rest_quote_options']['uc_canadapost_rest_customer_number'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Customer Number'),
    '#default_value' => variable_get('uc_canadapost_rest_customer_number', ''),
    '#description'   => t('This element is required to obtain discounted rates for commercial customers and Solutions for Small Business members. It must be omitted to obtain counter (i.e., consumer) rates.'),
  );


  // Form to specify date format.
  $form['uc_canadapost_rest_quote_options']['uc_canadapost_rest_datefmt'] = array(
    '#type'          => 'select',
    '#title'         => t('Delivery date format'),
    '#default_value' => variable_get('uc_canadapost_rest_datefmt', ''),
    '#description'   => t('Format to display estimated delivery date.'),
    '#options'       => _uc_canadapost_rest_get_date_options(),
  );

  // Form to specify Box Length.
  $form['uc_canadapost_rest_quote_options']['uc_canadapost_rest_box_length'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Standard Box Length in cm'),
    '#default_value' => variable_get('uc_canadapost_rest_box_length', '30'),
    '#element_validate' => array('element_validate_number'),
    '#description'   => t('The length in cm of the standard box to be used for quotes .'),
  );  

  // Form to specify Box Width.
  $form['uc_canadapost_rest_quote_options']['uc_canadapost_rest_box_width'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Standard Box Width in cm'),
    '#default_value' => variable_get('uc_canadapost_rest_box_width', '30'),
    '#element_validate' => array('element_validate_number'),
    '#description'   => t('The width in cm of the standard box to be used for quotes .'),
  );  
  
    // Form to specify Box Height.
  $form['uc_canadapost_rest_quote_options']['uc_canadapost_rest_box_height'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Standard Box Height in cm'),
    '#default_value' => variable_get('uc_canadapost_rest_box_height', '30'),
    '#element_validate' => array('element_validate_number'),
    '#description'   => t('The height in cm of the standard box to be used for quotes .'),
  );  

  // Container for markup forms.
  $form['uc_canadapost_rest_markups'] = array(
    '#type'          => 'fieldset',
    '#title'         => t('Markups'),
    '#description'   => t('Modifiers to the shipping weight and quoted rate'),
    '#collapsible'   => TRUE,
    '#collapsed'     => TRUE,
    '#group'         => 'canadapost-settings',
  );

  // Form to select type of rate markup.
  $form['uc_canadapost_rest_markups']['uc_canadapost_rest_rate_markup_type'] = array(
    '#type'          => 'select',
    '#title'         => t('Rate Markup Type'),
    '#default_value' => variable_get('uc_canadapost_rest_rate_markup_type', 'percentage'),
    '#options'       => array(
      'percentage' => t('Percentage (%)'),
      'multiplier' => t('Multiplier (×)'),
      'currency'   => t('Addition (!currency)', array('!currency' => variable_get('uc_currency_sign', '$'))),
    ),
  );

  // Form to select type of rate amount.
  $form['uc_canadapost_rest_markups']['uc_canadapost_rest_rate_markup'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Canada Post Shipping Rate Markup'),
    '#default_value' => variable_get('uc_canadapost_rest_rate_markup', '0'),
    '#description'   => t('Markup shipping rate quote by dollar amount, percentage, or multiplier. Please note if this field is not blank, it overrides the "Handling fee" set up in your SellOnline account. If blank, the handling fee from your SellOnline account will be used.'),
  );

  // Form to select type of weight markup.
  $form['uc_canadapost_rest_markups']['uc_canadapost_rest_weight_markup_type'] = array(
    '#type'          => 'select',
    '#title'         => t('Weight Markup Type'),
    '#default_value' => variable_get('uc_canadapost_rest_weight_markup_type', 'percentage'),
    '#options'       => array(
      'percentage' => t('Percentage (%)'),
      'multiplier' => t('Multiplier (×)'),
      'mass'       => t('Addition (!mass)', array('!mass' => '#')),
    ),
  );

  // Form to select type of weight markup amount.
  $form['uc_canadapost_rest_markups']['uc_canadapost_rest_weight_markup'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Canada Post Shipping Weight Markup'),
    '#default_value' => variable_get('uc_canadapost_rest_weight_markup', '0'),
    '#description'   => t('Markup Canada Post shipping weight before quote, on a per-package basis, by weight amount, percentage, or multiplier.'),
  );

  // Container for errors messages forms.
  $form['uc_canadapost_rest_error_handling'] = array(
    '#type'          => 'fieldset',
    '#title'         => t('Error handling'),
    '#collapsible'   => TRUE,
    '#collapsed'     => TRUE,
    '#group'         => 'canadapost-settings',
  );  

  // Form to select type of weight markup amount.
  $form['uc_canadapost_rest_error_handling']['uc_canadapost_rest_bad_request_message'] = array(
    '#type'          => 'textarea',
    '#title'         => t('Bad Request message'),
    '#default_value' => variable_get('uc_canadapost_rest_bad_request_message', 'Canada Post failed to recognize postal code.'),
    '#description'   => t('Bad Request is caused by some errors in message which is sent to CP. Postal code is only value provided by customer which is sent with request, so mainly wrong postal code is reason for Bad Request.'),
  );

  $form = system_settings_form($form);

  // Add Cancel link.
  $form['actions']['cancel'] = array(
    '#markup' => l(t('Cancel'), 'admin/store/settings/quotes'),
  );

  return $form;
}

/**
 * Utility routine to construct options for date format.
 *
 * @return
 *   Array of today's date in various formats.
 */
function _uc_canadapost_rest_get_date_options() {
  $date_options = array(
    'm/d/Y', 'd/m/Y', 'Y/m/d',
    'D, M j, Y', 'D, M j', 'F j, Y',
    'l, j F', 'l, F j',
    'l, j F, Y', 'l, Y, F j', 'l, F j, Y'
  );
  $date_options_nice = array('' => t("Don't display estimate"));

  foreach ($date_options as $datefmt) {
    $date_options_nice[$datefmt] = t("Estimated delivery") . ': ' . date($datefmt);
  }
  return $date_options_nice;
}

/**
 * Utility function to determine province based on postal code.
 *
 * Not currently used by this module.
 *
 * FSA (= Forward Sortation Area) code is first three characters of
 * postal code.  The first letter indicates the postal district, which
 * has an <em>almost</em> 1 to 1 correspondence with province.  The
 * exceptions are that NU and NT are in the same postal district,
 * and ON and QC both have multiple districts.
 *
 * @param $postalcode
 *   6-character postal code.
 *
 * @return
 *   2-character province name abbreviation.
 */
function _uc_canadapost_rest_lookup_province($postalcode) {

  $fsa = drupal_strtoupper(drupal_substr($postalcode, 0, 1));
  $province = array(
    'A' => 'NL',
    'B' => 'NS',
    'C' => 'PE',
    'E' => 'NB',
    'G' => 'QC',
    'H' => 'QC',
    'J' => 'QC',
    'K' => 'ON',
    'L' => 'ON',
    'M' => 'ON',
    'N' => 'ON',
    'P' => 'ON',
    'R' => 'MB',
    'S' => 'SK',
    'T' => 'AB',
    'V' => 'BC',
    'X' => 'NT',  // X is also NU, but we can only return one value here...
    'Y' => 'YT',
  );
  return $province[$fsa];
}
