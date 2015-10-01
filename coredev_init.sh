#!/bin/sh

HOST=$1

if [ -z $HOST ]; then
    echo "$0: no host specified"
    exit 1
fi

rsync --delete --files-from=~/bin/coredev-files -rlptgoDv $HOME/ $HOST:~
