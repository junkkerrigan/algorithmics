// #define CURRENT true

#ifdef CURRENT

#include <iostream>
#include <vector>

using namespace std;

void DFS(vector<vector<bool>>& isFree, int x, int y, int& roomSize) {
    roomSize++;
    isFree[x][y] = false;

    int n = isFree.size();

    if (x + 1 < n && isFree[x + 1][y]) {
        DFS(isFree, x + 1, y, roomSize);
    }
    if (x - 1 >= 0 && isFree[x - 1][y]) {
        DFS(isFree, x - 1, y, roomSize);
    }
    if (y + 1 < n && isFree[x][y + 1]) {
        DFS(isFree, x, y + 1, roomSize);
    }
    if (y - 1 >= 0 && isFree[x][y - 1]) {
        DFS(isFree, x, y - 1, roomSize);
    }

    return;
}

int main() {
    int n;
    cin >> n;

    vector<vector<bool>> isFree(n, vector<bool>(n, true));
    char buf;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> buf;
            if (buf == '*') {
                isFree[i][j] = false;
            }
        }
    }

    int startX, startY;
    cin >> startX >> startY;
    startX--;
    startY--;

    int roomSize = 0;
    DFS(isFree, startX, startY, roomSize);

    cout << roomSize;
}

#endif
