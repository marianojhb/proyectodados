cmake_minimum_required(VERSION 3.27)
project(proyectodados)

set(CMAKE_CXX_STANDARD 14)

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
