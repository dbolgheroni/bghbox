#!/usr/bin/env lua

-- Use dofile instead of loadfile
--conf = loadfile("conf.lua")
--conf()
dofile("conf.lua")

print(general.foo)
print(general.bar)
