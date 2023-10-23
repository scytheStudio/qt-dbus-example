cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.4 REQUIRED COMPONENTS Quick DBus)

qt_add_executable(Service
    serviceMain.cpp
    Shop.h Shop.cpp
    ShopAdaptor.h ShopAdaptor.cpp
)

target_link_libraries(Service
    PRIVATE Qt6::DBus commonLib
)
