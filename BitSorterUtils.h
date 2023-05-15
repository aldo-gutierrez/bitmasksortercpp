//
// Created by aldo on 4/22/2022.
//

#ifndef BITMASKSORTER_BITSORTERUTILS_H
#define BITMASKSORTER_BITSORTERUTILS_H

#include <cstdint>
#include <list>
#include <vector>

namespace bit_mask_sorter {
    class BitSorterUtils {
    public:

        static int32_t *getMaskAsArray(int32_t mask, size_t &size);

        static int32_t *getMaskBit(const int32_t *array, size_t start, size_t endP1);

    };
}



#endif //BITMASKSORTER_BITSORTERUTILS_H
