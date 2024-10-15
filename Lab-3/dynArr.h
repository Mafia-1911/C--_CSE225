// #pragma once can also be used
#ifndef CSE_225_DAA_DSA_DYNARR_H
#define CSE_225_DAA_DSA_DYNARR_H

class dynArr {
private:
    int* data;
    int size;

public:
    dynArr(int);
    ~dynArr();
    void setValue(int,int);
    int getValue(int);
};


#endif //CSE_225_DAA_DSA_DYNARR_H
