cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(template-hell VERSION 0.1)

# Generate compile_commands.json for IDEs and tools
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD_INCLUDE_DIRECTORIES ${CMAKE_CXX_IMPLICIT_INCLUDE_DIRECTORIES})

add_compile_options (-fdiagnostics-color=always)
add_compile_options(-Wextra -Wall -Wpedantic -std=c++20)

# Linking all to test driver
add_executable(program main.cpp)
add_executable(solutions-program Solutions/typelevel_set1.cpp)

# vim: shiftwidth=2:
