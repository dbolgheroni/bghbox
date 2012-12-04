#!/usr/bin/perl

use Foo;

camel; # won't be executed (not in @EXPORT)
dog; # OK!

1;
