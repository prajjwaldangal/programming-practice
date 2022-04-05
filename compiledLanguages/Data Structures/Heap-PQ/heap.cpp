#include "heap.h"
#include <cstdio>
#include <iostream>
using namespace std;

template <class ItemType>
Heap<ItemType>::Heap() {
    myHead = malloc(sizeof(Node<ItemType>) * 16);
    if (myHead == NULL) {
        fprintf(stderr, "error: not enough memory to initialize heap");
        exit(-1);
    }
}

template <class ItemType>
Heap<ItemType>::Heap(int capacity) {
    myHead = malloc(sizeof(Node<ItemType>) * capacity);
}


int main() {
    // TO-DO: perform time and space complexity analysis
    return 0;
}