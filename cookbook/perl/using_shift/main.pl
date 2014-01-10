#!/usr/bin/perl

# test 1
print "test 1\n"; # string context?
@a = qw(a b c);
print @a;
print "@a\n"; # string context?

$i = shift(@a); # permanently shifts the array
print "@a\n";
print "$i\n";

unshift(@a);
print "@a\n";

# test 2
print "\ntest 2\n"; # string context?
@b = qw(d e);
$j = shift(@b);
print "$j\n";

$j = shift(@b);
print "$j\n";

$j = shift(@b);
if ($j) {
    print("foo\n");
} else {
    print("bar\n");
}

print "\nend\n";
