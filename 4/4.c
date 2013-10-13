// finds the largest palindrome made from the product of two
// three-digit numbers

#include <stdio.h>
#include <stdlib.h>

int is_palindrome(int n)
{
	char sn[8];
	int d,i;

	sprintf(sn,"%d",n);

	for (i=0; sn[i]!='\0'; i++) {
		;
	}
	d = 0;
	i--;

	while (i-d > 0) {
		if (sn[i--] != sn[d++]) {
			return 0;
		}
	}

	return 1;
}

int has_int_factors(int n)
{
	int a,b;

	a = 999;
	b = n/a;

	while(a > b && a > 100) {
		b = n/a;
		if (a*b == n && (b>99)){
		       //printf("%d\t has integer factors, %d\t%d\n",n,a,b);
	       	       return 1;
		}
		a--;
	}
	return 0;
}

int main(int argc, char *argv[])
{
	int i,n;
	
	for (i=999999; i>99; i--) {
		if (is_palindrome(i) && has_int_factors(i)) {
			printf("Largest 6-dig palindrome with int \
				factors is %d\n",i);
			return 1;
		}
	}

	return 1;
}

		
