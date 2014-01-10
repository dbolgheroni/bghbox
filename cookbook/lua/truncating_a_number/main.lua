#!/usr/bin/env lua

n = math.pi
print(n)

function truncate (n, d)
    d = 1 / 10^d
    n = n - n%d

    return n
end

print(truncate(n, 2))
