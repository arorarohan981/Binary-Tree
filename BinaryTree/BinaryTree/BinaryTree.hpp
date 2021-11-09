//
//  BinaryTree.hpp
//  BinaryTree
//
//  Created by Rohan Arora on 09/11/21.
//

#ifndef BinaryTree_hpp
#define BinaryTree_hpp

#include <stdio.h>
#include <memory>
#include <iostream>
#include <utility>
namespace mylib{

/*In the Binary Tree there is no order how data is added.In Binary Search tree order is Specified.
 Binary Tree is either an empty tree or a tree with atmost 2 nodes pointing to left and right binary trees.
 */
template <typename T>
class BinaryTree{
private:
    struct Node{
        std::unique_ptr<Node> left;
        std::unique_ptr<Node> right;
        T data;
        
         explicit Node(T userdata);
        ~Node()=default;
    };
    std::unique_ptr<Node> root;
    /*Returns True if the data is to be added in the left Subtree or else returns False to add data in the Right Subtree .*/
    bool askNodePosition();
    
    
    /*Returns True if Node's Left Subtree is Empty or else Returns false*/
    bool isNodesLeftSubtreeEmpty(Node *ptr) const;
    
    /*Returns True if Node's Right Subtree is Empty or else Returns false*/
    bool isNodesRightSubtreeEmpty(Node *ptr) const;
    
    /*Prints Tree in PreOrder Technique */
    void preOrder(Node* Iternode) const;
    
    
    /*Prints Tree in PostOrder Technique */
    void postOrder(Node* Iternode) const;
    
    
    
    /*Prints Tree in InOrder Technique */
    void inOrder(Node* Iternode) const;
    
public:
    
    virtual ~BinaryTree();
    
    /*Checks if the Tree is Empty . Returns True if the Tree is Empty or else Returns False .*/
    bool isEmpty() const;
    
    
    /*Inserts the Data in the Tree. Returns True if the if the data is added successfully or else returns false*/
    bool add(T data);
    
    /*Prints Tree in PreOrder Technique
     Wrapper for Private Function PreOrder */
    void preOrderPrintTree() const;
    
    /*Prints Tree in PostOrder Technique
     Wrapper for Private Function PostOrder */
    void postOrderPrintTree() const;
    
    
    
    /*Prints Tree in InOrder Technique
     Wrapper for Private Function InOrder */
    void inOrderPrintTree() const;
};

template <typename T>
BinaryTree<T>::Node::Node(T userdata):data(userdata){
}


template <typename T>
bool BinaryTree<T>::isNodesLeftSubtreeEmpty(Node *ptr) const{
    if(ptr->left.get()==nullptr){
        return true;
    }
    return false;
}

template <typename T>
bool BinaryTree<T>::isNodesRightSubtreeEmpty(Node *ptr) const{
    if(ptr->right.get()==nullptr){
        return true;
    }
    return false;
}

template<typename T>
bool BinaryTree<T>::askNodePosition(){
    unsigned int choice{0};
    while(true){
        std::cout<<"Enter 1 if we want to add data in the Left Subtree or else Enter 2 to enter data in the Right Subtree : ";
        std::cin>>choice;
        std::cout<<std::endl;
        if(choice==1){
            return true;
        }
        else if (choice==2){
            return false;
        }else{
            std::cout<<"Wrong Choice Entered "<<std::endl;
        }
}
    
}

template <typename T>
bool BinaryTree<T>::isEmpty() const{
    if(root==nullptr){
        return true;
    }
    return false;
}





template <typename T>
BinaryTree<T>::~BinaryTree<T>(){
    root.release();
}

template<typename T>
bool BinaryTree<T>::add(T userData){
    std::unique_ptr<Node> userNode = std::make_unique<Node>(userData);
    if(isEmpty()){
        root=std::move(userNode);
        std::cout<<"Tree is Empty ! Entered Data is the Root Node in the Binary Tree "<<std::endl;
        return true;
    }
    /*Created a Node Iterator which will iterate in the tree for inserting Data */
    Node* iterNode=root.get();
    bool choice;
    while (true) {
        std::cout<<"Current Data is -> "<<iterNode->data<<std::endl;
       choice = askNodePosition();
        if(choice){
            if( isNodesLeftSubtreeEmpty(iterNode)){
            iterNode->left=std::move(userNode);
                std::cout<<"Data Added Successfully "<<std::endl;
                return true;
            }
            iterNode=iterNode->left.get();
        }else{
            if( isNodesRightSubtreeEmpty(iterNode)){
            iterNode->right=std::move(userNode);
                std::cout<<"Data Added Successfully "<<std::endl;
                return true;
            }
            iterNode=iterNode->right.get();
        }
    }
    return false;
    
    
}


template <typename T>
void BinaryTree<T>::preOrderPrintTree() const{
    if(isEmpty()){
        std::cout<<"Tree is Empty "<<std::endl;
        return;
    }
    std::cout<<"Printing Data in Pre Order Technique : "<<std::endl;
    preOrder(root.get());
}


template <typename T>
void BinaryTree<T>::inOrderPrintTree() const{
    if(isEmpty()){
        std::cout<<"Tree is Empty "<<std::endl;
        return;
    }
    std::cout<<"Printing Data in In-Order Technique : "<<std::endl;
    inOrder(root.get());
}


template <typename T>
void BinaryTree<T>::postOrderPrintTree() const{
    if(isEmpty()){
        std::cout<<"Tree is Empty "<<std::endl;
        return;
    }
    std::cout<<"Printing Data in Post Order Technique : "<<std::endl;
    postOrder(root.get());
}


template <typename T>
void BinaryTree<T>::postOrder(Node* nodeIter) const{
    
    if(nodeIter->left.get()!=nullptr){
        postOrder(nodeIter->left.get());
    }
    if(nodeIter->right.get()!=nullptr){
        postOrder(nodeIter->right.get());
    }
    std::cout<<nodeIter->data<<std::endl;
}


template <typename T>
void BinaryTree<T>::preOrder(Node* nodeIter) const{
    
    std::cout<<nodeIter->data<<std::endl;
    if(nodeIter->left.get()!=nullptr){
        preOrder(nodeIter->left.get());
    }
    if(nodeIter->right.get()!=nullptr){
        preOrder(nodeIter->right.get());
    }
   
}


template <typename T>
void BinaryTree<T>::inOrder(Node* nodeIter) const{
    
    
    if(nodeIter->left.get()!=nullptr){
        inOrder(nodeIter->left.get());
    }
    std::cout<<nodeIter->data<<std::endl;
    if(nodeIter->right.get()!=nullptr){
        inOrder(nodeIter->right.get());
    }
   
}




}
#endif /* BinaryTree_hpp */
