cmake_minimum_required(VERSION 3.22)
project(bitMaskSorter)

set(CMAKE_CXX_STANDARD 14)

add_executable(bitMaskSorter main.cpp BitSorterUtils.cpp BitSorterUtils.h IntSorterUtils.cpp IntSorterUtils.h IntSorter.cpp IntSorter.h Sorter.cpp Sorter.h RadixBitSorterInt.cpp RadixBitSorterInt.h)
