#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"


extern lua_State *g_lua;
extern void printLuaStack(lua_State* lua);
void lua_gettable_settable_test(void)
{
  luaL_dofile(g_lua, "C:/Users/wl/Desktop/vscode/vscode/lua_file/lua_gettable_settable.lua");
  
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
    lua_rawget(g_lua, -2);                  // 取information.address的值 -->lua_rawget用法
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
    lua_rawset(g_lua, -3);

    lua_getglobal(g_lua, "func_print_addr"); // 调用打印函数
    lua_pcall(g_lua, 0, 0, 0);
     



}