#include <iostream>
using namespace std;

struct jj2 {
	char c;
	int i;

	jj2 foo();
};

jj2 foo() {
	jj2 k;
	k.c='a';
	k.i=1;
	return k;
}

jj2 * bar() {
	jj2 * k = new jj2();
}

jj2 jj2::foo() {
	jj2 k = foo();
	return k;
	cout << "Hello world" << endl;
}

int main() {
	jj2 k = foo();
	cout << k.c << k.i << endl;
	jj2 i;
	
	jj2 k2 = i.foo();
	cout << "From member func: " << k2.c << k2.i;
	return 0;
}