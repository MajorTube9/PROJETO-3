cmake_minimum_required(VERSION 3.26)
project(PROJETO_3 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(PROJETO_3
        biblioteca.c
        biblioteca.h
        main.c)
