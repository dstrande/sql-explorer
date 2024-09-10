cmake_minimum_required(VERSION 3.16)

project(sqlExplorer VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(BUILD_SHARED_LIBS FALSE)

set(PROJECT_SOURCES
        src/main.cpp
        src/sqlexplorer.cpp
        src/sqlexplorer.h
        src/sqlexplorer.ui
        src/query.h
        src/credsdialog.cpp
        src/credsdialog.h
        src/credsDialog.ui
)

include_directories("~/.conan2")

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

find_package(libpqxx REQUIRED)
find_package(Qt6 COMPONENTS Widgets REQUIRED)

target_link_libraries(${PROJECT_NAME} libpqxx::pqxx)
target_link_libraries(${PROJECT_NAME} Qt6::Widgets)
