cmake_minimum_required(VERSION 3.12)
project(test C)

set(CMAKE_C_STANDARD 11)

add_executable(test test.c datatype.c datatype.h bstree.c bstree.h matrix.c matrix.h main.c)