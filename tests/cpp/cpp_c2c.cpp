/**
 * cpp_c2c.cpp
 *
 * Tests using a 3-D array in C-ordering.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <catch2/catch_test_macros.hpp>

#include <carraf.h>

TEST_CASE("Basic")
{
  // Create a 3-D array with entries 0..n-1 in C-ordering
  const size_t nx = 4;
  const size_t ny = 5;
  const size_t nz = 7;
  
  caf::CarraF<int> arr(nx, ny, nz);
  int ctr = 0;
  for (size_t i = 0; i < nx; i++)
  {
    for (size_t j = 0; j < ny; j++)
    {
      for (size_t k = 0; k < nz; k++)
      {
	arr(i, j, k) = ctr;
	ctr++;
      }
    }
  }

  // Check that memory contents matches expectation 0..n-1
  ctr = 0;
  for (const auto it : arr)
  {
    REQUIRE(it == ctr);
    ctr++;
  }
}
