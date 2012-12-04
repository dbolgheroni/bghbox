#!/usr/bin/perl

@a = (4, 5, 6);
$total = sum ( \@a );

print "total = $total\n";

sub sum {
    my ($aref) = @_; # don't work without "my"! WHY!?

    foreach (@$aref) {
	$total += $_;
    }

    return $total;
}
