#include<iostream>
using namespace std;

template<class T>
class vector{
    T number;
public:
    vector(T num){
        this->number=num;
        cout<<"You enetered: "<<number;
    }
};

int main(){
    vector<int> myVect(5);


}

