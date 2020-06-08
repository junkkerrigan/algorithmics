#include <iostream>

using namespace std;

struct RatNumber
{
	long x, y;
} one6, temp, res[25][150], s;

long gcd(long a, long b) { return !b ? a : gcd(b, a % b); }

long lcm(long a, long b) { return a / gcd(a, b) * b; }

struct RatNumber add(struct RatNumber a, struct RatNumber b)
{
	struct RatNumber res;
	res.y = lcm(a.y, b.y);
	res.x = res.y / a.y*a.x + res.y / b.y*b.x;
	long d = gcd(res.x, res.y);
	if (d) res.x /= d, res.y /= d;
	return res;
}

int main()
{
	for (int i = 0; i < 25; i++)
		for (int j = 0; j < 150; j++) res[i][j].x = 0, res[i][j].y = 1;

	one6.x = 1; one6.y = 6;
	for (int i = 1; i <= 6; i++) res[1][i] = one6;
	for (int n = 2; n < 25; n++) {
		for (int i = n - 1; i <= 6 * (n - 1); i++)
			for (int j = 1; j <= 6; j++)
			{
				temp = res[n - 1][i];
				temp.y = temp.y * 6;
				res[n][i + j] = add(res[n][i + j], temp);
			}
	}
	int n, x;
	while (scanf("%d %d", &n, &x), n + x)
	{
		s.x = 0, s.y = 1;
		for (int i = x; i <= 6 * n; i++) s = add(s, res[n][i]);

		if (s.x == 0) printf("0\n");
		else
			if (s.y == 1) printf("%ld\n", s.x);
			else printf("%ld/%ld\n", s.x, s.y);
	}
	return 0;
}
