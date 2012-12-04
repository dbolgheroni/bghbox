#!/bin/sh


FOO=

#if [ $FOO -eq 0 ]; then
#        echo 0
#elif [ $FOO -eq 1 ]; then
#        echo 1
#else
#        echo else
#fi

if [ -z "$FOO" ]; then
    echo if
else
    echo else
fi
