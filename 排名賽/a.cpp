// directed, brute force
#include <bits/stdc++.h>
#define int long long
#define MS(s,v) memset(s,v,sizeof(s))
#define FOR(i,end) for (int i=0; i<end; ++i)
#define FOR1(i,end) for (int i=1; i<=end; ++i)
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;

const size_t MAXN = 1000010;
bool in[MAXN], out[MAXN];
int ef[MAXN]; // efficiency
vector<int> G[MAXN];
bool vis[MAXN];

inline int dfs(int x) {
    vis[x] = 1;
    int res = ef[x];
    for (int y : G[x])
        if (!vis[y])
            res += dfs(y);
    return res;
}

main() {
#ifdef soytw
    freopen("in.txt","r",stdin);
#else
    ios::sync_with_stdio(0);
    cin.tie(0);
#endif

    int n, m, a, b;
    cin >> n >> m;
    FOR(i, n) cin >> ef[i];
    while (m--) {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    int ans = -1;
    FOR(i, n) {
        MS(vis, 0);
        int t = dfs(i);
        ans = max(ans, t);
    }
    cout << ans << '\n';


#ifdef soytw
    freopen("con","r",stdin);
    system("pause");
#endif
    return 0;
}
