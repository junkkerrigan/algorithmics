// #define CURRENT true

#ifdef CURRENT

#include <iostream>
#include <vector>

using namespace std;

void DFS(const vector<vector<bool>>& adjacencyMatrix, vector<bool>& visited, int v, int& componentSize) {
    componentSize++;
    visited[v] = true;

    int n = adjacencyMatrix.size();

    for(int i = 0; i < n; i++) {
        if (adjacencyMatrix[v][i] && !visited[i]) {
            DFS(adjacencyMatrix, visited, i, componentSize);
        }
    }

    return;
}

int main() {
    int n, start;
    cin >> n >> start;
    start--;

    vector<vector<bool>> adjacencyMatrix(n, vector<bool>(n, true));
    int buf;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> buf;
            if (buf == 0) {
                adjacencyMatrix[i][j] = false;
            }
        }
    }

    int componentSize = 0;
    vector<bool> visited(n, false);

    DFS(adjacencyMatrix, visited, start, componentSize);

    cout << componentSize;
}

#endif
