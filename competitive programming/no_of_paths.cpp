#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int numberOfPaths(vector < vector <int> > a);

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));
    int res;
    
    int _a_rows = 0;
    int _a_cols = 0;
    cin >> _a_rows >> _a_cols;
    vector< vector < int > > _a(_a_rows);
    for(int _a_i=0; _a_i<_a_rows; _a_i++) {
        for(int _a_j=0; _a_j<_a_cols; _a_j++) {
            int _a_tmp;
            cin >> _a_tmp;
            _a[_a_i].push_back(_a_tmp);
        }
    }
    
    res = numberOfPaths(_a);
    fout << res << endl;
    
    fout.close();
    return 0;
}

int numberOfPaths(vector < vector < int > > a) {
	int n = a.size();
    int m;
    try {
        m = a[0].size();
    } except {
        
    }
}


