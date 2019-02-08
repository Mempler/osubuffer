cmake_minimum_required(VERSION 3.13)
project(osubuffer_example C)

set(CMAKE_C_STANDARD 90)

add_subdirectory(..)

add_executable(buffer main.c)
target_link_libraries(buffer osubuffer)