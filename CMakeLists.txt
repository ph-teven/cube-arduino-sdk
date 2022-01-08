cmake_minimum_required(VERSION 3.13)

project("cube-arduino-sdk" C CXX)

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_C_COMPILER_WORKS 1)
set(CMAKE_CXX_COMPILER_WORKS 1)
set(CMAKE_CXX_STANDARD 11)

include_directories("${CMAKE_CURRENT_LIST_DIR}/examples")
include_directories("${CMAKE_CURRENT_LIST_DIR}/src")

add_subdirectory(examples)
add_subdirectory(src)
add_subdirectory(test)
