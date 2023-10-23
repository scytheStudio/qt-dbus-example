cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.4 REQUIRED COMPONENTS Quick DBus)

qt_add_executable(Client
    main.cpp
    ShopController.h ShopController.cpp
    ShopInterface.h ShopInterface.cpp
)

qt_add_qml_module(Client
    URI Shop
    VERSION 1.0
    QML_FILES Main.qml
)

target_link_libraries(Client
    PRIVATE Qt6::Quick Qt6::DBus commonLib
)
