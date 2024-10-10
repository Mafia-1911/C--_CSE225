#include "dynarr.h"
#include "dynarr.cpp"
#include <iostream>
using namespace std; 

//For data members and their implementations use the header file
//for the Code members / methods use the .cpp file
int main() {
    Dynarr myarr;
    cout<<"Enter the size of the array: ";
    int size=0;cin>>size;
    Dynarr arr2(size);

    
    for(int i=0;i<size;i++){
        cout<<"Enter the Values for index["<<i<<"] : ";
        int input;
        cin>>input;
        arr2.setValue(i,input);
    }
    cout<<"Printing the array: ";
    for(int i=0;i<size;i++){
        cout<<arr2.getValue(i)<<" ";
    }
    arr2.allocate(7);
    

}