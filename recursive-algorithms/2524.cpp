
#include <iostream>

using namespace std;

#define MAX 44

int n, k, tests, fib[MAX] = {1, 1};

char getAnswer(int n, int k)
{
  if (n == 0)
    return 'a';
  if (n == 1)
    return 'b';
  if (k <= fib[n - 2])
    return getAnswer(n - 2, k);
  return getAnswer(n - 1, k - fib[n - 2]);
}

int main()
{
  for (int i = 2; i < MAX; i++)
    fib[i] = fib[i - 1] + fib[i - 2];
  scanf("%d", &tests);
  while (tests--)
  {
    scanf("%d %d", &n, &k);
    printf("%c\n", getAnswer(n, k));
  }
  return 0;
}