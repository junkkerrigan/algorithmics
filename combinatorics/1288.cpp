#include <iostream>
#include <string>

using namespace std;

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  string s;
  if (a + b == 0)
    cout << 0 << endl;
  else {
    if (a == b | !(a * b))
      cout << 1;
    else
      cout << 2;
    for (int i = 0; i < n - 1; i++)
      s += '0';
    cout << s << endl;
  }
}