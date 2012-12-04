#!/usr/bin/perl -w

use strict;

my @lt = localtime;
$lt[4]++;
$lt[5]+=1900;

print "$lt[3]/$lt[4]/$lt[5]\n";
