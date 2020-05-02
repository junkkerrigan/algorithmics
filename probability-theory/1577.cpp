// #define CURRENT

#ifdef CURRENT

#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

double integrate(double a, double k, double t) {
    double res = 0;
    double val = a / k;

    if (t == 1) return max(a, k);
    if (val > 1) return a * (1 - t);

    if (val >= t) res = a * (val - t);
    else val = t;

    res += k * (1 - pow(val, 2)) / 2;
    return res / (1 - t);
}

double maxWinning(int n, double t, int a = 1) {
    if (!n) return a;

    double k = maxWinning(n - 1, t, 2 * a);
    return integrate(a, k, t);
}

int main() {
    int n;
    double t;

    while (cin >> n >> t && n) {
        cout << fixed << setprecision(3) << maxWinning(n, t) << '\n';
    }
}

#endif
