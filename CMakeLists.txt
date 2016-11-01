cmake_minimum_required(VERSION 3.5)
project(eclipse_auto_workspace)

SET(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
SET(BUILD_SHARED_LIBRARIES OFF)
SET(CMAKE_EXE_LINKER_FLAGS "-static")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc -std=c++11")

set(SOURCE_FILES main.cpp all_inlcudes.h ConfigInfo.cpp ConfigInfo.h)
add_executable(eclipse_auto_workspace ${SOURCE_FILES})
