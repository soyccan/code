// toj389
// undone
// cut vertex
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

int dep[100010];
int low[100010];
int wt[100010];
int dp[100010];
vector<int> G[100010];
int ans;

void dfs(int x, int pa, int d) {
    dep[x] = low[x] = d;
    dp[x] = wt[x];
    for (int y : G[x]) {
        if (dep[y] == -1) {
            dfs(y, x, d+1);
            low[x] = min(low[x], low[y]);
            if (low[y] >= dep[x])
                // cut vertex
                dp[x] += dp[y];
        } else if (y != pa) {
            low[x] = min(low[x], dep[y]);
        }
    }
}

int main() {
#ifdef soytw
    // freopen("in.txt","r",stdin);
#endif
    int n, m;
    while (scanf("%d%d", &n, &m) == 2) {
        for (int i=0; i<n; i++) scanf("%d", wt+i);
        while (m--) {
            int a, b;
            scanf("%d%d", &a, &b);
            G[a].push_back(b);
            G[b].push_back(a);
        }
        memset(dep, -1, sizeof dep);
        // memset(cut, false, sizeof cut);
        dfs(0, -1, 0);

        for (int i=0; i<n; i++) printf("%d ", dp[i]);
        putchar('\n');
    }
#ifdef soytw
    freopen("con","r",stdin);
    system("pause");
#endif
    return 0;
}

/*
4 5
5 11 7 18
0 1
1 2
2 3
3 1
0 4

ans: 4 or 1 ???
*/
