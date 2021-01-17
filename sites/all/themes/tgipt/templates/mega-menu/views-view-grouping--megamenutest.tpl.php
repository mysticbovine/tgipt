<?php

/**
 * @file
 * This template is used to print a single grouping in a view.
 *
 * It is not actually used in default Views, as this is registered as a theme
 * function which has better performance. For single overrides, the template is
 * perfectly okay.
 *
 * Variables available:
 * - $view: The view object
 * - $grouping: The grouping instruction.
 * - $grouping_level: Integer indicating the hierarchical level of the grouping.
 * - $rows: The rows contained in this grouping.
 * - $title: The title of this grouping.
 * - $content: The processed content output that will normally be used.
 * 
 * 0 = Child
 * 1 = Grand Child
 */
?>
<?php if($grouping_level == 0){ ?>
    <?php 
      $remove = array(" ","&amp;");
      $replace = array("_","");
      $child = str_replace($remove,$replace, $title); $child = strip_tags($child);
      $child = preg_replace(' ', '', $child);
      $child = trim($child);?>

    <?php print $title; ?>
    <div class="wsshoptabing wtsdepartmentmenu clearfix <?php print $child; ?> ZERO">
        <div class="wsshopwp clearfix">
            <ul class="wstabitem clearfix">
                
                <?php print $content; ?>
                
            </ul>
        </div>

    </div>
    </li> 
<?php } ?>
<?php if($grouping_level == 1){ ?>
    <?php 
      $remove = array(" ","&amp;");
      $replace = array("_","");
      $child = str_replace($remove,$replace, $title); $child = strip_tags($child);
      $child = trim($child);?>
    <?php print $title; ?>
    <div class="wstitemright clearfix wstitemrightactive <?php print $child; ?> ONE">
        <div class="container-fluid">
            <div class="row">
                <?php print $content; ?>
               <!-- -->
               
            </div>
            <div class="here"></div>
        </div>
    </div>
    </li>
<?php } ?>
