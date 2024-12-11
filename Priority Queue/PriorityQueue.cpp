
#include "PriorityQueue.h"

PriorityQueue::PriorityQueue(int max) {
    this->maxItems=max;
    heapName.arr=new int[max];
    length=0;
}

void PriorityQueue::makeEmpty() {
    length=0;
}

bool PriorityQueue::isFull(){
    if(length==maxItems){
        return true;
    }else return false;
}

bool PriorityQueue::isEmpty() {
    if(length==0){
        return true;
    }else return false;
}

//Insertion can be done only at the end
void PriorityQueue::Enqueue(int newItem) {
    if(length==maxItems){
        throw maxItems;
    }else{
        length++;
        //Inserting at the end
        heapName.arrName[length-1]=newItem;
        //Ordering the heap by reheap up during insertion
        heapName.reHeapUp(0,length-1);
    }
}
//deletion can be done only at the top
//DEQUEUE
// a. Replace the root with the last leaf node
// b. Decrement the length so that the last leaf node is out
// c. Perform reheap down operation to place the root in its appropriate position
