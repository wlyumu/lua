cmake_minimum_required(VERSION 3.0.0)
project(lua VERSION 0.1.0)

include(CTest)
enable_testing()


aux_source_directory(./Lua LUA_SRC)
aux_source_directory(./luatest LUA_TEST)

include_directories(./Lua LUA_INC)
add_executable(lua main.c ${LUA_SRC} ${LUA_TEST})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
