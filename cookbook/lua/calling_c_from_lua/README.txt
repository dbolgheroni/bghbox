How to compile:

Lua 5.1:
$ gcc -shared -lm -L/usr/local/lib -llua5.1 -I/usr/local/include -I/usr/local/include/lua-5.1 -omylib.so mylib.c

LuaJIT 2.0:
$ gcc -shared -lm -L/usr/local/lib -lluajit-5.1 -I/usr/local/include -I/usr/local/include/luajit-2.0 -omylib.so mylib.c
