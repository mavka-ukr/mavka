set(MAVKA_SYNTAX mavka_syntax CACHE INTERNAL "")
set(MAVKA_SYNTAX_SRC
        MavkaLexer.cpp
        MavkaLexer.h
        MavkaParser.cpp
        MavkaParser.h
        MavkaParserBaseListener.cpp
        MavkaParserBaseListener.h
        MavkaParserListener.cpp
        MavkaParserListener.h
)

add_subdirectory(antlr4-cpp-runtime)

add_library(${MAVKA_SYNTAX} ${MAVKA_SYNTAX_SRC})

target_include_directories(${MAVKA_SYNTAX} PUBLIC
        .
)
target_link_libraries(${MAVKA_SYNTAX} antlr4_cpp_runtime)

if ("${CMAKE_BUILD_TYPE}" STREQUAL "DEBUG")
    target_compile_options(${MAVKA_SYNTAX} PRIVATE
            -g -Wall -O0
    )
else ()
    target_compile_options(${MAVKA_SYNTAX} PRIVATE
            -w -O3
    )
    target_compile_options(${MAVKA_SYNTAX} PUBLIC
            -Wno-attributes
    )
endif ()
