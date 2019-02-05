cmake_minimum_required(VERSION 3.13)
project(osubuffer C)

set(CMAKE_C_STANDARD 11)

include_directories(include)

add_library(osubuffer STATIC
        include/buffer.h src/buffer.c

        )

add_executable(osu_buffer_playground main)
target_link_libraries(osu_buffer_playground osubuffer)
