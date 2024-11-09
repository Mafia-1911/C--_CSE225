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
  bool insert(int value){
        Node* newNode= new Node(value);
        if(root==nullptr){
            root=newNode;
            return true;
        }
        Node* temp=root;
        while(true){
            if(temp->value == newNode->value ){
                //Duplicate Value Found
                cout<<"Value already Exists";
                return false;
            }else if(newNode->value > temp->value ){
                //Move right
                if(temp->right == nullptr){
                    temp->right=newNode;
                    return true;
                }else {
                    temp=temp->right;
                }
            }else if(newNode->value < temp->value){
                //Move left
                if(temp->left==nullptr){
                    temp->left=newNode;
                    return true;
                }else{
                    temp=temp->left;
                }
            }
        }
    }
bool contains(int target){
        if(root== nullptr){ //This line is reduntant , in original implementation you dont need to check for it
            return false;
        }
        Node* temp=root;
        //traverse
        while(temp != nullptr){
            if(temp->value == target){
                cout<<"Found the value: "<<target;
                return true;
            }else if(target <temp->value){
                temp=temp->right;
            }else if(target>temp->value){
                temp=temp->left;
            }
        }
        //came out of the loop meaning value is not in the tree
        return false;
    }


};

int main(){
    BinarySearchTree* myBST=new BinarySearchTree();
    myBST->insert(47);
    myBST->insert(21);
    myBST->insert(76);
    myBST->insert(18);
    myBST->insert(52);
    myBST->insert(82);

    myBST->insert(27);
    cout<<myBST->root->left->right->value<<endl;

    cout<<"Contains 18: "<<myBST->contains(18)<<endl;
    cout<<"Contains 420: "<<myBST->contains(420)<<endl;

}


