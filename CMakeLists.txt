cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

project(heisprosjekt C)

file(GLOB heisprosjekt_SRC "src/*.c")
file(GLOB elevator_driver_SRC "src/elevator_lib/*.c")

set(CMAKE_C_FLAGS "-std=c99")

execute_process(COMMAND git submodule update --init)

include_directories(include Unity/src)

add_definitions(-lcomedi)


add_library(unity_lib Unity/src/unity.c)
add_library(elevator_driver ${elevator_driver_SRC})
target_link_libraries(elevator_driver PRIVATE -lcomedi)

add_library(heisprosjekt_lib ${heisprosjekt_SRC})
target_link_libraries(heisprosjekt_lib elevator_driver)

add_executable(heisprosjekt src/main/main.c)
target_link_libraries(heisprosjekt heisprosjekt_lib)

add_executable(heisprosjekt_test test/TestUnity.c)
target_link_libraries(heisprosjekt_test unity_lib heisprosjekt_lib)


