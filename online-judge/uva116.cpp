// uva116
// DP TSP
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
int arr[15][105];
int dp[15][105];
int N,M;
const int INF = 1e12;
int solve() {
    for (int i=1; i<=N; ++i)
        for (int j=1; j<=M; ++j)
            dp[i][j]=INF;
    for (int i=1; i<=N; ++i)
        dp[i][M]=arr[i][M];
    for (int j=M-1; j>=1; --j)
        for (int i=1; i<=N; ++i) {
            int a=i-1, b=i, c=i+1;
            if (a==0) a=N;
            if (c==N+1) c=1;
            dp[i][j]=min(dp[i][j],dp[a][j+1]+arr[i][j]);
            dp[i][j]=min(dp[i][j],dp[b][j+1]+arr[i][j]);
            dp[i][j]=min(dp[i][j],dp[c][j+1]+arr[i][j]);
        }
    int Min=INF;
    int en;
    for (int i=N; i>=1; --i) {
        if (Min >= dp[i][1]) {
            Min=dp[i][1];
            en=i;
        }
    }
    return en;
}
void output(int x,int y) {
    if (y>M) return;
    cout<<x;
    if (y!=M) cout<<' ';
    int a=x-1, b=x, c=x+1;
    if (a==0) a=N;
    if (c==N+1) c=1;
    vector<int> v {a,b,c};
    sort(v.begin(), v.end());
    for (int nxt : v)
        if (dp[nxt][y+1]+arr[x][y]==dp[x][y]) {
            output(nxt,y+1);
            break;
        }
}
main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (cin>>N>>M) {
        for (int i=1; i<=N; ++i)
            for (int j=1; j<=M; ++j)
                cin>>arr[i][j];
        int en=solve();
        output(en,1);
        cout<<endl<<dp[en][1]<<endl;
    }
    return 0;
}
