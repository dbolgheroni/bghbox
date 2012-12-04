#!/usr/bin/perl -w

local $foo;

sub catch_print {
    print "Signal catch!\n";
}

$SIG{'INT'} = 'catch_print';

print "Process running... Press [Return] to exit.\n";
$foo = <STDIN>;
