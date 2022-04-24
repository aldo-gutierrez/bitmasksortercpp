# Mask Bit Sorters C++
This project tests different ideas for sorting algorithms.
We use a bitmask as a way to get statistical information about the numbers to be sorted.
All the algorithms use this bitmask.

See the initial implementation in java for more information.
[Java Version and Documentation] (https://github.com/aldo-gutierrez/bitmasksorter)

Only RadixBitSorter is implemented for now in this project

## RadixBitSorter:
RadixBitSorter is a Radix Sorter that uses the bitmask to make a LSD sorting using bits instead of bytes
upto 11 bits at a time.

# Speed
Comparison for sorting 1 Million int elements with range from 0 to 1000 in an AMD Ryzen 7 4800H processor,
Debug Mode, MinGW w64 9.0, CMake 3.22.3, GDB 11.1, default CLion 2022.1 Configuration

| Algorithm         | AVG CPU time [ns] | AVG CPU time [ms] |
|-------------------|------------------:|------------------:|
| C++ std::sort     |         105978879 |               106 |
| RadixBitSorterInt |          13093120 |                13 |
| Ska Sort          |          51864353 |                52 |

Comparison for sorting 1 Million int elements with range from 0 to 1000  in an AMD Ryzen 7 4800H processor,
Release Mode, MinGW w64 9.0, CMake 3.22.3, GDB 11.1, default CLion 2022.1 Configuration


| Algorithm         | AVG CPU time [ns] | AVG CPU time [ms] |
|-------------------|------------------:|------------------:|
| C++ std::sort     |          34834473 |                34 |
| RadixBitSorterInt |           5664794 |                 6 |
| Ska Sort          |          11600489 |                12 |

The times are in line with the java times were Java sort took 36ms. and RadixBitSorterInt 5ms.

And as expected if we increment the range the difference between RadixBitSorterInt and Ska Sort is reduced to almost 0.

Comparison for sorting 40 Million int elements with range from 0 to 1000 Million in an AMD Ryzen 7 4800H processor,
Release Mode, MinGW w64 9.0, CMake 3.22.3, GDB 11.1, default CLion 2022.1 Configuration


| Algorithm         |   AVG CPU time [ns] | AVG CPU time [ms] |
|-------------------|--------------------:|------------------:|
| C++ std::sort     |          1903686759 |              1904 |
| RadixBitSorterInt |           445662125 |               446 |
| Ska Sort          |           443268867 |               443 |

# TODO
- Use size_t for indexes
- Use inline for some small methods
- Make more graphs
- Review memory usage
- Learn C++
- Use a SIMD library
- Port other algorithms from Java repository
- Learn C
- Compare to Wolf Sort
- Learn C++ Templates

# References:
[Ska Sort] (https://github.com/skarupke/ska_sort)
[Wolf Sort] (https://github.com/scandum/wolfsort)
