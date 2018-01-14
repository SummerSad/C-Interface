#include "arith.h"
#include <stdio.h>

int Arith_max(int x, int y)
{
	return x > y ? x : y;
}

int Arith_min(int x, int y)
{
	return x < y ? x : y;
}

int Arith_div(int x, int y)
{
	if ((x > 0) == (y > 0) || x % y == 0)
		return x / y;
	else
		return x / y - 1;
}

int Arith_mod(int x, int y)
{
	return x - y * Arith_div(x, y);
}

int Arith_ceiling(int x, int y)
{
	return Arith_div(x, y) + (x % y != 0);
}

int Arith_floor(int x, int y)
{
	return Arith_div(x, y);
}

int main()
{
	printf("%d\n", Arith_mod(-13, 5));
	return 0;
}
