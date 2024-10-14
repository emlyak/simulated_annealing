cmake_minimum_required(VERSION 3.12)

project(simulated_annealing
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE SOURCES
    "src/*,cpp"
)
set(SOURCES
    src/salesman.cpp
)

file(GLOB_RECURSE HEADERS
    "headers/*.h"
    "headers/*.hpp"
)

add_compile_definitions(ANNEALING_EXPORTS)

include_directories(headers)

add_library(${PROJECT_NAME} SHARED ${SOURCES} ${HEADERS})