#!/bin/sh
#
# null non-null test script

foo=true

# always, I mean ALWAYS use the variable inside double quotes here
# or IT WON'T WORK as expected

if [ -n "$foo" ]; then
    echo "yes"
else
    echo "no"
fi
