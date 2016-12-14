#include <bits/stdc++.h>
#define int long long
#define MS(a,v) memset(a,v,sizeof a)
#define FOR(i,l,r) for (int i=l; i<=r; ++i)
#define RFOR(i,l,r) for (int i=l; i>=r; --i)
using namespace std;
int low[1000];
int pre[1000];
bool iscut[1000];
int dfn;
vector<int> G[1000];
void dfs(int x,int p) {
    cout<<'x'<<x<<endl;
    low[x]=pre[x]=++dfn;
    int chd=0;
    for (int y:G[x]) {
        if (!pre[y]) {
            dfs(y,x);
            low[x]=min(low[x],low[y]);
            if (low[y] >= pre[x])
                iscut[x]=1;
            chd++;
        } else if (y!=p && pre[y]<pre[x]) {
            low[x]=min(low[x],pre[y]);
        }
    }
    if (p==-1 && chd==1) iscut[x]=0;
}
main() {
    freopen("in.txt","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,x,y;
    while (cin>>n && n) {
        FOR(i,1,n) G[i].clear();
        string ln;
        while (getline(cin,ln) && ln!="0") {
            stringstream ss(ln);
            ss>>x;
            while (ss>>y) {
                G[x].push_back(y);
                G[y].push_back(x);
            }
        }
        dfn=0;
        MS(pre,0x3f); MS(low,0x3f); MS(iscut,0);
        dfs(1,-1);
        int ans=0;
        FOR(i,1,n) if (iscut[i]) ans++;
        cout<<ans<<'\n';
    }
    return 0;
}
