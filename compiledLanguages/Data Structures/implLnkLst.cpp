#include <iostream>
#include "LinkedList.cpp"

// we will implement the linkedlist api by including the
//      file that contains the actual api

// please note how class methods also require template
//      syntax
template <class ItemType>
LinkedList<ItemType>::LinkedList() {
    length = 0;
    head = NULL;
}

template <class ItemType>
LinkedList<ItemType>::~LinkedList() {
    while (head != NULL) {
        Node <ItemType> * curr = head;
        head = head->next;
        delete curr;
    }
    delete head;
}

template <class ItemType>
bool LinkedList<ItemType>::IsFull () const {
    Node <ItemType> * checkPtr;
    try {
        checkPtr = new Node <int>;
        delete checkPtr;
        return false;
    } catch (std::bad_alloc exception) {
        return true;
    }
}

template <class ItemType>
int LinkedList<ItemType>::LengthIs() const {
    return (int) length;
}

template <class ItemType>
void LinkedList<ItemType>::MakeEmpty() {
    while (head != NULL) {
        Node <ItemType> * curr = head;
        head = head->next;
        delete curr;
    }
    length = 0;
}
