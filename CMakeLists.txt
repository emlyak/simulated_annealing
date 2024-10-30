cmake_minimum_required(VERSION 3.12)

project(simulated_annealing
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES
    src/salesman.cpp
    src/min.cpp
)

file(GLOB_RECURSE HEADERS
    headers/dllexport.h
    headers/includes.h
    headers/metrics.hpp
    headers/Pount.h
    headers/simulated_annealing.h
)

add_compile_definitions(ANNEALING_EXPORTS)

include_directories(headers)

add_library(${PROJECT_NAME} SHARED ${SOURCES} ${HEADERS})