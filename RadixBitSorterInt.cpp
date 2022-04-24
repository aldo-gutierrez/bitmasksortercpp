//
// Created by aldo on 4/23/2022.
//

#include "RadixBitSorterInt.h"
#include "BitSorterUtils.h"
#include "IntSorterUtils.h"

void bit_mask_sorter::RadixBitSorterInt::sort(int32_t *array, int32_t aLength) {
    if (aLength < 2) {
        return;
    }
    int32_t start = 0;
    int32_t end = aLength;
    //int32_t ordered = isUnsigned() ? listIsOrderedUnSigned(array, start, end) : listIsOrderedSigned(array, start, end);
    //if (ordered == AnalysisResult.DESCENDING) {
    //    IntSorterUtils.reverse(array, start, end);
    //}
    //if (ordered != AnalysisResult.UNORDERED) return;

    int32_t *maskParts = BitSorterUtils::getMaskBit(array, start, end);
    int32_t mask = maskParts[0] & maskParts[1];
    int32_t kListLength = 0;
    int32_t *kList = BitSorterUtils::getMaskAsArray(mask, kListLength);
    if (kListLength == 0) {
        return;
    }
    if (kList[0] == 31) { //there are negative numbers and positive numbers
        int32_t sortMask = BitSorterUtils::getMaskBit(kList[0]);
        int32_t finalLeft = isUnsigned()
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

void bit_mask_sorter::RadixBitSorterInt::radixSort(int32_t *array, int32_t start, int32_t end, const int32_t *kList, int32_t kIndexStart,
                                  int32_t kIndexEnd, int32_t *aux) {
    for (int32_t i = kIndexStart; i >= kIndexEnd; i--) {
        int32_t kListI = kList[i];
        int32_t maskI = BitSorterUtils::getMaskBit(kListI);
        int32_t bits = 1;
        int32_t imm = 0;
        for (int32_t j = 1; j <= 11; j++) { //11bits looks faster than 8 on AMD 4800H, 15 is slower
            if (i - j >= kIndexEnd) {
                int32_t kListIm1 = kList[i - j];
                if (kListIm1 == kListI + j) {
                    int32_t maskIm1 = BitSorterUtils::getMaskBit(kListIm1);
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
            int32_t twoPowerBits = BitSorterUtils::twoPowerX(bits);
            if (kListI == 0) {
                IntSorterUtils::partitionStableLastBits(array, start, end, maskI, twoPowerBits, aux);
            } else {
                IntSorterUtils::partitionStableGroupBits(array, start, end, maskI, kListI, twoPowerBits, aux);
            }
        }
    }
}
