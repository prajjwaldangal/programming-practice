// http://codeforces.com/contest/838/problem/B

#include <stdio.h>
#include <sstream>
#include <iostream>
#include <string>

using namespace std;
int main() {
	string line;
	getline(cin, line);
	istringstream iss(line);
	int n, q;
	iss >> n >> q;

	int arr[2*n - 2 + q][3];
	for (int i=0; i<2*n-2+q; i++) {
		getline(cin, line);
		iss.str(line);
		iss.clear();
		iss.seekg(0);
		istringstream iss(line);
		iss >> arr[i][0] >> arr[i][1] >> arr[i][2];
		cout << arr[i][0] << arr[i][1] << arr[i][2] << endl;
	}
	return 0;
}