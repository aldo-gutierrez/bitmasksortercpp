# BitMask Sorters C++

This project explores various sorting algorithms employing a BitMask approach. 
One of the algorithms is a Radix Sort utilizing a BitMask to minimize the number of Count Sort iterations required.

The following code demonstrates the calculation of the BitMask:

```
    int32_t bit_mask_sorter::BitSorterUtils::getMaskBit(const int32_t *array, size_t start, size_t endP1) {
        int32_t mask = 0x00000000;
        int32_t inv_mask = 0x00000000;
        for (size_t i = start; i < endP1; i++) {
            int32_t ei = array[i];
            mask = mask | ei;
            inv_mask = inv_mask | (~ei);
        }
        return mask & inv_mask;
    }
```

For further details, refer to the initial Java implementation
[Java Version and Documentation] (https://github.com/aldo-gutierrez/bitmasksorter)

## RadixBitSorter:
RadixBitSorter is the implementation of a Radix Sort utilizing a BitMask to minimize the number of Count Sort iterations required.

The number of bits per iteration has been increased to 11, departing from the standard 8.

# Speed

### Comparison for sorting 1 million integer(int) elements ranging from 0 to 1000.

AMD Ryzen 7 4800H processor Performance Mode, Release Mode, MinGW w64 9.0, CMake 3.25.2, GDB 13.1, default CLion 2023.1.2 Configuration


| Algorithm         | AVG CPU time [ns] | AVG CPU time [ms] |
|-------------------|------------------:|------------------:|
| C++ std::sort     |          33102600 |                33 |
| RadixBitSorterInt |           4985560 |                 5 |
| Ska Sort          |          11034395 |                11 |

The times are in line with the java times were Java sort took 36ms. and RadixBitSorterInt 5ms. 

### Comparison for sorting 40 million integer(int) elements ranging from 0 to 1000 million.

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
