#!/bin/sh

conf="foo bar baz"

for c in $conf; do
    C=`echo $c | tr '[:lower:]' '[:upper:]'`
    echo $C 
done
