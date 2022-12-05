cmake_minimum_required(VERSION 3.12)

project(ranfs)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_subdirectory(src)
add_subdirectory(test)