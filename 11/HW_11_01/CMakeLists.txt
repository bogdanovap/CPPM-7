cmake_minimum_required(VERSION 3.24)
project(HW_11_01)

set(CMAKE_CXX_STANDARD 17)

add_library(LIBRARY STATIC "library/library.cpp" "library/Library.h")

add_executable(HW_11_01 main.cpp)

target_link_libraries(HW_11_01 LIBRARY)
