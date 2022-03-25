#include "queue.cpp"

int main() {
    Queue<std::string> * myQueue = new Queue<std::string>();
    myQueue->PrintQueue();
    std::string myStrings[] = {
        "force",
        "love",
        "power"
    };
    std::string s;
    for (int i = 0; i < myStrings->size(); i++) {
        s = myStrings[i];
        Packet <std::string> p = {
            .source_addr = "121.10.10.21",
            .dest_addr = "10.140.123.1",
            .timeout =  10,
            .payload = s
        };
        myQueue->Enqueue(p);
    }
    myQueue->PrintQueue();
    return 0;
}