#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
struct Edge {
    int to, w;
    bool operator<(Edge e) const {
        return w < e.w;
    }
};
int N;
vector<Edge> G[50005];
int dep[50005]={0};
int pa[50005][20]={0};
inline void dfs(int x) {
    for (Edge e : G[x]) {
        if (e.to != pa[x][0]) {
            dep[e.to] = dep[x]+1;
            pa[e.to][0] = x;
            for (int i=1; i<20; i++) {
                pa[e.to][i] = pa[pa[e.to][i-1]][i-1];
            }
            dfs(e.to);
        }
    }
}
inline int lca(int x, int y) {
    if (dep[x] > dep[y]) swap(x, y);
    
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int v,w;
    cin>>N;
    for (int i=2; i<=N; i++) {
        cin>>v>>w;
        G[i].push_back({v,w});
        G[v].push_back({i,w});
    }
    // int ans = 0;
    // for (int i=1; i<=N; i++)
    //     ans ^= dfs(i, i);
    // cout<<ans<<endl;
    return 0;
}
