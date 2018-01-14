/* Atom is a pointer to string (or anything)
 * 2 atoms are identical if they point to same location
 * atom can be used for hash table
 */

#include "atom.h"
#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>

static struct atom {
	struct atom *link;
	int len;
	char *str;
} * buckets[2048]; // buckets[2048] contain 2048 atom pointer

#define NELEMS(x) ((sizeof(x)) / (sizeof((x)[0])))

const char *Atom_string(const char *str)
{
	assert(str);
	return Atom_new(str, strlen(str));
}

const char *Atom_int(long n)
{
	// 43 is enough to represent any long number
	char str[43];
	char *s = str + sizeof(str);
	unsigned long m;

	// convert n (long) -> m (unsigned long)
	// -1000..0..999 -> 0..999
	if (n == LONG_MIN)
		// 1UL is an unsigned long int with a value of 1 represented at
		// the bit level as: 00000000000000000000000000000001
		m = LONG_MAX + 1UL;
	else if (n < 0)
		m = -n;
	else
		m = n;
	// s represent m in string, ex "1234"
	do {
		*--s = m % 10 + '0';
	} while ((m /= 10) > 0);
	if (n < 0)
		*--s = '-';
	return Atom_new(s, (str + sizeof(str)) - s);
}

// Atom_new computes a hash number for the sequence given by str[0..len-1]
const char *Atom_new(const char *str, int len)
{
	assert(str);
	assert(len >= 0);

	unsigned long h;
	// h <- hash str
	h %= NELEMS(buckets);
	struct atom *p;
	for (p = buckets[h]; p; p = p->link) {
		if (len == p->len) {
			// compare to check if str exist in buckets[h]
			for (i = 0; i < len && p->str[i] == str[i];)
				++i;
			if (i == len)
				return p->str;
		}
	}
	// str doesn't exist, create new
	p = malloc(sizeof(*p) + len + 1);
	p->len = len;
	p->str = (char *)(p + 1);

	return p->str;
}

int main()
{
	printf("%ld %ld\n", LONG_MAX + 1UL, LONG_MIN);
	return 0;
}
