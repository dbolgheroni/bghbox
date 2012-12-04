#!/usr/bin/perl

my $var = 1;

sub my_test {
    my $var = 2;
}

print "$var\n";
my_test;
print "$var\n";
