#!/bin/sh

func1() {
    echo 'in func1()'
    return 2
}

CMD=$(func1)
echo $?
echo $CMD
