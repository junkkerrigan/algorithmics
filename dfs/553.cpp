// #define CURRENT true

#ifdef CURRENT

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

void reset(
    const map<string, vector<string>>& adjacencyList,
    map<string, bool>& visited
) {
    for(const auto& it : adjacencyList) {
        visited[it.first] = false;
    }
}

void DFS(
    const string& rootId,
    const string& currentId,
    const map<string, vector<string>>& adjacencyList,
    map<string, bool>& visited,
    bool& isCyclic
) {
    visited[currentId] = true;

    if (isCyclic) {
        return;
    }

    string callableId;

    for(const auto& it : adjacencyList.at(currentId)) {
        callableId = it;
        if (callableId == rootId) {
            isCyclic = true;
            return;
        }
        if (!visited[callableId]) {
            DFS(rootId, callableId, adjacencyList, visited, isCyclic);
        }
    }

    return;
}

int main() {
    int n;
    cin >> n;

    map<string, vector<string>> adjacencyList;

    string selfId;
    int k;
    string callableId;
    string delimiter;
    vector<string> ids(n);

    for(int i = 0; i < n; i++) {
        cin >> selfId;
        ids[i] = selfId;

        cin >> k;
        adjacencyList[selfId] = vector<string>();

        for(int j = 0; j < k; j++) {
            cin >> callableId;
            adjacencyList[selfId].push_back(callableId);
        }

        if (i < n - 1) {
            cin >> delimiter;
        }
    }

    map<string, bool> visited;
    bool isCyclic;
    map<string, bool> results;

    for(const auto& it : adjacencyList) {
        reset(adjacencyList, visited);
        isCyclic = false;

        DFS(it.first, it.first, adjacencyList, visited, isCyclic);
        results[it.first] = isCyclic;
    }

    for(int i = 0; i < n; i++) {
        if (results[ids[i]]) {
            cout << ids[i] << ": YES\n";
        } else {
            cout << ids[i] << ": NO\n";
        }
    }
}

#endif
