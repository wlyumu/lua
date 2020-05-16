#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"

#include "lua_test.h"

/*
  int lua_pcall (lua_State *L, int nargs, int nresults, int msgh);
  nargs    ：参数个数
  nresults ：返回值个数
  msgh     ：0表示无，表示错误处理函数在栈中的索引

  void lua_rawseti (lua_State *L, int index, lua_Integer i);
  功能：是否等价于t[i] = v，其中t是给定索引处的表，v是堆栈顶部的值。
  
*/
void lua_rawgeti_rawseti(void)
{
  luaL_dofile(g_lua,"C:/Users/wl/Desktop/lua/lua_file/lua_rawgeti.lua");
  
  lua_getglobal(g_lua, "languagesTable");
 
  //
  lua_rawgeti(g_lua, -1, 2);
  if(lua_isnil(g_lua, -1))
  {
    printf("c++ ---> [2] = nil \r\n");
  }
  else
  {
    printf("c++ ---> [2] = %s\r\n", lua_tostring(g_lua, -1));
  }
  
  lua_pop(g_lua, 1);
  
  lua_getglobal(g_lua, "func_prt");
  lua_pcall(g_lua, 0, 0, 0);

  
  lua_pushstring(g_lua, "php");
  lua_rawseti(g_lua, -2, 4);
  
  lua_pushstring(g_lua, "swift");
  lua_rawseti(g_lua, -2, 5);
 
  lua_getglobal(g_lua, "func_prt");
  lua_pcall(g_lua, 0, 0, 0);

}

