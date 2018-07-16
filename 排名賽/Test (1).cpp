// without cycle
#include <bits/stdc++.h>
#define int long long
#define MS(s,v) memset(s,v,sizeof(s))
#define FOR(i,end) for (int i=0; i<end; ++i)
#define FOR1(i,end) for (int i=1; i<=end; ++i)
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;

const size_t MAXN = 1000010;
int ef[MAXN]; // efficiency
set<int> DAG[MAXN], rDAG[MAXN];
int id[MAXN]; // in degree
int dp[MAXN]; // max gain if end at this point
int N;

inline void init() {
    MS(id, 0);
    MS(dp, -1);
}


main() {
#ifdef soytw
    // freopen("in.txt","r",stdin);
#else
    ios::sync_with_stdio(0);
    cin.tie(0);
#endif

    init();
    int m, a, b;
    cin >> N >> m;
    FOR(i, N) cin >> ef[i];
    while (m--) {
        cin >> a >> b;
        if (a == b) continue;
        DAG[a].insert(b);
        rDAG[b].insert(a);
        id[b] = rDAG[b].size();
    }

    queue<int> q;
    FOR(i, N)
        if (id[i] == 0)
            q.push(i);
    while (q.size()) {
        int x = q.front(); q.pop();
        dp[x] = ef[x];
        for (int w : rDAG[x])
            dp[x] = max(dp[x], dp[w] + ef[x]);
        for (int y : DAG[x]) {
            id[y]--;
            // cout<<y<<"id"<<id[y]<<endl;
            if (id[y] == 0) q.push(y);
        }
    }

#ifdef soytw
    FOR(i, N)
        cout<<i<<' '<<dp[i]<<endl;
#endif

    int ans = *max_element(dp, dp+N);
    assert(ans != -1);
    cout << ans << '\n';


#ifdef soytw
    freopen("con","r",stdin);
    system("pause");
#endif
    return 0;
}
