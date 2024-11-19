# CarraF

The `carraf` library provides a simple to use 3-D array type that can be type-specialised to either
C- or Fortran-indexing, hence _CarraF_.
In common with `C++ STL` containers the `CarraF` can contain any type and, being based on `STL`
containers is compatible with `STL` algorithms.

## Usage

A `CarraF` array is specialised on the type it contains and the `indexer` which determines its
storage layout, for example a `Fortran` indexed array of `double`s would be instantiated as
```
CarraF<double, findexer> arr(nx, ny, nz);
```
and subsequently indexing the array `arr(i, j, k)` accesses entries with the first index (`i`)
varying fastest as in Fortran.

The storage of the `CarraF` is backed by a `std::vector` which can be accessed by `begin()` and
`end()` iterators, supporting iterator-based code such as
```
for (const auto itr : arr)
{
  std::cout << *itr << std::endl;
}
```
to print the elements of an array in storage-order.

## Building

The `carraf` build system is generated using `cmake`, a typical procedure to configure and build is
```
cmake -B build .
cmake --build build
```
After the initial step further configuration of the build can be performed using the `ccmake` tool.

## Testing

The `carraf` test suite is based on the `Catch2` library and is enabled by default - if the build
system cannot find `Catch2` it will attempt to download and build it as part of the build.
To run the test suite, first build `carraf` and the tests and then run
```
ctest --test-dir build
```
this will run the tests and print their success or failure.

## License

The `carraf` library is licensed under the Apache 2.0 license - see the LICENSE file.
