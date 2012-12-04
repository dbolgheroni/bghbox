#!/usr/bin/env python

test = {}
test["foo"] = "baz"

r = test.get("foo", "bar")
print(r)
