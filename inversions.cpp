// 11??00? 

#include <iostream>
#include <string>
#include <sstream>

// https://open.kattis.com/contests/hdm73k/problems/deletethis

using namespace std;

int main() {
	string line;
	getline(cin, line);
	istringstream iss(line);
	int n_r, n_c, n, m;
	iss >> n_r >> n_c >> n >> m;
	// n -> delete
	// m -> don't, n+m <= 100
	// 15 -> height, 9 -> width

	// inside the box if its center is in the box
	// not in same location but can overlap, at least 
	//    one pixel on screen->initially and after the move
	// Edges of a delete rectangle lie on pixel boundaries.

	// output minimum no. of file icons to move
	
	// should of course remove in one delete op.
	// m -> m()
	// upper left

	// After this will be a set of 2(n+m) integers indicating the location of the n+m
 	// files, the first n
 	// of which are the files to be deleted. 
 	int arr[2 * (n + m)];
 	getline(cin, line);
 	// https://stackoverflow.com/questions/236129/most-elegant-way-to-split-a-string
 	cout << line;
	return 0;
}