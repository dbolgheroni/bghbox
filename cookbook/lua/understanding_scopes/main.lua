#!/usr/bin/env lua

local f = function ()
    local x = 1

    local lf = function ()
        z = 3

        local y = 2
        print(x)
    end

    lf()
    print(y)
end

f()
print(z)
