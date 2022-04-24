
//
// Created by aldo on 4/23/2022.
//

#ifndef TESTCMM1_SORTER_H
#define TESTCMM1_SORTER_H

#include <typeinfo>

class Sorter {

    const char *name() {
        return typeid(this).name();
    }

    bool isUnsigned() {
        return false;
    }

    virtual void setUnsigned(bool unsignedP) = 0;

    bool isStable() {
        return false;
    }

};


#endif //TESTCMM1_SORTER_H
