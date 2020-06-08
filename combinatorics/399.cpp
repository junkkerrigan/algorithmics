#include <iostream>
using namespace std;

int main() {
  int n, k;
  long long brackets[33];
  brackets[0] = 1;
  for (int i = 1; i <= 32; ++i) {
    brackets[i] = 0;
    for (int j = 0; j < i; ++j) {
      brackets[i] += brackets[j] * brackets[i - 1 - j];
    }
  }
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> k;
    cout << (k % 2 == 0 ? brackets[k / 2] : 0) << endl;
  }
  return 0;
}