#include <string>
template <typename ItemType>
class Packet {
    std::string source_addr;
    std::string dest_addr;
    int timeout;
    ItemType payload;
};

template <typename ItemType>
class Queue {
    public:
        Queue();
        Queue(int max); // max is the size of the queue
        ~Queue(); // by default the size will be 500        
        bool IsEmpty() const;
        bool IsFull() const;
        void Enqueue(Packet <ItemType> newPacket);
        void Dequeue(Packet <ItemType> & removedPacket);
    private:
        int front;
        int rear;
        Packet <ItemType> * items;
        int maxQ;
};