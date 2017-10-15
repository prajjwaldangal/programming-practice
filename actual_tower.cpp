// general enough to accomodate odd v even mid_diff, by just the change of glob var PAR
// 0 -> even, 1 -> odd

#include <iostream>
#include <string>
#include <string.h>

int PAR = 1;
int LEV = 0;
int UNIT_IND = 3;
char SYM1 = 'O';
char SYM2 = '_';
char SYM3 = '|';
using namespace std;

void draw(int level);

int main(int argc, char * argv[]) {
	cout << "Enter no. of levels: ";
	cin >> LEV;
	LEV = LEV - 1;
	for (int i=0; i<=LEV; i++){
		draw(i);
	}
}

void draw(int level) {
	int indent = (LEV-level) * UNIT_IND;
	cout << string(indent, " ");
	for (int j=(LEV-level); j <= LEV; j++) {
		cout << SYM1 << SYM2 << SYM2;
	}
	cout << SYM1 << endl;
	cout << string(indent, " ");
	for (int j=(LEV-level); j<=LEV; j++) {
		cout << SYM3 << SYM2 << SYM2;
	}
	cout << SYM3 << endl;
}