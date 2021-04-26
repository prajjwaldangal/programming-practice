#include <stdio.h>
#include <stdlib.h>

char * getbuf() 
{
	char * myBuf = (char *) malloc(sizeof(char) * 4);
	gets(myBuf);	
	return myBuf;
}

int pass2(int a1, char a2, short a3, long a4, 
		int a5, char a6, short a7, long a8, 
		long a9, long a10, long a11) {

	getbuf();
	return a1+a2+a3+a4+a5+a6+a7+a8+a9+a10+a11;
}

int pass(int a1, char a2, short a3, long a4, 
		int a5, char a6, short a7, long a8, 
		long a9, long a10, long a11) {
	return pass2(a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11);
}

int main(void) {
	pass(1, 'b', 3,4,5,'a',7,8, 9, 10, 11);
	return 0;
}
