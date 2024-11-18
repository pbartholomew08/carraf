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
   * The CarraF 3-D array type.
   */
  template <class T>
  class CarraF
  {
   public:
    /**
     * @param nx The array extent in x.
     * @param ny The array extent in y.
     * @param nz The array extent in z.
     */
    CarraF(const size_t nx, const size_t ny, const size_t nz) : nx(nx), ny(ny), nz(nz)
    {
      const size_t nelt = nx * ny * nz;
      v.resize(nelt);
    }

    /**
     * Array subscript accessor.
     *
     * @param i The "x axis" index.
     * @param j The "y axis" index.
     * @param k The "z axis" index.
     * @returns A reference to the array entry, allowing use as a value and in assignments.
     */
    [[nodiscard]] T& operator()(const size_t i, const size_t j, const size_t k)
    {
      const size_t idx = i * ny * nz + j * nz + k;

      return v[idx];
    }

    /**
     * @returns The iterator to the beginning of the underlying storage.
     */
    [[nodiscard]] auto begin()
    {
      return v.begin();
    }

    /**
     * @returns The end iterator of the underlying storage.
     */
    [[nodiscard]] auto end()
    {
      return v.end();
    }

   private:
    size_t nx, ny, nz;
    std::vector<T> v;
  };
}  // namespace caf

#endif  // __CAF_H_
