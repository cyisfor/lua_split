#include "lua.h"
#include "lauxlib.h"

#include <string.h>

static int l_split (lua_State *L) {
    const char *s = luaL_checkstring(L, 1);
    size_t len = 0;
    const char *sep = luaL_checklstring(L, 2, &len);
    const char *e = NULL;
    int i = 1;

    lua_newtable(L);  /* result */

    /* repeat for each separator */
    while ((e = strstr(s, sep)) != NULL) {
        lua_pushlstring(L, s, e-s);  /* push substring */
        lua_rawseti(L, -2, i++);
        s = e + len;  /* skip separator */
    }

    /* push last substring */
    lua_pushstring(L, s);
    lua_rawseti(L, -2, i);

    return 1;  /* return the table */
}

int luaopen_split(lua_State* L)
{
    lua_pushcfunction(L,l_split);
    lua_pushstring(L, "split");
    lua_getmetatable(L,-1);
    lua_pushvalue(L,-2);
    lua_pushvalue(L,-4);
    lua_settable(L,-3);
    lua_pop(L,1);
    lua_getfield(L, LUA_GLOBALSINDEX, "string");
    lua_pushvalue(L,-2);
    lua_pushvalue(L,-4);
    lua_settable(L,-3);
    lua_pop(L,2);
    return 1;
}
