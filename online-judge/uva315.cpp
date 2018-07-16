// uva315
// cut vertex
#include <bits/stdc++.h>
#define int long long
#define MS(s,v) memset(s,v,sizeof(s))
#define FOR(i,st,en) for (int i=st; i<=en; ++i)
#define RFOR(i,st,en) for (int i=st; i>=en; --i)
using namespace std;
const int N = 200;
int vis[N],low[N],cnt;
bool cut[N];
vector<int> G[N];
void dfs(int x,int p) {
    vis[x]=low[x]=++cnt;
    cut[x]=0;
    int chd=0;
    for (int y:G[x]) {
        if (!vis[y]) {
            dfs(y,x);
            low[x]=min(low[x],low[y]);
            if (low[y]>=vis[x]) cut[x]=1;
            ++chd;
        } else if (y!=p) {
            low[x]=min(low[x],vis[y]);
        }
    }
    if (p==-1) cut[x]=(chd>1);
}
main() {
#ifndef XD
    ios::sync_with_stdio(0);
    cin.tie(0);
#endif
    int n,x,y; string ln;
    while (cin>>n && n) {
        FOR(i,1,n) G[i].clear();
        while (getline(cin,ln) && ln!="0") {
            stringstream ss(ln);
            ss>>x;
            while (ss>>y) {
                G[x].push_back(y);
                G[y].push_back(x);
            }
            cnt=0;
            MS(vis,0);
            dfs(1,-1);
        }
        cout<<count(cut+1,cut+n+1,1)<<'\n';
    }
    return 0;
}
