#include <iostream>
#include <string.h>

using namespace std;

#define MAX 51
int res, a, b, d, n, k, i, m[MAX][MAX], used[MAX];


void dfs(int v, int depth)
{
	if (depth > d) return;

	if (v == b)
	{
		res++;
		return;
	}
	used[v] = 1;

	for (int i = 1; i <= n; i++)
		if (m[v][i] && !used[i]) dfs(i, depth + 1);

	used[v] = 0;
}

int main() {
	scanf("%d %d %d %d %d", &n, &k, &a, &b, &d);
	memset(m, 0, sizeof m);
	memset(used, 0, sizeof used);
	for (res = i = 0; i < k; i++)
	{
		int a1, a2;
		scanf("%d %d", &a1, &a2);
		m[a1][a2] = 1;
	}
	dfs(a, 0);
	printf("%d\n", res);
	return 0;
}
