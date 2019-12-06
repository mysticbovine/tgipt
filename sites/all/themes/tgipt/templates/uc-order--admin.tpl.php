<?php

/**
 * @file
 * This file is the default admin notification template for Ubercart.
 */
?>

<p>
<?php print t('Order number:'); ?> <?php print $order_admin_link; ?><br />
<?php print t('Customer:'); ?> <?php print $order_first_name; ?> <?php print $order_last_name; ?> - <?php print $order_email; ?><br />
<?php print t('Order total:'); ?> <?php print $order_total; ?><br />
<?php print t('Shipping method:'); ?> <?php print $order_shipping_method; ?>
</p>
 <table width="100%" cellspacing="0" cellpadding="0" style="font-family: verdana, arial, helvetica; font-size: small;">
                    <tr>
                      <td valign="top" width="50%">
                        <b><?php print t('Billing Address:'); ?></b><br />
                        <?php print $order_billing_address; ?><br />
                        <br />
                        <b><?php print t('Billing Phone:'); ?></b><br />
                        <?php print $order_billing_phone; ?><br />
                      </td>
                      <?php if ($shippable): ?>
                      <td valign="top" width="50%">
                        <b><?php print t('Shipping Address:'); ?></b><br />
                        <?php print $order_shipping_address; ?><br />
                        <br />
                        <b><?php print t('Shipping Phone:'); ?></b><br />
                        <?php print $order_shipping_phone; ?><br />
                      </td>
                      <?php endif; ?>
                    </tr>
                  </table>
<p>
<?php print t('Products:'); ?><br />
<?php foreach ($products as $product): ?>
- <?php print $product->qty; ?> x <?php print $product->title; ?> - <?php print $product->total_price; ?><br />
&nbsp;&nbsp;<?php print t('SKU'); ?>: <?php print $product->model; ?><br />
    <?php if (!empty($product->data['attributes'])): ?>
    <?php foreach ($product->data['attributes'] as $attribute => $option): ?>
    &nbsp;&nbsp;<?php print t('@attribute: @options', array('@attribute' => $attribute, '@options' => implode(', ', (array)$option))); ?><br />
    <?php endforeach; ?>
    <?php endif; ?>
<br />
<?php endforeach; ?>
</p>

<p>
<?php print t('Order comments:'); ?><br />
<?php print $order_comments; ?>
</p>

<p>
<?php print t('Payment record:'); ?><br />
<?php print $admin_comments; ?>
</p>
