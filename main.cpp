#include <iostream>
#include <chrono>
#include "RadixBitSorterInt.h"
#include <algorithm>
#include "IntSorterUtils.h"

static const int32_t arraySize = 1000000;

static const int range = 1000;

int main() {
    std::cout << "Comparing Sorters" << std::endl;

    /* initialize random seed: */
    srand (time(NULL));

    long long totalCpp = 0;
    long long totalRadix = 0;

    for (int j = 0; j < 100; j++)
    {
        // Array of integers
        auto * intArray = new int32_t[arraySize];

        for (int32_t i = 0; i < arraySize; i++)
        {
            intArray[i] = rand() % range + 1;
        }

        auto * intArrayAux = new int32_t[arraySize];
        bit_mask_sorter::IntSorterUtils::arraycopy(intArray, 0, intArrayAux, 0, arraySize);


        // Sort array in ASC order
        std::cout << "Sorted array in ASC order" << std::endl;
        auto start = std::chrono::high_resolution_clock::now();
        std::sort(intArray, intArray + arraySize);
        auto finish = std::chrono::high_resolution_clock::now();

        auto cppTime = (finish - start).count();
        totalCpp+=cppTime;
        std::cout << "Elapsed Time C++   is " << cppTime << std::endl;

        intArrayAux = new int32_t [arraySize];
        bit_mask_sorter::IntSorterUtils::arraycopy(intArray, 0, intArrayAux, 0, arraySize);
        start = std::chrono::high_resolution_clock::now();
        auto* radixBiSorterInt = new bit_mask_sorter::RadixBitSorterInt();
        radixBiSorterInt->sort(intArray, arraySize);
        finish = std::chrono::high_resolution_clock::now();
        auto radixTime = (finish - start).count();
        totalRadix+=radixTime;

        std::cout << "Elapsed Time Radix is  " << radixTime << std::endl;

        std::sort(intArrayAux, intArrayAux + arraySize);

        // Linearly compare elements
        for (int32_t i = 0; i < arraySize; i++)
            if (intArrayAux[i] != intArray[i])
                std::cout << "Arrays are not equal.";


    }
    std::cout << std::endl;
    std::cout << " AVG C++   time: " <<totalCpp/100 << std::endl;
    std::cout << " AVG Radix time: " <<totalRadix/100 << std::endl;

    return 0;
}
