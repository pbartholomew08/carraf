# CMakeLists.txt
#
# The CMake configuration for the carraf C++ test suite.
#
# SPDX-License-Identifier: Apache-2.0

add_executable(cpp_c2c cpp_c2c.cpp)
target_include_directories(cpp_c2c PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(cpp_c2c PRIVATE Catch2::Catch2WithMain)
catch_discover_tests(cpp_c2c)
