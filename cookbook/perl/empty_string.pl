#!/usr/bin/perl

use strict;

my ($empty);

if (defined($empty)) {
    print "first OK\n";
}

if ($empty) {
    print "second OK\n";
}

$empty = "";
if (defined($empty)) {
    print "third OK\n";
}

if ($empty) {
    print "fourth OK\n";
}
