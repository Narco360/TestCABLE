cmake_minimum_required(VERSION 3.14)

project(Testcable LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Sql) # Ajoute Sql ici
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Sql) # Ajoute Sql ici

add_executable(Testcable
  main.cpp
)

target_link_libraries(Testcable Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Sql) # Ajoute Sql ici

include(GNUInstallDirs)
install(TARGETS Testcable
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
