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
 *
 * 9:44pm)
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
			<div class="row">
				<div class="col-sm-12 topbar">
					<ul class="menu nav navbar-nav">
						<li><a href="/cart">Cart: 
						<?php  
							if(!isset($cid)) {$cid = NULL;}
							$item = uc_cart_get_total_qty($cid);
							if($item == 0) {
								echo " 0 items";
							} else {
							
								 if ($item == 1) {
									
									echo " $item item";
								 } else {
									echo "$item items";
								 } 
							} ?>
						</a></li>
					
					
						<?php 
							if (user_is_logged_in()){
								echo "<li><a href='/user/logout'>Log out</a></li>  <li><a href='/user'>View your account</a></li> ";
							} else {
								echo "<li><a href='/user'>Log in </a></li>  <li><a href='/user/register'>Sign up</a></li> ";	
							}?>
							<li><a href="tel:+16046893647"><span class="phonenumber">Phone us: 1-604-882-7505</span></a></li> 
							<li class="last expanded dropdown hidden"><a href="/contact" class="dropdown-toggle" data-toggle="dropdown" aria-expanded="false">Contact <span class="caret"></span></a>
								<ul class="dropdown-menu">
									<li class="first leaf"><a href="/contact" title="">Contact</a></li>
									<li class="last leaf"><a href="/charity-community-support">Charity &amp; Community</a></li>
								</ul>
							</li>
							<li><a href="/blog">Blog</a></li> 
							<li><a href="/our-distributors">Our Distributors</a></li> 
							<li><a href="/retailers-carrying-our-treats">Our Retailers</a></li>
							<li class="first expanded dropdown hidden"><a href="/why-granville-island-pet-treatery" class="dropdown-toggle" data-toggle="dropdown">Why Us? <span class="caret"></span></a>
								<ul class="dropdown-menu"><li class="first leaf"><a href="/why-granville-island-pet-treatery" title="">Why Pet Treatery?</a></li>
									<li class="leaf"><a href="/why-pet-treatery/our-vision-mission-values">Our Vision, Mission and Values</a></li>
									<li class="leaf"><a href="/why-pet-treatery/recipes-and-ingredients">Recipes and Ingredients</a></li>
									<li class="leaf"><a href="/why-pet-treatery/caboose">The Caboose</a></li>
									<li class="leaf"><a href="/about/testimonials" title="">Testimonials</a></li>
									<li class="last leaf"><a href="/why-tgipt/faq">FAQ</a></li>
								</ul>
							</li>
							<li><a href="/"><i class="fa fa-home" aria-hidden="true"></i> Home</a></li> 
					
					
				</div>
			</div>
			
			<!-- Newsletter -->
			<div class="row">
				<div class="col-sm-12 newslettersignup">
					<div id="mc_embed_signup" class="">
						<form action="//wooflesandmeowz.us7.list-manage.com/subscribe/post?u=7b318c8879e4e7974840119f6&amp;id=1e3329cad6" 
						method="post" id="mc-embedded-subscribe-form" name="mc-embedded-subscribe-form" class="validate" target="_blank" novalidate>
							<div id="mc_embed_signup_scroll">
								<h2 class="hidden">Join our Newsletter</h2>
								<label for="mce-EMAIL" class="hidden">Join our Newsletter</label>
								<h3>Join our mailing list <span class="hidden-xs hidden-sm">for a chance to win FREE healthy pet treats! </span></h3>
								<div class="fields">
									<input type="email" value="" name="EMAIL" class="email" id="mce-EMAIL" placeholder="Email" required>
									<!-- real people should not fill this in and expect good things - do not remove this or risk form bot signups-->
									<div style="position: absolute; left: -5000px;" aria-hidden="true"><input type="text" name="b_7b318c8879e4e7974840119f6_1e3329cad6" tabindex="-1" value=""></div>
									<button type="submit" value="Subscribe" name="subscribe" id="mc-embedded-subscribe" class="btn btn-default">Subscribe</button>
								</div>
							</div>
						</form>
					</div>
				</div>
			</div>
				<!-- end -->

			 <div class="row">
				<nav role="navigation" class="mainmenu">
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
			</div>
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
      <?php print $messages; ?>
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
<div class="container teaser">
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

<?php if (!empty($page['footer'])): ?>
  <footer class="footer <?php print $container_class; ?>">
	

		<?php print render($page['footer']); ?>

  </footer>
<?php endif; ?>
v