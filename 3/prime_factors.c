#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long int uint_64;

struct prime_list {
	uint_64 prime;
	struct prime_list *next;
};

struct primes {
	struct prime_list *largest;
	struct prime_list *smallest;
};

uint_64 is_prime(uint_64 n, struct primes *ps) 
{
	if (ps->largest->prime == 1) {
		return 1;
	}

	struct prime_list *pl;
	uint_64 prime;	

	pl = ps->smallest;
	prime = pl->prime;
	
	while(n % prime || prime == 1) {
		if (pl->next == NULL) {
			return 1;
		}
		pl = pl->next;
		prime = pl->prime;
	}

	return 0;
}

/* finds next prime; adds it to the list */
uint_64 next_prime(struct primes *ps) 
{
	uint_64 n;
	struct prime_list *new_p;
	struct prime_list *p;

	n = ps->largest->prime;

	for (++n; !is_prime(n,ps); n++) {}
	new_p = malloc(sizeof(struct prime_list));
	new_p->prime = n;
	new_p->next = NULL;

	ps->largest->next = new_p;
	ps->largest = new_p;

	return n;
}

void print_primes(struct primes *ps) 
{
	struct prime_list *pl;
	printf("Primes Found:\n");
	for (pl = ps->smallest; pl->next != NULL; pl = pl->next) {
		printf("%llu ",pl->prime);
	}
	printf("\n");
}


int main(int argc, char *argv[])
{
	if (argc != 2) {
		fprintf(stderr,"Enter the number for which to calculate the max prime factor.\n");
		exit(1);
	}

	/* initialize variables and structures */
	uint_64 in = strtoull(argv[1],NULL,10);
	uint_64 prime_factor = 1;
	uint_64 ceiling = in;
	uint_64 n;
	
	struct prime_list *l = malloc(sizeof(struct prime_list));
	struct prime_list *s = malloc(sizeof(struct prime_list));
	struct primes *ps = malloc(sizeof(struct primes));

	ps->largest = l;
	ps->smallest = s;

	s->prime = prime_factor;
	s->next = l;

	l->prime = prime_factor;
	l->next = NULL;
	
	/* algorithm *
	 * ceiling variable holds the largest number to search to for primes 
	 * beyond ceiling, it is guaranteed that there are no prime factors
	 */
	for (n = 1; n <= ceiling; n = next_prime(ps)) {
		if (!(in % n)) {
			printf("main:\t %llu is a prime factor\n",n);
			ceiling = in / n;
			prime_factor = n;
		}
	}

	print_primes(ps);
	printf("Largest prime factor of %llu:\t%llu\n",in,prime_factor);

	return prime_factor;
}
