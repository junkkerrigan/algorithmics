#include <iostream>

using namespace std;

long p, q;

long g(long p)
{
	long t = p % 10;
	if (!p) return 0;
	return t * (1 + t) / 2 + p / 10 * 45 + g(p / 10);
}

long s(long p, long q)
{
	return g(q) - g(p - 1);
}

int main() {
	while (scanf("%ld %ld", &p, &q), p + q >= 0) printf("%ld\n", s(p, q));
	return 0;
}
