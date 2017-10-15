#include "btree.h"
#include <iostream>

using namespace std;

BinaryTree::BinaryTree() {
	root = NULL; // or equivalently this->root = NULL
}


void foo(int &a, int &b) {

}

void foo(int *a, int *b) {
	* a = * a + 5;
	* b = * b + 5;
	cout << * a << " " << * b << endl;
	cout << *a+*b << endl;
}

int main() {
	int a=2, b=10;
	foo(&a, &b);
	cout << a << " " << b << endl;
	return 0;
}