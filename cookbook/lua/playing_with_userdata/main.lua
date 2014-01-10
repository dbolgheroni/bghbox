#!/usr/bin/env lua51

local mylib = require "mylib"

--print(mylib.mysin(30))
n = mylib.new()

-- before set
print("before set")
i = mylib.get(n)
print(i)

print()

-- after set
mylib.set(n)
print("after set")
i = mylib.get(n)
print(i)
