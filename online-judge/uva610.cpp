// uva610
// bridge
#include <bits/stdc++.h>
#define int long long
#define MS(s,v) memset(s,v,sizeof(s))
#define FOR(i,st,en) for (int i=st; i<=en; ++i)
#define RFOR(i,st,en) for (int i=st; i>=en; --i)
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;
int low[1005];
int dep[1005];
bool G[1005][1005];
void dfs(int x,int p,int d) {
    low[x]=dep[x]=d;
    FOR(y,1,1000) {
        if (G[x][y] && y!=p) {
            if (dep[y]==-1) {
                dfs(y,x,d+1);
                low[x]=min(low[x],low[y]);
                if (low[y]>dep[x]
                    || (p==-1 && low[y]!=dep[x])) { // root
                    // bridge
                    cout<<x<<' '<<y<<'\n';
                    cout<<y<<' '<<x<<'\n';
                } else {
                    cout<<x<<' '<<y<<'\n';
                }
            } else {
                if (dep[x]>dep[y])
                    cout<<x<<' '<<y<<'\n';
                low[x]=min(low[x],dep[y]);
            }
        }
    }
}
main() {
#ifndef XD
    ios::sync_with_stdio(0);
    cin.tie(0);
#endif
    int n,m,a,b,tc=0;
    while (cin>>n>>m && n && m) {
        cout<<++tc<<"\n\n";
        MS(G,0);
        while (m--) {
            cin>>a>>b;
            G[a][b]=G[b][a]=1;
        }
        MS(dep,-1); MS(low,-1);
        dfs(1,-1,0);
        cout<<"#\n";
    }
    return 0;
}
