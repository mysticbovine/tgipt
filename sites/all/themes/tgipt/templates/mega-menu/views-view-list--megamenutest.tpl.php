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

      $productCount = count($rows);
      if ($productCount >= 10){
        $class= "col-md-8";
        $productLayout = "column-count:2";
      } else {
        $class = "col-md-4";
        $productLayout = "column-count:1";
      }
      ?>
<!--<?php print $child; ?>-->

 <div class="<?php print $class; ?> clearfix <?php print $grandchild; ?> ">
<?php print $wrapper_prefix; ?>
  <?php if (!empty($title)) : ?>

    <?php print $title; ?>
  <?php endif; ?>

      <ul class="wstliststy02 clearfix" style="<?php print $productLayout; ?>" >
        <?php foreach ($rows as $id => $row): ?>
        
        <?php /* PRODUCTS */?>
 
          <?php print $row; ?>

        <?php endforeach; ?>
      </ul>
<?php print $wrapper_suffix; ?>
</div>