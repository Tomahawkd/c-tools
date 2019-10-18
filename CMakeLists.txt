cmake_minimum_required(VERSION 3.14)
project(tools C)

set(CMAKE_C_STANDARD 99)

include_directories(include)

set(ARG_SRC)
aux_source_directory(opt ARG_SRC)
add_executable(argparsetest ${ARG_SRC} test/argparsetest.c)

set(RAND_SRC)
aux_source_directory(random RAND_SRC)
add_executable(randomtest ${RAND_SRC} test/randomtest.c)
