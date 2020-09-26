/**
 * @file
 * script.js
 *
 * Provides general enhancements and fixes to TGIPT.
 */

jQuery(document).ready(function($) {
	(function ($) {

		/* Close nutra pop up*/
		$(".front #nutraopen").hide();
		$(".not-front #nutrapopup").hide();
		
		$("#nutraclose").click(function() {
		
		  $("#nutrapopup").fadeOut( "slow");
		  $("#nutraopen").fadeIn("slow");
		})
		/* Open nutra pop up*/
		$("#nutraopen").click(function() {
		  $("#nutraopen").hide();
		  $("#nutrapopup").fadeIn( "slow");
		})
		
		/* Move the copyright notice to same line as the footer menu */
		$( ".footer .menu.nav" ).append( $( "span.copyright" ) );
		
		/* Add TM to Nutra Supplement Treats from Taxonomy */
		$("h1.page-header:contains('Nutra Supplement Bites')").append('<sup>TM</sup>');
		
		/* Shrinking Menu */
		$(window).scroll(function() {
		  if ($(document).scrollTop() > 238) {
			$('#navbar').addClass('shrink');
		  } else {
			$('#navbar').removeClass('shrink');
		  }
		});
		/* Add CDN */
		var copy = "<div style='font-size: 20px; display: inline-block'> per carton.</div><div style='font-size: 20px'>($6.50 per bag wholesale. $12.99 per bag <abbr title='Manufacturers Suggested Retail Price' style=''>MSRP</abbr>)</div>";
	
		$( ".page-node-157 .suffix" ).replaceWith("<div class='suffix'>%</div>"); /* JOINT SUPPORT */
		$( ".page-node-158 .suffix" ).replaceWith("<div class='suffix'>%</div>"); /* ANXIETY & STRESS */
		$( ".page-node-159 .suffix" ).replaceWith("<div class='suffix'>%</div>"); /* SKIN AND COAT */
		$( ".page-node-160 .suffix" ).replaceWith("<div class='suffix'>%</div>"); /* ANTIOXIDANT */
		$( ".page-node-161 .suffix" ).replaceWith("<div class='suffix'>%</div>"); /* ALLEGIES AND IMMUNE */
		$( ".page-node-162 .suffix" ).replaceWith("<div class='suffix'>%</div>"); /* DIGESTION */
		$( ".page-node-199 .suffix" ).replaceWith("<div class='suffix'>%</div>"); /* TRAINING */
		$( ".page-node-311 .suffix" ).replaceWith("<div class='suffix'>%</div>"); /* SARDINE */
		
		/* change freeminimum on shipping box. */
		$(	".page-node-157 #freeminimum" ).replaceWith("$200");
		$(	".page-node-158 #freeminimum" ).replaceWith("$200");
		$(	".page-node-159 #freeminimum" ).replaceWith("$200");
		$(	".page-node-160 #freeminimum" ).replaceWith("$200");
		$(	".page-node-161 #freeminimum" ).replaceWith("$200");
		$(	".page-node-162 #freeminimum" ).replaceWith("$200");
		$(	".page-node-199 #freeminimum" ).replaceWith("$200");
		$(	".page-node-311 #freeminimum" ).replaceWith("$200");
		/* Black Bar with triangle
		
		var top = triheight/2;
		var bottom = triheight/2;
		var left = triheight/4;
		var right = triheight/4;
			$("h1.page-header:after").css({"border-top-width": top+"px", "border-right-width": right+"px","border-bottom-width": bottom+"px","border-left-width": "0"});
		$("h1.page-header:before").css({"border-top-width": top+"px", "border-right-width": "0","border-bottom-width": bottom+"px","border-left-width": left+"px"});
		*/
		$( window ).resize(function() {	
		var triheight = $("h1.page-header").height();
			if (triheight > 60) {
				$("h1.page-header").toggleClass("twoline");
			}
			
			var triheight = $(".featured h2.block-title").height();		
			if (triheight > 60) {
				$(".featured h2.block-title").toggleClass("twoline");
			}
		
		}); 
			
		var triheight = $("h1.page-header").height();
		if (triheight > 60) {
			$("h1.page-header").toggleClass("twoline");
		}
		
		var triheight = $(".featured h2.block-title").height();		
		if (triheight > 60) {
			$(".featured h2.block-title").toggleClass("twoline");
		}
	
		// Mega Menu intial active menu
		// Selects first grandchild under For Cats and For Dogs.
		$("ul.wsmenu-list li:first-child").addClass("wsshoplink-active");
		
	}(jQuery));
});