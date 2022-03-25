#include "queue.h"
#include <iostream>
template <class ItemType>
Queue<ItemType>::Queue() {
    maxQ = 500;
    front = maxQ - 1;
    rear = maxQ - 1;
    items  = new Packet<ItemType>[maxQ];
}

template <class ItemType>
Queue<ItemType>::~Queue(){
    delete [] items;
}

template <class ItemType>
bool Queue<ItemType>::IsEmpty() const {
    return rear == front;
}

template <class ItemType>
bool Queue<ItemType>::IsFull() const {
    return ((rear + 1) % maxQ == front);
}

template <class ItemType>
void Queue<ItemType>::Enqueue(Packet <ItemType> newPacket) {
    if (IsFull())
        throw FullQueue();

    rear = (rear + 1) % maxQ;
    items[rear] = newPacket;
}

template <class ItemType>
void Queue<ItemType>::Dequeue(Packet <ItemType> & removedPacket) {
    if (IsEmpty())
        throw EmptyQueue();
    
    front = (front + 1) % maxQ;
    removedPacket = items[front];
}

template <class ItemType>
void Queue<ItemType>::PrintQueue() {
    for (int i = front; i <= rear; i++){
        std::cout << items[i].payload;
    }
    std::cout << std::endl;
}