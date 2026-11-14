cmake_minimum_required(VERSION 3.27)
project(proyectodados)

set(CMAKE_CXX_STANDARD 14)

# Source files and terminal output use UTF-8 on every platform.
if(MSVC)
    add_compile_options(/utf-8)
endif()

include_directories(.)

add_executable(proyectodados
        condiciones.cpp
        funciones.cpp
        funciones.h
        graficosDados.cpp
        main.cpp
        menues.cpp
        modo_solitario.cpp
        multijugador.cpp
        ranking.cpp
        rlutil.h
        vectores.cpp)
