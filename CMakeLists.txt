cmake_minimum_required(VERSION 3.0.0)
project(small_example VERSION 0.1.0)

set(CMAKE_EXPORT_COMPILE_COMMANDS   ON)
set(CMAKE_C_STANDARD                11)
set(CMAKE_C_STANDARD_REQUIRED       ON)
set(CMAKE_C_EXTENSIONS              ON)
set(CMAKE_CXX_STANDARD              20)
set(CMAKE_CXX_STANDARD_REQUIRED     ON)
set(CMAKE_CXX_EXTENSIONS            ON)
set(PROJ_PATH                       ${CMAKE_CURRENT_SOURCE_DIR})
message("Build type: "              ${CMAKE_BUILD_TYPE})

enable_language(C CXX ASM)

add_library(Core src/add.c src/subtract.c)

target_include_directories(Core 
    PUBLIC
        "inc"
)

add_executable(Main main/main.c)

target_link_libraries(Main Core)

#include(CTest)
#enable_testing()
