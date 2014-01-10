#!/usr/bin/env lua

cmd = "ls"
filehandle = io.popen(cmd)

for l in filehandle:lines() do
    print(l)
end
