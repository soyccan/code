#include <bits/stdc++.h>
#define int long long
#define MS(a,v) memset(a,v,sizeof a)
#define FOR(i,l,r) for (int i=l; i<=r; i++)
using namespace std;
struct Edge {
    int a,b,w;
    Edge(int a=-1,int b=-1,int w=-1): a(a),b(b),w(w) {}
    bool operator<(Edge e) const { return w<e.w; }
    bool operator==(Edge e) const { return a==e.a && b==e.b && w==e.w; }
};
vector<Edge> ed;
vector<int> G[20005];
bool mst[130005];
int pa[20005];
int mxed[20005][20]; // max edge
const int INF = 1e9;
int find(int x) {
    if (x!=pa[x]) pa[x]=find(pa[x]);
    return pa[x];
}
int dfs(int x,int pa) {
    FOR(i,)
}
// int kruskal(int n,Edge ban=Edge()) {
//     FOR(i,0,n) pa[i]=i;
//     int r=0, g=n;
//     MS(mst,0);
//     for (Edge e:ed) {
//         if (!(e==ban) && find(e.a)!=find(e.b)) {
//             pa[find(e.a)]=find(e.b);
//             g--;
//             if (ban==Edge()) mst.push_back(e);
//             r+=e.w;
//         }
//     }
//     if (g>1) return INF;
//     return r;
// }
main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("in.txt","r",stdin);
    int t,n,m,a,b,w;
    cin>>t;
    while (t--) {
        cin>>n>>m;
        ed.clear();
        while (m--) {
            cin>>a>>b>>w;
            if (a==b) continue;
            ed.push_back({a,b,w});
        }
        sort(ed.begin(), ed.end());
        FOR(i,0,(int)ed.size()-1) {
            if (!mst[i]) {
                Edge e=ed[i];

            }
        }
        // MS(mst,0);
        // int mn=kruskal(n);
        // for(Edge e:mst)cout<<"edge:"<<e.a<<' '<<e.b<<endl;
        // int sd=INF;
        //     int k=kruskal(n,e);
        //     if (k<sd && k!=mn) sd=k;
        // }
        // cout<<sd-mn<<'\n';
    }
    return 0;
}
