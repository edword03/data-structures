cmake_minimum_required(VERSION 3.27)
project(data_structures C)

set(CMAKE_C_STANDARD 99)

add_executable(data_structures main.c
        linked-list/linked_list.h
        linked-list/linked-list.c
)
