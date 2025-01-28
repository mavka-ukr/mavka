set(MAVKA_SYNTAX mavka_syntax CACHE INTERNAL "")
set(MAVKA_SYNTAX_SRC
        generated/MavkaLexer.cpp
        generated/MavkaParser.cpp
        generated/MavkaParserBaseListener.cpp
        generated/MavkaParserListener.cpp
        generated/MavkaParserListener.cpp
        generated/MavkaParserBaseVisitor.cpp
        generated/MavkaParserVisitor.cpp
)

cmake_minimum_required(VERSION 3.26)
project(${MAVKA_SYNTAX})

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(antlr4-cpp-runtime)

add_library(${MAVKA_SYNTAX} ${MAVKA_SYNTAX_SRC})

target_include_directories(${MAVKA_SYNTAX} PUBLIC generated)

target_link_libraries(${MAVKA_SYNTAX} antlr4_cpp_runtime)

target_compile_options(${MAVKA_SYNTAX} PRIVATE -O3)
