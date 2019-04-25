#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#pragma GCC optimize "Ofast"

#ifdef lioraju_trip
    inline void dbg_(){cout<<'\n';}
    template<typename A, typename... B>
    inline void dbg_(A x, B... y){cout<<x<<' ', dbg_(y...);}
    #define dbg(x,...) cout<<string(x,'#'), dbg_(__VA_ARGS__)
    #define ndbg(x)
#else
    #define dbg(...)
    #define ndbg(x) x
#endif

#define int long long

#define mxsz 1005

int dp[mxsz][205][205];
bool vis[mxsz][205][205];

int v[mxsz][2];

inline int d(int32_t n, int32_t k1, int32_t k2)
{
//  dbg(1, n, k1, k2);
    if (n<0) return 0;
    if (vis[n][k1][k2]) return dp[n][k1][k2];

    vis[n][k1][k2] = 1;
    int mxn = d(n-1, k1, k2);
    if (k1) mxn = max(mxn, d(n-1, k1-1, k2) + v[n][0]);
    if (k2) mxn = max(mxn, d(n-1, k1, k2-1) + v[n][1]);

    return dp[n][k1][k2] = mxn;
}

inline int get(int n, int k1, int k2)
{
    if (n<0) return 0;
    return dp[n][k1][k2];
}

main()
{
    ndbg( ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); );

    int n, k;//, a, b;
    cin>>n>>k;

    for (int i=0;i<n;i++)
        cin>>v[i][0]>>v[i][1];

//  for (int i=0;i<n;i++)
//  {
//      dp[i].resize(k+2, vector<int>(k+2));
//      vis[i].resize(k+2, vector<bool>(k+2));
//  }

    for (int i=0;i<n;i++)
        for (int k1=0;k1<=k;k1++)
            for (int k2=0;k2<=k;k2++)
            {
                int mxn = get(i-1, k1, k2);
                if (k1) mxn = max(mxn, get(i-1, k1-1, k2) + v[i][0]);
                if (k2) mxn = max(mxn, get(i-1, k1, k2-1) + v[i][1]);
                dp[i][k1][k2] = mxn;
            }
    cout<<dp[n-1][k][k]<<'\n';
//  cout<<d(n-1, k, k)<<'\n';
}
