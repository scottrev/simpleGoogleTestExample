cmake_minimum_required(VERSION 3.0.0)
project(small_example VERSION 0.1.0)

include(GoogleTest)
include(CTest)


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

add_library(Core src/add.c src/subtract.c src/fib.c)

target_include_directories(Core 
    PUBLIC
        "inc"
)

add_executable(Main main/main.c)

target_link_libraries(Main Core)

set (gtest_force_shared_crt ON CACHE BOOL "MSVC defaults to shared CRT" FORCE)
add_subdirectory(third_party/googletest)
target_compile_definitions(gtest
  PUBLIC
    GTEST_LANG_CXX20
    GTEST_HAS_TR1_TUPLE=0
)
add_executable(tests)
target_sources(tests
  PRIVATE
    tests/unit_tests/SomeTest.cpp
    tests/unit_tests/fib_test.cpp
)

enable_testing()

set_target_properties(tests PROPERTIES COMPILE_FLAGS "${cxx_strict}")
target_link_libraries(tests gtest gtest_main Core)

add_test(NAME please COMMAND tests)
