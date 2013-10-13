// find the smallest positive number that is
// evenly divisible by every number from 1 to 20
#include <stdio.h>

int div(unsigned int n)
{
	unsigned int d;
	unsigned int m;
	for (d = 20; d > 10; d--) {
		m = n/d;
		if (m*d != n) {
			return 0;
		}
	}
	return 1;
}


int main (int argc, char *argv[])
{
	unsigned int n;
	unsigned int a = 19*17*13*11*7*5*3*2;

	for (n=a*20; ; n += a) {
		if (div(n)) {
			printf("Answer is: %u\n",n);
			return 1;
		}
	}
	return 0;
}

