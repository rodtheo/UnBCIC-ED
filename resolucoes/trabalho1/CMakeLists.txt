# Specify the minimum version for CMake

cmake_minimum_required(VERSION 2.8)

# Project's name
project(trabalho1)

# Set the output folder where your program will be created
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)

# The following folder will be included
include_directories("${PROJECT_SOURCE_DIR}")

#Subdirectories
add_subdirectory(src)
add_subdirectory(tests)

#Unit tests
enable_testing()
add_test(NAME check_pilha COMMAND check_pilha)
