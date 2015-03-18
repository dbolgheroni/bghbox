#!/bin/sh

func1() {
    typeset FOO='bar'
    echo $FOO
}

func1
echo $FOO
