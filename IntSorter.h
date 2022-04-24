//
// Created by aldo on 4/23/2022.
//

#ifndef BITMASKSORTER_INTSORTER_H
#define BITMASKSORTER_INTSORTER_H


#include <cstdint>
#include "Sorter.h"

namespace bit_mask_sorter {

    class IntSorter : public Sorter {
    public:
        virtual void sort(int32_t *array, int32_t aLength) = 0;
    };
}
#endif //BITMASKSORTER_INTSORTER_H
