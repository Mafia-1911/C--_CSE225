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
