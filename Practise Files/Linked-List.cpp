//Code for reversing a linked List 
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

Node* reverse(Node* &head){
    //NULL<-1->2->3->4
    //      prev cur next
    Node* prevptr=nullptr;
    Node* current=head;
    Node* nextptr;

    while(current != nullptr){
        nextptr=current->next;
        current->next=prevptr; //reversing

        prevptr=current;
        current=nextptr;
    }
    return prevptr;
}

//Current Pointer points to the previous pointer
//Then the pointers step ahead (previous pointer points to the current)(Current points to next )
//          The next pointer points to the next pointer to of the updated current
//Finally the previous pointer points to the new Head
