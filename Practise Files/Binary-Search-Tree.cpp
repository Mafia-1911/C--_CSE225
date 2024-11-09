#include<iostream>
using namespace std;
//The right side of the root node contains values greater
//The left side contains less than values
// O(log n) to find and insert and - its very efficient
// The number of level the node is , the number of steps we need to take
class BinarySearchTree{
public:
    struct Node{
        int value;
        Node* right;
        Node* left;

        Node(int value){
            this->value=value;
            this->right=nullptr;
            this->left=nullptr;
        }
    };
    Node* root;

    BinarySearchTree(){
        this->root=nullptr;
    }
    BinarySearchTree(int value){
        Node* newNode=new Node(value);
        root=newNode;
    }
//////////Insert Function
//    create newNode
//    empty tree - place new node in the root
//    non empty -
//            make a temp node
//            Keep checking for , Duplicate (newNode=temp)
//                                The Left side
//                                The Right side
//            if nullptr insert at that position
//            else move to the next node
