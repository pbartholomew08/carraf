/**
 * ordering.cpp
 *
 * Tests using a 3-D array in C/F-ordering.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <catch2/catch_test_macros.hpp>

#include <carraf.h>

const size_t nx = 4;
const size_t ny = 5;
const size_t nz = 7;

TEST_CASE("C-indexing")
{
  // Create a 3-D array with entries 0..n-1 in C-ordering.
  // This illustrates both how to set values by element access, and constructing a const initialised
  // CarraF array through an immediately invoked lambda.
  // XXX: A constructor overload could take an `init` lambda to achieve the same thing.
  const auto carr = []()
  {
    caf::CarraF<int, caf::cindexer> arr(nx, ny, nz);
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
  for (const auto itr : carr)
  {
    REQUIRE(itr == ctr);
    ctr++;
  }
}

TEST_CASE("F-indexing")
{
  // Create a 3-D array with entries 0..n-1 in F-ordering.
  // This illustrates both how to set values by element access, and constructing a const initialised
  // CarraF array through an immediately invoked lambda.
  // XXX: A constructor overload could take an `init` lambda to achieve the same thing.
  const auto farr = []()
  {
    caf::CarraF<int, caf::findexer> arr(nx, ny, nz);
    int ctr = 0;
    for (size_t k = 0; k < nz; k++)
    {
      for (size_t j = 0; j < ny; j++)
      {
	for (size_t i = 0; i < nx; i++)
	{
          arr(i, j, k) = ctr;
          ctr++;
        }
      }
    }

    return arr;
  }();

  // Sequential memory accesses should count from 0..n-1 based on the initialisation.
  int fctr = 0;
  for (const auto itr : farr)
  {
    REQUIRE(itr == fctr);
    fctr++;
  }
}
