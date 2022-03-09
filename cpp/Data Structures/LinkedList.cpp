// we define the linked list node in a generic way
template <class ItemType>
class Node {
    ItemType val;
    Node * next;
};

// next we will use node as encapsulating it into a 
//     linkedlist class as in line 23-25
template <class ItemType>
class LinkedList {
    public:
        LinkedList();
        ~LinkedList();
    bool IsFull() const;
    int LengthIs() const;
    void MakeEmpty();
    void RetrieveItem (ItemType item, bool & found);
    void InsertItem(ItemType item);
    void DeleteItem(ItemType item);

    private:
        Node <ItemType> * head;
        ItemType length;
        Node <ItemType> * currPos; 
};