// brute force, TLE
#include <bits/stdc++.h>
#define int long long
#define MS(s,v) memset(s,v,sizeof(s))
#define FOR(i,end) for (int i=0; i<end; ++i)
#define FOR1(i,end) for (int i=1; i<=end; ++i)
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;

const size_t MAXN = 1000010;
int ef[MAXN]; // efficiency
set<int> G[MAXN];
bool vis[MAXN];
int N, ans;

inline void dfs(int x, int dis) {
    for (int y : G[x])
        dfs(y, dis+ef[y]);
    if (G[x].empty())
        ans = max(ans, dis);
}


main() {
#ifdef soytw
    // freopen("in.txt","r",stdin);
#else
    ios::sync_with_stdio(0);
    cin.tie(0);
#endif

    int m, a, b;
    cin >> N >> m;
    FOR(i, N) cin >> ef[i];
    while (m--) {
        cin >> a >> b;
        if (a == b) continue;
        G[a].insert(b);
    }

    ans = -1;
    FOR(i, N) {
        dfs(i, ef[i]);
    }
    cout << ans << '\n';


#ifdef soytw
    freopen("con","r",stdin);
    system("pause");
#endif
    return 0;
}
