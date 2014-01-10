#!/bin/sh

string=$1

case "$string" in
    foo) echo 1 ;;
    bar) echo 2 ;;
    foobar) echo 3 ;;
    *) echo 4 ;;
esac
