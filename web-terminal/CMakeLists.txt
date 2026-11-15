cmake_minimum_required(VERSION 3.20)
project(EscaleraOriginalWeb LANGUAGES CXX)
if(NOT EMSCRIPTEN)
    message(FATAL_ERROR "Use emcmake cmake to build the original browser terminal.")
endif()
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(ROOT "${CMAKE_CURRENT_SOURCE_DIR}/..")
add_executable(original bridge.cpp
    "${ROOT}/main.cpp" "${ROOT}/condiciones.cpp" "${ROOT}/funciones.cpp"
    "${ROOT}/graficosDados.cpp" "${ROOT}/menues.cpp" "${ROOT}/modo_solitario.cpp"
    "${ROOT}/multijugador.cpp" "${ROOT}/ranking.cpp" "${ROOT}/vectores.cpp")
set_source_files_properties("${ROOT}/main.cpp" PROPERTIES COMPILE_DEFINITIONS "main=console_main")
target_compile_options(original PRIVATE -Wall -Wextra)
target_link_options(original PRIVATE -sASYNCIFY -sASYNCIFY_STACK_SIZE=131072
    -sALLOW_MEMORY_GROWTH=1 -sEXIT_RUNTIME=1
    "SHELL:--shell-file ${CMAKE_CURRENT_SOURCE_DIR}/shell.html")
set_target_properties(original PROPERTIES SUFFIX ".html")
set_property(TARGET original APPEND PROPERTY LINK_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/shell.html")

set(XTERM "${CMAKE_CURRENT_SOURCE_DIR}/node_modules/@xterm/xterm")
if(NOT EXISTS "${XTERM}/lib/xterm.js")
    message(FATAL_ERROR "Install xterm.js first: npm ci --prefix web-terminal")
endif()
foreach(file IN ITEMS app.js styles.css)
    configure_file("${file}" "${file}" COPYONLY)
endforeach()
configure_file("${XTERM}/lib/xterm.js" "xterm.js" COPYONLY)
configure_file("${XTERM}/css/xterm.css" "xterm.css" COPYONLY)
configure_file("${XTERM}/LICENSE" "xterm-LICENSE.txt" COPYONLY)
