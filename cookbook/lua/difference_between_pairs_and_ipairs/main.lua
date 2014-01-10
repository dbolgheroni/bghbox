#!/usr/bin/env lua

t = { key1 = "value1", key2 = "value2" }
u = { "foo", "bar", "baz", "qux" }
v = { key1 = "value1", key2 = "value2", "foo", "bar", "baz" }

-- pairs: to use with key/value tables
print("case 1:")
for x in pairs(t) do -- x is the key here
    print(x)
end

print("\ncase 2:")
for _, x in pairs(t) do 
    print(x)
end

print("\ncase 3:") -- key/value/array table mix
for x in pairs(v) do
    print(x)
end

print("\ncase 4:") -- key/value/array table mix
for _, x in pairs(v) do
    print(x)
end

-- ipairs: to use with arrays (tables)
print("\ncase 5:") 
for x in ipairs(u) do -- x is the index here
    print(x)
end

print("\ncase 6:") 
for _, x in ipairs(u) do 
    print(x)
end

print("\ncase 7:") -- key/value/array table mix
for x in ipairs(v) do
    print(x)
end

print("\ncase 8:") -- key/value/array table mix
for _, x in ipairs(v) do
    print(x)
end
