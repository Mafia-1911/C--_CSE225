#include "Heap.h"

class FullPQ{};
class EmptyPQ{};

class PriorityQueue {
public:
    PriorityQueue(int);
    ~PriorityQueue();
    void makeEmpty();
    bool isEmpty();
    bool isFull();
    void Enqueue(int newItem);
    void Dequeue(int& newItem);
private:
    int length;
    int maxItems;
    Heap<int> heapName;
};
