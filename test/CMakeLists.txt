cmake_minimum_required(VERSION 3.13)

set(CMAKE_AUTOMOC ON)

# retrieve googletest from github
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.10.0)

FetchContent_GetProperties(googletest)
if(NOT googletest_POPULATED)
  FetchContent_Populate(googletest)
  add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
endif()

find_package(
  Qt5
  COMPONENTS Core Test
  REQUIRED)

find_package(OpenCV REQUIRED)

add_executable(unit_tests)

target_sources(
  unit_tests
  PRIVATE
  src/main.cpp
  src/toolchain_test.cpp
  src/board_test.cpp)

target_compile_features(unit_tests PRIVATE cxx_std_17)
target_include_directories(
  unit_tests
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${GTEST_INCLUDE_DIRS}
          ${PROJECT_SOURCE_DIR}/src ${PROJECT_SOURCE_DIR}/src/libSnakqt)

target_link_libraries(
  unit_tests
  PRIVATE gtest
          gmock
          Qt5::Core
          Qt5::Test
          ${OpenCV_LIBRARIES}
          libSnakqt::libSnakqt)

target_compile_options(
  unit_tests
  PRIVATE $<$<OR:$<CXX_COMPILER_ID:GNU>,$<CXX_COMPILER_ID:Clang>>:-Wall>
          $<$<OR:$<CXX_COMPILER_ID:GNU>,$<CXX_COMPILER_ID:Clang>>:-Werror>
          $<$<OR:$<CXX_COMPILER_ID:GNU>,$<CXX_COMPILER_ID:Clang>>:-pedantic>)

add_test(NAME unit_tests COMMAND unit_tests)
