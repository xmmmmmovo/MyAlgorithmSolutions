cmake_minimum_required(VERSION 3.16)
project(acwing)

set(CMAKE_CXX_STANDARD 17)

add_executable(qsort base/qsort.cpp)
add_executable(A+B base/A+B.cpp)
add_executable(merge_sort base/merge_sort.cpp)
add_executable(topk base/topk.cpp)
add_executable(reverse_count base/reverse_count.cpp)
add_executable(num_range base/num_range.cpp)