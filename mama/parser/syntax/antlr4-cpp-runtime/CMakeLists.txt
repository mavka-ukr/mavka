cmake_minimum_required(VERSION 3.25)
project(antlr4-cpp-runtime VERSION 4.13.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if ("${CMAKE_BUILD_TYPE}" STREQUAL "")
    set(CMAKE_BUILD_TYPE RELEASE)
else()
    string(TOUPPER ${CMAKE_BUILD_TYPE} CMAKE_BUILD_TYPE)
endif()
message(STATUS "Building ANTLR4-CPP-RUNTIME in ${CMAKE_BUILD_TYPE} mode")

#------------------- SUBDIRECTORY ADDITION ------------------------------------

add_subdirectory(runtime)
