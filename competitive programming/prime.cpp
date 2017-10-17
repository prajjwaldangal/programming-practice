#include <stdio.h>
#include <stdlib.h>
#include <vector>

bool isPrime(int num)
{
	if ((num % 2 == 0) && (num > 2))
		return false;

	for (int i=3; i<=int(num^(1/2)); i+=2)
	{
		if (num % i == 0) 
			return false;
	}
	return true;
}

std::vector<int> primesum(int A)
{
	int j = 0;
	std::vector <int> v;
	for (int i=2; i<=int(A/2); i++)
	{
		j = A - i;
		if (isPrime(i) && isPrime(j))
		{
			v.push_back(i);
			v.push_back(j);
		}
	}
	return v;
}

int main() {
	int li[] = {4, 10, 12, 14, 18, 78, 52, 10002, 16777214, 16777214*2, 378};
	for (int j=0; j < sizeof(li)/sizeof(*li); j++)
	{
		printf("List %d: Res: %d, %d\n", j, primesum(li[j])[0], primesum(li[j])[1]);
	}
	printf("%d\n", int(2.0));
	return 0;
}