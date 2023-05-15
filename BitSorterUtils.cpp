//
// Created by aldo on 4/22/2022.
//

#include "BitSorterUtils.h"
int32_t *bit_mask_sorter::BitSorterUtils::getMaskBit(const int32_t *array, size_t start, size_t endP1) {
    int32_t mask = 0x00000000;
    int32_t inv_mask = 0x00000000;
    for (size_t i = start; i < endP1; i++) {
        int32_t ei = array[i];
        mask = mask | ei;
        inv_mask = inv_mask | (~ei);
    }
    return new int32_t[]{mask, inv_mask};
}

int32_t *bit_mask_sorter::BitSorterUtils::getMaskAsArray(int32_t mask, size_t &size) {
    std::vector <int32_t> list;
    for (int32_t i = 31; i >= 0; i--) {
        if (((mask >> i) & 1) == 1) {
            list.push_back(i);
        }
    }
    size = list.size();
    auto *res = new int32_t[list.size()];
    for (size_t  i = 0; i < list.size(); i++) {
        res[i] = list[i];
    }
    return res;
}


