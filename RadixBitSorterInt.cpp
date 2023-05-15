//
// Created by aldo on 4/23/2022.
//

#include "RadixBitSorterInt.h"
#include "BitSorterUtils.h"
#include "IntSorterUtils.h"

void bit_mask_sorter::RadixBitSorterInt::sort(int32_t *array, size_t aLength) {
    if (aLength < 2) {
        return;
    }
    size_t start = 0;
    size_t end = aLength;

    int32_t *maskParts = BitSorterUtils::getMaskBit(array, start, end);
    int32_t mask = maskParts[0] & maskParts[1];
    size_t kListLength = 0;
    int32_t *kList = BitSorterUtils::getMaskAsArray(mask, kListLength);
    if (kListLength == 0) {
        return;
    }
    if (kList[0] == 31) { //there are negative numbers and positive numbers
        int32_t sortMask = 1 << kList[0];
        size_t finalLeft = isUnsigned()
                            ? IntSorterUtils::partitionNotStable(array, start, end, sortMask)
                            : IntSorterUtils::partitionReverseNotStable(array, start, end, sortMask);
        if (finalLeft - start > 1) { //sort negative numbers
            auto *aux = new int32_t[finalLeft - start];
            maskParts = BitSorterUtils::getMaskBit(array, start, finalLeft);
            mask = maskParts[0] & maskParts[1];
            kList = BitSorterUtils::getMaskAsArray(mask, kListLength);
            radixSort(array, start, finalLeft, kList, kListLength - 1, 0, aux);
            delete[] aux;
            delete[] maskParts;
            delete[] kList;
        }
        if (end - finalLeft > 1) { //sort positive numbers
            auto * aux = new int32_t[end - finalLeft];
            maskParts = BitSorterUtils::getMaskBit(array, finalLeft, end);
            mask = maskParts[0] & maskParts[1];
            kList = BitSorterUtils::getMaskAsArray(mask, kListLength);
            radixSort(array, finalLeft, end, kList, kListLength - 1, 0, aux);
            delete[] aux;
            delete[] maskParts;
            delete[] kList;
        }
    } else {
        auto *aux = new int32_t[end - start];
        radixSort(array, start, end, kList, kListLength - 1, 0, aux);
        delete[] aux;
        delete[] maskParts;
        delete[] kList;
    }
}

void bit_mask_sorter::RadixBitSorterInt::radixSort(int32_t *array, size_t start, size_t end, const int32_t *kList, size_t kIndexStart,
                                                   size_t kIndexEnd, int32_t *aux) {
    for (size_t i = kIndexStart; i >= kIndexEnd; i--) {
        int32_t kListI = kList[i];
        int32_t maskI = 1 << kListI;
        int32_t bits = 1;
        int32_t imm = 0;
        for (size_t j = 1; j <= 11; j++) { //11bits looks faster than 8 on AMD 4800H, 15 is slower
            if (i - j >= kIndexEnd) {
                int32_t kListIm1 = kList[i - j];
                if (kListIm1 == kListI + j) {
                    int32_t maskIm1 = 1 << kListIm1;
                    maskI = maskI | maskIm1;
                    bits++;
                    imm++;
                } else {
                    break;
                }
            }
        }
        i -= imm;
        if (bits == 1) {
            IntSorterUtils::partitionStable(array, start, end, maskI, aux);
        } else {
            int32_t twoPowerBits = 1 << bits;
            if (kListI == 0) {
                IntSorterUtils::partitionStableLastBits(array, start, end, maskI, twoPowerBits, aux);
            } else {
                IntSorterUtils::partitionStableGroupBits(array, start, end, maskI, kListI, twoPowerBits, aux);
            }
        }
        if (i == 0) { //this problem only happens in C++, nor in javascript, nor java
            return;
        }
    }
}
