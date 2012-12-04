#!/bin/sh

CHECK=0
echo "CHECK=0 [ -n \$CHECK ]"
if [ -n $CHECK ]; then
    echo "\tif"
else
    echo "\telse"
fi

CHECK=0
echo "CHECK=0 [ -z \$CHECK ]"
if [ -z $CHECK ]; then
    echo "\tif"
else
    echo "\telse"
fi

CHECK=1
echo "CHECK=1 [ -n \$CHECK ]"
if [ -n $CHECK ]; then
    echo "\tif"
else
    echo "\telse"
fi

CHECK=1
echo "CHECK=1 [ -z \$CHECK ]"
if [ -z $CHECK ]; then
    echo "\tif"
else
    echo "\telse"
fi
