// uva11504
// SCC
#include <bits/stdc++.h>
#define int long long
#define MS(s,v) memset(s,v,sizeof(s))
#define _FOR(i,start,end,step) for (int i=start; i!=end; i+=step)
#define FOR(i,start,end) for (int i=start; i<end; ++i)
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;
int dfn[100005];
int low[100005];
int scc[100005];
int indeg[100005];
bool instk[100005];
vector<int> G[100005];
int dfc,sccc;
stack<int> stk;
void dfs(int x) {
    dfn[x]=low[x]=++dfc;
    instk[x]=1;
    stk.push(x);
    for (int y : G[x]) {
        if (!dfn[y]) {
            dfs(y);
            low[x]=min(low[x], low[y]);
        } else if (instk[y]) {
            low[x]=min(low[x], dfn[y]);
        }
    }
    if (dfn[x]==low[x]) {
        int k;
        do {
            k = stk.top(); stk.pop();
            instk[k]=0;
            scc[k]=sccc;
        } while (k!=x);
        ++sccc;
    }
}
main() {
#ifdef soytw
    freopen("in.txt","r",stdin);
#else
    ios::sync_with_stdio(0);
    cin.tie(0);
#endif
    int n,t,m,a,b;
    cin>>t;
    while (cin>>n>>m) {
        FOR(i,1,n+1) G[i].clear();
        while (stk.size()) stk.pop();
        MS(instk,0);
        MS(scc,-1);
        MS(dfn,0);
        dfc=sccc=0;
        MS(indeg,0);

        while (m--) {
            cin>>a>>b;
            G[a].push_back(b);
        }
        FOR(i,1,n+1) if (!dfn[i]) dfs(i);
        FOR(i,1,n+1)
            for (int j : G[i])
                if (scc[i]!=scc[j])
                    indeg[scc[j]]++;
        cout<<count(indeg, indeg+sccc, 0)<<'\n';
    }
#ifdef soytw
    freopen("con","r",stdin);
    system("pause");
#endif
    return 0;
}
