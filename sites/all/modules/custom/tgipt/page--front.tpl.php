<?php
/**
 * @file
 * Default theme implementation to display a single Drupal page.
 *
 * The doctype, html, head and body tags are not in this template. Instead they
 * can be found in the html.tpl.php template in this directory.
 *
 * Available variables:
 *
 * General utility variables:
 * - $base_path: The base URL path of the Drupal installation. At the very
 *   least, this will always default to /.
 * - $directory: The directory the template is located in, e.g. modules/system
 *   or themes/bartik.
 * - $is_front: TRUE if the current page is the front page.
 * - $logged_in: TRUE if the user is registered and signed in.
 * - $is_admin: TRUE if the user has permission to access administration pages.
 *
 * Site identity:
 * - $front_page: The URL of the front page. Use this instead of $base_path,
 *   when linking to the front page. This includes the language domain or
 *   prefix.
 * - $logo: The path to the logo image, as defined in theme configuration.
 * - $site_name: The name of the site, empty when display has been disabled
 *   in theme settings.
 * - $site_slogan: The slogan of the site, empty when display has been disabled
 *   in theme settings.
 *
 * Navigation:
 * - $main_menu (array): An array containing the Main menu links for the
 *   site, if they have been configured.
 * - $secondary_menu (array): An array containing the Secondary menu links for
 *   the site, if they have been configured.
 * - $breadcrumb: The breadcrumb trail for the current page.
 *
 * Page content (in order of occurrence in the default page.tpl.php):
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title: The page title, for use in the actual HTML content.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 * - $messages: HTML for status and error messages. Should be displayed
 *   prominently.
 * - $tabs (array): Tabs linking to any sub-pages beneath the current page
 *   (e.g., the view and edit tabs when displaying a node).
 * - $action_links (array): Actions local to the page, such as 'Add menu' on the
 *   menu administration interface.
 * - $feed_icons: A string of all feed icons for the current page.
 * - $node: The node object, if there is an automatically-loaded node
 *   associated with the page, and the node ID is the second argument
 *   in the page's path (e.g. node/12345 and node/12345/revisions, but not
 *   comment/reply/12345).
 *
 * Regions:
 * - $page['help']: Dynamic help text, mostly for admin pages.
 * - $page['highlighted']: Items for the highlighted content region.
 * - $page['content']: The main content of the current page.
 * - $page['sidebar_first']: Items for the first sidebar.
 * - $page['sidebar_second']: Items for the second sidebar.
 * - $page['header']: Items for the header region.
 * - $page['footer']: Items for the footer region.
 *
 * @see bootstrap_preprocess_page()
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see bootstrap_process_page()
 * @see template_process()
 * @see html.tpl.php
 *
 * @ingroup templates
 */
?>
<header id="navbar" role="banner" class="<?php print $navbar_classes; ?>">
  <div class="<?php print $container_class; ?>">
	  <div class="logo col-sm-2">
	  	<div class="navbar-header">
		  <?php if ($logo): ?>
			<a class="logo navbar-btn pull-left" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>">
			  <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" class="img-responsive"/>
			</a>
		  <?php endif; ?>

		  <?php if (!empty($site_name)): ?>
			<a class="name navbar-brand" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>"><?php print $site_name; ?></a>
		  <?php endif; ?>

		  <?php if (!empty($primary_nav) || !empty($secondary_nav) || !empty($page['navigation'])): ?>
			<button type="button" class="navbar-toggle" data-toggle="collapse" data-target=".navbar-collapse">
			  <span class="sr-only"><?php print t('Toggle navigation'); ?></span>
			  <span class="menu-hint"><?php print t('Menu'); ?></span>
			  <span class="icon-bar"></span>
			  <span class="icon-bar"></span>
			  <span class="icon-bar"></span>
			</button>
		  <?php endif; ?>
		</div>
	  
	  </div>
	  <div class="menu col-sm-10">
	
	<div class="navbar-collapse collapse">
		<?php if (!empty($primary_nav) || !empty($secondary_nav) || !empty($page['navigation'])): ?>

			<!-- newsletter and shopping cart here -->
		
			<div class="col-sm-2 account">
			<a href="/cart">
			<?php  
				if(!isset($cid)) {$cid = NULL;}
				$item = uc_cart_get_total_qty($cid);
				if($item == 0) {
					echo "<img src='/sites/all/themes/tgipt/img/empty.png' alt='Your cart is empty'>
							<br />Your&nbsp;cart&nbsp;is empty.";
				} else {
					echo "<img src='/sites/all/themes/tgipt/img/items.png' alt='You have $item " ;
					 if ($item == 1) {
						echo "item in your cart.'>
						<br />$item item in your cart.";
					 } else {
						Echo "items in your cart.'>
						<br />$item items in your cart.";
					 }
				} 
			?>
			</a>
			</div>
			<div class="col-sm-2 account login">
				<?php 
					if (user_is_logged_in()){
						echo "<a href='/user/logout'>Log out</a> | <a href='/user'>View your account</a>";
					} else {
						echo "<a href='/user'>Log in </a> | <a href='/user/register'>Sign up</a>";	
					}								
				?><br />
				<span class="phonenumber">Phone us: <a href="tel:+16046893647">1-604-689-3647</a></span>
			</div>

		  
			<nav role="navigation">
			  <?php if (!empty($primary_nav)): ?>
				<?php print render($primary_nav); ?>
			  <?php endif; ?>
			  <?php if (!empty($secondary_nav)): ?>
				<?php print render($secondary_nav); ?>
			  <?php endif; ?>
			  <?php if (!empty($page['navigation'])): ?>
				<?php print render($page['navigation']); ?>
			  <?php endif; ?>
			</nav>
	  
		<?php endif; ?>
    </div>
  
	  
	  </div>


  </div>
</header>
<div class="main-site">
	<?php if (!empty($page['highlighted'])): ?>
		
			<?php print render($page['highlighted']); ?>
	
	<?php endif; ?>
	<?php if (!empty($breadcrumb)): ?>
		<div class="container-fluid breadcrumb-fluid">
			<div class="container">
				<?php	print $breadcrumb; ?>
			</div>
		</div>
	<?php endif;?>
<div class="main-container container">

  <header role="banner" id="page-header">
    <?php if (!empty($site_slogan)): ?>
      <p class="lead"><?php print $site_slogan; ?></p>
    <?php endif; ?>
 <?php print render($page['header']); ?>
  
  </header> <!-- /#page-header -->

  <div class="row">

    <?php if (!empty($page['sidebar_first'])): ?>
      <aside class="col-sm-3" role="complementary">
        <?php print render($page['sidebar_first']); ?>
      </aside>  <!-- /#sidebar-first -->
    <?php endif; ?>

    <section<?php print $content_column_class; ?>>
    
      
      <a id="main-content"></a>
      <?php print render($title_prefix); ?>
      <?php if (!empty($title)): ?>
        <h1 class="page-header"><?php print $title; ?></h1>
      <?php endif; ?>
      <?php print render($title_suffix); ?>
      <?php print $messages; ?> <!-- MESSAGE HERE page--front -->
      <?php if (!empty($tabs)): ?>
        <?php print render($tabs); ?>
      <?php endif; ?>
      <?php if (!empty($page['help'])): ?>
        <?php print render($page['help']); ?>
      <?php endif; ?>
      <?php if (!empty($action_links)): ?>
        <ul class="action-links"><?php print render($action_links); ?></ul>
      <?php endif; ?>
      <?php print render($page['content']); ?>
    </section>

    <?php if (!empty($page['sidebar_second'])): ?>
      <aside class="col-sm-3" role="complementary">
        <?php print render($page['sidebar_second']); ?>
      </aside>  <!-- /#sidebar-second -->
    <?php endif; ?>

  </div>
</div>
</div>
<?php if (!empty($page['abovefooter'])): ?>
	<div class="container-fluid abovefooter">
		<?php print render($page['abovefooter']); ?>
	</div>
<?php endif; ?>
<div class="container">
	<div class="row">
		<div class="col-sm-4">
				<?php print render($page['abovefooter1']); ?>
		</div>
		<div class="col-sm-4">
				<?php print render($page['abovefooter2']); ?>
		</div>
		<div class="col-sm-4">
				<?php print render($page['abovefooter3']); ?>
		</div>
	</div>
</div>
<div class="value hidden">
	<h3 class="mission">Our <span>CORE VALUE</span> is the <span>COMPASSIONATE</span>, <span>HUMANE</span> & <span>LOVING</span> treatment of animals.</h3>
	<h3 class="mission big"><span>1%</span> OF ALL SALES GO TO <img src="/sites/all/themes/tgipt/img/bcspca.png" alt="BCSPCA logo"></h3>
</div>
<?php if (!empty($page['footer'])): ?>
  <footer class="footer <?php print $container_class; ?>">
	

		<?php print render($page['footer']); ?>

  </footer>
<?php endif; ?>
