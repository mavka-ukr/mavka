set(MAVKA_PARSER mavka_parser CACHE INTERNAL "")
set(MAVKA_PARSER_SRC
        tools.cpp
        parser.cpp
        visitor.cpp
)

cmake_minimum_required(VERSION 3.26)
project(${MAVKA_PARSER})

set(CMAKE_CXX_STANDARD 20)

add_definitions(-DANTLR4CPP_STATIC)

add_subdirectory(syntax)

add_library(${MAVKA_PARSER} ${MAVKA_PARSER_SRC})

target_compile_options(${MAVKA_PARSER} PRIVATE -O3)
target_include_directories(${MAVKA_PARSER} PUBLIC .)
target_link_libraries(${MAVKA_PARSER} mavka_syntax)
