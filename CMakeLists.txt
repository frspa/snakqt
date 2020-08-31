cmake_minimum_required(VERSION 3.13)

# Project Information
project(
  SNAKQT
  LANGUAGES CXX
  VERSION 0.0.1
  DESCRIPTION "The classic game Snake using CMake, Qt and QML"
  HOMEPAGE_URL "https://github.com/frspa/snakqt")

include(CTest GNUInstallDir)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# STEP1: System libraries
find_package(
  Qt5
  COMPONENTS Core Quick Qml Network
  REQUIRED)
find_package(OpenCV REQUIRED)
find_package(Threads REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(SYSTEMD REQUIRED libsystemd)

# STEP2: Create internal library
add_library(libSnakqt STATIC)
add_library(libSnakqt::libSnakqt ALIAS libSnakqt)

# Components of internal library
target_sources(
    libSnakqt
    PRIVATE
    src/libSnakqt/startup.hpp
    src/libSnakqt/startup.cpp)

target_compile_features(libSnakqt PRIVATE cxx_std_17)
target_compile_definitions(
  libSnakqt PRIVATE
  $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)

target_compile_options(
  libSnakqt
  PRIVATE $<$<OR:$<CXX_COMPILER_ID:GNU>,$<CXX_COMPILER_ID:Clang>>:-Wall>
          $<$<OR:$<CXX_COMPILER_ID:GNU>,$<CXX_COMPILER_ID:Clang>>:-Werror>
          $<$<OR:$<CXX_COMPILER_ID:GNU>,$<CXX_COMPILER_ID:Clang>>:-Weffc++>
          $<$<OR:$<CXX_COMPILER_ID:GNU>,$<CXX_COMPILER_ID:Clang>>:-pedantic>)

# Internal library is linked with system dependencies.
target_link_libraries(
    libSnakqt
    PRIVATE Qt5::Core Qt5::Quick Qt5::Network Threads::Threads ${OpenCV_LIBRARIES})

target_include_directories(libSnakqt PRIVATE src/)
target_include_directories(
  libSnakqt
  INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
            $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/libSnakqt)

# STEP3: Compile and link the project
add_executable(${PROJECT_NAME})
target_sources(
  ${PROJECT_NAME}
  PRIVATE
  src/main.cpp
  src/appSnakqt/qml.qrc
)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

target_compile_definitions(
  ${PROJECT_NAME} PRIVATE
  $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>
  BUILD_VERSION_STRING="${PROJECT_VERSION}")

target_compile_options(
  ${PROJECT_NAME}
  PRIVATE $<$<OR:$<CXX_COMPILER_ID:GNU>,$<CXX_COMPILER_ID:Clang>>:-Wall>
          $<$<OR:$<CXX_COMPILER_ID:GNU>,$<CXX_COMPILER_ID:Clang>>:-Werror>
          $<$<OR:$<CXX_COMPILER_ID:GNU>,$<CXX_COMPILER_ID:Clang>>:-Weffc++>
          $<$<OR:$<CXX_COMPILER_ID:GNU>,$<CXX_COMPILER_ID:Clang>>:-pedantic>)

# Link main application with internal and system library
target_link_libraries(
  ${PROJECT_NAME}
  PRIVATE Qt5::Core
          Qt5::Quick
          Qt5::Network
          Threads::Threads
          systemd
          ${OpenCV_LIBRARIES}
          libSnakqt::libSnakqt)

target_include_directories(${PROJECT_NAME} PRIVATE src/ src/libSnakqt)

# STEP4: Add unit tests
add_subdirectory(test)
