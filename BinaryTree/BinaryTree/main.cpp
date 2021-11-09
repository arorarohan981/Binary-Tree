//
//  main.cpp
//  BinaryTree
//
//  Created by Rohan Arora on 09/11/21.
//

#include <iostream>
#include "BinaryTree.hpp"
int main(int argc, const char * argv[]) {
    mylib::BinaryTree<int> intTree{};
    std::cout<<"Is Binary Tree Empty "<<std::boolalpha<<intTree.isEmpty()<<std::endl;
    intTree.add(1);
    intTree.add(2);
    intTree.add(3);
    intTree.add(4);
    intTree.add(5);
        intTree.preOrderPrintTree();
    intTree.inOrderPrintTree();
    intTree.postOrderPrintTree();
    return 0;
}
