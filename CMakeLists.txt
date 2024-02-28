cmake_minimum_required(VERSION 3.26)
project(mavka)

set(CMAKE_CXX_STANDARD 20)

file(READ "VERSION" MAVKA_VERSION)

add_subdirectory(mama/src)

set(MAVKA_COMPILER_SRC)

add_executable(mavka mavka.cpp ${MAVKA_COMPILER_SRC})
add_executable(mavka_optimized mavka.cpp ${MAVKA_COMPILER_SRC})

target_link_libraries(mavka PRIVATE mama)
target_link_libraries(mavka_optimized PRIVATE mama)

target_compile_options(mavka PRIVATE -fexceptions -DMAVKA_VERSION="${MAVKA_VERSION}")
target_compile_options(mavka_optimized PRIVATE -fexceptions -O3 -DMAVKA_VERSION="${MAVKA_VERSION}")

set_target_properties(mavka PROPERTIES OUTPUT_NAME "мавка")
set_target_properties(mavka_optimized PROPERTIES OUTPUT_NAME "мавка_оптимізовано")
