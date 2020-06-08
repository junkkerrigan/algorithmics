#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k; cin >> n >> k;
    vector<int> v;
    v.resize(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &v[i]);
    sort(v.begin(), v.end());
    int res = 0;
    int a = 0;
    int b = v.size() - 1;
    if (v[b] > k) {
        printf("Impossible\n");
        return 0;
    }
    while (a <= b) {
        if (v[a] + v[b] > k) b--;
        else {
            a++;
            b--;
        }
        res++;
    }
    printf("%d\n", res);
}