/*
	1 km = 1 l
	capacity = 200 l

*/

// Problem: adventures_in_moving_IV 
// Website: kattis

#include <iostream>
#include <iterator>
#include <sstream>
#include <fstream>

// https://stackoverflow.com/questions/236129/split-a-string-in-c

using namespace std;

int main() {
	string dis;
	cin >> dis;
	stringstream jj2(dis);
	int num;
	jj2 >> num;

	int c;
	char line[2];
	// while (c <= 100) {
	// 	if(agetline(cin, line)) {
	// 		cout << line;
	// 	}
	// }
	while (getchar() != '\n') {
		gets(line);
		cout<<line<<endl;
	}
	
	return 0;
}