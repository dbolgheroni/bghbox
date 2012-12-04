#!/bin/sh

while getopts ":abc:" opt; do
    case $opt in
	a)
	    a=1 ;;
	b)
	    b=1 ;;
	c)
	    c=1

	    case $OPTARG in
		1)
		    c1=1 ;;
		2)
		    c2=1 ;;
		3)
		    c3=1 ;;
	    esac ;;
    esac
done

echo "a = $a"
echo "b = $b"
echo "c = $c"
echo
echo "c1 = $c1"
echo "c2 = $c2"
echo "c3 = $c3"
