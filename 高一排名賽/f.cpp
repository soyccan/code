#include <bits/stdc++.h>
using namespace std;

int dis[4000][4000];

int main() {
	int n, m, q;
	scanf("%d%d", &n, &m);

	memset(dis, -1, sizeof dis);
	for (int i=0; i<n; i++)
		dis[i][i] = 0;

	while (m--) {
		int a, b, w;
		scanf("%d%d%d", &a, &b, &w);
		dis[a][b] = dis[b][a] = w;
	}

	for (int k=0; k<n; k++)
		for (int i=0; i<n; i++)
			for (int j=0; j<n; j++)
				dis[i][j] = max(dis[i][j], min(dis[i][k], dis[k][j]));

	scanf("%d", &q);
	while (q--) {
		int s, t;
		scanf("%d%d", &s, &t);
		printf("%d\n", dis[s][t]);
	}

	return 0;
}
