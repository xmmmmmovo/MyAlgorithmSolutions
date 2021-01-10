cmake_minimum_required(VERSION 3.16)
project(acwing)

set(CMAKE_CXX_STANDARD 17)

add_executable(qsort base/qsort.cpp)
add_executable(A+B base/A+B.cpp)
add_executable(merge_sort base/merge_sort.cpp)
add_executable(topk base/topk.cpp)
add_executable(reverse_count base/reverse_count.cpp)
add_executable(bsearch base/bsearch.cpp)
add_executable(choose_repo "winter/choose_repo.cpp")
add_executable(float_csearch base/float_csearch.cpp)