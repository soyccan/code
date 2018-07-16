// uva11134
// greedy
#include <bits/stdc++.h>
#define int long long
#define MS(s,v) memset(s,v,sizeof(s))
#define FOR(i,st,en) for (int i=st; i<=en; ++i)
#define RFOR(i,st,en) for (int i=st; i>=en; --i)
using namespace std;
const int INF = 0x3f3f3f3f3f3f3f3fLL;
struct Interval {
    int l,r,i,ans;
    Interval(): ans(0) {}
    bool operator<(Interval t) const {
        if (r!=t.r) return r<t.r;
        else return l<t.l;
    }
};
Interval X[5005];
Interval Y[5005];
int ansx[5005];
int ansy[5005];
bool solve(Interval s[],int r[],int n) {
    sort(s,s+n);
    FOR(i,1,n) {
        FOR(j,0,n-1) {
            Interval& it=s[j];
            if (it.l<=i && i<=it.r && !it.ans) {
                it.ans=i;
                break;
            }
        }
    }
    FOR(j,0,n-1) if (!s[j].ans) return 0;
    FOR(j,0,n-1) r[s[j].i]=s[j].ans;
    return 1;
}
main() {
#ifdef XD
    freopen("in.txt","r",stdin);
#else
    ios::sync_with_stdio(0);
    cin.tie(0);
#endif
    int n;
    while (cin>>n && n) {
        FOR(i,0,n-1) {
            cin>>X[i].l>>Y[i].l>>X[i].r>>Y[i].r;
            X[i].ans=Y[i].ans=0;
            X[i].i=Y[i].i=i;
        }
        if (solve(X,ansx,n) && solve(Y,ansy,n))
            FOR(i,0,n-1) cout<<ansx[i]<<' '<<ansy[i]<<'\n';
        else
            cout<<"IMPOSSIBLE\n";
    }
    return 0;
}
