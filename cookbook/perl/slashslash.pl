#!/usr/bin/#perl
#
# conclusion: using // to match a pattern (as in # [1]) will match the
# latest pattern used (in this case, "foo")
# 
# "Oh, Dear Lord."

use strict;

my ($var1, $var2);

$var1 = "foo";
$var2 = "bar";

if ($var1 =~ /foo/) {
    print "OK!\n";
}

if ($var2 =~ //) { # [1]
    print "OK again!\n";
}
