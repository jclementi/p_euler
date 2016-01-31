/* fird the pythagorean triplet for which a + b + c = 1000
 * a < b < c
 * find the product a*b*c
 */

/* i)	a + b + c = 1000
 * ii)	a < b < c
 * iii) a^2 + b^2 = c^2
 *
 * test triplets satisfying i and ii for condition iii
 */
#include <stdio.h>

int is_triplet(int a, int b, int c) {
	return ((a*a + b*b) == c*c);
}

int main(int argc, char *argv[])
{
	int a, b, c;
	int sum_ab, prod_abc;
	for (c=997; c > 1; c--) {
		// determine start values of a and b
		sum_ab = 1000 - c;
		for (a=1, b=sum_ab-1; a <= b; a++, b--) {
			if (a*a + b*b == c*c) {
				prod_abc = a*b*c;
				printf("Triplet values: %d, %d, %d\nProduct: %d\n", a, b, c, prod_abc);
				return 1;
			}
		}
	}

	return 0;
}
