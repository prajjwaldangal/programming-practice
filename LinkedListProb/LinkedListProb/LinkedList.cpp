#include <stdio.h>

struct NodeType {
    int n;
    NodeType * next;
};

class SortedType {
private:
    NodeType * root;

public:
    SortedType();
    ~SortedType();
    int InsertNode(NodeType node);
    void PrintLinkedList(NodeType root);
};

SortedType::SortedType() {
    root = NULL;
}

int SortedType::InsertNode(<#NodeType node#>) {

}

SortedType::~SortedType() {

    Node *temp = head;

    while(temp != nullptr)
    {
        Node *nodeToDelete = temp;
        temp = temp->getLink();
        delete nodeToDelete;
    }

    NodeType * temp;
    while (root != NULL) {
        temp = root;
        delete(root);
        root = temp->next;
    }
}




