#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
#include <stdio.h>

extern lua_State *g_lua;


void print_stacknum(const char * desc, const int count)
{
    printf("%s stack num = %d\n",desc, count);
}


void printLuaStack(lua_State* lua) {

    printf("========= content of stack from top to bottom: ===========\r\n");

    int stackSize = lua_gettop(lua);                    // 获得栈中元素个数
    for (int i=stackSize; i>0; --i) {
        printf("%d [%d]\t", i, -1 - (stackSize - i));
        int t = lua_type(lua, i);                       // 判断当前元素类型
        switch (t) {
            case LUA_TNUMBER:
                printf("%s: \t%.2f\n", lua_typename(lua, t), lua_tonumber(lua, i));     // 打印类型名称和值
                break;
            case LUA_TBOOLEAN:
                printf("%s: \t%d\n", lua_typename(lua, t), lua_toboolean(lua, i));
                break;
            case LUA_TSTRING:
                printf("%s: \t%s\n", lua_typename(lua, t), lua_tostring(lua, i));
                break;
            default:
                // LUA_TTABLE
                // LUA_TTHREAD
                // LUA_TFUNCTION
                // LUA_TLIGHTUSERDATA
                // LUA_TUSERDATA
                // LUA_TNIL
                printf("%s\n", lua_typename(lua, t));                                   // 不好打印的类型，暂时仅打印类型名称
                break;
        }
    }
   // psln(stackSize);

   //  int stackTop=lua_gettop(g_lua);//获取栈顶的索引值
	// int nIdx = 0;
	// int nType;
 
	// printf(" element count: %d\n", stackTop);
 
   
	// printf("栈顶(v)(%d)----------\r\n", stackTop);
    
 
	// //显示栈中的元素
	// for(nIdx = stackTop;nIdx > 0;--nIdx)
	// {
	// 	nType = lua_type(g_lua, nIdx);
	// 	printf("(i:%d) %s(%s)\n",nIdx, lua_typename(g_lua,nType), lua_tostring(g_lua,nIdx));
	// }
 
   
	// printf("-------------\r\n");
    
}

/*
  lua_getfield :  把 t[k] 值压入堆栈， 这里的 t 是指有效索引 index 指向的值
  lua_setfield :  这个函数将把这个值弹出堆栈

  lua 中全局变量是放在一个大table中， 该table 名为 _G

  lua_getglobal: 将特定的全局变量推入到栈顶

  lua_pop        :    从栈中弹出特定数量的元素
  lua_pushinteger：   将值压入栈中
  lua_tointeger  :    将给定索引处的Lua值转换为有符号整数类型lua_Integer

*/


void test_api_getfield(void)
{
   //lua_State *_L = luaL_newstate();

    luaL_dofile(g_lua, "C:/Users/wl/Desktop/vscode/vscode/lua_file/fieldtest.lua");

   // print_stacknum("stage0", lua_gettop(g_lua));
  
   /*查找para变量压入栈底*/
    lua_getglobal(g_lua,"param");           // 查找param变量压入栈底
    print_stacknum("stage1", lua_gettop(g_lua));
    
   /*将Para.a入栈*/
   lua_getfield(g_lua, -1, "a");
   int nParam_a = lua_tointeger(g_lua, -1);
   /*将param.b入栈*/
   lua_getfield(g_lua, -2, "b");
   int nParam_b = lua_tointeger(g_lua, -1);
   print_stacknum("stage2", lua_gettop(g_lua));
//    printf("%d %d\r\n", nParam_a, nParam_b);

   printLuaStack(g_lua);
   
   
//    /*将三个元素出栈*/
   lua_pop(g_lua, 3);
   print_stacknum("stage3",lua_gettop(g_lua));
    
   printLuaStack(g_lua);
   int nParam_c = 2* nParam_a + nParam_b;
   /*将nParam_b推入栈顶*/
   lua_pushinteger(g_lua, nParam_c); 
   /*将栈顶的值赋给tbale _G 中的全局变量c*/
   lua_setfield(g_lua, -2, "c");
   print_stacknum("stage4",lua_gettop(g_lua));

   lua_getglobal(g_lua, "c");
   int _temp = lua_tointeger(g_lua, -1);
  // printf("_temp:%d\r\n", _temp);
    
   

   lua_getglobal(g_lua,"lua_func");         // 查找lua_func函数压入栈底
   lua_pushinteger(g_lua, 3);              // 压入函数变量x=3
   lua_pcall(g_lua,1,1,0);                 // 执行脚本函数lua_func
   print_stacknum("stage5",lua_gettop(g_lua));
   printLuaStack(g_lua);
  


}