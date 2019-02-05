cmake_minimum_required(VERSION 3.13)
project(osubuffer C)

set(CMAKE_C_STANDARD 89)

include_directories(include)

add_library(osubuffer STATIC
        include/buffer.h src/buffer.c)

