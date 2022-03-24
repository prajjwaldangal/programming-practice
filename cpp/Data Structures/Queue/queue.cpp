#include "queue.h"

template <typename ItemType>
Queue<ItemType>::Queue() {
    maxQ = 500;
    front = maxQ - 1;
    rear = maxQ - 1;
    items  = new Packet<std::string>[maxQ];
}

template <typename ItemType>
Queue<ItemType>::~Queue(){
    delete [] items;
}

// template <typename ItemType>
// bool Queue<ItemType>::IsEmpty() const {

// }

template <typename ItemType>
void Queue<ItemType>::Enqueue(Packet <ItemType> newPacket) {
    
}