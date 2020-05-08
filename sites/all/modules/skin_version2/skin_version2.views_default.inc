<?php

/**
 * @file
 * skin_version2.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function skin_version2_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'blog';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Blog';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Blog';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_grid_plugin_style';
  $handler->display->display_options['style_options']['columns_horizontal'] = '-1';
  $handler->display->display_options['style_options']['columns_vertical'] = '4';
  $handler->display->display_options['style_options']['columns_xs'] = '12';
  $handler->display->display_options['style_options']['columns_sm'] = '0';
  $handler->display->display_options['style_options']['columns_md'] = '0';
  $handler->display->display_options['style_options']['columns_lg'] = '4';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_class'] = 'img-thumbnail';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'product_details',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h2';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['nl2br'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['preserve_tags'] = '<b<';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '140',
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'article' => 'article',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'blog';
  $translatables['blog'] = array(
    t('Master'),
    t('Blog'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Page'),
  );
  $export['blog'] = $view;

  $view = new view();
  $view->name = 'category_descriptions';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Category Descriptions';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Category Descriptions';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
  /* Field: Taxonomy term: Image */
  $handler->display->display_options['fields']['uc_catalog_image']['id'] = 'uc_catalog_image';
  $handler->display->display_options['fields']['uc_catalog_image']['table'] = 'field_data_uc_catalog_image';
  $handler->display->display_options['fields']['uc_catalog_image']['field'] = 'uc_catalog_image';
  $handler->display->display_options['fields']['uc_catalog_image']['label'] = '';
  $handler->display->display_options['fields']['uc_catalog_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uc_catalog_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['uc_catalog_image']['settings'] = array(
    'image_style' => 'squared',
    'image_link' => 'content',
  );
  /* Field: Taxonomy term: Term description */
  $handler->display->display_options['fields']['description']['id'] = 'description';
  $handler->display->display_options['fields']['description']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['description']['field'] = 'description';
  $handler->display->display_options['fields']['description']['label'] = '';
  $handler->display->display_options['fields']['description']['element_label_colon'] = FALSE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name_1']['id'] = 'name_1';
  $handler->display->display_options['fields']['name_1']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name_1']['field'] = 'name';
  $handler->display->display_options['fields']['name_1']['label'] = '';
  $handler->display->display_options['fields']['name_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['name_1']['alter']['text'] = 'See more';
  $handler->display->display_options['fields']['name_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name_1']['link_to_taxonomy'] = TRUE;
  /* Field: Taxonomy term: Weight */
  $handler->display->display_options['fields']['weight']['id'] = 'weight';
  $handler->display->display_options['fields']['weight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['weight']['field'] = 'weight';
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'catalog' => 'catalog',
  );
  /* Filter criterion: Taxonomy term: Term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['value'] = array(
    0 => '5',
    1 => '7',
    2 => '1',
    3 => '2',
    4 => '3',
  );
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'catalog';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $translatables['category_descriptions'] = array(
    t('Master'),
    t('Category Descriptions'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('See more'),
    t('Weight'),
    t('.'),
    t(','),
    t('Block'),
  );
  $export['category_descriptions'] = $view;

  $view = new view();
  $view->name = 'gallery';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'instagram_social_feed_photos';
  $view->human_name = 'Gallery';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Gallery';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '9';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_grid_plugin_style';
  $handler->display->display_options['style_options']['columns_horizontal'] = '-1';
  $handler->display->display_options['style_options']['columns_vertical'] = '4';
  $handler->display->display_options['style_options']['columns_xs'] = '12';
  $handler->display->display_options['style_options']['columns_sm'] = '6';
  $handler->display->display_options['style_options']['columns_md'] = '4';
  $handler->display->display_options['style_options']['columns_lg'] = '4';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  /* Field: Instagram photo: Instagram_link */
  $handler->display->display_options['fields']['instagram_link']['id'] = 'instagram_link';
  $handler->display->display_options['fields']['instagram_link']['table'] = 'instagram_social_feed_photos';
  $handler->display->display_options['fields']['instagram_link']['field'] = 'instagram_link';
  $handler->display->display_options['fields']['instagram_link']['label'] = '';
  $handler->display->display_options['fields']['instagram_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['instagram_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['instagram_link']['display_as_link'] = FALSE;
  /* Field: Instagram photo: Thumbnail */
  $handler->display->display_options['fields']['thumbnail']['id'] = 'thumbnail';
  $handler->display->display_options['fields']['thumbnail']['table'] = 'instagram_social_feed_photos';
  $handler->display->display_options['fields']['thumbnail']['field'] = 'thumbnail';
  $handler->display->display_options['fields']['thumbnail']['label'] = '';
  $handler->display->display_options['fields']['thumbnail']['exclude'] = TRUE;
  $handler->display->display_options['fields']['thumbnail']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['thumbnail']['alter']['text'] = '<a href="[instagram_link]" target=_blank"><img src="[thumbnail]" class="img-responsive img-thumbnail"><a/>';
  $handler->display->display_options['fields']['thumbnail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['thumbnail']['display_as_link'] = FALSE;
  /* Field: Instagram photo: Standard_resolution */
  $handler->display->display_options['fields']['standard_resolution']['id'] = 'standard_resolution';
  $handler->display->display_options['fields']['standard_resolution']['table'] = 'instagram_social_feed_photos';
  $handler->display->display_options['fields']['standard_resolution']['field'] = 'standard_resolution';
  $handler->display->display_options['fields']['standard_resolution']['label'] = '';
  $handler->display->display_options['fields']['standard_resolution']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['standard_resolution']['alter']['text'] = '<a href="[instagram_link]" target=_blank><img src="[standard_resolution]" class=""></a>';
  $handler->display->display_options['fields']['standard_resolution']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['standard_resolution']['display_as_link'] = FALSE;
  /* Field: Instagram photo: Low_resolution */
  $handler->display->display_options['fields']['low_resolution']['id'] = 'low_resolution';
  $handler->display->display_options['fields']['low_resolution']['table'] = 'instagram_social_feed_photos';
  $handler->display->display_options['fields']['low_resolution']['field'] = 'low_resolution';
  $handler->display->display_options['fields']['low_resolution']['label'] = '';
  $handler->display->display_options['fields']['low_resolution']['exclude'] = TRUE;
  $handler->display->display_options['fields']['low_resolution']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['low_resolution']['alter']['text'] = '<a href="[instagram_link]" target=_blank"><img src="[low_resolution]" class="img-responsive"></a>';
  $handler->display->display_options['fields']['low_resolution']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['low_resolution']['display_as_link'] = FALSE;
  /* Field: Instagram photo: Caption */
  $handler->display->display_options['fields']['caption']['id'] = 'caption';
  $handler->display->display_options['fields']['caption']['table'] = 'instagram_social_feed_photos';
  $handler->display->display_options['fields']['caption']['field'] = 'caption';
  $handler->display->display_options['fields']['caption']['label'] = '';
  $handler->display->display_options['fields']['caption']['exclude'] = TRUE;
  $handler->display->display_options['fields']['caption']['element_label_colon'] = FALSE;
  /* Sort criterion: Instagram photo: Created_time */
  $handler->display->display_options['sorts']['created_time']['id'] = 'created_time';
  $handler->display->display_options['sorts']['created_time']['table'] = 'instagram_social_feed_photos';
  $handler->display->display_options['sorts']['created_time']['field'] = 'created_time';
  $handler->display->display_options['sorts']['created_time']['order'] = 'DESC';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<p>Click image for more details.</p>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['path'] = 'gallery';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Pet Treatery on Instagram';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'TGIPT on Instagram';
  $handler->display->display_options['header']['area']['content'] = '<h2 class="block-title text-center"><a href="https://www.instagram.com/granvilleislandpettreatery/" target="_blank">Pet Treatery on Instagram</a></h2>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Instagram photo: Instagram_link */
  $handler->display->display_options['fields']['instagram_link']['id'] = 'instagram_link';
  $handler->display->display_options['fields']['instagram_link']['table'] = 'instagram_social_feed_photos';
  $handler->display->display_options['fields']['instagram_link']['field'] = 'instagram_link';
  $handler->display->display_options['fields']['instagram_link']['label'] = '';
  $handler->display->display_options['fields']['instagram_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['instagram_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['instagram_link']['display_as_link'] = FALSE;
  /* Field: Instagram photo: Thumbnail */
  $handler->display->display_options['fields']['thumbnail']['id'] = 'thumbnail';
  $handler->display->display_options['fields']['thumbnail']['table'] = 'instagram_social_feed_photos';
  $handler->display->display_options['fields']['thumbnail']['field'] = 'thumbnail';
  $handler->display->display_options['fields']['thumbnail']['label'] = '';
  $handler->display->display_options['fields']['thumbnail']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['thumbnail']['alter']['text'] = '<a href="[instagram_link]" target=_blank"><img src="[thumbnail]" class="img-responsive"><a/>';
  $handler->display->display_options['fields']['thumbnail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['thumbnail']['display_as_link'] = FALSE;
  /* Field: Instagram photo: Standard_resolution */
  $handler->display->display_options['fields']['standard_resolution']['id'] = 'standard_resolution';
  $handler->display->display_options['fields']['standard_resolution']['table'] = 'instagram_social_feed_photos';
  $handler->display->display_options['fields']['standard_resolution']['field'] = 'standard_resolution';
  $handler->display->display_options['fields']['standard_resolution']['label'] = '';
  $handler->display->display_options['fields']['standard_resolution']['exclude'] = TRUE;
  $handler->display->display_options['fields']['standard_resolution']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['standard_resolution']['alter']['text'] = '<a href="[instagram_link]" target=_blank><img src="[standard_resolution]" class=""></a>';
  $handler->display->display_options['fields']['standard_resolution']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['standard_resolution']['display_as_link'] = FALSE;
  /* Field: Instagram photo: Low_resolution */
  $handler->display->display_options['fields']['low_resolution']['id'] = 'low_resolution';
  $handler->display->display_options['fields']['low_resolution']['table'] = 'instagram_social_feed_photos';
  $handler->display->display_options['fields']['low_resolution']['field'] = 'low_resolution';
  $handler->display->display_options['fields']['low_resolution']['label'] = '';
  $handler->display->display_options['fields']['low_resolution']['exclude'] = TRUE;
  $handler->display->display_options['fields']['low_resolution']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['low_resolution']['alter']['text'] = '<a href="[instagram_link]" target=_blank"><img src="[low_resolution]" class="img-responsive"></a>';
  $handler->display->display_options['fields']['low_resolution']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['low_resolution']['display_as_link'] = FALSE;
  /* Field: Instagram photo: Caption */
  $handler->display->display_options['fields']['caption']['id'] = 'caption';
  $handler->display->display_options['fields']['caption']['table'] = 'instagram_social_feed_photos';
  $handler->display->display_options['fields']['caption']['field'] = 'caption';
  $handler->display->display_options['fields']['caption']['label'] = '';
  $handler->display->display_options['fields']['caption']['exclude'] = TRUE;
  $handler->display->display_options['fields']['caption']['element_label_colon'] = FALSE;
  $translatables['gallery'] = array(
    t('Master'),
    t('Gallery'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('<a href="[instagram_link]" target=_blank"><img src="[thumbnail]" class="img-responsive img-thumbnail"><a/>'),
    t('<a href="[instagram_link]" target=_blank><img src="[standard_resolution]" class=""></a>'),
    t('<a href="[instagram_link]" target=_blank"><img src="[low_resolution]" class="img-responsive"></a>'),
    t('Page'),
    t('<p>Click image for more details.</p>'),
    t('Block'),
    t('Pet Treatery on Instagram'),
    t('TGIPT on Instagram'),
    t('<h2 class="block-title text-center"><a href="https://www.instagram.com/granvilleislandpettreatery/" target="_blank">Pet Treatery on Instagram</a></h2>'),
    t('<a href="[instagram_link]" target=_blank"><img src="[thumbnail]" class="img-responsive"><a/>'),
  );
  $export['gallery'] = $view;

  $view = new view();
  $view->name = 'latest_blog_teaser';
  $view->description = 'For home page.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Latest Blog teaser';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Latest Blog teaser';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'Latest Blog teaser';
  $handler->display->display_options['header']['area']['content'] = '<h2 class="block-title"><a href="/blog">Latest Blog teaser</a></h2>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'article' => 'article',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $translatables['latest_blog_teaser'] = array(
    t('Master'),
    t('Latest Blog teaser'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('<h2 class="block-title"><a href="/blog">Latest Blog teaser</a></h2>'),
    t('Block'),
  );
  $export['latest_blog_teaser'] = $view;

  $view = new view();
  $view->name = 'new_products';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'New Products';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Just Added';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '8';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_grid_plugin_style';
  $handler->display->display_options['style_options']['columns_horizontal'] = '-1';
  $handler->display->display_options['style_options']['columns_vertical'] = '3';
  $handler->display->display_options['style_options']['columns_xs'] = '12';
  $handler->display->display_options['style_options']['columns_sm'] = '6';
  $handler->display->display_options['style_options']['columns_md'] = '3';
  $handler->display->display_options['style_options']['columns_lg'] = '3';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: for css */
  $handler->display->display_options['fields']['taxonomy_catalog_1']['id'] = 'taxonomy_catalog_1';
  $handler->display->display_options['fields']['taxonomy_catalog_1']['table'] = 'field_data_taxonomy_catalog';
  $handler->display->display_options['fields']['taxonomy_catalog_1']['field'] = 'taxonomy_catalog';
  $handler->display->display_options['fields']['taxonomy_catalog_1']['ui_name'] = 'for css';
  $handler->display->display_options['fields']['taxonomy_catalog_1']['label'] = '';
  $handler->display->display_options['fields']['taxonomy_catalog_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['taxonomy_catalog_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['taxonomy_catalog_1']['alter']['text'] = 'category[taxonomy_catalog_1-tid]';
  $handler->display->display_options['fields']['taxonomy_catalog_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['taxonomy_catalog_1']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['taxonomy_catalog_1']['delta_offset'] = '0';
  /* Field: Content: Catalog */
  $handler->display->display_options['fields']['taxonomy_catalog']['id'] = 'taxonomy_catalog';
  $handler->display->display_options['fields']['taxonomy_catalog']['table'] = 'field_data_taxonomy_catalog';
  $handler->display->display_options['fields']['taxonomy_catalog']['field'] = 'taxonomy_catalog';
  $handler->display->display_options['fields']['taxonomy_catalog']['label'] = '';
  $handler->display->display_options['fields']['taxonomy_catalog']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['taxonomy_catalog']['alter']['text'] = '<h3 class="[taxonomy_catalog_1]">[taxonomy_catalog]</h3>';
  $handler->display->display_options['fields']['taxonomy_catalog']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['taxonomy_catalog']['delta_limit'] = '1';
  $handler->display->display_options['fields']['taxonomy_catalog']['delta_offset'] = '0';
  /* Field: Content: Image */
  $handler->display->display_options['fields']['uc_product_image']['id'] = 'uc_product_image';
  $handler->display->display_options['fields']['uc_product_image']['table'] = 'field_data_uc_product_image';
  $handler->display->display_options['fields']['uc_product_image']['field'] = 'uc_product_image';
  $handler->display->display_options['fields']['uc_product_image']['label'] = '';
  $handler->display->display_options['fields']['uc_product_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uc_product_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['uc_product_image']['settings'] = array(
    'image_style' => '',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['uc_product_image']['delta_limit'] = '1';
  $handler->display->display_options['fields']['uc_product_image']['delta_offset'] = '0';
  /* Field: Product: Display price */
  $handler->display->display_options['fields']['display_price']['id'] = 'display_price';
  $handler->display->display_options['fields']['display_price']['table'] = 'uc_products';
  $handler->display->display_options['fields']['display_price']['field'] = 'display_price';
  $handler->display->display_options['fields']['display_price']['label'] = '';
  $handler->display->display_options['fields']['display_price']['element_class'] = 'dispaly-price [taxonomy_catalog_1]';
  $handler->display->display_options['fields']['display_price']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<h2 class="[taxonomy_catalog_1]">[title]</h2>';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_class'] = '[taxonomy_catalog_1]';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Ailment */
  $handler->display->display_options['fields']['field_aliment']['id'] = 'field_aliment';
  $handler->display->display_options['fields']['field_aliment']['table'] = 'field_data_field_aliment';
  $handler->display->display_options['fields']['field_aliment']['field'] = 'field_aliment';
  $handler->display->display_options['fields']['field_aliment']['label'] = '';
  $handler->display->display_options['fields']['field_aliment']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_aliment']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_aliment']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_aliment']['delta_offset'] = '0';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['text'] = '[body]';
  $handler->display->display_options['fields']['body']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '140';
  $handler->display->display_options['fields']['body']['alter']['more_link_text'] = 'More';
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['preserve_tags'] = '<b> <strong> <br> <em>';
  $handler->display->display_options['fields']['body']['alter']['html'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_wrapper_type'] = 'p';
  /* Field: Product: Buy it now button */
  $handler->display->display_options['fields']['buyitnowbutton']['id'] = 'buyitnowbutton';
  $handler->display->display_options['fields']['buyitnowbutton']['table'] = 'uc_products';
  $handler->display->display_options['fields']['buyitnowbutton']['field'] = 'buyitnowbutton';
  $handler->display->display_options['fields']['buyitnowbutton']['label'] = '';
  $handler->display->display_options['fields']['buyitnowbutton']['exclude'] = TRUE;
  $handler->display->display_options['fields']['buyitnowbutton']['element_label_colon'] = FALSE;
  /* Field: Content: Link to content */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['view_node']['alter']['link_class'] = 'field-content list-add-to-cart btn btn-black geared-reg form-submit';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['element_wrapper_type'] = 'p';
  $handler->display->display_options['fields']['view_node']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'Select';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'product' => 'product',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Catalog (taxonomy_catalog) */
  $handler->display->display_options['filters']['taxonomy_catalog_tid']['id'] = 'taxonomy_catalog_tid';
  $handler->display->display_options['filters']['taxonomy_catalog_tid']['table'] = 'field_data_taxonomy_catalog';
  $handler->display->display_options['filters']['taxonomy_catalog_tid']['field'] = 'taxonomy_catalog_tid';
  $handler->display->display_options['filters']['taxonomy_catalog_tid']['operator'] = 'not';
  $handler->display->display_options['filters']['taxonomy_catalog_tid']['value'] = array(
    0 => '197',
  );
  $handler->display->display_options['filters']['taxonomy_catalog_tid']['vocabulary'] = 'catalog';

  /* Display: Newest */
  $handler = $view->new_display('block', 'Newest', 'block');

  /* Display: Popular */
  $handler = $view->new_display('block', 'Popular', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Popular Products';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content statistics: Total views */
  $handler->display->display_options['sorts']['totalcount']['id'] = 'totalcount';
  $handler->display->display_options['sorts']['totalcount']['table'] = 'node_counter';
  $handler->display->display_options['sorts']['totalcount']['field'] = 'totalcount';
  $handler->display->display_options['sorts']['totalcount']['order'] = 'DESC';

  /* Display: Featured */
  $handler = $view->new_display('block', 'Featured', 'block_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Featured Products';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Sticky status */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
  /* Sort criterion: Content: Updated date */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'node';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  $translatables['new_products'] = array(
    t('Master'),
    t('Just Added'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('category[taxonomy_catalog_1-tid]'),
    t('<h3 class="[taxonomy_catalog_1]">[taxonomy_catalog]</h3>'),
    t('.'),
    t(','),
    t('<h2 class="[taxonomy_catalog_1]">[title]</h2>'),
    t('[body]'),
    t('More'),
    t('Select'),
    t('Newest'),
    t('Popular'),
    t('Popular Products'),
    t('Featured'),
    t('Featured Products'),
  );
  $export['new_products'] = $view;

  $view = new view();
  $view->name = 'shop_parent';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Shop Parent';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Shop Parent';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Contextual filter: Content: Has taxonomy term ID (with depth) */
  $handler->display->display_options['arguments']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['arguments']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_action'] = 'default';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_options']['node'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_options']['limit'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_options']['vocabularies'] = array(
    'catalog' => 'catalog',
  );
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['term_node_tid_depth']['depth'] = '1';
  /* Filter criterion: Content: Published status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'product' => 'product',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'shop-parent/%';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $translatables['shop_parent'] = array(
    t('Master'),
    t('Shop Parent'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('All'),
    t('Page'),
    t('Block'),
  );
  $export['shop_parent'] = $view;

  $view = new view();
  $view->name = 'testimonials';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Testimonials';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Testimonials';
  $handler->display->display_options['css_class'] = 'container hidden-xs';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_grid_plugin_style';
  $handler->display->display_options['style_options']['columns_horizontal'] = '-1';
  $handler->display->display_options['style_options']['columns_vertical'] = '12';
  $handler->display->display_options['style_options']['columns_xs'] = '12';
  $handler->display->display_options['style_options']['columns_sm'] = '0';
  $handler->display->display_options['style_options']['columns_md'] = '0';
  $handler->display->display_options['style_options']['columns_lg'] = '12';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<h2 class="text-center">Healthy pets sit, stay and wag tails as their enthusiastic owners tell us why Pet Treatery is the most trusted one-stop shop for Nutra Bites&trade;.</h2>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<p class="text-center"><a href="/about/testimonials" class="btn btn-black btn-lg geared-regular">Read more testimonials</a></p>';
  $handler->display->display_options['footer']['area']['format'] = 'full_html';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['preserve_tags'] = '<b> <strong> <br> <em>';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '<div class="testimonial">

[body]

<h3>[title]</h3>
</div>';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  /* Filter criterion: Content: Published status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'testimonial' => 'testimonial',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['path'] = 'about/testimonials';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_grid_plugin_style';
  $handler->display->display_options['style_options']['columns_horizontal'] = '-1';
  $handler->display->display_options['style_options']['columns_vertical'] = '4';
  $handler->display->display_options['style_options']['columns_xs'] = '12';
  $handler->display->display_options['style_options']['columns_sm'] = '6';
  $handler->display->display_options['style_options']['columns_md'] = '4';
  $handler->display->display_options['style_options']['columns_lg'] = '4';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '200';
  $handler->display->display_options['fields']['body']['alter']['more_link_text'] = 'more';
  $handler->display->display_options['fields']['body']['alter']['more_link_path'] = 'testimonials';
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['preserve_tags'] = '<b> <strong> <br> <em>';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: layout */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'layout';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="testimonial hidden-xs">
<div class="quote left hidden">&ldquo;</div>
[body]
<div class="quote right hidden">&rdquo;</div>
<h3>[title]</h3>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $translatables['testimonials'] = array(
    t('Master'),
    t('Testimonials'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('<h2 class="text-center">Healthy pets sit, stay and wag tails as their enthusiastic owners tell us why Pet Treatery is the most trusted one-stop shop for Nutra Bites&trade;.</h2>'),
    t('<p class="text-center"><a href="/about/testimonials" class="btn btn-black btn-lg geared-regular">Read more testimonials</a></p>'),
    t('<div class="testimonial">

[body]

<h3>[title]</h3>
</div>'),
    t('Page'),
    t('Block'),
    t('<div class="testimonial hidden-xs">
<div class="quote left hidden">&ldquo;</div>
[body]
<div class="quote right hidden">&rdquo;</div>
<h3>[title]</h3>
</div>'),
  );
  $export['testimonials'] = $view;

  return $export;
}
