#!/usr/bin/perl -w
#
# this program, as it is right now, is WRONG!

use strict;

my ($foo, @bar, $foo1, $foo2);

# hash reference
$foo = {
    foo1 => $foo1,
    foo2 => $foo2,
};

# -> dereference
# $foo->{foo1} = "bar1"; ---> dereference on the left side?
# Programming Perl, 3rd. Ed, p. 278
$foo->{foo1} = "bar1";
$foo->{foo2} = "bar2";
$bar[0] = $foo;

$foo->{foo1} = "bar3";
$foo->{foo2} = "bar4";
$bar[1] = $foo;

print "$bar[0]->{foo1}\n";
print "$bar[0]->{foo2}\n";

print "$bar[1]->{foo1}\n";
print "$bar[1]->{foo2}\n";

# output
# 
# bar3
# bar4
# bar3
# bar4
#
# Shouldn't be
#
# bar1
# bar2
# bar3
# bar4
#
# ?
