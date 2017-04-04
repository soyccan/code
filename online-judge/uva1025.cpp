// uva 1025
// dp
#include <bits/stdc++.h>
#define int long long
#define MS(a,v) memset(a,v,sizeof a)
#define FOR(i,l,r) for (int i=l; i<=r; ++i)
#define RFOR(i,l,r) for (int i=l; i>=r; --i)
using namespace std;
const int INF = 0x3f3f3f3f3f3f3f3fLL;
int run[55];
int dp[1000][55]; // remain time(time,station)
bool train[1000][55][2]; // (time,station,0L/1R)
void debug(int T,int n) {
    FOR(i,0,T) {
        FOR(j,0,n)
            if (dp[i][j]>=INF) cout<<"INF ";
            else cout<<dp[i][j]<<' ';
        cout<<endl;
    }
    cout<<endl;
}
main() {
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T,n,m1,m2,x,tc=0;
    while (cin>>n && n) {
        cin>>T;
        FOR(i,1,n-1) cin>>run[i];
        cin>>m1;
        MS(train,0);
        while (m1--) {
            cin>>x;
            for (int j=x,k=1; j<=T&&k<=n; j+=run[k],k++)
                train[j][k][1]=1;
        }
        cin>>m2;
        while (m2--) {
            cin>>x;
            for (int j=x,k=n; j<=T&&k>=1; j+=run[k-1],k--)
                train[j][k][0]=1;
        }
        MS(dp,0x7f);
        dp[T][n]=0;
        RFOR(i,T-1,0) {
            FOR(j,1,n) {
                dp[i][j]=dp[i+1][j]+1;
                if (train[i][j][1] && i+run[j]<=T && j+1<=n)
                    dp[i][j]=min(dp[i][j], dp[i+run[j]][j+1]);
                if (train[i][j][0] && i+run[j-1]<=T && j-1>=1)
                    dp[i][j]=min(dp[i][j], dp[i+run[j-1]][j-1]);
            }
        }
//        debug(T,n);
        cout<<"Case Number "<<++tc<<": ";
        if (dp[0][1]>=INF) cout<<"impossible\n";
        else cout<<dp[0][1]<<'\n';
    }
    return 0;
}
