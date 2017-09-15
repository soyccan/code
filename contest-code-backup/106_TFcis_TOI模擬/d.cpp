#include <bits/stdc++.h>
// #define int long long
#define MS(s,v) memset(s,v,sizeof(s))
#define _FOR(i,start,end,step) for (int i=start; i!=end; i+=step)
#define FOR(i,start,end) for (int i=start; i<end; ++i)
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;
const long long MOD = 1e9+9;
struct Frac {
    int x,y;
    Frac(int x=1,int y=1): x(x), y(y) {}
    Frac operator*(const Frac& f) { return Frac(x*f.x, y*f.y).sim(); }
    bool operator<(const Frac& f) const { return x*f.y < f.x*y; }
    Frac& sim() {
        int g = __gcd(x,y);
        if (g) x/=g, y/=g;
        return *this;
    }
} A[505][505], dp[505][505][105];
ostream& operator<<(ostream& os, const Frac& f) {
    os << f.x << '/' << f.y;
    return os;
}
main() {
#ifndef soytw
    ios::sync_with_stdio(0);
    cin.tie(0);
#endif
    int n,K;
    while (cin>>n) {
        FOR(i,1,n+1) FOR(j,1,n+1) FOR(k,1,K+1) dp[i][j][k]=Frac();
        FOR(i,1,n+1) FOR(j,1,n+1) cin>>A[i][j].x>>A[i][j].y;
        cin>>K;
        FOR(i,1,n+1) FOR(j,1,n+1) dp[i][j][1]=A[i][j];
        FOR(k,2,K+1)
            FOR(i,1,n+1)
                FOR(j,1,n+1) {
                    Frac a=dp[i][j-1][k-1]*A[i][j];
                    Frac b=dp[i-1][j][k-1]*A[i][j];
                    if (i>1 && j>1)
                        dp[i][j][k]=max(a,b);
                    else if (i>1)
                        dp[i][j][k]=b;
                    else if (j>1)
                        dp[i][j][k]=a;
                    else {
                        //
                    }
                }
        FOR(i,1,n+1) {
            // FOR(j,1,n+1) cout<<dp[i][j][K]<<' '; cout<<endl;
        }
        Frac ans = dp[n][n][K];
        cout<<ans.x%MOD<<' '<<ans.y%MOD<<'\n';
    }
    return 0;
}
