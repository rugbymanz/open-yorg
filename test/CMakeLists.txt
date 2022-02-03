cmake_minimum_required(VERSION 3.22.1)

set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_BUILD_TYPE Debug)
set(program_name open-yorg)
set(source_dir ./test_src)
set(include_dir ./test_include)
set(compile_options -Wall -pedantic -Wextra)
set(sources Input.cpp)

project(${program_name} LANGUAGES CXX)

find_library(sfml-graphics sfml-graphics REQUIRED)
find_library(sfml-system sfml-system REQUIRED)
find_library(sfml-window sfml-window REQUIRED)

link_libraries(${sfml-graphics} ${sfml-system} ${sfml-window})

include_directories(${include_dir})

set(sources_)
foreach(element ${sources})
    set(dir)
    list(GET source_dir 0 dir)
    set(source_tmp ${dir}/${element})
    list(APPEND sources_  ${source_tmp})
endforeach()
list(APPEND sources_ test.cpp)

message(${sources_})

add_executable(${program_name} ${sources_})
target_compile_options(${program_name} PRIVATE ${compile_options})