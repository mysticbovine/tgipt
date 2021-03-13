<?php

/**
 * @file
 * This template is used to print a single field in a view.
 *
 * It is not actually used in default Views, as this is registered as a theme
 * function which has better performance. For single overrides, the template is
 * perfectly okay.
 *
 * Variables available:
 * - $view: The view object
 * - $field: The field handler object that can process the input
 * - $row: The raw SQL result that can be used
 * - $output: The processed output that will normally be used.
 *
 * When fetching output from the $row, this construct should be used:
 * $data = $row->{$field->field_alias}
 *
 * The above will guarantee that you'll always get the correct data,
 * regardless of any changes in the aliasing that might happen if
 * the view is modified.
 */
// [title] == Content: Title
// [taxonomy_catalog] == Content: Catalog
// [body] == Content: Description
// [uc_product_image] == Content: Image
// [nid] == Content: Nid
// [path] == Content: Path
// [sell_price] == Product: Sell price
// [buyitnowbutton] == Product: Buy it now button
?>
<?php
  $id = $row->_field_data["nid"]["entity"]->vid;
  $id = $row->nid;
  $productId = "product-".$id;
  $title = $row->node_title;
  $description = $row->_field_data["nid"]["entity"]->body[LANGUAGE_NONE][0]["safe_value"];

  $description  = $row->{$field->body};

  echo "<pre> "; 
  echo "<br>ID: " . $id; 
  echo "<br>Product ID: " . $productId; 
  echo "<br>TITLE: " . $title;
  echo "<br>DESCRIPTION: " . $description;
  echo "<br>PRICE: " . $price;
  echo "<br>URL: " . $url;
  echo "<br>Add to Cart: " . $addCart;
  echo "<br>image: " . $prodcutImage;
  print_r($output);
  echo "</pre> "; 
?>

views-view-field--title.tpl.php 
<?php print $output; ?>
<div class="row product-[nid]">
    <div class="col-sm-12">
        [title]
    </div>
    <div class="col-sm-3">
        [uc_product_image]
    </div>
    <div class="col-sm-9">
        <div class="row">
            <div class="col-sm-9">
                [body]
            </div>
            <div class="col-sm-3">
                [sell_price]<br>
                [buyitnowbutton]
            </div>
        </div>
    </div>
</div>