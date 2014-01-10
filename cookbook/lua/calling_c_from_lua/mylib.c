#include <stdio.h>
#include <string.h>
#include <math.h>
 
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
 
static int l_sin (lua_State *L) {
    double d = luaL_checknumber(L, 1);
    lua_pushnumber(L, sin(d));
    return 1;
}
 
static const struct luaL_Reg mylib [] = {
    {"mysin", l_sin},
    {NULL, NULL} /* sentinel */
};
 
/* main function */
int luaopen_mylib (lua_State *L) {
    luaL_register(L, "mylib", mylib); /* 5.1 */
    //luaL_newlib(L, mylib); /* 5.2 */
    return 1;
}
