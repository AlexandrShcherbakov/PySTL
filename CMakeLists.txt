cmake_minimum_required(VERSION 3.9)
project(PySTL)

set(CMAKE_CXX_STANDARD 17)

include_directories(include/PySTL_functions)

add_subdirectory(test)
#add_library(PySTL include/main.h)