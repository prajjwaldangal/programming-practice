#include <stdio.h>

struct S1 {
	long Arr[10];
};

typedef char Type;

int main() {
	struct S1 Brr[10];
	Type * ptr1 = (Type *) Brr[6].Arr;
	Type * ptr2 = (Type *) Brr[2].Arr;

	printf("ptr1 - ptr2 = %ld\n", ptr1-ptr2);
	return 0;
}
