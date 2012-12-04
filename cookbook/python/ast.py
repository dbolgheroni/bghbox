#!/usr/bin/env python

print("** test")
print("=======")

def test(*pos, **keyw):
    return keyw.get("prefix", "foo")

print("test() -->", test())
print("test(prefix=False) -->", test(prefix=False))

print()

print("* test")
print("======")
t = ("foo", "bar")
print("print(t) -->", t)
print("print(*t) -->", *t)
