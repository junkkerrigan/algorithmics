// #define CURRENT

#ifdef CURRENT

#include <iostream>
#include <string>

using namespace std;

long long GCD(long long a, long long b) {
    return b ? GCD(b, a % b) : a;
}

struct Rational {
    long long x;
    long long y;

    Rational operator+(Rational number) {
        Rational res = {x * number.y + y * number.x, y * number.y};

        long long d = GCD(res.x, res.y);
        if (d) {
            res.x /= d;
            res.y /= d;
        }

        return res;
    }
};

int countOfDigits(long long number)
{
    int res = 0;
    while (number)
    {
        number /= 10;
        res++;
    }
    return res;
}

int main() {
    int n;
    while (cin >> n)
    {
        Rational c = {0, 1};
        Rational temp = {1, 1};

        for (int i = 1; i <= n; i++)
        {
            temp.y = i;
            c = c + temp;
        }
        c.x = n * c.x;

        long long d = GCD(c.x, c.y);
        c.x /= d;
        c.y /= d;

        d = c.x / c.y;
        c.x -= d * c.y;

        if (c.y > 1) {
            cout << string(countOfDigits(d) + 1, ' ') << c.x << '\n';
            cout << d << ' ' << string(countOfDigits(c.y), '-') << '\n';
            cout << string(countOfDigits(d) + 1, ' ') << c.y << '\n';
        } else {
            cout << d << '\n';
        }
    }
    return 0;
}

#endif
