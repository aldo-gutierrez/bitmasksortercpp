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
        static int32_t getMaskBit(int32_t k);

        static int32_t *getMaskAsArray(int32_t mask, int32_t &size);

        static int32_t *getMaskBit(const int32_t *array, int32_t start, int32_t end);

        static int32_t twoPowerX(int32_t k);
    };
}



#endif //BITMASKSORTER_BITSORTERUTILS_H
