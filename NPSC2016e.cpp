#include <bits/stdc++.h>
#define int long long
#define MS(s,v) memset(s,v,sizeof(s))
#define FOR(i,st,en) for (int i=st; i<=en; i++)
#define RFOR(i,st,en) for (int i=st; i>=en; i--)
using namespace std;
const int INF = 1e9;
int dp[105][105];
inline int DP(int x,int y) {
    // cout<<x<<' '<<y<<' '<<dp[x][y]<<endl;
    if (x>y) swap(x,y);
    if (dp[x][y]!=-1) return dp[x][y];
    if (x==y) return 1;
    dp[x][y]=INF;
    FOR(i,0,x/2)
        dp[x][y]=min(dp[x][y],DP(i,y)+DP(x-i,y));
    FOR(i,0,y/2)
        dp[x][y]=min(dp[x][y],DP(x,i)+DP(x,y-i));
    return dp[x][y];
}
inline void print(int x,int y) {
    cout<<x<<' '<<y<<'\n';
    FOR(i,0,x/2) {
        if (dp[x][y]==dp[i][y]+dp[x-i][y]){
            print(i,y);
            print(x-i,y);
        }
    }
    FOR(i,0,y/2) {
        if (dp[x][y]==dp[x][i]+dp[x][y-i]) {
            print(x,i);
            print(x,y-i);
        }
    }
}
main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n=22,m=6;
    cin>>n>>m;
    MS(dp,-1);
    cout<<DP(n,m)<<'\n';
    print(n,m);
    return 0;
}
