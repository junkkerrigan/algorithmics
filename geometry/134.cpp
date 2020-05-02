// #define CURRENT true

#ifdef CURRENT

#include <iostream>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
    set<pair<int, int>> ans;
    int x1, y1, r1, x2, y2, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

    for (int i = -r1; i <= r1; i++)
        ans.insert(make_pair(i + x1, y1));
    for (int i = -r1; i <= r1; i++)
        ans.insert(make_pair(x1, i + y1));
    for (int i = -r2; i <= r2; i++) {
        ans.insert(make_pair(i + x2, y2));
    }
    for (int i = -r2; i <= r2; i++) {
        ans.insert(make_pair(x2, i + y2));
    }
    for (int i = 1; i <= r1; i++) {
        for (int j = 1; j <= sqrt(pow(r1, 2) - pow(i, 2)); j++) {
            ans.insert(make_pair( x1 + i, y1 + j));
            ans.insert(make_pair(x1 - i, y1 + j));
            ans.insert(make_pair(x1 + i, y1 - j));
            ans.insert(make_pair(x1 - i, y1 - j));
        }
    }
    for (int i = 1; i <= r2; i++) {
        for (int j = 1; j <= sqrt(pow(r2, 2) - pow(i, 2)); j++) {
            ans.insert(make_pair( x2 + i, y2 + j));
            ans.insert(make_pair(x2 - i, y2 + j));
            ans.insert(make_pair(x2 + i, y2 - j));
            ans.insert(make_pair(x2 - i, y2 - j));
        }
    }

    cout << ans.size();
    return 0;
}

#endif