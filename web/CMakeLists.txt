cmake_minimum_required(VERSION 3.20)
project(EscaleraWeb LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(DADOS_NATIVE_TESTS "Build native scoring tests instead of the browser app" OFF)
add_library(dados_core game.cpp ../condiciones.cpp)
target_include_directories(dados_core PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

if(DADOS_NATIVE_TESTS)
    enable_testing()
    add_executable(game_test tests/game_test.cpp)
    target_link_libraries(game_test PRIVATE dados_core)
    add_test(NAME scoring_and_turns COMMAND game_test)
    return()
endif()

if(NOT EMSCRIPTEN)
    message(FATAL_ERROR "Use emcmake cmake, or -DDADOS_NATIVE_TESTS=ON for native tests.")
endif()

add_executable(dados main.cpp)
target_link_libraries(dados PRIVATE dados_core)
target_compile_options(dados PRIVATE -sUSE_SDL=2 -Wall -Wextra -Wpedantic)
target_link_options(dados PRIVATE
    -sUSE_SDL=2 -sALLOW_MEMORY_GROWTH=1 -sNO_EXIT_RUNTIME=1
    "-sEXPORTED_RUNTIME_METHODS=['ccall']"
    "SHELL:--shell-file ${CMAKE_CURRENT_SOURCE_DIR}/shell.html"
)
set_target_properties(dados PROPERTIES SUFFIX ".html")
set_property(TARGET dados APPEND PROPERTY LINK_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/shell.html")
foreach(file IN ITEMS app.js styles.css)
    configure_file("${file}" "${file}" COPYONLY)
endforeach()
