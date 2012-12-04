#!/bin/sh

while [ $(pgrep cmus) ]; do
        echo "cmus running..."
        sleep 1
done

echo "process stopped or isn't running... good"
exit 0
