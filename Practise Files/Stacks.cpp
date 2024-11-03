#include <iostream>
using namespace std;

//Doing stacks from the left end == O(n) [insertion and deletion]
//Doing it from the right end    == O(1)

//++++ Using Linked List
//You would want the null pointer to point downwards instead of up
//Removing/Adding from the Head == O(1)
// removing from tail O(n) Because you need second last pointer
// adding to the tail O(1)

class Node{
public:
    int value;
    Node* next;
    Node(int data){
        this->value=data;
        this->next=nullptr;
    }
    Node(int value,Node* next){
        this->value=value;
        this->next=next;
    }
};

class Stack{
private:
    int height;
    Node* top;

public:
    Stack(int value){
        Node* newNode=new Node(value);
        this->top=newNode;

        height=1;
    }
    void printStack(){
        Node* temp=top;
        while(temp!= nullptr){
            cout<<temp->value<<"-> ";
            temp=temp->next;
        }
    }
    int getHeight(){
        cout<<endl<<"Height of the stack is: "<<height<<endl;
        return height;
    }
    void getTop(){
        cout<<"Top of the stack is: "<<top->value<<endl;
    }
    void push(int value){
        Node* newNode=new Node(value);
        newNode->next=top;
        top=newNode;
        height++;
    }
    int pop(){
    //Deleting the head and returning the deleted value
        if(height==0){
            return INT_MIN;
        }else{
            Node* temp=top;
            int poppedValue=top->value;
            top=top->next;
            delete temp;
            height--;
            return poppedValue;
        }
    }
};

int main(){
    Stack* myStack=new Stack(10);//You can use auto* when using new keyword
    myStack->push(11);
    myStack->push(12);
    myStack->printStack();

    cout<<"Just popped: "<<myStack->pop()<<endl;
    cout<<"Just popped: "<<myStack->pop()<<endl;
    cout<<"Just popped: "<<myStack->pop()<<endl;
    cout<<"Just popped: "<<myStack->pop()<<endl;//-2147483648

    myStack->printStack();




    delete myStack;
}




































