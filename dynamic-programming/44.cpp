#define CURRENT

#ifdef CURRENT

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> res(n + 1);
    res[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        res[i] = i;

        for (int j = 1; 2 * j < i; j++) {
            if (res[j] + res[i - j] < res[i]) {
                res[i] = res[j] + res[i - j];
            }
        }

        for (int j = 2; (int)pow(j, 2) <= i; j++) {
            if (i % j == 0 && res[j] + res[i / j] < res[i]) {
                res[i] = res[j] + res[i / j];
            }
        }
    }

    cout << res[n];
    return 0;
}

#endif
