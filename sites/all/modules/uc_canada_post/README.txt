In order to use this module you will need Canada Post API keys.
You can obtain these by signing up on the Canada Post webserver at:

 http://canadapost.ca

 Once registered, your API keys can be found at https://www.canadapost.ca/cpotools/apps/drc/registered?execution=e1s1
 (this could change)
To configure this module: 
Navigate to admin/store/settings/quotes/settings/canadapost and Service options
Enter your key(API User ID) and password.

For Endpoint:
  https://ct.soa-gw.canadapost.ca/rs/ship/price is for the Canadapost Sandbox and should be used for development
  https://soa-gw.canadapost.ca/rs/ship/price is the porduction system

Quotes are obtained using a standard box size. Defaults to 30cm x 30cm x30cm this can be changed on the Shipping Quotes, settings, Quote options admin page
   
This module automatically divides order products into packages of 30kg or less.
30kg is the Canada Post weight limit for a package.  This version will calculate
how many packages need to be sent, calculate the cost of shipping each package,
and display the total number of packages and the total shipping cost to the
customer.