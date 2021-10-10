#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long N = 600851475143;

int main() {
	bool * prime = (bool *) malloc(sizeof(bool) * (N+1) );
	// prime[2] = true;
	for (long i=2; i<=N; i++) {
		prime[i] = true;
	}
	for (long i=2; i*i <= N; i++) {
		if (!prime[i]) {
			continue;
		}
		for (long j=i*i; j <= N; j+=i) {
			prime[j] = false;
		}
	}
	printf("primes are:\n");

	for (long i=2; i <= N; i++) {
		if (prime[i]) {
			printf("%ld ", i);
		}
	}
	return 0;
}
