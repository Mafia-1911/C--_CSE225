#include "dynarr.h"
#include <iostream>
using namespace std;

Dynarr::Dynarr(){
    data=NULL;
    size = 0;
}
Dynarr::Dynarr(int size){
    data=new int[size];
    this->size=size;
    cout<<"Constructor is called";
}
Dynarr::~Dynarr(){
    delete[] data;
}
void Dynarr::setValue(int index,int value){
    data[index]=value;
    cout<<getValue(index);
}
int Dynarr::getValue(int index){
    return data[index];
}
