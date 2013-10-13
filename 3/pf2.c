#include <stdio.h>

typedef unsigned long long int uint_64;

int is_prime(uint_64 n)
{
	uint_64 i;
	uint_64 ceil = n;

	for (i = 2; i <= ceil; i++) {
		if (n%i) {
			ceil = n/i;
		} else {
			return 0;
		}
	}

	return 1;
}

int main(int argc, char *argv[])
{
	uint_64 i;
	uint_64 f;
	uint_64 ceil;
	uint_64 n = 600851475143;

	for (i = 2; i <= ceil; i++) {
		if (n%i) continue;
		f = n/i;
		if (is_prime(f)) {
			printf("Largest prime factor is %llu\n",f);
			return f;
		}
	}
	return 0; 
}
		
