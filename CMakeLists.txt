cmake_minimum_required(VERSION 3.12)
project(pass_any_across_lib)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN ON)

include(GenerateExportHeader)

include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_library(gen_any_lib SHARED
  genany.cpp
)

generate_export_header(
    gen_any_lib
    BASE_NAME
    "GEN_ANY"
    STATIC_DEFINE
    "GEN_ANY"
)

add_executable(pass_any_across_lib
  main.cpp
)

target_link_libraries(pass_any_across_lib gen_any_lib)

enable_testing()
add_test(NAME pass_any_across_lib COMMAND pass_any_across_lib)
