int func(int p1) {
// what effect does the removal of this line make in the assembly code
	return p1+10;
}

int main(void) {
	int a = 0;
	int b;
	b = func(a);
	return b;
}
