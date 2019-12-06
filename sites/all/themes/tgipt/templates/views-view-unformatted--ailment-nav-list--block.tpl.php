<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 * Allergies, Inflammation, Antioxidant, Arthritis, Bloating, Bone Health, Oral Health, Cartilage Health, Coat Health, Connective Tissue Health, Digestive Health, Flatulence, Immune Support, Joint Health, Liver Health, Lymph Health, Nervous System Health, Pain Relief, Skin Health, Sleep, Stress Support, Trauma, Worms
 */
?>
<?php if (!empty($title)): ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>
	
		<span class="filter mini btn btn-lg btn-nutra" data-filter=".all">All</span>
		<?php foreach ($rows as $id => $row): ?>
		   <?php print $row; ?>
		<?php endforeach; ?>
