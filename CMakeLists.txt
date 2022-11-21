cmake_minimum_required(VERSION 3.12)
project(pass_any_across_lib)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(gen_any_lib SHARED
  genany.cpp
)

add_executable(pass_any_across_lib
  main.cpp
)

target_link_libraries(pass_any_across_lib gen_any_lib)

enable_testing()
add_test(NAME pass_any_across_lib COMMAND pass_any_across_lib)
