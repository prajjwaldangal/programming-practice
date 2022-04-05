template <class ItemType>
struct Node {
    ItemType priority;
    float burstTime;
    float period;
};

template <class ItemType>
class Heap {
    public:
        Heap();
        Heap(int capacity);
        ~Heap();
        void MakeEmpty();
        bool IsEmpty();
        bool IsFull();
        int getLeftChild();
        int getRightChild();
    private:
        Node<ItemType> * myHead;
};