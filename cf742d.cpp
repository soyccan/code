#include <bits/stdc++.h>
#define int long long
#define MS(s,v) memset(s,v,sizeof(s))
#define FOR(i,st,en) for (int i=st; i<=en; i++)
using namespace std;
int dp[1005][1005];
int v[1005],w[1005],pa[1005];
vector<int> grp[1005];
int find(int x) {
    if (pa[x]!=x) pa[x]=find(pa[x]);
    return pa[x];
}
void debug(int n,int m) {
    FOR(i,0,n) {
        FOR(j,0,m)
            cout<<dp[i][j]<<' ';
        cout<<endl;
    }
}
main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("in.txt","r",stdin);
    int n,m,W,a,b;
    cin>>n>>m>>W;
    FOR(i,1,n) cin>>w[i];
    FOR(i,1,n) cin>>v[i];
    FOR(i,1,n) pa[i]=i;
    while (m--) {
        cin>>a>>b;
        pa[find(a)]=find(b);
    }
    FOR(i,1,n) {
        grp[pa[i]].push_back(i);
        // g++;
    }
    MS(dp,0);
    int i,g=0;
    while (g<=n && grp[g].empty()) g++;
    for (i=1; g<=n; i++) {
        FOR(j,0,W) {
            int sw=0,sv=0;
            for (int k:grp[g]) {
                cout<<"i:"<<i<<" g:"<<g<<" j:"<<j<<" K:"<<k<<endl;
                if (j<w[k]) dp[i][j]=dp[i-1][j];
                else dp[i][j]=max(dp[i-1][j]+v[k],dp[i-1][j-w[k]]+v[k]);
                sw+=w[k], sv+=v[k];
            }
            if (j>=sw)
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-sw]+sv);
        }
        g++;
        while (g<=n && grp[g].empty()) g++;
    }
    debug(i,W);
    cout<<*max_element(&dp[i-1][0],&dp[i-1][W]+1)<<'\n';
    return 0;
}
