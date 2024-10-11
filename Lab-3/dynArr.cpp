
#include "dynArr.h"

dynArr::dynArr(int size) {
    data=new int[size];
    this->size=size;
}
dynArr::~dynArr() {
    delete [] data;
}

int dynArr::getValue(int index) {
    return data[index];
}
void dynArr::setValue(int val, int index) {
    data[index]=val;
}

