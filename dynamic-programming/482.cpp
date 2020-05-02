// #define CURRENT

#ifdef CURRENT

#include <iostream>

using namespace std;

long long calculateCount(long long current)
{
    if (current < 0) {
        return 0;
    }
    if (current == 0) {
        return 1;
    }
    if (current == 2) {
        return 3;
    }
    return calculateCount(current - 2) * 4 - calculateCount(current - 4);
}

int main()
{
    long long n;
    while (cin >> n && n != -1) {
        if (n == 1) {
            cout << 0;
        } else {
            cout << calculateCount(n);
        }
        cout << '\n';
    }
}

#endif