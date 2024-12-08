# CMakeLists.txt
#
# The CMake configuration for the carraf tests.
#
# SPDX-License-Identifier: Apache-2.0

enable_testing()

find_package(Catch2 3)
if (NOT Catch2_FOUND)
  #
  # The following code is recommended by the Catch2 developers to integrate Catch2, it is used here
  # in the case that a local install of Catch2 cannot be found.
  #
  # Boost Software License - Version 1.0 - August 17th, 2003
  # 
  # Permission is hereby granted, free of charge, to any person or organization
  # obtaining a copy of the software and accompanying documentation covered by
  # this license (the "Software") to use, reproduce, display, distribute,
  # execute, and transmit the Software, and to prepare derivative works of the
  # Software, and to permit third-parties to whom the Software is furnished to
  # do so, all subject to the following:
  # 
  # The copyright notices in the Software and this entire statement, including
  # the above license grant, this restriction and the following disclaimer,
  # must be included in all copies of the Software, in whole or in part, and
  # all derivative works of the Software, unless such copies or derivative
  # works are solely in the form of machine-executable object code generated by
  # a source language processor.
  # 
  # THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  # IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  # FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
  # SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
  # FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
  # ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
  # DEALINGS IN THE SOFTWARE.
  #
  Include(FetchContent)

  FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG        v3.4.0 # or a later release
  )

  FetchContent_MakeAvailable(Catch2)
  #
  # End Catch2 code
  #
endif()
include(Catch)

add_subdirectory(cpp)
