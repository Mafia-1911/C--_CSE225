#include<iostream>
using namespace std;
#include "dynArr.cpp"

int main(){
    dynArr myArray(5);
    cout<<"Enter size: ";
    int size=0;cin>>size;
    int value;
    for(int i=0;i<size;i++){
        cin>>value;
        myArray.setValue(value,i);
    }
    for(int i=0;i<size;i++){
        cout<<"value at index["<<i<<"] is: "<<myArray.getValue(i)<<endl;
    }

}