#include <stdio.h>
#include <string.h>
#include <math.h>

#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"

#include "lua_test.h"

lua_State *g_lua = 0;

const char LUA_SCRIPT_GLOBAL[] =

"mytest(1, 3)";

static int mytest(lua_State *L)
{
   int ms;
   int us;
   if(lua_type(L, 1) == LUA_TNUMBER) /*判断第一个参数*/
   {
      ms = luaL_checknumber(L, 1);
      if(lua_type(L, 1) == LUA_TNUMBER)
      {
         /*检查函数参数arg是否是一个数字，并返回这个数字*/
         us = luaL_checknumber(L, 2);
      }
      else
      {
         return 0;
      }
      
   }
   printf("ms: %d, us : %d\r\n", ms, us);
   return 0;
}

static void lua_RegisterFunc(void)
{
  lua_register(g_lua, "mytest", mytest);
}


void LuaYeildHook(lua_State* _L, lua_Debug *ar)
{

 // printf("enter luaYeildHook\r\n");

}
void lua_Init(void)
{
  g_lua = luaL_newstate();
  /*将所有标准的Lua库打开到给定的状态*/
  luaL_openlibs(g_lua);
  luaopen_base(g_lua);

  lua_RegisterFunc();
  /*错误处理函数*/

  lua_sethook(g_lua, LuaYeildHook, LUA_MASKLINE, 0);
}


void mytest1(int _addr, int _len)
{
   int topNum = 0;
   /* 将全局名称的值推入堆栈
	   返回该值的类型
	*/
   lua_getglobal(g_lua, "mytest");

   /*获取栈顶元素的索引*/
   topNum = lua_gettop(g_lua);
    printf("beginint: stack :hight = %d\r\n", lua_gettop(g_lua));
   /*将值为n的整数推入堆栈*/
   lua_pushinteger(g_lua, _addr);
   lua_pushinteger(g_lua, _len);
   lua_pcall(g_lua, 2, 1,0);

   /*设置栈顶元素索引*/
   lua_settop(g_lua, topNum);
   printf("settopfun: stack hight = %d\r\n", lua_gettop(g_lua));
}



void test_api_gettop(void)
{
   lua_State *_L = luaL_newstate();
  /*lua_gettop 返回栈顶元素的索引，即栈内的元素个数*/
  printf("beginint: stack :hight = %d\r\n", lua_gettop(_L));
  /*lua_settop 将栈顶元素的索引为0*/
  lua_settop(_L, 0);
  printf("settopfun: stack hight = %d\r\n", lua_gettop(_L));
}

// fieldtest.lua
#define PI 3.1415926f
static double  Car_WheelBase  =  83;  
static double  Car_WheelTrack =  66;
void car_control(void )
{
  double v_fl;
  double v_fr;
  double v_rl;
  double v_rr;

  double v_speed = 100;
  double v_angle = 30.0 * PI / 180 ;

  
  double v_angleIn  = v_angle;
  
  double v_r = Car_WheelBase / tan(v_angleIn) + Car_WheelTrack / 2.0;

  double v_angleOut = atan( (v_r - Car_WheelTrack / 2.0) /(v_r + Car_WheelTrack / 2.0) * tan(v_angleIn));

  v_rr = v_speed  + v_speed*Car_WheelTrack / 2.0 / v_r;
  v_rl = v_speed  - v_speed*Car_WheelTrack / 2.0 / v_r;
  v_fl = v_speed * Car_WheelBase/ v_r  / sin(v_angleIn);
  v_fr = v_speed * Car_WheelBase/ v_r  / sin(v_angleOut);

  printf("%lf, %lf, %lf, %lf\r\n", v_rr, v_rl, v_fl, v_fr);


}


int main(void)
{

  printf("hello world\r\n");
 
   lua_Init();
//   mytest1(1, 1);

//   luaL_dostring(g_lua, LUA_SCRIPT_GLOBAL); /* 运行Lua脚本 */
//   luaL_dofile(g_lua, "C:/Users/wl/Desktop/vscode/vscode/fieldtest.lua");
//   test_api_gettop();

//   test_api_getfield();

//   car_control();
//   lua_gettable_settable_test();
     lua_rawgeti_rawseti();
     lua_close(g_lua);
   return 1;
}


