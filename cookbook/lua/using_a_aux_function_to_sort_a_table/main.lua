#!/usr/bin/env lua

t = { 3, 5, 4, 2 ,1 }

function mysort (x, y)
    print("x", x)
    print("y", y)
    print()
    return x > y
end

table.sort(t, mysort)

for i, n in ipairs(t) do
    print(n)
end
