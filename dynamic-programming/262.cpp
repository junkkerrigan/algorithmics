 #define CURRENT

#ifdef CURRENT

#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int calculateMaxSum(
    int index,
    const int& n,
    const int& k,
    const vector<int>& numbers,
    vector<int>& dn
) {
    if (index >= 2 * n) {
        return 0;
    }
    if (dn[index] > INT_MIN) {
        return dn[index];
    }

    int maxValue = calculateMaxSum(index + 1, n, k, numbers, dn);
    for (int i = 2; i <= k; i++) {
        maxValue = max(
            maxValue,
            calculateMaxSum(index + i, n, k, numbers, dn)
        );
    }

    dn[index] = numbers[index] + maxValue;
    return dn[index];
}

int main() {
    int n;
    cin >> n;

    vector<int> numbers(2 * n, 0);
    numbers[0] = 0;
    for (int i = 0; i < n; i++) {
        cin >> numbers[i + 1];
    }

    int k;
    cin >> k;
    vector<int> dn(2 * n, INT_MIN);

    cout << calculateMaxSum(0, n, k, numbers, dn);
}

#endif