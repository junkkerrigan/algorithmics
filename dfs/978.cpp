// #define CURRENT true

#ifdef CURRENT

#include <iostream>
#include <vector>

using namespace std;

void DFS(const vector<vector<int>>& adjacencyList, int from, vector<bool>& visited, int edgesCount = 0) {
    if (edgesCount == adjacencyList.size() - 1) {
        fill(visited.begin(), visited.end(), true);
        return;
    }
    visited[from] = true;

    for(int i = 0; i < adjacencyList[from].size(); i++) {
        int to = adjacencyList[from][i];
        if (!visited[to]) {
            cout << from + 1 << ' ' << to + 1<< '\n';
            DFS(adjacencyList, to, visited, edgesCount + 1);
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
}

#endif
