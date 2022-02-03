cmake_minimum_required(VERSION 3.22.1)

set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_BUILD_TYPE Debug)
set(program_name open-yorg)
set(source_dir .././src)
set(include_dir .././include ./test_include)
set(compile_options -Wall -pedantic -Wextra)

project(${program_name} LANGUAGES CXX)

file(GLOB_RECURSE sources CONFIGURE_DEPENDS ${source_dir}/*/*.cpp ./test_src/*.cpp)
list(APPEND sources ${source_dir}/Algorithms.cpp ${source_dir}/Clock.cpp ${source_dir}/Game.cpp ${source_dir}/GameElements.cpp ${source_dir}/Input.cpp ${source_dir}/Interface.cpp ${source_dir}/ValuesAndTypes.cpp)

find_library(sfml-graphics sfml-graphics REQUIRED)
find_library(sfml-system sfml-system REQUIRED)
find_library(sfml-window sfml-window REQUIRED)

link_libraries(${sfml-graphics} ${sfml-system} ${sfml-window})

include_directories(${include_dir})

add_executable(${program_name} ${sources})
target_compile_options(${program_name} PRIVATE ${compile_options})