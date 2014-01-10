#!/usr/bin/env python

def foo():
    def bar():
        return 1

    return bar()

#bar() # won't work, bar() is only visible inside foo()
print(foo())
