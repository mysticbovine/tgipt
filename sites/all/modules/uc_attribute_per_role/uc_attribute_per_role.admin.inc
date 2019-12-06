<?php
/**
 * @file
 * Administration page callbacks and form handlers for uc_attribute_per_role.
 */

/**
 * Displays a list of all definitions in a table.
 */
function uc_attribute_per_role_list() {
	$MAX_DISPLAYED_ATTR = 3;

	$header = array(
	t('Role'),
	t('Hidden Attributes'),
	t('Operations'),
	);

	$links = array('operations' => array('title' => 'Edit', 'href' => 'edit'));

	$roles = user_roles();
	$available_roles = uc_attribute_per_role_get_roles_defined();
	if ($available_roles) {
		foreach ($available_roles as $role_id) {
			$definition = uc_attribute_per_role_definition_load($role_id);
				
			$edit_url = 'admin/store/settings/attributes_per_role/' . $role_id . '/edit';
			$reset_url = 'admin/store/settings/attributes_per_role/' . $role_id . '/reset';
			$linklist = array(
        'edit' => array('title' => t('Edit'), 'href' => $edit_url),
        'reset' => array('title' => t('Reset'), 'href' => $reset_url),
			);

			// Load up to $MAX_DISPLAYED_ATTR attribute names, separated by a comma
			// Append 'X more' if more than $MAX_DISPLAYED_ATTR exist
			$summary_ids = array_slice($definition['attribute_ids'], 0, $MAX_DISPLAYED_ATTR);
			if ($summary_ids) {
				foreach (uc_attribute_load_multiple($summary_ids) as $attribute) {
					$summary_names[] = $attribute->name;
				}
				if (count($definition['attribute_ids']) > $MAX_DISPLAYED_ATTR) {
					$many_left = count($definition['attribute_ids']) - $MAX_DISPLAYED_ATTR;
					$summary_names[] = t('!number more', array('!number' => $many_left));
				}
				$summary_text = implode(', ', $summary_names);
			}
			else {
				$summary_text = t('None');
			}

			// Create the row array and add it to the list of all rows
			$row = array();
			$row[] = check_plain($roles[$role_id]);
			$row[] = check_plain($summary_text);
			$row[] = theme('links', array('links' => $linklist));
			$rows[] = $row;
		}
	}
	else {
		$rows[] = array(array('data' => t('No definitions found.'), 'colspan' => count($header)));
	}

	return theme('table', array('header' => $header, 'rows' => $rows));
}

/**
 * Displays a definition edit form to the user. If $target_role_id is set, then
 * form's initial values are loaded from the existing definition. If it is set
 * to NULL, then the default values are used.
 */
function uc_attribute_per_role_edit($form, $form_state, $target_role_id = NULL) {
	$roles = user_roles();

	if (isset($target_role_id)) {
		// We will be updating an existing definition
		$definition = uc_attribute_per_role_definition_load($target_role_id);
		if ($definition === FALSE) {
			// If we could not load a definition, it either does not exist or the role does not exist.
			if (isset($roles[$target_role_id])) {
				drupal_set_message(t('Role display settings for <em>@role</em> were not found in the database.', array('@role' => $roles[$target_role_id])), 'error');
			}
			else {
				drupal_set_message(t('Role #@role does not exist.', array('@role' => $target_role_id)), 'error');
			}
			drupal_goto('admin/store/settings/attributes_per_role');
		}

		// Force the selection of this role.
		$available_roles = array($target_role_id => $roles[$target_role_id]);
	}
	else {
		// We will be adding a new definition. $definition is just a generated array
		// and isn't in the database. It will just be used for setting form values.
		$definition = uc_attribute_per_role_definition_new();

		// User should only add definitions for roles without an existing definition
		$defined = uc_attribute_per_role_get_roles_defined();
		$available_roles = array();
		foreach ($roles as $role_id => $role_name) {
			if (!in_array($role_id, $defined)) {
				$available_roles[$role_id] = $role_name;
			}
		}

		// Set the role_id attribute so that the select gets a default value
		reset($available_roles);
		$definition['role_id'] = key($available_roles);
	}

	// Generate the list of all attributes
	$result = db_select('uc_attributes', 'ua')->fields('ua', array('aid', 'name'))->execute();
	while ($attribute = $result->fetchObject()) {
		$attributes[$attribute->aid] = check_plain($attribute->name);
	}

	$form = array();

	if (!empty($attributes)) {

		$form['action'] = array(
    '#type' => 'hidden',
    '#value' => isset($target_role_id) ? 'update' : 'add',
		);

		$form['role'] = array(
    '#type' => 'select',
    '#title' => t('Role'),
    '#default_value' => $definition['role_id'],
    '#options' => $available_roles,
    '#disabled' => isset($target_role_id),
    '#required' => TRUE,
    '#description' => t('Select the role for which you want to control the display of attributes.'),
		);

		$form['attributes'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Hide these attributes'),
    '#default_value' => $definition['attribute_ids'],
    '#options' => $attributes,
    '#required' => TRUE,
    '#description' => t('Select any attributes you wish to hide for users of this role.'),
		);

		$form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save changes'),
		);
	}

	else {
		$form['attribute_markup'] = array(
		  '#type' => 'item',
		  '#markup' => '<div> There is no attribute defined. Please add the attribute. ' . l(t('Add attribute'), 'admin/store/products/attributes') . '</div>',
		);

	}

	return $form;
}

/**
 * Submit handler for uc_attribute_per_role_edit().
 */
function uc_attribute_per_role_edit_submit($form, &$form_state) {
	// Create or load the definition depending on the current action
	$role_id = $form_state['values']['role'];
	if ($form_state['values']['action'] == 'add') {
		$definition = uc_attribute_per_role_definition_new();
		$definition['role_id'] = $role_id;
	}
	else {
		$definition = uc_attribute_per_role_definition_load($role_id);
	}

	// We only need the attribute IDs of the checkboxes, not their form value
	$attributes = array();
	foreach ($form_state['values']['attributes'] as $attribute => $value) {
		if ($value !== 0) {
			$attributes[] = $attribute;
		}
	}
	$definition['attribute_ids'] = $attributes;

	// Save changes and rediect back to the definitions page
	uc_attribute_per_role_definition_save($definition);
	$form_state['redirect'] = 'admin/store/settings/attributes_per_role';
}

/**
 * Build the reset confirmation form.
 *
 * A simple wrapper around Drupal's core confirm_form() function. Adds a value
 * field to store the ID of the role whose display settings are being reset.
 */
function uc_attribute_per_role_reset_confirm($form, $form_state, $role_id) {
	$roles = user_roles();

	$form['role_id'] = array(
    '#type' => 'value',
    '#value' => $role_id,
	);

	return confirm_form($form,
	t('Are you sure you want to reset the attribute display settings for role <em>:role</em>?', array(':role' => $roles[$role_id])),
	isset($_GET['destination']) ? $_GET['destination'] : 'admin/store/settings/attributes_per_role',
	t('This action cannot be undone.'),
	t('Reset'),
	t('Cancel')
	);
}

/**
 * Submit handler for uc_attribute_per_role_reset_confirm().
 */
function uc_attribute_per_role_reset_confirm_submit($form, &$form_state) {
	if ($form_state['values']['confirm']) {
		$roles = user_roles();
		$role_id = $form_state['values']['role_id'];
		uc_attribute_per_role_definition_delete($role_id);
		drupal_set_message(t('Attribute display settings for role <em>@role</em> have been reset.', array('@role' => $roles[$role_id])));
	}
	$form_state['redirect'] = 'admin/store/settings/attributes_per_role';
}
