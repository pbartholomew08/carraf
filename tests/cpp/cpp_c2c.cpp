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
  const size_t nx = 4;
  const size_t ny = 5;
  const size_t nz = 7;

  // Create a 3-D array with entries 0..n-1 in C-ordering.
  // This illustrates both how to set values by element access, and constructing a const initialised
  // CarraF array through an immediately invoked lambda.
  // XXX: A constructor overload could take an `init` lambda to achieve the same thing.
  const caf::CarraF<int> arr = []()
  {
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

    return arr;
  }();

  // Sequential memory accesses should count from 0..n-1 based on the initialisation.
  int ctr = 0;
  for (const auto itr : arr)
  {
    REQUIRE(itr == ctr);
    ctr++;
  }
}
