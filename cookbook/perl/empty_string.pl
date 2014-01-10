#!/usr/bin/perl

use strict;

my ($empty);

if (defined($empty)) {
    print "1 OK\n";
}

if ($empty) {
    print "2 OK\n";
}

$empty = "";
if (defined($empty)) {
    print "3 OK\n";
}

$empty = 0;
if (defined($empty)) {
    print "4 OK\n";
}

$empty = "0";
if (defined($empty)) {
    print "5 OK\n";
}


if ($empty) {
    print "6 OK\n";
}
