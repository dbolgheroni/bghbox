#!/usr/bin/env lua

openuptodd = function (table)
    for k, v in pairs(table) do
        local t = type(v)

        if t == "table" then
            print ("--")
            openuptodd(v)
        end

        print(k, v, t)
    end
end

openuptodd(_G)
