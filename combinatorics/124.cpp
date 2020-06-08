#include <iostream>
using namespace std;

int main() {
  int param;
  while (cin >> param) {
    cin.clear();
    cout << 4 * param << " " << param * param << '\n';
  }
}