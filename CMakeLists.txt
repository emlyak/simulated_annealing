cmake_minimum_required(VERSION 3.12)

project(simulated_annealing
    LANGUAGES C CXX
)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES

)

set(HEADERS

)

add_compile_definitions(ANNEALING_EXPORTS)

include_directories(headers)

add_library(${PROJECT_NAME} SHARED ${SOURCES} ${HEADERS})