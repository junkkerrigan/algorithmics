// #define CURRENT

#ifdef CURRENT

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<long long>> floor(n, vector<long long>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++) {
            cin >> floor[n - i - 1][j];
        }
    }

    for (int i = 1; i < n; i++) {
        floor[i][0] += floor[i - 1][0];
    }
    for (int j = 1; j < m; j++) {
        floor[0][j] += floor[0][j - 1];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            floor[i][j] += max(floor[i - 1][j], floor[i][j - 1]);
        }
    }

    int x = n - 1, y = m - 1;
    while (x || y)
    {
        floor[x][y] = -1;

        if (!x) {
            y--;
        } else if (!y) {
            x--;
        } else {
            if (floor[x - 1][y] > floor[x][y - 1]) {
                x--;
            }
            else {
                y--;
            }
        }
    }

    floor[0][0] = -1;
    x = 0;
    y = 0;
    while (x < n - 1 || y < m - 1)
    {
        if (x < n - 1 && floor[x + 1][y] == -1) {
            cout << "F";
            x++;
        } else {
            cout << "R";
            y++;
        }
    }
}

#endif