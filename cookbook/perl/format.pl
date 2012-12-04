#!/usr/bin/perl

$name = "Daniel";
$age = 29;
$profession = "Engineer";

write FOO;
select (STDOUT);

format FOO =
===============================================
@<<<<<, Age: @>>>>>>>, Profession: @>>>>>>>>>>>
$name, $age, $profession
===============================================
.
