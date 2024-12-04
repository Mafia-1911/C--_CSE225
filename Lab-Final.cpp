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
