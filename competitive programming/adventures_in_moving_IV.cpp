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
#include <vector>
#include <algorithm>

// https://stackoverflow.com/questions/236129/split-a-string-in-c
int CAP = 200;
int DIS_PER_LIT = 1;

using namespace std;
vector <int> dist;
vector <int> prcs;
vector <int> prcs_n;
int main() {
	int dis;
	cin >> dis;
	cout << dis << endl;
	string line;
	getline(cin, line);
	getline(cin, line);
	int d, p;
	while (!line.empty()) {
		char * l = new char[line.length()];
		strcpy(l, line.c_str());
		sscanf(l, "%d %d", &d, &p);
		dist.push_back(d);
		prcs.push_back(p);
		prcs_n.push_back(p);
		getline(cin, line);
	}
	sort(prcs_n.begin(), prcs_n.end());
	int i = 0;
	while (!prcs.empty()) {
		int temp = prcs_n[i];
		int ind = find(prcs.begin(), prcs.end(), temp);	
	}
	
	/* 50*999 +  */
	
	// fill minimal until you get to lowest price
	// fill all
	// repeat
	return 0;
}