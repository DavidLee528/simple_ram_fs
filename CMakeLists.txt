cmake_minimum_required(VERSION 3.12)

project(ramfs)

include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(/usr/local/include/tabulate)

add_subdirectory(src)
add_subdirectory(test)
