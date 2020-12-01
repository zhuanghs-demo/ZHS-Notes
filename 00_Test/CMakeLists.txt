cmake_minimum_required(VERSION 2.8)

set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "g++")

#项目名称
project(00_Test)

#创建debug版本
set(CMAKE_BUILD_TYPE "Debug")

#add module directory
include_directories(${PROJECT_SOURCE_DIR}/include)
add_subdirectory(src)

#编译生成可执行文件
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)
add_executable(test main.c)

#链接库
link_directories(${PROJECT_SOURCE_DIR}/lib)
target_link_libraries(test print mylist singlelist listQueue binarytreebaseonlist binarysearchtree listhash)
