//
//  bst.hpp
//  BST
//
//  Created by Prajjwal Dangal on 3/18/22.
//

#ifndef bst_hpp
#define bst_hpp

#include <stdio.h>

#endif /* bst_hpp */
template <typename ItemType>
class Node {
    public:
        Node * left;
        Node * right;
        ItemType val;
};

template <typename ItemType>
class BST {
    public:
        BST();
        // 1
        ~BST();
        // copy constructor
        BST(const BST & origTree);
        // void makeEmpty();
        bool isEmpty() const;
        bool isFull() const;
        int lengthIs() const;
        void RetrieveItem(
            ItemType item,
            bool & found
        ) const;
        // 2
        int insertItem(ItemType item);
        int removeItem(ItemType item);
        void printTree();
        // void printHelper(Node<ItemType> * node);
    private:
        Node<ItemType> * root;
};
