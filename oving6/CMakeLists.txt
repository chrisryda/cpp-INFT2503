cmake_minimum_required(VERSION 3.1)

project(oving6)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -pthread -Wall -Wextra")

find_package(Boost 1.54.0 COMPONENTS system REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

add_executable(task2 task2.cpp)
target_link_libraries(task2 ${Boost_LIBRARIES})

