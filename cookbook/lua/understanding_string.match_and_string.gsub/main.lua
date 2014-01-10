#!/usr/bin/env lua

s = "foo bar baz qux"
--s = nil

match = string.match(s, "bar") -- always check for s, error if it's nil
print(match)

t = string.gsub(s, "bar", "buteco") -- always check for s, error it it's nil
u = string.gsub(s, "buteco", "bar") -- no match, return original s
print(t)
print(u)
