cmake_minimum_required(VERSION 3.1)

project(oving7)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra")

add_executable(fraction 1/task1a.cpp 1/fraction.cpp)
add_executable(set 2/task2.cpp 2/set.cpp)
