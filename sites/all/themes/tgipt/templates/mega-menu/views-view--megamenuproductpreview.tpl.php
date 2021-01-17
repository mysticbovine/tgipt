<?php

/**
 * @file
 * Main view template.
 *
 * Variables available:
 * - $classes_array: An array of classes determined in
 *   template_preprocess_views_view(). Default classes are:
 *     .view
 *     .view-[css_name]
 *     .view-id-[view_name]
 *     .view-display-id-[display_name]
 *     .view-dom-id-[dom_id]
 * - $classes: A string version of $classes_array for use in the class attribute
 * - $css_name: A css-safe version of the view name.
 * - $css_class: The user-specified classes names, if any
 * - $header: The view header
 * - $footer: The view footer
 * - $rows: The results of the view query, if any
 * - $empty: The empty text to display if the view is empty
 * - $pager: The pager next/prev links to display, if any
 * - $exposed: Exposed widget form/info to display
 * - $feed_icon: Feed icon to display, if any
 * - $more: A link to view more, if any.
 *
 * @ingroup views_templates
 */
?>
<style>
  ul.wstliststy02 span, li.wsshoplink-active a {
    DISPLAY: block;
}

</style>
<script>
jQuery(document).ready(function($) {
	(function ($) {
   
    console.log( "ready!" );
    // $(".product-preview").hide();
    $( "li.wsshoplink-active a" ).click(function( event ) {
        console.log("prevent");
        event.preventDefault();
      });
    $("ul.wstliststy02 span").click(function() { // The Product id
    //$("li.child div").click(function() { // This gets the GrandChild
    // $("li.child.wsshoplink-active div").click(function() {  //Gets the Child
      var myClass, oldClass;
      console.log("myClass start.");
        console.log(myClass);
        
      if(typeof myClass == 'undefined'){
        // get my the prview and set as myClass
        console.log("myClass empty");
        console.log(myClass);

        myClass = $(this).attr("class");
        oldClass = myClass;
        
        console.log("myClass full 1");
        console.log(myClass);
        console.log(oldClass);

        $(".row."+myClass+".product-preview").clone().insertAfter(".here");

      } else {
        console.log("myClass full 2");
        console.log(myClass);
        console.log(oldClass);
        // clear old preview 
        $(".here").remove(".row."+oldClass+".product-preview");
        // insert new;
        $(".row."+myClass+".product-preview").clone().insertAfter(".here");
      }
       
      console.log("deeper");
      console.log(myClass);
      // $(".row."+myClass+".product-preview").clone().insertAfter(".here");
      // get height of product preview
      var preview = $(".row."+myClass+".product-preview").outerHeight( true );
      console.log(preview);
      // get height of menu pop down
      var menu = $(".wsshopwp").outerHeight( true );
      var height = menu + preview;
      $(".wsshopwp").css("height",height);
      console.log(menu);
      // add them together
      console.log("appendTo!?");
      // $( myClass ).appendTo( ".here" );
      // $( ".here" ).append( $( myClass ) );
      // $( "<p>Test</p>" ).appendTo( ".here" );
    });
  //  TO DO
  // If others are clicked then the it gets added.
  // Clicked ones stay visible on other tabs.
  // Menu area needs to expand.

  $(document).on("click",".appDetails", function () {
   var clickedBtnID = $(this).attr('id'); // or var clickedBtnID = this.id
   console.log('you clicked on button #' + clickedBtnID);
});

  }(jQuery));
});
</script>




<div class="<?php print $classes; ?>">
  <?php print render($title_prefix); ?>
  <?php if ($title): ?>
    <?php print $title; ?>
  <?php endif; ?>
  <?php print render($title_suffix); ?>
  <?php if ($header): ?>
    <div class="view-header">
      <?php print $header; ?>
    </div>
  <?php endif; ?>

  <?php if ($exposed): ?>
    <div class="view-filters">
      <?php print $exposed; ?>
    </div>
  <?php endif; ?>

  <?php if ($attachment_before): ?>
    <div class="attachment attachment-before">
      <?php print $attachment_before; ?>
    </div>
  <?php endif; ?>

  <?php if ($rows): ?>
    <div class="view-content">
      <?php print $rows; ?>
    </div>
  <?php elseif ($empty): ?>
    <div class="view-empty">
      <?php print $empty; ?>
    </div>
  <?php endif; ?>

  <?php if ($pager): ?>
    <?php print $pager; ?>
  <?php endif; ?>

  <?php if ($attachment_after): ?>
    <div class="attachment attachment-after">
      <?php print $attachment_after; ?>
    </div>
  <?php endif; ?>

  <?php if ($more): ?>
    <?php print $more; ?>
  <?php endif; ?>

  <?php if ($footer): ?>
    <div class="view-footer">
      <?php print $footer; ?>
    </div>
  <?php endif; ?>

  <?php if ($feed_icon): ?>
    <div class="feed-icon">
      <?php print $feed_icon; ?>
    </div>
  <?php endif; ?>

</div><?php /* class view */ ?>
