// uva 820
// max flow
#include <bits/stdc++.h>
#define int long long
#define MS(s,v) memset(s,v,sizeof(s))
#define FOR(i,st,en) for (int i=st; i<=en; i++)
using namespace std;
int cap[105][105];
int nk[105];
int pa[105];
int bfs(int s,int t,int n) {
    queue<int> q;
    q.push(s);
    MS(nk,0);
    nk[s]=1e9;
    while (q.size()) {
        int x=q.front(); q.pop();
        FOR(y,1,n) {
            if (!nk[y] && cap[x][y]>0) {
                nk[y]=min(nk[x],cap[x][y]);
                pa[y]=x;
                q.push(y);
            }
        }
        if (nk[t]) break;
    }
    if (!nk[t]) return 0;
    for (int x=t; x!=s; x=pa[x])
        cap[pa[x]][x]-=nk[t], cap[x][pa[x]]+=nk[t];
    return nk[t];
}
main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t,n,m,a,b,w,s,tc=0;
    while (cin>>n && n) {
        cin>>s>>t>>m;
        MS(cap,0);
        while (m--) {
            cin>>a>>b>>w;
            cap[a][b]+=w;
            cap[b][a]+=w;
        }
        int ans=0;
        for (;;) {
            int flow=bfs(s,t,n);
            if (!flow) break;
            ans+=flow;
        }
        cout<<"Network "<<++tc<<"\nThe bandwidth is "<<ans<<".\n\n";
    }
    return 0;
}
