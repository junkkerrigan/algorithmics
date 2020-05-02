// #define CURRENT

#ifdef CURRENT

#include <iostream>

using namespace std;

void extendedEuclideanAlgorithm(int a, int b, int& x, int& y, int& d)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        d = a;
        return;
    }

    extendedEuclideanAlgorithm(b, a % b, x, y, d);

    int temp = y;
    y = x - y * (a / b);
    x = temp;
}

int main() {
    int a, b;
    while (cin >> a >> b)
    {
        int x, y, d;
        extendedEuclideanAlgorithm(a, b, x, y, d);
        cout << x << ' ' << y << ' ' << d << '\n';
    }
    return 0;
}

#endif