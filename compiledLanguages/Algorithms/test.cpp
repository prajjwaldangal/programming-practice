#include <iostream>
#include "QuickFind.cpp"
#include "subprocess.hpp"

#define MAX_NUM_NODES 16
#define MAX_INP_LEN 16 * 3 + 15

using namespace std;
int main() {
    cout << "Enter the number of nodes" << endl;
    int N;
    cin >> N;
    string tuples;
    vector < tuple <int, int > > edge_list; 
    cout << "Enter the edge list separated by a semi-colon ";
    getline(cin, tuples);
    printf("inp: %s\n", tuples.c_str());
    vector <int> arr = {1,2,3,4,5,6,7,8,9};
    //1-2-5-6-7 3-8-9-4
    QuickFind <int> obj (arr);
    return 0;
}