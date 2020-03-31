cmake_minimum_required(VERSION 3.10)
project(DS)

set(CMAKE_CXX_STANDARD 17)

add_executable(DS main.cpp include/ds/vector.hpp include/ds/string.hpp)