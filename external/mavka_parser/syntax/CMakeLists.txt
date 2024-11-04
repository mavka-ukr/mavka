set(MAVKA_SYNTAX mavka_syntax CACHE INTERNAL "")
set(MAVKA_SYNTAX_SRC
        source/MavkaLexer.cpp
        source/MavkaParser.cpp
        source/MavkaParserBaseListener.cpp
        source/MavkaParserListener.cpp
        source/MavkaParserListener.cpp
        source/MavkaParserBaseVisitor.cpp
        source/MavkaParserVisitor.cpp
)

cmake_minimum_required(VERSION 3.26)
project(${MAVKA_SYNTAX})

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(antlr4-cpp-runtime)

add_library(${MAVKA_SYNTAX} ${MAVKA_SYNTAX_SRC})

target_include_directories(${MAVKA_SYNTAX} PUBLIC source)

target_link_libraries(${MAVKA_SYNTAX} antlr4_cpp_runtime)

target_compile_options(${MAVKA_SYNTAX} PRIVATE -w -O3)
target_compile_options(${MAVKA_SYNTAX} PUBLIC -Wno-attributes)
