#include <math.h>
#include <stdio.h>


int maxStep(int n, int k) {
	int m;
	int arr[n+1];
	for (int i=1; i<=n; i++) {

	}

	return m;
}

int main() {
	int j = maxStep(3, 4);
	printf("%d", j);
	return 0;
}


/*

def recursive_function(board, a, b, r, c):
    global count
    if a == r - 1 and b == c - 1:
        count += 1
    if b != (c -1) and board[a][b+1]:
        recursive_function(board, a, b+1, r, c)
    if a != (r-1) and board[a+1][b]:
        recursive_function(board, a+1, b, r, c)

def numberOfPaths(a):
    if a[0][0] == 0:
        return 0
    recursive_function(a, 0, 0, len(a), len(a[0]))
    return count

*/