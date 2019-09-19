cmake_minimum_required(VERSION 3.14)
project(tools C)

set(CMAKE_C_STANDARD 99)

add_executable(argparse opt/argparse.c opt/argparsetest.c)
target_include_directories(argparse PRIVATE include/opt)

add_executable(tools main.c)
target_include_directories(tools PRIVATE include)
