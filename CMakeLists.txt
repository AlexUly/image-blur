cmake_minimum_required(VERSION 3.21)
project(image-blur)

set(CMAKE_CXX_STANDARD 20)


set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(MY_SRC_DIR ${CMAKE_SOURCE_DIR}/src)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
add_subdirectory(src)





