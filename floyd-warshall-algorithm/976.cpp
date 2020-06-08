#include <iostream>

using namespace std;

#define INF 100000000
#define MAX 101

int n, m[MAX][MAX], res[MAX][MAX];

void floyd() {
  int i, j, k;
  for (k = 0; k < n; k++)
    for (i = 0; i < n; i++)
      for (j = 0; j < n; j++)
        if ((m[i][k] < INF) && (m[k][j] < INF)) {
          if (m[i][k] + m[k][j] < m[i][j])
            m[i][j] = m[i][k] + m[k][j];
          if (m[i][j] < -INF)
            m[i][j] = -INF;
        }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      scanf("%d", &m[i][j]);
      if (m[i][j] == 0 && i != j)
        m[i][j] = INF;
    }

  floyd();

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (m[i][j] == INF)
        res[i][j] = 0;
      else {
        res[i][j] = 1;
        for (int k = 0; k < n; k++)
          if (m[k][k] < 0 && m[i][k] < INF && m[k][j] < INF)
            res[i][k] = res[i][j] = res[k][j] = 2;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    printf("%d", res[i][0]);
    for (int j = 1; j < n; j++)
      printf(" %d", res[i][j]);
    printf("\n");
  }
  return 0;
}