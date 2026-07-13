cmake_minimum_required(VERSION 3.15)
project(CPPContainers)

set(CMAKE_CXX_STANDARD 20)

add_executable(tests
	tests/vector_tests.cpp
	tests/linkedlist_tests.cpp
 "include/vector.hpp" "include/linkedlist.hpp" "include/doctest.h")

target_include_directories(tests PRIVATE include)