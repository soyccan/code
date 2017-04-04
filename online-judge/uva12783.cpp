// uva12783
// bridge
#include <bits/stdc++.h>
#define int long long
#define MS(s,v) memset(s,v,sizeof(s))
#define FOR(i,st,en) for (int i=st; i<=en; ++i)
#define RFOR(i,st,en) for (int i=st; i>=en; --i)
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;
int low[100500];
int dep[100500];
vector<int> G[100500];
vector<pair<int,int>> brg;
void dfs(int x,int p,int d) {
    low[x]=dep[x]=d;
    for (int y : G[x]) {
        if (dep[y]==-1) {
            dfs(y,x,d+1);
            low[x]=min(low[x],low[y]);
            if ((p==-1 && low[y]!=dep[x]) // root
                || low[y]>dep[x]) brg.push_back({min(x,y),max(x,y)});
        } else if (y!=p) {
            low[x]=min(low[x],dep[y]);
        }
    }
}
main() {
#ifndef XD
    ios::sync_with_stdio(0);
    cin.tie(0);
#endif
    int n,m,a,b;
    while (cin>>n>>m && n && m) {
        FOR(i,0,n-1) G[i].clear();
        brg.clear();
        MS(dep,-1); MS(low,-1);
        while (m--) {
            cin>>a>>b;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        dfs(1,-1,0);
        sort(brg.begin(), brg.end());
        cout<<brg.size();
        FOR(i,0,(int)brg.size()-1)
            cout<<' '<<brg[i].first<<' '<<brg[i].second;
        cout<<'\n';
    }
    return 0;
}
