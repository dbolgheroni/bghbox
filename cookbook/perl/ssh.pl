#!/usr/bin/perl -w

use strict;
use Net::OpenSSH;

my $host = "devio.us";

my $ssh = Net::OpenSSH->new($host, password => 'S1Ndsuieq0,0K?');
$ssh->error and die "can't connect to $host: " . $ssh->error;

sub test_func {
    my @ls = $ssh->capture("ls -A1");
    $ssh->error and die "remote command failed: " . $ssh->error;

    print @ls;
}

test_func;

undef $ssh;
