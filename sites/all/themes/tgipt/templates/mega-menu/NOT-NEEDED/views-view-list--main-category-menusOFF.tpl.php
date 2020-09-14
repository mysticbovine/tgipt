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
<!-- WRAPS AROUND THE GRANDCHILDREN AND THE PRODCUTS -->
<ul> THIS IS NOT NEEDED
    <?php print $wrapper_prefix; ?>
    <?php if (!empty($title)) : ?>
        <li><?php print $title; ?></li>
    <?php endif; ?>
    <?php print $list_type_prefix; ?>
        <ul> HELLO?????
        <?php foreach ($rows as $id => $row): ?>
        <li class="<?php print $classes_array[$id]; ?>"><?php print $row; ?> BBB </li>
        <?php endforeach; ?>
        </ul>
    <?php print $list_type_suffix; ?>
    <?php print $wrapper_suffix; ?>
</ul>
