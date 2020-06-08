#include <iostream>
#include <vector>

using namespace std;

vector<pair<int,int> > v;

int up[310];
int cmp(pair<int,int> a, pair<int,int> b)
{
    int mm = min(min(a.first,a.second),min(b.first,b.second));
    if ((mm == a.first) || (mm == b.second)) return 0;
    return 1;
}

void sort(void)
{
    int i, j;
    for(i = 0; i < v.size(); i++)
        for(j = i + 1; j < v.size(); j++)
            if (cmp(v[i],v[j])) swap(v[i],v[j]);
}

int main() {
    int n, i, b, a, sum;
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &up[i]);
    for (i = 0; i < n; i++)
        scanf("%d", &b), v.push_back(make_pair(up[i], b));
    sort();
    for (a = sum = i = 0; i < v.size(); i++)
        a += v[i].first, sum = max(a, sum) + v[i].second;
    printf("%d\n", sum);
}
