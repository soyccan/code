#include <bits/stdc++.h>
using namespace std;
struct Edge {
    int a,b;
};
set<int> G[1005];
bool used[1005];
bool eused[1005][1005];
int pa[1005];
vector<Edge> E;
int N;
inline bool cross(Edge x, Edge y) {
    if ((x.a>=y.a && x.b<=y.b) ||
        (x.a>=y.b && x.b<=y.a+N)) return false;
    else return true;
}
inline bool ok(int a, int b) {
    Edge e;
    e.a=a; e.b=b;
    for (int i=0; i<E.size(); i++)
        if (eused[E[i].a][E[i].b] && cross(e,E[i]))
            return false;
    return true;
}
inline bool dfs(int x) {
    cout<<" x:"<<x<<endl;
    for (int y : G[x]) {
        cout<<"    Y:"<<y<<" "<<used[y]<<endl;
        if (!used[y] && ok(x,y)) {
            used[y]=true;
            eused[x][y]=eused[y][x]=true;
            if (dfs(y)) {
                pa[y]=x;
                return true;
            }
        }
    }
    for (int i=1; i<=N; i++)
        if (!used[i]) return false;
    return true;
}
int main() {
    int m,a,b;
    cin>>N>>m;
    while (m--) {
        cin>>a>>b;
        if (a > b) swap(a,b);
        G[a].insert(b);
        G[b].insert(a);
        E.push_back({a,b});
    }
    for (int i=1; i<=N; i++) {
        cout <<"i:"<<i<<endl;
        memset(used,0,sizeof used);
        memset(eused,0,sizeof eused);
        if (dfs(i)) {
            cout<<i<<endl;
        }
    }
    return 0;
}
