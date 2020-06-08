#include <iostream>
#include <vector>
#include <set>
#include <utility>
using namespace std;
#define INF 1000000000000
#define MAX 100000

vector<pair<int, long long>> G[MAX];
vector<int> path, ans;
set<pair<long long, int>> q;
long long length[MAX];
int parent[MAX];

int main() {
  ios::sync_with_stdio(false);
  int n, m, a, b;
  cin >> n >> m >> a >> b;
  a--, b--;
  for (int i = 0; i < m; i++) {
    int from, to, len;
    cin >> from >> to >> len;
    from--, to--;
    G[to].push_back(make_pair(from, len));
    G[from].push_back(make_pair(to, len));
  }
  for (int i = 0; i < n; i++)
    length[i] = INF;
  length[a] = 0;
  q.insert(make_pair(length[a], a));
  while (!q.empty()) {
    int v = q.begin()->second;
    q.erase(q.begin());
    for (int i = 0; i < G[v].size(); i++) {
      int to = G[v][i].first, len = G[v][i].second;
      if (length[v] + len < length[to]) {
        q.erase(make_pair(length[to], to));
        length[to] = length[v] + len;
        parent[to] = v;
        q.insert(make_pair(length[to], to));
      }
    }
  }
  if (length[b] == INF) {
    cout << "-1";
    return 0;
  }
  cout << length[b] << endl;
  int c = b;
  while (c != a) {
    ans.push_back(c + 1);
    c = parent[c];
  }
  ans.push_back(a + 1);
  cout << ans[ans.size() - 1];
  for (int it = ans.size() - 2; it >= 0; it--)
    cout << " " << ans[it];
  cout << endl;
  return 0;
}