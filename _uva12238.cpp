#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

struct E {
    int t,w;
};

vector<E> G[100005];
vector<E> Q[100005];
int pa[100005];
int dis[100005];
int lca[100005];
bool used[100005];
int n,q,a,b,w;

int find(int x) {
    if (x != pa[x])
        pa[x] = find(pa[x]);
    return pa[x];
}

void dfs(int x) {
    if (used[x]) return;
    used[x] = true;
    pa[x] = x;
    for (E e : G[x]) {
        dfs(e.t);
        pa[e.t] = x;
        if (dis[e.t] == -1)
            dis[e.t] = dis[x] + e.w;
    }
    for (E e : Q[x])
        if (used[e.t])
            lca[e.w] = find(e.t);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (cin>>n && n) {
        for (int i=1; i<n; i++) {
            cin>>b>>w;
            G[i].push_back({b,w});
            G[b].push_back({i,w});
        }
        cin>>q;
        for (int i=0; i<q; i++) {
            cin>>a>>b;
            Q[a].push_back({b,i});
        }
        memset(used, 0, sizeof used);
        memset(dis, -1, sizeof dis);
        dfs(0);
        for (int i=0; i<q; i++) {
            cout << dis[a]+dis[b]-2*dis[lca[i]] << '\n';
        }
    }
    return 0;
}
