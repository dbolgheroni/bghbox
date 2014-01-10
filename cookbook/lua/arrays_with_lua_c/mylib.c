#include <stdio.h>
#include <string.h>
#include <math.h>

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

/* PiL example */
static int l_sin (lua_State *L) {
    printf("mysin called\n");
    double d = luaL_checknumber(L, 1);
    lua_pushnumber(L, sin(d));
    return 1;
}

/* string */
static int l_string (lua_State *L) {
    printf("mystring called\n");
    const char *file;
    file = lua_tostring(L, 1);
    printf("%s bar\n", file);
}

/* array */
static int l_array (lua_State *L) {
    printf("myarray called\n");

    int i;
    double v = 0;

    lua_newtable(L); 
    for (i = 1; i <= 100; i++) { /* Lua-style */
        v += 0.1;
        /* t[k] = v; v is the top of stack, k is below the top */
        lua_pushinteger(L, i); /* i, below the top */
        lua_pushnumber(L, v); /* v, top */
        lua_settable(L, 1);
    }

    return 1;
}

/* no arg */
static int l_noarg (lua_State *L) {
    printf("noarg called\n");

    return 0;
}

static const struct luaL_Reg mylib [] = {
    {"mynoarg", l_noarg},
    {"myarray", l_array},
    {"mystring", l_string},
    {"mysin", l_sin},
    {NULL, NULL} /* sentinel */
};

/* main function */
int luaopen_mylib (lua_State *L) {
    luaL_register(L, "mylib", mylib); /* 5.1 */
    //luaL_newlib(L, mylib); /* 5.2 */
    return 1;
}
