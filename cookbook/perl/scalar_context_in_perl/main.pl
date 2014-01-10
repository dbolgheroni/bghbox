#!/usr/bin/perl

@a = ("foo", "bar", "baz", "qux");
%h = ("a", "foo", "b", "bar", "c", "baz", "d", "quz");
@empty_a = ();

$n =  @a;

if (@a) {
    print ("\@a has $n items\n");
}

if (@empty_a) {
    print ("\@empty_a has items\n");
}

@k = keys(%h); # list context
foreach (@k) {
    print($_, "\n");
}

$h = keys(%h); # scalar context
print ("\$h = $h\n");
