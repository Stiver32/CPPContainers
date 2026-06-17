cmake_minimum_required(VERSION 3.15)
project(CPPContainers)

set(CMAKE_CXX_STANDARD 20)

add_executable(tests
	tests/vector_tests.cpp
	vector.cpp
 "include/vector.h")

target_include_directories(tests PRIVATE include)