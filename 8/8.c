/* find the 13 adjascent digits that have the largest product
 * what is that product?
 */

#include <stdio.h>
#include <stdlib.h>

unsigned long int product(char *start) {
	// perform the multiplication
	int i;
	unsigned long int result = 1;
	char digit;
	for(i=0; i<13; i++) {
		digit = start[i];
		result *= atoi(&digit);
	}

	return result;
}

/* find the next starting digit to multiply
 * must check for 0s, and advance the start point beyond them
 */
int advance(char *number, int prev) {
	// start by looking at one character past the previous marker
	int next = ++prev;

	// check for 0s
	// if any are found, call the function again, starting after the found 0
	// check for null terminator
	int i;
	for (i=0; i<13; i++) {
		if (number[next + i] == '0') {
			return advance(number, next + i);
		}
		if (number[next + i] == '\0') {
			return 0;
		}
	}

	// if no 0s are found, the next pointer is good
	return next;
}

int main(int argc, char *argv[])
{
	char input[1001] = "731671765313306249192251196744265747423553491949349698352031277450632623957831801698480186947885184858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450";

	// store the highest product yet, and the pointer to its first digit
	// loop through until the number ends
	unsigned long int greatest_product, temp_product = 1;
	int start_digit = 1;

	int i;
	for (i=0; (advance(input, i) != 0); i = advance(input, i)) {
		temp_product = product(input+i);
		if (temp_product > greatest_product) {
			greatest_product = temp_product;
			start_digit = i;
		}
	}

	printf("greatest product: %ld\nstarting digit: %d\n", greatest_product, start_digit);
	return 1;
}
