#!/usr/bin/env python

for i in range(1, 101):
    if (not i % 3) and (not i % 5):
        print(i, "(FizzBuzz)")
        continue
    elif not i % 3:
        print(i, "(Fizz)")
    elif not i % 5:
        print(i, "(Fuzz)")
    else:
        print(i)
