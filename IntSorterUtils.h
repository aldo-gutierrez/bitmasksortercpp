//
// Created by aldo on 4/23/2022.
//

#ifndef BITMASKSORTER_INTSORTERUTILS_H
#define BITMASKSORTER_INTSORTERUTILS_H

#include <cstdint>
#include <list>
#include <vector>

namespace bit_mask_sorter {
    class IntSorterUtils {
    public:
        static size_t partitionNotStable(int32_t *array, size_t start, size_t end, int32_t mask);

        static size_t partitionReverseNotStable(int32_t *array, size_t start, size_t end, int32_t mask);

        static int32_t partitionStable(int32_t *array, size_t start, size_t end, int32_t mask, int32_t *aux);

        static void partitionStableLastBits(int32_t *array, size_t start, size_t end, int32_t mask, int32_t twoPowerK,
                                            int32_t *aux);

        static void partitionStableGroupBits(int32_t *array, size_t start, size_t end, int32_t mask, int32_t shiftRight,
                                             int32_t twoPowerK, int32_t *aux);

        static void arraycopy(int32_t *pSrc, size_t srcPos, int32_t *pDest, size_t destPos, size_t length);
    };
}

#endif //BITMASKSORTER_INTSORTERUTILS_H
