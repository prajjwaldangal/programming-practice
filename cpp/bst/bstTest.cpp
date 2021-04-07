#include "bst.h"
#include <iostream>

int main() {
    BST * myTree = new BST;
    myTree->insertNode(4);
    myTree->insertNode(2);
    myTree->insertNode(3);
    myTree->insertNode(1);
    myTree->insertNode(5);
    myTree->insertNode(7);
    myTree->insertNode(6);
    myTree->printTree(1);
    return 0;
}
