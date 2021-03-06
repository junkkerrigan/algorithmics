#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
#include <iostream>

#define INF 0x7fffffff

using namespace std;

int n, m, d[101], g[101][101];
map<string, int> str;

void Dijkstra(int start, int* dis) {
  bool vis[101];
  for (int i = 1; i <= n; i++)
    dis[i] = INF, vis[i] = 0;
  vis[start] = 1, dis[start] = 0;
  for (int i = 1; i < n; i++) {
    int mi = INF, k = start;
    for (int j = 1; j <= n; j++)
      if (dis[j] < mi && !vis[j])
        mi = dis[j], k = j;

    vis[k] = 1;
    for (int j = 1; j <= n; j++) {
      if (!vis[j] && dis[j] > dis[k] + g[k][j] && g[k][j] < INF)
        dis[j] = dis[k] + g[k][j];
    }
  }
}

int main() {
  int cot = 1, top;
  while (scanf("%d%d%d", &n, &top, &m), n || top || m) {
    str.clear();
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        g[i][j] = INF;

    int start, num = 1, dis1[101], dis2[101], car[101], carnum = 0;
    memset(car, 0, sizeof(car));
    string a, b, c;
    cin >> a;
    if (str[a] == 0)
      str[a] = num++;
    start = str[a];
    for (int i = 0; i < top; i++) {
      cin >> a;
      if (str[a] == 0)
        str[a] = num++, d[carnum++] = str[a];
      car[str[a]]++;
    }
    int u, v, t;
    while (m--) {
      cin >> a >> b >> c;
      if (str[a] == 0)
        str[a] = num++;
      u = str[a];
      if (str[c] == 0)
        str[c] = num++;
      v = str[c];
      int sum = 0, k = 0;
      while (b[k] == '-' || b[k] == '<')
        k++;
      while (b[k] != '-')
        sum = sum * 10 + b[k] - '0', k++;
      t = sum;
      if (b[0] == '<')
        g[v][u] = min(g[v][u], t);
      if (b[b.length() - 1] == '>')
        g[u][v] = min(g[u][v], t);
    }
    Dijkstra(start, dis1);
    for (int i = 1; i <= n; i++)
      for (int j = i + 1; j <= n; j++)
        swap(g[i][j], g[j][i]);

    Dijkstra(start, dis2);
    int ans = 0;
    for (int i = 0; i < carnum; i++) {
      int v = d[i];
      ans += (dis1[v] + dis2[v]) * car[v];
    }
    printf("%d. %d\n", cot++, ans);
  }
}