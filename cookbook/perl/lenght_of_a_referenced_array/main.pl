#!/usr/bin/perl

$a = [ 'foo', 'bar', 'baz' ];
$len1 = @{ $a };
$len2 = @$a; # same thing

print "$len1\n";
print "$len2\n";
