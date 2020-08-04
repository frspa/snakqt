cmake_minimum_required(VERSION 3.13)

project(
  SNAKQT
  LANGUAGES CXX
  VERSION 0.0.1
  DESCRIPTION "The classic game Snake using CMake, Qt and QML"
  HOMEPAGE_URL "https://github.com/frspa/snakqt")

include(CTest GNUInstallDir)

find_package(
  Qt5
  COMPONENTS Core Quick Qml Network
  REQUIRED)

set(CMAKE_AUTOMOC ON)

add_executable(${PROJECT_NAME})
target_sources(
  ${PROJECT_NAME}
  PRIVATE
  src/main.cpp
  #src/qml/qml.qrc
)

target_link_libraries(${PROJECT_NAME}
    Qt5::Core
)
