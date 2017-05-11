cmake_minimum_required(VERSION 3.6)
project(ps)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES 9-a-speedCam.cpp 9-a-speedCam2.cpp)
add_executable(ps ${SOURCE_FILES})