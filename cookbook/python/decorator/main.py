#!/usr/bin/env python3.3

def decorate(func):
    def wrapper(*a):
        print("executing", func.__name__)
        return func(*a)

    return wrapper

#@decorate
def myfunction(parameter):
    print(parameter)

myfunction = decorate(myfunction)
myfunction("bar")
