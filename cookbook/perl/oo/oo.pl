#!/usr/bin/perl

use Module1;

#{ package Module1;
#    sub func1 {
#        print " func1\n";
#    }
#}

print "main OO intro\n";

#Module1::func1();
#Module1::func1; # the same

my $tmp = "Module1";
$tmp->func1;

my $obj = Module1->new;
$obj->name("testy");
print "$obj->name\n";
