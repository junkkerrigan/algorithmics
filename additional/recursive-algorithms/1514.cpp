#include <iostream>

using namespace std;

unsigned long PowMod(unsigned long x, unsigned long y, unsigned long n)
{
	if (!y) return 1;
	if (y & 1) return x * PowMod(x * x % n, y / 2, n) % n;
	return PowMod(x * x % n, y / 2, n);
}

int main() {
	int cs = 1;
	unsigned long k, n, m, t, res;
	while (scanf("%lu %lu %lu", &k, &n, &t), k + n + t)
	{
		m = 1;
		for (int i = 0; i < t; i++) m *= 10;
		res = PowMod(k % m, n, m);
		printf("Case #%d: %ld\n", cs++, res);
	}
	return 0;
}
