cmake_minimum_required(VERSION 3.6)
project(ps)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES 12-c-orderedTree.cpp)
add_executable(ps ${SOURCE_FILES})