set(MAVKA_SYNTAX mavka_syntax CACHE INTERNAL "")
set(MAVKA_SYNTAX_SRC
        MavkaLexer.cpp
        MavkaParser.cpp
        MavkaParserBaseListener.cpp
        MavkaParserListener.cpp
)

add_subdirectory(antlr4-cpp-runtime)
add_library(${MAVKA_SYNTAX} ${MAVKA_SYNTAX_SRC})
target_include_directories(${MAVKA_SYNTAX} PUBLIC .)
target_link_libraries(${MAVKA_SYNTAX} antlr4_cpp_runtime)
