cmake_minimum_required(VERSION 3.24)
project(datastructures C)

set(CMAKE_C_STANDARD 17)

add_executable(datastructures main.c tests/test.h tests/stack_test.c tests/linkedlist_test.c url_tree.c singly_linkedlist.c tests/integer.c hashmap.c arraystack.c arraylist.c tests/arraylist_test.c)
