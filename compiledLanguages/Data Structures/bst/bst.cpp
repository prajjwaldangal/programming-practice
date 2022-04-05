#include "bst.h"

#include <stdio.h>

template <class ItemType>
BST<ItemType>::BST() {
    root = NULL;
}

template <typename ItemType>
void helper(Node<ItemType> & myNode) {
    if (myNode == NULL)
        return;
    Node<ItemType> * left = myNode.left;
    Node<ItemType> * right = myNode.right;
    delete myNode;
    helper(left);
    helper(right);
}

template <typename ItemType>
BST<ItemType>::~BST() {
    helper(root);
}

template <typename ItemType>
int BST<ItemType>::insertItem(ItemType item) {
    Node <ItemType> * newNode = new Node<ItemType>;
    newNode->val = item;
    newNode->left = NULL;
    newNode->right = NULL;
    Node <ItemType> * mover = root;
    while (mover) {
        if (root == NULL) {
            root = newNode;
            return 0;
        }
        mover = root;
        if (item < mover->val) { // allowing no duplicates
            if (mover->left == NULL) { 
                mover->left = newNode;
                return 0;
            } else {
                mover = mover->left;
            }
        } else if (item > mover->val) {
            if (mover->right == NULL) {
                mover->right = newNode;
                return 0;
            } else {
                mover = mover->right;
            }
        }
    }
    return -1;
}

template <typename ItemType>
int BST<ItemType>::removeItem(ItemType item) {
    
}

template <typename ItemType>
void printHelper(Node<ItemType> * myNode) {
    if (myNode == NULL) 
        return;
    printHelper(myNode->left);
    printHelper(myNode->right);
    
    printf("%d ", myNode->val);
}

template <typename ItemType>
void BST<ItemType>::printTree() {
    printHelper(root);
}