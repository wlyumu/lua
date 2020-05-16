#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"

#include "lua_test.h"


void lua_typetest(void)
{
    luaL_dofile(g_lua, "C:/Users/wl/Desktop/lua/lua_file/lua_type.lua");
    lua_getglobal(g_lua, "information");

    lua_pushstring(g_lua, "name");
    lua_gettable(g_lua, -2);
    printLuaStack(g_lua);

    /*获取栈顶数据的类型*/
    int luatype = lua_type(g_lua, -1); 
    if(luatype == LUA_TNONE)
    {
        printf("\r\n c++ --> information.name type error\r\n");
    }
    else
    {
        printf("\r\n c++ --> information.name type is %s\r\n", lua_typename(g_lua, luatype));
    }
    
    lua_pop(g_lua, -1);

    lua_getglobal(g_lua, "func_prt");
    lua_pcall(g_lua, 0, 0, 0);
    
}