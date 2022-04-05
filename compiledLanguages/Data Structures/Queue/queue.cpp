#include "queue.h"
#include <iostream>

template <class ItemType>
Queue<ItemType>::Queue() {
    maxQ = 501;
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
    size_t start, end;
    start = (front + 1) % maxQ;
    end = rear;
    for (int i = start; i <= end; i++){
        std::cout << items[i].payload << " ";
    }
    std::cout << std::endl;
}

// FullQueue::FullQueue() {
//     std::cout << "Queue is full, can't enqueue" << std::endl;
// }

// EmptyQueue::EmptyQueue() {
//     std::cout << "Queue is empty, can't dequeue" <<std::endl;
// }