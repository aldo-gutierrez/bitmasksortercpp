//
// Created by aldo on 4/23/2022.
//

#ifndef BITMASKSORTER_RADIXBITSORTERINT_H
#define BITMASKSORTER_RADIXBITSORTERINT_H


#include "IntSorter.h"
namespace bit_mask_sorter {
    class RadixBitSorterInt : public IntSorter {
    public:
        bool isUnsigned() {
            return unsignedN;
        }

        void setUnsigned(bool unsignedP) {
            this->unsignedN = unsignedP;
        }

        static void radixSort(int32_t *array, int32_t start, int32_t end, const int32_t *kList, int32_t kIndexStart,
                              int32_t kIndexEnd,
                              int32_t *aux);

        virtual void sort(int32_t *array, int32_t aLength);

        virtual ~RadixBitSorterInt() = default;

    private:
        bool unsignedN = false;
    };
}

#endif //BITMASKSORTER_RADIXBITSORTERINT_H
