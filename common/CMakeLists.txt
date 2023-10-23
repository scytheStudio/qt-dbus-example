cmake_minimum_required(VERSION 3.16)

project(commonLib VERSION 1.0.1 DESCRIPTION "common library for common use classes.")

find_package(Qt6 6.4 REQUIRED COMPONENTS DBus)

add_library(commonLib SHARED
    datasets/Product.h datasets/Product.cpp
)

target_link_libraries(commonLib PRIVATE Qt6::DBus)
