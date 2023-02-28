cmake_minimum_required(VERSION 3.24)
project(HW_11_02)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_library(LEAVER SHARED CLeaver/library.cpp CLeaver/library.h)

add_executable(HW_11_02 main.cpp)

target_link_libraries(HW_11_02 LEAVER)