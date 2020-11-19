cmake_minimum_required(VERSION 2.8)

set(INCLUDE_DIRECTORIES ${PROJECT_SOURCE_DIR}/include)
include_directories(${INCLUDE_DIRECTORIES})
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
# aux_source_directory(. DIR_LIB_SRC)
# add_library(all  ${DIR_LIB_SRC})

set(libmylist_src mylist.cpp)
add_library(mylist SHARED ${libmylist_src})

set(libprint_src print.cpp)
add_library(print SHARED ${libprint_src})

set(libsingle_src singlelist.c)
add_library(singlelist SHARED ${libsingle_src})

# add_library(print_static STATIC ${libprint_src})
# add_library(print_shared SHARED ${libprint_src})
#  按照一般的习惯，静态库名字跟动态库名字应该是一致的，只是扩展名不同；
# 即：静态库名为 libprint.a； 动态库名为libprint.so ；
# 所以，希望 "print_static" 在输出时，不是"print_static"，而是以"print"的名字显示，故设置如下
# SET_TARGET_PROPERTIES (print_shared PROPERTIES OUTPUT_NAME "print")
# SET_TARGET_PROPERTIES (print_static PROPERTIES OUTPUT_NAME "print")

# cmake在构建一个新的target时，会尝试清理掉其他使用这个名字的库，
# 因此，在构建libprint.a时，就会清理掉libprint.so.
# 为了回避这个问题，比如再次使用SET_TARGET_PROPERTIES定义 CLEAN_DIRECT_OUTPUT属性。
# SET_TARGET_PROPERTIES (print_static PROPERTIES CLEAN_DIRECT_OUTPUT 1)
# SET_TARGET_PROPERTIES (print_shared PROPERTIES CLEAN_DIRECT_OUTPUT 1)

# 按照规则，动态库是应该包含一个版本号的，
# VERSION指代动态库版本，SOVERSION指代API版本。
# SET_TARGET_PROPERTIES (print_static PROPERTIES VERSION 1.1 SOVERSION 1)
# SET_TARGET_PROPERTIES (print_shared PROPERTIES VERSION 1.1 SOVERSION 1)


# 若将libprint.a, libprint.so.x以及print.h安装到系统目录，才能真正让其他人开发使用，
# 本例中，将print的共享库安装到<prefix>/lib目录；
# 将print.h安装<prefix>/include/print目录。
#INSTALL (TARGETS print print_static LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)
#INSTALL (TARGETS print print_shared LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)
#INSTALL (FILES print.h DESTINATION include/print)