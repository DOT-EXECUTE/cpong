cmake_minimum_required(VERSION 4.3.4)
project(cpong C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

find_package(SDL3 REQUIRED CONFIG)

file(GLOB SOURCES "src/*.c")

add_executable(cpong ${SOURCES})

target_include_directories(cpong PRIVATE include)
target_link_libraries(cpong PRIVATE SDL3::SDL3)

