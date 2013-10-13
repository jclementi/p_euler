// find the difference between the sum of the squares of the first one hundred
// natural numbers and the square of the sum

#include <stdio.h>

int main(int argc, char *argv[])
{
	int lim,diff = 0;
	int sqsum = 0, smsquare=0;
	int i;

	lim = atoi(argv[1]);

	for (i=1; i<=lim; i++) {
		sqsum += i;
		smsquare += i*i;
	}

	sqsum *= sqsum;
	diff = sqsum-smsquare;		

	printf("The difference between the sum of the squares and \
		the square of the sums for the first %d \
		natural numbers is %d.\n",lim,diff);

	return 1;
}
