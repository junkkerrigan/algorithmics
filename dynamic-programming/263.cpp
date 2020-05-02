// #define CURRENT

#ifdef CURRENT

#include <iostream>

using namespace std;

const long long MOD = 12345;

int main()
{
    long long n;
    cin >> n;

    if (n == 1) {
        cout << 2;
    } else if (n == 2) {
        cout << 4;
    } else {
        long long sum = 2, endsWith1 = 1, endsWith11 = 0;
        long long sumTemp, endsWith1Temp, endsWith11Temp;

        for (int i = 0; i < n - 1; i++) {
            sumTemp = sum * 2 - endsWith11;
            endsWith1Temp = sum - endsWith1 - endsWith11;
            endsWith11Temp = endsWith1;

            sum = (sumTemp + MOD) % MOD;
            endsWith1 = (endsWith1Temp + MOD) % MOD;
            endsWith11 = (endsWith11Temp + MOD) % MOD;
        }

        cout << sum;
    }

    return 0;
}

#endif