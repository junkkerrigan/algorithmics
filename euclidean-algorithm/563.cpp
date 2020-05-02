#define CURRENT

#ifdef CURRENT

#include <iostream>

using namespace std;

void extendedEuclideanAlgorithm(long long a, long long b, long long& x, long long& y, long long& d)
{
    if (b == 0) {
        x = 1;
        y = 0;
        d = a;
        return;
    }

    extendedEuclideanAlgorithm(b, a % b, x, y, d);

    long long temp = y;
    y = x - y * (a / b);
    x = temp;
}

int main() {
    long long t;
    cin >> t;

    long long a, b;
    while (t-- && cin >> a >> b)
    {
        long long x, y, d;
        extendedEuclideanAlgorithm(a, b, x, y, d);

        if (d != 1) {
            cout << "No Solution\n";
        } else {
            if (x < 0) {
                x += b;
                y -= a;
            }
            cout << x << ' ' << y << '\n';
        }
    }
    return 0;
}

#endif
