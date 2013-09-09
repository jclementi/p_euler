/* finds the largest prime factor of an input */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv) 
{
	int i;
	long int li;
	unsigned long long int lli;

	printf("Size of: \n");
	printf("\tint:\t%d\n",sizeof(i));
	printf("\tlong int:\t%d\n",sizeof(li));
	printf("\tlong long int:\t%d\n",sizeof(lli));

	lli = 0;
	lli = 0xffffffffffffffff;

	printf("Max value of long long: %llu\n",lli);
	return 0;
}


