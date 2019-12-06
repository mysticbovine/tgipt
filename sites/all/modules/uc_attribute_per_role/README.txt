# README file for uc_attribute_per_role
# Copyright (C) 2011 Stewart Adam <s.adam at diffingo.com>
# License: GNU GPLv2+

What does uc_attribute_per_role do?
-----------------------------------
uc_attribute_per_role allows site administrators to define, on a per-role basis,
which attributes should be hidden to the users of an Ubercart site.


Installation
------------
Simply copy the uc_attribute_per_role folder into your sites/all/modules folder
and then browse to admin/modules to enable it.


Configuration
-------------
* Browse to "Administer > Store Administration > Configuration > Attributes Per
  Role Definitions" (URL shortcut admin/store/settings/attributes_per_role)
* Click "Add Definition"
* Choose a role name and use the checkboxes to select any attributes you wish to
  remain hidden for members of this user role.
* Click "Save changes" to store the definition.

You can later edit this definition to change the attributes which are hidden, or
reset it to restore the display of all attributes for members of that specific
user role.


Caveats and known bugs
----------------------
* Required attributes displayed in the form of form elements that get a default
  value set (for example, select boxes) may affect a product's price even though
  it is not actually displayed to the user.


Credits and Sponsors
--------------------
Development of this module was generously sponsored by Palas Emporio Pty Ltd.
for their website, www.palasjewellery.com.au.
