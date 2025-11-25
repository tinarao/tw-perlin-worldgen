cmake_minimum_required(VERSION 4.0)
project(topdown_world_generation CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(PkgConfig REQUIRED)
pkg_check_modules(RAYLIB REQUIRED raylib)

add_executable(${PROJECT_NAME} main.cpp
        tile.h)

target_compile_options(${PROJECT_NAME} PRIVATE
        -Wall
        -Wextra
)

target_link_libraries(${PROJECT_NAME} ${RAYLIB_LIBRARIES})
target_include_directories(${PROJECT_NAME} PRIVATE ${RAYLIB_INCLUDE_DIRS})
target_compile_options(${PROJECT_NAME} PRIVATE ${RAYLIB_CFLAGS_OTHER})

set_target_properties(${PROJECT_NAME} PROPERTIES
        DEBUG_POSTFIX "_debug"
)

target_compile_definitions(${PROJECT_NAME} PRIVATE $<$<CONFIG:Debug>:DEBUG>)
