<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * - $title : The title of this group of rows.  May be empty.
 * - $options['type'] will either be ul or ol.
 *
 * @ingroup views_templates
 */
?>

<?php 
      $remove = array(" ","&amp;");
      $replace = array("_","");
      $grandchild = str_replace($remove,$replace, $title); 
      $grandchild = strip_tags($grandchild);
      $grandchild = trim($grandchild);
      ?>
<!--<?php print $child; ?>-->
 <div class="col-md-4 clearfix <?php print $grandchild; ?>">
<?php print $wrapper_prefix; ?>
  <?php if (!empty($title)) : ?>

    <?php print $title; ?>
  <?php endif; ?>
   
      <ul class="wstliststy02 clearfix">
        <?php foreach ($rows as $id => $row): ?>
        <?php /* PRODUCTS */?>
          <?php print $row; ?>
        <?php endforeach; ?>
      </ul>
<?php print $wrapper_suffix; ?>
</div>