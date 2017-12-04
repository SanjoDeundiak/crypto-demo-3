cmake_minimum_required(VERSION 3.8)
project(lab3)

set(CMAKE_CXX_STANDARD 11)

file(GLOB_RECURSE SOURCE_FILES src/* src/ext/*)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

find_package(GMP REQUIRED)

add_executable(lab3 ${SOURCE_FILES})

target_link_libraries(lab3 gmp)