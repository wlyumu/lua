#ifndef _LUA_TEST_H__
#define _LUA_TEST_H__

extern lua_State *g_lua;

void lua_gettable_settable_test(void);
void lua_rawgeti_rawseti(void);
void print_stacknum(const char * desc, const int count);
void printLuaStack(lua_State* lua);
void lua_typetest(void);

#endif /*lua_test*/