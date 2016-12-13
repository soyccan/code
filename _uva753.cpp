#include <bits/stdc++.h>
#define int long long
#define MS(a,v) memset(a,v,sizeof a)
#define FOR(i,l,r) for (int i=l; i<=r; ++i)
#define RFOR(i,l,r) for (int i=l; i>=r; --i)
using namespace std;
const int INF = 0x3f3f3f3f3f3f3f3fLL;
int S=200,T=201;
int cap[1000][1000],pa[1000],nk[1000];
bool vis[1000];
map<string,int> mp;
int id(string s) {
    if (!mp.count(s)) {
        int i=mp.size();
        mp[s]=i;
    }
    return mp[s];
}
int findaug() {
    queue<int> q;
    q.push(S);
    MS(vis,0), vis[S]=1;
    MS(nk,0), nk[S]=INF;
    while (q.size()) {
        int x=q.front(); q.pop();
        FOR(y,0,T) {
            if (!vis[y] && cap[x][y]>0) {
                vis[y]=1;
                pa[y]=x;
                nk[y]=min(nk[x],cap[x][y]);
                q.push(y);
            }
        }
    }
    if (vis[T])
        for (int x=T; x!=S; x=pa[x])
            cap[pa[x]][x]-=nk[T], cap[x][pa[x]]+=nk[T];
    return nk[T];
}
main() {
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t,n,m,k; string s,s1;
    cin>>t;
    while (t--) {
        MS(cap,0);
        mp.clear();
        cin>>n;
        FOR(i,1,n) {
            cin>>s;
            cap[id(s)][T]+=1;
        }
        cin>>m;
        FOR(i,1,m) {
            cin>>s>>s1;
            cap[S][id(s)]+=1;
            cap[id(s)][id(s1)]+=1;
        }
        cin>>k;
        while (k--) {
            cin>>s>>s1;
            cap[id(s)][id(s1)]=INF;
        }
        int f,ans=0;
        while (f=findaug()) ans+=f;
        cout<<m-ans<<'\n';
        if (t!=0) cout<<'\n';
    }
    return 0;
}
