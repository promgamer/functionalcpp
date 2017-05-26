cmake_minimum_required(VERSION 3.6)
project(demo)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(SOURCE_FILES main.cpp functions.hpp helpers.hpp)
add_executable(demo ${SOURCE_FILES})