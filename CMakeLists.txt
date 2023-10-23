cmake_minimum_required(VERSION 3.16)

project(Shop VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.4 REQUIRED COMPONENTS Quick DBus)

qt_standard_project_setup()

add_subdirectory(common)
add_subdirectory(serviceSrc)
add_subdirectory(clientSrc)
