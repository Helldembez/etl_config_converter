cmake_minimum_required(VERSION 3.20)
project(etl_config_converter C)

set(CMAKE_C_STANDARD 11)

add_executable(etl_config_converter main.c mapping.c string_helper.c mapping.h)
