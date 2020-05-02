// #define CURRENT

#ifdef CURRENT

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long a, b;
    cin >> a >> b;

    long long temp = min(a, b);
    a = max(a, b);
    b = temp;

    long long ans = 0;
    while (b) {
        ans += a / b;
        a %= b;
        swap(a, b);
    }

    cout << ans;
    return 0;
}

#endif
