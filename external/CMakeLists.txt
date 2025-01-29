cmake_minimum_required(VERSION 3.26)

project(mavka_external)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(mavka_parser)

add_library(mavka_external extension.cpp)
target_compile_options(mavka_external PUBLIC -O3 -fexceptions -DMAVKA_READLINE=${READLINE_AVAILABLE})
target_link_libraries(mavka_external PUBLIC mavka_parser)