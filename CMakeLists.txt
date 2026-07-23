cmake_minimum_required(VERSION 4.3.4)

project(cpong C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

find_package(SDL3 REQUIRED CONFIG)
find_package(SDL3_ttf REQUIRED CONFIG)

file(GLOB SOURCES "src/*.c")

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(cpong PRIVATE include)
target_link_libraries(${PROJECT_NAME} PRIVATE SDL3_ttf::SDL3_ttf SDL3::SDL3)
