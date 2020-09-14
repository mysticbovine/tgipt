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
    <?php print $title; ?>
    <div class="wsshoptabing wtsdepartmentmenu clearfix">
        <div class="wsshopwp clearfix">
            <ul class="wstabitem clearfix">
                CHILD
                <?php print $content; ?>
            </ul>
        </div>
    </div>
    </li> 
<?php } ?>
<?php if($grouping_level == 1){ ?>
    <?php print $title; ?>
    <div class="wstitemright clearfix wstitemrightactive">
        <div class="container-fluid">
            <div class="row" style="border:1px solid pink;">
                <!-- WRAPS GRANDCHILD -->
                <?php print $content; ?>
            </div>
        </div>
    </div>
    </li>
<?php } ?>
<?php if($grouping_level == 2){ ?>
    TWO??!!
    <?php } ?>