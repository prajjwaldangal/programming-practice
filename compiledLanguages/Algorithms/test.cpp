#include <iostream>
#include "QuickFind.cpp"

using namespace std;


int main() {
    cout << "Enter the number of nodes" << endl;
    int N;
    cin >> N;

    cout << "Enter the edge list" << endl;

    vector <int> arr = {1,2,3,4,5,6,7,8,9};
    //1-2-5-6-7 3-8-9-4
    QuickFind <int> obj (arr);
    return 0;
}