#include "implLnkLst.cpp"

int main() {
    LinkedList <int> * myLL = new LinkedList <int> ();
    std::string full = "false";
    if (myLL->IsFull()) {
        full  = "true";
    }
    std::cout << "isFull: " << full << std::endl;
    std::cout << "length is: " << myLL->LengthIs() 
        << std::endl;
    for (int i = 1; i < 10; i++) {
        myLL->InsertItem(i);
    }
    std::cout << "InsertItem successful" << std::endl;
    bool found;
    for (int i = 1; i < 10; i++) {
        found = false;
        myLL->RetrieveItem(i, found);
        if (found) {
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}
