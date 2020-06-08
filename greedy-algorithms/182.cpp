#include <iostream>
#include <algorithm>

using namespace std;

struct role
{
  int g, h;
} x[10000];

bool compare(role a, role b)
{
  return (a.g - a.h) < (b.g - b.h);
}

int main()
{
  int n, g, h;
  cin >> n >> g >> h;
  if (n < g + h)
  {
    cout << "-1\n";
    return 0;
  }
  for (int i = 0; i < n; i++)
  {
    cin >> x[i].g;
    cin >> x[i].h;
  }
  sort(x, x + n, compare);
  int p = 0;
  for (int i = 0; i < n; i++)
  {
    if (i < h)
      p += x[i].h;
    else if (i < n - g)
      p += x[i].h > x[i].g ? x[i].h : x[i].g;
    else
      p += x[i].g;
  }
  cout << p << endl;
}