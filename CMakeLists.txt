cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

project(heisprosjekt C)

file(GLOB heisprosjekt_SRC "src/*.c")

execute_process(COMMAND git submodule update --init)

include_directories(include Unity/src)

add_library(unity_lib Unity/src/unity.c)

add_executable(heisprosjekt ${heisprosjekt_SRC})

add_executable(heisprosjekt_test test/TestUnity.c)
target_link_libraries(heisprosjekt_test unity_lib)


