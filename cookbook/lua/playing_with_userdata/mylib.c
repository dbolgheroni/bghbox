#include <stdio.h>
#include <string.h>
#include <math.h>
 
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
 
/* coringa */
static int l_sin (lua_State *L) {
    double d = luaL_checknumber(L, 1);
    lua_pushnumber(L, sin(d));
    return 1;
}

static int l_new (lua_State *L) {
    int *i;

    i = (int *)lua_newuserdata(L, sizeof(int));
    *i = 666;

    return 1;
}

static int l_set (lua_State *L) {
    int *i = (int *)lua_touserdata(L, 1);

    *i = 777;

    return 0;
}

static int l_get (lua_State *L) {
    //data *s = (data *)lua_touserdata(L, 1);
    int *i = (int *)lua_touserdata(L, 1);

    lua_pushinteger(L, *i);

    return 1;
}
 
static const struct luaL_Reg mylib [] = {
    {"mysin", l_sin},
    {"new", l_new},
    {"set", l_set},
    {"get", l_get},
    {NULL, NULL} /* sentinel */
};
 
/* main function */
int luaopen_mylib (lua_State *L) {
    luaL_register(L, "mylib", mylib); /* 5.1 */
    //luaL_newlib(L, mylib); /* 5.2 */
    return 1;
}
