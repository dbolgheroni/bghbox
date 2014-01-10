#!/usr/bin/env lua

n = 0
if n then
    print("ok")
end

n = false -- doesn't evaluate
if n then
    print("ok")
end

n = nil -- doesn't evaluate
if n then
    print("ok")
end
