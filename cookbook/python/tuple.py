#!/usr/bin/env python

def func(test):
    for t in test:
        print("arg: %s" % t)

t = ("foo", "bar", "baz")
func(t)
