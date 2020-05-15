#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"

#include "lua_test.h"
/*
  int lua_rawget (lua_State *L, int index);
  功能：将值t[k]推入堆栈，其中t是给定索引处的值，k是堆栈顶部的值
  
  
  void lua_rawset (lua_State *L, int index);
  功能：是否等价于t[k] = v，其中t是给定下标处的值，v是堆栈顶部的值，而k是刚好在顶部下方的值
*/


void lua_gettable_settable_test(void)
{
  luaL_dofile(g_lua, "C:/Users/wl/Desktop/lua/lua_file/lua_gettable_settable.lua");
  
  // 将全局表压入栈
  lua_getglobal(g_lua, "information");
 
  //将age压入栈中
  lua_pushstring(g_lua, "age");
  printLuaStack(g_lua);
  //取出information.age值
  lua_rawget(g_lua, -2);
  
  if(lua_isnil(g_lua, -1))
  {
      printf("c++ --> information.age = nil\r\n");
  }
  else
  {
      printf("c ++ --> information.age = %d\r\n", lua_tointeger(g_lua, -1));
  }
  //弹出栈顶
  lua_pop(g_lua, 1);


    lua_pushstring(g_lua, "sex");       // 将要取的变量压入栈
    printLuaStack(g_lua);
   // 取information.sex的值 -->lua_rawget用法，
    lua_rawget(g_lua, -2);                  

    printLuaStack(g_lua);
    if(lua_isnil(g_lua, -1))
    {
        printf("\nc++ --> information.address = nil\n");
    }
    else
    {
        printf("\nc++ --> information.address = %s\n", lua_tostring(g_lua, -1));
    }
    lua_pop(g_lua,1);    

      
    lua_pushstring(g_lua, "address");
    lua_pushstring(g_lua, "beijing");
    printLuaStack(g_lua);
    //设置information.adsress的值
    lua_rawset(g_lua, -3);

    lua_getglobal(g_lua, "func_print_addr"); // 调用打印函数
    lua_pcall(g_lua, 0, 0, 0);
     
}