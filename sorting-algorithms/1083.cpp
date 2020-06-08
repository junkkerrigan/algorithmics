#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

#define MOD 10000

int PowMod(int x, int n, int m)
{
    if (n == 0) return 1;
    if (n % 2 == 0) return PowMod((x * x) % m, n / 2, m);
    return (x * PowMod(x, n - 1, m)) % m;
}

int main() {
    int n, a, res, x;
    scanf("%d %d", &a, &n);
    x = PowMod(2, n - 1, MOD);
    res = PowMod(a, x, MOD);
    printf("%d\n", res);
}