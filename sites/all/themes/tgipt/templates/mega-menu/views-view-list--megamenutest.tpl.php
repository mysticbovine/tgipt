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
 <div class="col-md-4 clearfix" style="border: 1px dotted yellow">
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