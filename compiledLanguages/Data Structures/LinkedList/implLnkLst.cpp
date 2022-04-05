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
        checkPtr = new Node <ItemType>;
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

// void printList

// sorted linked list implementation
template <class ItemType>
void LinkedList<ItemType>::InsertItem(ItemType item) {
    std::cout << "item = " << item << std::endl;
    std::cout << "Head is not null" << std::endl;
    Node <ItemType> * prev = NULL;
    Node <ItemType> * curr = head;
    Node <ItemType> * newNode = NULL;
    bool moreToSearch = (curr != NULL);

    // find insertion point
    while (moreToSearch) {
        if (item > curr->val) {
            prev = curr;
            curr = curr->next;
            moreToSearch = (curr != NULL);
        } else {
            moreToSearch = false;
        }
    }
    newNode = new Node<int>();
    newNode->val = item;
    
    // insert into the list
    if (prev == NULL) {
        newNode->next = head;
        head = newNode;
    } else {
        prev->next = newNode;
        newNode->next = curr;    
    }
    length ++;
}

template <class ItemType>
void LinkedList<ItemType>::RetrieveItem(ItemType item, bool & found) {
    if (head == NULL) {
        found = false;
        return;
    }
    Node <int> * curr = head;
    while (curr) {
        if (curr->val == item) {
            found = true;
            return;
        }
        curr = curr->next;
    }
    found = false;
}