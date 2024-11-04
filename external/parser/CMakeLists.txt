cmake_minimum_required(VERSION 3.26)
project(mavka_parser)

set(CMAKE_CXX_STANDARD 20)

add_definitions(-DANTLR4CPP_STATIC)

set(MAVKA_PARSER mavka_parser CACHE INTERNAL "")
set(MAVKA_PARSER_SRC
        visitor/visitAccess.cpp
        visitor/visitArithmetic.cpp
        visitor/visitArray.cpp
        visitor/visitAs.cpp
        visitor/visitAssign.cpp
        visitor/visitBitwise.cpp
        visitor/visitBitwise_not.cpp
        visitor/visitBody.cpp
        visitor/visitCall.cpp
        visitor/visitComparison.cpp
        visitor/visitDict.cpp
        visitor/visitDiia.cpp
        visitor/visitFile.cpp
        visitor/visitGet.cpp
        visitor/visitGive.cpp
        visitor/visitIdentifier.cpp
        visitor/visitIf.cpp
        visitor/visitLogical.cpp
        visitor/visitModule.cpp
        visitor/visitNegative.cpp
        visitor/visitNested.cpp
        visitor/visitNot.cpp
        visitor/visitNumber.cpp
        visitor/visitPositive.cpp
        visitor/visitSet.cpp
        visitor/visitString.cpp
        visitor/visitStructure.cpp
        visitor/visitTake.cpp
        visitor/visitTry.cpp
        visitor/visitType.cpp
        visitor/visitWhile.cpp
        parser.cpp
        tools.cpp
)

add_subdirectory(syntax)

add_library(${MAVKA_PARSER} ${MAVKA_PARSER_SRC})

target_include_directories(${MAVKA_PARSER} PUBLIC .)
target_link_libraries(${MAVKA_PARSER} mavka_syntax)
