#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;

#define MAX 1001

int d[MAX], fi[MAX];

void FillEuler()
{
	memset(fi, 0, sizeof fi); fi[1] = 1;
	for (int i = 2; i < MAX; i++) {
		if (!fi[i]) {
			for (int j = i; j < MAX; j += i)
			{
				if (!fi[j]) fi[j] = j;
				fi[j] -= fi[j] / i;
			}
		}
	}
}

void f()
{
	for (int i = 2; i <= sqrt(1.0*MAX); i++)
		for (int j = i * i; j < MAX; j += i)
		{
			if (i * i < j) d[j] += i * fi[j / i] + j / i * fi[i];
			if (i * i == j) d[j] += i * fi[i];
		}
}

int main() {
	memset(d, 0, sizeof d);
	FillEuler();
	for (int i = 2; i < MAX; i++) d[i] = fi[i];
	f();
	for (int i = 3; i < MAX; i++) d[i] += d[i - 1];
	int n;
	while (scanf("%d", &n), n) printf("%d\n", d[n]);
	return 0;
}
