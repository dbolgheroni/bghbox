#!/usr/bin/env python

def foo():
    def bar():
        return 1

    return bar()

# won't work, because it's only visible inside foo()
#bar()
print(foo())
