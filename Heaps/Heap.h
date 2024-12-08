#pragma once 

template<class T>
class Heap{
  void reheapUp(int root , int down);
  void reheapDown(int root , int down);
  T* elements;
  int numElements;
}




