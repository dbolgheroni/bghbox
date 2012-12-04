#!/usr/bin/env python

def func(param="default"):
    print("param: %s" % param)

a = "test"
b = "test"

if a is b:
    print("a is b")

if a == b:
    print("a == b")

func()
func("myparam")


