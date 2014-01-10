#include <stdio.h>
#include <string.h>
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"

int main(void) {
    /* C declarations */
    char *str = "foo bar";
    const char *strcopy;

    /* Lua declarations */
    const char *buff = "print(\"foo Lua bar\")"; /* exec this */
    int error;

    /* init Lua */
    lua_State *L = luaL_newstate(); /* opens Lua */
    luaL_openlibs(L);               /* opens the standard libraries */

    /* starts HERE */
    lua_pushstring(L, str);        /* pushes string to stack */
    strcopy = lua_tostring(L, -1); /* pops string from stack */
    printf("%s\n", strcopy);       /* print stack */

    /* print using 'print' from Lua, as in buff */
    error = luaL_loadbuffer(L, buff, (size_t)strlen(buff), "line") ||
        lua_pcall(L, 0, 0, 0);

    if (error) {
        fprintf(stderr, "error parsing Lua code\n");
        lua_pop(L, 1);
    }

    /* enough, let's quit */
    lua_close(L);
    return 0;
}
