#!/usr/bin/perl -w

use strict;

my ($input);

print "input: ";
$input = <STDIN>;
print "eval'ing: $input";

eval $input;
