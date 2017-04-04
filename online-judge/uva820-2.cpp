// uva820
// max flow (dinic)
#include <bits/stdc++.h>
#define int long long
#define MS(a,v) memset(a,v,sizeof a)
#define FOR(i,l,r) for (int i=l; i<=r; ++i)
#define RFOR(i,l,r) for (int i=l; i>=r; --i)
using namespace std;
const int INF = 0x3f3f3f3f3f3f3f3fLL;
int S,T,N;
int dep[105];
int iter[105];
int cap[105][105];
int bfs() {
    queue<int> q; q.push(S);
    MS(dep,-1); dep[S]=0;
    while (q.size()) {
        int x=q.front(); q.pop();
        FOR(y,1,N) {
            if (cap[x][y]>0 && dep[y]==-1) {
                dep[y]=dep[x]+1;
                q.push(y);
            }
        }
    }
    return dep[T];
}
int dfs(int x,int nk) {
    if (x==T) return nk;
    for (int& y=iter[x]; y<=N; y++) {
        if (cap[x][y]>0 && dep[x]+1==dep[y]) {
            int f=dfs(y,min(nk,cap[x][y]));
            cap[x][y]-=f, cap[y][x]+=f;
            if (f) return f;
        }
    }
    return 0;
}
main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tc=0,m,a,b,w;
    while (cin>>N&&N) {
        cin>>S>>T>>m;
        MS(cap,0);
        while (m--) {
            cin>>a>>b>>w;
            cap[a][b]+=w;
            cap[b][a]+=w;
        }
        int ans=0,f;
        while (bfs()!=-1) {
            do {
                MS(iter,0);
                f=dfs(S,INF);
                ans+=f;
            } while (f);
        }
        cout<<"Network "<<++tc<<"\nThe bandwidth is ";
        cout<<ans<<".\n\n";
    }
    return 0;
}
