package Foo;

use strict;
use warnings;

BEGIN {
    use Exporter (); # equivalent to BEGIN { require Exporter; }
    our (@ISA, @EXPORT, @EXPORT_OK);

    @ISA = qw(Exporter);
    @EXPORT = qw(&dog);
    @EXPORT_OK = qw(bar);
}

our $bar = 1;

sub camel {
    print "Hello, I'm a came... hmmm, I mean... Perl!\n";
}

sub dog {
    print "Hello, I'm a dog!\n";
}

END { }

1;
