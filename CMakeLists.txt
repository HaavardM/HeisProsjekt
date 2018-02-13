cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

project(heisprosjekt C)

file(GLOB heisprosjekt_SRC "src/*.c")
file(GLOB elevator_driver_SRC "src/elevator_driver/*.c")

execute_process(COMMAND git submodule update --init)

include_directories(include Unity/src)

add_definitions(-lcomedi)

add_library(unity_lib Unity/src/unity.c)
add_library(elevator_driver ${elevator_driver_SRC})
target_link_libraries(elevator_driver PRIVATE -lcomedi)

add_executable(heisprosjekt ${heisprosjekt_SRC})
target_link_libraries(heisprosjekt elevator_driver)

add_executable(heisprosjekt_test test/TestUnity.c)
target_link_libraries(heisprosjekt_test unity_lib elevator_driver)


