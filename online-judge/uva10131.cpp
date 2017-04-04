// uva10131
// LIS
#include <bits/stdc++.h>
#define int long long
#define MS(a,v) memset(a,v,sizeof a)
#define _FOR(i,start,end,step) for (int i=start; i!=end; i+=step)
#define FOR(i,start,end) for (int i=start; i<end; ++i)
using namespace std;
struct S {
    int a,b,p;
    bool operator<(const S& s) const {
        if (a!=s.a) return a<s.a; // ascending
        else return b>s.b; // descending
    }
};
int dp[10005];
int prv[10005];
vector<S> v;
void output(int p,int n) {
    if (p==-1) return;
    output(prv[p],n);
    cout<<v[p].p<<'\n';
}
main() {
#ifndef LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
#endif
    int a,b,p=0;
    while (cin>>a>>b)
        v.push_back({a,b,++p});
    sort(v.begin(), v.end());
    MS(prv,-1);
    FOR(i,0,v.size()) {
        dp[i]=1;
        FOR(j,0,i) {
            if (v[j].a < v[i].a && v[j].b > v[i].b && dp[j]+1 > dp[i]) {
                dp[i]=dp[j]+1;
                prv[i]=j;
            }
        }
    }
    // FOR(i,0,v.size()) cout<<dp[i]<<' '; cout<<'\n';
    // FOR(i,0,v.size()) cout<<v[i].a<<' '<<v[i].b<<'\n';
    int k = max_element(dp,dp+v.size())-dp;
    cout<<dp[k]<<'\n';
    output(k, v.size());
    return 0;
}
