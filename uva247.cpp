#include <bits/stdc++.h>
#define int long long
#define MS(a,v) memset(a,v,sizeof a)
#define FOR(i,l,r) for (int i=l; i<=r; i++)
#define RFOR(i,l,r) for (int i=l; i>=r; i--)
using namespace std;
map<string,int> id;
main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("in.txt","r",stdin);
    int n,m;
    while (cin>>n>>m && n && m) {
        id.clear();
        MS(G,0);
        FOR(i,0,n) G[i][i]=1;
        while (m--) {
            string a,b;
            cin>>a>>b;
            if (!id.count(a)) id.insert({a,id.size()});
            if (!id.count(b)) id.insert({b,id.size()});
            G[id[a]][id[b]]=G[id[b]][id[a]]=1;
        }
        FOR(k,0,n-1)
            FOR(i,0,n-1)
                FOR(j,0,n-1)
                    G[i][j]|=G[i][k]&G[k][j];
    }
    return 0;
}