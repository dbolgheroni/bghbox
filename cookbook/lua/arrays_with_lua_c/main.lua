#!/usr/bin/env lua51

local extlib = require "mylib"

-- string
extlib.mystring("foo")

-- sin
print(extlib.mysin(30));

-- array
u = {}
u = extlib.myarray();
print(u[1], u[2], u[3]);
