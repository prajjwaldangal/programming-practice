#include<iostream>
#include<vector>
using namespace std;

int main() {
   int n = 4;
   vector<vector<int> > vec(n+1, vector<int>(2, 1e9));
   cout << "2D array, dp is as follows:" << " " << endl;
   for (int i = 0; i < vec.size(); i++)
   {
    cout << endl;
    for (int j = 0; j < vec[i].size(); j++)
      {
        cout << vec[i][j];
      }
   }
   cout << endl;
   return 0;
}
