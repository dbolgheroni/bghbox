#!/bin/sh

# ksh is dynamic scoped

# if it was lexically scoped, it should have printed
# 1
# 2

x=1

g() {
    echo $x
    x=2
}

f() {
    local x=3
    g
}

f
echo $x
