#include "dynarr.h"
#include "dynarr.cpp"
#include <iostream>
using namespace std; 

int main() {
    Dynarr myarr;
    Dynarr arr2(5);
    
    int test;
    cin>>test;
    cout<<test;
    
    for(int i=0;i<5;i++){
        cout<<"Enter the Values for index["<<i<<"] : ";
        int input;
        cin>>input;
        arr2.setValue(i,input);
    }
    cout<<"Printing the array: ";
    for(int i=0;i<5;i++){
        cout<<arr2.getValue(i)<<" ";
    }
    

}