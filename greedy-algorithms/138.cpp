#include <iostream>

using namespace std;

int A[] = {500, 200, 100, 50, 20, 10};
int main()
{
  int n, a, b;
  cin >> n;
  b = 0;
  for (int i = 0; i < 6; ++i)
  {
    a = A[i];
    b += n / a;
    n %= a;
  }
  if (n > 0)
    b = -1;
  cout << b;
  return 0;
}