//Q. Make a binary search and implement recursive Functions to view the nodes through inOrder Travelsal 
// To search for a particular node 
// To find the height of the tree

#include <iostream>
using namespace std;

template<class T>
struct BSTNode{
    T info;
    BSTNode* left;
    BSTNode* right;

    BSTNode(T info) : info(info), left(nullptr), right(nullptr) {};
};

template<class T>
class BST{
    public:
    BST(){
        root = nullptr;
    }
    BSTNode<T> *root;
    void insert(BSTNode<T>* &node,T value){
        if(node==nullptr){
            node=new BSTNode<T>(value);
        }
        else if(value < node->info){
            insert(node->left,value);
        }
        else if(value>node->info){
            insert(node->right,value);
        }
    }
    void insertNode(T value){
        insert(root,value);
    }
    void searchNode(BSTNode<T> *node,T value,bool& found){
        if(node==nullptr){
            found=false;
        }
        else if(node->info==value){
            found=true;
            return;
        }else if(value < node->info){
            searchNode(node->left,value,found);
        }else if(value> node->info){
            searchNode(node->right,value,found);
        }
    }
    void search(T value,bool& found){
        searchNode(root,value,found);
    }
    int heightOfNode(BSTNode<T>* node){
        if(node==nullptr){
            return 0;
        }
        else{
            return 1+max(heightOfNode(node->left),heightOfNode(node->right)); 
        }
    }
    int height(){
        return heightOfNode(root)-1;
    }
    void inorderTraversal(BSTNode<T>* currentNode){
        // left-self-right
        if(currentNode != nullptr){
            inorderTraversal(currentNode->left);
            cout<<currentNode->info<<" ";
            inorderTraversal(currentNode->right);
        }
    }
    void printInOrder(){
        inorderTraversal(root);
    }

};

int main(){
    BST<int> bst;
    int arr[]={20,10,30,5,15,25,35};
    for(int i=0;i<7;i++){
        bst.insertNode(arr[i]);
    }
    std::cout<<endl<<"Inorder Traversal"<<endl;
    bst.printInOrder();

    bool found15=false;//Setting it initially to be not found
    bst.search(15,found15);
    if(found15){
        std::cout<<endl<<"Search 15: found"<<endl;
    }else{
        std::cout<<endl<<"Search 15: not found"<<endl;
    }


bool found50=false;//Setting it initially to be not found
    bst.search(50,found50);
    if(found50){
        std::cout<<"Search 50: found"<<endl;
    }else{
        std::cout<<"Search 50: not found"<<endl;
    }

    int height=bst.height();
    cout<<"Height of the tree: "<<height<<endl;
    


return 0;
}
