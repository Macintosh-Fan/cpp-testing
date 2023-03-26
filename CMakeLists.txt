cmake_minimum_required(VERSION 3.24)
project(cpp_testing)

set(CMAKE_CXX_STANDARD 20)

add_library(cpp_testing testing.cpp testing.hpp)
