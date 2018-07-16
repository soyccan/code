#include <bits/stdc++.h>
#define int long long
#define MS(s,v) memset(s,v,sizeof(s))
#define FOR(i,end) for (int i=0; i<end; ++i)
#define FOR1(i,end) for (int i=1; i<=end; ++i)
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;

struct Edge
{
    int to,w;
};
vector<Edge> G[100005];
int dis[1000005];

void dfs(int x, int p) {
    for (Edge e : G[x]) {
        int y = e.to;
        if (y == p) continue;
        dis[y] = dis[x] + e.w;
        dfs(y, x);
    }
}

main() {
#ifdef soytw
    freopen("in.txt","r",stdin);
#else
    ios::sync_with_stdio(0);
    cin.tie(0);
#endif
    int n,m,a,b,w;
    cin>>n>>m;
    while (m--) {
        cin>>a>>b>>w;
        G[a].push_back({b,w});
        G[b].push_back({a,w});
    }
    dis[0] = 0;
    dfs(0, -1);

    int rt = -1, mx = -1;
    for (int i=0; i<n; i++) 
        if (dis[i] > mx)
            mx = dis[i], rt = i;

    dis[rt] = 0;
    dfs(rt, -1);
    cout<< *max_element(dis, dis+n) <<endl;
#ifdef soytw
    freopen("con","r",stdin);
    system("pause");
#endif
    return 0;
}