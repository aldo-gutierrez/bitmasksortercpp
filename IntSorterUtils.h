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
        static int32_t partitionNotStable(int32_t *array, int32_t start, int32_t end, int32_t mask);

        static int32_t partitionReverseNotStable(int32_t *array, int32_t start, int32_t end, int32_t mask);

        static int32_t partitionStable(int32_t *array, int32_t start, int32_t end, int32_t mask, int32_t *aux);

        static void partitionStableLastBits(int32_t *array, int32_t start, int32_t end, int32_t mask, int32_t twoPowerK,
                                            int32_t *aux);

        static void partitionStableGroupBits(int32_t *array, int32_t start, int32_t end, int32_t mask, int32_t shiftRight,
                                 int32_t twoPowerK, int32_t *aux);

        static void arraycopy(int32_t *pSrc, int srcPos, int32_t *pDest, int32_t destPos, int32_t length);
    };
}

#endif //BITMASKSORTER_INTSORTERUTILS_H
