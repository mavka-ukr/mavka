cmake_minimum_required(VERSION 3.26)
project(mavka)

set(CMAKE_CXX_STANDARD 20)

file(READ "VERSION" MAVKA_VERSION)

add_subdirectory(external/parser)
add_subdirectory(external/ordered-map)

set(MAVKA_COMPILER_SRC
        mama/compiler/nodes/compile_list_node.cpp
        mama/compiler/nodes/compile_assign_by_identifier_node.cpp
        mama/compiler/nodes/compile_assign_node.cpp
        mama/compiler/nodes/compile_binary_node.cpp
        mama/compiler/nodes/compile_break_node.cpp
        mama/compiler/nodes/compile_call_node.cpp
        mama/compiler/nodes/compile_chain_node.cpp
        mama/compiler/nodes/compile_continue_node.cpp
        mama/compiler/nodes/compile_dictionary_node.cpp
        mama/compiler/nodes/compile_diia_node.cpp
        mama/compiler/nodes/compile_each_node.cpp
        mama/compiler/nodes/compile_give_node.cpp
        mama/compiler/nodes/compile_god_node.cpp
        mama/compiler/nodes/compile_identifier_node.cpp
        mama/compiler/nodes/compile_if_node.cpp
        mama/compiler/nodes/compile_mockup_diia_node.cpp
        mama/compiler/nodes/compile_mockup_module_node.cpp
        mama/compiler/nodes/compile_mockup_structure_node.cpp
        mama/compiler/nodes/compile_mockup_subject_node.cpp
        mama/compiler/nodes/compile_module_node.cpp
        mama/compiler/nodes/compile_mrm_diia_node.cpp
        mama/compiler/nodes/compile_number_node.cpp
        mama/compiler/nodes/compile_unary_node.cpp
        mama/compiler/nodes/compile_return_node.cpp
        mama/compiler/nodes/compile_string_node.cpp
        mama/compiler/nodes/compile_structure_node.cpp
        mama/compiler/nodes/compile_take_node.cpp
        mama/compiler/nodes/compile_ternary_node.cpp
        mama/compiler/nodes/compile_test_node.cpp
        mama/compiler/nodes/compile_throw_node.cpp
        mama/compiler/nodes/compile_try_node.cpp
        mama/compiler/nodes/compile_type_node.cpp
        mama/compiler/nodes/compile_wait_node.cpp
        mama/compiler/nodes/compile_while_node.cpp
        mama/compiler/nodes/diia.cpp
        mama/compiler/compiler.cpp
        mama/objects/MaDict.cpp
        mama/objects/MaDiia.cpp
        mama/objects/MaList.cpp
        mama/objects/MaLogical.cpp
        mama/objects/MaModule.cpp
        mama/objects/MaNumber.cpp
        mama/objects/MaObject.cpp
        mama/objects/MaString.cpp
        mama/objects/MaStructure.cpp
        mama/MaFrame.cpp
        mama/MaInstruction.cpp
        mama/helpers.cpp
        mama/mama.cpp
        mama/mama.h
        mama/MaScope.cpp
        utils/chrono.h
        utils/tools.cpp
        utils/tools.h
)

add_executable(mavka mavka.cpp ${MAVKA_COMPILER_SRC})
add_executable(mavka_optimized mavka.cpp ${MAVKA_COMPILER_SRC})

target_link_libraries(mavka PRIVATE mavka_parser tsl::ordered_map)
target_link_libraries(mavka_optimized PRIVATE mavka_parser tsl::ordered_map)

target_compile_options(mavka PRIVATE -fexceptions -DMAVKA_VERSION="${MAVKA_VERSION}")
target_compile_options(mavka_optimized PRIVATE -fexceptions -O3 -DMAVKA_VERSION="${MAVKA_VERSION}")

set_target_properties(mavka PROPERTIES OUTPUT_NAME "мавка")
set_target_properties(mavka_optimized PROPERTIES OUTPUT_NAME "мавка_оптимізовано")
