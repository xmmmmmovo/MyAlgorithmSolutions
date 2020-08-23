cmake_minimum_required(VERSION 3.10)
project(DS)

set(CMAKE_CXX_STANDARD 17)

add_executable(vector_test test/vector_test.cpp)
add_executable(auto_test test/auto_test.cpp)
add_executable(charset_tools_test test/charset_tools_test.cpp)
add_executable(test test/test.cpp)