// directed, correct solution
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
set<int> DAG[MAXN], rDAG[MAXN];
int dfn[MAXN]; // DFS number
int low[MAXN]; // furthest ancestor it can reach
int scc[MAXN]; // SCC it belongs to
int dfc, sccc; // DFS/SCC count
bool instk[MAXN]; // whether in stack
stack<int> stk;
int tg[MAXN]; // total gain in an SCC
int id[MAXN]; // SCC in degree
int dp[MAXN]; // max gain if end at this SCC
int N;

inline void dfs(int x) {
    dfn[x] = low[x] = ++dfc;
    instk[x] = 1;
    // cout<<'x'<<x<<endl;
    stk.push(x);
    for (int y : G[x]) {
        if (!dfn[y]) {
            dfs(y);
            low[x] = min(low[x], low[y]);
        } else if (instk[y]) {
            low[x] = min(low[x], dfn[y]);
        }
    }
    // cout<<stk.size()<<endl;
    if (dfn[x] == low[x]) {
        int k;
        do {
            k = stk.top(); stk.pop();
            instk[k] = 0;
            scc[k] = sccc;
            tg[scc[k]] += ef[k];
#ifdef soytw
            cout<<k<<"in"<<scc[k]<<endl;
#endif
        } while (k != x && stk.size());
        ++sccc;
    }
}
inline void init() {
    MS(dfn, 0);
    MS(low, 0);
    MS(scc, -1);
    dfc = sccc = 0;
    MS(instk, 0);
    MS(tg, 0);
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
        G[a].insert(b);
    }

    FOR(i, N) if (!dfn[i]) dfs(i); // build SCC
    FOR(i, N)
        for (int j : G[i])
            if (scc[i] != scc[j]) { //
                DAG[scc[i]].insert(scc[j]); //
                rDAG[scc[j]].insert(scc[i]);
            }
    FOR(i, sccc) id[i] = rDAG[i].size();

    queue<int> q;
    FOR(i, sccc)
        if (id[i] == 0)
            q.push(i);
    while (q.size()) {
        int x = q.front(); q.pop();
        // cout<<'x'<<x<<' '<<id[x]<<endl;
        dp[x] = tg[x];
        for (int w : rDAG[x])
            dp[x] = max(dp[x], dp[w] + tg[x]);
        for (int y : DAG[x]) {
            id[y]--;
            if (id[y] == 0) q.push(y);
        }
    }

#ifdef soytw
    FOR(i, N)
        cout<<i<<' '<<dp[scc[i]]<<endl;
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
