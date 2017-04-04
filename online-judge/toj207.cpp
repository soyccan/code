// toj207
// second mst + lca
#include <bits/stdc++.h>
#define int long long
#define MS(a,v) memset(a,v,sizeof a)
#define FOR(i,l,r) for (int i=l; i<=r; i++)
using namespace std;
struct Edge {
    int f,t,w;
    bool operator<(Edge e) const { return w<e.w; }
};
vector<Edge> ed;
vector<Edge> G[20005];
bool mst[130005];
int fa[20005];
int dep[20005];
int pa[25][20005];
int neck[25][20005];
void dfs(int x,int p,int d) {
    pa[0][x]=p;
    dep[x]=d;
    for (Edge e:G[x])
        if (e.t!=p) dfs(e.t,x,d+1);
        else neck[0][x]=e.w;
}
void buildlca(int x,int n) {
    MS(pa,-1), MS(neck,-1);
    dfs(x,-1,0);
    FOR(i,0,20)
        FOR(j,0,n-1)
            if (pa[i][j]!=-1) {
                pa[i+1][j]=pa[i][pa[i][j]];
                neck[i+1][j]=max(neck[i][j],neck[i][pa[i][j]]);
            }
}
int getneck(int x,int y) {
    if (dep[x]<dep[y]) swap(x,y);
    int r=-1;
    FOR(i,0,20)
        if ((dep[x]-dep[y])>>i & 1) {
            r=max(r,neck[i][x]);
            x=pa[i][x];
        }
    if (x==y) return r;
    for (int i=20; i>=0; i--)
        if (pa[i][x]!=pa[i][y]) {
            r=max({r,neck[i][x],neck[i][y]});
            x=pa[i][x];
            y=pa[i][y];
        }
    r=max({r,neck[0][x],neck[0][y]});
    return r;
}
int find(int x) {
    if (x!=fa[x]) fa[x]=find(fa[x]);
    return fa[x];
}
int kruskal(int n) {
    FOR(i,0,n) fa[i]=i;
    int r=0;
    MS(mst,0);
    FOR(i,0,(int)ed.size()-1) {
        Edge e=ed[i];
        if (find(e.f)!=find(e.t)) {
            fa[find(e.f)]=find(e.t);
            mst[i]=1;
            r+=e.w;
        }
    }
    return r;
}
main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t,n,m,a,b,w;
    cin>>t;
    while (t--) {
        cin>>n>>m;
        ed.clear();
        FOR(i,0,n) G[i].clear();
        while (m--) {
            cin>>a>>b>>w;
            if (a==b) continue;
            ed.push_back({a,b,w});
        }
        sort(ed.begin(), ed.end());
        int minw=kruskal(n),sndw=1e18;
        FOR(i,0,(int)ed.size()-1) {
            if (mst[i]) {
                Edge e=ed[i];
                G[e.f].push_back({-1,e.t,e.w});
                G[e.t].push_back({-1,e.f,e.w});
            }
        }
        buildlca(0,n);
        FOR(i,0,(int)ed.size()-1) {
            if (!mst[i]) {
                Edge e=ed[i];
                int nk=getneck(e.f,e.t);
                int w=minw+e.w-nk;
                if (w<sndw && w!=minw) sndw=w;
            }
        }
        cout<<sndw-minw<<'\n';
    }
    return 0;
}
