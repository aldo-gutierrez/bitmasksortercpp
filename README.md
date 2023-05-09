# Mask Bit Sorters C++
This project tests different ideas for sorting algorithms that use a BitMask.
We use a radix sort that uses a bitmask to reduce the number of iterations

See the initial implementation in java for more information.
[Java Version and Documentation] (https://github.com/aldo-gutierrez/bitmasksorter)

Only RadixBitSorter is implemented for now in this project

## RadixBitSorter:
RadixBitSorter is a Radix Sorter that uses the bitmask to reduce the number of count sort passes 
and the bits used have been increased to 11 from standard 8

# Speed
Comparison for sorting 1 Million int elements with range from 0 to 1000.

AMD Ryzen 7 4800H processor Performance Mode, Debug Mode, MinGW w64 9.0, CMake 3.25.2, GDB 13.1, default CLion 2023.1.2 Configuration

| Algorithm         | AVG CPU time [ns] | AVG CPU time [ms] |
|-------------------|------------------:|------------------:|
| C++ std::sort     |          96314255 |                96 |
| RadixBitSorterInt |           9904475 |                10 |
| Ska Sort          |          48879965 |                49 |

Comparison for sorting 1 Million int elements with range from 0 to 1000  in an AMD Ryzen 7 4800H processor,

AMD Ryzen 7 4800H processor Performance Mode, Release Mode, MinGW w64 9.0, CMake 3.25.2, GDB 13.1, default CLion 2023.1.2 Configuration


| Algorithm         | AVG CPU time [ns] | AVG CPU time [ms] |
|-------------------|------------------:|------------------:|
| C++ std::sort     |          33102600 |                33 |
| RadixBitSorterInt |           4985560 |                 5 |
| Ska Sort          |          11034395 |                11 |

The times are in line with the java times were Java sort took 36ms. and RadixBitSorterInt 5ms. 


Comparison for sorting 40 Million int elements with range from 0 to 1000 Million

AMD Ryzen 7 4800H processor Performance Mode, Release Mode, MinGW w64 9.0, CMake 3.25.2, GDB 13.1, default CLion 2023.1.2 Configuration


| Algorithm         |   AVG CPU time [ns] | AVG CPU time [ms] |
|-------------------|--------------------:|------------------:|
| C++ std::sort     |          1800773695 |              1800 |
| RadixBitSorterInt |           398003770 |               398 |
| Ska Sort          |           428653195 |               428 |

As expected if we increment the range the difference between RadixBitSorterInt and Ska Sort is reduced.

# TODO
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
