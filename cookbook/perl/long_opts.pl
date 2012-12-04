#!/usr/bin/perl -w

use strict;
use warnings;

use Getopt::Long;

#Getopt::Long::Configure("pass_through");
Getopt::Long::Configure("bundling");

our ($a_opt, $b_opt, $c_opt);
my $opts = GetOptions ("-a" => \$a_opt,
                       "-b" => \$b_opt,
                       "-c=i" => \$c_opt);

if ($a_opt) {
    print "-a opt enabled\n";
}

if ($c_opt) {
    print "-c opt got $c_opt integer\n";
}

print "\@ARGV = @ARGV\n";
