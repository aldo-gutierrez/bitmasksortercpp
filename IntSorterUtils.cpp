//
// Created by aldo on 4/23/2022.
//


#include <cstdint>
#include <cstring>
#include "IntSorterUtils.h"

void swap(int32_t* array, int32_t left, int32_t right) {
    int32_t aux = array[left];
    array[left] = array[right];
    array[right] = aux;
}

 int32_t bit_mask_sorter::IntSorterUtils::partitionNotStable(int32_t* array, int32_t start, int32_t end, int32_t mask) {
    int32_t left = start;
    int32_t right = end - 1;

    while (left <= right) {
        int32_t element = array[left];
        if ((element & mask) == 0) {
            left++;
        } else {
            while (left <= right) {
                element = array[right];
                if ((element & mask) == 0) {
                    swap(array, left, right);
                    left++;
                    right--;
                    break;
                } else {
                    right--;
                }
            }
        }
    }
    return left;
}

 int32_t bit_mask_sorter::IntSorterUtils::partitionReverseNotStable(int32_t* array, int32_t start, int32_t end, int32_t mask) {
    int32_t left = start;
    int32_t right = end - 1;

    while (left <= right) {
        int32_t element = array[left];
        if ((element & mask) == 0) {
            while (left <= right) {
                element = array[right];
                if (((element & mask) == 0)) {
                    right--;
                } else {
                    swap(array, left, right);
                    left++;
                    right--;
                    break;
                }
            }
        } else {
            left++;
        }
    }
    return left;
}

 int32_t bit_mask_sorter::IntSorterUtils::partitionStable(int32_t* array, int32_t start, int32_t end, int32_t mask, int32_t* aux) {
    int32_t left = start;
    int32_t right = 0;
    for (int32_t i = start; i < end; i++) {
        int32_t element = array[i];
        if ((element & mask) == 0) {
            array[left] = element;
            left++;
        } else {
            aux[right] = element;
            right++;
        }
    }
    arraycopy(aux, 0, array, left, right);
    return left;
}



 void bit_mask_sorter::IntSorterUtils::partitionStableLastBits(int32_t* array, int32_t start, int32_t end, int32_t mask, int32_t twoPowerK, int32_t* aux) {
    auto leftX = new int32_t[twoPowerK]{0};
    auto count = new int32_t[twoPowerK]{0};
    for (int32_t i = start; i < end; i++) {
        count[array[i] & mask]++;
    }
    for (int32_t i = 1; i < twoPowerK; i++) {
        leftX[i] = leftX[i - 1] + count[i - 1];
    }
    for (int32_t i = start; i < end; i++) {
        int32_t element = array[i];
        int32_t elementShiftMasked = element & mask;
        aux[leftX[elementShiftMasked]] = element;
        leftX[elementShiftMasked]++;
    }
    arraycopy(aux, 0, array, start, end - start);
}

 void bit_mask_sorter::IntSorterUtils::partitionStableGroupBits(int32_t* array, int32_t start, int32_t end, int32_t mask, int32_t shiftRight, int32_t twoPowerK, int32_t* aux) {
    auto leftX = new int32_t[twoPowerK]{0};
    auto count = new int32_t[twoPowerK]{0};
    for (int32_t i = start; i < end; i++) {
        count[(array[i] & mask) >> shiftRight]++;
    }
    for (int32_t i = 1; i < twoPowerK; i++) {
        leftX[i] = leftX[i - 1] + count[i - 1];
    }
    for (int32_t i = start; i < end; i++) {
        int32_t element = array[i];
        int32_t elementShiftMasked = (element & mask) >> shiftRight;
        aux[leftX[elementShiftMasked]] = element;
        leftX[elementShiftMasked]++;
    }
    arraycopy(aux, 0, array, start, end - start);
}

void bit_mask_sorter::IntSorterUtils::arraycopy(int32_t *pSrc, int srcPos, int32_t *pDest, int32_t destPos, int32_t length) {
    memcpy(pDest+destPos, pSrc+srcPos, length * sizeof (int32_t));
}
