<?php
/**
 * @file
 * The primary PHP file for this theme.
 */
function tgipt_megamenu($parent){
    $tid = "";
    $block = "block";
    if ($parent == "cat"){
        $block = "block_1";
    } else {
        $block == "block";
    }
    $view = views_get_view('megamenutest'); //test_view is the view machine name
    $view->set_display($block); //block is the view display name
    $view->set_arguments($tid); //$tid is the argument to pass
    $view->pre_execute();
    $view->execute();
    $content = $view->render();
    return $content;
};

function tgipt_menu_tree__primary(array &$variables) {
    return $variables['tree'];
  }
function tgipt_theme_menu_link(array $variables) {
    $element = $variables['element'];
    $sub_menu = '';
    if ($element['#below']) {
        $sub_menu = drupal_render($element['#below']);
    }
    $output = l($element['#title'], $element['#href'], $element['#localized_options']);
    return '<li' . drupal_attributes($element['#attributes']) . '><span></span>' . $output . $sub_menu . "</li>\n";
}

function tgipt_uc_attribute_help($path, $arg) {
    switch ($path) {
      // Help message for the product Adjustments tab.
      case 'node/%/edit/adjustments':
        return '<p>' . t('Enter an alternate SKU and UPC to be used when the specified set of options are chosen and the product is added to the cart.') . '</p><p>' . t('<b>Warning:</b> Adding or removing attributes from this product will reset all the SKUs and UPC on this page to the default product SKU or UPC.') . '</p>';
    }
}
// function tgipt_menu() {
   // $items['node/%node/edit/adjustments'] = array(
    // 'title' => 'Adjustments',
    // 'description' => 'Administer SKU adjustments for different variants of this product.',
    // 'page callback' => 'drupal_get_form',
    // 'page arguments' => array('uc_product_adjustments_form', 1),
    // 'access callback' => 'uc_attribute_product_option_access',
    // 'access arguments' => array(1),
    // 'type' => MENU_LOCAL_TASK,
    // 'weight' => 3,
    // 'file' => 'uc_attribute.admin.inc',
  // );

  // return $items;
// 