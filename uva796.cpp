// uva796
// bridge
#include <bits/stdc++.h>
#define int long long
#define MS(s,v) memset(s,v,sizeof(s))
#define _FOR(i,start,end,step) for (int i=start; i!=end; i+=step)
#define FOR(i,start,end) for (size_t i=start; i<end; ++i)
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;
int dep[10000005];
int low[10000005];
vector<int> G[10000005];
vector<pair<int,int>> brg;
void dfs(int x,int p,int d,int n) {
    dep[x]=low[x]=d;
    for (int y:G[x]) {
        if (y==p) continue;
        if (dep[y]==-1) {
            dfs(y,x,d+1,n);
            low[x]=min(low[x],low[y]);
            if (low[y]>dep[x]) brg.push_back({min(x,y), max(x,y)});
        } else {
            low[x]=min(low[x],dep[y]);
        }
    }
}
main() {
#ifndef XD
    ios::sync_with_stdio(0);
    cin.tie(0);
#endif
    int n,a,b,m; string ms;
    while (cin>>n) {
        if (n==0) {
            cout<<"0 critical links\n\n";
            continue;
        }
        FOR(i,0,n) G[i].clear();
        FOR(i,0,n) {
            cin>>a>>ms;
            ms.erase(0,1);
            ms.pop_back();
            m=stoi(ms);
            while (m--) {
                cin>>b;
                G[a].push_back(b);
                G[b].push_back(a);
            }
        }
        brg.clear();
        MS(dep,-1);
        FOR(i,0,n) if (dep[i]==-1) dfs(i,-1,0,n);
        sort(brg.begin(), brg.end());
        cout<<brg.size()<<" critical links\n";
        FOR(i,0,brg.size())
            cout<<brg[i].first<<" - "<<brg[i].second<<"\n";
        cout<<'\n';
    }
    return 0;
}
