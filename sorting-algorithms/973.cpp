#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, mas[100001];
    cin >> n;
    for (int i = 0; i < n; i++) scanf("%d", &mas[i]);
    sort(mas, mas + n);
    for (int i = 0; i < n - 1; i++) printf("%d ", mas[i]);
    printf("%d\n", mas[n - 1]);
}