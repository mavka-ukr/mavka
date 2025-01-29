cmake_minimum_required(VERSION 3.26)

IF (WIN32)
    project(mavka)

    set(CMAKE_CXX_STANDARD 20)

    add_subdirectory(mavka_parser)

    add_executable(mavka
            main.cpp
            extension.cpp
            ../build/мавка/бібліотека/М.o
            ../build/мавка/бібліотека/мавка.o
            ../build/мавка/бібліотека/МаМа.o
            ../build/мавка/бібліотека/читати_юнікод.o
            ../build/мавка/компілятор.o
            ../build/мавка/мавка.o
            ../build/старт.o
            ../build/МаМа/КД/КД.o
            ../build/МаМа/біб.o
            ../build/МаМа/Код.o
            ../build/МаМа/Машина.o
            ../build/МаМа/Назва.o
            ../build/МаМа/Обʼєкт.o
            ../build/МаМа/ОбʼєктБайтів.o
            ../build/МаМа/ОбʼєктДії.o
            ../build/МаМа/ОбʼєктЛогічного.o
            ../build/МаМа/ОбʼєктМодуля.o
            ../build/МаМа/ОбʼєктНативноїДії.o
            ../build/МаМа/ОбʼєктСловника.o
            ../build/МаМа/ОбʼєктСписку.o
            ../build/МаМа/ОбʼєктСтруктури.o
            ../build/МаМа/ОбʼєктТексту.o
            ../build/МаМа/ОбʼєктЮнікоду.o
            ../build/МаМа/ОбʼєктЧисла.o
            ../build/МаМа/Помилка.o
            ../build/МаМа/Середовище.o
            ../build/МаМа/СкладенийОбʼєкт.o
            ../build/МаМа/Утилізатор.o)
    target_compile_options(mavka PUBLIC -O3 -fexceptions -DMAVKA_READLINE=${READLINE_AVAILABLE})
    target_link_libraries(mavka PUBLIC mavka_parser)
ELSE ()
    project(mavka_external)

    set(CMAKE_CXX_STANDARD 20)

    add_subdirectory(mavka_parser)

    add_library(mavka_external extension.cpp)
    target_compile_options(mavka_external PUBLIC -O3 -fexceptions -DMAVKA_READLINE=${READLINE_AVAILABLE})
    target_link_libraries(mavka_external PUBLIC mavka_parser)
ENDIF ()