// #define CURRENT true

#ifdef CURRENT

#include <iostream>
#include <vector>

using namespace std;

void DFS(const vector<vector<int>>& adjacencyList, int from, vector<bool>& visited) {
    visited[from] = true;

    for(int i = 0; i < adjacencyList[from].size(); i++) {
        int to = adjacencyList[from][i];
        if (!visited[to]) {
            DFS(adjacencyList, to, visited);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adjacencyList(n, vector<int>(n));
    int from, to;
    for(int i = 0; i < m; i++) {
        cin >> from >> to;
        from--;
        to--;
        adjacencyList[from].push_back(to);
        adjacencyList[to].push_back(from);
    }

    vector<bool> visited(n, false);

    DFS(adjacencyList, 0, visited);

    for(int i = 0; i < n; i++) {
        if (!visited[i]) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}

#endif
