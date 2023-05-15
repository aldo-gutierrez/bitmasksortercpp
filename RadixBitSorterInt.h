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
            return _unsignedN;
        }

        void setUnsigned(bool unsignedP) {
            this->_unsignedN = unsignedP;
        }

        static void radixSort(int32_t *array, size_t start, size_t end, const int32_t *kList, size_t kIndexStart,
                              size_t kIndexEnd,
                              int32_t *aux);

        virtual void sort(int32_t *array, size_t aLength);

        virtual ~RadixBitSorterInt() = default;

    private:
        bool _unsignedN = false;
    };
}

#endif //BITMASKSORTER_RADIXBITSORTERINT_H
