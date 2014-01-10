#include <stdio.h>
#include <string.h>
#include <math.h>
 
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
 
int r;

static int l_set (lua_State *L) {
    /*
    r = luaL_ref(L, LUA_ENVIRONINDEX);
    //printf("ref = %d\n", r);

    lua_rawgeti(L, LUA_ENVIRONINDEX, r);
    int n = lua_tonumber(L, -1);
    //printf("n = %d\n", n);
    */

    r = lua_tointeger(L, -1);

    return 0;
}

static int l_get (lua_State *L) {
    /*
    lua_rawgeti(L, LUA_ENVIRONINDEX, r);

    int n = lua_tonumber(L, -1);
    printf("%d\n", n);
    */
    printf("%d\n", r);

    return 0;
}
static const struct luaL_Reg mylib [] = {
    {"set", l_set},
    {"get", l_get},
    {NULL, NULL} /* sentinel */
};
 
/* main function */
int luaopen_mylib (lua_State *L) {
    lua_newtable(L);
    lua_replace(L, LUA_ENVIRONINDEX);

    luaL_register(L, "mylib", mylib); /* 5.1 */
    //luaL_newlib(L, mylib); /* 5.2 */
    return 1;
}
