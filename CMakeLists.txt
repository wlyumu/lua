cmake_minimum_required(VERSION 3.0.0)
project(lua VERSION 0.1.0)

include(CTest)
enable_testing()


aux_source_directory(./Lua LUA_SRC)
aux_source_directory(./luatest/src LUA_TEST_SRC)

include_directories(./Lua LUA_INC)
include_directories(./luatest/inc LUA_TEST_INC)
add_executable(lua main.c ${LUA_SRC} ${LUA_TEST_SRC})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
