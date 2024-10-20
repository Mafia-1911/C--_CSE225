#include<iostream>
using namespace std;

//Making the node class
class Node{

public:
    int value;
    Node* next;
    Node* prev;

    Node(int data){
        this->value=data;
        next= nullptr;//since they are pointers, so you can not use the integer NULL here .
        prev= nullptr; // instead use the nullptr to assign to the pointers in the first iteration
    }
    Node(int data,Node* next,Node* prev){
        this->value=data;
        this->next=next;
        this->prev=prev;
    }
};

//Making the Doubly linked list class
class DoublyLL{
private:
    Node* head;
    Node* tail;
    int length=0;

public:
    DoublyLL(int data){
        //memory assigning logic should be in the constructor
        Node* newNode=new Node(data);
        //for first iteration head and tail will point the same node
        head=newNode;
        tail=newNode;
        length++;
    }

    //printing the list
    void printList(){
       Node* temp=head;
       while(temp){
           cout<<temp->value<<"->";
           temp=temp->next;
       }
       cout<<endl;
    }

    void append(int data){
        Node* newNode=new Node(data);
        //if the linked list is empty
        if(length==0){
            head=newNode;
            tail=newNode;
            length++;
        }else{
            tail->next=newNode;
            newNode->prev=tail;
            newNode->next=nullptr;
            length++;
            tail=newNode;
        }
    }
    void prepend(int data){
        Node* newNode= new Node(data);
        //we need to cover only one corner case for the prepend function
        if(length==0){
            head=newNode;
            tail=newNode;
            length++;
        }else{
            newNode->next=head;
            head->prev=newNode;
            head=head->prev; //Moving the head Pointer OR head=newNode
            length++;
        }

    }
    Node* get(int index){
        if(index<0 || index>length) {
            cout<<"Invalid Index";
            return nullptr;
        }

        Node* temp=head;
        // Optimization in doubly Linked List
        if(index<length/2){
            for(int i=0;i<index;i++){
                temp=temp->next;
            }
        }else{
            for(int j=length-1;j>index;j++){
                temp=temp->next;
            }
        }

        return temp;
    }
    //Set Value

    bool setNode(int index,int value){
        //Make a temp node and point it to that index
        Node* temp=head;

        //Invalid Index
        if(index<0 || index>length){
            cout<<"Invalid Index";
        }else {
            for (int i = 0; i < index; i++) {
                temp = temp->next;
            }
            temp->value = value;
            return true;
        }
        return false;
    }

///Insertion
// Fist the corner cases , Smaller than 0 and greater than index will not be valid
// in the middle with 2 pointer approach
    // Create - 1 Target node , 2 pointers (before and after)
// First Connect the new node with them , Which means first work with null pointers and then work with pointers that are already pointing something
    bool insertItem(int index,int value){

        Node* before;
        Node* toInsert = new Node(value);
        Node* after;

        if(index<0 || index > length){
            cout<< "Invalid Index" <<endl;
            return false;
        }else if(index==0){
            //Complete this
                length++;
                return true;
        }else if(index==length-1){
            //Complete this
            length++;
            return true;
        }else{
            for(int i=0;i<index;i++){
                if(i==0) before=head;
                else{
                    before=before->next;
                }

            }
            //before is ready
            after=before->next;

            //working with null pointers first
            toInsert->prev=before;
            toInsert->next=after;
            //Then redirecting the before and after
            before->next=toInsert;
            after->prev=toInsert;
            length++;
            return true;
        }
        cout<<"Couldn't insert"<<endl;return false;
    }


///Deleting the Last element - It will much easier because we have previous pointers
    // since we do not need to iterate it will be done in O(1) instead of O(n)
    //+ For every operation you implement there will be two edge cases :
    //1. When the list is empty (nullptr)
    //2. When there is only one element

    void deleteLast(){
        if(length==0) {
            cout << "List is empty";
            return;
        }else if(length==1){
            head=nullptr;
            tail=nullptr;
            length--;
        }else{
            Node* temp=tail;
            tail=tail->prev;
            tail->next=nullptr;
            delete temp;
            length--;
        }
    }
    void deleteMiddle(int index){
        //2pointer approach would work fine , Take the before and after pointer
        Node* temp=head;
        for(int i=0;i<index;i++){
            temp=temp->next;
        }
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        delete temp;
        length--;

    }
    void deleteFirst(){
        if(length==0) return;
        else if(length==1){
            head= nullptr;
            tail= nullptr;
            length--;
        }else{
            Node* temp=head;
            head=head->next;
            head->prev= nullptr;
            delete temp;
            length--;
        }
    }

};

int main(){
    DoublyLL* myDLL=new DoublyLL(77);

    myDLL->printList();
    myDLL->append(88);
    myDLL->append(99);
    myDLL->append(66);
    myDLL->printList();
    myDLL->prepend(66);
    myDLL->prepend(55);
    myDLL->printList();

    cout<<"Value at index[2] is:"<<myDLL->get(2)->value<<endl;
    myDLL->printList();
    myDLL->setNode(6,67);
    myDLL->printList();


//    myDLL->insertItem(1,56);
//    myDLL->insertItem(5,69);
    cout<<"BEFORE"<<endl;
    myDLL->printList();
    myDLL->deleteMiddle(2);
    cout<<"Hello";
    cout<<"After"<<endl;
    myDLL->printList();

    //Checking the delete method
//    myDLL->deleteLast();
//    myDLL->printList();
//    myDLL->deleteLast();
//    myDLL->printList();
//    myDLL->deleteLast();
//    myDLL->printList();
//    myDLL->deleteLast();
//    myDLL->printList();
//    myDLL->deleteLast();
//    myDLL->printList();


//myDLL->deleteFirst();
//myDLL->printList();
//myDLL->deleteFirst();
//myDLL->printList();

}
