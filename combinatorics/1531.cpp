#include <iostream>
#include <string.h>

using namespace std;

long a, b, n, m, s[21][21];

long gcd(long A, long B) {
  if (B == 0)
    return A;
  return gcd(B, A % B);
}

void getAllKeys(int n, int m, long& a, long& b) {
  int i, k;
  long d;
  memset(s, 0, sizeof s);
  s[0][0] = 1;
  for (i = 1; i <= n; i++)
    for (k = 1; k <= n; k++)
      s[i][k] = s[i - 1][k - 1] + (i - 1) * s[i - 1][k];

  for (a = 0, i = 1; i <= m; i++)
    a += s[n][i];

  for (b = i = 1; i <= n; i++)
    b *= i;

  d = gcd(a, b);
  a /= d;
  b /= d;
}

int main() {
  while (scanf("%d %d", &n, &m) == 2) {
    getAllKeys(n, m, a, b);
    printf("%ld/%ld\n", a, b);
  }
  return 0;
}