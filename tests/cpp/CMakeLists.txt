# CMakeLists.txt
#
# The CMake configuration for the carraf C++ test suite.
#
# SPDX-License-Identifier: Apache-2.0

add_executable(ordering ordering.cpp)
target_include_directories(ordering PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(ordering PRIVATE Catch2::Catch2WithMain)
catch_discover_tests(ordering)
