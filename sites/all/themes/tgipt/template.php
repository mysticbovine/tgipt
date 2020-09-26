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