# CMakeLists.txt
#
# The CMake configuration for the carraf project.
#
# SPDX-License-Identifier: Apache-2.0

## Toolchain settings
set(CMAKE_CXX_FLAGS_INIT "-Wall -Wpedantic -Werror")

## General configuration
cmake_minimum_required(VERSION 3.5)

project(carraf
  LANGUAGES CXX
  VERSION 0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(GNUInstallDirs)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

## Tests
include(CTest)
if (BUILD_TESTING)
  add_subdirectory(tests)
endif()
