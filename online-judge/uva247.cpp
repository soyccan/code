#include <bits/stdc++.h>
#define int long long
#define MS(a,v) memset(a,v,sizeof a)
#define FOR(i,l,r) for (int i=l; i<=r; i++)
#define RFOR(i,l,r) for (int i=l; i>=r; i--)
using namespace std;
map<string,int> id;
map<int,string> name;
int pa[100];
bool G[100][100];
vector<int> grp[100];
int find(int x) {
    if (x!=pa[x]) pa[x]=find(pa[x]);
    return pa[x];
}
main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("in.txt","r",stdin);
    int n,m;
    int k=0;
    while (cin>>n>>m && n && m) {
        id.clear();
        name.clear();
        MS(G,0);
        FOR(i,0,n-1) pa[i]=i, grp[i].clear();
        while (m--) {
            string a,b;
            cin>>a>>b;
            if (!id.count(a)) {
                id.insert({a,id.size()});
                name[id[a]]=a;
            }
            if (!id.count(b)) {
                id.insert({b,id.size()});
                name[id[b]]=b;
            }
            G[id[a]][id[b]]=1;
        }
        FOR(k,0,n-1) FOR(i,0,n-1) FOR(j,0,n-1)
            G[i][j]|=G[i][k]&G[k][j];
        FOR(i,0,n-1) FOR(j,0,n-1)
            if (G[i][j]&&G[j][i])
                pa[find(i)]=find(j);
        FOR(i,0,n-1)
            grp[find(i)].push_back(i);
        if (k!=0) cout<<'\n';
        cout<<"Calling circles for data set "<<++k<<":\n";
        FOR(i,0,n-1) {
            if (grp[i].empty()) continue;
            for (int e:grp[i]) {
                cout<<name[e];
                if (e!=grp[i].back()) cout<<", ";
                else cout<<'\n';
            }
        }
    }
    return 0;
}
