#include "bst.cpp"
int main() {
    BST <int> * myBST = new BST<int>;
    int arr[6] = {5, 7, 2, 4, 8, 6};
    for (int i = 0; i < 6; i++ ) {
        myBST->insertItem(i);
    }
    myBST->printTree();
    return 0;
}