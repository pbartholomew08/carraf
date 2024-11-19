/**
 * carraf.h
 *
 * Defines the CarraF 3-D C/F array object.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __CAF_H_
#define __CAF_H_

#include <cstddef>
#include <vector>

namespace caf
{
  /**
   * A utility type representing a 3-D index (i, j, k).
   */
  struct indices : public std::array<size_t, 3>
  {
  };

  /**
   * A utility type representing the extents of a 3-D array (nx, ny, nz).
   */
  struct extents : public std::array<size_t, 3>
  {
  };

  /**
   * A functor class implementing the mapping from coordinates (i,j,k) -> 1-D offset in C ordering.
   */
  class cindexer
  {
   public:
    [[nodiscard]] size_t operator()(const indices idx, const extents n)
    {
      return idx[0] * n[1] * n[2] + idx[1] * n[2] + idx[2];
    }
  };

  /**
   * A functor class implementing the mapping from coordinates (i,j,k) -> 1-D offset in Fortran ordering.
   */
  class findexer
  {
   public:
    [[nodiscard]] size_t operator()(const indices idx, const extents n)
    {
      return idx[0] + idx[1] * n[0] + idx[2] * n[0] * n[1];
    }
  };

  /**
   * The CarraF 3-D array type.
   * @param T The storage type for the array.
   * @param I The indexer class, used to determine the storage ordering.
   */
  template <class T, class I>
  class CarraF
  {
   public:
    /**
     * @param nx The array extent in x.
     * @param ny The array extent in y.
     * @param nz The array extent in z.
     */
    CarraF(const size_t nx, const size_t ny, const size_t nz) : n{nx, ny, nz}
    {
      v.resize(nx * ny * nz);
    }

    /**
     * Element-wise accessor supporting returning and assigning values.
     *
     * @param i The "x axis" index.
     * @param j The "y axis" index.
     * @param k The "z axis" index.
     * @returns A reference to the array entry.
     */
    [[nodiscard]] T& operator()(const size_t i, const size_t j, const size_t k)
    {
      return v[idx(indices{i, j, k}, n)];
    }

    /**
     * @returns The iterator to the beginning of the underlying storage.
     */
    [[nodiscard]] auto begin() const
    {
      return v.begin();
    }

    /**
     * @returns The end iterator of the underlying storage.
     */
    [[nodiscard]] auto end() const
    {
      return v.end();
    }

   private:
    extents n;
    std::vector<T> v;
    I idx;  // Index object
  };
}  // namespace caf

#endif  // __CAF_H_
